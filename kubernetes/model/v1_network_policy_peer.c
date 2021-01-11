#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_network_policy_peer.h"



v1_network_policy_peer_t *v1_network_policy_peer_create(
    v1_ip_block_t *ip_block,
    v1_label_selector_t *namespace_selector,
    v1_label_selector_t *pod_selector
    ) {
    v1_network_policy_peer_t *v1_network_policy_peer_local_var = malloc(sizeof(v1_network_policy_peer_t));
    if (!v1_network_policy_peer_local_var) {
        return NULL;
    }
    v1_network_policy_peer_local_var->ip_block = ip_block;
    v1_network_policy_peer_local_var->namespace_selector = namespace_selector;
    v1_network_policy_peer_local_var->pod_selector = pod_selector;

    return v1_network_policy_peer_local_var;
}


void v1_network_policy_peer_free(v1_network_policy_peer_t *v1_network_policy_peer) {
    if(NULL == v1_network_policy_peer){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_network_policy_peer->ip_block) {
        v1_ip_block_free(v1_network_policy_peer->ip_block);
        v1_network_policy_peer->ip_block = NULL;
    }
    if (v1_network_policy_peer->namespace_selector) {
        v1_label_selector_free(v1_network_policy_peer->namespace_selector);
        v1_network_policy_peer->namespace_selector = NULL;
    }
    if (v1_network_policy_peer->pod_selector) {
        v1_label_selector_free(v1_network_policy_peer->pod_selector);
        v1_network_policy_peer->pod_selector = NULL;
    }
    free(v1_network_policy_peer);
}

cJSON *v1_network_policy_peer_convertToJSON(v1_network_policy_peer_t *v1_network_policy_peer) {
    cJSON *item = cJSON_CreateObject();

    // v1_network_policy_peer->ip_block
    if(v1_network_policy_peer->ip_block) { 
    cJSON *ip_block_local_JSON = v1_ip_block_convertToJSON(v1_network_policy_peer->ip_block);
    if(ip_block_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ipBlock", ip_block_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_network_policy_peer->namespace_selector
    if(v1_network_policy_peer->namespace_selector) { 
    cJSON *namespace_selector_local_JSON = v1_label_selector_convertToJSON(v1_network_policy_peer->namespace_selector);
    if(namespace_selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "namespaceSelector", namespace_selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_network_policy_peer->pod_selector
    if(v1_network_policy_peer->pod_selector) { 
    cJSON *pod_selector_local_JSON = v1_label_selector_convertToJSON(v1_network_policy_peer->pod_selector);
    if(pod_selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "podSelector", pod_selector_local_JSON);
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

v1_network_policy_peer_t *v1_network_policy_peer_parseFromJSON(cJSON *v1_network_policy_peerJSON){

    v1_network_policy_peer_t *v1_network_policy_peer_local_var = NULL;

    // v1_network_policy_peer->ip_block
    cJSON *ip_block = cJSON_GetObjectItemCaseSensitive(v1_network_policy_peerJSON, "ipBlock");
    v1_ip_block_t *ip_block_local_nonprim = NULL;
    if (ip_block) { 
    ip_block_local_nonprim = v1_ip_block_parseFromJSON(ip_block); //nonprimitive
    }

    // v1_network_policy_peer->namespace_selector
    cJSON *namespace_selector = cJSON_GetObjectItemCaseSensitive(v1_network_policy_peerJSON, "namespaceSelector");
    v1_label_selector_t *namespace_selector_local_nonprim = NULL;
    if (namespace_selector) { 
    namespace_selector_local_nonprim = v1_label_selector_parseFromJSON(namespace_selector); //nonprimitive
    }

    // v1_network_policy_peer->pod_selector
    cJSON *pod_selector = cJSON_GetObjectItemCaseSensitive(v1_network_policy_peerJSON, "podSelector");
    v1_label_selector_t *pod_selector_local_nonprim = NULL;
    if (pod_selector) { 
    pod_selector_local_nonprim = v1_label_selector_parseFromJSON(pod_selector); //nonprimitive
    }


    v1_network_policy_peer_local_var = v1_network_policy_peer_create (
        ip_block ? ip_block_local_nonprim : NULL,
        namespace_selector ? namespace_selector_local_nonprim : NULL,
        pod_selector ? pod_selector_local_nonprim : NULL
        );

    return v1_network_policy_peer_local_var;
end:
    if (ip_block_local_nonprim) {
        v1_ip_block_free(ip_block_local_nonprim);
        ip_block_local_nonprim = NULL;
    }
    if (namespace_selector_local_nonprim) {
        v1_label_selector_free(namespace_selector_local_nonprim);
        namespace_selector_local_nonprim = NULL;
    }
    if (pod_selector_local_nonprim) {
        v1_label_selector_free(pod_selector_local_nonprim);
        pod_selector_local_nonprim = NULL;
    }
    return NULL;

}
