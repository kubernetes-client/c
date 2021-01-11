#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "networking_v1beta1_ingress_status.h"



networking_v1beta1_ingress_status_t *networking_v1beta1_ingress_status_create(
    v1_load_balancer_status_t *load_balancer
    ) {
    networking_v1beta1_ingress_status_t *networking_v1beta1_ingress_status_local_var = malloc(sizeof(networking_v1beta1_ingress_status_t));
    if (!networking_v1beta1_ingress_status_local_var) {
        return NULL;
    }
    networking_v1beta1_ingress_status_local_var->load_balancer = load_balancer;

    return networking_v1beta1_ingress_status_local_var;
}


void networking_v1beta1_ingress_status_free(networking_v1beta1_ingress_status_t *networking_v1beta1_ingress_status) {
    if(NULL == networking_v1beta1_ingress_status){
        return ;
    }
    listEntry_t *listEntry;
    if (networking_v1beta1_ingress_status->load_balancer) {
        v1_load_balancer_status_free(networking_v1beta1_ingress_status->load_balancer);
        networking_v1beta1_ingress_status->load_balancer = NULL;
    }
    free(networking_v1beta1_ingress_status);
}

cJSON *networking_v1beta1_ingress_status_convertToJSON(networking_v1beta1_ingress_status_t *networking_v1beta1_ingress_status) {
    cJSON *item = cJSON_CreateObject();

    // networking_v1beta1_ingress_status->load_balancer
    if(networking_v1beta1_ingress_status->load_balancer) { 
    cJSON *load_balancer_local_JSON = v1_load_balancer_status_convertToJSON(networking_v1beta1_ingress_status->load_balancer);
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

networking_v1beta1_ingress_status_t *networking_v1beta1_ingress_status_parseFromJSON(cJSON *networking_v1beta1_ingress_statusJSON){

    networking_v1beta1_ingress_status_t *networking_v1beta1_ingress_status_local_var = NULL;

    // networking_v1beta1_ingress_status->load_balancer
    cJSON *load_balancer = cJSON_GetObjectItemCaseSensitive(networking_v1beta1_ingress_statusJSON, "loadBalancer");
    v1_load_balancer_status_t *load_balancer_local_nonprim = NULL;
    if (load_balancer) { 
    load_balancer_local_nonprim = v1_load_balancer_status_parseFromJSON(load_balancer); //nonprimitive
    }


    networking_v1beta1_ingress_status_local_var = networking_v1beta1_ingress_status_create (
        load_balancer ? load_balancer_local_nonprim : NULL
        );

    return networking_v1beta1_ingress_status_local_var;
end:
    if (load_balancer_local_nonprim) {
        v1_load_balancer_status_free(load_balancer_local_nonprim);
        load_balancer_local_nonprim = NULL;
    }
    return NULL;

}
