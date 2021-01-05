#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "apps_v1beta1_deployment_condition.h"



apps_v1beta1_deployment_condition_t *apps_v1beta1_deployment_condition_create(
    char *last_transition_time,
    char *last_update_time,
    char *message,
    char *reason,
    char *status,
    char *type
    ) {
    apps_v1beta1_deployment_condition_t *apps_v1beta1_deployment_condition_local_var = malloc(sizeof(apps_v1beta1_deployment_condition_t));
    if (!apps_v1beta1_deployment_condition_local_var) {
        return NULL;
    }
    apps_v1beta1_deployment_condition_local_var->last_transition_time = last_transition_time;
    apps_v1beta1_deployment_condition_local_var->last_update_time = last_update_time;
    apps_v1beta1_deployment_condition_local_var->message = message;
    apps_v1beta1_deployment_condition_local_var->reason = reason;
    apps_v1beta1_deployment_condition_local_var->status = status;
    apps_v1beta1_deployment_condition_local_var->type = type;

    return apps_v1beta1_deployment_condition_local_var;
}


void apps_v1beta1_deployment_condition_free(apps_v1beta1_deployment_condition_t *apps_v1beta1_deployment_condition) {
    if(NULL == apps_v1beta1_deployment_condition){
        return ;
    }
    listEntry_t *listEntry;
    if (apps_v1beta1_deployment_condition->last_transition_time) {
        free(apps_v1beta1_deployment_condition->last_transition_time);
        apps_v1beta1_deployment_condition->last_transition_time = NULL;
    }
    if (apps_v1beta1_deployment_condition->last_update_time) {
        free(apps_v1beta1_deployment_condition->last_update_time);
        apps_v1beta1_deployment_condition->last_update_time = NULL;
    }
    if (apps_v1beta1_deployment_condition->message) {
        free(apps_v1beta1_deployment_condition->message);
        apps_v1beta1_deployment_condition->message = NULL;
    }
    if (apps_v1beta1_deployment_condition->reason) {
        free(apps_v1beta1_deployment_condition->reason);
        apps_v1beta1_deployment_condition->reason = NULL;
    }
    if (apps_v1beta1_deployment_condition->status) {
        free(apps_v1beta1_deployment_condition->status);
        apps_v1beta1_deployment_condition->status = NULL;
    }
    if (apps_v1beta1_deployment_condition->type) {
        free(apps_v1beta1_deployment_condition->type);
        apps_v1beta1_deployment_condition->type = NULL;
    }
    free(apps_v1beta1_deployment_condition);
}

cJSON *apps_v1beta1_deployment_condition_convertToJSON(apps_v1beta1_deployment_condition_t *apps_v1beta1_deployment_condition) {
    cJSON *item = cJSON_CreateObject();

    // apps_v1beta1_deployment_condition->last_transition_time
    if(apps_v1beta1_deployment_condition->last_transition_time) { 
    if(cJSON_AddStringToObject(item, "lastTransitionTime", apps_v1beta1_deployment_condition->last_transition_time) == NULL) {
    goto fail; //Date-Time
    }
     } 


    // apps_v1beta1_deployment_condition->last_update_time
    if(apps_v1beta1_deployment_condition->last_update_time) { 
    if(cJSON_AddStringToObject(item, "lastUpdateTime", apps_v1beta1_deployment_condition->last_update_time) == NULL) {
    goto fail; //Date-Time
    }
     } 


    // apps_v1beta1_deployment_condition->message
    if(apps_v1beta1_deployment_condition->message) { 
    if(cJSON_AddStringToObject(item, "message", apps_v1beta1_deployment_condition->message) == NULL) {
    goto fail; //String
    }
     } 


    // apps_v1beta1_deployment_condition->reason
    if(apps_v1beta1_deployment_condition->reason) { 
    if(cJSON_AddStringToObject(item, "reason", apps_v1beta1_deployment_condition->reason) == NULL) {
    goto fail; //String
    }
     } 


    // apps_v1beta1_deployment_condition->status
    if (!apps_v1beta1_deployment_condition->status) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "status", apps_v1beta1_deployment_condition->status) == NULL) {
    goto fail; //String
    }


    // apps_v1beta1_deployment_condition->type
    if (!apps_v1beta1_deployment_condition->type) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "type", apps_v1beta1_deployment_condition->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

apps_v1beta1_deployment_condition_t *apps_v1beta1_deployment_condition_parseFromJSON(cJSON *apps_v1beta1_deployment_conditionJSON){

    apps_v1beta1_deployment_condition_t *apps_v1beta1_deployment_condition_local_var = NULL;

    // apps_v1beta1_deployment_condition->last_transition_time
    cJSON *last_transition_time = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_conditionJSON, "lastTransitionTime");
    if (last_transition_time) { 
    if(!cJSON_IsString(last_transition_time))
    {
    goto end; //DateTime
    }
    }

    // apps_v1beta1_deployment_condition->last_update_time
    cJSON *last_update_time = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_conditionJSON, "lastUpdateTime");
    if (last_update_time) { 
    if(!cJSON_IsString(last_update_time))
    {
    goto end; //DateTime
    }
    }

    // apps_v1beta1_deployment_condition->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_conditionJSON, "message");
    if (message) { 
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }
    }

    // apps_v1beta1_deployment_condition->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_conditionJSON, "reason");
    if (reason) { 
    if(!cJSON_IsString(reason))
    {
    goto end; //String
    }
    }

    // apps_v1beta1_deployment_condition->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_conditionJSON, "status");
    if (!status) {
        goto end;
    }

    
    if(!cJSON_IsString(status))
    {
    goto end; //String
    }

    // apps_v1beta1_deployment_condition->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_conditionJSON, "type");
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }


    apps_v1beta1_deployment_condition_local_var = apps_v1beta1_deployment_condition_create (
        last_transition_time ? strdup(last_transition_time->valuestring) : NULL,
        last_update_time ? strdup(last_update_time->valuestring) : NULL,
        message ? strdup(message->valuestring) : NULL,
        reason ? strdup(reason->valuestring) : NULL,
        strdup(status->valuestring),
        strdup(type->valuestring)
        );

    return apps_v1beta1_deployment_condition_local_var;
end:
    return NULL;

}
