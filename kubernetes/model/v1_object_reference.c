#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_object_reference.h"



v1_object_reference_t *v1_object_reference_create(
    char *api_version,
    char *field_path,
    char *kind,
    char *name,
    char *_namespace,
    char *resource_version,
    char *uid
    ) {
    v1_object_reference_t *v1_object_reference_local_var = malloc(sizeof(v1_object_reference_t));
    if (!v1_object_reference_local_var) {
        return NULL;
    }
    v1_object_reference_local_var->api_version = api_version;
    v1_object_reference_local_var->field_path = field_path;
    v1_object_reference_local_var->kind = kind;
    v1_object_reference_local_var->name = name;
    v1_object_reference_local_var->_namespace = _namespace;
    v1_object_reference_local_var->resource_version = resource_version;
    v1_object_reference_local_var->uid = uid;

    return v1_object_reference_local_var;
}


void v1_object_reference_free(v1_object_reference_t *v1_object_reference) {
    if(NULL == v1_object_reference){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_object_reference->api_version) {
        free(v1_object_reference->api_version);
        v1_object_reference->api_version = NULL;
    }
    if (v1_object_reference->field_path) {
        free(v1_object_reference->field_path);
        v1_object_reference->field_path = NULL;
    }
    if (v1_object_reference->kind) {
        free(v1_object_reference->kind);
        v1_object_reference->kind = NULL;
    }
    if (v1_object_reference->name) {
        free(v1_object_reference->name);
        v1_object_reference->name = NULL;
    }
    if (v1_object_reference->_namespace) {
        free(v1_object_reference->_namespace);
        v1_object_reference->_namespace = NULL;
    }
    if (v1_object_reference->resource_version) {
        free(v1_object_reference->resource_version);
        v1_object_reference->resource_version = NULL;
    }
    if (v1_object_reference->uid) {
        free(v1_object_reference->uid);
        v1_object_reference->uid = NULL;
    }
    free(v1_object_reference);
}

cJSON *v1_object_reference_convertToJSON(v1_object_reference_t *v1_object_reference) {
    cJSON *item = cJSON_CreateObject();

    // v1_object_reference->api_version
    if(v1_object_reference->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_object_reference->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // v1_object_reference->field_path
    if(v1_object_reference->field_path) { 
    if(cJSON_AddStringToObject(item, "fieldPath", v1_object_reference->field_path) == NULL) {
    goto fail; //String
    }
     } 


    // v1_object_reference->kind
    if(v1_object_reference->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_object_reference->kind) == NULL) {
    goto fail; //String
    }
     } 


    // v1_object_reference->name
    if(v1_object_reference->name) { 
    if(cJSON_AddStringToObject(item, "name", v1_object_reference->name) == NULL) {
    goto fail; //String
    }
     } 


    // v1_object_reference->_namespace
    if(v1_object_reference->_namespace) { 
    if(cJSON_AddStringToObject(item, "namespace", v1_object_reference->_namespace) == NULL) {
    goto fail; //String
    }
     } 


    // v1_object_reference->resource_version
    if(v1_object_reference->resource_version) { 
    if(cJSON_AddStringToObject(item, "resourceVersion", v1_object_reference->resource_version) == NULL) {
    goto fail; //String
    }
     } 


    // v1_object_reference->uid
    if(v1_object_reference->uid) { 
    if(cJSON_AddStringToObject(item, "uid", v1_object_reference->uid) == NULL) {
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

v1_object_reference_t *v1_object_reference_parseFromJSON(cJSON *v1_object_referenceJSON){

    v1_object_reference_t *v1_object_reference_local_var = NULL;

    // v1_object_reference->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_object_referenceJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v1_object_reference->field_path
    cJSON *field_path = cJSON_GetObjectItemCaseSensitive(v1_object_referenceJSON, "fieldPath");
    if (field_path) { 
    if(!cJSON_IsString(field_path))
    {
    goto end; //String
    }
    }

    // v1_object_reference->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_object_referenceJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_object_reference->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_object_referenceJSON, "name");
    if (name) { 
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }
    }

    // v1_object_reference->_namespace
    cJSON *_namespace = cJSON_GetObjectItemCaseSensitive(v1_object_referenceJSON, "namespace");
    if (_namespace) { 
    if(!cJSON_IsString(_namespace))
    {
    goto end; //String
    }
    }

    // v1_object_reference->resource_version
    cJSON *resource_version = cJSON_GetObjectItemCaseSensitive(v1_object_referenceJSON, "resourceVersion");
    if (resource_version) { 
    if(!cJSON_IsString(resource_version))
    {
    goto end; //String
    }
    }

    // v1_object_reference->uid
    cJSON *uid = cJSON_GetObjectItemCaseSensitive(v1_object_referenceJSON, "uid");
    if (uid) { 
    if(!cJSON_IsString(uid))
    {
    goto end; //String
    }
    }


    v1_object_reference_local_var = v1_object_reference_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        field_path ? strdup(field_path->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        name ? strdup(name->valuestring) : NULL,
        _namespace ? strdup(_namespace->valuestring) : NULL,
        resource_version ? strdup(resource_version->valuestring) : NULL,
        uid ? strdup(uid->valuestring) : NULL
        );

    return v1_object_reference_local_var;
end:
    return NULL;

}
