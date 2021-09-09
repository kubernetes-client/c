#include "wsclient.h"
#include "../config/kube_config_common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef _WIN32
#include <unistd.h>
#endif
#include <fcntl.h>
#include <stdbool.h>

#define WSC_ATTACH_STDIN_BUFFER_SIZE 1024
#define TTY_STDIN_NUMBER 0
#define TTY_STDOUT_NUMBER 1
#define WS_PROTOCOL_DELIM "://"
#define WS_BASE_PATH_DELIM_CHAR ':' /* ip:port */
#define WS_BASE_PATH_DELIM_LENGTH 1

static struct lws_context *g_lws_context;
static bool g_interrupted;

/*
 * The retry and backoff policy we want to use for our client connections
 */

static const uint32_t backoff_ms[] = { 1000, 2000, 3000, 4000, 5000 };

static const lws_retry_bo_t retry = {
    .retry_ms_table = backoff_ms,
    .retry_ms_table_count = LWS_ARRAY_SIZE(backoff_ms),
    .conceal_count = LWS_ARRAY_SIZE(backoff_ms),

    .secs_since_valid_ping = 3, /* force PINGs after secs idle */
    .secs_since_valid_hangup = 10,  /* hangup after secs idle */

    .jitter_percent = 20,
};

static int get_server_address_and_port(char **p_ws_addr, int *p_ws_port, const char *base_path)
{
    if (!base_path) {
        return -1;
    }

    char *p = strstr(base_path, WS_PROTOCOL_DELIM); /* e.g. base_path="https://ip:port" */
    if (NULL == p) {
        fprintf(stderr, "%s: %s is not a valid websocket base path.\n", __func__, base_path);
        return -1;
    }
    const char *addr_and_port_string = p + strlen(WS_PROTOCOL_DELIM);   /* addr_and_port_string="ip:port" */

    p = strrchr(addr_and_port_string, WS_BASE_PATH_DELIM_CHAR);
    if (NULL == p) {
        fprintf(stderr, "%s: %s is not a valid websocket base path.\n", __func__, addr_and_port_string);
        return -1;
    }
    const char *port_string = p + WS_BASE_PATH_DELIM_LENGTH;

    int ws_port = atoi(port_string);
    if (0 == ws_port) {
        fprintf(stderr, "%s: Cannot get a valid websocket port from <%s>.\n", __func__, port_string);
        return -1;
    }

    int port_string_length = strlen(addr_and_port_string) - WS_BASE_PATH_DELIM_LENGTH - strlen(port_string);
    char *ws_addr = (char *) calloc(sizeof(char), port_string_length + 1);  /* the memory of ws_addr will be deleted by wsclient_free() */
    if (!ws_addr) {
        fprintf(stderr, "%s: Cannot allocate the memory for websocket server address.\n", __func__);
        return -1;
    }
    strncpy(ws_addr, addr_and_port_string, port_string_length);

    *p_ws_port = ws_port;
    *p_ws_addr = ws_addr;

    return 0;
}

wsclient_t *wsclient_create(const char *base_path, sslConfig_t * ssl_config, list_t * api_tokens, int ws_log_mask)
{
    if (!base_path) {
        fprintf(stderr, "%s: The base path is invalid.\n", __func__);
        return NULL;
    }

    wsclient_t *wsc = (wsclient_t *) calloc(1, sizeof(wsclient_t));
    if (!wsc) {
        fprintf(stderr, "%s: Cannot allocate the memory for websocket client.\n", __func__);
        return NULL;
    }

    int rc = get_server_address_and_port(&wsc->server_address, &wsc->server_port, base_path);
    if (0 != rc) {
        fprintf(stderr, "%s: Cannot get the websocket server address or port from the base path <%s>.\n", __func__, base_path);
        goto error;
    }

    wsc->ssl_config = ssl_config;
    wsc->api_tokens = api_tokens;
    wsc->log_mask = ws_log_mask;

    return wsc;

  error:
    if (wsc) {
        free(wsc);
        wsc = NULL;
    }
    return NULL;
}

void wsclient_free(wsclient_t * wsc)
{
    if (!wsc) {
        return;
    }
    if (wsc->server_address) {
        free(wsc->server_address);
        wsc->server_address = NULL;
    }
    if (wsc->data_received) {
        free(wsc->data_received);
        wsc->data_received = NULL;
    }
    wsc->data_received_len = 0;
    wsc->data_callback_func = NULL;
    wsc->ssl_config = NULL;
    wsc->api_tokens = NULL;

    free(wsc);
}

/*
 * Scheduled sul callback that starts the connection attempt
 */

static void connect_client(lws_sorted_usec_list_t * sul)
{
    wsclient_t *wsc = lws_container_of(sul, wsclient_t, sul);
    struct lws_client_connect_info i;

    memset(&i, 0, sizeof(i));

    i.context = g_lws_context;
    i.port = wsc->server_port;
    i.address = wsc->server_address;
    i.path = wsc->path;
    i.host = i.address;
    i.origin = i.address;
    i.ssl_connection = wsc->ssl_config ? LCCSCF_USE_SSL : 0;

    //i.protocol = pro;
    //i.local_protocol_name = "websocket-client";
    i.pwsi = &wsc->wsi;
    i.retry_and_idle_policy = &retry;
    i.userdata = wsc;

    if (!lws_client_connect_via_info(&i))
        /*
         * Failed... schedule a retry... we can't use the _retry_wsi()
         * convenience wrapper api here because no valid wsi at this
         * point.
         */
        if (lws_retry_sul_schedule(g_lws_context, 0, sul, &retry, connect_client, &wsc->retry_count)) {
            lwsl_err("%s: connection attempts exhausted\n", __func__);
            g_interrupted = true;
        }
}

static int callback_wsclient(struct lws *wsi, enum lws_callback_reasons reason, void *user, void *in, size_t len)
{
    lwsl_user("%s: callback reason %d\n", __func__, reason);

    wsclient_t *wsc = (wsclient_t *) user;

    switch (reason) {

    case LWS_CALLBACK_CLIENT_CONNECTION_ERROR:
        lwsl_err("%s: wsclient connection error: %s\n", __func__, in ? (char *) in : "(null)");
        goto do_retry;
        break;

    case LWS_CALLBACK_CLIENT_APPEND_HANDSHAKE_HEADER:
        if (!wsc->api_tokens) {
            return 0;
        }
        lwsl_user("%s: LWS_CALLBACK_CLIENT_APPEND_HANDSHAKE_HEADER\n", __func__);
        unsigned char **p = (unsigned char **) in, *end = (*p) + len;
        listEntry_t *listEntry = NULL;
        keyValuePair_t *token = NULL;
        list_ForEach(listEntry, wsc->api_tokens) {
            token = listEntry->data;
            if (token && token->key && token->value && 0 == strcmp(token->key, AUTH_TOKEN_KEY)) {
                lwsl_user("%s: token->key==%s, token->value=%s\n", __func__, token->key, (char *) token->value);
                if (lws_add_http_header_by_token(wsi, WSI_TOKEN_HTTP_AUTHORIZATION, (unsigned char *) token->value, (int) strlen(token->value), p, end)) {
                    return -1;
                }
            }
        }
        break;

    case LWS_CALLBACK_CLIENT_ESTABLISHED:
        lwsl_user("%s: wsclient connection established\n", __func__);
        lws_callback_on_writable(wsi);
        break;

    case LWS_CALLBACK_CLIENT_RECEIVE:
        lwsl_hexdump_notice(in, len);
        if (TTY_STDOUT_NUMBER != ((char *) in)[0]) {
            lwsl_user("%s: The first char of data received is not STDOUT.\n", __func__);
            return 0;
        }
        /*
         * The first character of data received from
         * the kubernets API server is "STDOUT",
         * we ignore it
         */
        int valid_data_len = len - 1;
        if (0 == valid_data_len) {
            lwsl_user("%s: The content of data received is empty.\n", __func__);
            return 0;
        }
        char *valid_data = (char *) in + 1;

        if (wsc->data_received_len > 0 && wsc->data_received) {
            free(wsc->data_received);
            wsc->data_received = NULL;
            wsc->data_received_len = 0;
        }
        wsc->data_received = (char *) calloc(sizeof(char), valid_data_len + 1);
        if (!wsc->data_received) {
            lwsl_err("%s: Cannot allocate memory for received data.\n", __func__);
            return -1;
        }
        memcpy(wsc->data_received, valid_data, valid_data_len);
        wsc->data_received_len = valid_data_len;

        if (wsc->data_received_len != 0 && wsc->data_received && wsc->data_callback_func) {
            wsc->data_callback_func(&wsc->data_received, &wsc->data_received_len);
        }
        break;

    case LWS_CALLBACK_CLIENT_WRITEABLE:
        if (wsc->data_to_send_len > 0 && wsc->data_to_send) {
            int m = lws_write(wsi, wsc->data_to_send + LWS_PRE, wsc->data_to_send_len, LWS_WRITE_BINARY);
            if (m < wsc->data_to_send_len) {
                lwsl_err("%s: Sending message failed: %d\n", __func__, m);
                return -1;
            }
            lwsl_user("%s: Succeed to send message: %d\n", __func__, m);
            if (wsc->data_to_send) {
                free(wsc->data_to_send);
                wsc->data_to_send = NULL;
                wsc->data_to_send_len = 0;
            }
        }
        break;

    case LWS_CALLBACK_CLIENT_CLOSED:
        //goto do_retry;
        g_interrupted = true;
        break;
    default:
        break;
    }

    return lws_callback_http_dummy(wsi, reason, user, in, len);

  do_retry:
    /*
     * retry the connection to keep it nailed up
     *
     * For this example, we try to conceal any problem for one set of
     * backoff retries and then exit the app.
     *
     * If you set retry.conceal_count to be larger than the number of
     * elements in the backoff table, it will never give up and keep
     * retrying at the last backoff delay plus the random jitter amount.
     */
    if (lws_retry_sul_schedule_retry_wsi(wsi, &wsc->sul, connect_client, &wsc->retry_count)) {
        lwsl_err("%s: wsclient connection attempts exhausted.\n", __func__);
        g_interrupted = true;
    }

    return 0;
}

static const struct lws_protocols protocols[] = {
    {"", callback_wsclient, 0, 0,},
    {NULL, NULL, 0, 0}
};

static void read_from_stdin(wsclient_t * wsc)
{
    char wsc_attach_stdin_buffer[WSC_ATTACH_STDIN_BUFFER_SIZE];
    memset(wsc_attach_stdin_buffer, 0, sizeof(wsc_attach_stdin_buffer));

#ifndef _WIN32
    int flag, newflag;
    flag = fcntl(STDIN_FILENO, F_GETFL);
    newflag = flag | O_NONBLOCK;
    fcntl(STDIN_FILENO, F_SETFL, newflag);
    fgets(wsc_attach_stdin_buffer, sizeof(wsc_attach_stdin_buffer) - 1, stdin);
#endif

    if (wsc_attach_stdin_buffer && strlen(wsc_attach_stdin_buffer) > 0) {
        wsc->data_to_send_len = strlen(wsc_attach_stdin_buffer) + 1 /* TTY_STDIN_NUMBER */ ;
        wsc->data_to_send = (char *) calloc(LWS_PRE + 1 /* TTY_STDIN_NUMBER */  + wsc->data_to_send_len + 1, 1);
        wsc->data_to_send[LWS_PRE] = TTY_STDIN_NUMBER;
        strncpy(wsc->data_to_send + LWS_PRE + 1, wsc_attach_stdin_buffer, strlen(wsc_attach_stdin_buffer));
    }
#ifndef _WIN32
    fcntl(STDIN_FILENO, F_SETFL, flag);
#endif
}

int wsclient_run(wsclient_t * wsc, wsc_mode_t mode)
{
    int n = 0;
    lws_set_log_level(wsc->log_mask, NULL);

    struct lws_context_creation_info info;
    memset(&info, 0, sizeof(struct lws_context_creation_info));

    info.options = LWS_SERVER_OPTION_DO_SSL_GLOBAL_INIT;
    info.port = CONTEXT_PORT_NO_LISTEN; /* we do not run any server */
    info.protocols = protocols;
    /*
     * since we know this lws context is only ever going to be used with
     * one client wsis / fds / sockets at a time, let lws know it doesn't
     * have to use the default allocations for fd tables up to ulimit -n.
     * It will just allocate for 1 internal and 1 (+ 1 http2 nwsi) that we
     * will use.
     */
    info.fd_limit_per_thread = 1 + 1 + 1;

    if (wsc->ssl_config) {
        lwsl_user("%s: CACertFile=%s\n", __func__, wsc->ssl_config->CACertFile);
        info.client_ssl_ca_filepath = wsc->ssl_config->CACertFile;
        lwsl_user("%s: clientKeyFile=%s\n", __func__, wsc->ssl_config->clientKeyFile);
        info.client_ssl_private_key_filepath = wsc->ssl_config->clientKeyFile;
        lwsl_user("%s: clientCertFile=%s\n", __func__, wsc->ssl_config->clientCertFile);
        info.client_ssl_cert_filepath = wsc->ssl_config->clientCertFile;
    }

    g_lws_context = lws_create_context(&info);
    if (!g_lws_context) {
        lwsl_err("%s: wsclient init failed.\n", __func__);
        return 1;
    }

    /* schedule the first client connection attempt to happen immediately */
    lws_sul_schedule(g_lws_context, 0, &wsc->sul, connect_client, 1);

    while (n >= 0 && false == g_interrupted) {
        if (WSC_MODE_IT == mode) {
            read_from_stdin(wsc);
        }
        n = lws_service(g_lws_context, 0);
    }

    lwsl_user("%s: wsclient completed.\n", __func__);
    lws_context_destroy(g_lws_context);
    g_interrupted = false;

    return 0;
}
