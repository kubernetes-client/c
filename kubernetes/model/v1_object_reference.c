#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_object_reference.h"



static v1_object_reference_t *v1_object_reference_create_internal(
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
    memset(v1_object_reference_local_var, 0, sizeof(v1_object_reference_t));
    v1_object_reference_local_var->_library_owned = 1;
    v1_object_reference_local_var->api_version = api_version;
    v1_object_reference_local_var->field_path = field_path;
    v1_object_reference_local_var->kind = kind;
    v1_object_reference_local_var->name = name;
    v1_object_reference_local_var->_namespace = _namespace;
    v1_object_reference_local_var->resource_version = resource_version;
    v1_object_reference_local_var->uid = uid;
    return v1_object_reference_local_var;
}

__attribute__((deprecated)) v1_object_reference_t *v1_object_reference_create(
    char *api_version,
    char *field_path,
    char *kind,
    char *name,
    char *_namespace,
    char *resource_version,
    char *uid
    ) {
    v1_object_reference_t *result = v1_object_reference_create_internal (
        api_version,
        field_path,
        kind,
        name,
        _namespace,
        resource_version,
        uid
        );
    if (!result) {
    }
    return result;
}

void v1_object_reference_free(v1_object_reference_t *v1_object_reference) {
    if(NULL == v1_object_reference){
        return ;
    }
    if(v1_object_reference->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_object_reference_free");
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

    char *api_version_local_str = NULL;

    char *field_path_local_str = NULL;

    char *kind_local_str = NULL;

    char *name_local_str = NULL;

    char *_namespace_local_str = NULL;

    char *resource_version_local_str = NULL;

    char *uid_local_str = NULL;

    // v1_object_reference->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_object_referenceJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_object_reference->field_path
    cJSON *field_path = cJSON_GetObjectItemCaseSensitive(v1_object_referenceJSON, "fieldPath");
    if (cJSON_IsNull(field_path)) {
        field_path = NULL;
    }
    if (field_path) { 
    if(!cJSON_IsString(field_path) && !cJSON_IsNull(field_path))
    {
    goto end; //String
    }
    }

    // v1_object_reference->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_object_referenceJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_object_reference->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_object_referenceJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // v1_object_reference->_namespace
    cJSON *_namespace = cJSON_GetObjectItemCaseSensitive(v1_object_referenceJSON, "namespace");
    if (cJSON_IsNull(_namespace)) {
        _namespace = NULL;
    }
    if (_namespace) { 
    if(!cJSON_IsString(_namespace) && !cJSON_IsNull(_namespace))
    {
    goto end; //String
    }
    }

    // v1_object_reference->resource_version
    cJSON *resource_version = cJSON_GetObjectItemCaseSensitive(v1_object_referenceJSON, "resourceVersion");
    if (cJSON_IsNull(resource_version)) {
        resource_version = NULL;
    }
    if (resource_version) { 
    if(!cJSON_IsString(resource_version) && !cJSON_IsNull(resource_version))
    {
    goto end; //String
    }
    }

    // v1_object_reference->uid
    cJSON *uid = cJSON_GetObjectItemCaseSensitive(v1_object_referenceJSON, "uid");
    if (cJSON_IsNull(uid)) {
        uid = NULL;
    }
    if (uid) { 
    if(!cJSON_IsString(uid) && !cJSON_IsNull(uid))
    {
    goto end; //String
    }
    }


    if (api_version && !cJSON_IsNull(api_version)) api_version_local_str = strdup(api_version->valuestring);
    if (field_path && !cJSON_IsNull(field_path)) field_path_local_str = strdup(field_path->valuestring);
    if (kind && !cJSON_IsNull(kind)) kind_local_str = strdup(kind->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (_namespace && !cJSON_IsNull(_namespace)) _namespace_local_str = strdup(_namespace->valuestring);
    if (resource_version && !cJSON_IsNull(resource_version)) resource_version_local_str = strdup(resource_version->valuestring);
    if (uid && !cJSON_IsNull(uid)) uid_local_str = strdup(uid->valuestring);

    v1_object_reference_local_var = v1_object_reference_create_internal (
        api_version_local_str,
        field_path_local_str,
        kind_local_str,
        name_local_str,
        _namespace_local_str,
        resource_version_local_str,
        uid_local_str
        );

    if (!v1_object_reference_local_var) {
        goto end;
    }

    return v1_object_reference_local_var;
end:
    if (api_version_local_str) {
        free(api_version_local_str);
        api_version_local_str = NULL;
    }
    if (field_path_local_str) {
        free(field_path_local_str);
        field_path_local_str = NULL;
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
    if (resource_version_local_str) {
        free(resource_version_local_str);
        resource_version_local_str = NULL;
    }
    if (uid_local_str) {
        free(uid_local_str);
        uid_local_str = NULL;
    }
    return NULL;

}
