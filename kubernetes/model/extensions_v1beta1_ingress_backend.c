#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_ingress_backend.h"



extensions_v1beta1_ingress_backend_t *extensions_v1beta1_ingress_backend_create(
    char *service_name,
    object_t *service_port
    ) {
    extensions_v1beta1_ingress_backend_t *extensions_v1beta1_ingress_backend_local_var = malloc(sizeof(extensions_v1beta1_ingress_backend_t));
    if (!extensions_v1beta1_ingress_backend_local_var) {
        return NULL;
    }
    extensions_v1beta1_ingress_backend_local_var->service_name = service_name;
    extensions_v1beta1_ingress_backend_local_var->service_port = service_port;

    return extensions_v1beta1_ingress_backend_local_var;
}


void extensions_v1beta1_ingress_backend_free(extensions_v1beta1_ingress_backend_t *extensions_v1beta1_ingress_backend) {
    if(NULL == extensions_v1beta1_ingress_backend){
        return ;
    }
    listEntry_t *listEntry;
    if (extensions_v1beta1_ingress_backend->service_name) {
        free(extensions_v1beta1_ingress_backend->service_name);
        extensions_v1beta1_ingress_backend->service_name = NULL;
    }
    if (extensions_v1beta1_ingress_backend->service_port) {
        object_free(extensions_v1beta1_ingress_backend->service_port);
        extensions_v1beta1_ingress_backend->service_port = NULL;
    }
    free(extensions_v1beta1_ingress_backend);
}

cJSON *extensions_v1beta1_ingress_backend_convertToJSON(extensions_v1beta1_ingress_backend_t *extensions_v1beta1_ingress_backend) {
    cJSON *item = cJSON_CreateObject();

    // extensions_v1beta1_ingress_backend->service_name
    if (!extensions_v1beta1_ingress_backend->service_name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "serviceName", extensions_v1beta1_ingress_backend->service_name) == NULL) {
    goto fail; //String
    }


    // extensions_v1beta1_ingress_backend->service_port
    if (!extensions_v1beta1_ingress_backend->service_port) {
        goto fail;
    }
    
    cJSON *service_port_object = object_convertToJSON(extensions_v1beta1_ingress_backend->service_port);
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

extensions_v1beta1_ingress_backend_t *extensions_v1beta1_ingress_backend_parseFromJSON(cJSON *extensions_v1beta1_ingress_backendJSON){

    extensions_v1beta1_ingress_backend_t *extensions_v1beta1_ingress_backend_local_var = NULL;

    // extensions_v1beta1_ingress_backend->service_name
    cJSON *service_name = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_ingress_backendJSON, "serviceName");
    if (!service_name) {
        goto end;
    }

    
    if(!cJSON_IsString(service_name))
    {
    goto end; //String
    }

    // extensions_v1beta1_ingress_backend->service_port
    cJSON *service_port = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_ingress_backendJSON, "servicePort");
    if (!service_port) {
        goto end;
    }

    object_t *service_port_local_object = NULL;
    
    service_port_local_object = object_parseFromJSON(service_port); //object


    extensions_v1beta1_ingress_backend_local_var = extensions_v1beta1_ingress_backend_create (
        strdup(service_name->valuestring),
        service_port_local_object
        );

    return extensions_v1beta1_ingress_backend_local_var;
end:
    return NULL;

}
