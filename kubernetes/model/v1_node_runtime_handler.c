#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_runtime_handler.h"



v1_node_runtime_handler_t *v1_node_runtime_handler_create(
    v1_node_runtime_handler_features_t *features,
    char *name
    ) {
    v1_node_runtime_handler_t *v1_node_runtime_handler_local_var = malloc(sizeof(v1_node_runtime_handler_t));
    if (!v1_node_runtime_handler_local_var) {
        return NULL;
    }
    v1_node_runtime_handler_local_var->features = features;
    v1_node_runtime_handler_local_var->name = name;

    return v1_node_runtime_handler_local_var;
}


void v1_node_runtime_handler_free(v1_node_runtime_handler_t *v1_node_runtime_handler) {
    if(NULL == v1_node_runtime_handler){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_node_runtime_handler->features) {
        v1_node_runtime_handler_features_free(v1_node_runtime_handler->features);
        v1_node_runtime_handler->features = NULL;
    }
    if (v1_node_runtime_handler->name) {
        free(v1_node_runtime_handler->name);
        v1_node_runtime_handler->name = NULL;
    }
    free(v1_node_runtime_handler);
}

cJSON *v1_node_runtime_handler_convertToJSON(v1_node_runtime_handler_t *v1_node_runtime_handler) {
    cJSON *item = cJSON_CreateObject();

    // v1_node_runtime_handler->features
    if(v1_node_runtime_handler->features) {
    cJSON *features_local_JSON = v1_node_runtime_handler_features_convertToJSON(v1_node_runtime_handler->features);
    if(features_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "features", features_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_node_runtime_handler->name
    if(v1_node_runtime_handler->name) {
    if(cJSON_AddStringToObject(item, "name", v1_node_runtime_handler->name) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_node_runtime_handler_t *v1_node_runtime_handler_parseFromJSON(cJSON *v1_node_runtime_handlerJSON){

    v1_node_runtime_handler_t *v1_node_runtime_handler_local_var = NULL;

    // define the local variable for v1_node_runtime_handler->features
    v1_node_runtime_handler_features_t *features_local_nonprim = NULL;

    // v1_node_runtime_handler->features
    cJSON *features = cJSON_GetObjectItemCaseSensitive(v1_node_runtime_handlerJSON, "features");
    if (features) { 
    features_local_nonprim = v1_node_runtime_handler_features_parseFromJSON(features); //nonprimitive
    }

    // v1_node_runtime_handler->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_node_runtime_handlerJSON, "name");
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }


    v1_node_runtime_handler_local_var = v1_node_runtime_handler_create (
        features ? features_local_nonprim : NULL,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL
        );

    return v1_node_runtime_handler_local_var;
end:
    if (features_local_nonprim) {
        v1_node_runtime_handler_features_free(features_local_nonprim);
        features_local_nonprim = NULL;
    }
    return NULL;

}
