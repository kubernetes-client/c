#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_container_state_running.h"



static v1_container_state_running_t *v1_container_state_running_create_internal(
    char *started_at
    ) {
    v1_container_state_running_t *v1_container_state_running_local_var = malloc(sizeof(v1_container_state_running_t));
    if (!v1_container_state_running_local_var) {
        return NULL;
    }
    memset(v1_container_state_running_local_var, 0, sizeof(v1_container_state_running_t));
    v1_container_state_running_local_var->_library_owned = 1;
    v1_container_state_running_local_var->started_at = started_at;
    return v1_container_state_running_local_var;
}

__attribute__((deprecated)) v1_container_state_running_t *v1_container_state_running_create(
    char *started_at
    ) {
    v1_container_state_running_t *result = v1_container_state_running_create_internal (
        started_at
        );
    if (!result) {
    }
    return result;
}

void v1_container_state_running_free(v1_container_state_running_t *v1_container_state_running) {
    if(NULL == v1_container_state_running){
        return ;
    }
    if(v1_container_state_running->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_container_state_running_free");
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

    char *started_at_local_str = NULL;

    // v1_container_state_running->started_at
    cJSON *started_at = cJSON_GetObjectItemCaseSensitive(v1_container_state_runningJSON, "startedAt");
    if (cJSON_IsNull(started_at)) {
        started_at = NULL;
    }
    if (started_at) { 
    if(!cJSON_IsString(started_at) && !cJSON_IsNull(started_at))
    {
    goto end; //DateTime
    }
    }


    if (started_at && !cJSON_IsNull(started_at)) started_at_local_str = strdup(started_at->valuestring);

    v1_container_state_running_local_var = v1_container_state_running_create_internal (
        started_at_local_str
        );

    if (!v1_container_state_running_local_var) {
        goto end;
    }

    return v1_container_state_running_local_var;
end:
    if (started_at_local_str) {
        free(started_at_local_str);
        started_at_local_str = NULL;
    }
    return NULL;

}
