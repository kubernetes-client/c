#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_ingress_port_status.h"



static v1_ingress_port_status_t *v1_ingress_port_status_create_internal(
    char *error,
    int port,
    char *protocol
    ) {
    v1_ingress_port_status_t *v1_ingress_port_status_local_var = malloc(sizeof(v1_ingress_port_status_t));
    if (!v1_ingress_port_status_local_var) {
        return NULL;
    }
    v1_ingress_port_status_local_var->error = error;
    v1_ingress_port_status_local_var->port = port;
    v1_ingress_port_status_local_var->protocol = protocol;

    v1_ingress_port_status_local_var->_library_owned = 1;
    return v1_ingress_port_status_local_var;
}

__attribute__((deprecated)) v1_ingress_port_status_t *v1_ingress_port_status_create(
    char *error,
    int port,
    char *protocol
    ) {
    return v1_ingress_port_status_create_internal (
        error,
        port,
        protocol
        );
}

void v1_ingress_port_status_free(v1_ingress_port_status_t *v1_ingress_port_status) {
    if(NULL == v1_ingress_port_status){
        return ;
    }
    if(v1_ingress_port_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_ingress_port_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_ingress_port_status->error) {
        free(v1_ingress_port_status->error);
        v1_ingress_port_status->error = NULL;
    }
    if (v1_ingress_port_status->protocol) {
        free(v1_ingress_port_status->protocol);
        v1_ingress_port_status->protocol = NULL;
    }
    free(v1_ingress_port_status);
}

cJSON *v1_ingress_port_status_convertToJSON(v1_ingress_port_status_t *v1_ingress_port_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_ingress_port_status->error
    if(v1_ingress_port_status->error) {
    if(cJSON_AddStringToObject(item, "error", v1_ingress_port_status->error) == NULL) {
    goto fail; //String
    }
    }


    // v1_ingress_port_status->port
    if (!v1_ingress_port_status->port) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "port", v1_ingress_port_status->port) == NULL) {
    goto fail; //Numeric
    }


    // v1_ingress_port_status->protocol
    if (!v1_ingress_port_status->protocol) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "protocol", v1_ingress_port_status->protocol) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_ingress_port_status_t *v1_ingress_port_status_parseFromJSON(cJSON *v1_ingress_port_statusJSON){

    v1_ingress_port_status_t *v1_ingress_port_status_local_var = NULL;

    // v1_ingress_port_status->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(v1_ingress_port_statusJSON, "error");
    if (cJSON_IsNull(error)) {
        error = NULL;
    }
    if (error) { 
    if(!cJSON_IsString(error) && !cJSON_IsNull(error))
    {
    goto end; //String
    }
    }

    // v1_ingress_port_status->port
    cJSON *port = cJSON_GetObjectItemCaseSensitive(v1_ingress_port_statusJSON, "port");
    if (cJSON_IsNull(port)) {
        port = NULL;
    }
    if (!port) {
        goto end;
    }

    
    if(!cJSON_IsNumber(port))
    {
    goto end; //Numeric
    }

    // v1_ingress_port_status->protocol
    cJSON *protocol = cJSON_GetObjectItemCaseSensitive(v1_ingress_port_statusJSON, "protocol");
    if (cJSON_IsNull(protocol)) {
        protocol = NULL;
    }
    if (!protocol) {
        goto end;
    }

    
    if(!cJSON_IsString(protocol))
    {
    goto end; //String
    }


    v1_ingress_port_status_local_var = v1_ingress_port_status_create_internal (
        error && !cJSON_IsNull(error) ? strdup(error->valuestring) : NULL,
        port->valuedouble,
        strdup(protocol->valuestring)
        );

    return v1_ingress_port_status_local_var;
end:
    return NULL;

}
