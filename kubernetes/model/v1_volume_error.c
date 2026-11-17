#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_volume_error.h"



static v1_volume_error_t *v1_volume_error_create_internal(
    int *error_code,
    char *message,
    char *time
    ) {
    v1_volume_error_t *v1_volume_error_local_var = malloc(sizeof(v1_volume_error_t));
    if (!v1_volume_error_local_var) {
        return NULL;
    }
    memset(v1_volume_error_local_var, 0, sizeof(v1_volume_error_t));
    v1_volume_error_local_var->_library_owned = 1;
    v1_volume_error_local_var->error_code = error_code;
    v1_volume_error_local_var->message = message;
    v1_volume_error_local_var->time = time;
    return v1_volume_error_local_var;
}

__attribute__((deprecated)) v1_volume_error_t *v1_volume_error_create(
    int *error_code,
    char *message,
    char *time
    ) {
    int *error_code_copy = NULL;
    if (error_code) {
        error_code_copy = malloc(sizeof(int));
        if (error_code_copy) *error_code_copy = *error_code;
    }
    v1_volume_error_t *result = v1_volume_error_create_internal (
        error_code_copy,
        message,
        time
        );
    if (!result) {
        free(error_code_copy);
    }
    return result;
}

void v1_volume_error_free(v1_volume_error_t *v1_volume_error) {
    if(NULL == v1_volume_error){
        return ;
    }
    if(v1_volume_error->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_volume_error_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_volume_error->error_code) {
        free(v1_volume_error->error_code);
        v1_volume_error->error_code = NULL;
    }
    if (v1_volume_error->message) {
        free(v1_volume_error->message);
        v1_volume_error->message = NULL;
    }
    if (v1_volume_error->time) {
        free(v1_volume_error->time);
        v1_volume_error->time = NULL;
    }
    free(v1_volume_error);
}

cJSON *v1_volume_error_convertToJSON(v1_volume_error_t *v1_volume_error) {
    cJSON *item = cJSON_CreateObject();

    // v1_volume_error->error_code
    if(v1_volume_error->error_code) {
    if(cJSON_AddNumberToObject(item, "errorCode", *v1_volume_error->error_code) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_volume_error->message
    if(v1_volume_error->message) {
    if(cJSON_AddStringToObject(item, "message", v1_volume_error->message) == NULL) {
    goto fail; //String
    }
    }


    // v1_volume_error->time
    if(v1_volume_error->time) {
    if(cJSON_AddStringToObject(item, "time", v1_volume_error->time) == NULL) {
    goto fail; //Date-Time
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_volume_error_t *v1_volume_error_parseFromJSON(cJSON *v1_volume_errorJSON){

    v1_volume_error_t *v1_volume_error_local_var = NULL;

    // define the local variable for v1_volume_error->error_code
    int *error_code_local_var = NULL;

    char *message_local_str = NULL;

    char *time_local_str = NULL;

    // v1_volume_error->error_code
    cJSON *error_code = cJSON_GetObjectItemCaseSensitive(v1_volume_errorJSON, "errorCode");
    if (cJSON_IsNull(error_code)) {
        error_code = NULL;
    }
    if (error_code) { 
    if(!cJSON_IsNumber(error_code))
    {
    goto end; //Numeric
    }
    error_code_local_var = malloc(sizeof(int));
    if(!error_code_local_var)
    {
        goto end;
    }
    *error_code_local_var = error_code->valuedouble;
    }

    // v1_volume_error->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1_volume_errorJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // v1_volume_error->time
    cJSON *time = cJSON_GetObjectItemCaseSensitive(v1_volume_errorJSON, "time");
    if (cJSON_IsNull(time)) {
        time = NULL;
    }
    if (time) { 
    if(!cJSON_IsString(time) && !cJSON_IsNull(time))
    {
    goto end; //DateTime
    }
    }


    if (message && !cJSON_IsNull(message)) message_local_str = strdup(message->valuestring);
    if (time && !cJSON_IsNull(time)) time_local_str = strdup(time->valuestring);

    v1_volume_error_local_var = v1_volume_error_create_internal (
        error_code_local_var,
        message_local_str,
        time_local_str
        );

    if (!v1_volume_error_local_var) {
        goto end;
    }

    return v1_volume_error_local_var;
end:
    if (error_code_local_var) {
        free(error_code_local_var);
        error_code_local_var = NULL;
    }
    if (message_local_str) {
        free(message_local_str);
        message_local_str = NULL;
    }
    if (time_local_str) {
        free(time_local_str);
        time_local_str = NULL;
    }
    return NULL;

}
