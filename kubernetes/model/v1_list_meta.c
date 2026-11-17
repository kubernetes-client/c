#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_list_meta.h"



static v1_list_meta_t *v1_list_meta_create_internal(
    char *_continue,
    long *remaining_item_count,
    char *resource_version,
    char *self_link,
    v1_shard_info_t *shard_info
    ) {
    v1_list_meta_t *v1_list_meta_local_var = malloc(sizeof(v1_list_meta_t));
    if (!v1_list_meta_local_var) {
        return NULL;
    }
    memset(v1_list_meta_local_var, 0, sizeof(v1_list_meta_t));
    v1_list_meta_local_var->_library_owned = 1;
    v1_list_meta_local_var->_continue = _continue;
    v1_list_meta_local_var->remaining_item_count = remaining_item_count;
    v1_list_meta_local_var->resource_version = resource_version;
    v1_list_meta_local_var->self_link = self_link;
    v1_list_meta_local_var->shard_info = shard_info;
    return v1_list_meta_local_var;
}

__attribute__((deprecated)) v1_list_meta_t *v1_list_meta_create(
    char *_continue,
    long *remaining_item_count,
    char *resource_version,
    char *self_link,
    v1_shard_info_t *shard_info
    ) {
    long *remaining_item_count_copy = NULL;
    if (remaining_item_count) {
        remaining_item_count_copy = malloc(sizeof(long));
        if (remaining_item_count_copy) *remaining_item_count_copy = *remaining_item_count;
    }
    v1_list_meta_t *result = v1_list_meta_create_internal (
        _continue,
        remaining_item_count_copy,
        resource_version,
        self_link,
        shard_info
        );
    if (!result) {
        free(remaining_item_count_copy);
    }
    return result;
}

void v1_list_meta_free(v1_list_meta_t *v1_list_meta) {
    if(NULL == v1_list_meta){
        return ;
    }
    if(v1_list_meta->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_list_meta_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_list_meta->_continue) {
        free(v1_list_meta->_continue);
        v1_list_meta->_continue = NULL;
    }
    if (v1_list_meta->remaining_item_count) {
        free(v1_list_meta->remaining_item_count);
        v1_list_meta->remaining_item_count = NULL;
    }
    if (v1_list_meta->resource_version) {
        free(v1_list_meta->resource_version);
        v1_list_meta->resource_version = NULL;
    }
    if (v1_list_meta->self_link) {
        free(v1_list_meta->self_link);
        v1_list_meta->self_link = NULL;
    }
    if (v1_list_meta->shard_info) {
        v1_shard_info_free(v1_list_meta->shard_info);
        v1_list_meta->shard_info = NULL;
    }
    free(v1_list_meta);
}

cJSON *v1_list_meta_convertToJSON(v1_list_meta_t *v1_list_meta) {
    cJSON *item = cJSON_CreateObject();

    // v1_list_meta->_continue
    if(v1_list_meta->_continue) {
    if(cJSON_AddStringToObject(item, "continue", v1_list_meta->_continue) == NULL) {
    goto fail; //String
    }
    }


    // v1_list_meta->remaining_item_count
    if(v1_list_meta->remaining_item_count) {
    if(cJSON_AddNumberToObject(item, "remainingItemCount", *v1_list_meta->remaining_item_count) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_list_meta->resource_version
    if(v1_list_meta->resource_version) {
    if(cJSON_AddStringToObject(item, "resourceVersion", v1_list_meta->resource_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_list_meta->self_link
    if(v1_list_meta->self_link) {
    if(cJSON_AddStringToObject(item, "selfLink", v1_list_meta->self_link) == NULL) {
    goto fail; //String
    }
    }


    // v1_list_meta->shard_info
    if(v1_list_meta->shard_info) {
    cJSON *shard_info_local_JSON = v1_shard_info_convertToJSON(v1_list_meta->shard_info);
    if(shard_info_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "shardInfo", shard_info_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_list_meta_t *v1_list_meta_parseFromJSON(cJSON *v1_list_metaJSON){

    v1_list_meta_t *v1_list_meta_local_var = NULL;

    char *_continue_local_str = NULL;

    // define the local variable for v1_list_meta->remaining_item_count
    long *remaining_item_count_local_var = NULL;

    char *resource_version_local_str = NULL;

    char *self_link_local_str = NULL;

    // define the local variable for v1_list_meta->shard_info
    v1_shard_info_t *shard_info_local_nonprim = NULL;

    // v1_list_meta->_continue
    cJSON *_continue = cJSON_GetObjectItemCaseSensitive(v1_list_metaJSON, "continue");
    if (cJSON_IsNull(_continue)) {
        _continue = NULL;
    }
    if (_continue) { 
    if(!cJSON_IsString(_continue) && !cJSON_IsNull(_continue))
    {
    goto end; //String
    }
    }

    // v1_list_meta->remaining_item_count
    cJSON *remaining_item_count = cJSON_GetObjectItemCaseSensitive(v1_list_metaJSON, "remainingItemCount");
    if (cJSON_IsNull(remaining_item_count)) {
        remaining_item_count = NULL;
    }
    if (remaining_item_count) { 
    if(!cJSON_IsNumber(remaining_item_count))
    {
    goto end; //Numeric
    }
    remaining_item_count_local_var = malloc(sizeof(long));
    if(!remaining_item_count_local_var)
    {
        goto end;
    }
    *remaining_item_count_local_var = remaining_item_count->valuedouble;
    }

    // v1_list_meta->resource_version
    cJSON *resource_version = cJSON_GetObjectItemCaseSensitive(v1_list_metaJSON, "resourceVersion");
    if (cJSON_IsNull(resource_version)) {
        resource_version = NULL;
    }
    if (resource_version) { 
    if(!cJSON_IsString(resource_version) && !cJSON_IsNull(resource_version))
    {
    goto end; //String
    }
    }

    // v1_list_meta->self_link
    cJSON *self_link = cJSON_GetObjectItemCaseSensitive(v1_list_metaJSON, "selfLink");
    if (cJSON_IsNull(self_link)) {
        self_link = NULL;
    }
    if (self_link) { 
    if(!cJSON_IsString(self_link) && !cJSON_IsNull(self_link))
    {
    goto end; //String
    }
    }

    // v1_list_meta->shard_info
    cJSON *shard_info = cJSON_GetObjectItemCaseSensitive(v1_list_metaJSON, "shardInfo");
    if (cJSON_IsNull(shard_info)) {
        shard_info = NULL;
    }
    if (shard_info) { 
    shard_info_local_nonprim = v1_shard_info_parseFromJSON(shard_info); //nonprimitive
    }


    if (_continue && !cJSON_IsNull(_continue)) _continue_local_str = strdup(_continue->valuestring);
    if (resource_version && !cJSON_IsNull(resource_version)) resource_version_local_str = strdup(resource_version->valuestring);
    if (self_link && !cJSON_IsNull(self_link)) self_link_local_str = strdup(self_link->valuestring);

    v1_list_meta_local_var = v1_list_meta_create_internal (
        _continue_local_str,
        remaining_item_count_local_var,
        resource_version_local_str,
        self_link_local_str,
        shard_info ? shard_info_local_nonprim : NULL
        );

    if (!v1_list_meta_local_var) {
        goto end;
    }

    return v1_list_meta_local_var;
end:
    if (_continue_local_str) {
        free(_continue_local_str);
        _continue_local_str = NULL;
    }
    if (remaining_item_count_local_var) {
        free(remaining_item_count_local_var);
        remaining_item_count_local_var = NULL;
    }
    if (resource_version_local_str) {
        free(resource_version_local_str);
        resource_version_local_str = NULL;
    }
    if (self_link_local_str) {
        free(self_link_local_str);
        self_link_local_str = NULL;
    }
    if (shard_info_local_nonprim) {
        v1_shard_info_free(shard_info_local_nonprim);
        shard_info_local_nonprim = NULL;
    }
    return NULL;

}
