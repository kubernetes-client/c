#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_service_port.h"



v1_service_port_t *v1_service_port_create(
    char *name,
    int node_port,
    int port,
    char *protocol,
    object_t *target_port
    ) {
    v1_service_port_t *v1_service_port_local_var = malloc(sizeof(v1_service_port_t));
    if (!v1_service_port_local_var) {
        return NULL;
    }
    v1_service_port_local_var->name = name;
    v1_service_port_local_var->node_port = node_port;
    v1_service_port_local_var->port = port;
    v1_service_port_local_var->protocol = protocol;
    v1_service_port_local_var->target_port = target_port;

    return v1_service_port_local_var;
}


void v1_service_port_free(v1_service_port_t *v1_service_port) {
    if(NULL == v1_service_port){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_service_port->name) {
        free(v1_service_port->name);
        v1_service_port->name = NULL;
    }
    if (v1_service_port->protocol) {
        free(v1_service_port->protocol);
        v1_service_port->protocol = NULL;
    }
    if (v1_service_port->target_port) {
        object_free(v1_service_port->target_port);
        v1_service_port->target_port = NULL;
    }
    free(v1_service_port);
}

cJSON *v1_service_port_convertToJSON(v1_service_port_t *v1_service_port) {
    cJSON *item = cJSON_CreateObject();

    // v1_service_port->name
    if(v1_service_port->name) { 
    if(cJSON_AddStringToObject(item, "name", v1_service_port->name) == NULL) {
    goto fail; //String
    }
     } 


    // v1_service_port->node_port
    if(v1_service_port->node_port) { 
    if(cJSON_AddNumberToObject(item, "nodePort", v1_service_port->node_port) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_service_port->port
    if (!v1_service_port->port) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "port", v1_service_port->port) == NULL) {
    goto fail; //Numeric
    }


    // v1_service_port->protocol
    if(v1_service_port->protocol) { 
    if(cJSON_AddStringToObject(item, "protocol", v1_service_port->protocol) == NULL) {
    goto fail; //String
    }
     } 


    // v1_service_port->target_port
    if(v1_service_port->target_port) { 
    cJSON *target_port_object = object_convertToJSON(v1_service_port->target_port);
    if(target_port_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "targetPort", target_port_object);
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

v1_service_port_t *v1_service_port_parseFromJSON(cJSON *v1_service_portJSON){

    v1_service_port_t *v1_service_port_local_var = NULL;

    // v1_service_port->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_service_portJSON, "name");
    if (name) { 
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }
    }

    // v1_service_port->node_port
    cJSON *node_port = cJSON_GetObjectItemCaseSensitive(v1_service_portJSON, "nodePort");
    if (node_port) { 
    if(!cJSON_IsNumber(node_port))
    {
    goto end; //Numeric
    }
    }

    // v1_service_port->port
    cJSON *port = cJSON_GetObjectItemCaseSensitive(v1_service_portJSON, "port");
    if (!port) {
        goto end;
    }

    
    if(!cJSON_IsNumber(port))
    {
    goto end; //Numeric
    }

    // v1_service_port->protocol
    cJSON *protocol = cJSON_GetObjectItemCaseSensitive(v1_service_portJSON, "protocol");
    if (protocol) { 
    if(!cJSON_IsString(protocol))
    {
    goto end; //String
    }
    }

    // v1_service_port->target_port
    cJSON *target_port = cJSON_GetObjectItemCaseSensitive(v1_service_portJSON, "targetPort");
    object_t *target_port_local_object = NULL;
    if (target_port) { 
    target_port_local_object = object_parseFromJSON(target_port); //object
    }


    v1_service_port_local_var = v1_service_port_create (
        name ? strdup(name->valuestring) : NULL,
        node_port ? node_port->valuedouble : 0,
        port->valuedouble,
        protocol ? strdup(protocol->valuestring) : NULL,
        target_port ? target_port_local_object : NULL
        );

    return v1_service_port_local_var;
end:
    return NULL;

}
