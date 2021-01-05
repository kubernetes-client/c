#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_endpoint_port.h"



v1_endpoint_port_t *v1_endpoint_port_create(
    char *name,
    int port,
    char *protocol
    ) {
    v1_endpoint_port_t *v1_endpoint_port_local_var = malloc(sizeof(v1_endpoint_port_t));
    if (!v1_endpoint_port_local_var) {
        return NULL;
    }
    v1_endpoint_port_local_var->name = name;
    v1_endpoint_port_local_var->port = port;
    v1_endpoint_port_local_var->protocol = protocol;

    return v1_endpoint_port_local_var;
}


void v1_endpoint_port_free(v1_endpoint_port_t *v1_endpoint_port) {
    if(NULL == v1_endpoint_port){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_endpoint_port->name) {
        free(v1_endpoint_port->name);
        v1_endpoint_port->name = NULL;
    }
    if (v1_endpoint_port->protocol) {
        free(v1_endpoint_port->protocol);
        v1_endpoint_port->protocol = NULL;
    }
    free(v1_endpoint_port);
}

cJSON *v1_endpoint_port_convertToJSON(v1_endpoint_port_t *v1_endpoint_port) {
    cJSON *item = cJSON_CreateObject();

    // v1_endpoint_port->name
    if(v1_endpoint_port->name) { 
    if(cJSON_AddStringToObject(item, "name", v1_endpoint_port->name) == NULL) {
    goto fail; //String
    }
     } 


    // v1_endpoint_port->port
    if (!v1_endpoint_port->port) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "port", v1_endpoint_port->port) == NULL) {
    goto fail; //Numeric
    }


    // v1_endpoint_port->protocol
    if(v1_endpoint_port->protocol) { 
    if(cJSON_AddStringToObject(item, "protocol", v1_endpoint_port->protocol) == NULL) {
    goto fail; //String
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_endpoint_port_t *v1_endpoint_port_parseFromJSON(cJSON *v1_endpoint_portJSON){

    v1_endpoint_port_t *v1_endpoint_port_local_var = NULL;

    // v1_endpoint_port->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_endpoint_portJSON, "name");
    if (name) { 
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }
    }

    // v1_endpoint_port->port
    cJSON *port = cJSON_GetObjectItemCaseSensitive(v1_endpoint_portJSON, "port");
    if (!port) {
        goto end;
    }

    
    if(!cJSON_IsNumber(port))
    {
    goto end; //Numeric
    }

    // v1_endpoint_port->protocol
    cJSON *protocol = cJSON_GetObjectItemCaseSensitive(v1_endpoint_portJSON, "protocol");
    if (protocol) { 
    if(!cJSON_IsString(protocol))
    {
    goto end; //String
    }
    }


    v1_endpoint_port_local_var = v1_endpoint_port_create (
        name ? strdup(name->valuestring) : NULL,
        port->valuedouble,
        protocol ? strdup(protocol->valuestring) : NULL
        );

    return v1_endpoint_port_local_var;
end:
    return NULL;

}
