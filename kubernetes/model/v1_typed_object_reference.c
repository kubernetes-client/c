#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_typed_object_reference.h"



static v1_typed_object_reference_t *v1_typed_object_reference_create_internal(
    char *api_group,
    char *kind,
    char *name,
    char *_namespace
    ) {
    v1_typed_object_reference_t *v1_typed_object_reference_local_var = malloc(sizeof(v1_typed_object_reference_t));
    if (!v1_typed_object_reference_local_var) {
        return NULL;
    }
    memset(v1_typed_object_reference_local_var, 0, sizeof(v1_typed_object_reference_t));
    v1_typed_object_reference_local_var->_library_owned = 1;
    v1_typed_object_reference_local_var->api_group = api_group;
    v1_typed_object_reference_local_var->kind = kind;
    v1_typed_object_reference_local_var->name = name;
    v1_typed_object_reference_local_var->_namespace = _namespace;
    return v1_typed_object_reference_local_var;
}

__attribute__((deprecated)) v1_typed_object_reference_t *v1_typed_object_reference_create(
    char *api_group,
    char *kind,
    char *name,
    char *_namespace
    ) {
    v1_typed_object_reference_t *result = v1_typed_object_reference_create_internal (
        api_group,
        kind,
        name,
        _namespace
        );
    if (!result) {
    }
    return result;
}

void v1_typed_object_reference_free(v1_typed_object_reference_t *v1_typed_object_reference) {
    if(NULL == v1_typed_object_reference){
        return ;
    }
    if(v1_typed_object_reference->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_typed_object_reference_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_typed_object_reference->api_group) {
        free(v1_typed_object_reference->api_group);
        v1_typed_object_reference->api_group = NULL;
    }
    if (v1_typed_object_reference->kind) {
        free(v1_typed_object_reference->kind);
        v1_typed_object_reference->kind = NULL;
    }
    if (v1_typed_object_reference->name) {
        free(v1_typed_object_reference->name);
        v1_typed_object_reference->name = NULL;
    }
    if (v1_typed_object_reference->_namespace) {
        free(v1_typed_object_reference->_namespace);
        v1_typed_object_reference->_namespace = NULL;
    }
    free(v1_typed_object_reference);
}

cJSON *v1_typed_object_reference_convertToJSON(v1_typed_object_reference_t *v1_typed_object_reference) {
    cJSON *item = cJSON_CreateObject();

    // v1_typed_object_reference->api_group
    if(v1_typed_object_reference->api_group) {
    if(cJSON_AddStringToObject(item, "apiGroup", v1_typed_object_reference->api_group) == NULL) {
    goto fail; //String
    }
    }


    // v1_typed_object_reference->kind
    if (!v1_typed_object_reference->kind) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kind", v1_typed_object_reference->kind) == NULL) {
    goto fail; //String
    }


    // v1_typed_object_reference->name
    if (!v1_typed_object_reference->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_typed_object_reference->name) == NULL) {
    goto fail; //String
    }


    // v1_typed_object_reference->_namespace
    if(v1_typed_object_reference->_namespace) {
    if(cJSON_AddStringToObject(item, "namespace", v1_typed_object_reference->_namespace) == NULL) {
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

v1_typed_object_reference_t *v1_typed_object_reference_parseFromJSON(cJSON *v1_typed_object_referenceJSON){

    v1_typed_object_reference_t *v1_typed_object_reference_local_var = NULL;

    char *api_group_local_str = NULL;

    char *kind_local_str = NULL;

    char *name_local_str = NULL;

    char *_namespace_local_str = NULL;

    // v1_typed_object_reference->api_group
    cJSON *api_group = cJSON_GetObjectItemCaseSensitive(v1_typed_object_referenceJSON, "apiGroup");
    if (cJSON_IsNull(api_group)) {
        api_group = NULL;
    }
    if (api_group) { 
    if(!cJSON_IsString(api_group) && !cJSON_IsNull(api_group))
    {
    goto end; //String
    }
    }

    // v1_typed_object_reference->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_typed_object_referenceJSON, "kind");
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

    // v1_typed_object_reference->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_typed_object_referenceJSON, "name");
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

    // v1_typed_object_reference->_namespace
    cJSON *_namespace = cJSON_GetObjectItemCaseSensitive(v1_typed_object_referenceJSON, "namespace");
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

    v1_typed_object_reference_local_var = v1_typed_object_reference_create_internal (
        api_group_local_str,
        kind_local_str,
        name_local_str,
        _namespace_local_str
        );

    if (!v1_typed_object_reference_local_var) {
        goto end;
    }

    return v1_typed_object_reference_local_var;
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
