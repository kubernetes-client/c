#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_service_port.h"



static v1_service_port_t *v1_service_port_create_internal(
    char *app_protocol,
    char *name,
    int *node_port,
    int *port,
    char *protocol,
    int_or_string_t *target_port
    ) {
    v1_service_port_t *v1_service_port_local_var = malloc(sizeof(v1_service_port_t));
    if (!v1_service_port_local_var) {
        return NULL;
    }
    memset(v1_service_port_local_var, 0, sizeof(v1_service_port_t));
    v1_service_port_local_var->_library_owned = 1;
    v1_service_port_local_var->app_protocol = app_protocol;
    v1_service_port_local_var->name = name;
    v1_service_port_local_var->node_port = node_port;
    v1_service_port_local_var->port = port;
    v1_service_port_local_var->protocol = protocol;
    v1_service_port_local_var->target_port = target_port;
    return v1_service_port_local_var;
}

__attribute__((deprecated)) v1_service_port_t *v1_service_port_create(
    char *app_protocol,
    char *name,
    int *node_port,
    int *port,
    char *protocol,
    int_or_string_t *target_port
    ) {
    int *node_port_copy = NULL;
    if (node_port) {
        node_port_copy = malloc(sizeof(int));
        if (node_port_copy) *node_port_copy = *node_port;
    }
    int *port_copy = NULL;
    if (port) {
        port_copy = malloc(sizeof(int));
        if (port_copy) *port_copy = *port;
    }
    v1_service_port_t *result = v1_service_port_create_internal (
        app_protocol,
        name,
        node_port_copy,
        port_copy,
        protocol,
        target_port
        );
    if (!result) {
        free(node_port_copy);
        free(port_copy);
    }
    return result;
}

void v1_service_port_free(v1_service_port_t *v1_service_port) {
    if(NULL == v1_service_port){
        return ;
    }
    if(v1_service_port->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_service_port_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_service_port->app_protocol) {
        free(v1_service_port->app_protocol);
        v1_service_port->app_protocol = NULL;
    }
    if (v1_service_port->name) {
        free(v1_service_port->name);
        v1_service_port->name = NULL;
    }
    if (v1_service_port->node_port) {
        free(v1_service_port->node_port);
        v1_service_port->node_port = NULL;
    }
    if (v1_service_port->port) {
        free(v1_service_port->port);
        v1_service_port->port = NULL;
    }
    if (v1_service_port->protocol) {
        free(v1_service_port->protocol);
        v1_service_port->protocol = NULL;
    }
    if (v1_service_port->target_port) {
        int_or_string_free(v1_service_port->target_port);
        v1_service_port->target_port = NULL;
    }
    free(v1_service_port);
}

cJSON *v1_service_port_convertToJSON(v1_service_port_t *v1_service_port) {
    cJSON *item = cJSON_CreateObject();

    // v1_service_port->app_protocol
    if(v1_service_port->app_protocol) {
    if(cJSON_AddStringToObject(item, "appProtocol", v1_service_port->app_protocol) == NULL) {
    goto fail; //String
    }
    }


    // v1_service_port->name
    if(v1_service_port->name) {
    if(cJSON_AddStringToObject(item, "name", v1_service_port->name) == NULL) {
    goto fail; //String
    }
    }


    // v1_service_port->node_port
    if(v1_service_port->node_port) {
    if(cJSON_AddNumberToObject(item, "nodePort", *v1_service_port->node_port) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_service_port->port
    if (!v1_service_port->port) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "port", *v1_service_port->port) == NULL) {
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
    cJSON *target_port_local_JSON = int_or_string_convertToJSON(v1_service_port->target_port);
    if(target_port_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "targetPort", target_port_local_JSON);
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

    char *app_protocol_local_str = NULL;

    char *name_local_str = NULL;

    // define the local variable for v1_service_port->node_port
    int *node_port_local_var = NULL;

    // define the local variable for v1_service_port->port
    int *port_local_var = NULL;

    char *protocol_local_str = NULL;

    // define the local variable for v1_service_port->target_port
    int_or_string_t *target_port_local_nonprim = NULL;

    // v1_service_port->app_protocol
    cJSON *app_protocol = cJSON_GetObjectItemCaseSensitive(v1_service_portJSON, "appProtocol");
    if (cJSON_IsNull(app_protocol)) {
        app_protocol = NULL;
    }
    if (app_protocol) { 
    if(!cJSON_IsString(app_protocol) && !cJSON_IsNull(app_protocol))
    {
    goto end; //String
    }
    }

    // v1_service_port->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_service_portJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // v1_service_port->node_port
    cJSON *node_port = cJSON_GetObjectItemCaseSensitive(v1_service_portJSON, "nodePort");
    if (cJSON_IsNull(node_port)) {
        node_port = NULL;
    }
    if (node_port) { 
    if(!cJSON_IsNumber(node_port))
    {
    goto end; //Numeric
    }
    node_port_local_var = malloc(sizeof(int));
    if(!node_port_local_var)
    {
        goto end;
    }
    *node_port_local_var = node_port->valuedouble;
    }

    // v1_service_port->port
    cJSON *port = cJSON_GetObjectItemCaseSensitive(v1_service_portJSON, "port");
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

    // v1_service_port->protocol
    cJSON *protocol = cJSON_GetObjectItemCaseSensitive(v1_service_portJSON, "protocol");
    if (cJSON_IsNull(protocol)) {
        protocol = NULL;
    }
    if (protocol) { 
    if(!cJSON_IsString(protocol) && !cJSON_IsNull(protocol))
    {
    goto end; //String
    }
    }

    // v1_service_port->target_port
    cJSON *target_port = cJSON_GetObjectItemCaseSensitive(v1_service_portJSON, "targetPort");
    if (cJSON_IsNull(target_port)) {
        target_port = NULL;
    }
    if (target_port) { 
    target_port_local_nonprim = int_or_string_parseFromJSON(target_port); //custom
    }


    if (app_protocol && !cJSON_IsNull(app_protocol)) app_protocol_local_str = strdup(app_protocol->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (protocol && !cJSON_IsNull(protocol)) protocol_local_str = strdup(protocol->valuestring);

    v1_service_port_local_var = v1_service_port_create_internal (
        app_protocol_local_str,
        name_local_str,
        node_port_local_var,
        port_local_var,
        protocol_local_str,
        target_port ? target_port_local_nonprim : NULL
        );

    if (!v1_service_port_local_var) {
        goto end;
    }

    return v1_service_port_local_var;
end:
    if (app_protocol_local_str) {
        free(app_protocol_local_str);
        app_protocol_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (node_port_local_var) {
        free(node_port_local_var);
        node_port_local_var = NULL;
    }
    if (port_local_var) {
        free(port_local_var);
        port_local_var = NULL;
    }
    if (protocol_local_str) {
        free(protocol_local_str);
        protocol_local_str = NULL;
    }
    if (target_port_local_nonprim) {
        int_or_string_free(target_port_local_nonprim);
        target_port_local_nonprim = NULL;
    }
    return NULL;

}
