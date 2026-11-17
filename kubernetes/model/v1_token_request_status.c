#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_token_request_status.h"



static v1_token_request_status_t *v1_token_request_status_create_internal(
    char *expiration_timestamp,
    char *token
    ) {
    v1_token_request_status_t *v1_token_request_status_local_var = malloc(sizeof(v1_token_request_status_t));
    if (!v1_token_request_status_local_var) {
        return NULL;
    }
    memset(v1_token_request_status_local_var, 0, sizeof(v1_token_request_status_t));
    v1_token_request_status_local_var->_library_owned = 1;
    v1_token_request_status_local_var->expiration_timestamp = expiration_timestamp;
    v1_token_request_status_local_var->token = token;
    return v1_token_request_status_local_var;
}

__attribute__((deprecated)) v1_token_request_status_t *v1_token_request_status_create(
    char *expiration_timestamp,
    char *token
    ) {
    v1_token_request_status_t *result = v1_token_request_status_create_internal (
        expiration_timestamp,
        token
        );
    if (!result) {
    }
    return result;
}

void v1_token_request_status_free(v1_token_request_status_t *v1_token_request_status) {
    if(NULL == v1_token_request_status){
        return ;
    }
    if(v1_token_request_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_token_request_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_token_request_status->expiration_timestamp) {
        free(v1_token_request_status->expiration_timestamp);
        v1_token_request_status->expiration_timestamp = NULL;
    }
    if (v1_token_request_status->token) {
        free(v1_token_request_status->token);
        v1_token_request_status->token = NULL;
    }
    free(v1_token_request_status);
}

cJSON *v1_token_request_status_convertToJSON(v1_token_request_status_t *v1_token_request_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_token_request_status->expiration_timestamp
    if(v1_token_request_status->expiration_timestamp) {
    if(cJSON_AddStringToObject(item, "expirationTimestamp", v1_token_request_status->expiration_timestamp) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1_token_request_status->token
    if(v1_token_request_status->token) {
    if(cJSON_AddStringToObject(item, "token", v1_token_request_status->token) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_token_request_status_t *v1_token_request_status_parseFromJSON(cJSON *v1_token_request_statusJSON){

    v1_token_request_status_t *v1_token_request_status_local_var = NULL;

    char *expiration_timestamp_local_str = NULL;

    char *token_local_str = NULL;

    // v1_token_request_status->expiration_timestamp
    cJSON *expiration_timestamp = cJSON_GetObjectItemCaseSensitive(v1_token_request_statusJSON, "expirationTimestamp");
    if (cJSON_IsNull(expiration_timestamp)) {
        expiration_timestamp = NULL;
    }
    if (expiration_timestamp) { 
    if(!cJSON_IsString(expiration_timestamp) && !cJSON_IsNull(expiration_timestamp))
    {
    goto end; //DateTime
    }
    }

    // v1_token_request_status->token
    cJSON *token = cJSON_GetObjectItemCaseSensitive(v1_token_request_statusJSON, "token");
    if (cJSON_IsNull(token)) {
        token = NULL;
    }
    if (token) { 
    if(!cJSON_IsString(token) && !cJSON_IsNull(token))
    {
    goto end; //String
    }
    }


    if (expiration_timestamp && !cJSON_IsNull(expiration_timestamp)) expiration_timestamp_local_str = strdup(expiration_timestamp->valuestring);
    if (token && !cJSON_IsNull(token)) token_local_str = strdup(token->valuestring);

    v1_token_request_status_local_var = v1_token_request_status_create_internal (
        expiration_timestamp_local_str,
        token_local_str
        );

    if (!v1_token_request_status_local_var) {
        goto end;
    }

    return v1_token_request_status_local_var;
end:
    if (expiration_timestamp_local_str) {
        free(expiration_timestamp_local_str);
        expiration_timestamp_local_str = NULL;
    }
    if (token_local_str) {
        free(token_local_str);
        token_local_str = NULL;
    }
    return NULL;

}
