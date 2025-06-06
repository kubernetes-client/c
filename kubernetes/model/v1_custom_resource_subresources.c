#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_custom_resource_subresources.h"



static v1_custom_resource_subresources_t *v1_custom_resource_subresources_create_internal(
    v1_custom_resource_subresource_scale_t *scale,
    object_t *status
    ) {
    v1_custom_resource_subresources_t *v1_custom_resource_subresources_local_var = malloc(sizeof(v1_custom_resource_subresources_t));
    if (!v1_custom_resource_subresources_local_var) {
        return NULL;
    }
    v1_custom_resource_subresources_local_var->scale = scale;
    v1_custom_resource_subresources_local_var->status = status;

    v1_custom_resource_subresources_local_var->_library_owned = 1;
    return v1_custom_resource_subresources_local_var;
}

__attribute__((deprecated)) v1_custom_resource_subresources_t *v1_custom_resource_subresources_create(
    v1_custom_resource_subresource_scale_t *scale,
    object_t *status
    ) {
    return v1_custom_resource_subresources_create_internal (
        scale,
        status
        );
}

void v1_custom_resource_subresources_free(v1_custom_resource_subresources_t *v1_custom_resource_subresources) {
    if(NULL == v1_custom_resource_subresources){
        return ;
    }
    if(v1_custom_resource_subresources->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_custom_resource_subresources_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_custom_resource_subresources->scale) {
        v1_custom_resource_subresource_scale_free(v1_custom_resource_subresources->scale);
        v1_custom_resource_subresources->scale = NULL;
    }
    if (v1_custom_resource_subresources->status) {
        object_free(v1_custom_resource_subresources->status);
        v1_custom_resource_subresources->status = NULL;
    }
    free(v1_custom_resource_subresources);
}

cJSON *v1_custom_resource_subresources_convertToJSON(v1_custom_resource_subresources_t *v1_custom_resource_subresources) {
    cJSON *item = cJSON_CreateObject();

    // v1_custom_resource_subresources->scale
    if(v1_custom_resource_subresources->scale) {
    cJSON *scale_local_JSON = v1_custom_resource_subresource_scale_convertToJSON(v1_custom_resource_subresources->scale);
    if(scale_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "scale", scale_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_custom_resource_subresources->status
    if(v1_custom_resource_subresources->status) {
    cJSON *status_object = object_convertToJSON(v1_custom_resource_subresources->status);
    if(status_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "status", status_object);
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

v1_custom_resource_subresources_t *v1_custom_resource_subresources_parseFromJSON(cJSON *v1_custom_resource_subresourcesJSON){

    v1_custom_resource_subresources_t *v1_custom_resource_subresources_local_var = NULL;

    // define the local variable for v1_custom_resource_subresources->scale
    v1_custom_resource_subresource_scale_t *scale_local_nonprim = NULL;

    // v1_custom_resource_subresources->scale
    cJSON *scale = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_subresourcesJSON, "scale");
    if (cJSON_IsNull(scale)) {
        scale = NULL;
    }
    if (scale) { 
    scale_local_nonprim = v1_custom_resource_subresource_scale_parseFromJSON(scale); //nonprimitive
    }

    // v1_custom_resource_subresources->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_subresourcesJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    object_t *status_local_object = NULL;
    if (status) { 
    status_local_object = object_parseFromJSON(status); //object
    }


    v1_custom_resource_subresources_local_var = v1_custom_resource_subresources_create_internal (
        scale ? scale_local_nonprim : NULL,
        status ? status_local_object : NULL
        );

    return v1_custom_resource_subresources_local_var;
end:
    if (scale_local_nonprim) {
        v1_custom_resource_subresource_scale_free(scale_local_nonprim);
        scale_local_nonprim = NULL;
    }
    return NULL;

}
