#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_parent_reference.h"



static v1_parent_reference_t *v1_parent_reference_create_internal(
    char *group,
    char *name,
    char *_namespace,
    char *resource
    ) {
    v1_parent_reference_t *v1_parent_reference_local_var = malloc(sizeof(v1_parent_reference_t));
    if (!v1_parent_reference_local_var) {
        return NULL;
    }
    memset(v1_parent_reference_local_var, 0, sizeof(v1_parent_reference_t));
    v1_parent_reference_local_var->_library_owned = 1;
    v1_parent_reference_local_var->group = group;
    v1_parent_reference_local_var->name = name;
    v1_parent_reference_local_var->_namespace = _namespace;
    v1_parent_reference_local_var->resource = resource;
    return v1_parent_reference_local_var;
}

__attribute__((deprecated)) v1_parent_reference_t *v1_parent_reference_create(
    char *group,
    char *name,
    char *_namespace,
    char *resource
    ) {
    v1_parent_reference_t *result = v1_parent_reference_create_internal (
        group,
        name,
        _namespace,
        resource
        );
    if (!result) {
    }
    return result;
}

void v1_parent_reference_free(v1_parent_reference_t *v1_parent_reference) {
    if(NULL == v1_parent_reference){
        return ;
    }
    if(v1_parent_reference->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_parent_reference_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_parent_reference->group) {
        free(v1_parent_reference->group);
        v1_parent_reference->group = NULL;
    }
    if (v1_parent_reference->name) {
        free(v1_parent_reference->name);
        v1_parent_reference->name = NULL;
    }
    if (v1_parent_reference->_namespace) {
        free(v1_parent_reference->_namespace);
        v1_parent_reference->_namespace = NULL;
    }
    if (v1_parent_reference->resource) {
        free(v1_parent_reference->resource);
        v1_parent_reference->resource = NULL;
    }
    free(v1_parent_reference);
}

cJSON *v1_parent_reference_convertToJSON(v1_parent_reference_t *v1_parent_reference) {
    cJSON *item = cJSON_CreateObject();

    // v1_parent_reference->group
    if(v1_parent_reference->group) {
    if(cJSON_AddStringToObject(item, "group", v1_parent_reference->group) == NULL) {
    goto fail; //String
    }
    }


    // v1_parent_reference->name
    if (!v1_parent_reference->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_parent_reference->name) == NULL) {
    goto fail; //String
    }


    // v1_parent_reference->_namespace
    if(v1_parent_reference->_namespace) {
    if(cJSON_AddStringToObject(item, "namespace", v1_parent_reference->_namespace) == NULL) {
    goto fail; //String
    }
    }


    // v1_parent_reference->resource
    if (!v1_parent_reference->resource) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "resource", v1_parent_reference->resource) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_parent_reference_t *v1_parent_reference_parseFromJSON(cJSON *v1_parent_referenceJSON){

    v1_parent_reference_t *v1_parent_reference_local_var = NULL;

    char *group_local_str = NULL;

    char *name_local_str = NULL;

    char *_namespace_local_str = NULL;

    char *resource_local_str = NULL;

    // v1_parent_reference->group
    cJSON *group = cJSON_GetObjectItemCaseSensitive(v1_parent_referenceJSON, "group");
    if (cJSON_IsNull(group)) {
        group = NULL;
    }
    if (group) { 
    if(!cJSON_IsString(group) && !cJSON_IsNull(group))
    {
    goto end; //String
    }
    }

    // v1_parent_reference->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_parent_referenceJSON, "name");
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

    // v1_parent_reference->_namespace
    cJSON *_namespace = cJSON_GetObjectItemCaseSensitive(v1_parent_referenceJSON, "namespace");
    if (cJSON_IsNull(_namespace)) {
        _namespace = NULL;
    }
    if (_namespace) { 
    if(!cJSON_IsString(_namespace) && !cJSON_IsNull(_namespace))
    {
    goto end; //String
    }
    }

    // v1_parent_reference->resource
    cJSON *resource = cJSON_GetObjectItemCaseSensitive(v1_parent_referenceJSON, "resource");
    if (cJSON_IsNull(resource)) {
        resource = NULL;
    }
    if (!resource) {
        goto end;
    }

    
    if(!cJSON_IsString(resource))
    {
    goto end; //String
    }


    if (group && !cJSON_IsNull(group)) group_local_str = strdup(group->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (_namespace && !cJSON_IsNull(_namespace)) _namespace_local_str = strdup(_namespace->valuestring);
    if (resource && !cJSON_IsNull(resource)) resource_local_str = strdup(resource->valuestring);

    v1_parent_reference_local_var = v1_parent_reference_create_internal (
        group_local_str,
        name_local_str,
        _namespace_local_str,
        resource_local_str
        );

    if (!v1_parent_reference_local_var) {
        goto end;
    }

    return v1_parent_reference_local_var;
end:
    if (group_local_str) {
        free(group_local_str);
        group_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (_namespace_local_str) {
        free(_namespace_local_str);
        _namespace_local_str = NULL;
    }
    if (resource_local_str) {
        free(resource_local_str);
        resource_local_str = NULL;
    }
    return NULL;

}
