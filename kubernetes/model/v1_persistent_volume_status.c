#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_persistent_volume_status.h"



static v1_persistent_volume_status_t *v1_persistent_volume_status_create_internal(
    char *last_phase_transition_time,
    char *message,
    char *phase,
    char *reason
    ) {
    v1_persistent_volume_status_t *v1_persistent_volume_status_local_var = malloc(sizeof(v1_persistent_volume_status_t));
    if (!v1_persistent_volume_status_local_var) {
        return NULL;
    }
    memset(v1_persistent_volume_status_local_var, 0, sizeof(v1_persistent_volume_status_t));
    v1_persistent_volume_status_local_var->_library_owned = 1;
    v1_persistent_volume_status_local_var->last_phase_transition_time = last_phase_transition_time;
    v1_persistent_volume_status_local_var->message = message;
    v1_persistent_volume_status_local_var->phase = phase;
    v1_persistent_volume_status_local_var->reason = reason;
    return v1_persistent_volume_status_local_var;
}

__attribute__((deprecated)) v1_persistent_volume_status_t *v1_persistent_volume_status_create(
    char *last_phase_transition_time,
    char *message,
    char *phase,
    char *reason
    ) {
    v1_persistent_volume_status_t *result = v1_persistent_volume_status_create_internal (
        last_phase_transition_time,
        message,
        phase,
        reason
        );
    if (!result) {
    }
    return result;
}

void v1_persistent_volume_status_free(v1_persistent_volume_status_t *v1_persistent_volume_status) {
    if(NULL == v1_persistent_volume_status){
        return ;
    }
    if(v1_persistent_volume_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_persistent_volume_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_persistent_volume_status->last_phase_transition_time) {
        free(v1_persistent_volume_status->last_phase_transition_time);
        v1_persistent_volume_status->last_phase_transition_time = NULL;
    }
    if (v1_persistent_volume_status->message) {
        free(v1_persistent_volume_status->message);
        v1_persistent_volume_status->message = NULL;
    }
    if (v1_persistent_volume_status->phase) {
        free(v1_persistent_volume_status->phase);
        v1_persistent_volume_status->phase = NULL;
    }
    if (v1_persistent_volume_status->reason) {
        free(v1_persistent_volume_status->reason);
        v1_persistent_volume_status->reason = NULL;
    }
    free(v1_persistent_volume_status);
}

cJSON *v1_persistent_volume_status_convertToJSON(v1_persistent_volume_status_t *v1_persistent_volume_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_persistent_volume_status->last_phase_transition_time
    if(v1_persistent_volume_status->last_phase_transition_time) {
    if(cJSON_AddStringToObject(item, "lastPhaseTransitionTime", v1_persistent_volume_status->last_phase_transition_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1_persistent_volume_status->message
    if(v1_persistent_volume_status->message) {
    if(cJSON_AddStringToObject(item, "message", v1_persistent_volume_status->message) == NULL) {
    goto fail; //String
    }
    }


    // v1_persistent_volume_status->phase
    if(v1_persistent_volume_status->phase) {
    if(cJSON_AddStringToObject(item, "phase", v1_persistent_volume_status->phase) == NULL) {
    goto fail; //String
    }
    }


    // v1_persistent_volume_status->reason
    if(v1_persistent_volume_status->reason) {
    if(cJSON_AddStringToObject(item, "reason", v1_persistent_volume_status->reason) == NULL) {
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

v1_persistent_volume_status_t *v1_persistent_volume_status_parseFromJSON(cJSON *v1_persistent_volume_statusJSON){

    v1_persistent_volume_status_t *v1_persistent_volume_status_local_var = NULL;

    char *last_phase_transition_time_local_str = NULL;

    char *message_local_str = NULL;

    char *phase_local_str = NULL;

    char *reason_local_str = NULL;

    // v1_persistent_volume_status->last_phase_transition_time
    cJSON *last_phase_transition_time = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_statusJSON, "lastPhaseTransitionTime");
    if (cJSON_IsNull(last_phase_transition_time)) {
        last_phase_transition_time = NULL;
    }
    if (last_phase_transition_time) { 
    if(!cJSON_IsString(last_phase_transition_time) && !cJSON_IsNull(last_phase_transition_time))
    {
    goto end; //DateTime
    }
    }

    // v1_persistent_volume_status->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_statusJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // v1_persistent_volume_status->phase
    cJSON *phase = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_statusJSON, "phase");
    if (cJSON_IsNull(phase)) {
        phase = NULL;
    }
    if (phase) { 
    if(!cJSON_IsString(phase) && !cJSON_IsNull(phase))
    {
    goto end; //String
    }
    }

    // v1_persistent_volume_status->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_statusJSON, "reason");
    if (cJSON_IsNull(reason)) {
        reason = NULL;
    }
    if (reason) { 
    if(!cJSON_IsString(reason) && !cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }


    if (last_phase_transition_time && !cJSON_IsNull(last_phase_transition_time)) last_phase_transition_time_local_str = strdup(last_phase_transition_time->valuestring);
    if (message && !cJSON_IsNull(message)) message_local_str = strdup(message->valuestring);
    if (phase && !cJSON_IsNull(phase)) phase_local_str = strdup(phase->valuestring);
    if (reason && !cJSON_IsNull(reason)) reason_local_str = strdup(reason->valuestring);

    v1_persistent_volume_status_local_var = v1_persistent_volume_status_create_internal (
        last_phase_transition_time_local_str,
        message_local_str,
        phase_local_str,
        reason_local_str
        );

    if (!v1_persistent_volume_status_local_var) {
        goto end;
    }

    return v1_persistent_volume_status_local_var;
end:
    if (last_phase_transition_time_local_str) {
        free(last_phase_transition_time_local_str);
        last_phase_transition_time_local_str = NULL;
    }
    if (message_local_str) {
        free(message_local_str);
        message_local_str = NULL;
    }
    if (phase_local_str) {
        free(phase_local_str);
        phase_local_str = NULL;
    }
    if (reason_local_str) {
        free(reason_local_str);
        reason_local_str = NULL;
    }
    return NULL;

}
