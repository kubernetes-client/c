#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_allocatable_overhead_resources.h"



static v1_node_allocatable_overhead_resources_t *v1_node_allocatable_overhead_resources_create_internal(
    char *name,
    char *per_container,
    char *per_pod
    ) {
    v1_node_allocatable_overhead_resources_t *v1_node_allocatable_overhead_resources_local_var = malloc(sizeof(v1_node_allocatable_overhead_resources_t));
    if (!v1_node_allocatable_overhead_resources_local_var) {
        return NULL;
    }
    memset(v1_node_allocatable_overhead_resources_local_var, 0, sizeof(v1_node_allocatable_overhead_resources_t));
    v1_node_allocatable_overhead_resources_local_var->_library_owned = 1;
    v1_node_allocatable_overhead_resources_local_var->name = name;
    v1_node_allocatable_overhead_resources_local_var->per_container = per_container;
    v1_node_allocatable_overhead_resources_local_var->per_pod = per_pod;
    return v1_node_allocatable_overhead_resources_local_var;
}

__attribute__((deprecated)) v1_node_allocatable_overhead_resources_t *v1_node_allocatable_overhead_resources_create(
    char *name,
    char *per_container,
    char *per_pod
    ) {
    v1_node_allocatable_overhead_resources_t *result = v1_node_allocatable_overhead_resources_create_internal (
        name,
        per_container,
        per_pod
        );
    if (!result) {
    }
    return result;
}

void v1_node_allocatable_overhead_resources_free(v1_node_allocatable_overhead_resources_t *v1_node_allocatable_overhead_resources) {
    if(NULL == v1_node_allocatable_overhead_resources){
        return ;
    }
    if(v1_node_allocatable_overhead_resources->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_node_allocatable_overhead_resources_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_node_allocatable_overhead_resources->name) {
        free(v1_node_allocatable_overhead_resources->name);
        v1_node_allocatable_overhead_resources->name = NULL;
    }
    if (v1_node_allocatable_overhead_resources->per_container) {
        free(v1_node_allocatable_overhead_resources->per_container);
        v1_node_allocatable_overhead_resources->per_container = NULL;
    }
    if (v1_node_allocatable_overhead_resources->per_pod) {
        free(v1_node_allocatable_overhead_resources->per_pod);
        v1_node_allocatable_overhead_resources->per_pod = NULL;
    }
    free(v1_node_allocatable_overhead_resources);
}

cJSON *v1_node_allocatable_overhead_resources_convertToJSON(v1_node_allocatable_overhead_resources_t *v1_node_allocatable_overhead_resources) {
    cJSON *item = cJSON_CreateObject();

    // v1_node_allocatable_overhead_resources->name
    if (!v1_node_allocatable_overhead_resources->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_node_allocatable_overhead_resources->name) == NULL) {
    goto fail; //String
    }


    // v1_node_allocatable_overhead_resources->per_container
    if(v1_node_allocatable_overhead_resources->per_container) {
    if(cJSON_AddStringToObject(item, "perContainer", v1_node_allocatable_overhead_resources->per_container) == NULL) {
    goto fail; //String
    }
    }


    // v1_node_allocatable_overhead_resources->per_pod
    if(v1_node_allocatable_overhead_resources->per_pod) {
    if(cJSON_AddStringToObject(item, "perPod", v1_node_allocatable_overhead_resources->per_pod) == NULL) {
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

v1_node_allocatable_overhead_resources_t *v1_node_allocatable_overhead_resources_parseFromJSON(cJSON *v1_node_allocatable_overhead_resourcesJSON){

    v1_node_allocatable_overhead_resources_t *v1_node_allocatable_overhead_resources_local_var = NULL;

    char *name_local_str = NULL;

    char *per_container_local_str = NULL;

    char *per_pod_local_str = NULL;

    // v1_node_allocatable_overhead_resources->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_node_allocatable_overhead_resourcesJSON, "name");
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

    // v1_node_allocatable_overhead_resources->per_container
    cJSON *per_container = cJSON_GetObjectItemCaseSensitive(v1_node_allocatable_overhead_resourcesJSON, "perContainer");
    if (cJSON_IsNull(per_container)) {
        per_container = NULL;
    }
    if (per_container) { 
    if(!cJSON_IsString(per_container) && !cJSON_IsNull(per_container))
    {
    goto end; //String
    }
    }

    // v1_node_allocatable_overhead_resources->per_pod
    cJSON *per_pod = cJSON_GetObjectItemCaseSensitive(v1_node_allocatable_overhead_resourcesJSON, "perPod");
    if (cJSON_IsNull(per_pod)) {
        per_pod = NULL;
    }
    if (per_pod) { 
    if(!cJSON_IsString(per_pod) && !cJSON_IsNull(per_pod))
    {
    goto end; //String
    }
    }


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (per_container && !cJSON_IsNull(per_container)) per_container_local_str = strdup(per_container->valuestring);
    if (per_pod && !cJSON_IsNull(per_pod)) per_pod_local_str = strdup(per_pod->valuestring);

    v1_node_allocatable_overhead_resources_local_var = v1_node_allocatable_overhead_resources_create_internal (
        name_local_str,
        per_container_local_str,
        per_pod_local_str
        );

    if (!v1_node_allocatable_overhead_resources_local_var) {
        goto end;
    }

    return v1_node_allocatable_overhead_resources_local_var;
end:
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
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
