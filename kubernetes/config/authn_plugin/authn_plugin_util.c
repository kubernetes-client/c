#include "authn_plugin_util.h"
#include <errno.h>
#include "include/utils.h"

int shc_request(char **p_http_response, int *p_http_response_length, char *type, const char *url, sslConfig_t * sc, list_t * apiKeys, list_t * contentType, char *post_data)
{
    static char fname[] = "shc_request()";

    apiClient_t *http_client = apiClient_create_with_base_path(url, sc, apiKeys);
    if (!http_client) {
        fprintf(stderr, "%s: Cannot create http client. [%s].\n", fname, strerror(errno));
        return -1;
    }
    apiClient_invoke(http_client, NULL, NULL, NULL, NULL, NULL, contentType, post_data, type);

    int rc = http_client->response_code;
    switch (rc) {
    case HTTP_RC_OK:
        *p_http_response = strndup((char *) http_client->dataReceived, http_client->dataReceivedLen);
        *p_http_response_length = http_client->dataReceivedLen;
        break;
    default:
        printf("%s: response_code=%ld\n", fname, http_client->response_code);
        if (http_client->dataReceived) {
            printf("%s: %s\n", fname, (char *) http_client->dataReceived);
        }
        break;
    }

    if (http_client->dataReceived) {
        free(http_client->dataReceived);
        http_client->dataReceived = NULL;
        http_client->dataReceivedLen = 0;
    }

    if (http_client) {
        apiClient_free(http_client);
        http_client = NULL;
    }

    return rc;
}

char *shc_get_string_from_json(const char *json_string, const char *key)
{
    static char fname[] = "shc_get_string_from_json()";

    char *res = NULL;

    if (!json_string || !key) {
        return NULL;
    }

    const char *parse_end = NULL;
    cJSON *json = cJSON_ParseWithOpts(json_string, &parse_end, 1);
    if (!json) {
        fprintf(stderr, "%s: Cannot create JSON from string: [%s].\n", fname, parse_end);
        return NULL;
    }
    cJSON *value = cJSON_GetObjectItem(json, key);
    if (!value) {
        fprintf(stderr, "%s: Cannot get the value for %s.\n", fname, key);
        goto end;
    }
    if (value->type != cJSON_String && value->type != cJSON_Object) {
        fprintf(stderr, "%s: The value for %s is invalid.\n", fname, key);
        goto end;
    }
    res = strdup(value->valuestring);

  end:
    if (json) {
        cJSON_Delete(json);
        json = NULL;
    }

    return res;
}
