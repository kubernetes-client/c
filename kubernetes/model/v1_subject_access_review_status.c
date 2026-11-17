#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_subject_access_review_status.h"



static v1_subject_access_review_status_t *v1_subject_access_review_status_create_internal(
    int *allowed,
    int *denied,
    char *evaluation_error,
    char *reason
    ) {
    v1_subject_access_review_status_t *v1_subject_access_review_status_local_var = malloc(sizeof(v1_subject_access_review_status_t));
    if (!v1_subject_access_review_status_local_var) {
        return NULL;
    }
    memset(v1_subject_access_review_status_local_var, 0, sizeof(v1_subject_access_review_status_t));
    v1_subject_access_review_status_local_var->_library_owned = 1;
    v1_subject_access_review_status_local_var->allowed = allowed;
    v1_subject_access_review_status_local_var->denied = denied;
    v1_subject_access_review_status_local_var->evaluation_error = evaluation_error;
    v1_subject_access_review_status_local_var->reason = reason;
    return v1_subject_access_review_status_local_var;
}

__attribute__((deprecated)) v1_subject_access_review_status_t *v1_subject_access_review_status_create(
    int *allowed,
    int *denied,
    char *evaluation_error,
    char *reason
    ) {
    int *allowed_copy = NULL;
    if (allowed) {
        allowed_copy = malloc(sizeof(int));
        if (allowed_copy) *allowed_copy = *allowed;
    }
    int *denied_copy = NULL;
    if (denied) {
        denied_copy = malloc(sizeof(int));
        if (denied_copy) *denied_copy = *denied;
    }
    v1_subject_access_review_status_t *result = v1_subject_access_review_status_create_internal (
        allowed_copy,
        denied_copy,
        evaluation_error,
        reason
        );
    if (!result) {
        free(allowed_copy);
        free(denied_copy);
    }
    return result;
}

void v1_subject_access_review_status_free(v1_subject_access_review_status_t *v1_subject_access_review_status) {
    if(NULL == v1_subject_access_review_status){
        return ;
    }
    if(v1_subject_access_review_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_subject_access_review_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_subject_access_review_status->allowed) {
        free(v1_subject_access_review_status->allowed);
        v1_subject_access_review_status->allowed = NULL;
    }
    if (v1_subject_access_review_status->denied) {
        free(v1_subject_access_review_status->denied);
        v1_subject_access_review_status->denied = NULL;
    }
    if (v1_subject_access_review_status->evaluation_error) {
        free(v1_subject_access_review_status->evaluation_error);
        v1_subject_access_review_status->evaluation_error = NULL;
    }
    if (v1_subject_access_review_status->reason) {
        free(v1_subject_access_review_status->reason);
        v1_subject_access_review_status->reason = NULL;
    }
    free(v1_subject_access_review_status);
}

cJSON *v1_subject_access_review_status_convertToJSON(v1_subject_access_review_status_t *v1_subject_access_review_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_subject_access_review_status->allowed
    if (!v1_subject_access_review_status->allowed) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "allowed", *v1_subject_access_review_status->allowed) == NULL) {
    goto fail; //Bool
    }


    // v1_subject_access_review_status->denied
    if(v1_subject_access_review_status->denied) {
    if(cJSON_AddBoolToObject(item, "denied", *v1_subject_access_review_status->denied) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_subject_access_review_status->evaluation_error
    if(v1_subject_access_review_status->evaluation_error) {
    if(cJSON_AddStringToObject(item, "evaluationError", v1_subject_access_review_status->evaluation_error) == NULL) {
    goto fail; //String
    }
    }


    // v1_subject_access_review_status->reason
    if(v1_subject_access_review_status->reason) {
    if(cJSON_AddStringToObject(item, "reason", v1_subject_access_review_status->reason) == NULL) {
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

v1_subject_access_review_status_t *v1_subject_access_review_status_parseFromJSON(cJSON *v1_subject_access_review_statusJSON){

    v1_subject_access_review_status_t *v1_subject_access_review_status_local_var = NULL;

    // define the local variable for v1_subject_access_review_status->allowed
    int *allowed_local_var = NULL;

    // define the local variable for v1_subject_access_review_status->denied
    int *denied_local_var = NULL;

    char *evaluation_error_local_str = NULL;

    char *reason_local_str = NULL;

    // v1_subject_access_review_status->allowed
    cJSON *allowed = cJSON_GetObjectItemCaseSensitive(v1_subject_access_review_statusJSON, "allowed");
    if (cJSON_IsNull(allowed)) {
        allowed = NULL;
    }
    if (!allowed) {
        goto end;
    }

    
    if(!cJSON_IsBool(allowed))
    {
    goto end; //Bool
    }
    allowed_local_var = malloc(sizeof(int));
    if(!allowed_local_var)
    {
        goto end;
    }
    *allowed_local_var = allowed->valueint;

    // v1_subject_access_review_status->denied
    cJSON *denied = cJSON_GetObjectItemCaseSensitive(v1_subject_access_review_statusJSON, "denied");
    if (cJSON_IsNull(denied)) {
        denied = NULL;
    }
    if (denied) { 
    if(!cJSON_IsBool(denied))
    {
    goto end; //Bool
    }
    denied_local_var = malloc(sizeof(int));
    if(!denied_local_var)
    {
        goto end;
    }
    *denied_local_var = denied->valueint;
    }

    // v1_subject_access_review_status->evaluation_error
    cJSON *evaluation_error = cJSON_GetObjectItemCaseSensitive(v1_subject_access_review_statusJSON, "evaluationError");
    if (cJSON_IsNull(evaluation_error)) {
        evaluation_error = NULL;
    }
    if (evaluation_error) { 
    if(!cJSON_IsString(evaluation_error) && !cJSON_IsNull(evaluation_error))
    {
    goto end; //String
    }
    }

    // v1_subject_access_review_status->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1_subject_access_review_statusJSON, "reason");
    if (cJSON_IsNull(reason)) {
        reason = NULL;
    }
    if (reason) { 
    if(!cJSON_IsString(reason) && !cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }


    if (evaluation_error && !cJSON_IsNull(evaluation_error)) evaluation_error_local_str = strdup(evaluation_error->valuestring);
    if (reason && !cJSON_IsNull(reason)) reason_local_str = strdup(reason->valuestring);

    v1_subject_access_review_status_local_var = v1_subject_access_review_status_create_internal (
        allowed_local_var,
        denied_local_var,
        evaluation_error_local_str,
        reason_local_str
        );

    if (!v1_subject_access_review_status_local_var) {
        goto end;
    }

    return v1_subject_access_review_status_local_var;
end:
    if (allowed_local_var) {
        free(allowed_local_var);
        allowed_local_var = NULL;
    }
    if (denied_local_var) {
        free(denied_local_var);
        denied_local_var = NULL;
    }
    if (evaluation_error_local_str) {
        free(evaluation_error_local_str);
        evaluation_error_local_str = NULL;
    }
    if (reason_local_str) {
        free(reason_local_str);
        reason_local_str = NULL;
    }
    return NULL;

}
