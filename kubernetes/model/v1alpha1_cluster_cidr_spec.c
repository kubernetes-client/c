#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_cluster_cidr_spec.h"



v1alpha1_cluster_cidr_spec_t *v1alpha1_cluster_cidr_spec_create(
    char *ipv4,
    char *ipv6,
    v1_node_selector_t *node_selector,
    int per_node_host_bits
    ) {
    v1alpha1_cluster_cidr_spec_t *v1alpha1_cluster_cidr_spec_local_var = malloc(sizeof(v1alpha1_cluster_cidr_spec_t));
    if (!v1alpha1_cluster_cidr_spec_local_var) {
        return NULL;
    }
    v1alpha1_cluster_cidr_spec_local_var->ipv4 = ipv4;
    v1alpha1_cluster_cidr_spec_local_var->ipv6 = ipv6;
    v1alpha1_cluster_cidr_spec_local_var->node_selector = node_selector;
    v1alpha1_cluster_cidr_spec_local_var->per_node_host_bits = per_node_host_bits;

    return v1alpha1_cluster_cidr_spec_local_var;
}


void v1alpha1_cluster_cidr_spec_free(v1alpha1_cluster_cidr_spec_t *v1alpha1_cluster_cidr_spec) {
    if(NULL == v1alpha1_cluster_cidr_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_cluster_cidr_spec->ipv4) {
        free(v1alpha1_cluster_cidr_spec->ipv4);
        v1alpha1_cluster_cidr_spec->ipv4 = NULL;
    }
    if (v1alpha1_cluster_cidr_spec->ipv6) {
        free(v1alpha1_cluster_cidr_spec->ipv6);
        v1alpha1_cluster_cidr_spec->ipv6 = NULL;
    }
    if (v1alpha1_cluster_cidr_spec->node_selector) {
        v1_node_selector_free(v1alpha1_cluster_cidr_spec->node_selector);
        v1alpha1_cluster_cidr_spec->node_selector = NULL;
    }
    free(v1alpha1_cluster_cidr_spec);
}

cJSON *v1alpha1_cluster_cidr_spec_convertToJSON(v1alpha1_cluster_cidr_spec_t *v1alpha1_cluster_cidr_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_cluster_cidr_spec->ipv4
    if(v1alpha1_cluster_cidr_spec->ipv4) {
    if(cJSON_AddStringToObject(item, "ipv4", v1alpha1_cluster_cidr_spec->ipv4) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_cluster_cidr_spec->ipv6
    if(v1alpha1_cluster_cidr_spec->ipv6) {
    if(cJSON_AddStringToObject(item, "ipv6", v1alpha1_cluster_cidr_spec->ipv6) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_cluster_cidr_spec->node_selector
    if(v1alpha1_cluster_cidr_spec->node_selector) {
    cJSON *node_selector_local_JSON = v1_node_selector_convertToJSON(v1alpha1_cluster_cidr_spec->node_selector);
    if(node_selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "nodeSelector", node_selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha1_cluster_cidr_spec->per_node_host_bits
    if (!v1alpha1_cluster_cidr_spec->per_node_host_bits) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "perNodeHostBits", v1alpha1_cluster_cidr_spec->per_node_host_bits) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_cluster_cidr_spec_t *v1alpha1_cluster_cidr_spec_parseFromJSON(cJSON *v1alpha1_cluster_cidr_specJSON){

    v1alpha1_cluster_cidr_spec_t *v1alpha1_cluster_cidr_spec_local_var = NULL;

    // define the local variable for v1alpha1_cluster_cidr_spec->node_selector
    v1_node_selector_t *node_selector_local_nonprim = NULL;

    // v1alpha1_cluster_cidr_spec->ipv4
    cJSON *ipv4 = cJSON_GetObjectItemCaseSensitive(v1alpha1_cluster_cidr_specJSON, "ipv4");
    if (ipv4) { 
    if(!cJSON_IsString(ipv4) && !cJSON_IsNull(ipv4))
    {
    goto end; //String
    }
    }

    // v1alpha1_cluster_cidr_spec->ipv6
    cJSON *ipv6 = cJSON_GetObjectItemCaseSensitive(v1alpha1_cluster_cidr_specJSON, "ipv6");
    if (ipv6) { 
    if(!cJSON_IsString(ipv6) && !cJSON_IsNull(ipv6))
    {
    goto end; //String
    }
    }

    // v1alpha1_cluster_cidr_spec->node_selector
    cJSON *node_selector = cJSON_GetObjectItemCaseSensitive(v1alpha1_cluster_cidr_specJSON, "nodeSelector");
    if (node_selector) { 
    node_selector_local_nonprim = v1_node_selector_parseFromJSON(node_selector); //nonprimitive
    }

    // v1alpha1_cluster_cidr_spec->per_node_host_bits
    cJSON *per_node_host_bits = cJSON_GetObjectItemCaseSensitive(v1alpha1_cluster_cidr_specJSON, "perNodeHostBits");
    if (!per_node_host_bits) {
        goto end;
    }

    
    if(!cJSON_IsNumber(per_node_host_bits))
    {
    goto end; //Numeric
    }


    v1alpha1_cluster_cidr_spec_local_var = v1alpha1_cluster_cidr_spec_create (
        ipv4 && !cJSON_IsNull(ipv4) ? strdup(ipv4->valuestring) : NULL,
        ipv6 && !cJSON_IsNull(ipv6) ? strdup(ipv6->valuestring) : NULL,
        node_selector ? node_selector_local_nonprim : NULL,
        per_node_host_bits->valuedouble
        );

    return v1alpha1_cluster_cidr_spec_local_var;
end:
    if (node_selector_local_nonprim) {
        v1_node_selector_free(node_selector_local_nonprim);
        node_selector_local_nonprim = NULL;
    }
    return NULL;

}
