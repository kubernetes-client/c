#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_tcp_socket_action.h"



v1_tcp_socket_action_t *v1_tcp_socket_action_create(
    char *host,
    int_or_string_t *port
    ) {
    v1_tcp_socket_action_t *v1_tcp_socket_action_local_var = malloc(sizeof(v1_tcp_socket_action_t));
    if (!v1_tcp_socket_action_local_var) {
        return NULL;
    }
    v1_tcp_socket_action_local_var->host = host;
    v1_tcp_socket_action_local_var->port = port;

    return v1_tcp_socket_action_local_var;
}


void v1_tcp_socket_action_free(v1_tcp_socket_action_t *v1_tcp_socket_action) {
    if(NULL == v1_tcp_socket_action){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_tcp_socket_action->host) {
        free(v1_tcp_socket_action->host);
        v1_tcp_socket_action->host = NULL;
    }
    if (v1_tcp_socket_action->port) {
        int_or_string_free(v1_tcp_socket_action->port);
        v1_tcp_socket_action->port = NULL;
    }
    free(v1_tcp_socket_action);
}

cJSON *v1_tcp_socket_action_convertToJSON(v1_tcp_socket_action_t *v1_tcp_socket_action) {
    cJSON *item = cJSON_CreateObject();

    // v1_tcp_socket_action->host
    if(v1_tcp_socket_action->host) { 
    if(cJSON_AddStringToObject(item, "host", v1_tcp_socket_action->host) == NULL) {
    goto fail; //String
    }
     } 


    // v1_tcp_socket_action->port
    if (!v1_tcp_socket_action->port) {
        goto fail;
    }
    
    cJSON *port_local_JSON = int_or_string_convertToJSON(v1_tcp_socket_action->port);
    if(port_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "port", port_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_tcp_socket_action_t *v1_tcp_socket_action_parseFromJSON(cJSON *v1_tcp_socket_actionJSON){

    v1_tcp_socket_action_t *v1_tcp_socket_action_local_var = NULL;

    // define the local variable for v1_tcp_socket_action->port
    int_or_string_t *port_local_nonprim = NULL;

    // v1_tcp_socket_action->host
    cJSON *host = cJSON_GetObjectItemCaseSensitive(v1_tcp_socket_actionJSON, "host");
    if (host) { 
    if(!cJSON_IsString(host))
    {
    goto end; //String
    }
    }

    // v1_tcp_socket_action->port
    cJSON *port = cJSON_GetObjectItemCaseSensitive(v1_tcp_socket_actionJSON, "port");
    if (!port) {
        goto end;
    }

    
    port_local_nonprim = int_or_string_parseFromJSON(port); //custom


    v1_tcp_socket_action_local_var = v1_tcp_socket_action_create (
        host ? strdup(host->valuestring) : NULL,
        port_local_nonprim
        );

    return v1_tcp_socket_action_local_var;
end:
    if (port_local_nonprim) {
        int_or_string_free(port_local_nonprim);
        port_local_nonprim = NULL;
    }
    return NULL;

}
