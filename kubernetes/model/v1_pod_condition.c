#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_condition.h"



static v1_pod_condition_t *v1_pod_condition_create_internal(
    char *last_probe_time,
    char *last_transition_time,
    char *message,
    long observed_generation,
    char *reason,
    char *status,
    char *type
    ) {
    v1_pod_condition_t *v1_pod_condition_local_var = malloc(sizeof(v1_pod_condition_t));
    if (!v1_pod_condition_local_var) {
        return NULL;
    }
    v1_pod_condition_local_var->last_probe_time = last_probe_time;
    v1_pod_condition_local_var->last_transition_time = last_transition_time;
    v1_pod_condition_local_var->message = message;
    v1_pod_condition_local_var->observed_generation = observed_generation;
    v1_pod_condition_local_var->reason = reason;
    v1_pod_condition_local_var->status = status;
    v1_pod_condition_local_var->type = type;

    v1_pod_condition_local_var->_library_owned = 1;
    return v1_pod_condition_local_var;
}

__attribute__((deprecated)) v1_pod_condition_t *v1_pod_condition_create(
    char *last_probe_time,
    char *last_transition_time,
    char *message,
    long observed_generation,
    char *reason,
    char *status,
    char *type
    ) {
    return v1_pod_condition_create_internal (
        last_probe_time,
        last_transition_time,
        message,
        observed_generation,
        reason,
        status,
        type
        );
}

void v1_pod_condition_free(v1_pod_condition_t *v1_pod_condition) {
    if(NULL == v1_pod_condition){
        return ;
    }
    if(v1_pod_condition->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_pod_condition_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_pod_condition->last_probe_time) {
        free(v1_pod_condition->last_probe_time);
        v1_pod_condition->last_probe_time = NULL;
    }
    if (v1_pod_condition->last_transition_time) {
        free(v1_pod_condition->last_transition_time);
        v1_pod_condition->last_transition_time = NULL;
    }
    if (v1_pod_condition->message) {
        free(v1_pod_condition->message);
        v1_pod_condition->message = NULL;
    }
    if (v1_pod_condition->reason) {
        free(v1_pod_condition->reason);
        v1_pod_condition->reason = NULL;
    }
    if (v1_pod_condition->status) {
        free(v1_pod_condition->status);
        v1_pod_condition->status = NULL;
    }
    if (v1_pod_condition->type) {
        free(v1_pod_condition->type);
        v1_pod_condition->type = NULL;
    }
    free(v1_pod_condition);
}

cJSON *v1_pod_condition_convertToJSON(v1_pod_condition_t *v1_pod_condition) {
    cJSON *item = cJSON_CreateObject();

    // v1_pod_condition->last_probe_time
    if(v1_pod_condition->last_probe_time) {
    if(cJSON_AddStringToObject(item, "lastProbeTime", v1_pod_condition->last_probe_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1_pod_condition->last_transition_time
    if(v1_pod_condition->last_transition_time) {
    if(cJSON_AddStringToObject(item, "lastTransitionTime", v1_pod_condition->last_transition_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1_pod_condition->message
    if(v1_pod_condition->message) {
    if(cJSON_AddStringToObject(item, "message", v1_pod_condition->message) == NULL) {
    goto fail; //String
    }
    }


    // v1_pod_condition->observed_generation
    if(v1_pod_condition->observed_generation) {
    if(cJSON_AddNumberToObject(item, "observedGeneration", v1_pod_condition->observed_generation) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_pod_condition->reason
    if(v1_pod_condition->reason) {
    if(cJSON_AddStringToObject(item, "reason", v1_pod_condition->reason) == NULL) {
    goto fail; //String
    }
    }


    // v1_pod_condition->status
    if (!v1_pod_condition->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", v1_pod_condition->status) == NULL) {
    goto fail; //String
    }


    // v1_pod_condition->type
    if (!v1_pod_condition->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", v1_pod_condition->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_pod_condition_t *v1_pod_condition_parseFromJSON(cJSON *v1_pod_conditionJSON){

    v1_pod_condition_t *v1_pod_condition_local_var = NULL;

    // v1_pod_condition->last_probe_time
    cJSON *last_probe_time = cJSON_GetObjectItemCaseSensitive(v1_pod_conditionJSON, "lastProbeTime");
    if (cJSON_IsNull(last_probe_time)) {
        last_probe_time = NULL;
    }
    if (last_probe_time) { 
    if(!cJSON_IsString(last_probe_time) && !cJSON_IsNull(last_probe_time))
    {
    goto end; //DateTime
    }
    }

    // v1_pod_condition->last_transition_time
    cJSON *last_transition_time = cJSON_GetObjectItemCaseSensitive(v1_pod_conditionJSON, "lastTransitionTime");
    if (cJSON_IsNull(last_transition_time)) {
        last_transition_time = NULL;
    }
    if (last_transition_time) { 
    if(!cJSON_IsString(last_transition_time) && !cJSON_IsNull(last_transition_time))
    {
    goto end; //DateTime
    }
    }

    // v1_pod_condition->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1_pod_conditionJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // v1_pod_condition->observed_generation
    cJSON *observed_generation = cJSON_GetObjectItemCaseSensitive(v1_pod_conditionJSON, "observedGeneration");
    if (cJSON_IsNull(observed_generation)) {
        observed_generation = NULL;
    }
    if (observed_generation) { 
    if(!cJSON_IsNumber(observed_generation))
    {
    goto end; //Numeric
    }
    }

    // v1_pod_condition->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1_pod_conditionJSON, "reason");
    if (cJSON_IsNull(reason)) {
        reason = NULL;
    }
    if (reason) { 
    if(!cJSON_IsString(reason) && !cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }

    // v1_pod_condition->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_pod_conditionJSON, "status");
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

    // v1_pod_condition->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_pod_conditionJSON, "type");
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


    v1_pod_condition_local_var = v1_pod_condition_create_internal (
        last_probe_time && !cJSON_IsNull(last_probe_time) ? strdup(last_probe_time->valuestring) : NULL,
        last_transition_time && !cJSON_IsNull(last_transition_time) ? strdup(last_transition_time->valuestring) : NULL,
        message && !cJSON_IsNull(message) ? strdup(message->valuestring) : NULL,
        observed_generation ? observed_generation->valuedouble : 0,
        reason && !cJSON_IsNull(reason) ? strdup(reason->valuestring) : NULL,
        strdup(status->valuestring),
        strdup(type->valuestring)
        );

    return v1_pod_condition_local_var;
end:
    return NULL;

}
