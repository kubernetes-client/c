#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_responder_status.h"



static v1alpha1_responder_status_t *v1alpha1_responder_status_create_internal(
    char *completion_time,
    char *expected_completion_time,
    char *heartbeat_time,
    char *message,
    char *name,
    char *start_time
    ) {
    v1alpha1_responder_status_t *v1alpha1_responder_status_local_var = malloc(sizeof(v1alpha1_responder_status_t));
    if (!v1alpha1_responder_status_local_var) {
        return NULL;
    }
    memset(v1alpha1_responder_status_local_var, 0, sizeof(v1alpha1_responder_status_t));
    v1alpha1_responder_status_local_var->_library_owned = 1;
    v1alpha1_responder_status_local_var->completion_time = completion_time;
    v1alpha1_responder_status_local_var->expected_completion_time = expected_completion_time;
    v1alpha1_responder_status_local_var->heartbeat_time = heartbeat_time;
    v1alpha1_responder_status_local_var->message = message;
    v1alpha1_responder_status_local_var->name = name;
    v1alpha1_responder_status_local_var->start_time = start_time;
    return v1alpha1_responder_status_local_var;
}

__attribute__((deprecated)) v1alpha1_responder_status_t *v1alpha1_responder_status_create(
    char *completion_time,
    char *expected_completion_time,
    char *heartbeat_time,
    char *message,
    char *name,
    char *start_time
    ) {
    v1alpha1_responder_status_t *result = v1alpha1_responder_status_create_internal (
        completion_time,
        expected_completion_time,
        heartbeat_time,
        message,
        name,
        start_time
        );
    if (!result) {
    }
    return result;
}

void v1alpha1_responder_status_free(v1alpha1_responder_status_t *v1alpha1_responder_status) {
    if(NULL == v1alpha1_responder_status){
        return ;
    }
    if(v1alpha1_responder_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha1_responder_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_responder_status->completion_time) {
        free(v1alpha1_responder_status->completion_time);
        v1alpha1_responder_status->completion_time = NULL;
    }
    if (v1alpha1_responder_status->expected_completion_time) {
        free(v1alpha1_responder_status->expected_completion_time);
        v1alpha1_responder_status->expected_completion_time = NULL;
    }
    if (v1alpha1_responder_status->heartbeat_time) {
        free(v1alpha1_responder_status->heartbeat_time);
        v1alpha1_responder_status->heartbeat_time = NULL;
    }
    if (v1alpha1_responder_status->message) {
        free(v1alpha1_responder_status->message);
        v1alpha1_responder_status->message = NULL;
    }
    if (v1alpha1_responder_status->name) {
        free(v1alpha1_responder_status->name);
        v1alpha1_responder_status->name = NULL;
    }
    if (v1alpha1_responder_status->start_time) {
        free(v1alpha1_responder_status->start_time);
        v1alpha1_responder_status->start_time = NULL;
    }
    free(v1alpha1_responder_status);
}

cJSON *v1alpha1_responder_status_convertToJSON(v1alpha1_responder_status_t *v1alpha1_responder_status) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_responder_status->completion_time
    if(v1alpha1_responder_status->completion_time) {
    if(cJSON_AddStringToObject(item, "completionTime", v1alpha1_responder_status->completion_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1alpha1_responder_status->expected_completion_time
    if(v1alpha1_responder_status->expected_completion_time) {
    if(cJSON_AddStringToObject(item, "expectedCompletionTime", v1alpha1_responder_status->expected_completion_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1alpha1_responder_status->heartbeat_time
    if(v1alpha1_responder_status->heartbeat_time) {
    if(cJSON_AddStringToObject(item, "heartbeatTime", v1alpha1_responder_status->heartbeat_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1alpha1_responder_status->message
    if(v1alpha1_responder_status->message) {
    if(cJSON_AddStringToObject(item, "message", v1alpha1_responder_status->message) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_responder_status->name
    if (!v1alpha1_responder_status->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1alpha1_responder_status->name) == NULL) {
    goto fail; //String
    }


    // v1alpha1_responder_status->start_time
    if(v1alpha1_responder_status->start_time) {
    if(cJSON_AddStringToObject(item, "startTime", v1alpha1_responder_status->start_time) == NULL) {
    goto fail; //Date-Time
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_responder_status_t *v1alpha1_responder_status_parseFromJSON(cJSON *v1alpha1_responder_statusJSON){

    v1alpha1_responder_status_t *v1alpha1_responder_status_local_var = NULL;

    char *completion_time_local_str = NULL;

    char *expected_completion_time_local_str = NULL;

    char *heartbeat_time_local_str = NULL;

    char *message_local_str = NULL;

    char *name_local_str = NULL;

    char *start_time_local_str = NULL;

    // v1alpha1_responder_status->completion_time
    cJSON *completion_time = cJSON_GetObjectItemCaseSensitive(v1alpha1_responder_statusJSON, "completionTime");
    if (cJSON_IsNull(completion_time)) {
        completion_time = NULL;
    }
    if (completion_time) { 
    if(!cJSON_IsString(completion_time) && !cJSON_IsNull(completion_time))
    {
    goto end; //DateTime
    }
    }

    // v1alpha1_responder_status->expected_completion_time
    cJSON *expected_completion_time = cJSON_GetObjectItemCaseSensitive(v1alpha1_responder_statusJSON, "expectedCompletionTime");
    if (cJSON_IsNull(expected_completion_time)) {
        expected_completion_time = NULL;
    }
    if (expected_completion_time) { 
    if(!cJSON_IsString(expected_completion_time) && !cJSON_IsNull(expected_completion_time))
    {
    goto end; //DateTime
    }
    }

    // v1alpha1_responder_status->heartbeat_time
    cJSON *heartbeat_time = cJSON_GetObjectItemCaseSensitive(v1alpha1_responder_statusJSON, "heartbeatTime");
    if (cJSON_IsNull(heartbeat_time)) {
        heartbeat_time = NULL;
    }
    if (heartbeat_time) { 
    if(!cJSON_IsString(heartbeat_time) && !cJSON_IsNull(heartbeat_time))
    {
    goto end; //DateTime
    }
    }

    // v1alpha1_responder_status->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1alpha1_responder_statusJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // v1alpha1_responder_status->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1alpha1_responder_statusJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1alpha1_responder_status->start_time
    cJSON *start_time = cJSON_GetObjectItemCaseSensitive(v1alpha1_responder_statusJSON, "startTime");
    if (cJSON_IsNull(start_time)) {
        start_time = NULL;
    }
    if (start_time) { 
    if(!cJSON_IsString(start_time) && !cJSON_IsNull(start_time))
    {
    goto end; //DateTime
    }
    }


    if (completion_time && !cJSON_IsNull(completion_time)) completion_time_local_str = strdup(completion_time->valuestring);
    if (expected_completion_time && !cJSON_IsNull(expected_completion_time)) expected_completion_time_local_str = strdup(expected_completion_time->valuestring);
    if (heartbeat_time && !cJSON_IsNull(heartbeat_time)) heartbeat_time_local_str = strdup(heartbeat_time->valuestring);
    if (message && !cJSON_IsNull(message)) message_local_str = strdup(message->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (start_time && !cJSON_IsNull(start_time)) start_time_local_str = strdup(start_time->valuestring);

    v1alpha1_responder_status_local_var = v1alpha1_responder_status_create_internal (
        completion_time_local_str,
        expected_completion_time_local_str,
        heartbeat_time_local_str,
        message_local_str,
        name_local_str,
        start_time_local_str
        );

    if (!v1alpha1_responder_status_local_var) {
        goto end;
    }

    return v1alpha1_responder_status_local_var;
end:
    if (completion_time_local_str) {
        free(completion_time_local_str);
        completion_time_local_str = NULL;
    }
    if (expected_completion_time_local_str) {
        free(expected_completion_time_local_str);
        expected_completion_time_local_str = NULL;
    }
    if (heartbeat_time_local_str) {
        free(heartbeat_time_local_str);
        heartbeat_time_local_str = NULL;
    }
    if (message_local_str) {
        free(message_local_str);
        message_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (start_time_local_str) {
        free(start_time_local_str);
        start_time_local_str = NULL;
    }
    return NULL;

}
