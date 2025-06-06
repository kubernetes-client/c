#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_daemon_endpoints.h"



static v1_node_daemon_endpoints_t *v1_node_daemon_endpoints_create_internal(
    v1_daemon_endpoint_t *kubelet_endpoint
    ) {
    v1_node_daemon_endpoints_t *v1_node_daemon_endpoints_local_var = malloc(sizeof(v1_node_daemon_endpoints_t));
    if (!v1_node_daemon_endpoints_local_var) {
        return NULL;
    }
    v1_node_daemon_endpoints_local_var->kubelet_endpoint = kubelet_endpoint;

    v1_node_daemon_endpoints_local_var->_library_owned = 1;
    return v1_node_daemon_endpoints_local_var;
}

__attribute__((deprecated)) v1_node_daemon_endpoints_t *v1_node_daemon_endpoints_create(
    v1_daemon_endpoint_t *kubelet_endpoint
    ) {
    return v1_node_daemon_endpoints_create_internal (
        kubelet_endpoint
        );
}

void v1_node_daemon_endpoints_free(v1_node_daemon_endpoints_t *v1_node_daemon_endpoints) {
    if(NULL == v1_node_daemon_endpoints){
        return ;
    }
    if(v1_node_daemon_endpoints->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_node_daemon_endpoints_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_node_daemon_endpoints->kubelet_endpoint) {
        v1_daemon_endpoint_free(v1_node_daemon_endpoints->kubelet_endpoint);
        v1_node_daemon_endpoints->kubelet_endpoint = NULL;
    }
    free(v1_node_daemon_endpoints);
}

cJSON *v1_node_daemon_endpoints_convertToJSON(v1_node_daemon_endpoints_t *v1_node_daemon_endpoints) {
    cJSON *item = cJSON_CreateObject();

    // v1_node_daemon_endpoints->kubelet_endpoint
    if(v1_node_daemon_endpoints->kubelet_endpoint) {
    cJSON *kubelet_endpoint_local_JSON = v1_daemon_endpoint_convertToJSON(v1_node_daemon_endpoints->kubelet_endpoint);
    if(kubelet_endpoint_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "kubeletEndpoint", kubelet_endpoint_local_JSON);
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

v1_node_daemon_endpoints_t *v1_node_daemon_endpoints_parseFromJSON(cJSON *v1_node_daemon_endpointsJSON){

    v1_node_daemon_endpoints_t *v1_node_daemon_endpoints_local_var = NULL;

    // define the local variable for v1_node_daemon_endpoints->kubelet_endpoint
    v1_daemon_endpoint_t *kubelet_endpoint_local_nonprim = NULL;

    // v1_node_daemon_endpoints->kubelet_endpoint
    cJSON *kubelet_endpoint = cJSON_GetObjectItemCaseSensitive(v1_node_daemon_endpointsJSON, "kubeletEndpoint");
    if (cJSON_IsNull(kubelet_endpoint)) {
        kubelet_endpoint = NULL;
    }
    if (kubelet_endpoint) { 
    kubelet_endpoint_local_nonprim = v1_daemon_endpoint_parseFromJSON(kubelet_endpoint); //nonprimitive
    }


    v1_node_daemon_endpoints_local_var = v1_node_daemon_endpoints_create_internal (
        kubelet_endpoint ? kubelet_endpoint_local_nonprim : NULL
        );

    return v1_node_daemon_endpoints_local_var;
end:
    if (kubelet_endpoint_local_nonprim) {
        v1_daemon_endpoint_free(kubelet_endpoint_local_nonprim);
        kubelet_endpoint_local_nonprim = NULL;
    }
    return NULL;

}
