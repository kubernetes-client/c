#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_network_policy_port.h"



v1_network_policy_port_t *v1_network_policy_port_create(
    int end_port,
    int_or_string_t *port,
    char *protocol
    ) {
    v1_network_policy_port_t *v1_network_policy_port_local_var = malloc(sizeof(v1_network_policy_port_t));
    if (!v1_network_policy_port_local_var) {
        return NULL;
    }
    v1_network_policy_port_local_var->end_port = end_port;
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
        int_or_string_free(v1_network_policy_port->port);
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

    // v1_network_policy_port->end_port
    if(v1_network_policy_port->end_port) {
    if(cJSON_AddNumberToObject(item, "endPort", v1_network_policy_port->end_port) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_network_policy_port->port
    if(v1_network_policy_port->port) {
    cJSON *port_local_JSON = int_or_string_convertToJSON(v1_network_policy_port->port);
    if(port_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "port", port_local_JSON);
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

    // define the local variable for v1_network_policy_port->port
    int_or_string_t *port_local_nonprim = NULL;

    // v1_network_policy_port->end_port
    cJSON *end_port = cJSON_GetObjectItemCaseSensitive(v1_network_policy_portJSON, "endPort");
    if (end_port) { 
    if(!cJSON_IsNumber(end_port))
    {
    goto end; //Numeric
    }
    }

    // v1_network_policy_port->port
    cJSON *port = cJSON_GetObjectItemCaseSensitive(v1_network_policy_portJSON, "port");
    if (port) { 
    port_local_nonprim = int_or_string_parseFromJSON(port); //custom
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
        end_port ? end_port->valuedouble : 0,
        port ? port_local_nonprim : NULL,
        protocol ? strdup(protocol->valuestring) : NULL
        );

    return v1_network_policy_port_local_var;
end:
    if (port_local_nonprim) {
        int_or_string_free(port_local_nonprim);
        port_local_nonprim = NULL;
    }
    return NULL;

}
