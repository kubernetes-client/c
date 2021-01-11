#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_service_status.h"



v1_service_status_t *v1_service_status_create(
    v1_load_balancer_status_t *load_balancer
    ) {
    v1_service_status_t *v1_service_status_local_var = malloc(sizeof(v1_service_status_t));
    if (!v1_service_status_local_var) {
        return NULL;
    }
    v1_service_status_local_var->load_balancer = load_balancer;

    return v1_service_status_local_var;
}


void v1_service_status_free(v1_service_status_t *v1_service_status) {
    if(NULL == v1_service_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_service_status->load_balancer) {
        v1_load_balancer_status_free(v1_service_status->load_balancer);
        v1_service_status->load_balancer = NULL;
    }
    free(v1_service_status);
}

cJSON *v1_service_status_convertToJSON(v1_service_status_t *v1_service_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_service_status->load_balancer
    if(v1_service_status->load_balancer) { 
    cJSON *load_balancer_local_JSON = v1_load_balancer_status_convertToJSON(v1_service_status->load_balancer);
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

v1_service_status_t *v1_service_status_parseFromJSON(cJSON *v1_service_statusJSON){

    v1_service_status_t *v1_service_status_local_var = NULL;

    // v1_service_status->load_balancer
    cJSON *load_balancer = cJSON_GetObjectItemCaseSensitive(v1_service_statusJSON, "loadBalancer");
    v1_load_balancer_status_t *load_balancer_local_nonprim = NULL;
    if (load_balancer) { 
    load_balancer_local_nonprim = v1_load_balancer_status_parseFromJSON(load_balancer); //nonprimitive
    }


    v1_service_status_local_var = v1_service_status_create (
        load_balancer ? load_balancer_local_nonprim : NULL
        );

    return v1_service_status_local_var;
end:
    if (load_balancer_local_nonprim) {
        v1_load_balancer_status_free(load_balancer_local_nonprim);
        load_balancer_local_nonprim = NULL;
    }
    return NULL;

}
