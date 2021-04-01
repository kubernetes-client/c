#include <kube_config.h>
#include <apiClient.h>
#include <CoreV1API.h>
#include <malloc.h>
#include <stdio.h>
#include <errno.h>
#include <watch_util.h>

#define WATCH_EVENT_KEY_TYPE "type"
#define WATCH_EVENT_KEY_OBJECT "object"

void on_pod_event_comes(const char *event_string)
{
    static char fname[] = "process_one_watch_event()";

    if (!event_string) {
        return;
    }
    printf("\nwatch event raw string:\n%s\n\n", event_string);

    char *type = NULL;
    v1_pod_t *pod = NULL;

    const char *parse_end = NULL;
    cJSON *event_json_obj = cJSON_ParseWithOpts(event_string, &parse_end, 1);
    if (!event_json_obj) {
        fprintf(stderr, "%s: Cannot create JSON from string: [%s].\n", fname, parse_end);
        goto end;
    }

    cJSON *json_value_type = cJSON_GetObjectItem(event_json_obj, WATCH_EVENT_KEY_TYPE);
    if (!json_value_type || json_value_type->type != cJSON_String) {
        fprintf(stderr, "%s: Cannot get type in watch event.\n", fname);
        goto end;
    }
    type = strdup(json_value_type->valuestring);
    printf("type: %s\n", type);

    cJSON *json_value_object = cJSON_GetObjectItem(event_json_obj, WATCH_EVENT_KEY_OBJECT);
    if (!json_value_object || json_value_object->type != cJSON_Object) {
        fprintf(stderr, "%s: Cannot get object in watch event.\n", fname);
        goto end;
    }
    pod = v1_pod_parseFromJSON(json_value_object);
    if (!pod) {
        fprintf(stderr, "%s: Cannot get pod from watch event object.\n", fname);
        goto end;
    }
    printf("pod:\n\tname: %s\n", pod->metadata->name);

  end:
    if (pod) {
        v1_pod_free(pod);
        pod = NULL;
    }
    if (type) {
        free(type);
        type = NULL;
    }
    if (event_json_obj) {
        cJSON_Delete(event_json_obj);
        event_json_obj = NULL;
    }
}

void my_pod_watch_handler(void **pData, long *pDataLen)
{
    kubernets_watch_handler(pData, pDataLen, on_pod_event_comes);
}

void watch_list_pod(apiClient_t * apiClient)
{
    apiClient->data_callback_func = my_pod_watch_handler;

    CoreV1API_listNamespacedPod(apiClient, "default",   /*namespace */
                                NULL,   /* pretty */
                                0,  /* allowWatchBookmarks */
                                NULL,   /* continue */
                                NULL,   /* fieldSelector */
                                NULL,   /* labelSelector */
                                0,  /* limit */
                                NULL,   /* resourceVersion */
                                0,  /* timeoutSeconds */
                                1   /* watch */
        );
}

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
    apiClient_t *apiClient = apiClient_create_with_base_path(basePath, sslConfig, apiKeys);
    if (!apiClient) {
        printf("Cannot create a kubernetes client.\n");
        return -1;
    }

    watch_list_pod(apiClient);

    apiClient_free(apiClient);
    apiClient = NULL;
    free_client_config(basePath, sslConfig, apiKeys);
    basePath = NULL;
    sslConfig = NULL;
    apiKeys = NULL;
    apiClient_unsetupGlobalEnv();

    return 0;
}
