#include <kube_config.h>
#include "mt.h"

bool g_exit_watch = false;
pthread_mutex_t exit_watch_mutex;

int main(int argc, char *argv[])
{
    char *basePath = NULL;
    sslConfig_t *sslConfig = NULL;
    list_t *apiKeys = NULL;
    int rc = load_kube_config(&basePath, &sslConfig, &apiKeys, NULL);   /* NULL means loading configuration from $HOME/.kube/config */
    if (rc != 0) {
        printf("Cannot load kubernetes configuration.\n");
        return -1;
    }
    kube_params_t *params = calloc(1, sizeof(kube_params_t));
    params->basePath = basePath;
    params->sslConfig = sslConfig;
    params->apiKeys = apiKeys;
    apiClient_setupGlobalEnv();

    pthread_t watch_pod_thread;
    int err = pthread_create(&watch_pod_thread, NULL, watch_pod_thread_func, (void *) params);
    if (0 != err) {
        perror("creating thread error");
        exit(-1);
    }

    pthread_t create_pod_thread;
    err = pthread_create(&create_pod_thread, NULL, create_pod_thread_func, (void *) params);
    if (0 != err) {
        perror("creating thread error");
        exit(-1);
    }

    sleep(30);

    pthread_mutex_lock(&exit_watch_mutex);
    g_exit_watch = true;        // notify watch thread to exit
    pthread_mutex_unlock(&exit_watch_mutex);

    pthread_join(watch_pod_thread, NULL);
    pthread_join(create_pod_thread, NULL);

    free_client_config(basePath, sslConfig, apiKeys);
    basePath = NULL;
    sslConfig = NULL;
    apiKeys = NULL;
    free(params);
    params = NULL;
    apiClient_unsetupGlobalEnv();

    return 0;
}
