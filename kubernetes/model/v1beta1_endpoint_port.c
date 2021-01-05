#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_endpoint_port.h"



v1beta1_endpoint_port_t *v1beta1_endpoint_port_create(
    char *app_protocol,
    char *name,
    int port,
    char *protocol
    ) {
    v1beta1_endpoint_port_t *v1beta1_endpoint_port_local_var = malloc(sizeof(v1beta1_endpoint_port_t));
    if (!v1beta1_endpoint_port_local_var) {
        return NULL;
    }
    v1beta1_endpoint_port_local_var->app_protocol = app_protocol;
    v1beta1_endpoint_port_local_var->name = name;
    v1beta1_endpoint_port_local_var->port = port;
    v1beta1_endpoint_port_local_var->protocol = protocol;

    return v1beta1_endpoint_port_local_var;
}


void v1beta1_endpoint_port_free(v1beta1_endpoint_port_t *v1beta1_endpoint_port) {
    if(NULL == v1beta1_endpoint_port){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_endpoint_port->app_protocol) {
        free(v1beta1_endpoint_port->app_protocol);
        v1beta1_endpoint_port->app_protocol = NULL;
    }
    if (v1beta1_endpoint_port->name) {
        free(v1beta1_endpoint_port->name);
        v1beta1_endpoint_port->name = NULL;
    }
    if (v1beta1_endpoint_port->protocol) {
        free(v1beta1_endpoint_port->protocol);
        v1beta1_endpoint_port->protocol = NULL;
    }
    free(v1beta1_endpoint_port);
}

cJSON *v1beta1_endpoint_port_convertToJSON(v1beta1_endpoint_port_t *v1beta1_endpoint_port) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_endpoint_port->app_protocol
    if(v1beta1_endpoint_port->app_protocol) { 
    if(cJSON_AddStringToObject(item, "appProtocol", v1beta1_endpoint_port->app_protocol) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_endpoint_port->name
    if(v1beta1_endpoint_port->name) { 
    if(cJSON_AddStringToObject(item, "name", v1beta1_endpoint_port->name) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_endpoint_port->port
    if(v1beta1_endpoint_port->port) { 
    if(cJSON_AddNumberToObject(item, "port", v1beta1_endpoint_port->port) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1beta1_endpoint_port->protocol
    if(v1beta1_endpoint_port->protocol) { 
    if(cJSON_AddStringToObject(item, "protocol", v1beta1_endpoint_port->protocol) == NULL) {
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

v1beta1_endpoint_port_t *v1beta1_endpoint_port_parseFromJSON(cJSON *v1beta1_endpoint_portJSON){

    v1beta1_endpoint_port_t *v1beta1_endpoint_port_local_var = NULL;

    // v1beta1_endpoint_port->app_protocol
    cJSON *app_protocol = cJSON_GetObjectItemCaseSensitive(v1beta1_endpoint_portJSON, "appProtocol");
    if (app_protocol) { 
    if(!cJSON_IsString(app_protocol))
    {
    goto end; //String
    }
    }

    // v1beta1_endpoint_port->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1beta1_endpoint_portJSON, "name");
    if (name) { 
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }
    }

    // v1beta1_endpoint_port->port
    cJSON *port = cJSON_GetObjectItemCaseSensitive(v1beta1_endpoint_portJSON, "port");
    if (port) { 
    if(!cJSON_IsNumber(port))
    {
    goto end; //Numeric
    }
    }

    // v1beta1_endpoint_port->protocol
    cJSON *protocol = cJSON_GetObjectItemCaseSensitive(v1beta1_endpoint_portJSON, "protocol");
    if (protocol) { 
    if(!cJSON_IsString(protocol))
    {
    goto end; //String
    }
    }


    v1beta1_endpoint_port_local_var = v1beta1_endpoint_port_create (
        app_protocol ? strdup(app_protocol->valuestring) : NULL,
        name ? strdup(name->valuestring) : NULL,
        port ? port->valuedouble : 0,
        protocol ? strdup(protocol->valuestring) : NULL
        );

    return v1beta1_endpoint_port_local_var;
end:
    return NULL;

}
