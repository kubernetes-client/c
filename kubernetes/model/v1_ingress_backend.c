#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_ingress_backend.h"



v1_ingress_backend_t *v1_ingress_backend_create(
    v1_typed_local_object_reference_t *resource,
    v1_ingress_service_backend_t *service
    ) {
    v1_ingress_backend_t *v1_ingress_backend_local_var = malloc(sizeof(v1_ingress_backend_t));
    if (!v1_ingress_backend_local_var) {
        return NULL;
    }
    v1_ingress_backend_local_var->resource = resource;
    v1_ingress_backend_local_var->service = service;

    return v1_ingress_backend_local_var;
}


void v1_ingress_backend_free(v1_ingress_backend_t *v1_ingress_backend) {
    if(NULL == v1_ingress_backend){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_ingress_backend->resource) {
        v1_typed_local_object_reference_free(v1_ingress_backend->resource);
        v1_ingress_backend->resource = NULL;
    }
    if (v1_ingress_backend->service) {
        v1_ingress_service_backend_free(v1_ingress_backend->service);
        v1_ingress_backend->service = NULL;
    }
    free(v1_ingress_backend);
}

cJSON *v1_ingress_backend_convertToJSON(v1_ingress_backend_t *v1_ingress_backend) {
    cJSON *item = cJSON_CreateObject();

    // v1_ingress_backend->resource
    if(v1_ingress_backend->resource) { 
    cJSON *resource_local_JSON = v1_typed_local_object_reference_convertToJSON(v1_ingress_backend->resource);
    if(resource_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "resource", resource_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_ingress_backend->service
    if(v1_ingress_backend->service) { 
    cJSON *service_local_JSON = v1_ingress_service_backend_convertToJSON(v1_ingress_backend->service);
    if(service_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "service", service_local_JSON);
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

v1_ingress_backend_t *v1_ingress_backend_parseFromJSON(cJSON *v1_ingress_backendJSON){

    v1_ingress_backend_t *v1_ingress_backend_local_var = NULL;

    // v1_ingress_backend->resource
    cJSON *resource = cJSON_GetObjectItemCaseSensitive(v1_ingress_backendJSON, "resource");
    v1_typed_local_object_reference_t *resource_local_nonprim = NULL;
    if (resource) { 
    resource_local_nonprim = v1_typed_local_object_reference_parseFromJSON(resource); //nonprimitive
    }

    // v1_ingress_backend->service
    cJSON *service = cJSON_GetObjectItemCaseSensitive(v1_ingress_backendJSON, "service");
    v1_ingress_service_backend_t *service_local_nonprim = NULL;
    if (service) { 
    service_local_nonprim = v1_ingress_service_backend_parseFromJSON(service); //nonprimitive
    }


    v1_ingress_backend_local_var = v1_ingress_backend_create (
        resource ? resource_local_nonprim : NULL,
        service ? service_local_nonprim : NULL
        );

    return v1_ingress_backend_local_var;
end:
    if (resource_local_nonprim) {
        v1_typed_local_object_reference_free(resource_local_nonprim);
        resource_local_nonprim = NULL;
    }
    if (service_local_nonprim) {
        v1_ingress_service_backend_free(service_local_nonprim);
        service_local_nonprim = NULL;
    }
    return NULL;

}
