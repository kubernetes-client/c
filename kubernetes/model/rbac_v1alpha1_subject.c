#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "rbac_v1alpha1_subject.h"



rbac_v1alpha1_subject_t *rbac_v1alpha1_subject_create(
    char *api_version,
    char *kind,
    char *name,
    char *_namespace
    ) {
    rbac_v1alpha1_subject_t *rbac_v1alpha1_subject_local_var = malloc(sizeof(rbac_v1alpha1_subject_t));
    if (!rbac_v1alpha1_subject_local_var) {
        return NULL;
    }
    rbac_v1alpha1_subject_local_var->api_version = api_version;
    rbac_v1alpha1_subject_local_var->kind = kind;
    rbac_v1alpha1_subject_local_var->name = name;
    rbac_v1alpha1_subject_local_var->_namespace = _namespace;

    return rbac_v1alpha1_subject_local_var;
}


void rbac_v1alpha1_subject_free(rbac_v1alpha1_subject_t *rbac_v1alpha1_subject) {
    if(NULL == rbac_v1alpha1_subject){
        return ;
    }
    listEntry_t *listEntry;
    if (rbac_v1alpha1_subject->api_version) {
        free(rbac_v1alpha1_subject->api_version);
        rbac_v1alpha1_subject->api_version = NULL;
    }
    if (rbac_v1alpha1_subject->kind) {
        free(rbac_v1alpha1_subject->kind);
        rbac_v1alpha1_subject->kind = NULL;
    }
    if (rbac_v1alpha1_subject->name) {
        free(rbac_v1alpha1_subject->name);
        rbac_v1alpha1_subject->name = NULL;
    }
    if (rbac_v1alpha1_subject->_namespace) {
        free(rbac_v1alpha1_subject->_namespace);
        rbac_v1alpha1_subject->_namespace = NULL;
    }
    free(rbac_v1alpha1_subject);
}

cJSON *rbac_v1alpha1_subject_convertToJSON(rbac_v1alpha1_subject_t *rbac_v1alpha1_subject) {
    cJSON *item = cJSON_CreateObject();

    // rbac_v1alpha1_subject->api_version
    if(rbac_v1alpha1_subject->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", rbac_v1alpha1_subject->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // rbac_v1alpha1_subject->kind
    if (!rbac_v1alpha1_subject->kind) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "kind", rbac_v1alpha1_subject->kind) == NULL) {
    goto fail; //String
    }


    // rbac_v1alpha1_subject->name
    if (!rbac_v1alpha1_subject->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", rbac_v1alpha1_subject->name) == NULL) {
    goto fail; //String
    }


    // rbac_v1alpha1_subject->_namespace
    if(rbac_v1alpha1_subject->_namespace) { 
    if(cJSON_AddStringToObject(item, "namespace", rbac_v1alpha1_subject->_namespace) == NULL) {
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

rbac_v1alpha1_subject_t *rbac_v1alpha1_subject_parseFromJSON(cJSON *rbac_v1alpha1_subjectJSON){

    rbac_v1alpha1_subject_t *rbac_v1alpha1_subject_local_var = NULL;

    // rbac_v1alpha1_subject->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(rbac_v1alpha1_subjectJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // rbac_v1alpha1_subject->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(rbac_v1alpha1_subjectJSON, "kind");
    if (!kind) {
        goto end;
    }

    
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }

    // rbac_v1alpha1_subject->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(rbac_v1alpha1_subjectJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // rbac_v1alpha1_subject->_namespace
    cJSON *_namespace = cJSON_GetObjectItemCaseSensitive(rbac_v1alpha1_subjectJSON, "namespace");
    if (_namespace) { 
    if(!cJSON_IsString(_namespace))
    {
    goto end; //String
    }
    }


    rbac_v1alpha1_subject_local_var = rbac_v1alpha1_subject_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        strdup(kind->valuestring),
        strdup(name->valuestring),
        _namespace ? strdup(_namespace->valuestring) : NULL
        );

    return rbac_v1alpha1_subject_local_var;
end:
    return NULL;

}
