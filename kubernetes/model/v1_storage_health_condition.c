#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_storage_health_condition.h"



static v1_storage_health_condition_t *v1_storage_health_condition_create_internal(
    char *access_mode,
    char *last_transition_time,
    char *message,
    char *reason,
    char *status,
    char *volume_mode
    ) {
    v1_storage_health_condition_t *v1_storage_health_condition_local_var = malloc(sizeof(v1_storage_health_condition_t));
    if (!v1_storage_health_condition_local_var) {
        return NULL;
    }
    memset(v1_storage_health_condition_local_var, 0, sizeof(v1_storage_health_condition_t));
    v1_storage_health_condition_local_var->_library_owned = 1;
    v1_storage_health_condition_local_var->access_mode = access_mode;
    v1_storage_health_condition_local_var->last_transition_time = last_transition_time;
    v1_storage_health_condition_local_var->message = message;
    v1_storage_health_condition_local_var->reason = reason;
    v1_storage_health_condition_local_var->status = status;
    v1_storage_health_condition_local_var->volume_mode = volume_mode;
    return v1_storage_health_condition_local_var;
}

__attribute__((deprecated)) v1_storage_health_condition_t *v1_storage_health_condition_create(
    char *access_mode,
    char *last_transition_time,
    char *message,
    char *reason,
    char *status,
    char *volume_mode
    ) {
    v1_storage_health_condition_t *result = v1_storage_health_condition_create_internal (
        access_mode,
        last_transition_time,
        message,
        reason,
        status,
        volume_mode
        );
    if (!result) {
    }
    return result;
}

void v1_storage_health_condition_free(v1_storage_health_condition_t *v1_storage_health_condition) {
    if(NULL == v1_storage_health_condition){
        return ;
    }
    if(v1_storage_health_condition->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_storage_health_condition_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_storage_health_condition->access_mode) {
        free(v1_storage_health_condition->access_mode);
        v1_storage_health_condition->access_mode = NULL;
    }
    if (v1_storage_health_condition->last_transition_time) {
        free(v1_storage_health_condition->last_transition_time);
        v1_storage_health_condition->last_transition_time = NULL;
    }
    if (v1_storage_health_condition->message) {
        free(v1_storage_health_condition->message);
        v1_storage_health_condition->message = NULL;
    }
    if (v1_storage_health_condition->reason) {
        free(v1_storage_health_condition->reason);
        v1_storage_health_condition->reason = NULL;
    }
    if (v1_storage_health_condition->status) {
        free(v1_storage_health_condition->status);
        v1_storage_health_condition->status = NULL;
    }
    if (v1_storage_health_condition->volume_mode) {
        free(v1_storage_health_condition->volume_mode);
        v1_storage_health_condition->volume_mode = NULL;
    }
    free(v1_storage_health_condition);
}

cJSON *v1_storage_health_condition_convertToJSON(v1_storage_health_condition_t *v1_storage_health_condition) {
    cJSON *item = cJSON_CreateObject();

    // v1_storage_health_condition->access_mode
    if(v1_storage_health_condition->access_mode) {
    if(cJSON_AddStringToObject(item, "accessMode", v1_storage_health_condition->access_mode) == NULL) {
    goto fail; //String
    }
    }


    // v1_storage_health_condition->last_transition_time
    if(v1_storage_health_condition->last_transition_time) {
    if(cJSON_AddStringToObject(item, "lastTransitionTime", v1_storage_health_condition->last_transition_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1_storage_health_condition->message
    if(v1_storage_health_condition->message) {
    if(cJSON_AddStringToObject(item, "message", v1_storage_health_condition->message) == NULL) {
    goto fail; //String
    }
    }


    // v1_storage_health_condition->reason
    if (!v1_storage_health_condition->reason) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "reason", v1_storage_health_condition->reason) == NULL) {
    goto fail; //String
    }


    // v1_storage_health_condition->status
    if (!v1_storage_health_condition->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", v1_storage_health_condition->status) == NULL) {
    goto fail; //String
    }


    // v1_storage_health_condition->volume_mode
    if(v1_storage_health_condition->volume_mode) {
    if(cJSON_AddStringToObject(item, "volumeMode", v1_storage_health_condition->volume_mode) == NULL) {
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

v1_storage_health_condition_t *v1_storage_health_condition_parseFromJSON(cJSON *v1_storage_health_conditionJSON){

    v1_storage_health_condition_t *v1_storage_health_condition_local_var = NULL;

    char *access_mode_local_str = NULL;

    char *last_transition_time_local_str = NULL;

    char *message_local_str = NULL;

    char *reason_local_str = NULL;

    char *status_local_str = NULL;

    char *volume_mode_local_str = NULL;

    // v1_storage_health_condition->access_mode
    cJSON *access_mode = cJSON_GetObjectItemCaseSensitive(v1_storage_health_conditionJSON, "accessMode");
    if (cJSON_IsNull(access_mode)) {
        access_mode = NULL;
    }
    if (access_mode) { 
    if(!cJSON_IsString(access_mode) && !cJSON_IsNull(access_mode))
    {
    goto end; //String
    }
    }

    // v1_storage_health_condition->last_transition_time
    cJSON *last_transition_time = cJSON_GetObjectItemCaseSensitive(v1_storage_health_conditionJSON, "lastTransitionTime");
    if (cJSON_IsNull(last_transition_time)) {
        last_transition_time = NULL;
    }
    if (last_transition_time) { 
    if(!cJSON_IsString(last_transition_time) && !cJSON_IsNull(last_transition_time))
    {
    goto end; //DateTime
    }
    }

    // v1_storage_health_condition->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1_storage_health_conditionJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // v1_storage_health_condition->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1_storage_health_conditionJSON, "reason");
    if (cJSON_IsNull(reason)) {
        reason = NULL;
    }
    if (!reason) {
        goto end;
    }

    
    if(!cJSON_IsString(reason))
    {
    goto end; //String
    }

    // v1_storage_health_condition->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_storage_health_conditionJSON, "status");
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

    // v1_storage_health_condition->volume_mode
    cJSON *volume_mode = cJSON_GetObjectItemCaseSensitive(v1_storage_health_conditionJSON, "volumeMode");
    if (cJSON_IsNull(volume_mode)) {
        volume_mode = NULL;
    }
    if (volume_mode) { 
    if(!cJSON_IsString(volume_mode) && !cJSON_IsNull(volume_mode))
    {
    goto end; //String
    }
    }


    if (access_mode && !cJSON_IsNull(access_mode)) access_mode_local_str = strdup(access_mode->valuestring);
    if (last_transition_time && !cJSON_IsNull(last_transition_time)) last_transition_time_local_str = strdup(last_transition_time->valuestring);
    if (message && !cJSON_IsNull(message)) message_local_str = strdup(message->valuestring);
    if (reason && !cJSON_IsNull(reason)) reason_local_str = strdup(reason->valuestring);
    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);
    if (volume_mode && !cJSON_IsNull(volume_mode)) volume_mode_local_str = strdup(volume_mode->valuestring);

    v1_storage_health_condition_local_var = v1_storage_health_condition_create_internal (
        access_mode_local_str,
        last_transition_time_local_str,
        message_local_str,
        reason_local_str,
        status_local_str,
        volume_mode_local_str
        );

    if (!v1_storage_health_condition_local_var) {
        goto end;
    }

    return v1_storage_health_condition_local_var;
end:
    if (access_mode_local_str) {
        free(access_mode_local_str);
        access_mode_local_str = NULL;
    }
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
    if (volume_mode_local_str) {
        free(volume_mode_local_str);
        volume_mode_local_str = NULL;
    }
    return NULL;

}
