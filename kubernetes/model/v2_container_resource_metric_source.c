#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2_container_resource_metric_source.h"



static v2_container_resource_metric_source_t *v2_container_resource_metric_source_create_internal(
    char *container,
    char *name,
    v2_metric_target_t *target
    ) {
    v2_container_resource_metric_source_t *v2_container_resource_metric_source_local_var = malloc(sizeof(v2_container_resource_metric_source_t));
    if (!v2_container_resource_metric_source_local_var) {
        return NULL;
    }
    v2_container_resource_metric_source_local_var->container = container;
    v2_container_resource_metric_source_local_var->name = name;
    v2_container_resource_metric_source_local_var->target = target;

    v2_container_resource_metric_source_local_var->_library_owned = 1;
    return v2_container_resource_metric_source_local_var;
}

__attribute__((deprecated)) v2_container_resource_metric_source_t *v2_container_resource_metric_source_create(
    char *container,
    char *name,
    v2_metric_target_t *target
    ) {
    return v2_container_resource_metric_source_create_internal (
        container,
        name,
        target
        );
}

void v2_container_resource_metric_source_free(v2_container_resource_metric_source_t *v2_container_resource_metric_source) {
    if(NULL == v2_container_resource_metric_source){
        return ;
    }
    if(v2_container_resource_metric_source->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v2_container_resource_metric_source_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v2_container_resource_metric_source->container) {
        free(v2_container_resource_metric_source->container);
        v2_container_resource_metric_source->container = NULL;
    }
    if (v2_container_resource_metric_source->name) {
        free(v2_container_resource_metric_source->name);
        v2_container_resource_metric_source->name = NULL;
    }
    if (v2_container_resource_metric_source->target) {
        v2_metric_target_free(v2_container_resource_metric_source->target);
        v2_container_resource_metric_source->target = NULL;
    }
    free(v2_container_resource_metric_source);
}

cJSON *v2_container_resource_metric_source_convertToJSON(v2_container_resource_metric_source_t *v2_container_resource_metric_source) {
    cJSON *item = cJSON_CreateObject();

    // v2_container_resource_metric_source->container
    if (!v2_container_resource_metric_source->container) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "container", v2_container_resource_metric_source->container) == NULL) {
    goto fail; //String
    }


    // v2_container_resource_metric_source->name
    if (!v2_container_resource_metric_source->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v2_container_resource_metric_source->name) == NULL) {
    goto fail; //String
    }


    // v2_container_resource_metric_source->target
    if (!v2_container_resource_metric_source->target) {
        goto fail;
    }
    cJSON *target_local_JSON = v2_metric_target_convertToJSON(v2_container_resource_metric_source->target);
    if(target_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "target", target_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v2_container_resource_metric_source_t *v2_container_resource_metric_source_parseFromJSON(cJSON *v2_container_resource_metric_sourceJSON){

    v2_container_resource_metric_source_t *v2_container_resource_metric_source_local_var = NULL;

    // define the local variable for v2_container_resource_metric_source->target
    v2_metric_target_t *target_local_nonprim = NULL;

    // v2_container_resource_metric_source->container
    cJSON *container = cJSON_GetObjectItemCaseSensitive(v2_container_resource_metric_sourceJSON, "container");
    if (cJSON_IsNull(container)) {
        container = NULL;
    }
    if (!container) {
        goto end;
    }

    
    if(!cJSON_IsString(container))
    {
    goto end; //String
    }

    // v2_container_resource_metric_source->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v2_container_resource_metric_sourceJSON, "name");
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

    // v2_container_resource_metric_source->target
    cJSON *target = cJSON_GetObjectItemCaseSensitive(v2_container_resource_metric_sourceJSON, "target");
    if (cJSON_IsNull(target)) {
        target = NULL;
    }
    if (!target) {
        goto end;
    }

    
    target_local_nonprim = v2_metric_target_parseFromJSON(target); //nonprimitive


    v2_container_resource_metric_source_local_var = v2_container_resource_metric_source_create_internal (
        strdup(container->valuestring),
        strdup(name->valuestring),
        target_local_nonprim
        );

    return v2_container_resource_metric_source_local_var;
end:
    if (target_local_nonprim) {
        v2_metric_target_free(target_local_nonprim);
        target_local_nonprim = NULL;
    }
    return NULL;

}
