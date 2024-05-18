#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_runtime_handler_features.h"



v1_node_runtime_handler_features_t *v1_node_runtime_handler_features_create(
    int recursive_read_only_mounts
    ) {
    v1_node_runtime_handler_features_t *v1_node_runtime_handler_features_local_var = malloc(sizeof(v1_node_runtime_handler_features_t));
    if (!v1_node_runtime_handler_features_local_var) {
        return NULL;
    }
    v1_node_runtime_handler_features_local_var->recursive_read_only_mounts = recursive_read_only_mounts;

    return v1_node_runtime_handler_features_local_var;
}


void v1_node_runtime_handler_features_free(v1_node_runtime_handler_features_t *v1_node_runtime_handler_features) {
    if(NULL == v1_node_runtime_handler_features){
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
    if (recursive_read_only_mounts) { 
    if(!cJSON_IsBool(recursive_read_only_mounts))
    {
    goto end; //Bool
    }
    }


    v1_node_runtime_handler_features_local_var = v1_node_runtime_handler_features_create (
        recursive_read_only_mounts ? recursive_read_only_mounts->valueint : 0
        );

    return v1_node_runtime_handler_features_local_var;
end:
    return NULL;

}
