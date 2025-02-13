#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_scheduling_gate.h"



static v1_pod_scheduling_gate_t *v1_pod_scheduling_gate_create_internal(
    char *name
    ) {
    v1_pod_scheduling_gate_t *v1_pod_scheduling_gate_local_var = malloc(sizeof(v1_pod_scheduling_gate_t));
    if (!v1_pod_scheduling_gate_local_var) {
        return NULL;
    }
    v1_pod_scheduling_gate_local_var->name = name;

    v1_pod_scheduling_gate_local_var->_library_owned = 1;
    return v1_pod_scheduling_gate_local_var;
}

__attribute__((deprecated)) v1_pod_scheduling_gate_t *v1_pod_scheduling_gate_create(
    char *name
    ) {
    return v1_pod_scheduling_gate_create_internal (
        name
        );
}

void v1_pod_scheduling_gate_free(v1_pod_scheduling_gate_t *v1_pod_scheduling_gate) {
    if(NULL == v1_pod_scheduling_gate){
        return ;
    }
    if(v1_pod_scheduling_gate->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_pod_scheduling_gate_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_pod_scheduling_gate->name) {
        free(v1_pod_scheduling_gate->name);
        v1_pod_scheduling_gate->name = NULL;
    }
    free(v1_pod_scheduling_gate);
}

cJSON *v1_pod_scheduling_gate_convertToJSON(v1_pod_scheduling_gate_t *v1_pod_scheduling_gate) {
    cJSON *item = cJSON_CreateObject();

    // v1_pod_scheduling_gate->name
    if (!v1_pod_scheduling_gate->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_pod_scheduling_gate->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_pod_scheduling_gate_t *v1_pod_scheduling_gate_parseFromJSON(cJSON *v1_pod_scheduling_gateJSON){

    v1_pod_scheduling_gate_t *v1_pod_scheduling_gate_local_var = NULL;

    // v1_pod_scheduling_gate->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_pod_scheduling_gateJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    v1_pod_scheduling_gate_local_var = v1_pod_scheduling_gate_create_internal (
        strdup(name->valuestring)
        );

    return v1_pod_scheduling_gate_local_var;
end:
    return NULL;

}
