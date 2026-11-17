#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "core_v1_endpoint_port.h"



static core_v1_endpoint_port_t *core_v1_endpoint_port_create_internal(
    char *app_protocol,
    char *name,
    int *port,
    char *protocol
    ) {
    core_v1_endpoint_port_t *core_v1_endpoint_port_local_var = malloc(sizeof(core_v1_endpoint_port_t));
    if (!core_v1_endpoint_port_local_var) {
        return NULL;
    }
    memset(core_v1_endpoint_port_local_var, 0, sizeof(core_v1_endpoint_port_t));
    core_v1_endpoint_port_local_var->_library_owned = 1;
    core_v1_endpoint_port_local_var->app_protocol = app_protocol;
    core_v1_endpoint_port_local_var->name = name;
    core_v1_endpoint_port_local_var->port = port;
    core_v1_endpoint_port_local_var->protocol = protocol;
    return core_v1_endpoint_port_local_var;
}

__attribute__((deprecated)) core_v1_endpoint_port_t *core_v1_endpoint_port_create(
    char *app_protocol,
    char *name,
    int *port,
    char *protocol
    ) {
    int *port_copy = NULL;
    if (port) {
        port_copy = malloc(sizeof(int));
        if (port_copy) *port_copy = *port;
    }
    core_v1_endpoint_port_t *result = core_v1_endpoint_port_create_internal (
        app_protocol,
        name,
        port_copy,
        protocol
        );
    if (!result) {
        free(port_copy);
    }
    return result;
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
    if (core_v1_endpoint_port->port) {
        free(core_v1_endpoint_port->port);
        core_v1_endpoint_port->port = NULL;
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
    if(cJSON_AddNumberToObject(item, "port", *core_v1_endpoint_port->port) == NULL) {
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

    char *app_protocol_local_str = NULL;

    char *name_local_str = NULL;

    // define the local variable for core_v1_endpoint_port->port
    int *port_local_var = NULL;

    char *protocol_local_str = NULL;

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
    port_local_var = malloc(sizeof(int));
    if(!port_local_var)
    {
        goto end;
    }
    *port_local_var = port->valuedouble;

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


    if (app_protocol && !cJSON_IsNull(app_protocol)) app_protocol_local_str = strdup(app_protocol->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (protocol && !cJSON_IsNull(protocol)) protocol_local_str = strdup(protocol->valuestring);

    core_v1_endpoint_port_local_var = core_v1_endpoint_port_create_internal (
        app_protocol_local_str,
        name_local_str,
        port_local_var,
        protocol_local_str
        );

    if (!core_v1_endpoint_port_local_var) {
        goto end;
    }

    return core_v1_endpoint_port_local_var;
end:
    if (app_protocol_local_str) {
        free(app_protocol_local_str);
        app_protocol_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (port_local_var) {
        free(port_local_var);
        port_local_var = NULL;
    }
    if (protocol_local_str) {
        free(protocol_local_str);
        protocol_local_str = NULL;
    }
    return NULL;

}
