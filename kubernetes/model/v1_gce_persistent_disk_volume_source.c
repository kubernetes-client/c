#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_gce_persistent_disk_volume_source.h"



static v1_gce_persistent_disk_volume_source_t *v1_gce_persistent_disk_volume_source_create_internal(
    char *fs_type,
    int *partition,
    char *pd_name,
    int *read_only
    ) {
    v1_gce_persistent_disk_volume_source_t *v1_gce_persistent_disk_volume_source_local_var = malloc(sizeof(v1_gce_persistent_disk_volume_source_t));
    if (!v1_gce_persistent_disk_volume_source_local_var) {
        return NULL;
    }
    memset(v1_gce_persistent_disk_volume_source_local_var, 0, sizeof(v1_gce_persistent_disk_volume_source_t));
    v1_gce_persistent_disk_volume_source_local_var->_library_owned = 1;
    v1_gce_persistent_disk_volume_source_local_var->fs_type = fs_type;
    v1_gce_persistent_disk_volume_source_local_var->partition = partition;
    v1_gce_persistent_disk_volume_source_local_var->pd_name = pd_name;
    v1_gce_persistent_disk_volume_source_local_var->read_only = read_only;
    return v1_gce_persistent_disk_volume_source_local_var;
}

__attribute__((deprecated)) v1_gce_persistent_disk_volume_source_t *v1_gce_persistent_disk_volume_source_create(
    char *fs_type,
    int *partition,
    char *pd_name,
    int *read_only
    ) {
    int *partition_copy = NULL;
    if (partition) {
        partition_copy = malloc(sizeof(int));
        if (partition_copy) *partition_copy = *partition;
    }
    int *read_only_copy = NULL;
    if (read_only) {
        read_only_copy = malloc(sizeof(int));
        if (read_only_copy) *read_only_copy = *read_only;
    }
    v1_gce_persistent_disk_volume_source_t *result = v1_gce_persistent_disk_volume_source_create_internal (
        fs_type,
        partition_copy,
        pd_name,
        read_only_copy
        );
    if (!result) {
        free(partition_copy);
        free(read_only_copy);
    }
    return result;
}

void v1_gce_persistent_disk_volume_source_free(v1_gce_persistent_disk_volume_source_t *v1_gce_persistent_disk_volume_source) {
    if(NULL == v1_gce_persistent_disk_volume_source){
        return ;
    }
    if(v1_gce_persistent_disk_volume_source->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_gce_persistent_disk_volume_source_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_gce_persistent_disk_volume_source->fs_type) {
        free(v1_gce_persistent_disk_volume_source->fs_type);
        v1_gce_persistent_disk_volume_source->fs_type = NULL;
    }
    if (v1_gce_persistent_disk_volume_source->partition) {
        free(v1_gce_persistent_disk_volume_source->partition);
        v1_gce_persistent_disk_volume_source->partition = NULL;
    }
    if (v1_gce_persistent_disk_volume_source->pd_name) {
        free(v1_gce_persistent_disk_volume_source->pd_name);
        v1_gce_persistent_disk_volume_source->pd_name = NULL;
    }
    if (v1_gce_persistent_disk_volume_source->read_only) {
        free(v1_gce_persistent_disk_volume_source->read_only);
        v1_gce_persistent_disk_volume_source->read_only = NULL;
    }
    free(v1_gce_persistent_disk_volume_source);
}

cJSON *v1_gce_persistent_disk_volume_source_convertToJSON(v1_gce_persistent_disk_volume_source_t *v1_gce_persistent_disk_volume_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_gce_persistent_disk_volume_source->fs_type
    if(v1_gce_persistent_disk_volume_source->fs_type) {
    if(cJSON_AddStringToObject(item, "fsType", v1_gce_persistent_disk_volume_source->fs_type) == NULL) {
    goto fail; //String
    }
    }


    // v1_gce_persistent_disk_volume_source->partition
    if(v1_gce_persistent_disk_volume_source->partition) {
    if(cJSON_AddNumberToObject(item, "partition", *v1_gce_persistent_disk_volume_source->partition) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_gce_persistent_disk_volume_source->pd_name
    if (!v1_gce_persistent_disk_volume_source->pd_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "pdName", v1_gce_persistent_disk_volume_source->pd_name) == NULL) {
    goto fail; //String
    }


    // v1_gce_persistent_disk_volume_source->read_only
    if(v1_gce_persistent_disk_volume_source->read_only) {
    if(cJSON_AddBoolToObject(item, "readOnly", *v1_gce_persistent_disk_volume_source->read_only) == NULL) {
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

v1_gce_persistent_disk_volume_source_t *v1_gce_persistent_disk_volume_source_parseFromJSON(cJSON *v1_gce_persistent_disk_volume_sourceJSON){

    v1_gce_persistent_disk_volume_source_t *v1_gce_persistent_disk_volume_source_local_var = NULL;

    char *fs_type_local_str = NULL;

    // define the local variable for v1_gce_persistent_disk_volume_source->partition
    int *partition_local_var = NULL;

    char *pd_name_local_str = NULL;

    // define the local variable for v1_gce_persistent_disk_volume_source->read_only
    int *read_only_local_var = NULL;

    // v1_gce_persistent_disk_volume_source->fs_type
    cJSON *fs_type = cJSON_GetObjectItemCaseSensitive(v1_gce_persistent_disk_volume_sourceJSON, "fsType");
    if (cJSON_IsNull(fs_type)) {
        fs_type = NULL;
    }
    if (fs_type) { 
    if(!cJSON_IsString(fs_type) && !cJSON_IsNull(fs_type))
    {
    goto end; //String
    }
    }

    // v1_gce_persistent_disk_volume_source->partition
    cJSON *partition = cJSON_GetObjectItemCaseSensitive(v1_gce_persistent_disk_volume_sourceJSON, "partition");
    if (cJSON_IsNull(partition)) {
        partition = NULL;
    }
    if (partition) { 
    if(!cJSON_IsNumber(partition))
    {
    goto end; //Numeric
    }
    partition_local_var = malloc(sizeof(int));
    if(!partition_local_var)
    {
        goto end;
    }
    *partition_local_var = partition->valuedouble;
    }

    // v1_gce_persistent_disk_volume_source->pd_name
    cJSON *pd_name = cJSON_GetObjectItemCaseSensitive(v1_gce_persistent_disk_volume_sourceJSON, "pdName");
    if (cJSON_IsNull(pd_name)) {
        pd_name = NULL;
    }
    if (!pd_name) {
        goto end;
    }

    
    if(!cJSON_IsString(pd_name))
    {
    goto end; //String
    }

    // v1_gce_persistent_disk_volume_source->read_only
    cJSON *read_only = cJSON_GetObjectItemCaseSensitive(v1_gce_persistent_disk_volume_sourceJSON, "readOnly");
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


    if (fs_type && !cJSON_IsNull(fs_type)) fs_type_local_str = strdup(fs_type->valuestring);
    if (pd_name && !cJSON_IsNull(pd_name)) pd_name_local_str = strdup(pd_name->valuestring);

    v1_gce_persistent_disk_volume_source_local_var = v1_gce_persistent_disk_volume_source_create_internal (
        fs_type_local_str,
        partition_local_var,
        pd_name_local_str,
        read_only_local_var
        );

    if (!v1_gce_persistent_disk_volume_source_local_var) {
        goto end;
    }

    return v1_gce_persistent_disk_volume_source_local_var;
end:
    if (fs_type_local_str) {
        free(fs_type_local_str);
        fs_type_local_str = NULL;
    }
    if (partition_local_var) {
        free(partition_local_var);
        partition_local_var = NULL;
    }
    if (pd_name_local_str) {
        free(pd_name_local_str);
        pd_name_local_str = NULL;
    }
    if (read_only_local_var) {
        free(read_only_local_var);
        read_only_local_var = NULL;
    }
    return NULL;

}
