#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_config_source.h"



static v1_node_config_source_t *v1_node_config_source_create_internal(
    v1_config_map_node_config_source_t *config_map
    ) {
    v1_node_config_source_t *v1_node_config_source_local_var = malloc(sizeof(v1_node_config_source_t));
    if (!v1_node_config_source_local_var) {
        return NULL;
    }
    v1_node_config_source_local_var->config_map = config_map;

    v1_node_config_source_local_var->_library_owned = 1;
    return v1_node_config_source_local_var;
}

__attribute__((deprecated)) v1_node_config_source_t *v1_node_config_source_create(
    v1_config_map_node_config_source_t *config_map
    ) {
    return v1_node_config_source_create_internal (
        config_map
        );
}

void v1_node_config_source_free(v1_node_config_source_t *v1_node_config_source) {
    if(NULL == v1_node_config_source){
        return ;
    }
    if(v1_node_config_source->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_node_config_source_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_node_config_source->config_map) {
        v1_config_map_node_config_source_free(v1_node_config_source->config_map);
        v1_node_config_source->config_map = NULL;
    }
    free(v1_node_config_source);
}

cJSON *v1_node_config_source_convertToJSON(v1_node_config_source_t *v1_node_config_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_node_config_source->config_map
    if(v1_node_config_source->config_map) {
    cJSON *config_map_local_JSON = v1_config_map_node_config_source_convertToJSON(v1_node_config_source->config_map);
    if(config_map_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "configMap", config_map_local_JSON);
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

v1_node_config_source_t *v1_node_config_source_parseFromJSON(cJSON *v1_node_config_sourceJSON){

    v1_node_config_source_t *v1_node_config_source_local_var = NULL;

    // define the local variable for v1_node_config_source->config_map
    v1_config_map_node_config_source_t *config_map_local_nonprim = NULL;

    // v1_node_config_source->config_map
    cJSON *config_map = cJSON_GetObjectItemCaseSensitive(v1_node_config_sourceJSON, "configMap");
    if (cJSON_IsNull(config_map)) {
        config_map = NULL;
    }
    if (config_map) { 
    config_map_local_nonprim = v1_config_map_node_config_source_parseFromJSON(config_map); //nonprimitive
    }


    v1_node_config_source_local_var = v1_node_config_source_create_internal (
        config_map ? config_map_local_nonprim : NULL
        );

    return v1_node_config_source_local_var;
end:
    if (config_map_local_nonprim) {
        v1_config_map_node_config_source_free(config_map_local_nonprim);
        config_map_local_nonprim = NULL;
    }
    return NULL;

}
