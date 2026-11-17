#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_volume_health_condition.h"



static v1_volume_health_condition_t *v1_volume_health_condition_create_internal(
    char *message,
    char *reason,
    char *status
    ) {
    v1_volume_health_condition_t *v1_volume_health_condition_local_var = malloc(sizeof(v1_volume_health_condition_t));
    if (!v1_volume_health_condition_local_var) {
        return NULL;
    }
    memset(v1_volume_health_condition_local_var, 0, sizeof(v1_volume_health_condition_t));
    v1_volume_health_condition_local_var->_library_owned = 1;
    v1_volume_health_condition_local_var->message = message;
    v1_volume_health_condition_local_var->reason = reason;
    v1_volume_health_condition_local_var->status = status;
    return v1_volume_health_condition_local_var;
}

__attribute__((deprecated)) v1_volume_health_condition_t *v1_volume_health_condition_create(
    char *message,
    char *reason,
    char *status
    ) {
    v1_volume_health_condition_t *result = v1_volume_health_condition_create_internal (
        message,
        reason,
        status
        );
    if (!result) {
    }
    return result;
}

void v1_volume_health_condition_free(v1_volume_health_condition_t *v1_volume_health_condition) {
    if(NULL == v1_volume_health_condition){
        return ;
    }
    if(v1_volume_health_condition->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_volume_health_condition_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_volume_health_condition->message) {
        free(v1_volume_health_condition->message);
        v1_volume_health_condition->message = NULL;
    }
    if (v1_volume_health_condition->reason) {
        free(v1_volume_health_condition->reason);
        v1_volume_health_condition->reason = NULL;
    }
    if (v1_volume_health_condition->status) {
        free(v1_volume_health_condition->status);
        v1_volume_health_condition->status = NULL;
    }
    free(v1_volume_health_condition);
}

cJSON *v1_volume_health_condition_convertToJSON(v1_volume_health_condition_t *v1_volume_health_condition) {
    cJSON *item = cJSON_CreateObject();

    // v1_volume_health_condition->message
    if(v1_volume_health_condition->message) {
    if(cJSON_AddStringToObject(item, "message", v1_volume_health_condition->message) == NULL) {
    goto fail; //String
    }
    }


    // v1_volume_health_condition->reason
    if (!v1_volume_health_condition->reason) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "reason", v1_volume_health_condition->reason) == NULL) {
    goto fail; //String
    }


    // v1_volume_health_condition->status
    if (!v1_volume_health_condition->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", v1_volume_health_condition->status) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_volume_health_condition_t *v1_volume_health_condition_parseFromJSON(cJSON *v1_volume_health_conditionJSON){

    v1_volume_health_condition_t *v1_volume_health_condition_local_var = NULL;

    char *message_local_str = NULL;

    char *reason_local_str = NULL;

    char *status_local_str = NULL;

    // v1_volume_health_condition->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1_volume_health_conditionJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // v1_volume_health_condition->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1_volume_health_conditionJSON, "reason");
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

    // v1_volume_health_condition->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_volume_health_conditionJSON, "status");
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


    if (message && !cJSON_IsNull(message)) message_local_str = strdup(message->valuestring);
    if (reason && !cJSON_IsNull(reason)) reason_local_str = strdup(reason->valuestring);
    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);

    v1_volume_health_condition_local_var = v1_volume_health_condition_create_internal (
        message_local_str,
        reason_local_str,
        status_local_str
        );

    if (!v1_volume_health_condition_local_var) {
        goto end;
    }

    return v1_volume_health_condition_local_var;
end:
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
    return NULL;

}
