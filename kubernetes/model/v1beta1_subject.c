#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_subject.h"



v1beta1_subject_t *v1beta1_subject_create(
    v1beta1_group_subject_t *group,
    char *kind,
    v1beta1_service_account_subject_t *service_account,
    v1beta1_user_subject_t *user
    ) {
    v1beta1_subject_t *v1beta1_subject_local_var = malloc(sizeof(v1beta1_subject_t));
    if (!v1beta1_subject_local_var) {
        return NULL;
    }
    v1beta1_subject_local_var->group = group;
    v1beta1_subject_local_var->kind = kind;
    v1beta1_subject_local_var->service_account = service_account;
    v1beta1_subject_local_var->user = user;

    return v1beta1_subject_local_var;
}


void v1beta1_subject_free(v1beta1_subject_t *v1beta1_subject) {
    if(NULL == v1beta1_subject){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_subject->group) {
        v1beta1_group_subject_free(v1beta1_subject->group);
        v1beta1_subject->group = NULL;
    }
    if (v1beta1_subject->kind) {
        free(v1beta1_subject->kind);
        v1beta1_subject->kind = NULL;
    }
    if (v1beta1_subject->service_account) {
        v1beta1_service_account_subject_free(v1beta1_subject->service_account);
        v1beta1_subject->service_account = NULL;
    }
    if (v1beta1_subject->user) {
        v1beta1_user_subject_free(v1beta1_subject->user);
        v1beta1_subject->user = NULL;
    }
    free(v1beta1_subject);
}

cJSON *v1beta1_subject_convertToJSON(v1beta1_subject_t *v1beta1_subject) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_subject->group
    if(v1beta1_subject->group) { 
    cJSON *group_local_JSON = v1beta1_group_subject_convertToJSON(v1beta1_subject->group);
    if(group_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "group", group_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1beta1_subject->kind
    if (!v1beta1_subject->kind) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "kind", v1beta1_subject->kind) == NULL) {
    goto fail; //String
    }


    // v1beta1_subject->service_account
    if(v1beta1_subject->service_account) { 
    cJSON *service_account_local_JSON = v1beta1_service_account_subject_convertToJSON(v1beta1_subject->service_account);
    if(service_account_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "serviceAccount", service_account_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1beta1_subject->user
    if(v1beta1_subject->user) { 
    cJSON *user_local_JSON = v1beta1_user_subject_convertToJSON(v1beta1_subject->user);
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

v1beta1_subject_t *v1beta1_subject_parseFromJSON(cJSON *v1beta1_subjectJSON){

    v1beta1_subject_t *v1beta1_subject_local_var = NULL;

    // define the local variable for v1beta1_subject->group
    v1beta1_group_subject_t *group_local_nonprim = NULL;

    // define the local variable for v1beta1_subject->service_account
    v1beta1_service_account_subject_t *service_account_local_nonprim = NULL;

    // define the local variable for v1beta1_subject->user
    v1beta1_user_subject_t *user_local_nonprim = NULL;

    // v1beta1_subject->group
    cJSON *group = cJSON_GetObjectItemCaseSensitive(v1beta1_subjectJSON, "group");
    if (group) { 
    group_local_nonprim = v1beta1_group_subject_parseFromJSON(group); //nonprimitive
    }

    // v1beta1_subject->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1beta1_subjectJSON, "kind");
    if (!kind) {
        goto end;
    }

    
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }

    // v1beta1_subject->service_account
    cJSON *service_account = cJSON_GetObjectItemCaseSensitive(v1beta1_subjectJSON, "serviceAccount");
    if (service_account) { 
    service_account_local_nonprim = v1beta1_service_account_subject_parseFromJSON(service_account); //nonprimitive
    }

    // v1beta1_subject->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(v1beta1_subjectJSON, "user");
    if (user) { 
    user_local_nonprim = v1beta1_user_subject_parseFromJSON(user); //nonprimitive
    }


    v1beta1_subject_local_var = v1beta1_subject_create (
        group ? group_local_nonprim : NULL,
        strdup(kind->valuestring),
        service_account ? service_account_local_nonprim : NULL,
        user ? user_local_nonprim : NULL
        );

    return v1beta1_subject_local_var;
end:
    if (group_local_nonprim) {
        v1beta1_group_subject_free(group_local_nonprim);
        group_local_nonprim = NULL;
    }
    if (service_account_local_nonprim) {
        v1beta1_service_account_subject_free(service_account_local_nonprim);
        service_account_local_nonprim = NULL;
    }
    if (user_local_nonprim) {
        v1beta1_user_subject_free(user_local_nonprim);
        user_local_nonprim = NULL;
    }
    return NULL;

}
