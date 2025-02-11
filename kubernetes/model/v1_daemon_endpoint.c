#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_daemon_endpoint.h"



static v1_daemon_endpoint_t *v1_daemon_endpoint_create_internal(
    int port
    ) {
    v1_daemon_endpoint_t *v1_daemon_endpoint_local_var = malloc(sizeof(v1_daemon_endpoint_t));
    if (!v1_daemon_endpoint_local_var) {
        return NULL;
    }
    v1_daemon_endpoint_local_var->port = port;

    v1_daemon_endpoint_local_var->_library_owned = 1;
    return v1_daemon_endpoint_local_var;
}

__attribute__((deprecated)) v1_daemon_endpoint_t *v1_daemon_endpoint_create(
    int port
    ) {
    return v1_daemon_endpoint_create_internal (
        port
        );
}

void v1_daemon_endpoint_free(v1_daemon_endpoint_t *v1_daemon_endpoint) {
    if(NULL == v1_daemon_endpoint){
        return ;
    }
    if(v1_daemon_endpoint->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_daemon_endpoint_free");
        return ;
    }
    listEntry_t *listEntry;
    free(v1_daemon_endpoint);
}

cJSON *v1_daemon_endpoint_convertToJSON(v1_daemon_endpoint_t *v1_daemon_endpoint) {
    cJSON *item = cJSON_CreateObject();

    // v1_daemon_endpoint->port
    if (!v1_daemon_endpoint->port) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "Port", v1_daemon_endpoint->port) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_daemon_endpoint_t *v1_daemon_endpoint_parseFromJSON(cJSON *v1_daemon_endpointJSON){

    v1_daemon_endpoint_t *v1_daemon_endpoint_local_var = NULL;

    // v1_daemon_endpoint->port
    cJSON *port = cJSON_GetObjectItemCaseSensitive(v1_daemon_endpointJSON, "Port");
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


    v1_daemon_endpoint_local_var = v1_daemon_endpoint_create_internal (
        port->valuedouble
        );

    return v1_daemon_endpoint_local_var;
end:
    return NULL;

}
