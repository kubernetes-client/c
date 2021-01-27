#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_container_state.h"



v1_container_state_t *v1_container_state_create(
    v1_container_state_running_t *running,
    v1_container_state_terminated_t *terminated,
    v1_container_state_waiting_t *waiting
    ) {
    v1_container_state_t *v1_container_state_local_var = malloc(sizeof(v1_container_state_t));
    if (!v1_container_state_local_var) {
        return NULL;
    }
    v1_container_state_local_var->running = running;
    v1_container_state_local_var->terminated = terminated;
    v1_container_state_local_var->waiting = waiting;

    return v1_container_state_local_var;
}


void v1_container_state_free(v1_container_state_t *v1_container_state) {
    if(NULL == v1_container_state){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_container_state->running) {
        v1_container_state_running_free(v1_container_state->running);
        v1_container_state->running = NULL;
    }
    if (v1_container_state->terminated) {
        v1_container_state_terminated_free(v1_container_state->terminated);
        v1_container_state->terminated = NULL;
    }
    if (v1_container_state->waiting) {
        v1_container_state_waiting_free(v1_container_state->waiting);
        v1_container_state->waiting = NULL;
    }
    free(v1_container_state);
}

cJSON *v1_container_state_convertToJSON(v1_container_state_t *v1_container_state) {
    cJSON *item = cJSON_CreateObject();

    // v1_container_state->running
    if(v1_container_state->running) { 
    cJSON *running_local_JSON = v1_container_state_running_convertToJSON(v1_container_state->running);
    if(running_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "running", running_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_container_state->terminated
    if(v1_container_state->terminated) { 
    cJSON *terminated_local_JSON = v1_container_state_terminated_convertToJSON(v1_container_state->terminated);
    if(terminated_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "terminated", terminated_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_container_state->waiting
    if(v1_container_state->waiting) { 
    cJSON *waiting_local_JSON = v1_container_state_waiting_convertToJSON(v1_container_state->waiting);
    if(waiting_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "waiting", waiting_local_JSON);
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

v1_container_state_t *v1_container_state_parseFromJSON(cJSON *v1_container_stateJSON){

    v1_container_state_t *v1_container_state_local_var = NULL;

    // v1_container_state->running
    cJSON *running = cJSON_GetObjectItemCaseSensitive(v1_container_stateJSON, "running");
    v1_container_state_running_t *running_local_nonprim = NULL;
    if (running) { 
    running_local_nonprim = v1_container_state_running_parseFromJSON(running); //nonprimitive
    }

    // v1_container_state->terminated
    cJSON *terminated = cJSON_GetObjectItemCaseSensitive(v1_container_stateJSON, "terminated");
    v1_container_state_terminated_t *terminated_local_nonprim = NULL;
    if (terminated) { 
    terminated_local_nonprim = v1_container_state_terminated_parseFromJSON(terminated); //nonprimitive
    }

    // v1_container_state->waiting
    cJSON *waiting = cJSON_GetObjectItemCaseSensitive(v1_container_stateJSON, "waiting");
    v1_container_state_waiting_t *waiting_local_nonprim = NULL;
    if (waiting) { 
    waiting_local_nonprim = v1_container_state_waiting_parseFromJSON(waiting); //nonprimitive
    }


    v1_container_state_local_var = v1_container_state_create (
        running ? running_local_nonprim : NULL,
        terminated ? terminated_local_nonprim : NULL,
        waiting ? waiting_local_nonprim : NULL
        );

    return v1_container_state_local_var;
end:
    if (running_local_nonprim) {
        v1_container_state_running_free(running_local_nonprim);
        running_local_nonprim = NULL;
    }
    if (terminated_local_nonprim) {
        v1_container_state_terminated_free(terminated_local_nonprim);
        terminated_local_nonprim = NULL;
    }
    if (waiting_local_nonprim) {
        v1_container_state_waiting_free(waiting_local_nonprim);
        waiting_local_nonprim = NULL;
    }
    return NULL;

}
