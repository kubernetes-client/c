#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_component_condition.h"



static v1_component_condition_t *v1_component_condition_create_internal(
    char *error,
    char *message,
    char *status,
    char *type
    ) {
    v1_component_condition_t *v1_component_condition_local_var = malloc(sizeof(v1_component_condition_t));
    if (!v1_component_condition_local_var) {
        return NULL;
    }
    v1_component_condition_local_var->error = error;
    v1_component_condition_local_var->message = message;
    v1_component_condition_local_var->status = status;
    v1_component_condition_local_var->type = type;

    v1_component_condition_local_var->_library_owned = 1;
    return v1_component_condition_local_var;
}

__attribute__((deprecated)) v1_component_condition_t *v1_component_condition_create(
    char *error,
    char *message,
    char *status,
    char *type
    ) {
    return v1_component_condition_create_internal (
        error,
        message,
        status,
        type
        );
}

void v1_component_condition_free(v1_component_condition_t *v1_component_condition) {
    if(NULL == v1_component_condition){
        return ;
    }
    if(v1_component_condition->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_component_condition_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_component_condition->error) {
        free(v1_component_condition->error);
        v1_component_condition->error = NULL;
    }
    if (v1_component_condition->message) {
        free(v1_component_condition->message);
        v1_component_condition->message = NULL;
    }
    if (v1_component_condition->status) {
        free(v1_component_condition->status);
        v1_component_condition->status = NULL;
    }
    if (v1_component_condition->type) {
        free(v1_component_condition->type);
        v1_component_condition->type = NULL;
    }
    free(v1_component_condition);
}

cJSON *v1_component_condition_convertToJSON(v1_component_condition_t *v1_component_condition) {
    cJSON *item = cJSON_CreateObject();

    // v1_component_condition->error
    if(v1_component_condition->error) {
    if(cJSON_AddStringToObject(item, "error", v1_component_condition->error) == NULL) {
    goto fail; //String
    }
    }


    // v1_component_condition->message
    if(v1_component_condition->message) {
    if(cJSON_AddStringToObject(item, "message", v1_component_condition->message) == NULL) {
    goto fail; //String
    }
    }


    // v1_component_condition->status
    if (!v1_component_condition->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", v1_component_condition->status) == NULL) {
    goto fail; //String
    }


    // v1_component_condition->type
    if (!v1_component_condition->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", v1_component_condition->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_component_condition_t *v1_component_condition_parseFromJSON(cJSON *v1_component_conditionJSON){

    v1_component_condition_t *v1_component_condition_local_var = NULL;

    // v1_component_condition->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(v1_component_conditionJSON, "error");
    if (cJSON_IsNull(error)) {
        error = NULL;
    }
    if (error) { 
    if(!cJSON_IsString(error) && !cJSON_IsNull(error))
    {
    goto end; //String
    }
    }

    // v1_component_condition->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1_component_conditionJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // v1_component_condition->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_component_conditionJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    if(!cJSON_IsString(status))
    {
    goto end; //String
    }

    // v1_component_condition->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_component_conditionJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }


    v1_component_condition_local_var = v1_component_condition_create_internal (
        error && !cJSON_IsNull(error) ? strdup(error->valuestring) : NULL,
        message && !cJSON_IsNull(message) ? strdup(message->valuestring) : NULL,
        strdup(status->valuestring),
        strdup(type->valuestring)
        );

    return v1_component_condition_local_var;
end:
    return NULL;

}
