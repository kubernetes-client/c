#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_lifecycle_handler.h"



static v1_lifecycle_handler_t *v1_lifecycle_handler_create_internal(
    v1_exec_action_t *exec,
    v1_http_get_action_t *http_get,
    v1_sleep_action_t *sleep,
    v1_tcp_socket_action_t *tcp_socket
    ) {
    v1_lifecycle_handler_t *v1_lifecycle_handler_local_var = malloc(sizeof(v1_lifecycle_handler_t));
    if (!v1_lifecycle_handler_local_var) {
        return NULL;
    }
    v1_lifecycle_handler_local_var->exec = exec;
    v1_lifecycle_handler_local_var->http_get = http_get;
    v1_lifecycle_handler_local_var->sleep = sleep;
    v1_lifecycle_handler_local_var->tcp_socket = tcp_socket;

    v1_lifecycle_handler_local_var->_library_owned = 1;
    return v1_lifecycle_handler_local_var;
}

__attribute__((deprecated)) v1_lifecycle_handler_t *v1_lifecycle_handler_create(
    v1_exec_action_t *exec,
    v1_http_get_action_t *http_get,
    v1_sleep_action_t *sleep,
    v1_tcp_socket_action_t *tcp_socket
    ) {
    return v1_lifecycle_handler_create_internal (
        exec,
        http_get,
        sleep,
        tcp_socket
        );
}

void v1_lifecycle_handler_free(v1_lifecycle_handler_t *v1_lifecycle_handler) {
    if(NULL == v1_lifecycle_handler){
        return ;
    }
    if(v1_lifecycle_handler->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_lifecycle_handler_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_lifecycle_handler->exec) {
        v1_exec_action_free(v1_lifecycle_handler->exec);
        v1_lifecycle_handler->exec = NULL;
    }
    if (v1_lifecycle_handler->http_get) {
        v1_http_get_action_free(v1_lifecycle_handler->http_get);
        v1_lifecycle_handler->http_get = NULL;
    }
    if (v1_lifecycle_handler->sleep) {
        v1_sleep_action_free(v1_lifecycle_handler->sleep);
        v1_lifecycle_handler->sleep = NULL;
    }
    if (v1_lifecycle_handler->tcp_socket) {
        v1_tcp_socket_action_free(v1_lifecycle_handler->tcp_socket);
        v1_lifecycle_handler->tcp_socket = NULL;
    }
    free(v1_lifecycle_handler);
}

cJSON *v1_lifecycle_handler_convertToJSON(v1_lifecycle_handler_t *v1_lifecycle_handler) {
    cJSON *item = cJSON_CreateObject();

    // v1_lifecycle_handler->exec
    if(v1_lifecycle_handler->exec) {
    cJSON *exec_local_JSON = v1_exec_action_convertToJSON(v1_lifecycle_handler->exec);
    if(exec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "exec", exec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_lifecycle_handler->http_get
    if(v1_lifecycle_handler->http_get) {
    cJSON *http_get_local_JSON = v1_http_get_action_convertToJSON(v1_lifecycle_handler->http_get);
    if(http_get_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "httpGet", http_get_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_lifecycle_handler->sleep
    if(v1_lifecycle_handler->sleep) {
    cJSON *sleep_local_JSON = v1_sleep_action_convertToJSON(v1_lifecycle_handler->sleep);
    if(sleep_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sleep", sleep_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_lifecycle_handler->tcp_socket
    if(v1_lifecycle_handler->tcp_socket) {
    cJSON *tcp_socket_local_JSON = v1_tcp_socket_action_convertToJSON(v1_lifecycle_handler->tcp_socket);
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

v1_lifecycle_handler_t *v1_lifecycle_handler_parseFromJSON(cJSON *v1_lifecycle_handlerJSON){

    v1_lifecycle_handler_t *v1_lifecycle_handler_local_var = NULL;

    // define the local variable for v1_lifecycle_handler->exec
    v1_exec_action_t *exec_local_nonprim = NULL;

    // define the local variable for v1_lifecycle_handler->http_get
    v1_http_get_action_t *http_get_local_nonprim = NULL;

    // define the local variable for v1_lifecycle_handler->sleep
    v1_sleep_action_t *sleep_local_nonprim = NULL;

    // define the local variable for v1_lifecycle_handler->tcp_socket
    v1_tcp_socket_action_t *tcp_socket_local_nonprim = NULL;

    // v1_lifecycle_handler->exec
    cJSON *exec = cJSON_GetObjectItemCaseSensitive(v1_lifecycle_handlerJSON, "exec");
    if (cJSON_IsNull(exec)) {
        exec = NULL;
    }
    if (exec) { 
    exec_local_nonprim = v1_exec_action_parseFromJSON(exec); //nonprimitive
    }

    // v1_lifecycle_handler->http_get
    cJSON *http_get = cJSON_GetObjectItemCaseSensitive(v1_lifecycle_handlerJSON, "httpGet");
    if (cJSON_IsNull(http_get)) {
        http_get = NULL;
    }
    if (http_get) { 
    http_get_local_nonprim = v1_http_get_action_parseFromJSON(http_get); //nonprimitive
    }

    // v1_lifecycle_handler->sleep
    cJSON *sleep = cJSON_GetObjectItemCaseSensitive(v1_lifecycle_handlerJSON, "sleep");
    if (cJSON_IsNull(sleep)) {
        sleep = NULL;
    }
    if (sleep) { 
    sleep_local_nonprim = v1_sleep_action_parseFromJSON(sleep); //nonprimitive
    }

    // v1_lifecycle_handler->tcp_socket
    cJSON *tcp_socket = cJSON_GetObjectItemCaseSensitive(v1_lifecycle_handlerJSON, "tcpSocket");
    if (cJSON_IsNull(tcp_socket)) {
        tcp_socket = NULL;
    }
    if (tcp_socket) { 
    tcp_socket_local_nonprim = v1_tcp_socket_action_parseFromJSON(tcp_socket); //nonprimitive
    }


    v1_lifecycle_handler_local_var = v1_lifecycle_handler_create_internal (
        exec ? exec_local_nonprim : NULL,
        http_get ? http_get_local_nonprim : NULL,
        sleep ? sleep_local_nonprim : NULL,
        tcp_socket ? tcp_socket_local_nonprim : NULL
        );

    return v1_lifecycle_handler_local_var;
end:
    if (exec_local_nonprim) {
        v1_exec_action_free(exec_local_nonprim);
        exec_local_nonprim = NULL;
    }
    if (http_get_local_nonprim) {
        v1_http_get_action_free(http_get_local_nonprim);
        http_get_local_nonprim = NULL;
    }
    if (sleep_local_nonprim) {
        v1_sleep_action_free(sleep_local_nonprim);
        sleep_local_nonprim = NULL;
    }
    if (tcp_socket_local_nonprim) {
        v1_tcp_socket_action_free(tcp_socket_local_nonprim);
        tcp_socket_local_nonprim = NULL;
    }
    return NULL;

}
