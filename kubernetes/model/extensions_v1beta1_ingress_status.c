#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_ingress_status.h"



extensions_v1beta1_ingress_status_t *extensions_v1beta1_ingress_status_create(
    v1_load_balancer_status_t *load_balancer
    ) {
    extensions_v1beta1_ingress_status_t *extensions_v1beta1_ingress_status_local_var = malloc(sizeof(extensions_v1beta1_ingress_status_t));
    if (!extensions_v1beta1_ingress_status_local_var) {
        return NULL;
    }
    extensions_v1beta1_ingress_status_local_var->load_balancer = load_balancer;

    return extensions_v1beta1_ingress_status_local_var;
}


void extensions_v1beta1_ingress_status_free(extensions_v1beta1_ingress_status_t *extensions_v1beta1_ingress_status) {
    if(NULL == extensions_v1beta1_ingress_status){
        return ;
    }
    listEntry_t *listEntry;
    if (extensions_v1beta1_ingress_status->load_balancer) {
        v1_load_balancer_status_free(extensions_v1beta1_ingress_status->load_balancer);
        extensions_v1beta1_ingress_status->load_balancer = NULL;
    }
    free(extensions_v1beta1_ingress_status);
}

cJSON *extensions_v1beta1_ingress_status_convertToJSON(extensions_v1beta1_ingress_status_t *extensions_v1beta1_ingress_status) {
    cJSON *item = cJSON_CreateObject();

    // extensions_v1beta1_ingress_status->load_balancer
    if(extensions_v1beta1_ingress_status->load_balancer) { 
    cJSON *load_balancer_local_JSON = v1_load_balancer_status_convertToJSON(extensions_v1beta1_ingress_status->load_balancer);
    if(load_balancer_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "loadBalancer", load_balancer_local_JSON);
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

extensions_v1beta1_ingress_status_t *extensions_v1beta1_ingress_status_parseFromJSON(cJSON *extensions_v1beta1_ingress_statusJSON){

    extensions_v1beta1_ingress_status_t *extensions_v1beta1_ingress_status_local_var = NULL;

    // extensions_v1beta1_ingress_status->load_balancer
    cJSON *load_balancer = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_ingress_statusJSON, "loadBalancer");
    v1_load_balancer_status_t *load_balancer_local_nonprim = NULL;
    if (load_balancer) { 
    load_balancer_local_nonprim = v1_load_balancer_status_parseFromJSON(load_balancer); //nonprimitive
    }


    extensions_v1beta1_ingress_status_local_var = extensions_v1beta1_ingress_status_create (
        load_balancer ? load_balancer_local_nonprim : NULL
        );

    return extensions_v1beta1_ingress_status_local_var;
end:
    if (load_balancer_local_nonprim) {
        v1_load_balancer_status_free(load_balancer_local_nonprim);
        load_balancer_local_nonprim = NULL;
    }
    return NULL;

}
