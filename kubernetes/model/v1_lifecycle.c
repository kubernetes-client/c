#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_lifecycle.h"



static v1_lifecycle_t *v1_lifecycle_create_internal(
    v1_lifecycle_handler_t *post_start,
    v1_lifecycle_handler_t *pre_stop,
    char *stop_signal
    ) {
    v1_lifecycle_t *v1_lifecycle_local_var = malloc(sizeof(v1_lifecycle_t));
    if (!v1_lifecycle_local_var) {
        return NULL;
    }
    v1_lifecycle_local_var->post_start = post_start;
    v1_lifecycle_local_var->pre_stop = pre_stop;
    v1_lifecycle_local_var->stop_signal = stop_signal;

    v1_lifecycle_local_var->_library_owned = 1;
    return v1_lifecycle_local_var;
}

__attribute__((deprecated)) v1_lifecycle_t *v1_lifecycle_create(
    v1_lifecycle_handler_t *post_start,
    v1_lifecycle_handler_t *pre_stop,
    char *stop_signal
    ) {
    return v1_lifecycle_create_internal (
        post_start,
        pre_stop,
        stop_signal
        );
}

void v1_lifecycle_free(v1_lifecycle_t *v1_lifecycle) {
    if(NULL == v1_lifecycle){
        return ;
    }
    if(v1_lifecycle->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_lifecycle_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_lifecycle->post_start) {
        v1_lifecycle_handler_free(v1_lifecycle->post_start);
        v1_lifecycle->post_start = NULL;
    }
    if (v1_lifecycle->pre_stop) {
        v1_lifecycle_handler_free(v1_lifecycle->pre_stop);
        v1_lifecycle->pre_stop = NULL;
    }
    if (v1_lifecycle->stop_signal) {
        free(v1_lifecycle->stop_signal);
        v1_lifecycle->stop_signal = NULL;
    }
    free(v1_lifecycle);
}

cJSON *v1_lifecycle_convertToJSON(v1_lifecycle_t *v1_lifecycle) {
    cJSON *item = cJSON_CreateObject();

    // v1_lifecycle->post_start
    if(v1_lifecycle->post_start) {
    cJSON *post_start_local_JSON = v1_lifecycle_handler_convertToJSON(v1_lifecycle->post_start);
    if(post_start_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "postStart", post_start_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_lifecycle->pre_stop
    if(v1_lifecycle->pre_stop) {
    cJSON *pre_stop_local_JSON = v1_lifecycle_handler_convertToJSON(v1_lifecycle->pre_stop);
    if(pre_stop_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "preStop", pre_stop_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_lifecycle->stop_signal
    if(v1_lifecycle->stop_signal) {
    if(cJSON_AddStringToObject(item, "stopSignal", v1_lifecycle->stop_signal) == NULL) {
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

v1_lifecycle_t *v1_lifecycle_parseFromJSON(cJSON *v1_lifecycleJSON){

    v1_lifecycle_t *v1_lifecycle_local_var = NULL;

    // define the local variable for v1_lifecycle->post_start
    v1_lifecycle_handler_t *post_start_local_nonprim = NULL;

    // define the local variable for v1_lifecycle->pre_stop
    v1_lifecycle_handler_t *pre_stop_local_nonprim = NULL;

    // v1_lifecycle->post_start
    cJSON *post_start = cJSON_GetObjectItemCaseSensitive(v1_lifecycleJSON, "postStart");
    if (cJSON_IsNull(post_start)) {
        post_start = NULL;
    }
    if (post_start) { 
    post_start_local_nonprim = v1_lifecycle_handler_parseFromJSON(post_start); //nonprimitive
    }

    // v1_lifecycle->pre_stop
    cJSON *pre_stop = cJSON_GetObjectItemCaseSensitive(v1_lifecycleJSON, "preStop");
    if (cJSON_IsNull(pre_stop)) {
        pre_stop = NULL;
    }
    if (pre_stop) { 
    pre_stop_local_nonprim = v1_lifecycle_handler_parseFromJSON(pre_stop); //nonprimitive
    }

    // v1_lifecycle->stop_signal
    cJSON *stop_signal = cJSON_GetObjectItemCaseSensitive(v1_lifecycleJSON, "stopSignal");
    if (cJSON_IsNull(stop_signal)) {
        stop_signal = NULL;
    }
    if (stop_signal) { 
    if(!cJSON_IsString(stop_signal) && !cJSON_IsNull(stop_signal))
    {
    goto end; //String
    }
    }


    v1_lifecycle_local_var = v1_lifecycle_create_internal (
        post_start ? post_start_local_nonprim : NULL,
        pre_stop ? pre_stop_local_nonprim : NULL,
        stop_signal && !cJSON_IsNull(stop_signal) ? strdup(stop_signal->valuestring) : NULL
        );

    return v1_lifecycle_local_var;
end:
    if (post_start_local_nonprim) {
        v1_lifecycle_handler_free(post_start_local_nonprim);
        post_start_local_nonprim = NULL;
    }
    if (pre_stop_local_nonprim) {
        v1_lifecycle_handler_free(pre_stop_local_nonprim);
        pre_stop_local_nonprim = NULL;
    }
    return NULL;

}
