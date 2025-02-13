#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_volume_node_resources.h"



static v1_volume_node_resources_t *v1_volume_node_resources_create_internal(
    int count
    ) {
    v1_volume_node_resources_t *v1_volume_node_resources_local_var = malloc(sizeof(v1_volume_node_resources_t));
    if (!v1_volume_node_resources_local_var) {
        return NULL;
    }
    v1_volume_node_resources_local_var->count = count;

    v1_volume_node_resources_local_var->_library_owned = 1;
    return v1_volume_node_resources_local_var;
}

__attribute__((deprecated)) v1_volume_node_resources_t *v1_volume_node_resources_create(
    int count
    ) {
    return v1_volume_node_resources_create_internal (
        count
        );
}

void v1_volume_node_resources_free(v1_volume_node_resources_t *v1_volume_node_resources) {
    if(NULL == v1_volume_node_resources){
        return ;
    }
    if(v1_volume_node_resources->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_volume_node_resources_free");
        return ;
    }
    listEntry_t *listEntry;
    free(v1_volume_node_resources);
}

cJSON *v1_volume_node_resources_convertToJSON(v1_volume_node_resources_t *v1_volume_node_resources) {
    cJSON *item = cJSON_CreateObject();

    // v1_volume_node_resources->count
    if(v1_volume_node_resources->count) {
    if(cJSON_AddNumberToObject(item, "count", v1_volume_node_resources->count) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_volume_node_resources_t *v1_volume_node_resources_parseFromJSON(cJSON *v1_volume_node_resourcesJSON){

    v1_volume_node_resources_t *v1_volume_node_resources_local_var = NULL;

    // v1_volume_node_resources->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(v1_volume_node_resourcesJSON, "count");
    if (cJSON_IsNull(count)) {
        count = NULL;
    }
    if (count) { 
    if(!cJSON_IsNumber(count))
    {
    goto end; //Numeric
    }
    }


    v1_volume_node_resources_local_var = v1_volume_node_resources_create_internal (
        count ? count->valuedouble : 0
        );

    return v1_volume_node_resources_local_var;
end:
    return NULL;

}
