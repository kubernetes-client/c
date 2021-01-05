#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_container_state_running.h"



v1_container_state_running_t *v1_container_state_running_create(
    char *started_at
    ) {
    v1_container_state_running_t *v1_container_state_running_local_var = malloc(sizeof(v1_container_state_running_t));
    if (!v1_container_state_running_local_var) {
        return NULL;
    }
    v1_container_state_running_local_var->started_at = started_at;

    return v1_container_state_running_local_var;
}


void v1_container_state_running_free(v1_container_state_running_t *v1_container_state_running) {
    if(NULL == v1_container_state_running){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_container_state_running->started_at) {
        free(v1_container_state_running->started_at);
        v1_container_state_running->started_at = NULL;
    }
    free(v1_container_state_running);
}

cJSON *v1_container_state_running_convertToJSON(v1_container_state_running_t *v1_container_state_running) {
    cJSON *item = cJSON_CreateObject();

    // v1_container_state_running->started_at
    if(v1_container_state_running->started_at) { 
    if(cJSON_AddStringToObject(item, "startedAt", v1_container_state_running->started_at) == NULL) {
    goto fail; //Date-Time
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_container_state_running_t *v1_container_state_running_parseFromJSON(cJSON *v1_container_state_runningJSON){

    v1_container_state_running_t *v1_container_state_running_local_var = NULL;

    // v1_container_state_running->started_at
    cJSON *started_at = cJSON_GetObjectItemCaseSensitive(v1_container_state_runningJSON, "startedAt");
    if (started_at) { 
    if(!cJSON_IsString(started_at))
    {
    goto end; //DateTime
    }
    }


    v1_container_state_running_local_var = v1_container_state_running_create (
        started_at ? strdup(started_at->valuestring) : NULL
        );

    return v1_container_state_running_local_var;
end:
    return NULL;

}
