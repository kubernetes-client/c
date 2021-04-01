#include "authn_plugin.h"
#include "authn_plugin_util.h"
#include "kube_config_util.h"
#include "kube_config_common.h"
#include "binary.h"
#include "cJSON.h"
#include <time.h>
#include <errno.h>

#define OIDC_ID_TOKEN_DELIM "."
#define OIDC_ID_TOKEN_EXP "exp"
#define OIDC_CONFIGURATION_URL_TEMPLATE "%s/.well-known/openid-configuration"
#define OIDC_TOKEN_ENDPOINT "token_endpoint"
#define OIDC_ID_TOKEN "id_token"
#define OIDC_REFRESH_TOKEN "refresh_token"

#define JWT_PART2_BUFFER_SIZE 1024
#define BASE64_PADDING_STRING_SIZE 4
#define BASE64_PADDING_CHAR "="

#define REFRESH_TOKEN_CONTENT_TYPE "application/x-www-form-urlencoded"
#define REFRESH_TOKEN_CREDENTIAL_TEMPLATE "%s:%s"
#define REFRESH_TOKEN_POST_DATA_TEMPLATE "refresh_token=%s&grant_type=refresh_token"

#define OIDC_CONFIGURATION_URL_BUFFER_SIZE 1024
#define REFRESH_TOKEN_CREDENTIAL_BUFFER_SIZE 1024
#define REFRESH_TOKEN_POST_DATA_BUFFER_SIZE 1024

static time_t get_token_expiration_time(const char *token_string)
{
    static char fname[] = "get_token_expiration_time()";

    time_t expiration_time = 0;

    if (!token_string || '\0' == token_string[0]) {
        return 0;
    }
    char *dup_token_string = strdup(token_string);
    if (!dup_token_string) {
        return 0;
    }

    char *p = NULL;
    p = strtok(dup_token_string, OIDC_ID_TOKEN_DELIM);  /* jwt header */
    if (!p) {
        fprintf(stderr, "%s: The token <%s> is not a valid JWT token.\n", fname, token_string);
        goto end;
    }
    p = strtok(NULL, OIDC_ID_TOKEN_DELIM);  /* jwt part2 */
    if (!p) {
        fprintf(stderr, "%s: The token <%s> is not a valid JWT token.\n", fname, token_string);
        goto end;
    }

    int base64_padding_length = 4 - strlen(p) % 4;
    char base64_padding_string[BASE64_PADDING_STRING_SIZE];
    memset(base64_padding_string, 0, sizeof(base64_padding_string));
    for (int i = 0; i < base64_padding_length; i++) {
        strncat(base64_padding_string, BASE64_PADDING_CHAR, 1);
    }

    char jwt_part2_string[JWT_PART2_BUFFER_SIZE];
    memset(jwt_part2_string, 0, sizeof(jwt_part2_string));
    snprintf(jwt_part2_string, sizeof(jwt_part2_string), "%s%s", p, base64_padding_string);

    int decoded_bytes = 0;
    char *b64decode = base64decode(jwt_part2_string, strlen(jwt_part2_string), &decoded_bytes);
    if (!b64decode || 0 == decoded_bytes) {
        fprintf(stderr, "%s: Base64 decodes failed.\n", fname);
        goto end;
    }

    const char *parse_end = NULL;
    cJSON *payload_JSON = cJSON_ParseWithOpts(b64decode, &parse_end, 1);
    if (!payload_JSON) {
        fprintf(stderr, "%s: Cannot create JSON from string.[%s].\n", fname, parse_end);
        goto end;
    }
    cJSON *json_value = cJSON_GetObjectItem(payload_JSON, OIDC_ID_TOKEN_EXP);
    if (!json_value || json_value->type != cJSON_Number) {
        fprintf(stderr, "%s: Cannot get expiration time in id token.\n", fname);
        goto end;
    }
    expiration_time = json_value->valueint;

  end:
    if (payload_JSON) {
        cJSON_Delete(payload_JSON);
        payload_JSON = NULL;
    }
    if (b64decode) {
        free(b64decode);
        b64decode = NULL;
    }
    if (dup_token_string) {
        free(dup_token_string);
        dup_token_string = NULL;
    }
    return expiration_time;
}

char *get_token(kubeconfig_property_t * auth_provider)
{
    return auth_provider->id_token;
}

bool is_expired(kubeconfig_property_t * auth_provider)
{
    static char fname[] = "is_expired()";

    if (NULL == auth_provider->id_token) {
        fprintf(stderr, "%s: The id token is NULL.\n", fname);
        return true;
    } else if ('\0' == auth_provider->id_token[0]) {
        fprintf(stderr, "%s: The id token is empty.\n", fname);
        return true;
    }

    time_t exp_time = get_token_expiration_time(auth_provider->id_token);
    if (exp_time < time(NULL)) {
        return true;
    }

    return false;
}

char *get_token_endpoint(const char *idp_issuer_url, sslConfig_t * sc)
{
    static char fname[] = "get_token_endpoint()";

    char *token_endpoint = NULL;

    if (!idp_issuer_url || '\0' == idp_issuer_url[0]) {
        fprintf(stderr, "%s: The parameters idp_issuer_url is NULL or empty.\n", fname);
        return NULL;
    }
    if (!sc) {
        fprintf(stderr, "%s: SSL configuration is required.\n", fname);
        return NULL;
    }

    char oidc_configuration_url[OIDC_CONFIGURATION_URL_BUFFER_SIZE];
    memset(oidc_configuration_url, 0, sizeof(oidc_configuration_url));
    snprintf(oidc_configuration_url, sizeof(oidc_configuration_url), OIDC_CONFIGURATION_URL_TEMPLATE, idp_issuer_url);

    char *http_response = NULL;
    int http_response_length = 0;
    int rc = shc_request(&http_response, &http_response_length, HTTP_REQUEST_GET, oidc_configuration_url, sc, NULL, NULL, NULL);
    if (HTTP_RC_OK != rc) {
        fprintf(stderr, "%s: Failed to get token endpoint.\n", fname);
        goto end;
    }

    token_endpoint = shc_get_string_from_json(http_response, OIDC_TOKEN_ENDPOINT);

  end:
    if (http_response) {
        free(http_response);
        http_response_length = 0;
    }

    return token_endpoint;
}

static int refresh_oidc_token(kubeconfig_property_t * auth_provider, const char *token_endpoint, sslConfig_t * sc)
{
    static char fname[] = "refresh_oidc_token()";

    int rc = 0;

    if (!auth_provider || !token_endpoint || !sc) {
        fprintf(stderr, "%s: The parameters are not valid.\n", fname);
        return -1;
    }

    list_t *content_type = list_create();
    if (!content_type) {
        fprintf(stderr, "%s: Cannot create list for content type.[%s]\n", fname, strerror(errno));
        return -1;
    }
    list_addElement(content_type, strdup(REFRESH_TOKEN_CONTENT_TYPE));

    char refresh_token_credential[REFRESH_TOKEN_CREDENTIAL_BUFFER_SIZE];
    memset(refresh_token_credential, 0, sizeof(refresh_token_credential));
    snprintf(refresh_token_credential, sizeof(refresh_token_credential), REFRESH_TOKEN_CREDENTIAL_TEMPLATE, auth_provider->client_id, auth_provider->client_secret);
    char *base64_credential = base64encode(refresh_token_credential, strlen(refresh_token_credential));
    if (!base64_credential) {
        fprintf(stderr, "%s: Cannot encode refresh token with base64.\n", fname);
        rc = -1;
        goto end;
    }
    char basic_token_buffer[BASIC_TOKEN_BUFFER_SIZE];
    memset(basic_token_buffer, 0, sizeof(basic_token_buffer));
    snprintf(basic_token_buffer, sizeof(basic_token_buffer), BASIC_TOKEN_TEMPLATE, base64_credential);

    list_t *api_keys = list_create();
    if (!api_keys) {
        fprintf(stderr, "%s: Cannot create list for refresh token.[%s]\n", fname, strerror(errno));
        rc = -1;
        goto end;
    }
    keyValuePair_t *keyPairToken = keyValuePair_create(strdup(AUTH_TOKEN_KEY), strdup(basic_token_buffer));
    list_addElement(api_keys, keyPairToken);

    char refresh_token_post_data[REFRESH_TOKEN_POST_DATA_BUFFER_SIZE];
    memset(refresh_token_post_data, 0, sizeof(refresh_token_post_data));
    snprintf(refresh_token_post_data, sizeof(refresh_token_post_data), REFRESH_TOKEN_POST_DATA_TEMPLATE, auth_provider->refresh_token);

    char *http_response = NULL;
    int http_response_length = 0;
    rc = shc_request(&http_response, &http_response_length, HTTP_REQUEST_POST, token_endpoint, sc, api_keys, content_type, refresh_token_post_data);
    if (HTTP_RC_OK == rc) {
        rc = 0;                 // update return code
    } else {
        fprintf(stderr, "%s: Failed to refresh OIDC token.\n", fname);
        rc = -1;
        goto end;
    }

    char *new_id_token = shc_get_string_from_json(http_response, OIDC_ID_TOKEN);
    if (new_id_token) {
        if (auth_provider->id_token) {
            free(auth_provider->id_token);
            auth_provider->id_token = NULL;
        }
        auth_provider->id_token = new_id_token;
    } else {
        fprintf(stderr, "%s: Failed to get the new OIDC token from the response.\n", fname);
        rc = -1;
        goto end;
    }

    char *new_refresh_token = shc_get_string_from_json(http_response, OIDC_REFRESH_TOKEN);
    if (new_refresh_token) {
        if (auth_provider->refresh_token) {
            free(auth_provider->refresh_token);
            auth_provider->refresh_token = NULL;
        }
        auth_provider->refresh_token = new_refresh_token;
    } else {
        rc = -1;
        fprintf(stderr, "%s: Failed to get the new refresh token from the response.\n", fname);
        goto end;
    }

  end:
    if (http_response) {
        free(http_response);
        http_response = NULL;
        http_response_length = 0;
    }
    if (base64_credential) {
        free(base64_credential);
        base64_credential = NULL;
    }
    if (api_keys) {
        clear_and_free_string_pair_list(api_keys);
        api_keys = NULL;
    }
    if (content_type) {
        clear_and_free_string_list(content_type);
        content_type = NULL;
    }
    return rc;
}

int refresh(kubeconfig_property_t * auth_provider)
{
    static char fname[] = "refresh()";

    int rc = 0;

    sslConfig_t *sc = NULL;
    if (auth_provider->idp_certificate_authority && '\0' != auth_provider->idp_certificate_authority[0]) {
        sc = sslConfig_create(NULL, NULL, auth_provider->idp_certificate_authority, 0);
    } else if (auth_provider->idp_certificate_authority_data && '\0' != auth_provider->idp_certificate_authority_data[0]) {
        char *idp_certificate_file = kubeconfig_mk_cert_key_tempfile(auth_provider->idp_certificate_authority_data);
        if (!idp_certificate_file) {
            fprintf(stderr, "%s: Failed to create the temporary file for certificate.\n", fname);
            return -1;
        }
        sc = sslConfig_create(NULL, NULL, idp_certificate_file, 0);
        free(idp_certificate_file);
        idp_certificate_file = NULL;
    } else {
        sc = sslConfig_create(NULL, NULL, NULL, 1);
    }
    if (!sc) {
        fprintf(stderr, "%s: Cannot create the SSL configuration.\n", fname);
        return -1;
    }

    char *token_endpoint = get_token_endpoint(auth_provider->idp_issuer_url, sc);
    if (!token_endpoint) {
        fprintf(stderr, "%s: Cannot get the token endpoint.\n", fname);
        rc = -1;
        goto end;
    }
    rc = refresh_oidc_token(auth_provider, token_endpoint, sc);
    if (-1 == rc) {
        fprintf(stderr, "%s: Failed to refresh OIDC token.\n", fname);
        goto end;
    }

  end:
    if (token_endpoint) {
        free(token_endpoint);
        token_endpoint = NULL;
    }
    if (sc) {
        if (NULL == auth_provider->idp_certificate_authority && auth_provider->idp_certificate_authority_data && '\0' != auth_provider->idp_certificate_authority_data[0]) {
            unsetSslConfig(sc);
        }
        sslConfig_free(sc);
        sc = NULL;
    }

    return rc;
}
