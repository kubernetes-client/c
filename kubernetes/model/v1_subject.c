#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_subject.h"



v1_subject_t *v1_subject_create(
    char *api_group,
    char *kind,
    char *name,
    char *_namespace
    ) {
    v1_subject_t *v1_subject_local_var = malloc(sizeof(v1_subject_t));
    if (!v1_subject_local_var) {
        return NULL;
    }
    v1_subject_local_var->api_group = api_group;
    v1_subject_local_var->kind = kind;
    v1_subject_local_var->name = name;
    v1_subject_local_var->_namespace = _namespace;

    return v1_subject_local_var;
}


void v1_subject_free(v1_subject_t *v1_subject) {
    if(NULL == v1_subject){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_subject->api_group) {
        free(v1_subject->api_group);
        v1_subject->api_group = NULL;
    }
    if (v1_subject->kind) {
        free(v1_subject->kind);
        v1_subject->kind = NULL;
    }
    if (v1_subject->name) {
        free(v1_subject->name);
        v1_subject->name = NULL;
    }
    if (v1_subject->_namespace) {
        free(v1_subject->_namespace);
        v1_subject->_namespace = NULL;
    }
    free(v1_subject);
}

cJSON *v1_subject_convertToJSON(v1_subject_t *v1_subject) {
    cJSON *item = cJSON_CreateObject();

    // v1_subject->api_group
    if(v1_subject->api_group) { 
    if(cJSON_AddStringToObject(item, "apiGroup", v1_subject->api_group) == NULL) {
    goto fail; //String
    }
     } 


    // v1_subject->kind
    if (!v1_subject->kind) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "kind", v1_subject->kind) == NULL) {
    goto fail; //String
    }


    // v1_subject->name
    if (!v1_subject->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1_subject->name) == NULL) {
    goto fail; //String
    }


    // v1_subject->_namespace
    if(v1_subject->_namespace) { 
    if(cJSON_AddStringToObject(item, "namespace", v1_subject->_namespace) == NULL) {
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

v1_subject_t *v1_subject_parseFromJSON(cJSON *v1_subjectJSON){

    v1_subject_t *v1_subject_local_var = NULL;

    // v1_subject->api_group
    cJSON *api_group = cJSON_GetObjectItemCaseSensitive(v1_subjectJSON, "apiGroup");
    if (api_group) { 
    if(!cJSON_IsString(api_group))
    {
    goto end; //String
    }
    }

    // v1_subject->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_subjectJSON, "kind");
    if (!kind) {
        goto end;
    }

    
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }

    // v1_subject->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_subjectJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_subject->_namespace
    cJSON *_namespace = cJSON_GetObjectItemCaseSensitive(v1_subjectJSON, "namespace");
    if (_namespace) { 
    if(!cJSON_IsString(_namespace))
    {
    goto end; //String
    }
    }


    v1_subject_local_var = v1_subject_create (
        api_group ? strdup(api_group->valuestring) : NULL,
        strdup(kind->valuestring),
        strdup(name->valuestring),
        _namespace ? strdup(_namespace->valuestring) : NULL
        );

    return v1_subject_local_var;
end:
    return NULL;

}
