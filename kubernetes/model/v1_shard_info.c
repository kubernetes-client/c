#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_shard_info.h"



static v1_shard_info_t *v1_shard_info_create_internal(
    char *selector
    ) {
    v1_shard_info_t *v1_shard_info_local_var = malloc(sizeof(v1_shard_info_t));
    if (!v1_shard_info_local_var) {
        return NULL;
    }
    memset(v1_shard_info_local_var, 0, sizeof(v1_shard_info_t));
    v1_shard_info_local_var->_library_owned = 1;
    v1_shard_info_local_var->selector = selector;
    return v1_shard_info_local_var;
}

__attribute__((deprecated)) v1_shard_info_t *v1_shard_info_create(
    char *selector
    ) {
    v1_shard_info_t *result = v1_shard_info_create_internal (
        selector
        );
    if (!result) {
    }
    return result;
}

void v1_shard_info_free(v1_shard_info_t *v1_shard_info) {
    if(NULL == v1_shard_info){
        return ;
    }
    if(v1_shard_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_shard_info_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_shard_info->selector) {
        free(v1_shard_info->selector);
        v1_shard_info->selector = NULL;
    }
    free(v1_shard_info);
}

cJSON *v1_shard_info_convertToJSON(v1_shard_info_t *v1_shard_info) {
    cJSON *item = cJSON_CreateObject();

    // v1_shard_info->selector
    if (!v1_shard_info->selector) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "selector", v1_shard_info->selector) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_shard_info_t *v1_shard_info_parseFromJSON(cJSON *v1_shard_infoJSON){

    v1_shard_info_t *v1_shard_info_local_var = NULL;

    char *selector_local_str = NULL;

    // v1_shard_info->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1_shard_infoJSON, "selector");
    if (cJSON_IsNull(selector)) {
        selector = NULL;
    }
    if (!selector) {
        goto end;
    }

    
    if(!cJSON_IsString(selector))
    {
    goto end; //String
    }


    if (selector && !cJSON_IsNull(selector)) selector_local_str = strdup(selector->valuestring);

    v1_shard_info_local_var = v1_shard_info_create_internal (
        selector_local_str
        );

    if (!v1_shard_info_local_var) {
        goto end;
    }

    return v1_shard_info_local_var;
end:
    if (selector_local_str) {
        free(selector_local_str);
        selector_local_str = NULL;
    }
    return NULL;

}
