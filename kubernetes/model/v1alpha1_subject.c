#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_subject.h"



v1alpha1_subject_t *v1alpha1_subject_create(
    char *api_version,
    char *kind,
    char *name,
    char *_namespace
    ) {
    v1alpha1_subject_t *v1alpha1_subject_local_var = malloc(sizeof(v1alpha1_subject_t));
    if (!v1alpha1_subject_local_var) {
        return NULL;
    }
    v1alpha1_subject_local_var->api_version = api_version;
    v1alpha1_subject_local_var->kind = kind;
    v1alpha1_subject_local_var->name = name;
    v1alpha1_subject_local_var->_namespace = _namespace;

    return v1alpha1_subject_local_var;
}


void v1alpha1_subject_free(v1alpha1_subject_t *v1alpha1_subject) {
    if(NULL == v1alpha1_subject){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_subject->api_version) {
        free(v1alpha1_subject->api_version);
        v1alpha1_subject->api_version = NULL;
    }
    if (v1alpha1_subject->kind) {
        free(v1alpha1_subject->kind);
        v1alpha1_subject->kind = NULL;
    }
    if (v1alpha1_subject->name) {
        free(v1alpha1_subject->name);
        v1alpha1_subject->name = NULL;
    }
    if (v1alpha1_subject->_namespace) {
        free(v1alpha1_subject->_namespace);
        v1alpha1_subject->_namespace = NULL;
    }
    free(v1alpha1_subject);
}

cJSON *v1alpha1_subject_convertToJSON(v1alpha1_subject_t *v1alpha1_subject) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_subject->api_version
    if(v1alpha1_subject->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1alpha1_subject->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // v1alpha1_subject->kind
    if (!v1alpha1_subject->kind) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "kind", v1alpha1_subject->kind) == NULL) {
    goto fail; //String
    }


    // v1alpha1_subject->name
    if (!v1alpha1_subject->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1alpha1_subject->name) == NULL) {
    goto fail; //String
    }


    // v1alpha1_subject->_namespace
    if(v1alpha1_subject->_namespace) { 
    if(cJSON_AddStringToObject(item, "namespace", v1alpha1_subject->_namespace) == NULL) {
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

v1alpha1_subject_t *v1alpha1_subject_parseFromJSON(cJSON *v1alpha1_subjectJSON){

    v1alpha1_subject_t *v1alpha1_subject_local_var = NULL;

    // v1alpha1_subject->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1alpha1_subjectJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v1alpha1_subject->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha1_subjectJSON, "kind");
    if (!kind) {
        goto end;
    }

    
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }

    // v1alpha1_subject->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1alpha1_subjectJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1alpha1_subject->_namespace
    cJSON *_namespace = cJSON_GetObjectItemCaseSensitive(v1alpha1_subjectJSON, "namespace");
    if (_namespace) { 
    if(!cJSON_IsString(_namespace))
    {
    goto end; //String
    }
    }


    v1alpha1_subject_local_var = v1alpha1_subject_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        strdup(kind->valuestring),
        strdup(name->valuestring),
        _namespace ? strdup(_namespace->valuestring) : NULL
        );

    return v1alpha1_subject_local_var;
end:
    return NULL;

}
