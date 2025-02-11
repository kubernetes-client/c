#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_migration_condition.h"



static v1alpha1_migration_condition_t *v1alpha1_migration_condition_create_internal(
    char *last_update_time,
    char *message,
    char *reason,
    char *status,
    char *type
    ) {
    v1alpha1_migration_condition_t *v1alpha1_migration_condition_local_var = malloc(sizeof(v1alpha1_migration_condition_t));
    if (!v1alpha1_migration_condition_local_var) {
        return NULL;
    }
    v1alpha1_migration_condition_local_var->last_update_time = last_update_time;
    v1alpha1_migration_condition_local_var->message = message;
    v1alpha1_migration_condition_local_var->reason = reason;
    v1alpha1_migration_condition_local_var->status = status;
    v1alpha1_migration_condition_local_var->type = type;

    v1alpha1_migration_condition_local_var->_library_owned = 1;
    return v1alpha1_migration_condition_local_var;
}

__attribute__((deprecated)) v1alpha1_migration_condition_t *v1alpha1_migration_condition_create(
    char *last_update_time,
    char *message,
    char *reason,
    char *status,
    char *type
    ) {
    return v1alpha1_migration_condition_create_internal (
        last_update_time,
        message,
        reason,
        status,
        type
        );
}

void v1alpha1_migration_condition_free(v1alpha1_migration_condition_t *v1alpha1_migration_condition) {
    if(NULL == v1alpha1_migration_condition){
        return ;
    }
    if(v1alpha1_migration_condition->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha1_migration_condition_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_migration_condition->last_update_time) {
        free(v1alpha1_migration_condition->last_update_time);
        v1alpha1_migration_condition->last_update_time = NULL;
    }
    if (v1alpha1_migration_condition->message) {
        free(v1alpha1_migration_condition->message);
        v1alpha1_migration_condition->message = NULL;
    }
    if (v1alpha1_migration_condition->reason) {
        free(v1alpha1_migration_condition->reason);
        v1alpha1_migration_condition->reason = NULL;
    }
    if (v1alpha1_migration_condition->status) {
        free(v1alpha1_migration_condition->status);
        v1alpha1_migration_condition->status = NULL;
    }
    if (v1alpha1_migration_condition->type) {
        free(v1alpha1_migration_condition->type);
        v1alpha1_migration_condition->type = NULL;
    }
    free(v1alpha1_migration_condition);
}

cJSON *v1alpha1_migration_condition_convertToJSON(v1alpha1_migration_condition_t *v1alpha1_migration_condition) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_migration_condition->last_update_time
    if(v1alpha1_migration_condition->last_update_time) {
    if(cJSON_AddStringToObject(item, "lastUpdateTime", v1alpha1_migration_condition->last_update_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1alpha1_migration_condition->message
    if(v1alpha1_migration_condition->message) {
    if(cJSON_AddStringToObject(item, "message", v1alpha1_migration_condition->message) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_migration_condition->reason
    if(v1alpha1_migration_condition->reason) {
    if(cJSON_AddStringToObject(item, "reason", v1alpha1_migration_condition->reason) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_migration_condition->status
    if (!v1alpha1_migration_condition->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", v1alpha1_migration_condition->status) == NULL) {
    goto fail; //String
    }


    // v1alpha1_migration_condition->type
    if (!v1alpha1_migration_condition->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", v1alpha1_migration_condition->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_migration_condition_t *v1alpha1_migration_condition_parseFromJSON(cJSON *v1alpha1_migration_conditionJSON){

    v1alpha1_migration_condition_t *v1alpha1_migration_condition_local_var = NULL;

    // v1alpha1_migration_condition->last_update_time
    cJSON *last_update_time = cJSON_GetObjectItemCaseSensitive(v1alpha1_migration_conditionJSON, "lastUpdateTime");
    if (cJSON_IsNull(last_update_time)) {
        last_update_time = NULL;
    }
    if (last_update_time) { 
    if(!cJSON_IsString(last_update_time) && !cJSON_IsNull(last_update_time))
    {
    goto end; //DateTime
    }
    }

    // v1alpha1_migration_condition->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1alpha1_migration_conditionJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // v1alpha1_migration_condition->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1alpha1_migration_conditionJSON, "reason");
    if (cJSON_IsNull(reason)) {
        reason = NULL;
    }
    if (reason) { 
    if(!cJSON_IsString(reason) && !cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }

    // v1alpha1_migration_condition->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1alpha1_migration_conditionJSON, "status");
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

    // v1alpha1_migration_condition->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1alpha1_migration_conditionJSON, "type");
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


    v1alpha1_migration_condition_local_var = v1alpha1_migration_condition_create_internal (
        last_update_time && !cJSON_IsNull(last_update_time) ? strdup(last_update_time->valuestring) : NULL,
        message && !cJSON_IsNull(message) ? strdup(message->valuestring) : NULL,
        reason && !cJSON_IsNull(reason) ? strdup(reason->valuestring) : NULL,
        strdup(status->valuestring),
        strdup(type->valuestring)
        );

    return v1alpha1_migration_condition_local_var;
end:
    return NULL;

}
