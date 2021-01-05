#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "networking_v1beta1_ingress_backend.h"



networking_v1beta1_ingress_backend_t *networking_v1beta1_ingress_backend_create(
    char *service_name,
    object_t *service_port
    ) {
    networking_v1beta1_ingress_backend_t *networking_v1beta1_ingress_backend_local_var = malloc(sizeof(networking_v1beta1_ingress_backend_t));
    if (!networking_v1beta1_ingress_backend_local_var) {
        return NULL;
    }
    networking_v1beta1_ingress_backend_local_var->service_name = service_name;
    networking_v1beta1_ingress_backend_local_var->service_port = service_port;

    return networking_v1beta1_ingress_backend_local_var;
}


void networking_v1beta1_ingress_backend_free(networking_v1beta1_ingress_backend_t *networking_v1beta1_ingress_backend) {
    if(NULL == networking_v1beta1_ingress_backend){
        return ;
    }
    listEntry_t *listEntry;
    if (networking_v1beta1_ingress_backend->service_name) {
        free(networking_v1beta1_ingress_backend->service_name);
        networking_v1beta1_ingress_backend->service_name = NULL;
    }
    if (networking_v1beta1_ingress_backend->service_port) {
        object_free(networking_v1beta1_ingress_backend->service_port);
        networking_v1beta1_ingress_backend->service_port = NULL;
    }
    free(networking_v1beta1_ingress_backend);
}

cJSON *networking_v1beta1_ingress_backend_convertToJSON(networking_v1beta1_ingress_backend_t *networking_v1beta1_ingress_backend) {
    cJSON *item = cJSON_CreateObject();

    // networking_v1beta1_ingress_backend->service_name
    if (!networking_v1beta1_ingress_backend->service_name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "serviceName", networking_v1beta1_ingress_backend->service_name) == NULL) {
    goto fail; //String
    }


    // networking_v1beta1_ingress_backend->service_port
    if (!networking_v1beta1_ingress_backend->service_port) {
        goto fail;
    }
    
    cJSON *service_port_object = object_convertToJSON(networking_v1beta1_ingress_backend->service_port);
    if(service_port_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "servicePort", service_port_object);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

networking_v1beta1_ingress_backend_t *networking_v1beta1_ingress_backend_parseFromJSON(cJSON *networking_v1beta1_ingress_backendJSON){

    networking_v1beta1_ingress_backend_t *networking_v1beta1_ingress_backend_local_var = NULL;

    // networking_v1beta1_ingress_backend->service_name
    cJSON *service_name = cJSON_GetObjectItemCaseSensitive(networking_v1beta1_ingress_backendJSON, "serviceName");
    if (!service_name) {
        goto end;
    }

    
    if(!cJSON_IsString(service_name))
    {
    goto end; //String
    }

    // networking_v1beta1_ingress_backend->service_port
    cJSON *service_port = cJSON_GetObjectItemCaseSensitive(networking_v1beta1_ingress_backendJSON, "servicePort");
    if (!service_port) {
        goto end;
    }

    object_t *service_port_local_object = NULL;
    
    service_port_local_object = object_parseFromJSON(service_port); //object


    networking_v1beta1_ingress_backend_local_var = networking_v1beta1_ingress_backend_create (
        strdup(service_name->valuestring),
        service_port_local_object
        );

    return networking_v1beta1_ingress_backend_local_var;
end:
    return NULL;

}
