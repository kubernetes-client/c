#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_parent_reference.h"



v1alpha1_parent_reference_t *v1alpha1_parent_reference_create(
    char *group,
    char *name,
    char *_namespace,
    char *resource,
    char *uid
    ) {
    v1alpha1_parent_reference_t *v1alpha1_parent_reference_local_var = malloc(sizeof(v1alpha1_parent_reference_t));
    if (!v1alpha1_parent_reference_local_var) {
        return NULL;
    }
    v1alpha1_parent_reference_local_var->group = group;
    v1alpha1_parent_reference_local_var->name = name;
    v1alpha1_parent_reference_local_var->_namespace = _namespace;
    v1alpha1_parent_reference_local_var->resource = resource;
    v1alpha1_parent_reference_local_var->uid = uid;

    return v1alpha1_parent_reference_local_var;
}


void v1alpha1_parent_reference_free(v1alpha1_parent_reference_t *v1alpha1_parent_reference) {
    if(NULL == v1alpha1_parent_reference){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_parent_reference->group) {
        free(v1alpha1_parent_reference->group);
        v1alpha1_parent_reference->group = NULL;
    }
    if (v1alpha1_parent_reference->name) {
        free(v1alpha1_parent_reference->name);
        v1alpha1_parent_reference->name = NULL;
    }
    if (v1alpha1_parent_reference->_namespace) {
        free(v1alpha1_parent_reference->_namespace);
        v1alpha1_parent_reference->_namespace = NULL;
    }
    if (v1alpha1_parent_reference->resource) {
        free(v1alpha1_parent_reference->resource);
        v1alpha1_parent_reference->resource = NULL;
    }
    if (v1alpha1_parent_reference->uid) {
        free(v1alpha1_parent_reference->uid);
        v1alpha1_parent_reference->uid = NULL;
    }
    free(v1alpha1_parent_reference);
}

cJSON *v1alpha1_parent_reference_convertToJSON(v1alpha1_parent_reference_t *v1alpha1_parent_reference) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_parent_reference->group
    if(v1alpha1_parent_reference->group) {
    if(cJSON_AddStringToObject(item, "group", v1alpha1_parent_reference->group) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_parent_reference->name
    if(v1alpha1_parent_reference->name) {
    if(cJSON_AddStringToObject(item, "name", v1alpha1_parent_reference->name) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_parent_reference->_namespace
    if(v1alpha1_parent_reference->_namespace) {
    if(cJSON_AddStringToObject(item, "namespace", v1alpha1_parent_reference->_namespace) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_parent_reference->resource
    if(v1alpha1_parent_reference->resource) {
    if(cJSON_AddStringToObject(item, "resource", v1alpha1_parent_reference->resource) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_parent_reference->uid
    if(v1alpha1_parent_reference->uid) {
    if(cJSON_AddStringToObject(item, "uid", v1alpha1_parent_reference->uid) == NULL) {
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

v1alpha1_parent_reference_t *v1alpha1_parent_reference_parseFromJSON(cJSON *v1alpha1_parent_referenceJSON){

    v1alpha1_parent_reference_t *v1alpha1_parent_reference_local_var = NULL;

    // v1alpha1_parent_reference->group
    cJSON *group = cJSON_GetObjectItemCaseSensitive(v1alpha1_parent_referenceJSON, "group");
    if (group) { 
    if(!cJSON_IsString(group) && !cJSON_IsNull(group))
    {
    goto end; //String
    }
    }

    // v1alpha1_parent_reference->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1alpha1_parent_referenceJSON, "name");
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // v1alpha1_parent_reference->_namespace
    cJSON *_namespace = cJSON_GetObjectItemCaseSensitive(v1alpha1_parent_referenceJSON, "namespace");
    if (_namespace) { 
    if(!cJSON_IsString(_namespace) && !cJSON_IsNull(_namespace))
    {
    goto end; //String
    }
    }

    // v1alpha1_parent_reference->resource
    cJSON *resource = cJSON_GetObjectItemCaseSensitive(v1alpha1_parent_referenceJSON, "resource");
    if (resource) { 
    if(!cJSON_IsString(resource) && !cJSON_IsNull(resource))
    {
    goto end; //String
    }
    }

    // v1alpha1_parent_reference->uid
    cJSON *uid = cJSON_GetObjectItemCaseSensitive(v1alpha1_parent_referenceJSON, "uid");
    if (uid) { 
    if(!cJSON_IsString(uid) && !cJSON_IsNull(uid))
    {
    goto end; //String
    }
    }


    v1alpha1_parent_reference_local_var = v1alpha1_parent_reference_create (
        group && !cJSON_IsNull(group) ? strdup(group->valuestring) : NULL,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        _namespace && !cJSON_IsNull(_namespace) ? strdup(_namespace->valuestring) : NULL,
        resource && !cJSON_IsNull(resource) ? strdup(resource->valuestring) : NULL,
        uid && !cJSON_IsNull(uid) ? strdup(uid->valuestring) : NULL
        );

    return v1alpha1_parent_reference_local_var;
end:
    return NULL;

}
