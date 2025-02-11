#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "discovery_v1_endpoint_port.h"



static discovery_v1_endpoint_port_t *discovery_v1_endpoint_port_create_internal(
    char *app_protocol,
    char *name,
    int port,
    char *protocol
    ) {
    discovery_v1_endpoint_port_t *discovery_v1_endpoint_port_local_var = malloc(sizeof(discovery_v1_endpoint_port_t));
    if (!discovery_v1_endpoint_port_local_var) {
        return NULL;
    }
    discovery_v1_endpoint_port_local_var->app_protocol = app_protocol;
    discovery_v1_endpoint_port_local_var->name = name;
    discovery_v1_endpoint_port_local_var->port = port;
    discovery_v1_endpoint_port_local_var->protocol = protocol;

    discovery_v1_endpoint_port_local_var->_library_owned = 1;
    return discovery_v1_endpoint_port_local_var;
}

__attribute__((deprecated)) discovery_v1_endpoint_port_t *discovery_v1_endpoint_port_create(
    char *app_protocol,
    char *name,
    int port,
    char *protocol
    ) {
    return discovery_v1_endpoint_port_create_internal (
        app_protocol,
        name,
        port,
        protocol
        );
}

void discovery_v1_endpoint_port_free(discovery_v1_endpoint_port_t *discovery_v1_endpoint_port) {
    if(NULL == discovery_v1_endpoint_port){
        return ;
    }
    if(discovery_v1_endpoint_port->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "discovery_v1_endpoint_port_free");
        return ;
    }
    listEntry_t *listEntry;
    if (discovery_v1_endpoint_port->app_protocol) {
        free(discovery_v1_endpoint_port->app_protocol);
        discovery_v1_endpoint_port->app_protocol = NULL;
    }
    if (discovery_v1_endpoint_port->name) {
        free(discovery_v1_endpoint_port->name);
        discovery_v1_endpoint_port->name = NULL;
    }
    if (discovery_v1_endpoint_port->protocol) {
        free(discovery_v1_endpoint_port->protocol);
        discovery_v1_endpoint_port->protocol = NULL;
    }
    free(discovery_v1_endpoint_port);
}

cJSON *discovery_v1_endpoint_port_convertToJSON(discovery_v1_endpoint_port_t *discovery_v1_endpoint_port) {
    cJSON *item = cJSON_CreateObject();

    // discovery_v1_endpoint_port->app_protocol
    if(discovery_v1_endpoint_port->app_protocol) {
    if(cJSON_AddStringToObject(item, "appProtocol", discovery_v1_endpoint_port->app_protocol) == NULL) {
    goto fail; //String
    }
    }


    // discovery_v1_endpoint_port->name
    if(discovery_v1_endpoint_port->name) {
    if(cJSON_AddStringToObject(item, "name", discovery_v1_endpoint_port->name) == NULL) {
    goto fail; //String
    }
    }


    // discovery_v1_endpoint_port->port
    if(discovery_v1_endpoint_port->port) {
    if(cJSON_AddNumberToObject(item, "port", discovery_v1_endpoint_port->port) == NULL) {
    goto fail; //Numeric
    }
    }


    // discovery_v1_endpoint_port->protocol
    if(discovery_v1_endpoint_port->protocol) {
    if(cJSON_AddStringToObject(item, "protocol", discovery_v1_endpoint_port->protocol) == NULL) {
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

discovery_v1_endpoint_port_t *discovery_v1_endpoint_port_parseFromJSON(cJSON *discovery_v1_endpoint_portJSON){

    discovery_v1_endpoint_port_t *discovery_v1_endpoint_port_local_var = NULL;

    // discovery_v1_endpoint_port->app_protocol
    cJSON *app_protocol = cJSON_GetObjectItemCaseSensitive(discovery_v1_endpoint_portJSON, "appProtocol");
    if (cJSON_IsNull(app_protocol)) {
        app_protocol = NULL;
    }
    if (app_protocol) { 
    if(!cJSON_IsString(app_protocol) && !cJSON_IsNull(app_protocol))
    {
    goto end; //String
    }
    }

    // discovery_v1_endpoint_port->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(discovery_v1_endpoint_portJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // discovery_v1_endpoint_port->port
    cJSON *port = cJSON_GetObjectItemCaseSensitive(discovery_v1_endpoint_portJSON, "port");
    if (cJSON_IsNull(port)) {
        port = NULL;
    }
    if (port) { 
    if(!cJSON_IsNumber(port))
    {
    goto end; //Numeric
    }
    }

    // discovery_v1_endpoint_port->protocol
    cJSON *protocol = cJSON_GetObjectItemCaseSensitive(discovery_v1_endpoint_portJSON, "protocol");
    if (cJSON_IsNull(protocol)) {
        protocol = NULL;
    }
    if (protocol) { 
    if(!cJSON_IsString(protocol) && !cJSON_IsNull(protocol))
    {
    goto end; //String
    }
    }


    discovery_v1_endpoint_port_local_var = discovery_v1_endpoint_port_create_internal (
        app_protocol && !cJSON_IsNull(app_protocol) ? strdup(app_protocol->valuestring) : NULL,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        port ? port->valuedouble : 0,
        protocol && !cJSON_IsNull(protocol) ? strdup(protocol->valuestring) : NULL
        );

    return discovery_v1_endpoint_port_local_var;
end:
    return NULL;

}
