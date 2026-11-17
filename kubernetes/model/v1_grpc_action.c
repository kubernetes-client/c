#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_grpc_action.h"



static v1_grpc_action_t *v1_grpc_action_create_internal(
    char *mode,
    int *port,
    char *service
    ) {
    v1_grpc_action_t *v1_grpc_action_local_var = malloc(sizeof(v1_grpc_action_t));
    if (!v1_grpc_action_local_var) {
        return NULL;
    }
    memset(v1_grpc_action_local_var, 0, sizeof(v1_grpc_action_t));
    v1_grpc_action_local_var->_library_owned = 1;
    v1_grpc_action_local_var->mode = mode;
    v1_grpc_action_local_var->port = port;
    v1_grpc_action_local_var->service = service;
    return v1_grpc_action_local_var;
}

__attribute__((deprecated)) v1_grpc_action_t *v1_grpc_action_create(
    char *mode,
    int *port,
    char *service
    ) {
    int *port_copy = NULL;
    if (port) {
        port_copy = malloc(sizeof(int));
        if (port_copy) *port_copy = *port;
    }
    v1_grpc_action_t *result = v1_grpc_action_create_internal (
        mode,
        port_copy,
        service
        );
    if (!result) {
        free(port_copy);
    }
    return result;
}

void v1_grpc_action_free(v1_grpc_action_t *v1_grpc_action) {
    if(NULL == v1_grpc_action){
        return ;
    }
    if(v1_grpc_action->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_grpc_action_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_grpc_action->mode) {
        free(v1_grpc_action->mode);
        v1_grpc_action->mode = NULL;
    }
    if (v1_grpc_action->port) {
        free(v1_grpc_action->port);
        v1_grpc_action->port = NULL;
    }
    if (v1_grpc_action->service) {
        free(v1_grpc_action->service);
        v1_grpc_action->service = NULL;
    }
    free(v1_grpc_action);
}

cJSON *v1_grpc_action_convertToJSON(v1_grpc_action_t *v1_grpc_action) {
    cJSON *item = cJSON_CreateObject();

    // v1_grpc_action->mode
    if(v1_grpc_action->mode) {
    if(cJSON_AddStringToObject(item, "mode", v1_grpc_action->mode) == NULL) {
    goto fail; //String
    }
    }


    // v1_grpc_action->port
    if (!v1_grpc_action->port) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "port", *v1_grpc_action->port) == NULL) {
    goto fail; //Numeric
    }


    // v1_grpc_action->service
    if(v1_grpc_action->service) {
    if(cJSON_AddStringToObject(item, "service", v1_grpc_action->service) == NULL) {
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

v1_grpc_action_t *v1_grpc_action_parseFromJSON(cJSON *v1_grpc_actionJSON){

    v1_grpc_action_t *v1_grpc_action_local_var = NULL;

    char *mode_local_str = NULL;

    // define the local variable for v1_grpc_action->port
    int *port_local_var = NULL;

    char *service_local_str = NULL;

    // v1_grpc_action->mode
    cJSON *mode = cJSON_GetObjectItemCaseSensitive(v1_grpc_actionJSON, "mode");
    if (cJSON_IsNull(mode)) {
        mode = NULL;
    }
    if (mode) { 
    if(!cJSON_IsString(mode) && !cJSON_IsNull(mode))
    {
    goto end; //String
    }
    }

    // v1_grpc_action->port
    cJSON *port = cJSON_GetObjectItemCaseSensitive(v1_grpc_actionJSON, "port");
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

    // v1_grpc_action->service
    cJSON *service = cJSON_GetObjectItemCaseSensitive(v1_grpc_actionJSON, "service");
    if (cJSON_IsNull(service)) {
        service = NULL;
    }
    if (service) { 
    if(!cJSON_IsString(service) && !cJSON_IsNull(service))
    {
    goto end; //String
    }
    }


    if (mode && !cJSON_IsNull(mode)) mode_local_str = strdup(mode->valuestring);
    if (service && !cJSON_IsNull(service)) service_local_str = strdup(service->valuestring);

    v1_grpc_action_local_var = v1_grpc_action_create_internal (
        mode_local_str,
        port_local_var,
        service_local_str
        );

    if (!v1_grpc_action_local_var) {
        goto end;
    }

    return v1_grpc_action_local_var;
end:
    if (mode_local_str) {
        free(mode_local_str);
        mode_local_str = NULL;
    }
    if (port_local_var) {
        free(port_local_var);
        port_local_var = NULL;
    }
    if (service_local_str) {
        free(service_local_str);
        service_local_str = NULL;
    }
    return NULL;

}
