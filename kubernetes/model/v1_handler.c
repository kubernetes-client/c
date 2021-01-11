#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_handler.h"



v1_handler_t *v1_handler_create(
    v1_exec_action_t *exec,
    v1_http_get_action_t *http_get,
    v1_tcp_socket_action_t *tcp_socket
    ) {
    v1_handler_t *v1_handler_local_var = malloc(sizeof(v1_handler_t));
    if (!v1_handler_local_var) {
        return NULL;
    }
    v1_handler_local_var->exec = exec;
    v1_handler_local_var->http_get = http_get;
    v1_handler_local_var->tcp_socket = tcp_socket;

    return v1_handler_local_var;
}


void v1_handler_free(v1_handler_t *v1_handler) {
    if(NULL == v1_handler){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_handler->exec) {
        v1_exec_action_free(v1_handler->exec);
        v1_handler->exec = NULL;
    }
    if (v1_handler->http_get) {
        v1_http_get_action_free(v1_handler->http_get);
        v1_handler->http_get = NULL;
    }
    if (v1_handler->tcp_socket) {
        v1_tcp_socket_action_free(v1_handler->tcp_socket);
        v1_handler->tcp_socket = NULL;
    }
    free(v1_handler);
}

cJSON *v1_handler_convertToJSON(v1_handler_t *v1_handler) {
    cJSON *item = cJSON_CreateObject();

    // v1_handler->exec
    if(v1_handler->exec) { 
    cJSON *exec_local_JSON = v1_exec_action_convertToJSON(v1_handler->exec);
    if(exec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "exec", exec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_handler->http_get
    if(v1_handler->http_get) { 
    cJSON *http_get_local_JSON = v1_http_get_action_convertToJSON(v1_handler->http_get);
    if(http_get_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "httpGet", http_get_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_handler->tcp_socket
    if(v1_handler->tcp_socket) { 
    cJSON *tcp_socket_local_JSON = v1_tcp_socket_action_convertToJSON(v1_handler->tcp_socket);
    if(tcp_socket_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "tcpSocket", tcp_socket_local_JSON);
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

v1_handler_t *v1_handler_parseFromJSON(cJSON *v1_handlerJSON){

    v1_handler_t *v1_handler_local_var = NULL;

    // v1_handler->exec
    cJSON *exec = cJSON_GetObjectItemCaseSensitive(v1_handlerJSON, "exec");
    v1_exec_action_t *exec_local_nonprim = NULL;
    if (exec) { 
    exec_local_nonprim = v1_exec_action_parseFromJSON(exec); //nonprimitive
    }

    // v1_handler->http_get
    cJSON *http_get = cJSON_GetObjectItemCaseSensitive(v1_handlerJSON, "httpGet");
    v1_http_get_action_t *http_get_local_nonprim = NULL;
    if (http_get) { 
    http_get_local_nonprim = v1_http_get_action_parseFromJSON(http_get); //nonprimitive
    }

    // v1_handler->tcp_socket
    cJSON *tcp_socket = cJSON_GetObjectItemCaseSensitive(v1_handlerJSON, "tcpSocket");
    v1_tcp_socket_action_t *tcp_socket_local_nonprim = NULL;
    if (tcp_socket) { 
    tcp_socket_local_nonprim = v1_tcp_socket_action_parseFromJSON(tcp_socket); //nonprimitive
    }


    v1_handler_local_var = v1_handler_create (
        exec ? exec_local_nonprim : NULL,
        http_get ? http_get_local_nonprim : NULL,
        tcp_socket ? tcp_socket_local_nonprim : NULL
        );

    return v1_handler_local_var;
end:
    if (exec_local_nonprim) {
        v1_exec_action_free(exec_local_nonprim);
        exec_local_nonprim = NULL;
    }
    if (http_get_local_nonprim) {
        v1_http_get_action_free(http_get_local_nonprim);
        http_get_local_nonprim = NULL;
    }
    if (tcp_socket_local_nonprim) {
        v1_tcp_socket_action_free(tcp_socket_local_nonprim);
        tcp_socket_local_nonprim = NULL;
    }
    return NULL;

}
