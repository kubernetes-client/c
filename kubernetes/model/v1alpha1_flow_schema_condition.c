#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_flow_schema_condition.h"



v1alpha1_flow_schema_condition_t *v1alpha1_flow_schema_condition_create(
    char *last_transition_time,
    char *message,
    char *reason,
    char *status,
    char *type
    ) {
    v1alpha1_flow_schema_condition_t *v1alpha1_flow_schema_condition_local_var = malloc(sizeof(v1alpha1_flow_schema_condition_t));
    if (!v1alpha1_flow_schema_condition_local_var) {
        return NULL;
    }
    v1alpha1_flow_schema_condition_local_var->last_transition_time = last_transition_time;
    v1alpha1_flow_schema_condition_local_var->message = message;
    v1alpha1_flow_schema_condition_local_var->reason = reason;
    v1alpha1_flow_schema_condition_local_var->status = status;
    v1alpha1_flow_schema_condition_local_var->type = type;

    return v1alpha1_flow_schema_condition_local_var;
}


void v1alpha1_flow_schema_condition_free(v1alpha1_flow_schema_condition_t *v1alpha1_flow_schema_condition) {
    if(NULL == v1alpha1_flow_schema_condition){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_flow_schema_condition->last_transition_time) {
        free(v1alpha1_flow_schema_condition->last_transition_time);
        v1alpha1_flow_schema_condition->last_transition_time = NULL;
    }
    if (v1alpha1_flow_schema_condition->message) {
        free(v1alpha1_flow_schema_condition->message);
        v1alpha1_flow_schema_condition->message = NULL;
    }
    if (v1alpha1_flow_schema_condition->reason) {
        free(v1alpha1_flow_schema_condition->reason);
        v1alpha1_flow_schema_condition->reason = NULL;
    }
    if (v1alpha1_flow_schema_condition->status) {
        free(v1alpha1_flow_schema_condition->status);
        v1alpha1_flow_schema_condition->status = NULL;
    }
    if (v1alpha1_flow_schema_condition->type) {
        free(v1alpha1_flow_schema_condition->type);
        v1alpha1_flow_schema_condition->type = NULL;
    }
    free(v1alpha1_flow_schema_condition);
}

cJSON *v1alpha1_flow_schema_condition_convertToJSON(v1alpha1_flow_schema_condition_t *v1alpha1_flow_schema_condition) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_flow_schema_condition->last_transition_time
    if(v1alpha1_flow_schema_condition->last_transition_time) { 
    if(cJSON_AddStringToObject(item, "lastTransitionTime", v1alpha1_flow_schema_condition->last_transition_time) == NULL) {
    goto fail; //Date-Time
    }
     } 


    // v1alpha1_flow_schema_condition->message
    if(v1alpha1_flow_schema_condition->message) { 
    if(cJSON_AddStringToObject(item, "message", v1alpha1_flow_schema_condition->message) == NULL) {
    goto fail; //String
    }
     } 


    // v1alpha1_flow_schema_condition->reason
    if(v1alpha1_flow_schema_condition->reason) { 
    if(cJSON_AddStringToObject(item, "reason", v1alpha1_flow_schema_condition->reason) == NULL) {
    goto fail; //String
    }
     } 


    // v1alpha1_flow_schema_condition->status
    if(v1alpha1_flow_schema_condition->status) { 
    if(cJSON_AddStringToObject(item, "status", v1alpha1_flow_schema_condition->status) == NULL) {
    goto fail; //String
    }
     } 


    // v1alpha1_flow_schema_condition->type
    if(v1alpha1_flow_schema_condition->type) { 
    if(cJSON_AddStringToObject(item, "type", v1alpha1_flow_schema_condition->type) == NULL) {
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

v1alpha1_flow_schema_condition_t *v1alpha1_flow_schema_condition_parseFromJSON(cJSON *v1alpha1_flow_schema_conditionJSON){

    v1alpha1_flow_schema_condition_t *v1alpha1_flow_schema_condition_local_var = NULL;

    // v1alpha1_flow_schema_condition->last_transition_time
    cJSON *last_transition_time = cJSON_GetObjectItemCaseSensitive(v1alpha1_flow_schema_conditionJSON, "lastTransitionTime");
    if (last_transition_time) { 
    if(!cJSON_IsString(last_transition_time))
    {
    goto end; //DateTime
    }
    }

    // v1alpha1_flow_schema_condition->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1alpha1_flow_schema_conditionJSON, "message");
    if (message) { 
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }
    }

    // v1alpha1_flow_schema_condition->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1alpha1_flow_schema_conditionJSON, "reason");
    if (reason) { 
    if(!cJSON_IsString(reason))
    {
    goto end; //String
    }
    }

    // v1alpha1_flow_schema_condition->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1alpha1_flow_schema_conditionJSON, "status");
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //String
    }
    }

    // v1alpha1_flow_schema_condition->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1alpha1_flow_schema_conditionJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }
    }


    v1alpha1_flow_schema_condition_local_var = v1alpha1_flow_schema_condition_create (
        last_transition_time ? strdup(last_transition_time->valuestring) : NULL,
        message ? strdup(message->valuestring) : NULL,
        reason ? strdup(reason->valuestring) : NULL,
        status ? strdup(status->valuestring) : NULL,
        type ? strdup(type->valuestring) : NULL
        );

    return v1alpha1_flow_schema_condition_local_var;
end:
    return NULL;

}
