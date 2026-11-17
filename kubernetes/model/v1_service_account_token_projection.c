#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_service_account_token_projection.h"



static v1_service_account_token_projection_t *v1_service_account_token_projection_create_internal(
    char *audience,
    long *expiration_seconds,
    char *path,
    long *user
    ) {
    v1_service_account_token_projection_t *v1_service_account_token_projection_local_var = malloc(sizeof(v1_service_account_token_projection_t));
    if (!v1_service_account_token_projection_local_var) {
        return NULL;
    }
    memset(v1_service_account_token_projection_local_var, 0, sizeof(v1_service_account_token_projection_t));
    v1_service_account_token_projection_local_var->_library_owned = 1;
    v1_service_account_token_projection_local_var->audience = audience;
    v1_service_account_token_projection_local_var->expiration_seconds = expiration_seconds;
    v1_service_account_token_projection_local_var->path = path;
    v1_service_account_token_projection_local_var->user = user;
    return v1_service_account_token_projection_local_var;
}

__attribute__((deprecated)) v1_service_account_token_projection_t *v1_service_account_token_projection_create(
    char *audience,
    long *expiration_seconds,
    char *path,
    long *user
    ) {
    long *expiration_seconds_copy = NULL;
    if (expiration_seconds) {
        expiration_seconds_copy = malloc(sizeof(long));
        if (expiration_seconds_copy) *expiration_seconds_copy = *expiration_seconds;
    }
    long *user_copy = NULL;
    if (user) {
        user_copy = malloc(sizeof(long));
        if (user_copy) *user_copy = *user;
    }
    v1_service_account_token_projection_t *result = v1_service_account_token_projection_create_internal (
        audience,
        expiration_seconds_copy,
        path,
        user_copy
        );
    if (!result) {
        free(expiration_seconds_copy);
        free(user_copy);
    }
    return result;
}

void v1_service_account_token_projection_free(v1_service_account_token_projection_t *v1_service_account_token_projection) {
    if(NULL == v1_service_account_token_projection){
        return ;
    }
    if(v1_service_account_token_projection->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_service_account_token_projection_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_service_account_token_projection->audience) {
        free(v1_service_account_token_projection->audience);
        v1_service_account_token_projection->audience = NULL;
    }
    if (v1_service_account_token_projection->expiration_seconds) {
        free(v1_service_account_token_projection->expiration_seconds);
        v1_service_account_token_projection->expiration_seconds = NULL;
    }
    if (v1_service_account_token_projection->path) {
        free(v1_service_account_token_projection->path);
        v1_service_account_token_projection->path = NULL;
    }
    if (v1_service_account_token_projection->user) {
        free(v1_service_account_token_projection->user);
        v1_service_account_token_projection->user = NULL;
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
    if(cJSON_AddNumberToObject(item, "expirationSeconds", *v1_service_account_token_projection->expiration_seconds) == NULL) {
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


    // v1_service_account_token_projection->user
    if(v1_service_account_token_projection->user) {
    if(cJSON_AddNumberToObject(item, "user", *v1_service_account_token_projection->user) == NULL) {
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

v1_service_account_token_projection_t *v1_service_account_token_projection_parseFromJSON(cJSON *v1_service_account_token_projectionJSON){

    v1_service_account_token_projection_t *v1_service_account_token_projection_local_var = NULL;

    char *audience_local_str = NULL;

    // define the local variable for v1_service_account_token_projection->expiration_seconds
    long *expiration_seconds_local_var = NULL;

    char *path_local_str = NULL;

    // define the local variable for v1_service_account_token_projection->user
    long *user_local_var = NULL;

    // v1_service_account_token_projection->audience
    cJSON *audience = cJSON_GetObjectItemCaseSensitive(v1_service_account_token_projectionJSON, "audience");
    if (cJSON_IsNull(audience)) {
        audience = NULL;
    }
    if (audience) { 
    if(!cJSON_IsString(audience) && !cJSON_IsNull(audience))
    {
    goto end; //String
    }
    }

    // v1_service_account_token_projection->expiration_seconds
    cJSON *expiration_seconds = cJSON_GetObjectItemCaseSensitive(v1_service_account_token_projectionJSON, "expirationSeconds");
    if (cJSON_IsNull(expiration_seconds)) {
        expiration_seconds = NULL;
    }
    if (expiration_seconds) { 
    if(!cJSON_IsNumber(expiration_seconds))
    {
    goto end; //Numeric
    }
    expiration_seconds_local_var = malloc(sizeof(long));
    if(!expiration_seconds_local_var)
    {
        goto end;
    }
    *expiration_seconds_local_var = expiration_seconds->valuedouble;
    }

    // v1_service_account_token_projection->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(v1_service_account_token_projectionJSON, "path");
    if (cJSON_IsNull(path)) {
        path = NULL;
    }
    if (!path) {
        goto end;
    }

    
    if(!cJSON_IsString(path))
    {
    goto end; //String
    }

    // v1_service_account_token_projection->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(v1_service_account_token_projectionJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (user) { 
    if(!cJSON_IsNumber(user))
    {
    goto end; //Numeric
    }
    user_local_var = malloc(sizeof(long));
    if(!user_local_var)
    {
        goto end;
    }
    *user_local_var = user->valuedouble;
    }


    if (audience && !cJSON_IsNull(audience)) audience_local_str = strdup(audience->valuestring);
    if (path && !cJSON_IsNull(path)) path_local_str = strdup(path->valuestring);

    v1_service_account_token_projection_local_var = v1_service_account_token_projection_create_internal (
        audience_local_str,
        expiration_seconds_local_var,
        path_local_str,
        user_local_var
        );

    if (!v1_service_account_token_projection_local_var) {
        goto end;
    }

    return v1_service_account_token_projection_local_var;
end:
    if (audience_local_str) {
        free(audience_local_str);
        audience_local_str = NULL;
    }
    if (expiration_seconds_local_var) {
        free(expiration_seconds_local_var);
        expiration_seconds_local_var = NULL;
    }
    if (path_local_str) {
        free(path_local_str);
        path_local_str = NULL;
    }
    if (user_local_var) {
        free(user_local_var);
        user_local_var = NULL;
    }
    return NULL;

}
