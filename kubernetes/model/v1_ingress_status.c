#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_ingress_status.h"



static v1_ingress_status_t *v1_ingress_status_create_internal(
    v1_ingress_load_balancer_status_t *load_balancer
    ) {
    v1_ingress_status_t *v1_ingress_status_local_var = malloc(sizeof(v1_ingress_status_t));
    if (!v1_ingress_status_local_var) {
        return NULL;
    }
    v1_ingress_status_local_var->load_balancer = load_balancer;

    v1_ingress_status_local_var->_library_owned = 1;
    return v1_ingress_status_local_var;
}

__attribute__((deprecated)) v1_ingress_status_t *v1_ingress_status_create(
    v1_ingress_load_balancer_status_t *load_balancer
    ) {
    return v1_ingress_status_create_internal (
        load_balancer
        );
}

void v1_ingress_status_free(v1_ingress_status_t *v1_ingress_status) {
    if(NULL == v1_ingress_status){
        return ;
    }
    if(v1_ingress_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_ingress_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_ingress_status->load_balancer) {
        v1_ingress_load_balancer_status_free(v1_ingress_status->load_balancer);
        v1_ingress_status->load_balancer = NULL;
    }
    free(v1_ingress_status);
}

cJSON *v1_ingress_status_convertToJSON(v1_ingress_status_t *v1_ingress_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_ingress_status->load_balancer
    if(v1_ingress_status->load_balancer) {
    cJSON *load_balancer_local_JSON = v1_ingress_load_balancer_status_convertToJSON(v1_ingress_status->load_balancer);
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

v1_ingress_status_t *v1_ingress_status_parseFromJSON(cJSON *v1_ingress_statusJSON){

    v1_ingress_status_t *v1_ingress_status_local_var = NULL;

    // define the local variable for v1_ingress_status->load_balancer
    v1_ingress_load_balancer_status_t *load_balancer_local_nonprim = NULL;

    // v1_ingress_status->load_balancer
    cJSON *load_balancer = cJSON_GetObjectItemCaseSensitive(v1_ingress_statusJSON, "loadBalancer");
    if (cJSON_IsNull(load_balancer)) {
        load_balancer = NULL;
    }
    if (load_balancer) { 
    load_balancer_local_nonprim = v1_ingress_load_balancer_status_parseFromJSON(load_balancer); //nonprimitive
    }


    v1_ingress_status_local_var = v1_ingress_status_create_internal (
        load_balancer ? load_balancer_local_nonprim : NULL
        );

    return v1_ingress_status_local_var;
end:
    if (load_balancer_local_nonprim) {
        v1_ingress_load_balancer_status_free(load_balancer_local_nonprim);
        load_balancer_local_nonprim = NULL;
    }
    return NULL;

}
