#include <config/kube_config.h>
#include <api/CoreV1API.h>
#include <stdio.h>

#include <config/kube_config.h>
#include <api/CoreV1API.h>
#include <stdio.h>

void list_event(apiClient_t * apiClient)
{
    core_v1_event_list_t *event_list = CoreV1API_listNamespacedEvent(apiClient, "default",  /*namespace */
                                                                     "true",    /* pretty */
                                                                     0, /* allowWatchBookmarks */
                                                                     NULL,  /* continue */
                                                                     NULL,  /* fieldSelector */
                                                                     NULL,  /* labelSelector */
                                                                     0, /* limit */
                                                                     NULL,  /* resourceVersion */
                                                                     NULL,  /* resourceVersionMatch */
                                                                     0, /* timeoutSeconds */
                                                                     0  /* watch */
        );
    printf("The return code of HTTP request=%ld\n", apiClient->response_code);
    if (event_list) {
        if (event_list->items) {
            listEntry_t *listEntry = NULL;
            core_v1_event_t *event = NULL;
            list_ForEach(listEntry, event_list->items) {
                event = listEntry->data;
                if (event) {
                    if (event->type) {
                        printf("Event Type: %s\n", event->type);
                    }
                    if (event->message) {
                        printf("Event Message: %s\n", event->message);
                    }
                }
            }
        } else {
            fprintf(stderr, "There are no events in event list.\n");
        }
        core_v1_event_list_free(event_list);
        event_list = NULL;
    } else {
        fprintf(stderr, "Cannot get event list.\n");
    }
}

int main()
{
    char *basePath = NULL;
    sslConfig_t *sslConfig = NULL;
    list_t *apiKeys = NULL;
    int rc = load_kube_config(&basePath, &sslConfig, &apiKeys, NULL);   /* NULL means loading configuration from $HOME/.kube/config */
    if (rc != 0) {
        fprintf(stderr, "Cannot load kubernetes configuration.\n");
        return -1;
    }
    apiClient_t *apiClient = apiClient_create_with_base_path(basePath, sslConfig, apiKeys);
    if (!apiClient) {
        fprintf(stderr, "Cannot create a kubernetes client.\n");
        return -1;
    }

    list_event(apiClient);

    apiClient_free(apiClient);
    apiClient = NULL;
    free_client_config(basePath, sslConfig, apiKeys);
    basePath = NULL;
    sslConfig = NULL;
    apiKeys = NULL;
    apiClient_unsetupGlobalEnv();

    return 0;
}
