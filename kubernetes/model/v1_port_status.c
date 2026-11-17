#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_port_status.h"



static v1_port_status_t *v1_port_status_create_internal(
    char *error,
    int *port,
    char *protocol
    ) {
    v1_port_status_t *v1_port_status_local_var = malloc(sizeof(v1_port_status_t));
    if (!v1_port_status_local_var) {
        return NULL;
    }
    memset(v1_port_status_local_var, 0, sizeof(v1_port_status_t));
    v1_port_status_local_var->_library_owned = 1;
    v1_port_status_local_var->error = error;
    v1_port_status_local_var->port = port;
    v1_port_status_local_var->protocol = protocol;
    return v1_port_status_local_var;
}

__attribute__((deprecated)) v1_port_status_t *v1_port_status_create(
    char *error,
    int *port,
    char *protocol
    ) {
    int *port_copy = NULL;
    if (port) {
        port_copy = malloc(sizeof(int));
        if (port_copy) *port_copy = *port;
    }
    v1_port_status_t *result = v1_port_status_create_internal (
        error,
        port_copy,
        protocol
        );
    if (!result) {
        free(port_copy);
    }
    return result;
}

void v1_port_status_free(v1_port_status_t *v1_port_status) {
    if(NULL == v1_port_status){
        return ;
    }
    if(v1_port_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_port_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_port_status->error) {
        free(v1_port_status->error);
        v1_port_status->error = NULL;
    }
    if (v1_port_status->port) {
        free(v1_port_status->port);
        v1_port_status->port = NULL;
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
    if(cJSON_AddNumberToObject(item, "port", *v1_port_status->port) == NULL) {
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

    char *error_local_str = NULL;

    // define the local variable for v1_port_status->port
    int *port_local_var = NULL;

    char *protocol_local_str = NULL;

    // v1_port_status->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(v1_port_statusJSON, "error");
    if (cJSON_IsNull(error)) {
        error = NULL;
    }
    if (error) { 
    if(!cJSON_IsString(error) && !cJSON_IsNull(error))
    {
    goto end; //String
    }
    }

    // v1_port_status->port
    cJSON *port = cJSON_GetObjectItemCaseSensitive(v1_port_statusJSON, "port");
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

    // v1_port_status->protocol
    cJSON *protocol = cJSON_GetObjectItemCaseSensitive(v1_port_statusJSON, "protocol");
    if (cJSON_IsNull(protocol)) {
        protocol = NULL;
    }
    if (!protocol) {
        goto end;
    }

    
    if(!cJSON_IsString(protocol))
    {
    goto end; //String
    }


    if (error && !cJSON_IsNull(error)) error_local_str = strdup(error->valuestring);
    if (protocol && !cJSON_IsNull(protocol)) protocol_local_str = strdup(protocol->valuestring);

    v1_port_status_local_var = v1_port_status_create_internal (
        error_local_str,
        port_local_var,
        protocol_local_str
        );

    if (!v1_port_status_local_var) {
        goto end;
    }

    return v1_port_status_local_var;
end:
    if (error_local_str) {
        free(error_local_str);
        error_local_str = NULL;
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
