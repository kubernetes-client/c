#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_volume_node_affinity.h"



v1_volume_node_affinity_t *v1_volume_node_affinity_create(
    v1_node_selector_t *required
    ) {
    v1_volume_node_affinity_t *v1_volume_node_affinity_local_var = malloc(sizeof(v1_volume_node_affinity_t));
    if (!v1_volume_node_affinity_local_var) {
        return NULL;
    }
    v1_volume_node_affinity_local_var->required = required;

    return v1_volume_node_affinity_local_var;
}


void v1_volume_node_affinity_free(v1_volume_node_affinity_t *v1_volume_node_affinity) {
    if(NULL == v1_volume_node_affinity){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_volume_node_affinity->required) {
        v1_node_selector_free(v1_volume_node_affinity->required);
        v1_volume_node_affinity->required = NULL;
    }
    free(v1_volume_node_affinity);
}

cJSON *v1_volume_node_affinity_convertToJSON(v1_volume_node_affinity_t *v1_volume_node_affinity) {
    cJSON *item = cJSON_CreateObject();

    // v1_volume_node_affinity->required
    if(v1_volume_node_affinity->required) { 
    cJSON *required_local_JSON = v1_node_selector_convertToJSON(v1_volume_node_affinity->required);
    if(required_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "required", required_local_JSON);
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

v1_volume_node_affinity_t *v1_volume_node_affinity_parseFromJSON(cJSON *v1_volume_node_affinityJSON){

    v1_volume_node_affinity_t *v1_volume_node_affinity_local_var = NULL;

    // v1_volume_node_affinity->required
    cJSON *required = cJSON_GetObjectItemCaseSensitive(v1_volume_node_affinityJSON, "required");
    v1_node_selector_t *required_local_nonprim = NULL;
    if (required) { 
    required_local_nonprim = v1_node_selector_parseFromJSON(required); //nonprimitive
    }


    v1_volume_node_affinity_local_var = v1_volume_node_affinity_create (
        required ? required_local_nonprim : NULL
        );

    return v1_volume_node_affinity_local_var;
end:
    if (required_local_nonprim) {
        v1_node_selector_free(required_local_nonprim);
        required_local_nonprim = NULL;
    }
    return NULL;

}
