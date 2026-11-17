#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_container_state_waiting.h"



static v1_container_state_waiting_t *v1_container_state_waiting_create_internal(
    char *message,
    char *reason
    ) {
    v1_container_state_waiting_t *v1_container_state_waiting_local_var = malloc(sizeof(v1_container_state_waiting_t));
    if (!v1_container_state_waiting_local_var) {
        return NULL;
    }
    memset(v1_container_state_waiting_local_var, 0, sizeof(v1_container_state_waiting_t));
    v1_container_state_waiting_local_var->_library_owned = 1;
    v1_container_state_waiting_local_var->message = message;
    v1_container_state_waiting_local_var->reason = reason;
    return v1_container_state_waiting_local_var;
}

__attribute__((deprecated)) v1_container_state_waiting_t *v1_container_state_waiting_create(
    char *message,
    char *reason
    ) {
    v1_container_state_waiting_t *result = v1_container_state_waiting_create_internal (
        message,
        reason
        );
    if (!result) {
    }
    return result;
}

void v1_container_state_waiting_free(v1_container_state_waiting_t *v1_container_state_waiting) {
    if(NULL == v1_container_state_waiting){
        return ;
    }
    if(v1_container_state_waiting->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_container_state_waiting_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_container_state_waiting->message) {
        free(v1_container_state_waiting->message);
        v1_container_state_waiting->message = NULL;
    }
    if (v1_container_state_waiting->reason) {
        free(v1_container_state_waiting->reason);
        v1_container_state_waiting->reason = NULL;
    }
    free(v1_container_state_waiting);
}

cJSON *v1_container_state_waiting_convertToJSON(v1_container_state_waiting_t *v1_container_state_waiting) {
    cJSON *item = cJSON_CreateObject();

    // v1_container_state_waiting->message
    if(v1_container_state_waiting->message) {
    if(cJSON_AddStringToObject(item, "message", v1_container_state_waiting->message) == NULL) {
    goto fail; //String
    }
    }


    // v1_container_state_waiting->reason
    if(v1_container_state_waiting->reason) {
    if(cJSON_AddStringToObject(item, "reason", v1_container_state_waiting->reason) == NULL) {
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

v1_container_state_waiting_t *v1_container_state_waiting_parseFromJSON(cJSON *v1_container_state_waitingJSON){

    v1_container_state_waiting_t *v1_container_state_waiting_local_var = NULL;

    char *message_local_str = NULL;

    char *reason_local_str = NULL;

    // v1_container_state_waiting->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1_container_state_waitingJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // v1_container_state_waiting->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1_container_state_waitingJSON, "reason");
    if (cJSON_IsNull(reason)) {
        reason = NULL;
    }
    if (reason) { 
    if(!cJSON_IsString(reason) && !cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }


    if (message && !cJSON_IsNull(message)) message_local_str = strdup(message->valuestring);
    if (reason && !cJSON_IsNull(reason)) reason_local_str = strdup(reason->valuestring);

    v1_container_state_waiting_local_var = v1_container_state_waiting_create_internal (
        message_local_str,
        reason_local_str
        );

    if (!v1_container_state_waiting_local_var) {
        goto end;
    }

    return v1_container_state_waiting_local_var;
end:
    if (message_local_str) {
        free(message_local_str);
        message_local_str = NULL;
    }
    if (reason_local_str) {
        free(reason_local_str);
        reason_local_str = NULL;
    }
    return NULL;

}
