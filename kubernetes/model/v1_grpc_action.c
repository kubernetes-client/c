#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_grpc_action.h"



v1_grpc_action_t *v1_grpc_action_create(
    int port,
    char *service
    ) {
    v1_grpc_action_t *v1_grpc_action_local_var = malloc(sizeof(v1_grpc_action_t));
    if (!v1_grpc_action_local_var) {
        return NULL;
    }
    v1_grpc_action_local_var->port = port;
    v1_grpc_action_local_var->service = service;

    return v1_grpc_action_local_var;
}


void v1_grpc_action_free(v1_grpc_action_t *v1_grpc_action) {
    if(NULL == v1_grpc_action){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_grpc_action->service) {
        free(v1_grpc_action->service);
        v1_grpc_action->service = NULL;
    }
    free(v1_grpc_action);
}

cJSON *v1_grpc_action_convertToJSON(v1_grpc_action_t *v1_grpc_action) {
    cJSON *item = cJSON_CreateObject();

    // v1_grpc_action->port
    if (!v1_grpc_action->port) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "port", v1_grpc_action->port) == NULL) {
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

    // v1_grpc_action->port
    cJSON *port = cJSON_GetObjectItemCaseSensitive(v1_grpc_actionJSON, "port");
    if (!port) {
        goto end;
    }

    
    if(!cJSON_IsNumber(port))
    {
    goto end; //Numeric
    }

    // v1_grpc_action->service
    cJSON *service = cJSON_GetObjectItemCaseSensitive(v1_grpc_actionJSON, "service");
    if (service) { 
    if(!cJSON_IsString(service))
    {
    goto end; //String
    }
    }


    v1_grpc_action_local_var = v1_grpc_action_create (
        port->valuedouble,
        service ? strdup(service->valuestring) : NULL
        );

    return v1_grpc_action_local_var;
end:
    return NULL;

}
