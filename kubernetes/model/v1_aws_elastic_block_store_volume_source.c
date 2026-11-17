#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_aws_elastic_block_store_volume_source.h"



static v1_aws_elastic_block_store_volume_source_t *v1_aws_elastic_block_store_volume_source_create_internal(
    char *fs_type,
    int *partition,
    int *read_only,
    char *volume_id
    ) {
    v1_aws_elastic_block_store_volume_source_t *v1_aws_elastic_block_store_volume_source_local_var = malloc(sizeof(v1_aws_elastic_block_store_volume_source_t));
    if (!v1_aws_elastic_block_store_volume_source_local_var) {
        return NULL;
    }
    memset(v1_aws_elastic_block_store_volume_source_local_var, 0, sizeof(v1_aws_elastic_block_store_volume_source_t));
    v1_aws_elastic_block_store_volume_source_local_var->_library_owned = 1;
    v1_aws_elastic_block_store_volume_source_local_var->fs_type = fs_type;
    v1_aws_elastic_block_store_volume_source_local_var->partition = partition;
    v1_aws_elastic_block_store_volume_source_local_var->read_only = read_only;
    v1_aws_elastic_block_store_volume_source_local_var->volume_id = volume_id;
    return v1_aws_elastic_block_store_volume_source_local_var;
}

__attribute__((deprecated)) v1_aws_elastic_block_store_volume_source_t *v1_aws_elastic_block_store_volume_source_create(
    char *fs_type,
    int *partition,
    int *read_only,
    char *volume_id
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
    v1_aws_elastic_block_store_volume_source_t *result = v1_aws_elastic_block_store_volume_source_create_internal (
        fs_type,
        partition_copy,
        read_only_copy,
        volume_id
        );
    if (!result) {
        free(partition_copy);
        free(read_only_copy);
    }
    return result;
}

void v1_aws_elastic_block_store_volume_source_free(v1_aws_elastic_block_store_volume_source_t *v1_aws_elastic_block_store_volume_source) {
    if(NULL == v1_aws_elastic_block_store_volume_source){
        return ;
    }
    if(v1_aws_elastic_block_store_volume_source->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_aws_elastic_block_store_volume_source_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_aws_elastic_block_store_volume_source->fs_type) {
        free(v1_aws_elastic_block_store_volume_source->fs_type);
        v1_aws_elastic_block_store_volume_source->fs_type = NULL;
    }
    if (v1_aws_elastic_block_store_volume_source->partition) {
        free(v1_aws_elastic_block_store_volume_source->partition);
        v1_aws_elastic_block_store_volume_source->partition = NULL;
    }
    if (v1_aws_elastic_block_store_volume_source->read_only) {
        free(v1_aws_elastic_block_store_volume_source->read_only);
        v1_aws_elastic_block_store_volume_source->read_only = NULL;
    }
    if (v1_aws_elastic_block_store_volume_source->volume_id) {
        free(v1_aws_elastic_block_store_volume_source->volume_id);
        v1_aws_elastic_block_store_volume_source->volume_id = NULL;
    }
    free(v1_aws_elastic_block_store_volume_source);
}

cJSON *v1_aws_elastic_block_store_volume_source_convertToJSON(v1_aws_elastic_block_store_volume_source_t *v1_aws_elastic_block_store_volume_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_aws_elastic_block_store_volume_source->fs_type
    if(v1_aws_elastic_block_store_volume_source->fs_type) {
    if(cJSON_AddStringToObject(item, "fsType", v1_aws_elastic_block_store_volume_source->fs_type) == NULL) {
    goto fail; //String
    }
    }


    // v1_aws_elastic_block_store_volume_source->partition
    if(v1_aws_elastic_block_store_volume_source->partition) {
    if(cJSON_AddNumberToObject(item, "partition", *v1_aws_elastic_block_store_volume_source->partition) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_aws_elastic_block_store_volume_source->read_only
    if(v1_aws_elastic_block_store_volume_source->read_only) {
    if(cJSON_AddBoolToObject(item, "readOnly", *v1_aws_elastic_block_store_volume_source->read_only) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_aws_elastic_block_store_volume_source->volume_id
    if (!v1_aws_elastic_block_store_volume_source->volume_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "volumeID", v1_aws_elastic_block_store_volume_source->volume_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_aws_elastic_block_store_volume_source_t *v1_aws_elastic_block_store_volume_source_parseFromJSON(cJSON *v1_aws_elastic_block_store_volume_sourceJSON){

    v1_aws_elastic_block_store_volume_source_t *v1_aws_elastic_block_store_volume_source_local_var = NULL;

    char *fs_type_local_str = NULL;

    // define the local variable for v1_aws_elastic_block_store_volume_source->partition
    int *partition_local_var = NULL;

    // define the local variable for v1_aws_elastic_block_store_volume_source->read_only
    int *read_only_local_var = NULL;

    char *volume_id_local_str = NULL;

    // v1_aws_elastic_block_store_volume_source->fs_type
    cJSON *fs_type = cJSON_GetObjectItemCaseSensitive(v1_aws_elastic_block_store_volume_sourceJSON, "fsType");
    if (cJSON_IsNull(fs_type)) {
        fs_type = NULL;
    }
    if (fs_type) { 
    if(!cJSON_IsString(fs_type) && !cJSON_IsNull(fs_type))
    {
    goto end; //String
    }
    }

    // v1_aws_elastic_block_store_volume_source->partition
    cJSON *partition = cJSON_GetObjectItemCaseSensitive(v1_aws_elastic_block_store_volume_sourceJSON, "partition");
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

    // v1_aws_elastic_block_store_volume_source->read_only
    cJSON *read_only = cJSON_GetObjectItemCaseSensitive(v1_aws_elastic_block_store_volume_sourceJSON, "readOnly");
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

    // v1_aws_elastic_block_store_volume_source->volume_id
    cJSON *volume_id = cJSON_GetObjectItemCaseSensitive(v1_aws_elastic_block_store_volume_sourceJSON, "volumeID");
    if (cJSON_IsNull(volume_id)) {
        volume_id = NULL;
    }
    if (!volume_id) {
        goto end;
    }

    
    if(!cJSON_IsString(volume_id))
    {
    goto end; //String
    }


    if (fs_type && !cJSON_IsNull(fs_type)) fs_type_local_str = strdup(fs_type->valuestring);
    if (volume_id && !cJSON_IsNull(volume_id)) volume_id_local_str = strdup(volume_id->valuestring);

    v1_aws_elastic_block_store_volume_source_local_var = v1_aws_elastic_block_store_volume_source_create_internal (
        fs_type_local_str,
        partition_local_var,
        read_only_local_var,
        volume_id_local_str
        );

    if (!v1_aws_elastic_block_store_volume_source_local_var) {
        goto end;
    }

    return v1_aws_elastic_block_store_volume_source_local_var;
end:
    if (fs_type_local_str) {
        free(fs_type_local_str);
        fs_type_local_str = NULL;
    }
    if (partition_local_var) {
        free(partition_local_var);
        partition_local_var = NULL;
    }
    if (read_only_local_var) {
        free(read_only_local_var);
        read_only_local_var = NULL;
    }
    if (volume_id_local_str) {
        free(volume_id_local_str);
        volume_id_local_str = NULL;
    }
    return NULL;

}
