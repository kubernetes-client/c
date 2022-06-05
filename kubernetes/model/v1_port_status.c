#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_port_status.h"



v1_port_status_t *v1_port_status_create(
    char *error,
    int port,
    char *protocol
    ) {
    v1_port_status_t *v1_port_status_local_var = malloc(sizeof(v1_port_status_t));
    if (!v1_port_status_local_var) {
        return NULL;
    }
    v1_port_status_local_var->error = error;
    v1_port_status_local_var->port = port;
    v1_port_status_local_var->protocol = protocol;

    return v1_port_status_local_var;
}


void v1_port_status_free(v1_port_status_t *v1_port_status) {
    if(NULL == v1_port_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_port_status->error) {
        free(v1_port_status->error);
        v1_port_status->error = NULL;
    }
    if (v1_port_status->protocol) {
        free(v1_port_status->protocol);
        v1_port_status->protocol = NULL;
    }
    free(v1_port_status);
}

cJSON *v1_port_status_convertToJSON(v1_port_status_t *v1_port_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_port_status->error
    if(v1_port_status->error) {
    if(cJSON_AddStringToObject(item, "error", v1_port_status->error) == NULL) {
    goto fail; //String
    }
    }


    // v1_port_status->port
    if (!v1_port_status->port) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "port", v1_port_status->port) == NULL) {
    goto fail; //Numeric
    }


    // v1_port_status->protocol
    if (!v1_port_status->protocol) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "protocol", v1_port_status->protocol) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_port_status_t *v1_port_status_parseFromJSON(cJSON *v1_port_statusJSON){

    v1_port_status_t *v1_port_status_local_var = NULL;

    // v1_port_status->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(v1_port_statusJSON, "error");
    if (error) { 
    if(!cJSON_IsString(error))
    {
    goto end; //String
    }
    }

    // v1_port_status->port
    cJSON *port = cJSON_GetObjectItemCaseSensitive(v1_port_statusJSON, "port");
    if (!port) {
        goto end;
    }

    
    if(!cJSON_IsNumber(port))
    {
    goto end; //Numeric
    }

    // v1_port_status->protocol
    cJSON *protocol = cJSON_GetObjectItemCaseSensitive(v1_port_statusJSON, "protocol");
    if (!protocol) {
        goto end;
    }

    
    if(!cJSON_IsString(protocol))
    {
    goto end; //String
    }


    v1_port_status_local_var = v1_port_status_create (
        error ? strdup(error->valuestring) : NULL,
        port->valuedouble,
        strdup(protocol->valuestring)
        );

    return v1_port_status_local_var;
end:
    return NULL;

}
