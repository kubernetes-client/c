#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_namespace_condition.h"



static v1_namespace_condition_t *v1_namespace_condition_create_internal(
    char *last_transition_time,
    char *message,
    char *reason,
    char *status,
    char *type
    ) {
    v1_namespace_condition_t *v1_namespace_condition_local_var = malloc(sizeof(v1_namespace_condition_t));
    if (!v1_namespace_condition_local_var) {
        return NULL;
    }
    v1_namespace_condition_local_var->last_transition_time = last_transition_time;
    v1_namespace_condition_local_var->message = message;
    v1_namespace_condition_local_var->reason = reason;
    v1_namespace_condition_local_var->status = status;
    v1_namespace_condition_local_var->type = type;

    v1_namespace_condition_local_var->_library_owned = 1;
    return v1_namespace_condition_local_var;
}

__attribute__((deprecated)) v1_namespace_condition_t *v1_namespace_condition_create(
    char *last_transition_time,
    char *message,
    char *reason,
    char *status,
    char *type
    ) {
    return v1_namespace_condition_create_internal (
        last_transition_time,
        message,
        reason,
        status,
        type
        );
}

void v1_namespace_condition_free(v1_namespace_condition_t *v1_namespace_condition) {
    if(NULL == v1_namespace_condition){
        return ;
    }
    if(v1_namespace_condition->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_namespace_condition_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_namespace_condition->last_transition_time) {
        free(v1_namespace_condition->last_transition_time);
        v1_namespace_condition->last_transition_time = NULL;
    }
    if (v1_namespace_condition->message) {
        free(v1_namespace_condition->message);
        v1_namespace_condition->message = NULL;
    }
    if (v1_namespace_condition->reason) {
        free(v1_namespace_condition->reason);
        v1_namespace_condition->reason = NULL;
    }
    if (v1_namespace_condition->status) {
        free(v1_namespace_condition->status);
        v1_namespace_condition->status = NULL;
    }
    if (v1_namespace_condition->type) {
        free(v1_namespace_condition->type);
        v1_namespace_condition->type = NULL;
    }
    free(v1_namespace_condition);
}

cJSON *v1_namespace_condition_convertToJSON(v1_namespace_condition_t *v1_namespace_condition) {
    cJSON *item = cJSON_CreateObject();

    // v1_namespace_condition->last_transition_time
    if(v1_namespace_condition->last_transition_time) {
    if(cJSON_AddStringToObject(item, "lastTransitionTime", v1_namespace_condition->last_transition_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1_namespace_condition->message
    if(v1_namespace_condition->message) {
    if(cJSON_AddStringToObject(item, "message", v1_namespace_condition->message) == NULL) {
    goto fail; //String
    }
    }


    // v1_namespace_condition->reason
    if(v1_namespace_condition->reason) {
    if(cJSON_AddStringToObject(item, "reason", v1_namespace_condition->reason) == NULL) {
    goto fail; //String
    }
    }


    // v1_namespace_condition->status
    if (!v1_namespace_condition->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", v1_namespace_condition->status) == NULL) {
    goto fail; //String
    }


    // v1_namespace_condition->type
    if (!v1_namespace_condition->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", v1_namespace_condition->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_namespace_condition_t *v1_namespace_condition_parseFromJSON(cJSON *v1_namespace_conditionJSON){

    v1_namespace_condition_t *v1_namespace_condition_local_var = NULL;

    // v1_namespace_condition->last_transition_time
    cJSON *last_transition_time = cJSON_GetObjectItemCaseSensitive(v1_namespace_conditionJSON, "lastTransitionTime");
    if (cJSON_IsNull(last_transition_time)) {
        last_transition_time = NULL;
    }
    if (last_transition_time) { 
    if(!cJSON_IsString(last_transition_time) && !cJSON_IsNull(last_transition_time))
    {
    goto end; //DateTime
    }
    }

    // v1_namespace_condition->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1_namespace_conditionJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // v1_namespace_condition->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1_namespace_conditionJSON, "reason");
    if (cJSON_IsNull(reason)) {
        reason = NULL;
    }
    if (reason) { 
    if(!cJSON_IsString(reason) && !cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }

    // v1_namespace_condition->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_namespace_conditionJSON, "status");
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

    // v1_namespace_condition->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_namespace_conditionJSON, "type");
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


    v1_namespace_condition_local_var = v1_namespace_condition_create_internal (
        last_transition_time && !cJSON_IsNull(last_transition_time) ? strdup(last_transition_time->valuestring) : NULL,
        message && !cJSON_IsNull(message) ? strdup(message->valuestring) : NULL,
        reason && !cJSON_IsNull(reason) ? strdup(reason->valuestring) : NULL,
        strdup(status->valuestring),
        strdup(type->valuestring)
        );

    return v1_namespace_condition_local_var;
end:
    return NULL;

}
