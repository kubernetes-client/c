#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_azure_file_persistent_volume_source.h"



static v1_azure_file_persistent_volume_source_t *v1_azure_file_persistent_volume_source_create_internal(
    int *read_only,
    char *secret_name,
    char *secret_namespace,
    char *share_name
    ) {
    v1_azure_file_persistent_volume_source_t *v1_azure_file_persistent_volume_source_local_var = malloc(sizeof(v1_azure_file_persistent_volume_source_t));
    if (!v1_azure_file_persistent_volume_source_local_var) {
        return NULL;
    }
    memset(v1_azure_file_persistent_volume_source_local_var, 0, sizeof(v1_azure_file_persistent_volume_source_t));
    v1_azure_file_persistent_volume_source_local_var->_library_owned = 1;
    v1_azure_file_persistent_volume_source_local_var->read_only = read_only;
    v1_azure_file_persistent_volume_source_local_var->secret_name = secret_name;
    v1_azure_file_persistent_volume_source_local_var->secret_namespace = secret_namespace;
    v1_azure_file_persistent_volume_source_local_var->share_name = share_name;
    return v1_azure_file_persistent_volume_source_local_var;
}

__attribute__((deprecated)) v1_azure_file_persistent_volume_source_t *v1_azure_file_persistent_volume_source_create(
    int *read_only,
    char *secret_name,
    char *secret_namespace,
    char *share_name
    ) {
    int *read_only_copy = NULL;
    if (read_only) {
        read_only_copy = malloc(sizeof(int));
        if (read_only_copy) *read_only_copy = *read_only;
    }
    v1_azure_file_persistent_volume_source_t *result = v1_azure_file_persistent_volume_source_create_internal (
        read_only_copy,
        secret_name,
        secret_namespace,
        share_name
        );
    if (!result) {
        free(read_only_copy);
    }
    return result;
}

void v1_azure_file_persistent_volume_source_free(v1_azure_file_persistent_volume_source_t *v1_azure_file_persistent_volume_source) {
    if(NULL == v1_azure_file_persistent_volume_source){
        return ;
    }
    if(v1_azure_file_persistent_volume_source->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_azure_file_persistent_volume_source_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_azure_file_persistent_volume_source->read_only) {
        free(v1_azure_file_persistent_volume_source->read_only);
        v1_azure_file_persistent_volume_source->read_only = NULL;
    }
    if (v1_azure_file_persistent_volume_source->secret_name) {
        free(v1_azure_file_persistent_volume_source->secret_name);
        v1_azure_file_persistent_volume_source->secret_name = NULL;
    }
    if (v1_azure_file_persistent_volume_source->secret_namespace) {
        free(v1_azure_file_persistent_volume_source->secret_namespace);
        v1_azure_file_persistent_volume_source->secret_namespace = NULL;
    }
    if (v1_azure_file_persistent_volume_source->share_name) {
        free(v1_azure_file_persistent_volume_source->share_name);
        v1_azure_file_persistent_volume_source->share_name = NULL;
    }
    free(v1_azure_file_persistent_volume_source);
}

cJSON *v1_azure_file_persistent_volume_source_convertToJSON(v1_azure_file_persistent_volume_source_t *v1_azure_file_persistent_volume_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_azure_file_persistent_volume_source->read_only
    if(v1_azure_file_persistent_volume_source->read_only) {
    if(cJSON_AddBoolToObject(item, "readOnly", *v1_azure_file_persistent_volume_source->read_only) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_azure_file_persistent_volume_source->secret_name
    if (!v1_azure_file_persistent_volume_source->secret_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "secretName", v1_azure_file_persistent_volume_source->secret_name) == NULL) {
    goto fail; //String
    }


    // v1_azure_file_persistent_volume_source->secret_namespace
    if(v1_azure_file_persistent_volume_source->secret_namespace) {
    if(cJSON_AddStringToObject(item, "secretNamespace", v1_azure_file_persistent_volume_source->secret_namespace) == NULL) {
    goto fail; //String
    }
    }


    // v1_azure_file_persistent_volume_source->share_name
    if (!v1_azure_file_persistent_volume_source->share_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "shareName", v1_azure_file_persistent_volume_source->share_name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_azure_file_persistent_volume_source_t *v1_azure_file_persistent_volume_source_parseFromJSON(cJSON *v1_azure_file_persistent_volume_sourceJSON){

    v1_azure_file_persistent_volume_source_t *v1_azure_file_persistent_volume_source_local_var = NULL;

    // define the local variable for v1_azure_file_persistent_volume_source->read_only
    int *read_only_local_var = NULL;

    char *secret_name_local_str = NULL;

    char *secret_namespace_local_str = NULL;

    char *share_name_local_str = NULL;

    // v1_azure_file_persistent_volume_source->read_only
    cJSON *read_only = cJSON_GetObjectItemCaseSensitive(v1_azure_file_persistent_volume_sourceJSON, "readOnly");
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

    // v1_azure_file_persistent_volume_source->secret_name
    cJSON *secret_name = cJSON_GetObjectItemCaseSensitive(v1_azure_file_persistent_volume_sourceJSON, "secretName");
    if (cJSON_IsNull(secret_name)) {
        secret_name = NULL;
    }
    if (!secret_name) {
        goto end;
    }

    
    if(!cJSON_IsString(secret_name))
    {
    goto end; //String
    }

    // v1_azure_file_persistent_volume_source->secret_namespace
    cJSON *secret_namespace = cJSON_GetObjectItemCaseSensitive(v1_azure_file_persistent_volume_sourceJSON, "secretNamespace");
    if (cJSON_IsNull(secret_namespace)) {
        secret_namespace = NULL;
    }
    if (secret_namespace) { 
    if(!cJSON_IsString(secret_namespace) && !cJSON_IsNull(secret_namespace))
    {
    goto end; //String
    }
    }

    // v1_azure_file_persistent_volume_source->share_name
    cJSON *share_name = cJSON_GetObjectItemCaseSensitive(v1_azure_file_persistent_volume_sourceJSON, "shareName");
    if (cJSON_IsNull(share_name)) {
        share_name = NULL;
    }
    if (!share_name) {
        goto end;
    }

    
    if(!cJSON_IsString(share_name))
    {
    goto end; //String
    }


    if (secret_name && !cJSON_IsNull(secret_name)) secret_name_local_str = strdup(secret_name->valuestring);
    if (secret_namespace && !cJSON_IsNull(secret_namespace)) secret_namespace_local_str = strdup(secret_namespace->valuestring);
    if (share_name && !cJSON_IsNull(share_name)) share_name_local_str = strdup(share_name->valuestring);

    v1_azure_file_persistent_volume_source_local_var = v1_azure_file_persistent_volume_source_create_internal (
        read_only_local_var,
        secret_name_local_str,
        secret_namespace_local_str,
        share_name_local_str
        );

    if (!v1_azure_file_persistent_volume_source_local_var) {
        goto end;
    }

    return v1_azure_file_persistent_volume_source_local_var;
end:
    if (read_only_local_var) {
        free(read_only_local_var);
        read_only_local_var = NULL;
    }
    if (secret_name_local_str) {
        free(secret_name_local_str);
        secret_name_local_str = NULL;
    }
    if (secret_namespace_local_str) {
        free(secret_namespace_local_str);
        secret_namespace_local_str = NULL;
    }
    if (share_name_local_str) {
        free(share_name_local_str);
        share_name_local_str = NULL;
    }
    return NULL;

}
