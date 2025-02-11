#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_resource_field_selector.h"



static v1_resource_field_selector_t *v1_resource_field_selector_create_internal(
    char *container_name,
    char *divisor,
    char *resource
    ) {
    v1_resource_field_selector_t *v1_resource_field_selector_local_var = malloc(sizeof(v1_resource_field_selector_t));
    if (!v1_resource_field_selector_local_var) {
        return NULL;
    }
    v1_resource_field_selector_local_var->container_name = container_name;
    v1_resource_field_selector_local_var->divisor = divisor;
    v1_resource_field_selector_local_var->resource = resource;

    v1_resource_field_selector_local_var->_library_owned = 1;
    return v1_resource_field_selector_local_var;
}

__attribute__((deprecated)) v1_resource_field_selector_t *v1_resource_field_selector_create(
    char *container_name,
    char *divisor,
    char *resource
    ) {
    return v1_resource_field_selector_create_internal (
        container_name,
        divisor,
        resource
        );
}

void v1_resource_field_selector_free(v1_resource_field_selector_t *v1_resource_field_selector) {
    if(NULL == v1_resource_field_selector){
        return ;
    }
    if(v1_resource_field_selector->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_resource_field_selector_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_resource_field_selector->container_name) {
        free(v1_resource_field_selector->container_name);
        v1_resource_field_selector->container_name = NULL;
    }
    if (v1_resource_field_selector->divisor) {
        free(v1_resource_field_selector->divisor);
        v1_resource_field_selector->divisor = NULL;
    }
    if (v1_resource_field_selector->resource) {
        free(v1_resource_field_selector->resource);
        v1_resource_field_selector->resource = NULL;
    }
    free(v1_resource_field_selector);
}

cJSON *v1_resource_field_selector_convertToJSON(v1_resource_field_selector_t *v1_resource_field_selector) {
    cJSON *item = cJSON_CreateObject();

    // v1_resource_field_selector->container_name
    if(v1_resource_field_selector->container_name) {
    if(cJSON_AddStringToObject(item, "containerName", v1_resource_field_selector->container_name) == NULL) {
    goto fail; //String
    }
    }


    // v1_resource_field_selector->divisor
    if(v1_resource_field_selector->divisor) {
    if(cJSON_AddStringToObject(item, "divisor", v1_resource_field_selector->divisor) == NULL) {
    goto fail; //String
    }
    }


    // v1_resource_field_selector->resource
    if (!v1_resource_field_selector->resource) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "resource", v1_resource_field_selector->resource) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_resource_field_selector_t *v1_resource_field_selector_parseFromJSON(cJSON *v1_resource_field_selectorJSON){

    v1_resource_field_selector_t *v1_resource_field_selector_local_var = NULL;

    // v1_resource_field_selector->container_name
    cJSON *container_name = cJSON_GetObjectItemCaseSensitive(v1_resource_field_selectorJSON, "containerName");
    if (cJSON_IsNull(container_name)) {
        container_name = NULL;
    }
    if (container_name) { 
    if(!cJSON_IsString(container_name) && !cJSON_IsNull(container_name))
    {
    goto end; //String
    }
    }

    // v1_resource_field_selector->divisor
    cJSON *divisor = cJSON_GetObjectItemCaseSensitive(v1_resource_field_selectorJSON, "divisor");
    if (cJSON_IsNull(divisor)) {
        divisor = NULL;
    }
    if (divisor) { 
    if(!cJSON_IsString(divisor) && !cJSON_IsNull(divisor))
    {
    goto end; //String
    }
    }

    // v1_resource_field_selector->resource
    cJSON *resource = cJSON_GetObjectItemCaseSensitive(v1_resource_field_selectorJSON, "resource");
    if (cJSON_IsNull(resource)) {
        resource = NULL;
    }
    if (!resource) {
        goto end;
    }

    
    if(!cJSON_IsString(resource))
    {
    goto end; //String
    }


    v1_resource_field_selector_local_var = v1_resource_field_selector_create_internal (
        container_name && !cJSON_IsNull(container_name) ? strdup(container_name->valuestring) : NULL,
        divisor && !cJSON_IsNull(divisor) ? strdup(divisor->valuestring) : NULL,
        strdup(resource->valuestring)
        );

    return v1_resource_field_selector_local_var;
end:
    return NULL;

}
