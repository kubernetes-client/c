#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_subject_access_review_status.h"



v1beta1_subject_access_review_status_t *v1beta1_subject_access_review_status_create(
    int allowed,
    int denied,
    char *evaluation_error,
    char *reason
    ) {
    v1beta1_subject_access_review_status_t *v1beta1_subject_access_review_status_local_var = malloc(sizeof(v1beta1_subject_access_review_status_t));
    if (!v1beta1_subject_access_review_status_local_var) {
        return NULL;
    }
    v1beta1_subject_access_review_status_local_var->allowed = allowed;
    v1beta1_subject_access_review_status_local_var->denied = denied;
    v1beta1_subject_access_review_status_local_var->evaluation_error = evaluation_error;
    v1beta1_subject_access_review_status_local_var->reason = reason;

    return v1beta1_subject_access_review_status_local_var;
}


void v1beta1_subject_access_review_status_free(v1beta1_subject_access_review_status_t *v1beta1_subject_access_review_status) {
    if(NULL == v1beta1_subject_access_review_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_subject_access_review_status->evaluation_error) {
        free(v1beta1_subject_access_review_status->evaluation_error);
        v1beta1_subject_access_review_status->evaluation_error = NULL;
    }
    if (v1beta1_subject_access_review_status->reason) {
        free(v1beta1_subject_access_review_status->reason);
        v1beta1_subject_access_review_status->reason = NULL;
    }
    free(v1beta1_subject_access_review_status);
}

cJSON *v1beta1_subject_access_review_status_convertToJSON(v1beta1_subject_access_review_status_t *v1beta1_subject_access_review_status) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_subject_access_review_status->allowed
    if (!v1beta1_subject_access_review_status->allowed) {
        goto fail;
    }
    
    if(cJSON_AddBoolToObject(item, "allowed", v1beta1_subject_access_review_status->allowed) == NULL) {
    goto fail; //Bool
    }


    // v1beta1_subject_access_review_status->denied
    if(v1beta1_subject_access_review_status->denied) { 
    if(cJSON_AddBoolToObject(item, "denied", v1beta1_subject_access_review_status->denied) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1beta1_subject_access_review_status->evaluation_error
    if(v1beta1_subject_access_review_status->evaluation_error) { 
    if(cJSON_AddStringToObject(item, "evaluationError", v1beta1_subject_access_review_status->evaluation_error) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_subject_access_review_status->reason
    if(v1beta1_subject_access_review_status->reason) { 
    if(cJSON_AddStringToObject(item, "reason", v1beta1_subject_access_review_status->reason) == NULL) {
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

v1beta1_subject_access_review_status_t *v1beta1_subject_access_review_status_parseFromJSON(cJSON *v1beta1_subject_access_review_statusJSON){

    v1beta1_subject_access_review_status_t *v1beta1_subject_access_review_status_local_var = NULL;

    // v1beta1_subject_access_review_status->allowed
    cJSON *allowed = cJSON_GetObjectItemCaseSensitive(v1beta1_subject_access_review_statusJSON, "allowed");
    if (!allowed) {
        goto end;
    }

    
    if(!cJSON_IsBool(allowed))
    {
    goto end; //Bool
    }

    // v1beta1_subject_access_review_status->denied
    cJSON *denied = cJSON_GetObjectItemCaseSensitive(v1beta1_subject_access_review_statusJSON, "denied");
    if (denied) { 
    if(!cJSON_IsBool(denied))
    {
    goto end; //Bool
    }
    }

    // v1beta1_subject_access_review_status->evaluation_error
    cJSON *evaluation_error = cJSON_GetObjectItemCaseSensitive(v1beta1_subject_access_review_statusJSON, "evaluationError");
    if (evaluation_error) { 
    if(!cJSON_IsString(evaluation_error))
    {
    goto end; //String
    }
    }

    // v1beta1_subject_access_review_status->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1beta1_subject_access_review_statusJSON, "reason");
    if (reason) { 
    if(!cJSON_IsString(reason))
    {
    goto end; //String
    }
    }


    v1beta1_subject_access_review_status_local_var = v1beta1_subject_access_review_status_create (
        allowed->valueint,
        denied ? denied->valueint : 0,
        evaluation_error ? strdup(evaluation_error->valuestring) : NULL,
        reason ? strdup(reason->valuestring) : NULL
        );

    return v1beta1_subject_access_review_status_local_var;
end:
    return NULL;

}
