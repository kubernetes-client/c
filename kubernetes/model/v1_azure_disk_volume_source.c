#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_azure_disk_volume_source.h"



static v1_azure_disk_volume_source_t *v1_azure_disk_volume_source_create_internal(
    char *caching_mode,
    char *disk_name,
    char *disk_uri,
    char *fs_type,
    char *kind,
    int *read_only
    ) {
    v1_azure_disk_volume_source_t *v1_azure_disk_volume_source_local_var = malloc(sizeof(v1_azure_disk_volume_source_t));
    if (!v1_azure_disk_volume_source_local_var) {
        return NULL;
    }
    memset(v1_azure_disk_volume_source_local_var, 0, sizeof(v1_azure_disk_volume_source_t));
    v1_azure_disk_volume_source_local_var->_library_owned = 1;
    v1_azure_disk_volume_source_local_var->caching_mode = caching_mode;
    v1_azure_disk_volume_source_local_var->disk_name = disk_name;
    v1_azure_disk_volume_source_local_var->disk_uri = disk_uri;
    v1_azure_disk_volume_source_local_var->fs_type = fs_type;
    v1_azure_disk_volume_source_local_var->kind = kind;
    v1_azure_disk_volume_source_local_var->read_only = read_only;
    return v1_azure_disk_volume_source_local_var;
}

__attribute__((deprecated)) v1_azure_disk_volume_source_t *v1_azure_disk_volume_source_create(
    char *caching_mode,
    char *disk_name,
    char *disk_uri,
    char *fs_type,
    char *kind,
    int *read_only
    ) {
    int *read_only_copy = NULL;
    if (read_only) {
        read_only_copy = malloc(sizeof(int));
        if (read_only_copy) *read_only_copy = *read_only;
    }
    v1_azure_disk_volume_source_t *result = v1_azure_disk_volume_source_create_internal (
        caching_mode,
        disk_name,
        disk_uri,
        fs_type,
        kind,
        read_only_copy
        );
    if (!result) {
        free(read_only_copy);
    }
    return result;
}

void v1_azure_disk_volume_source_free(v1_azure_disk_volume_source_t *v1_azure_disk_volume_source) {
    if(NULL == v1_azure_disk_volume_source){
        return ;
    }
    if(v1_azure_disk_volume_source->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_azure_disk_volume_source_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_azure_disk_volume_source->caching_mode) {
        free(v1_azure_disk_volume_source->caching_mode);
        v1_azure_disk_volume_source->caching_mode = NULL;
    }
    if (v1_azure_disk_volume_source->disk_name) {
        free(v1_azure_disk_volume_source->disk_name);
        v1_azure_disk_volume_source->disk_name = NULL;
    }
    if (v1_azure_disk_volume_source->disk_uri) {
        free(v1_azure_disk_volume_source->disk_uri);
        v1_azure_disk_volume_source->disk_uri = NULL;
    }
    if (v1_azure_disk_volume_source->fs_type) {
        free(v1_azure_disk_volume_source->fs_type);
        v1_azure_disk_volume_source->fs_type = NULL;
    }
    if (v1_azure_disk_volume_source->kind) {
        free(v1_azure_disk_volume_source->kind);
        v1_azure_disk_volume_source->kind = NULL;
    }
    if (v1_azure_disk_volume_source->read_only) {
        free(v1_azure_disk_volume_source->read_only);
        v1_azure_disk_volume_source->read_only = NULL;
    }
    free(v1_azure_disk_volume_source);
}

cJSON *v1_azure_disk_volume_source_convertToJSON(v1_azure_disk_volume_source_t *v1_azure_disk_volume_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_azure_disk_volume_source->caching_mode
    if(v1_azure_disk_volume_source->caching_mode) {
    if(cJSON_AddStringToObject(item, "cachingMode", v1_azure_disk_volume_source->caching_mode) == NULL) {
    goto fail; //String
    }
    }


    // v1_azure_disk_volume_source->disk_name
    if (!v1_azure_disk_volume_source->disk_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "diskName", v1_azure_disk_volume_source->disk_name) == NULL) {
    goto fail; //String
    }


    // v1_azure_disk_volume_source->disk_uri
    if (!v1_azure_disk_volume_source->disk_uri) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "diskURI", v1_azure_disk_volume_source->disk_uri) == NULL) {
    goto fail; //String
    }


    // v1_azure_disk_volume_source->fs_type
    if(v1_azure_disk_volume_source->fs_type) {
    if(cJSON_AddStringToObject(item, "fsType", v1_azure_disk_volume_source->fs_type) == NULL) {
    goto fail; //String
    }
    }


    // v1_azure_disk_volume_source->kind
    if(v1_azure_disk_volume_source->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_azure_disk_volume_source->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_azure_disk_volume_source->read_only
    if(v1_azure_disk_volume_source->read_only) {
    if(cJSON_AddBoolToObject(item, "readOnly", *v1_azure_disk_volume_source->read_only) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_azure_disk_volume_source_t *v1_azure_disk_volume_source_parseFromJSON(cJSON *v1_azure_disk_volume_sourceJSON){

    v1_azure_disk_volume_source_t *v1_azure_disk_volume_source_local_var = NULL;

    char *caching_mode_local_str = NULL;

    char *disk_name_local_str = NULL;

    char *disk_uri_local_str = NULL;

    char *fs_type_local_str = NULL;

    char *kind_local_str = NULL;

    // define the local variable for v1_azure_disk_volume_source->read_only
    int *read_only_local_var = NULL;

    // v1_azure_disk_volume_source->caching_mode
    cJSON *caching_mode = cJSON_GetObjectItemCaseSensitive(v1_azure_disk_volume_sourceJSON, "cachingMode");
    if (cJSON_IsNull(caching_mode)) {
        caching_mode = NULL;
    }
    if (caching_mode) { 
    if(!cJSON_IsString(caching_mode) && !cJSON_IsNull(caching_mode))
    {
    goto end; //String
    }
    }

    // v1_azure_disk_volume_source->disk_name
    cJSON *disk_name = cJSON_GetObjectItemCaseSensitive(v1_azure_disk_volume_sourceJSON, "diskName");
    if (cJSON_IsNull(disk_name)) {
        disk_name = NULL;
    }
    if (!disk_name) {
        goto end;
    }

    
    if(!cJSON_IsString(disk_name))
    {
    goto end; //String
    }

    // v1_azure_disk_volume_source->disk_uri
    cJSON *disk_uri = cJSON_GetObjectItemCaseSensitive(v1_azure_disk_volume_sourceJSON, "diskURI");
    if (cJSON_IsNull(disk_uri)) {
        disk_uri = NULL;
    }
    if (!disk_uri) {
        goto end;
    }

    
    if(!cJSON_IsString(disk_uri))
    {
    goto end; //String
    }

    // v1_azure_disk_volume_source->fs_type
    cJSON *fs_type = cJSON_GetObjectItemCaseSensitive(v1_azure_disk_volume_sourceJSON, "fsType");
    if (cJSON_IsNull(fs_type)) {
        fs_type = NULL;
    }
    if (fs_type) { 
    if(!cJSON_IsString(fs_type) && !cJSON_IsNull(fs_type))
    {
    goto end; //String
    }
    }

    // v1_azure_disk_volume_source->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_azure_disk_volume_sourceJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_azure_disk_volume_source->read_only
    cJSON *read_only = cJSON_GetObjectItemCaseSensitive(v1_azure_disk_volume_sourceJSON, "readOnly");
    if (cJSON_IsNull(read_only)) {
        read_only = NULL;
    }
    if (read_only) { 
    if(!cJSON_IsBool(read_only))
    {
    goto end; //Bool
    }
    read_only_local_var = malloc(sizeof(int));
    if(!read_only_local_var)
    {
        goto end;
    }
    *read_only_local_var = read_only->valueint;
    }


    if (caching_mode && !cJSON_IsNull(caching_mode)) caching_mode_local_str = strdup(caching_mode->valuestring);
    if (disk_name && !cJSON_IsNull(disk_name)) disk_name_local_str = strdup(disk_name->valuestring);
    if (disk_uri && !cJSON_IsNull(disk_uri)) disk_uri_local_str = strdup(disk_uri->valuestring);
    if (fs_type && !cJSON_IsNull(fs_type)) fs_type_local_str = strdup(fs_type->valuestring);
    if (kind && !cJSON_IsNull(kind)) kind_local_str = strdup(kind->valuestring);

    v1_azure_disk_volume_source_local_var = v1_azure_disk_volume_source_create_internal (
        caching_mode_local_str,
        disk_name_local_str,
        disk_uri_local_str,
        fs_type_local_str,
        kind_local_str,
        read_only_local_var
        );

    if (!v1_azure_disk_volume_source_local_var) {
        goto end;
    }

    return v1_azure_disk_volume_source_local_var;
end:
    if (caching_mode_local_str) {
        free(caching_mode_local_str);
        caching_mode_local_str = NULL;
    }
    if (disk_name_local_str) {
        free(disk_name_local_str);
        disk_name_local_str = NULL;
    }
    if (disk_uri_local_str) {
        free(disk_uri_local_str);
        disk_uri_local_str = NULL;
    }
    if (fs_type_local_str) {
        free(fs_type_local_str);
        fs_type_local_str = NULL;
    }
    if (kind_local_str) {
        free(kind_local_str);
        kind_local_str = NULL;
    }
    if (read_only_local_var) {
        free(read_only_local_var);
        read_only_local_var = NULL;
    }
    return NULL;

}
