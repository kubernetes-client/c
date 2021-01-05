#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_service_account_subject.h"



v1alpha1_service_account_subject_t *v1alpha1_service_account_subject_create(
    char *name,
    char *_namespace
    ) {
    v1alpha1_service_account_subject_t *v1alpha1_service_account_subject_local_var = malloc(sizeof(v1alpha1_service_account_subject_t));
    if (!v1alpha1_service_account_subject_local_var) {
        return NULL;
    }
    v1alpha1_service_account_subject_local_var->name = name;
    v1alpha1_service_account_subject_local_var->_namespace = _namespace;

    return v1alpha1_service_account_subject_local_var;
}


void v1alpha1_service_account_subject_free(v1alpha1_service_account_subject_t *v1alpha1_service_account_subject) {
    if(NULL == v1alpha1_service_account_subject){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_service_account_subject->name) {
        free(v1alpha1_service_account_subject->name);
        v1alpha1_service_account_subject->name = NULL;
    }
    if (v1alpha1_service_account_subject->_namespace) {
        free(v1alpha1_service_account_subject->_namespace);
        v1alpha1_service_account_subject->_namespace = NULL;
    }
    free(v1alpha1_service_account_subject);
}

cJSON *v1alpha1_service_account_subject_convertToJSON(v1alpha1_service_account_subject_t *v1alpha1_service_account_subject) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_service_account_subject->name
    if (!v1alpha1_service_account_subject->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1alpha1_service_account_subject->name) == NULL) {
    goto fail; //String
    }


    // v1alpha1_service_account_subject->_namespace
    if (!v1alpha1_service_account_subject->_namespace) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "namespace", v1alpha1_service_account_subject->_namespace) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_service_account_subject_t *v1alpha1_service_account_subject_parseFromJSON(cJSON *v1alpha1_service_account_subjectJSON){

    v1alpha1_service_account_subject_t *v1alpha1_service_account_subject_local_var = NULL;

    // v1alpha1_service_account_subject->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1alpha1_service_account_subjectJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1alpha1_service_account_subject->_namespace
    cJSON *_namespace = cJSON_GetObjectItemCaseSensitive(v1alpha1_service_account_subjectJSON, "namespace");
    if (!_namespace) {
        goto end;
    }

    
    if(!cJSON_IsString(_namespace))
    {
    goto end; //String
    }


    v1alpha1_service_account_subject_local_var = v1alpha1_service_account_subject_create (
        strdup(name->valuestring),
        strdup(_namespace->valuestring)
        );

    return v1alpha1_service_account_subject_local_var;
end:
    return NULL;

}
