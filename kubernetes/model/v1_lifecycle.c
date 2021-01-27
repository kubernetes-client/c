#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_lifecycle.h"



v1_lifecycle_t *v1_lifecycle_create(
    v1_handler_t *post_start,
    v1_handler_t *pre_stop
    ) {
    v1_lifecycle_t *v1_lifecycle_local_var = malloc(sizeof(v1_lifecycle_t));
    if (!v1_lifecycle_local_var) {
        return NULL;
    }
    v1_lifecycle_local_var->post_start = post_start;
    v1_lifecycle_local_var->pre_stop = pre_stop;

    return v1_lifecycle_local_var;
}


void v1_lifecycle_free(v1_lifecycle_t *v1_lifecycle) {
    if(NULL == v1_lifecycle){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_lifecycle->post_start) {
        v1_handler_free(v1_lifecycle->post_start);
        v1_lifecycle->post_start = NULL;
    }
    if (v1_lifecycle->pre_stop) {
        v1_handler_free(v1_lifecycle->pre_stop);
        v1_lifecycle->pre_stop = NULL;
    }
    free(v1_lifecycle);
}

cJSON *v1_lifecycle_convertToJSON(v1_lifecycle_t *v1_lifecycle) {
    cJSON *item = cJSON_CreateObject();

    // v1_lifecycle->post_start
    if(v1_lifecycle->post_start) { 
    cJSON *post_start_local_JSON = v1_handler_convertToJSON(v1_lifecycle->post_start);
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
    cJSON *pre_stop_local_JSON = v1_handler_convertToJSON(v1_lifecycle->pre_stop);
    if(pre_stop_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "preStop", pre_stop_local_JSON);
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

v1_lifecycle_t *v1_lifecycle_parseFromJSON(cJSON *v1_lifecycleJSON){

    v1_lifecycle_t *v1_lifecycle_local_var = NULL;

    // v1_lifecycle->post_start
    cJSON *post_start = cJSON_GetObjectItemCaseSensitive(v1_lifecycleJSON, "postStart");
    v1_handler_t *post_start_local_nonprim = NULL;
    if (post_start) { 
    post_start_local_nonprim = v1_handler_parseFromJSON(post_start); //nonprimitive
    }

    // v1_lifecycle->pre_stop
    cJSON *pre_stop = cJSON_GetObjectItemCaseSensitive(v1_lifecycleJSON, "preStop");
    v1_handler_t *pre_stop_local_nonprim = NULL;
    if (pre_stop) { 
    pre_stop_local_nonprim = v1_handler_parseFromJSON(pre_stop); //nonprimitive
    }


    v1_lifecycle_local_var = v1_lifecycle_create (
        post_start ? post_start_local_nonprim : NULL,
        pre_stop ? pre_stop_local_nonprim : NULL
        );

    return v1_lifecycle_local_var;
end:
    if (post_start_local_nonprim) {
        v1_handler_free(post_start_local_nonprim);
        post_start_local_nonprim = NULL;
    }
    if (pre_stop_local_nonprim) {
        v1_handler_free(pre_stop_local_nonprim);
        pre_stop_local_nonprim = NULL;
    }
    return NULL;

}
