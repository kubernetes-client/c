#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_network_policy_port.h"



v1_network_policy_port_t *v1_network_policy_port_create(
    object_t *port,
    char *protocol
    ) {
    v1_network_policy_port_t *v1_network_policy_port_local_var = malloc(sizeof(v1_network_policy_port_t));
    if (!v1_network_policy_port_local_var) {
        return NULL;
    }
    v1_network_policy_port_local_var->port = port;
    v1_network_policy_port_local_var->protocol = protocol;

    return v1_network_policy_port_local_var;
}


void v1_network_policy_port_free(v1_network_policy_port_t *v1_network_policy_port) {
    if(NULL == v1_network_policy_port){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_network_policy_port->port) {
        object_free(v1_network_policy_port->port);
        v1_network_policy_port->port = NULL;
    }
    if (v1_network_policy_port->protocol) {
        free(v1_network_policy_port->protocol);
        v1_network_policy_port->protocol = NULL;
    }
    free(v1_network_policy_port);
}

cJSON *v1_network_policy_port_convertToJSON(v1_network_policy_port_t *v1_network_policy_port) {
    cJSON *item = cJSON_CreateObject();

    // v1_network_policy_port->port
    if(v1_network_policy_port->port) { 
    cJSON *port_object = object_convertToJSON(v1_network_policy_port->port);
    if(port_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "port", port_object);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_network_policy_port->protocol
    if(v1_network_policy_port->protocol) { 
    if(cJSON_AddStringToObject(item, "protocol", v1_network_policy_port->protocol) == NULL) {
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

v1_network_policy_port_t *v1_network_policy_port_parseFromJSON(cJSON *v1_network_policy_portJSON){

    v1_network_policy_port_t *v1_network_policy_port_local_var = NULL;

    // v1_network_policy_port->port
    cJSON *port = cJSON_GetObjectItemCaseSensitive(v1_network_policy_portJSON, "port");
    object_t *port_local_object = NULL;
    if (port) { 
    port_local_object = object_parseFromJSON(port); //object
    }

    // v1_network_policy_port->protocol
    cJSON *protocol = cJSON_GetObjectItemCaseSensitive(v1_network_policy_portJSON, "protocol");
    if (protocol) { 
    if(!cJSON_IsString(protocol))
    {
    goto end; //String
    }
    }


    v1_network_policy_port_local_var = v1_network_policy_port_create (
        port ? port_local_object : NULL,
        protocol ? strdup(protocol->valuestring) : NULL
        );

    return v1_network_policy_port_local_var;
end:
    return NULL;

}
