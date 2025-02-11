#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_status_cause.h"



static v1_status_cause_t *v1_status_cause_create_internal(
    char *field,
    char *message,
    char *reason
    ) {
    v1_status_cause_t *v1_status_cause_local_var = malloc(sizeof(v1_status_cause_t));
    if (!v1_status_cause_local_var) {
        return NULL;
    }
    v1_status_cause_local_var->field = field;
    v1_status_cause_local_var->message = message;
    v1_status_cause_local_var->reason = reason;

    v1_status_cause_local_var->_library_owned = 1;
    return v1_status_cause_local_var;
}

__attribute__((deprecated)) v1_status_cause_t *v1_status_cause_create(
    char *field,
    char *message,
    char *reason
    ) {
    return v1_status_cause_create_internal (
        field,
        message,
        reason
        );
}

void v1_status_cause_free(v1_status_cause_t *v1_status_cause) {
    if(NULL == v1_status_cause){
        return ;
    }
    if(v1_status_cause->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_status_cause_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_status_cause->field) {
        free(v1_status_cause->field);
        v1_status_cause->field = NULL;
    }
    if (v1_status_cause->message) {
        free(v1_status_cause->message);
        v1_status_cause->message = NULL;
    }
    if (v1_status_cause->reason) {
        free(v1_status_cause->reason);
        v1_status_cause->reason = NULL;
    }
    free(v1_status_cause);
}

cJSON *v1_status_cause_convertToJSON(v1_status_cause_t *v1_status_cause) {
    cJSON *item = cJSON_CreateObject();

    // v1_status_cause->field
    if(v1_status_cause->field) {
    if(cJSON_AddStringToObject(item, "field", v1_status_cause->field) == NULL) {
    goto fail; //String
    }
    }


    // v1_status_cause->message
    if(v1_status_cause->message) {
    if(cJSON_AddStringToObject(item, "message", v1_status_cause->message) == NULL) {
    goto fail; //String
    }
    }


    // v1_status_cause->reason
    if(v1_status_cause->reason) {
    if(cJSON_AddStringToObject(item, "reason", v1_status_cause->reason) == NULL) {
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

v1_status_cause_t *v1_status_cause_parseFromJSON(cJSON *v1_status_causeJSON){

    v1_status_cause_t *v1_status_cause_local_var = NULL;

    // v1_status_cause->field
    cJSON *field = cJSON_GetObjectItemCaseSensitive(v1_status_causeJSON, "field");
    if (cJSON_IsNull(field)) {
        field = NULL;
    }
    if (field) { 
    if(!cJSON_IsString(field) && !cJSON_IsNull(field))
    {
    goto end; //String
    }
    }

    // v1_status_cause->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1_status_causeJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // v1_status_cause->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1_status_causeJSON, "reason");
    if (cJSON_IsNull(reason)) {
        reason = NULL;
    }
    if (reason) { 
    if(!cJSON_IsString(reason) && !cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }


    v1_status_cause_local_var = v1_status_cause_create_internal (
        field && !cJSON_IsNull(field) ? strdup(field->valuestring) : NULL,
        message && !cJSON_IsNull(message) ? strdup(message->valuestring) : NULL,
        reason && !cJSON_IsNull(reason) ? strdup(reason->valuestring) : NULL
        );

    return v1_status_cause_local_var;
end:
    return NULL;

}
