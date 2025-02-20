#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_config_map_node_config_source.h"



static v1_config_map_node_config_source_t *v1_config_map_node_config_source_create_internal(
    char *kubelet_config_key,
    char *name,
    char *_namespace,
    char *resource_version,
    char *uid
    ) {
    v1_config_map_node_config_source_t *v1_config_map_node_config_source_local_var = malloc(sizeof(v1_config_map_node_config_source_t));
    if (!v1_config_map_node_config_source_local_var) {
        return NULL;
    }
    v1_config_map_node_config_source_local_var->kubelet_config_key = kubelet_config_key;
    v1_config_map_node_config_source_local_var->name = name;
    v1_config_map_node_config_source_local_var->_namespace = _namespace;
    v1_config_map_node_config_source_local_var->resource_version = resource_version;
    v1_config_map_node_config_source_local_var->uid = uid;

    v1_config_map_node_config_source_local_var->_library_owned = 1;
    return v1_config_map_node_config_source_local_var;
}

__attribute__((deprecated)) v1_config_map_node_config_source_t *v1_config_map_node_config_source_create(
    char *kubelet_config_key,
    char *name,
    char *_namespace,
    char *resource_version,
    char *uid
    ) {
    return v1_config_map_node_config_source_create_internal (
        kubelet_config_key,
        name,
        _namespace,
        resource_version,
        uid
        );
}

void v1_config_map_node_config_source_free(v1_config_map_node_config_source_t *v1_config_map_node_config_source) {
    if(NULL == v1_config_map_node_config_source){
        return ;
    }
    if(v1_config_map_node_config_source->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_config_map_node_config_source_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_config_map_node_config_source->kubelet_config_key) {
        free(v1_config_map_node_config_source->kubelet_config_key);
        v1_config_map_node_config_source->kubelet_config_key = NULL;
    }
    if (v1_config_map_node_config_source->name) {
        free(v1_config_map_node_config_source->name);
        v1_config_map_node_config_source->name = NULL;
    }
    if (v1_config_map_node_config_source->_namespace) {
        free(v1_config_map_node_config_source->_namespace);
        v1_config_map_node_config_source->_namespace = NULL;
    }
    if (v1_config_map_node_config_source->resource_version) {
        free(v1_config_map_node_config_source->resource_version);
        v1_config_map_node_config_source->resource_version = NULL;
    }
    if (v1_config_map_node_config_source->uid) {
        free(v1_config_map_node_config_source->uid);
        v1_config_map_node_config_source->uid = NULL;
    }
    free(v1_config_map_node_config_source);
}

cJSON *v1_config_map_node_config_source_convertToJSON(v1_config_map_node_config_source_t *v1_config_map_node_config_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_config_map_node_config_source->kubelet_config_key
    if (!v1_config_map_node_config_source->kubelet_config_key) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kubeletConfigKey", v1_config_map_node_config_source->kubelet_config_key) == NULL) {
    goto fail; //String
    }


    // v1_config_map_node_config_source->name
    if (!v1_config_map_node_config_source->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_config_map_node_config_source->name) == NULL) {
    goto fail; //String
    }


    // v1_config_map_node_config_source->_namespace
    if (!v1_config_map_node_config_source->_namespace) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "namespace", v1_config_map_node_config_source->_namespace) == NULL) {
    goto fail; //String
    }


    // v1_config_map_node_config_source->resource_version
    if(v1_config_map_node_config_source->resource_version) {
    if(cJSON_AddStringToObject(item, "resourceVersion", v1_config_map_node_config_source->resource_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_config_map_node_config_source->uid
    if(v1_config_map_node_config_source->uid) {
    if(cJSON_AddStringToObject(item, "uid", v1_config_map_node_config_source->uid) == NULL) {
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

v1_config_map_node_config_source_t *v1_config_map_node_config_source_parseFromJSON(cJSON *v1_config_map_node_config_sourceJSON){

    v1_config_map_node_config_source_t *v1_config_map_node_config_source_local_var = NULL;

    // v1_config_map_node_config_source->kubelet_config_key
    cJSON *kubelet_config_key = cJSON_GetObjectItemCaseSensitive(v1_config_map_node_config_sourceJSON, "kubeletConfigKey");
    if (cJSON_IsNull(kubelet_config_key)) {
        kubelet_config_key = NULL;
    }
    if (!kubelet_config_key) {
        goto end;
    }

    
    if(!cJSON_IsString(kubelet_config_key))
    {
    goto end; //String
    }

    // v1_config_map_node_config_source->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_config_map_node_config_sourceJSON, "name");
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

    // v1_config_map_node_config_source->_namespace
    cJSON *_namespace = cJSON_GetObjectItemCaseSensitive(v1_config_map_node_config_sourceJSON, "namespace");
    if (cJSON_IsNull(_namespace)) {
        _namespace = NULL;
    }
    if (!_namespace) {
        goto end;
    }

    
    if(!cJSON_IsString(_namespace))
    {
    goto end; //String
    }

    // v1_config_map_node_config_source->resource_version
    cJSON *resource_version = cJSON_GetObjectItemCaseSensitive(v1_config_map_node_config_sourceJSON, "resourceVersion");
    if (cJSON_IsNull(resource_version)) {
        resource_version = NULL;
    }
    if (resource_version) { 
    if(!cJSON_IsString(resource_version) && !cJSON_IsNull(resource_version))
    {
    goto end; //String
    }
    }

    // v1_config_map_node_config_source->uid
    cJSON *uid = cJSON_GetObjectItemCaseSensitive(v1_config_map_node_config_sourceJSON, "uid");
    if (cJSON_IsNull(uid)) {
        uid = NULL;
    }
    if (uid) { 
    if(!cJSON_IsString(uid) && !cJSON_IsNull(uid))
    {
    goto end; //String
    }
    }


    v1_config_map_node_config_source_local_var = v1_config_map_node_config_source_create_internal (
        strdup(kubelet_config_key->valuestring),
        strdup(name->valuestring),
        strdup(_namespace->valuestring),
        resource_version && !cJSON_IsNull(resource_version) ? strdup(resource_version->valuestring) : NULL,
        uid && !cJSON_IsNull(uid) ? strdup(uid->valuestring) : NULL
        );

    return v1_config_map_node_config_source_local_var;
end:
    return NULL;

}
