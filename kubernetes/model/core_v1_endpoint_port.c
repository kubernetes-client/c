#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "core_v1_endpoint_port.h"



static core_v1_endpoint_port_t *core_v1_endpoint_port_create_internal(
    char *app_protocol,
    char *name,
    int port,
    char *protocol
    ) {
    core_v1_endpoint_port_t *core_v1_endpoint_port_local_var = malloc(sizeof(core_v1_endpoint_port_t));
    if (!core_v1_endpoint_port_local_var) {
        return NULL;
    }
    core_v1_endpoint_port_local_var->app_protocol = app_protocol;
    core_v1_endpoint_port_local_var->name = name;
    core_v1_endpoint_port_local_var->port = port;
    core_v1_endpoint_port_local_var->protocol = protocol;

    core_v1_endpoint_port_local_var->_library_owned = 1;
    return core_v1_endpoint_port_local_var;
}

__attribute__((deprecated)) core_v1_endpoint_port_t *core_v1_endpoint_port_create(
    char *app_protocol,
    char *name,
    int port,
    char *protocol
    ) {
    return core_v1_endpoint_port_create_internal (
        app_protocol,
        name,
        port,
        protocol
        );
}

void core_v1_endpoint_port_free(core_v1_endpoint_port_t *core_v1_endpoint_port) {
    if(NULL == core_v1_endpoint_port){
        return ;
    }
    if(core_v1_endpoint_port->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "core_v1_endpoint_port_free");
        return ;
    }
    listEntry_t *listEntry;
    if (core_v1_endpoint_port->app_protocol) {
        free(core_v1_endpoint_port->app_protocol);
        core_v1_endpoint_port->app_protocol = NULL;
    }
    if (core_v1_endpoint_port->name) {
        free(core_v1_endpoint_port->name);
        core_v1_endpoint_port->name = NULL;
    }
    if (core_v1_endpoint_port->protocol) {
        free(core_v1_endpoint_port->protocol);
        core_v1_endpoint_port->protocol = NULL;
    }
    free(core_v1_endpoint_port);
}

cJSON *core_v1_endpoint_port_convertToJSON(core_v1_endpoint_port_t *core_v1_endpoint_port) {
    cJSON *item = cJSON_CreateObject();

    // core_v1_endpoint_port->app_protocol
    if(core_v1_endpoint_port->app_protocol) {
    if(cJSON_AddStringToObject(item, "appProtocol", core_v1_endpoint_port->app_protocol) == NULL) {
    goto fail; //String
    }
    }


    // core_v1_endpoint_port->name
    if(core_v1_endpoint_port->name) {
    if(cJSON_AddStringToObject(item, "name", core_v1_endpoint_port->name) == NULL) {
    goto fail; //String
    }
    }


    // core_v1_endpoint_port->port
    if (!core_v1_endpoint_port->port) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "port", core_v1_endpoint_port->port) == NULL) {
    goto fail; //Numeric
    }


    // core_v1_endpoint_port->protocol
    if(core_v1_endpoint_port->protocol) {
    if(cJSON_AddStringToObject(item, "protocol", core_v1_endpoint_port->protocol) == NULL) {
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

core_v1_endpoint_port_t *core_v1_endpoint_port_parseFromJSON(cJSON *core_v1_endpoint_portJSON){

    core_v1_endpoint_port_t *core_v1_endpoint_port_local_var = NULL;

    // core_v1_endpoint_port->app_protocol
    cJSON *app_protocol = cJSON_GetObjectItemCaseSensitive(core_v1_endpoint_portJSON, "appProtocol");
    if (cJSON_IsNull(app_protocol)) {
        app_protocol = NULL;
    }
    if (app_protocol) { 
    if(!cJSON_IsString(app_protocol) && !cJSON_IsNull(app_protocol))
    {
    goto end; //String
    }
    }

    // core_v1_endpoint_port->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(core_v1_endpoint_portJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // core_v1_endpoint_port->port
    cJSON *port = cJSON_GetObjectItemCaseSensitive(core_v1_endpoint_portJSON, "port");
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

    // core_v1_endpoint_port->protocol
    cJSON *protocol = cJSON_GetObjectItemCaseSensitive(core_v1_endpoint_portJSON, "protocol");
    if (cJSON_IsNull(protocol)) {
        protocol = NULL;
    }
    if (protocol) { 
    if(!cJSON_IsString(protocol) && !cJSON_IsNull(protocol))
    {
    goto end; //String
    }
    }


    core_v1_endpoint_port_local_var = core_v1_endpoint_port_create_internal (
        app_protocol && !cJSON_IsNull(app_protocol) ? strdup(app_protocol->valuestring) : NULL,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        port->valuedouble,
        protocol && !cJSON_IsNull(protocol) ? strdup(protocol->valuestring) : NULL
        );

    return core_v1_endpoint_port_local_var;
end:
    return NULL;

}
