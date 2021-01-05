#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_container_port.h"



v1_container_port_t *v1_container_port_create(
    int container_port,
    char *host_ip,
    int host_port,
    char *name,
    char *protocol
    ) {
    v1_container_port_t *v1_container_port_local_var = malloc(sizeof(v1_container_port_t));
    if (!v1_container_port_local_var) {
        return NULL;
    }
    v1_container_port_local_var->container_port = container_port;
    v1_container_port_local_var->host_ip = host_ip;
    v1_container_port_local_var->host_port = host_port;
    v1_container_port_local_var->name = name;
    v1_container_port_local_var->protocol = protocol;

    return v1_container_port_local_var;
}


void v1_container_port_free(v1_container_port_t *v1_container_port) {
    if(NULL == v1_container_port){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_container_port->host_ip) {
        free(v1_container_port->host_ip);
        v1_container_port->host_ip = NULL;
    }
    if (v1_container_port->name) {
        free(v1_container_port->name);
        v1_container_port->name = NULL;
    }
    if (v1_container_port->protocol) {
        free(v1_container_port->protocol);
        v1_container_port->protocol = NULL;
    }
    free(v1_container_port);
}

cJSON *v1_container_port_convertToJSON(v1_container_port_t *v1_container_port) {
    cJSON *item = cJSON_CreateObject();

    // v1_container_port->container_port
    if (!v1_container_port->container_port) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "containerPort", v1_container_port->container_port) == NULL) {
    goto fail; //Numeric
    }


    // v1_container_port->host_ip
    if(v1_container_port->host_ip) { 
    if(cJSON_AddStringToObject(item, "hostIP", v1_container_port->host_ip) == NULL) {
    goto fail; //String
    }
     } 


    // v1_container_port->host_port
    if(v1_container_port->host_port) { 
    if(cJSON_AddNumberToObject(item, "hostPort", v1_container_port->host_port) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_container_port->name
    if(v1_container_port->name) { 
    if(cJSON_AddStringToObject(item, "name", v1_container_port->name) == NULL) {
    goto fail; //String
    }
     } 


    // v1_container_port->protocol
    if(v1_container_port->protocol) { 
    if(cJSON_AddStringToObject(item, "protocol", v1_container_port->protocol) == NULL) {
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

v1_container_port_t *v1_container_port_parseFromJSON(cJSON *v1_container_portJSON){

    v1_container_port_t *v1_container_port_local_var = NULL;

    // v1_container_port->container_port
    cJSON *container_port = cJSON_GetObjectItemCaseSensitive(v1_container_portJSON, "containerPort");
    if (!container_port) {
        goto end;
    }

    
    if(!cJSON_IsNumber(container_port))
    {
    goto end; //Numeric
    }

    // v1_container_port->host_ip
    cJSON *host_ip = cJSON_GetObjectItemCaseSensitive(v1_container_portJSON, "hostIP");
    if (host_ip) { 
    if(!cJSON_IsString(host_ip))
    {
    goto end; //String
    }
    }

    // v1_container_port->host_port
    cJSON *host_port = cJSON_GetObjectItemCaseSensitive(v1_container_portJSON, "hostPort");
    if (host_port) { 
    if(!cJSON_IsNumber(host_port))
    {
    goto end; //Numeric
    }
    }

    // v1_container_port->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_container_portJSON, "name");
    if (name) { 
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }
    }

    // v1_container_port->protocol
    cJSON *protocol = cJSON_GetObjectItemCaseSensitive(v1_container_portJSON, "protocol");
    if (protocol) { 
    if(!cJSON_IsString(protocol))
    {
    goto end; //String
    }
    }


    v1_container_port_local_var = v1_container_port_create (
        container_port->valuedouble,
        host_ip ? strdup(host_ip->valuestring) : NULL,
        host_port ? host_port->valuedouble : 0,
        name ? strdup(name->valuestring) : NULL,
        protocol ? strdup(protocol->valuestring) : NULL
        );

    return v1_container_port_local_var;
end:
    return NULL;

}
