#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_affinity.h"



v1_affinity_t *v1_affinity_create(
    v1_node_affinity_t *node_affinity,
    v1_pod_affinity_t *pod_affinity,
    v1_pod_anti_affinity_t *pod_anti_affinity
    ) {
    v1_affinity_t *v1_affinity_local_var = malloc(sizeof(v1_affinity_t));
    if (!v1_affinity_local_var) {
        return NULL;
    }
    v1_affinity_local_var->node_affinity = node_affinity;
    v1_affinity_local_var->pod_affinity = pod_affinity;
    v1_affinity_local_var->pod_anti_affinity = pod_anti_affinity;

    return v1_affinity_local_var;
}


void v1_affinity_free(v1_affinity_t *v1_affinity) {
    if(NULL == v1_affinity){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_affinity->node_affinity) {
        v1_node_affinity_free(v1_affinity->node_affinity);
        v1_affinity->node_affinity = NULL;
    }
    if (v1_affinity->pod_affinity) {
        v1_pod_affinity_free(v1_affinity->pod_affinity);
        v1_affinity->pod_affinity = NULL;
    }
    if (v1_affinity->pod_anti_affinity) {
        v1_pod_anti_affinity_free(v1_affinity->pod_anti_affinity);
        v1_affinity->pod_anti_affinity = NULL;
    }
    free(v1_affinity);
}

cJSON *v1_affinity_convertToJSON(v1_affinity_t *v1_affinity) {
    cJSON *item = cJSON_CreateObject();

    // v1_affinity->node_affinity
    if(v1_affinity->node_affinity) { 
    cJSON *node_affinity_local_JSON = v1_node_affinity_convertToJSON(v1_affinity->node_affinity);
    if(node_affinity_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "nodeAffinity", node_affinity_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_affinity->pod_affinity
    if(v1_affinity->pod_affinity) { 
    cJSON *pod_affinity_local_JSON = v1_pod_affinity_convertToJSON(v1_affinity->pod_affinity);
    if(pod_affinity_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "podAffinity", pod_affinity_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_affinity->pod_anti_affinity
    if(v1_affinity->pod_anti_affinity) { 
    cJSON *pod_anti_affinity_local_JSON = v1_pod_anti_affinity_convertToJSON(v1_affinity->pod_anti_affinity);
    if(pod_anti_affinity_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "podAntiAffinity", pod_anti_affinity_local_JSON);
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

v1_affinity_t *v1_affinity_parseFromJSON(cJSON *v1_affinityJSON){

    v1_affinity_t *v1_affinity_local_var = NULL;

    // v1_affinity->node_affinity
    cJSON *node_affinity = cJSON_GetObjectItemCaseSensitive(v1_affinityJSON, "nodeAffinity");
    v1_node_affinity_t *node_affinity_local_nonprim = NULL;
    if (node_affinity) { 
    node_affinity_local_nonprim = v1_node_affinity_parseFromJSON(node_affinity); //nonprimitive
    }

    // v1_affinity->pod_affinity
    cJSON *pod_affinity = cJSON_GetObjectItemCaseSensitive(v1_affinityJSON, "podAffinity");
    v1_pod_affinity_t *pod_affinity_local_nonprim = NULL;
    if (pod_affinity) { 
    pod_affinity_local_nonprim = v1_pod_affinity_parseFromJSON(pod_affinity); //nonprimitive
    }

    // v1_affinity->pod_anti_affinity
    cJSON *pod_anti_affinity = cJSON_GetObjectItemCaseSensitive(v1_affinityJSON, "podAntiAffinity");
    v1_pod_anti_affinity_t *pod_anti_affinity_local_nonprim = NULL;
    if (pod_anti_affinity) { 
    pod_anti_affinity_local_nonprim = v1_pod_anti_affinity_parseFromJSON(pod_anti_affinity); //nonprimitive
    }


    v1_affinity_local_var = v1_affinity_create (
        node_affinity ? node_affinity_local_nonprim : NULL,
        pod_affinity ? pod_affinity_local_nonprim : NULL,
        pod_anti_affinity ? pod_anti_affinity_local_nonprim : NULL
        );

    return v1_affinity_local_var;
end:
    if (node_affinity_local_nonprim) {
        v1_node_affinity_free(node_affinity_local_nonprim);
        node_affinity_local_nonprim = NULL;
    }
    if (pod_affinity_local_nonprim) {
        v1_pod_affinity_free(pod_affinity_local_nonprim);
        pod_affinity_local_nonprim = NULL;
    }
    if (pod_anti_affinity_local_nonprim) {
        v1_pod_anti_affinity_free(pod_anti_affinity_local_nonprim);
        pod_anti_affinity_local_nonprim = NULL;
    }
    return NULL;

}
