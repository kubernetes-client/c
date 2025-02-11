#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_volume_error.h"



static v1_volume_error_t *v1_volume_error_create_internal(
    char *message,
    char *time
    ) {
    v1_volume_error_t *v1_volume_error_local_var = malloc(sizeof(v1_volume_error_t));
    if (!v1_volume_error_local_var) {
        return NULL;
    }
    v1_volume_error_local_var->message = message;
    v1_volume_error_local_var->time = time;

    v1_volume_error_local_var->_library_owned = 1;
    return v1_volume_error_local_var;
}

__attribute__((deprecated)) v1_volume_error_t *v1_volume_error_create(
    char *message,
    char *time
    ) {
    return v1_volume_error_create_internal (
        message,
        time
        );
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


    v1_volume_error_local_var = v1_volume_error_create_internal (
        message && !cJSON_IsNull(message) ? strdup(message->valuestring) : NULL,
        time && !cJSON_IsNull(time) ? strdup(time->valuestring) : NULL
        );

    return v1_volume_error_local_var;
end:
    return NULL;

}
