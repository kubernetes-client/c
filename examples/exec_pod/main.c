#include <kube_config.h>
#include <malloc.h>
#include <stdio.h>
#include <kube_exec.h>
#include <incluster_config.h>

/* 
 * An example of call back function:
 */
void my_exec_data_callback(void **p_data_received, long *p_data_received_len)
{
    printf("%s: Received %ld bytes:\n%s", __func__, *p_data_received_len, (char *) (*p_data_received));
}

int main(int argc, char *argv[])
{
    char *base_path = NULL;
    sslConfig_t *ssl_config = NULL;
    list_t *api_tokens = NULL;

    int rc = load_kube_config(&base_path, &ssl_config, &api_tokens, NULL);    /* NULL means loading configuration from $HOME/.kube/config */
    /* 
     * If you need exec pod in cluster:
     * int rc = load_incluster_config(&base_path, &ssl_config, &api_tokens);
     */
    if (rc != 0) {
        printf("Cannot load kubernetes configuration.\n");
        return -1;
    }

    /* The log level mask for libwebsokets */
    int wsc_log_mask = LLL_ERR | LLL_WARN;
    /* 
     * If you need a detailed log:
     * int wsc_log_mask = LLL_ERR | LLL_WARN | LLL_USER | LLL_NOTICE;
    */

    wsclient_t *wsc = wsclient_create(base_path, ssl_config, api_tokens, wsc_log_mask);
    if (!wsc) {
        fprintf(stderr, "Cannot create a websocket client.\n");
        return -1;
    }

    /*
     * Case #1
     * Normal mode (tty = 0)
     */
    kube_exec(wsc,              /* websocket client */
              "default",        /* namespace */
              "test-pod-8",     /* pod name */
              "my-container",   /* container name, NULL means the default container in the pod */
              1,                /* stdin */
              1,                /* stdout */
              0,                /* tty */
              "ls /"            /* command */
        );

    printf("Received %ld bytes:\n%s\n", wsc->data_received_len, (char *) (wsc->data_received));

    if (argc > 1) {             // skip the case #2 in the automation test
        goto end;
    }

    /*
     * Case #2
     * Interactive and tty mode (tty = 1)
     */
    /* Use the default callback function provided by libkubernetes */
    wsc->data_callback_func = NULL;
    /* If you want to use your call back function:
     * wsc->data_callback_func = my_callback_function;
     */
    kube_exec(wsc,              /* websocket client */
              "default",        /* namespace */
              "test-pod-8",     /* pod name */
              NULL,             /* container name, NULL means the default container in the pod */
              1,                /* stdin */
              1,                /* stdout */
              1,                /* tty */
              "bash"            /* command */
        );

  end:
    /* Clean up */
    wsclient_free(wsc);
    free_client_config(base_path, ssl_config, api_tokens);
    base_path = NULL;
    ssl_config = NULL;
    api_tokens = NULL;

    return 0;
}
