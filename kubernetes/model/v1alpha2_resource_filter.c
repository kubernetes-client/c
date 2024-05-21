#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha2_resource_filter.h"



v1alpha2_resource_filter_t *v1alpha2_resource_filter_create(
    char *driver_name,
    v1alpha2_named_resources_filter_t *named_resources
    ) {
    v1alpha2_resource_filter_t *v1alpha2_resource_filter_local_var = malloc(sizeof(v1alpha2_resource_filter_t));
    if (!v1alpha2_resource_filter_local_var) {
        return NULL;
    }
    v1alpha2_resource_filter_local_var->driver_name = driver_name;
    v1alpha2_resource_filter_local_var->named_resources = named_resources;

    return v1alpha2_resource_filter_local_var;
}


void v1alpha2_resource_filter_free(v1alpha2_resource_filter_t *v1alpha2_resource_filter) {
    if(NULL == v1alpha2_resource_filter){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha2_resource_filter->driver_name) {
        free(v1alpha2_resource_filter->driver_name);
        v1alpha2_resource_filter->driver_name = NULL;
    }
    if (v1alpha2_resource_filter->named_resources) {
        v1alpha2_named_resources_filter_free(v1alpha2_resource_filter->named_resources);
        v1alpha2_resource_filter->named_resources = NULL;
    }
    free(v1alpha2_resource_filter);
}

cJSON *v1alpha2_resource_filter_convertToJSON(v1alpha2_resource_filter_t *v1alpha2_resource_filter) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha2_resource_filter->driver_name
    if(v1alpha2_resource_filter->driver_name) {
    if(cJSON_AddStringToObject(item, "driverName", v1alpha2_resource_filter->driver_name) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha2_resource_filter->named_resources
    if(v1alpha2_resource_filter->named_resources) {
    cJSON *named_resources_local_JSON = v1alpha2_named_resources_filter_convertToJSON(v1alpha2_resource_filter->named_resources);
    if(named_resources_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "namedResources", named_resources_local_JSON);
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

v1alpha2_resource_filter_t *v1alpha2_resource_filter_parseFromJSON(cJSON *v1alpha2_resource_filterJSON){

    v1alpha2_resource_filter_t *v1alpha2_resource_filter_local_var = NULL;

    // define the local variable for v1alpha2_resource_filter->named_resources
    v1alpha2_named_resources_filter_t *named_resources_local_nonprim = NULL;

    // v1alpha2_resource_filter->driver_name
    cJSON *driver_name = cJSON_GetObjectItemCaseSensitive(v1alpha2_resource_filterJSON, "driverName");
    if (driver_name) { 
    if(!cJSON_IsString(driver_name) && !cJSON_IsNull(driver_name))
    {
    goto end; //String
    }
    }

    // v1alpha2_resource_filter->named_resources
    cJSON *named_resources = cJSON_GetObjectItemCaseSensitive(v1alpha2_resource_filterJSON, "namedResources");
    if (named_resources) { 
    named_resources_local_nonprim = v1alpha2_named_resources_filter_parseFromJSON(named_resources); //nonprimitive
    }


    v1alpha2_resource_filter_local_var = v1alpha2_resource_filter_create (
        driver_name && !cJSON_IsNull(driver_name) ? strdup(driver_name->valuestring) : NULL,
        named_resources ? named_resources_local_nonprim : NULL
        );

    return v1alpha2_resource_filter_local_var;
end:
    if (named_resources_local_nonprim) {
        v1alpha2_named_resources_filter_free(named_resources_local_nonprim);
        named_resources_local_nonprim = NULL;
    }
    return NULL;

}
