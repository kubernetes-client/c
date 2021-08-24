#ifndef _WSCLIENT_H
#define _WSCLIENT_H

#include <libwebsockets.h>
#include "../include/apiClient.h"

#ifdef  __cplusplus
extern "C" {
#endif

typedef void (*data_callback_func) (void **, long *);

typedef enum wsc_mode_t {
    WSC_MODE_NORMAL = 0,
    WSC_MODE_IT
} wsc_mode_t;

typedef struct wsclient_t {
    char *server_address;
    int server_port;
    char *path;
    char *data_to_send;
    long data_to_send_len;
    void *data_received;
    long data_received_len;
    data_callback_func data_callback_func;
    int log_mask;
    lws_sorted_usec_list_t sul; /* schedule connection retry */
    struct lws *wsi;        /* related wsi if any */
    uint16_t retry_count;   /* count of consequetive retries */
    sslConfig_t *ssl_config;
    list_t *api_tokens;
} wsclient_t;

wsclient_t *wsclient_create(const char *, sslConfig_t *, list_t *, int);
void wsclient_free(wsclient_t *);
int wsclient_run(wsclient_t *, wsc_mode_t);

#ifdef  __cplusplus
}
#endif
#endif                          /* _WSCLIENT_H */
