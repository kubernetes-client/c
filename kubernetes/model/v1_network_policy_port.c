#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_network_policy_port.h"



static v1_network_policy_port_t *v1_network_policy_port_create_internal(
    int *end_port,
    int_or_string_t *port,
    char *protocol
    ) {
    v1_network_policy_port_t *v1_network_policy_port_local_var = malloc(sizeof(v1_network_policy_port_t));
    if (!v1_network_policy_port_local_var) {
        return NULL;
    }
    memset(v1_network_policy_port_local_var, 0, sizeof(v1_network_policy_port_t));
    v1_network_policy_port_local_var->_library_owned = 1;
    v1_network_policy_port_local_var->end_port = end_port;
    v1_network_policy_port_local_var->port = port;
    v1_network_policy_port_local_var->protocol = protocol;
    return v1_network_policy_port_local_var;
}

__attribute__((deprecated)) v1_network_policy_port_t *v1_network_policy_port_create(
    int *end_port,
    int_or_string_t *port,
    char *protocol
    ) {
    int *end_port_copy = NULL;
    if (end_port) {
        end_port_copy = malloc(sizeof(int));
        if (end_port_copy) *end_port_copy = *end_port;
    }
    v1_network_policy_port_t *result = v1_network_policy_port_create_internal (
        end_port_copy,
        port,
        protocol
        );
    if (!result) {
        free(end_port_copy);
    }
    return result;
}

void v1_network_policy_port_free(v1_network_policy_port_t *v1_network_policy_port) {
    if(NULL == v1_network_policy_port){
        return ;
    }
    if(v1_network_policy_port->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_network_policy_port_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_network_policy_port->end_port) {
        free(v1_network_policy_port->end_port);
        v1_network_policy_port->end_port = NULL;
    }
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
    if(cJSON_AddNumberToObject(item, "endPort", *v1_network_policy_port->end_port) == NULL) {
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

    // define the local variable for v1_network_policy_port->end_port
    int *end_port_local_var = NULL;

    // define the local variable for v1_network_policy_port->port
    int_or_string_t *port_local_nonprim = NULL;

    char *protocol_local_str = NULL;

    // v1_network_policy_port->end_port
    cJSON *end_port = cJSON_GetObjectItemCaseSensitive(v1_network_policy_portJSON, "endPort");
    if (cJSON_IsNull(end_port)) {
        end_port = NULL;
    }
    if (end_port) { 
    if(!cJSON_IsNumber(end_port))
    {
    goto end; //Numeric
    }
    end_port_local_var = malloc(sizeof(int));
    if(!end_port_local_var)
    {
        goto end;
    }
    *end_port_local_var = end_port->valuedouble;
    }

    // v1_network_policy_port->port
    cJSON *port = cJSON_GetObjectItemCaseSensitive(v1_network_policy_portJSON, "port");
    if (cJSON_IsNull(port)) {
        port = NULL;
    }
    if (port) { 
    port_local_nonprim = int_or_string_parseFromJSON(port); //custom
    }

    // v1_network_policy_port->protocol
    cJSON *protocol = cJSON_GetObjectItemCaseSensitive(v1_network_policy_portJSON, "protocol");
    if (cJSON_IsNull(protocol)) {
        protocol = NULL;
    }
    if (protocol) { 
    if(!cJSON_IsString(protocol) && !cJSON_IsNull(protocol))
    {
    goto end; //String
    }
    }


    if (protocol && !cJSON_IsNull(protocol)) protocol_local_str = strdup(protocol->valuestring);

    v1_network_policy_port_local_var = v1_network_policy_port_create_internal (
        end_port_local_var,
        port ? port_local_nonprim : NULL,
        protocol_local_str
        );

    if (!v1_network_policy_port_local_var) {
        goto end;
    }

    return v1_network_policy_port_local_var;
end:
    if (end_port_local_var) {
        free(end_port_local_var);
        end_port_local_var = NULL;
    }
    if (port_local_nonprim) {
        int_or_string_free(port_local_nonprim);
        port_local_nonprim = NULL;
    }
    if (protocol_local_str) {
        free(protocol_local_str);
        protocol_local_str = NULL;
    }
    return NULL;

}
