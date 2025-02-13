#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_runtime_handler_features.h"



static v1_node_runtime_handler_features_t *v1_node_runtime_handler_features_create_internal(
    int recursive_read_only_mounts,
    int user_namespaces
    ) {
    v1_node_runtime_handler_features_t *v1_node_runtime_handler_features_local_var = malloc(sizeof(v1_node_runtime_handler_features_t));
    if (!v1_node_runtime_handler_features_local_var) {
        return NULL;
    }
    v1_node_runtime_handler_features_local_var->recursive_read_only_mounts = recursive_read_only_mounts;
    v1_node_runtime_handler_features_local_var->user_namespaces = user_namespaces;

    v1_node_runtime_handler_features_local_var->_library_owned = 1;
    return v1_node_runtime_handler_features_local_var;
}

__attribute__((deprecated)) v1_node_runtime_handler_features_t *v1_node_runtime_handler_features_create(
    int recursive_read_only_mounts,
    int user_namespaces
    ) {
    return v1_node_runtime_handler_features_create_internal (
        recursive_read_only_mounts,
        user_namespaces
        );
}

void v1_node_runtime_handler_features_free(v1_node_runtime_handler_features_t *v1_node_runtime_handler_features) {
    if(NULL == v1_node_runtime_handler_features){
        return ;
    }
    if(v1_node_runtime_handler_features->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_node_runtime_handler_features_free");
        return ;
    }
    listEntry_t *listEntry;
    free(v1_node_runtime_handler_features);
}

cJSON *v1_node_runtime_handler_features_convertToJSON(v1_node_runtime_handler_features_t *v1_node_runtime_handler_features) {
    cJSON *item = cJSON_CreateObject();

    // v1_node_runtime_handler_features->recursive_read_only_mounts
    if(v1_node_runtime_handler_features->recursive_read_only_mounts) {
    if(cJSON_AddBoolToObject(item, "recursiveReadOnlyMounts", v1_node_runtime_handler_features->recursive_read_only_mounts) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_node_runtime_handler_features->user_namespaces
    if(v1_node_runtime_handler_features->user_namespaces) {
    if(cJSON_AddBoolToObject(item, "userNamespaces", v1_node_runtime_handler_features->user_namespaces) == NULL) {
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

v1_node_runtime_handler_features_t *v1_node_runtime_handler_features_parseFromJSON(cJSON *v1_node_runtime_handler_featuresJSON){

    v1_node_runtime_handler_features_t *v1_node_runtime_handler_features_local_var = NULL;

    // v1_node_runtime_handler_features->recursive_read_only_mounts
    cJSON *recursive_read_only_mounts = cJSON_GetObjectItemCaseSensitive(v1_node_runtime_handler_featuresJSON, "recursiveReadOnlyMounts");
    if (cJSON_IsNull(recursive_read_only_mounts)) {
        recursive_read_only_mounts = NULL;
    }
    if (recursive_read_only_mounts) { 
    if(!cJSON_IsBool(recursive_read_only_mounts))
    {
    goto end; //Bool
    }
    }

    // v1_node_runtime_handler_features->user_namespaces
    cJSON *user_namespaces = cJSON_GetObjectItemCaseSensitive(v1_node_runtime_handler_featuresJSON, "userNamespaces");
    if (cJSON_IsNull(user_namespaces)) {
        user_namespaces = NULL;
    }
    if (user_namespaces) { 
    if(!cJSON_IsBool(user_namespaces))
    {
    goto end; //Bool
    }
    }


    v1_node_runtime_handler_features_local_var = v1_node_runtime_handler_features_create_internal (
        recursive_read_only_mounts ? recursive_read_only_mounts->valueint : 0,
        user_namespaces ? user_namespaces->valueint : 0
        );

    return v1_node_runtime_handler_features_local_var;
end:
    return NULL;

}
