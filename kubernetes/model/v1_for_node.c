#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_for_node.h"



static v1_for_node_t *v1_for_node_create_internal(
    char *name
    ) {
    v1_for_node_t *v1_for_node_local_var = malloc(sizeof(v1_for_node_t));
    if (!v1_for_node_local_var) {
        return NULL;
    }
    v1_for_node_local_var->name = name;

    v1_for_node_local_var->_library_owned = 1;
    return v1_for_node_local_var;
}

__attribute__((deprecated)) v1_for_node_t *v1_for_node_create(
    char *name
    ) {
    return v1_for_node_create_internal (
        name
        );
}

void v1_for_node_free(v1_for_node_t *v1_for_node) {
    if(NULL == v1_for_node){
        return ;
    }
    if(v1_for_node->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_for_node_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_for_node->name) {
        free(v1_for_node->name);
        v1_for_node->name = NULL;
    }
    free(v1_for_node);
}

cJSON *v1_for_node_convertToJSON(v1_for_node_t *v1_for_node) {
    cJSON *item = cJSON_CreateObject();

    // v1_for_node->name
    if (!v1_for_node->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_for_node->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_for_node_t *v1_for_node_parseFromJSON(cJSON *v1_for_nodeJSON){

    v1_for_node_t *v1_for_node_local_var = NULL;

    // v1_for_node->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_for_nodeJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    v1_for_node_local_var = v1_for_node_create_internal (
        strdup(name->valuestring)
        );

    return v1_for_node_local_var;
end:
    return NULL;

}
