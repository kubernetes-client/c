#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "rbac_v1_subject.h"



static rbac_v1_subject_t *rbac_v1_subject_create_internal(
    char *api_group,
    char *kind,
    char *name,
    char *_namespace
    ) {
    rbac_v1_subject_t *rbac_v1_subject_local_var = malloc(sizeof(rbac_v1_subject_t));
    if (!rbac_v1_subject_local_var) {
        return NULL;
    }
    memset(rbac_v1_subject_local_var, 0, sizeof(rbac_v1_subject_t));
    rbac_v1_subject_local_var->_library_owned = 1;
    rbac_v1_subject_local_var->api_group = api_group;
    rbac_v1_subject_local_var->kind = kind;
    rbac_v1_subject_local_var->name = name;
    rbac_v1_subject_local_var->_namespace = _namespace;
    return rbac_v1_subject_local_var;
}

__attribute__((deprecated)) rbac_v1_subject_t *rbac_v1_subject_create(
    char *api_group,
    char *kind,
    char *name,
    char *_namespace
    ) {
    rbac_v1_subject_t *result = rbac_v1_subject_create_internal (
        api_group,
        kind,
        name,
        _namespace
        );
    if (!result) {
    }
    return result;
}

void rbac_v1_subject_free(rbac_v1_subject_t *rbac_v1_subject) {
    if(NULL == rbac_v1_subject){
        return ;
    }
    if(rbac_v1_subject->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "rbac_v1_subject_free");
        return ;
    }
    listEntry_t *listEntry;
    if (rbac_v1_subject->api_group) {
        free(rbac_v1_subject->api_group);
        rbac_v1_subject->api_group = NULL;
    }
    if (rbac_v1_subject->kind) {
        free(rbac_v1_subject->kind);
        rbac_v1_subject->kind = NULL;
    }
    if (rbac_v1_subject->name) {
        free(rbac_v1_subject->name);
        rbac_v1_subject->name = NULL;
    }
    if (rbac_v1_subject->_namespace) {
        free(rbac_v1_subject->_namespace);
        rbac_v1_subject->_namespace = NULL;
    }
    free(rbac_v1_subject);
}

cJSON *rbac_v1_subject_convertToJSON(rbac_v1_subject_t *rbac_v1_subject) {
    cJSON *item = cJSON_CreateObject();

    // rbac_v1_subject->api_group
    if(rbac_v1_subject->api_group) {
    if(cJSON_AddStringToObject(item, "apiGroup", rbac_v1_subject->api_group) == NULL) {
    goto fail; //String
    }
    }


    // rbac_v1_subject->kind
    if (!rbac_v1_subject->kind) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kind", rbac_v1_subject->kind) == NULL) {
    goto fail; //String
    }


    // rbac_v1_subject->name
    if (!rbac_v1_subject->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", rbac_v1_subject->name) == NULL) {
    goto fail; //String
    }


    // rbac_v1_subject->_namespace
    if(rbac_v1_subject->_namespace) {
    if(cJSON_AddStringToObject(item, "namespace", rbac_v1_subject->_namespace) == NULL) {
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

rbac_v1_subject_t *rbac_v1_subject_parseFromJSON(cJSON *rbac_v1_subjectJSON){

    rbac_v1_subject_t *rbac_v1_subject_local_var = NULL;

    char *api_group_local_str = NULL;

    char *kind_local_str = NULL;

    char *name_local_str = NULL;

    char *_namespace_local_str = NULL;

    // rbac_v1_subject->api_group
    cJSON *api_group = cJSON_GetObjectItemCaseSensitive(rbac_v1_subjectJSON, "apiGroup");
    if (cJSON_IsNull(api_group)) {
        api_group = NULL;
    }
    if (api_group) { 
    if(!cJSON_IsString(api_group) && !cJSON_IsNull(api_group))
    {
    goto end; //String
    }
    }

    // rbac_v1_subject->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(rbac_v1_subjectJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (!kind) {
        goto end;
    }

    
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }

    // rbac_v1_subject->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(rbac_v1_subjectJSON, "name");
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

    // rbac_v1_subject->_namespace
    cJSON *_namespace = cJSON_GetObjectItemCaseSensitive(rbac_v1_subjectJSON, "namespace");
    if (cJSON_IsNull(_namespace)) {
        _namespace = NULL;
    }
    if (_namespace) { 
    if(!cJSON_IsString(_namespace) && !cJSON_IsNull(_namespace))
    {
    goto end; //String
    }
    }


    if (api_group && !cJSON_IsNull(api_group)) api_group_local_str = strdup(api_group->valuestring);
    if (kind && !cJSON_IsNull(kind)) kind_local_str = strdup(kind->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (_namespace && !cJSON_IsNull(_namespace)) _namespace_local_str = strdup(_namespace->valuestring);

    rbac_v1_subject_local_var = rbac_v1_subject_create_internal (
        api_group_local_str,
        kind_local_str,
        name_local_str,
        _namespace_local_str
        );

    if (!rbac_v1_subject_local_var) {
        goto end;
    }

    return rbac_v1_subject_local_var;
end:
    if (api_group_local_str) {
        free(api_group_local_str);
        api_group_local_str = NULL;
    }
    if (kind_local_str) {
        free(kind_local_str);
        kind_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (_namespace_local_str) {
        free(_namespace_local_str);
        _namespace_local_str = NULL;
    }
    return NULL;

}
