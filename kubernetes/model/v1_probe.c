#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_probe.h"



v1_probe_t *v1_probe_create(
    v1_exec_action_t *exec,
    int failure_threshold,
    v1_http_get_action_t *http_get,
    int initial_delay_seconds,
    int period_seconds,
    int success_threshold,
    v1_tcp_socket_action_t *tcp_socket,
    int timeout_seconds
    ) {
    v1_probe_t *v1_probe_local_var = malloc(sizeof(v1_probe_t));
    if (!v1_probe_local_var) {
        return NULL;
    }
    v1_probe_local_var->exec = exec;
    v1_probe_local_var->failure_threshold = failure_threshold;
    v1_probe_local_var->http_get = http_get;
    v1_probe_local_var->initial_delay_seconds = initial_delay_seconds;
    v1_probe_local_var->period_seconds = period_seconds;
    v1_probe_local_var->success_threshold = success_threshold;
    v1_probe_local_var->tcp_socket = tcp_socket;
    v1_probe_local_var->timeout_seconds = timeout_seconds;

    return v1_probe_local_var;
}


void v1_probe_free(v1_probe_t *v1_probe) {
    if(NULL == v1_probe){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_probe->exec) {
        v1_exec_action_free(v1_probe->exec);
        v1_probe->exec = NULL;
    }
    if (v1_probe->http_get) {
        v1_http_get_action_free(v1_probe->http_get);
        v1_probe->http_get = NULL;
    }
    if (v1_probe->tcp_socket) {
        v1_tcp_socket_action_free(v1_probe->tcp_socket);
        v1_probe->tcp_socket = NULL;
    }
    free(v1_probe);
}

cJSON *v1_probe_convertToJSON(v1_probe_t *v1_probe) {
    cJSON *item = cJSON_CreateObject();

    // v1_probe->exec
    if(v1_probe->exec) { 
    cJSON *exec_local_JSON = v1_exec_action_convertToJSON(v1_probe->exec);
    if(exec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "exec", exec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_probe->failure_threshold
    if(v1_probe->failure_threshold) { 
    if(cJSON_AddNumberToObject(item, "failureThreshold", v1_probe->failure_threshold) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_probe->http_get
    if(v1_probe->http_get) { 
    cJSON *http_get_local_JSON = v1_http_get_action_convertToJSON(v1_probe->http_get);
    if(http_get_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "httpGet", http_get_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_probe->initial_delay_seconds
    if(v1_probe->initial_delay_seconds) { 
    if(cJSON_AddNumberToObject(item, "initialDelaySeconds", v1_probe->initial_delay_seconds) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_probe->period_seconds
    if(v1_probe->period_seconds) { 
    if(cJSON_AddNumberToObject(item, "periodSeconds", v1_probe->period_seconds) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_probe->success_threshold
    if(v1_probe->success_threshold) { 
    if(cJSON_AddNumberToObject(item, "successThreshold", v1_probe->success_threshold) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_probe->tcp_socket
    if(v1_probe->tcp_socket) { 
    cJSON *tcp_socket_local_JSON = v1_tcp_socket_action_convertToJSON(v1_probe->tcp_socket);
    if(tcp_socket_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "tcpSocket", tcp_socket_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_probe->timeout_seconds
    if(v1_probe->timeout_seconds) { 
    if(cJSON_AddNumberToObject(item, "timeoutSeconds", v1_probe->timeout_seconds) == NULL) {
    goto fail; //Numeric
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_probe_t *v1_probe_parseFromJSON(cJSON *v1_probeJSON){

    v1_probe_t *v1_probe_local_var = NULL;

    // v1_probe->exec
    cJSON *exec = cJSON_GetObjectItemCaseSensitive(v1_probeJSON, "exec");
    v1_exec_action_t *exec_local_nonprim = NULL;
    if (exec) { 
    exec_local_nonprim = v1_exec_action_parseFromJSON(exec); //nonprimitive
    }

    // v1_probe->failure_threshold
    cJSON *failure_threshold = cJSON_GetObjectItemCaseSensitive(v1_probeJSON, "failureThreshold");
    if (failure_threshold) { 
    if(!cJSON_IsNumber(failure_threshold))
    {
    goto end; //Numeric
    }
    }

    // v1_probe->http_get
    cJSON *http_get = cJSON_GetObjectItemCaseSensitive(v1_probeJSON, "httpGet");
    v1_http_get_action_t *http_get_local_nonprim = NULL;
    if (http_get) { 
    http_get_local_nonprim = v1_http_get_action_parseFromJSON(http_get); //nonprimitive
    }

    // v1_probe->initial_delay_seconds
    cJSON *initial_delay_seconds = cJSON_GetObjectItemCaseSensitive(v1_probeJSON, "initialDelaySeconds");
    if (initial_delay_seconds) { 
    if(!cJSON_IsNumber(initial_delay_seconds))
    {
    goto end; //Numeric
    }
    }

    // v1_probe->period_seconds
    cJSON *period_seconds = cJSON_GetObjectItemCaseSensitive(v1_probeJSON, "periodSeconds");
    if (period_seconds) { 
    if(!cJSON_IsNumber(period_seconds))
    {
    goto end; //Numeric
    }
    }

    // v1_probe->success_threshold
    cJSON *success_threshold = cJSON_GetObjectItemCaseSensitive(v1_probeJSON, "successThreshold");
    if (success_threshold) { 
    if(!cJSON_IsNumber(success_threshold))
    {
    goto end; //Numeric
    }
    }

    // v1_probe->tcp_socket
    cJSON *tcp_socket = cJSON_GetObjectItemCaseSensitive(v1_probeJSON, "tcpSocket");
    v1_tcp_socket_action_t *tcp_socket_local_nonprim = NULL;
    if (tcp_socket) { 
    tcp_socket_local_nonprim = v1_tcp_socket_action_parseFromJSON(tcp_socket); //nonprimitive
    }

    // v1_probe->timeout_seconds
    cJSON *timeout_seconds = cJSON_GetObjectItemCaseSensitive(v1_probeJSON, "timeoutSeconds");
    if (timeout_seconds) { 
    if(!cJSON_IsNumber(timeout_seconds))
    {
    goto end; //Numeric
    }
    }


    v1_probe_local_var = v1_probe_create (
        exec ? exec_local_nonprim : NULL,
        failure_threshold ? failure_threshold->valuedouble : 0,
        http_get ? http_get_local_nonprim : NULL,
        initial_delay_seconds ? initial_delay_seconds->valuedouble : 0,
        period_seconds ? period_seconds->valuedouble : 0,
        success_threshold ? success_threshold->valuedouble : 0,
        tcp_socket ? tcp_socket_local_nonprim : NULL,
        timeout_seconds ? timeout_seconds->valuedouble : 0
        );

    return v1_probe_local_var;
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
