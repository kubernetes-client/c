#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_priority_level_configuration_condition.h"



static v1_priority_level_configuration_condition_t *v1_priority_level_configuration_condition_create_internal(
    char *last_transition_time,
    char *message,
    char *reason,
    char *status,
    char *type
    ) {
    v1_priority_level_configuration_condition_t *v1_priority_level_configuration_condition_local_var = malloc(sizeof(v1_priority_level_configuration_condition_t));
    if (!v1_priority_level_configuration_condition_local_var) {
        return NULL;
    }
    memset(v1_priority_level_configuration_condition_local_var, 0, sizeof(v1_priority_level_configuration_condition_t));
    v1_priority_level_configuration_condition_local_var->_library_owned = 1;
    v1_priority_level_configuration_condition_local_var->last_transition_time = last_transition_time;
    v1_priority_level_configuration_condition_local_var->message = message;
    v1_priority_level_configuration_condition_local_var->reason = reason;
    v1_priority_level_configuration_condition_local_var->status = status;
    v1_priority_level_configuration_condition_local_var->type = type;
    return v1_priority_level_configuration_condition_local_var;
}

__attribute__((deprecated)) v1_priority_level_configuration_condition_t *v1_priority_level_configuration_condition_create(
    char *last_transition_time,
    char *message,
    char *reason,
    char *status,
    char *type
    ) {
    v1_priority_level_configuration_condition_t *result = v1_priority_level_configuration_condition_create_internal (
        last_transition_time,
        message,
        reason,
        status,
        type
        );
    if (!result) {
    }
    return result;
}

void v1_priority_level_configuration_condition_free(v1_priority_level_configuration_condition_t *v1_priority_level_configuration_condition) {
    if(NULL == v1_priority_level_configuration_condition){
        return ;
    }
    if(v1_priority_level_configuration_condition->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_priority_level_configuration_condition_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_priority_level_configuration_condition->last_transition_time) {
        free(v1_priority_level_configuration_condition->last_transition_time);
        v1_priority_level_configuration_condition->last_transition_time = NULL;
    }
    if (v1_priority_level_configuration_condition->message) {
        free(v1_priority_level_configuration_condition->message);
        v1_priority_level_configuration_condition->message = NULL;
    }
    if (v1_priority_level_configuration_condition->reason) {
        free(v1_priority_level_configuration_condition->reason);
        v1_priority_level_configuration_condition->reason = NULL;
    }
    if (v1_priority_level_configuration_condition->status) {
        free(v1_priority_level_configuration_condition->status);
        v1_priority_level_configuration_condition->status = NULL;
    }
    if (v1_priority_level_configuration_condition->type) {
        free(v1_priority_level_configuration_condition->type);
        v1_priority_level_configuration_condition->type = NULL;
    }
    free(v1_priority_level_configuration_condition);
}

cJSON *v1_priority_level_configuration_condition_convertToJSON(v1_priority_level_configuration_condition_t *v1_priority_level_configuration_condition) {
    cJSON *item = cJSON_CreateObject();

    // v1_priority_level_configuration_condition->last_transition_time
    if(v1_priority_level_configuration_condition->last_transition_time) {
    if(cJSON_AddStringToObject(item, "lastTransitionTime", v1_priority_level_configuration_condition->last_transition_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1_priority_level_configuration_condition->message
    if(v1_priority_level_configuration_condition->message) {
    if(cJSON_AddStringToObject(item, "message", v1_priority_level_configuration_condition->message) == NULL) {
    goto fail; //String
    }
    }


    // v1_priority_level_configuration_condition->reason
    if(v1_priority_level_configuration_condition->reason) {
    if(cJSON_AddStringToObject(item, "reason", v1_priority_level_configuration_condition->reason) == NULL) {
    goto fail; //String
    }
    }


    // v1_priority_level_configuration_condition->status
    if(v1_priority_level_configuration_condition->status) {
    if(cJSON_AddStringToObject(item, "status", v1_priority_level_configuration_condition->status) == NULL) {
    goto fail; //String
    }
    }


    // v1_priority_level_configuration_condition->type
    if (!v1_priority_level_configuration_condition->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", v1_priority_level_configuration_condition->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_priority_level_configuration_condition_t *v1_priority_level_configuration_condition_parseFromJSON(cJSON *v1_priority_level_configuration_conditionJSON){

    v1_priority_level_configuration_condition_t *v1_priority_level_configuration_condition_local_var = NULL;

    char *last_transition_time_local_str = NULL;

    char *message_local_str = NULL;

    char *reason_local_str = NULL;

    char *status_local_str = NULL;

    char *type_local_str = NULL;

    // v1_priority_level_configuration_condition->last_transition_time
    cJSON *last_transition_time = cJSON_GetObjectItemCaseSensitive(v1_priority_level_configuration_conditionJSON, "lastTransitionTime");
    if (cJSON_IsNull(last_transition_time)) {
        last_transition_time = NULL;
    }
    if (last_transition_time) { 
    if(!cJSON_IsString(last_transition_time) && !cJSON_IsNull(last_transition_time))
    {
    goto end; //DateTime
    }
    }

    // v1_priority_level_configuration_condition->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1_priority_level_configuration_conditionJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // v1_priority_level_configuration_condition->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1_priority_level_configuration_conditionJSON, "reason");
    if (cJSON_IsNull(reason)) {
        reason = NULL;
    }
    if (reason) { 
    if(!cJSON_IsString(reason) && !cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }

    // v1_priority_level_configuration_condition->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_priority_level_configuration_conditionJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    if(!cJSON_IsString(status) && !cJSON_IsNull(status))
    {
    goto end; //String
    }
    }

    // v1_priority_level_configuration_condition->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_priority_level_configuration_conditionJSON, "type");
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


    if (last_transition_time && !cJSON_IsNull(last_transition_time)) last_transition_time_local_str = strdup(last_transition_time->valuestring);
    if (message && !cJSON_IsNull(message)) message_local_str = strdup(message->valuestring);
    if (reason && !cJSON_IsNull(reason)) reason_local_str = strdup(reason->valuestring);
    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);
    if (type && !cJSON_IsNull(type)) type_local_str = strdup(type->valuestring);

    v1_priority_level_configuration_condition_local_var = v1_priority_level_configuration_condition_create_internal (
        last_transition_time_local_str,
        message_local_str,
        reason_local_str,
        status_local_str,
        type_local_str
        );

    if (!v1_priority_level_configuration_condition_local_var) {
        goto end;
    }

    return v1_priority_level_configuration_condition_local_var;
end:
    if (last_transition_time_local_str) {
        free(last_transition_time_local_str);
        last_transition_time_local_str = NULL;
    }
    if (message_local_str) {
        free(message_local_str);
        message_local_str = NULL;
    }
    if (reason_local_str) {
        free(reason_local_str);
        reason_local_str = NULL;
    }
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    if (type_local_str) {
        free(type_local_str);
        type_local_str = NULL;
    }
    return NULL;

}
