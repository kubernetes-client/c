#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_service_account_token_projection.h"



v1_service_account_token_projection_t *v1_service_account_token_projection_create(
    char *audience,
    long expiration_seconds,
    char *path
    ) {
    v1_service_account_token_projection_t *v1_service_account_token_projection_local_var = malloc(sizeof(v1_service_account_token_projection_t));
    if (!v1_service_account_token_projection_local_var) {
        return NULL;
    }
    v1_service_account_token_projection_local_var->audience = audience;
    v1_service_account_token_projection_local_var->expiration_seconds = expiration_seconds;
    v1_service_account_token_projection_local_var->path = path;

    return v1_service_account_token_projection_local_var;
}


void v1_service_account_token_projection_free(v1_service_account_token_projection_t *v1_service_account_token_projection) {
    if(NULL == v1_service_account_token_projection){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_service_account_token_projection->audience) {
        free(v1_service_account_token_projection->audience);
        v1_service_account_token_projection->audience = NULL;
    }
    if (v1_service_account_token_projection->path) {
        free(v1_service_account_token_projection->path);
        v1_service_account_token_projection->path = NULL;
    }
    free(v1_service_account_token_projection);
}

cJSON *v1_service_account_token_projection_convertToJSON(v1_service_account_token_projection_t *v1_service_account_token_projection) {
    cJSON *item = cJSON_CreateObject();

    // v1_service_account_token_projection->audience
    if(v1_service_account_token_projection->audience) { 
    if(cJSON_AddStringToObject(item, "audience", v1_service_account_token_projection->audience) == NULL) {
    goto fail; //String
    }
     } 


    // v1_service_account_token_projection->expiration_seconds
    if(v1_service_account_token_projection->expiration_seconds) { 
    if(cJSON_AddNumberToObject(item, "expirationSeconds", v1_service_account_token_projection->expiration_seconds) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_service_account_token_projection->path
    if (!v1_service_account_token_projection->path) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "path", v1_service_account_token_projection->path) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_service_account_token_projection_t *v1_service_account_token_projection_parseFromJSON(cJSON *v1_service_account_token_projectionJSON){

    v1_service_account_token_projection_t *v1_service_account_token_projection_local_var = NULL;

    // v1_service_account_token_projection->audience
    cJSON *audience = cJSON_GetObjectItemCaseSensitive(v1_service_account_token_projectionJSON, "audience");
    if (audience) { 
    if(!cJSON_IsString(audience))
    {
    goto end; //String
    }
    }

    // v1_service_account_token_projection->expiration_seconds
    cJSON *expiration_seconds = cJSON_GetObjectItemCaseSensitive(v1_service_account_token_projectionJSON, "expirationSeconds");
    if (expiration_seconds) { 
    if(!cJSON_IsNumber(expiration_seconds))
    {
    goto end; //Numeric
    }
    }

    // v1_service_account_token_projection->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(v1_service_account_token_projectionJSON, "path");
    if (!path) {
        goto end;
    }

    
    if(!cJSON_IsString(path))
    {
    goto end; //String
    }


    v1_service_account_token_projection_local_var = v1_service_account_token_projection_create (
        audience ? strdup(audience->valuestring) : NULL,
        expiration_seconds ? expiration_seconds->valuedouble : 0,
        strdup(path->valuestring)
        );

    return v1_service_account_token_projection_local_var;
end:
    return NULL;

}
