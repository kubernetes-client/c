#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "storage_v1_token_request.h"



static storage_v1_token_request_t *storage_v1_token_request_create_internal(
    char *audience,
    long expiration_seconds
    ) {
    storage_v1_token_request_t *storage_v1_token_request_local_var = malloc(sizeof(storage_v1_token_request_t));
    if (!storage_v1_token_request_local_var) {
        return NULL;
    }
    storage_v1_token_request_local_var->audience = audience;
    storage_v1_token_request_local_var->expiration_seconds = expiration_seconds;

    storage_v1_token_request_local_var->_library_owned = 1;
    return storage_v1_token_request_local_var;
}

__attribute__((deprecated)) storage_v1_token_request_t *storage_v1_token_request_create(
    char *audience,
    long expiration_seconds
    ) {
    return storage_v1_token_request_create_internal (
        audience,
        expiration_seconds
        );
}

void storage_v1_token_request_free(storage_v1_token_request_t *storage_v1_token_request) {
    if(NULL == storage_v1_token_request){
        return ;
    }
    if(storage_v1_token_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "storage_v1_token_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (storage_v1_token_request->audience) {
        free(storage_v1_token_request->audience);
        storage_v1_token_request->audience = NULL;
    }
    free(storage_v1_token_request);
}

cJSON *storage_v1_token_request_convertToJSON(storage_v1_token_request_t *storage_v1_token_request) {
    cJSON *item = cJSON_CreateObject();

    // storage_v1_token_request->audience
    if (!storage_v1_token_request->audience) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "audience", storage_v1_token_request->audience) == NULL) {
    goto fail; //String
    }


    // storage_v1_token_request->expiration_seconds
    if(storage_v1_token_request->expiration_seconds) {
    if(cJSON_AddNumberToObject(item, "expirationSeconds", storage_v1_token_request->expiration_seconds) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

storage_v1_token_request_t *storage_v1_token_request_parseFromJSON(cJSON *storage_v1_token_requestJSON){

    storage_v1_token_request_t *storage_v1_token_request_local_var = NULL;

    // storage_v1_token_request->audience
    cJSON *audience = cJSON_GetObjectItemCaseSensitive(storage_v1_token_requestJSON, "audience");
    if (cJSON_IsNull(audience)) {
        audience = NULL;
    }
    if (!audience) {
        goto end;
    }

    
    if(!cJSON_IsString(audience))
    {
    goto end; //String
    }

    // storage_v1_token_request->expiration_seconds
    cJSON *expiration_seconds = cJSON_GetObjectItemCaseSensitive(storage_v1_token_requestJSON, "expirationSeconds");
    if (cJSON_IsNull(expiration_seconds)) {
        expiration_seconds = NULL;
    }
    if (expiration_seconds) { 
    if(!cJSON_IsNumber(expiration_seconds))
    {
    goto end; //Numeric
    }
    }


    storage_v1_token_request_local_var = storage_v1_token_request_create_internal (
        strdup(audience->valuestring),
        expiration_seconds ? expiration_seconds->valuedouble : 0
        );

    return storage_v1_token_request_local_var;
end:
    return NULL;

}
