#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_volume_node_resources.h"



v1beta1_volume_node_resources_t *v1beta1_volume_node_resources_create(
    int count
    ) {
    v1beta1_volume_node_resources_t *v1beta1_volume_node_resources_local_var = malloc(sizeof(v1beta1_volume_node_resources_t));
    if (!v1beta1_volume_node_resources_local_var) {
        return NULL;
    }
    v1beta1_volume_node_resources_local_var->count = count;

    return v1beta1_volume_node_resources_local_var;
}


void v1beta1_volume_node_resources_free(v1beta1_volume_node_resources_t *v1beta1_volume_node_resources) {
    if(NULL == v1beta1_volume_node_resources){
        return ;
    }
    listEntry_t *listEntry;
    free(v1beta1_volume_node_resources);
}

cJSON *v1beta1_volume_node_resources_convertToJSON(v1beta1_volume_node_resources_t *v1beta1_volume_node_resources) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_volume_node_resources->count
    if(v1beta1_volume_node_resources->count) { 
    if(cJSON_AddNumberToObject(item, "count", v1beta1_volume_node_resources->count) == NULL) {
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

v1beta1_volume_node_resources_t *v1beta1_volume_node_resources_parseFromJSON(cJSON *v1beta1_volume_node_resourcesJSON){

    v1beta1_volume_node_resources_t *v1beta1_volume_node_resources_local_var = NULL;

    // v1beta1_volume_node_resources->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(v1beta1_volume_node_resourcesJSON, "count");
    if (count) { 
    if(!cJSON_IsNumber(count))
    {
    goto end; //Numeric
    }
    }


    v1beta1_volume_node_resources_local_var = v1beta1_volume_node_resources_create (
        count ? count->valuedouble : 0
        );

    return v1beta1_volume_node_resources_local_var;
end:
    return NULL;

}
