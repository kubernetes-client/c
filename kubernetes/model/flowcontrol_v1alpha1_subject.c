#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "flowcontrol_v1alpha1_subject.h"



flowcontrol_v1alpha1_subject_t *flowcontrol_v1alpha1_subject_create(
    v1alpha1_group_subject_t *group,
    char *kind,
    v1alpha1_service_account_subject_t *service_account,
    v1alpha1_user_subject_t *user
    ) {
    flowcontrol_v1alpha1_subject_t *flowcontrol_v1alpha1_subject_local_var = malloc(sizeof(flowcontrol_v1alpha1_subject_t));
    if (!flowcontrol_v1alpha1_subject_local_var) {
        return NULL;
    }
    flowcontrol_v1alpha1_subject_local_var->group = group;
    flowcontrol_v1alpha1_subject_local_var->kind = kind;
    flowcontrol_v1alpha1_subject_local_var->service_account = service_account;
    flowcontrol_v1alpha1_subject_local_var->user = user;

    return flowcontrol_v1alpha1_subject_local_var;
}


void flowcontrol_v1alpha1_subject_free(flowcontrol_v1alpha1_subject_t *flowcontrol_v1alpha1_subject) {
    if(NULL == flowcontrol_v1alpha1_subject){
        return ;
    }
    listEntry_t *listEntry;
    if (flowcontrol_v1alpha1_subject->group) {
        v1alpha1_group_subject_free(flowcontrol_v1alpha1_subject->group);
        flowcontrol_v1alpha1_subject->group = NULL;
    }
    if (flowcontrol_v1alpha1_subject->kind) {
        free(flowcontrol_v1alpha1_subject->kind);
        flowcontrol_v1alpha1_subject->kind = NULL;
    }
    if (flowcontrol_v1alpha1_subject->service_account) {
        v1alpha1_service_account_subject_free(flowcontrol_v1alpha1_subject->service_account);
        flowcontrol_v1alpha1_subject->service_account = NULL;
    }
    if (flowcontrol_v1alpha1_subject->user) {
        v1alpha1_user_subject_free(flowcontrol_v1alpha1_subject->user);
        flowcontrol_v1alpha1_subject->user = NULL;
    }
    free(flowcontrol_v1alpha1_subject);
}

cJSON *flowcontrol_v1alpha1_subject_convertToJSON(flowcontrol_v1alpha1_subject_t *flowcontrol_v1alpha1_subject) {
    cJSON *item = cJSON_CreateObject();

    // flowcontrol_v1alpha1_subject->group
    if(flowcontrol_v1alpha1_subject->group) { 
    cJSON *group_local_JSON = v1alpha1_group_subject_convertToJSON(flowcontrol_v1alpha1_subject->group);
    if(group_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "group", group_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // flowcontrol_v1alpha1_subject->kind
    if (!flowcontrol_v1alpha1_subject->kind) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "kind", flowcontrol_v1alpha1_subject->kind) == NULL) {
    goto fail; //String
    }


    // flowcontrol_v1alpha1_subject->service_account
    if(flowcontrol_v1alpha1_subject->service_account) { 
    cJSON *service_account_local_JSON = v1alpha1_service_account_subject_convertToJSON(flowcontrol_v1alpha1_subject->service_account);
    if(service_account_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "serviceAccount", service_account_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // flowcontrol_v1alpha1_subject->user
    if(flowcontrol_v1alpha1_subject->user) { 
    cJSON *user_local_JSON = v1alpha1_user_subject_convertToJSON(flowcontrol_v1alpha1_subject->user);
    if(user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "user", user_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

flowcontrol_v1alpha1_subject_t *flowcontrol_v1alpha1_subject_parseFromJSON(cJSON *flowcontrol_v1alpha1_subjectJSON){

    flowcontrol_v1alpha1_subject_t *flowcontrol_v1alpha1_subject_local_var = NULL;

    // flowcontrol_v1alpha1_subject->group
    cJSON *group = cJSON_GetObjectItemCaseSensitive(flowcontrol_v1alpha1_subjectJSON, "group");
    v1alpha1_group_subject_t *group_local_nonprim = NULL;
    if (group) { 
    group_local_nonprim = v1alpha1_group_subject_parseFromJSON(group); //nonprimitive
    }

    // flowcontrol_v1alpha1_subject->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(flowcontrol_v1alpha1_subjectJSON, "kind");
    if (!kind) {
        goto end;
    }

    
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }

    // flowcontrol_v1alpha1_subject->service_account
    cJSON *service_account = cJSON_GetObjectItemCaseSensitive(flowcontrol_v1alpha1_subjectJSON, "serviceAccount");
    v1alpha1_service_account_subject_t *service_account_local_nonprim = NULL;
    if (service_account) { 
    service_account_local_nonprim = v1alpha1_service_account_subject_parseFromJSON(service_account); //nonprimitive
    }

    // flowcontrol_v1alpha1_subject->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(flowcontrol_v1alpha1_subjectJSON, "user");
    v1alpha1_user_subject_t *user_local_nonprim = NULL;
    if (user) { 
    user_local_nonprim = v1alpha1_user_subject_parseFromJSON(user); //nonprimitive
    }


    flowcontrol_v1alpha1_subject_local_var = flowcontrol_v1alpha1_subject_create (
        group ? group_local_nonprim : NULL,
        strdup(kind->valuestring),
        service_account ? service_account_local_nonprim : NULL,
        user ? user_local_nonprim : NULL
        );

    return flowcontrol_v1alpha1_subject_local_var;
end:
    if (group_local_nonprim) {
        v1alpha1_group_subject_free(group_local_nonprim);
        group_local_nonprim = NULL;
    }
    if (service_account_local_nonprim) {
        v1alpha1_service_account_subject_free(service_account_local_nonprim);
        service_account_local_nonprim = NULL;
    }
    if (user_local_nonprim) {
        v1alpha1_user_subject_free(user_local_nonprim);
        user_local_nonprim = NULL;
    }
    return NULL;

}
