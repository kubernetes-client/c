#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_ingress_service_backend.h"



static v1_ingress_service_backend_t *v1_ingress_service_backend_create_internal(
    char *name,
    v1_service_backend_port_t *port
    ) {
    v1_ingress_service_backend_t *v1_ingress_service_backend_local_var = malloc(sizeof(v1_ingress_service_backend_t));
    if (!v1_ingress_service_backend_local_var) {
        return NULL;
    }
    v1_ingress_service_backend_local_var->name = name;
    v1_ingress_service_backend_local_var->port = port;

    v1_ingress_service_backend_local_var->_library_owned = 1;
    return v1_ingress_service_backend_local_var;
}

__attribute__((deprecated)) v1_ingress_service_backend_t *v1_ingress_service_backend_create(
    char *name,
    v1_service_backend_port_t *port
    ) {
    return v1_ingress_service_backend_create_internal (
        name,
        port
        );
}

void v1_ingress_service_backend_free(v1_ingress_service_backend_t *v1_ingress_service_backend) {
    if(NULL == v1_ingress_service_backend){
        return ;
    }
    if(v1_ingress_service_backend->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_ingress_service_backend_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_ingress_service_backend->name) {
        free(v1_ingress_service_backend->name);
        v1_ingress_service_backend->name = NULL;
    }
    if (v1_ingress_service_backend->port) {
        v1_service_backend_port_free(v1_ingress_service_backend->port);
        v1_ingress_service_backend->port = NULL;
    }
    free(v1_ingress_service_backend);
}

cJSON *v1_ingress_service_backend_convertToJSON(v1_ingress_service_backend_t *v1_ingress_service_backend) {
    cJSON *item = cJSON_CreateObject();

    // v1_ingress_service_backend->name
    if (!v1_ingress_service_backend->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_ingress_service_backend->name) == NULL) {
    goto fail; //String
    }


    // v1_ingress_service_backend->port
    if(v1_ingress_service_backend->port) {
    cJSON *port_local_JSON = v1_service_backend_port_convertToJSON(v1_ingress_service_backend->port);
    if(port_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "port", port_local_JSON);
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

v1_ingress_service_backend_t *v1_ingress_service_backend_parseFromJSON(cJSON *v1_ingress_service_backendJSON){

    v1_ingress_service_backend_t *v1_ingress_service_backend_local_var = NULL;

    // define the local variable for v1_ingress_service_backend->port
    v1_service_backend_port_t *port_local_nonprim = NULL;

    // v1_ingress_service_backend->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_ingress_service_backendJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_ingress_service_backend->port
    cJSON *port = cJSON_GetObjectItemCaseSensitive(v1_ingress_service_backendJSON, "port");
    if (cJSON_IsNull(port)) {
        port = NULL;
    }
    if (port) { 
    port_local_nonprim = v1_service_backend_port_parseFromJSON(port); //nonprimitive
    }


    v1_ingress_service_backend_local_var = v1_ingress_service_backend_create_internal (
        strdup(name->valuestring),
        port ? port_local_nonprim : NULL
        );

    return v1_ingress_service_backend_local_var;
end:
    if (port_local_nonprim) {
        v1_service_backend_port_free(port_local_nonprim);
        port_local_nonprim = NULL;
    }
    return NULL;

}
