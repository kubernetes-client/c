#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_node_allocatable_overhead.h"



static v1beta2_node_allocatable_overhead_t *v1beta2_node_allocatable_overhead_create_internal(
    char *per_container,
    char *per_pod
    ) {
    v1beta2_node_allocatable_overhead_t *v1beta2_node_allocatable_overhead_local_var = malloc(sizeof(v1beta2_node_allocatable_overhead_t));
    if (!v1beta2_node_allocatable_overhead_local_var) {
        return NULL;
    }
    memset(v1beta2_node_allocatable_overhead_local_var, 0, sizeof(v1beta2_node_allocatable_overhead_t));
    v1beta2_node_allocatable_overhead_local_var->_library_owned = 1;
    v1beta2_node_allocatable_overhead_local_var->per_container = per_container;
    v1beta2_node_allocatable_overhead_local_var->per_pod = per_pod;
    return v1beta2_node_allocatable_overhead_local_var;
}

__attribute__((deprecated)) v1beta2_node_allocatable_overhead_t *v1beta2_node_allocatable_overhead_create(
    char *per_container,
    char *per_pod
    ) {
    v1beta2_node_allocatable_overhead_t *result = v1beta2_node_allocatable_overhead_create_internal (
        per_container,
        per_pod
        );
    if (!result) {
    }
    return result;
}

void v1beta2_node_allocatable_overhead_free(v1beta2_node_allocatable_overhead_t *v1beta2_node_allocatable_overhead) {
    if(NULL == v1beta2_node_allocatable_overhead){
        return ;
    }
    if(v1beta2_node_allocatable_overhead->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta2_node_allocatable_overhead_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta2_node_allocatable_overhead->per_container) {
        free(v1beta2_node_allocatable_overhead->per_container);
        v1beta2_node_allocatable_overhead->per_container = NULL;
    }
    if (v1beta2_node_allocatable_overhead->per_pod) {
        free(v1beta2_node_allocatable_overhead->per_pod);
        v1beta2_node_allocatable_overhead->per_pod = NULL;
    }
    free(v1beta2_node_allocatable_overhead);
}

cJSON *v1beta2_node_allocatable_overhead_convertToJSON(v1beta2_node_allocatable_overhead_t *v1beta2_node_allocatable_overhead) {
    cJSON *item = cJSON_CreateObject();

    // v1beta2_node_allocatable_overhead->per_container
    if(v1beta2_node_allocatable_overhead->per_container) {
    if(cJSON_AddStringToObject(item, "perContainer", v1beta2_node_allocatable_overhead->per_container) == NULL) {
    goto fail; //String
    }
    }


    // v1beta2_node_allocatable_overhead->per_pod
    if(v1beta2_node_allocatable_overhead->per_pod) {
    if(cJSON_AddStringToObject(item, "perPod", v1beta2_node_allocatable_overhead->per_pod) == NULL) {
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

v1beta2_node_allocatable_overhead_t *v1beta2_node_allocatable_overhead_parseFromJSON(cJSON *v1beta2_node_allocatable_overheadJSON){

    v1beta2_node_allocatable_overhead_t *v1beta2_node_allocatable_overhead_local_var = NULL;

    char *per_container_local_str = NULL;

    char *per_pod_local_str = NULL;

    // v1beta2_node_allocatable_overhead->per_container
    cJSON *per_container = cJSON_GetObjectItemCaseSensitive(v1beta2_node_allocatable_overheadJSON, "perContainer");
    if (cJSON_IsNull(per_container)) {
        per_container = NULL;
    }
    if (per_container) { 
    if(!cJSON_IsString(per_container) && !cJSON_IsNull(per_container))
    {
    goto end; //String
    }
    }

    // v1beta2_node_allocatable_overhead->per_pod
    cJSON *per_pod = cJSON_GetObjectItemCaseSensitive(v1beta2_node_allocatable_overheadJSON, "perPod");
    if (cJSON_IsNull(per_pod)) {
        per_pod = NULL;
    }
    if (per_pod) { 
    if(!cJSON_IsString(per_pod) && !cJSON_IsNull(per_pod))
    {
    goto end; //String
    }
    }


    if (per_container && !cJSON_IsNull(per_container)) per_container_local_str = strdup(per_container->valuestring);
    if (per_pod && !cJSON_IsNull(per_pod)) per_pod_local_str = strdup(per_pod->valuestring);

    v1beta2_node_allocatable_overhead_local_var = v1beta2_node_allocatable_overhead_create_internal (
        per_container_local_str,
        per_pod_local_str
        );

    if (!v1beta2_node_allocatable_overhead_local_var) {
        goto end;
    }

    return v1beta2_node_allocatable_overhead_local_var;
end:
    if (per_container_local_str) {
        free(per_container_local_str);
        per_container_local_str = NULL;
    }
    if (per_pod_local_str) {
        free(per_pod_local_str);
        per_pod_local_str = NULL;
    }
    return NULL;

}
