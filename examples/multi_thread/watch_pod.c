#include "mt.h"
#include <watch_util.h>

#define WATCH_EVENT_KEY_TYPE "type"
#define WATCH_EVENT_KEY_OBJECT "object"

static void on_pod_event_comes(const char *event_string)
{
    static char fname[] = "process_one_watch_event()";

    if (!event_string) {
        return;
    }

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

static void my_pod_watch_handler(void **pData, long *pDataLen)
{
    kubernets_watch_handler(pData, pDataLen, on_pod_event_comes);
}

static int my_watch_progress_func(void *clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow)
{
    bool exit_watch = false;

    pthread_mutex_lock(&exit_watch_mutex);
    exit_watch = g_exit_watch;
    pthread_mutex_unlock(&exit_watch_mutex);

    if (true == exit_watch) {
        /* Returning any other non-zero value from this callback will cause libcurl to 
         * abort the transfer and return CURLE_ABORTED_BY_CALLBACK.
         */
        return 1;
    }

    return 0;
}

void *watch_pod_thread_func(void *arg)
{
    kube_params_t *params = (kube_params_t *) arg;
    apiClient_t *apiClient = apiClient_create_with_base_path(params->basePath, params->sslConfig, params->apiKeys);
    if (!apiClient) {
        fprintf(stderr, "Cannot create a kubernetes client.\n");
        return ((void *) 1);
    }

    apiClient->data_callback_func = my_pod_watch_handler;
    apiClient->progress_func = my_watch_progress_func;

    CoreV1API_listNamespacedPod(apiClient, "default",   /*namespace */
                                NULL,   /* pretty */
                                0,  /* allowWatchBookmarks */
                                NULL,   /* continue */
                                NULL,   /* fieldSelector */
                                NULL,   /* labelSelector */
                                0,  /* limit */
                                NULL,   /* resourceVersion */
                                0,  /* timeoutSeconds
                                       Setting the value to 0 means the watch never stops.
                                     */
                                1   /* watch */
        );

    apiClient_free(apiClient);
    apiClient = NULL;

    pthread_exit(NULL);
}
