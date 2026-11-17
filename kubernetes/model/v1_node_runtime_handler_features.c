#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_runtime_handler_features.h"



static v1_node_runtime_handler_features_t *v1_node_runtime_handler_features_create_internal(
    int *recursive_read_only_mounts,
    int *user_namespaces
    ) {
    v1_node_runtime_handler_features_t *v1_node_runtime_handler_features_local_var = malloc(sizeof(v1_node_runtime_handler_features_t));
    if (!v1_node_runtime_handler_features_local_var) {
        return NULL;
    }
    memset(v1_node_runtime_handler_features_local_var, 0, sizeof(v1_node_runtime_handler_features_t));
    v1_node_runtime_handler_features_local_var->_library_owned = 1;
    v1_node_runtime_handler_features_local_var->recursive_read_only_mounts = recursive_read_only_mounts;
    v1_node_runtime_handler_features_local_var->user_namespaces = user_namespaces;
    return v1_node_runtime_handler_features_local_var;
}

__attribute__((deprecated)) v1_node_runtime_handler_features_t *v1_node_runtime_handler_features_create(
    int *recursive_read_only_mounts,
    int *user_namespaces
    ) {
    int *recursive_read_only_mounts_copy = NULL;
    if (recursive_read_only_mounts) {
        recursive_read_only_mounts_copy = malloc(sizeof(int));
        if (recursive_read_only_mounts_copy) *recursive_read_only_mounts_copy = *recursive_read_only_mounts;
    }
    int *user_namespaces_copy = NULL;
    if (user_namespaces) {
        user_namespaces_copy = malloc(sizeof(int));
        if (user_namespaces_copy) *user_namespaces_copy = *user_namespaces;
    }
    v1_node_runtime_handler_features_t *result = v1_node_runtime_handler_features_create_internal (
        recursive_read_only_mounts_copy,
        user_namespaces_copy
        );
    if (!result) {
        free(recursive_read_only_mounts_copy);
        free(user_namespaces_copy);
    }
    return result;
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
    if (v1_node_runtime_handler_features->recursive_read_only_mounts) {
        free(v1_node_runtime_handler_features->recursive_read_only_mounts);
        v1_node_runtime_handler_features->recursive_read_only_mounts = NULL;
    }
    if (v1_node_runtime_handler_features->user_namespaces) {
        free(v1_node_runtime_handler_features->user_namespaces);
        v1_node_runtime_handler_features->user_namespaces = NULL;
    }
    free(v1_node_runtime_handler_features);
}

cJSON *v1_node_runtime_handler_features_convertToJSON(v1_node_runtime_handler_features_t *v1_node_runtime_handler_features) {
    cJSON *item = cJSON_CreateObject();

    // v1_node_runtime_handler_features->recursive_read_only_mounts
    if(v1_node_runtime_handler_features->recursive_read_only_mounts) {
    if(cJSON_AddBoolToObject(item, "recursiveReadOnlyMounts", *v1_node_runtime_handler_features->recursive_read_only_mounts) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_node_runtime_handler_features->user_namespaces
    if(v1_node_runtime_handler_features->user_namespaces) {
    if(cJSON_AddBoolToObject(item, "userNamespaces", *v1_node_runtime_handler_features->user_namespaces) == NULL) {
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

    // define the local variable for v1_node_runtime_handler_features->recursive_read_only_mounts
    int *recursive_read_only_mounts_local_var = NULL;

    // define the local variable for v1_node_runtime_handler_features->user_namespaces
    int *user_namespaces_local_var = NULL;

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
    recursive_read_only_mounts_local_var = malloc(sizeof(int));
    if(!recursive_read_only_mounts_local_var)
    {
        goto end;
    }
    *recursive_read_only_mounts_local_var = recursive_read_only_mounts->valueint;
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
    user_namespaces_local_var = malloc(sizeof(int));
    if(!user_namespaces_local_var)
    {
        goto end;
    }
    *user_namespaces_local_var = user_namespaces->valueint;
    }



    v1_node_runtime_handler_features_local_var = v1_node_runtime_handler_features_create_internal (
        recursive_read_only_mounts_local_var,
        user_namespaces_local_var
        );

    if (!v1_node_runtime_handler_features_local_var) {
        goto end;
    }

    return v1_node_runtime_handler_features_local_var;
end:
    if (recursive_read_only_mounts_local_var) {
        free(recursive_read_only_mounts_local_var);
        recursive_read_only_mounts_local_var = NULL;
    }
    if (user_namespaces_local_var) {
        free(user_namespaces_local_var);
        user_namespaces_local_var = NULL;
    }
    return NULL;

}
