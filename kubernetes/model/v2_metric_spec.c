#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2_metric_spec.h"



v2_metric_spec_t *v2_metric_spec_create(
    v2_container_resource_metric_source_t *container_resource,
    v2_external_metric_source_t *external,
    v2_object_metric_source_t *object,
    v2_pods_metric_source_t *pods,
    v2_resource_metric_source_t *resource,
    char *type
    ) {
    v2_metric_spec_t *v2_metric_spec_local_var = malloc(sizeof(v2_metric_spec_t));
    if (!v2_metric_spec_local_var) {
        return NULL;
    }
    v2_metric_spec_local_var->container_resource = container_resource;
    v2_metric_spec_local_var->external = external;
    v2_metric_spec_local_var->object = object;
    v2_metric_spec_local_var->pods = pods;
    v2_metric_spec_local_var->resource = resource;
    v2_metric_spec_local_var->type = type;

    return v2_metric_spec_local_var;
}


void v2_metric_spec_free(v2_metric_spec_t *v2_metric_spec) {
    if(NULL == v2_metric_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v2_metric_spec->container_resource) {
        v2_container_resource_metric_source_free(v2_metric_spec->container_resource);
        v2_metric_spec->container_resource = NULL;
    }
    if (v2_metric_spec->external) {
        v2_external_metric_source_free(v2_metric_spec->external);
        v2_metric_spec->external = NULL;
    }
    if (v2_metric_spec->object) {
        v2_object_metric_source_free(v2_metric_spec->object);
        v2_metric_spec->object = NULL;
    }
    if (v2_metric_spec->pods) {
        v2_pods_metric_source_free(v2_metric_spec->pods);
        v2_metric_spec->pods = NULL;
    }
    if (v2_metric_spec->resource) {
        v2_resource_metric_source_free(v2_metric_spec->resource);
        v2_metric_spec->resource = NULL;
    }
    if (v2_metric_spec->type) {
        free(v2_metric_spec->type);
        v2_metric_spec->type = NULL;
    }
    free(v2_metric_spec);
}

cJSON *v2_metric_spec_convertToJSON(v2_metric_spec_t *v2_metric_spec) {
    cJSON *item = cJSON_CreateObject();

    // v2_metric_spec->container_resource
    if(v2_metric_spec->container_resource) { 
    cJSON *container_resource_local_JSON = v2_container_resource_metric_source_convertToJSON(v2_metric_spec->container_resource);
    if(container_resource_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "containerResource", container_resource_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v2_metric_spec->external
    if(v2_metric_spec->external) { 
    cJSON *external_local_JSON = v2_external_metric_source_convertToJSON(v2_metric_spec->external);
    if(external_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "external", external_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v2_metric_spec->object
    if(v2_metric_spec->object) { 
    cJSON *object_local_JSON = v2_object_metric_source_convertToJSON(v2_metric_spec->object);
    if(object_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "object", object_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v2_metric_spec->pods
    if(v2_metric_spec->pods) { 
    cJSON *pods_local_JSON = v2_pods_metric_source_convertToJSON(v2_metric_spec->pods);
    if(pods_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "pods", pods_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v2_metric_spec->resource
    if(v2_metric_spec->resource) { 
    cJSON *resource_local_JSON = v2_resource_metric_source_convertToJSON(v2_metric_spec->resource);
    if(resource_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "resource", resource_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v2_metric_spec->type
    if (!v2_metric_spec->type) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "type", v2_metric_spec->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v2_metric_spec_t *v2_metric_spec_parseFromJSON(cJSON *v2_metric_specJSON){

    v2_metric_spec_t *v2_metric_spec_local_var = NULL;

    // define the local variable for v2_metric_spec->container_resource
    v2_container_resource_metric_source_t *container_resource_local_nonprim = NULL;

    // define the local variable for v2_metric_spec->external
    v2_external_metric_source_t *external_local_nonprim = NULL;

    // define the local variable for v2_metric_spec->object
    v2_object_metric_source_t *object_local_nonprim = NULL;

    // define the local variable for v2_metric_spec->pods
    v2_pods_metric_source_t *pods_local_nonprim = NULL;

    // define the local variable for v2_metric_spec->resource
    v2_resource_metric_source_t *resource_local_nonprim = NULL;

    // v2_metric_spec->container_resource
    cJSON *container_resource = cJSON_GetObjectItemCaseSensitive(v2_metric_specJSON, "containerResource");
    if (container_resource) { 
    container_resource_local_nonprim = v2_container_resource_metric_source_parseFromJSON(container_resource); //nonprimitive
    }

    // v2_metric_spec->external
    cJSON *external = cJSON_GetObjectItemCaseSensitive(v2_metric_specJSON, "external");
    if (external) { 
    external_local_nonprim = v2_external_metric_source_parseFromJSON(external); //nonprimitive
    }

    // v2_metric_spec->object
    cJSON *object = cJSON_GetObjectItemCaseSensitive(v2_metric_specJSON, "object");
    if (object) { 
    object_local_nonprim = v2_object_metric_source_parseFromJSON(object); //nonprimitive
    }

    // v2_metric_spec->pods
    cJSON *pods = cJSON_GetObjectItemCaseSensitive(v2_metric_specJSON, "pods");
    if (pods) { 
    pods_local_nonprim = v2_pods_metric_source_parseFromJSON(pods); //nonprimitive
    }

    // v2_metric_spec->resource
    cJSON *resource = cJSON_GetObjectItemCaseSensitive(v2_metric_specJSON, "resource");
    if (resource) { 
    resource_local_nonprim = v2_resource_metric_source_parseFromJSON(resource); //nonprimitive
    }

    // v2_metric_spec->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v2_metric_specJSON, "type");
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }


    v2_metric_spec_local_var = v2_metric_spec_create (
        container_resource ? container_resource_local_nonprim : NULL,
        external ? external_local_nonprim : NULL,
        object ? object_local_nonprim : NULL,
        pods ? pods_local_nonprim : NULL,
        resource ? resource_local_nonprim : NULL,
        strdup(type->valuestring)
        );

    return v2_metric_spec_local_var;
end:
    if (container_resource_local_nonprim) {
        v2_container_resource_metric_source_free(container_resource_local_nonprim);
        container_resource_local_nonprim = NULL;
    }
    if (external_local_nonprim) {
        v2_external_metric_source_free(external_local_nonprim);
        external_local_nonprim = NULL;
    }
    if (object_local_nonprim) {
        v2_object_metric_source_free(object_local_nonprim);
        object_local_nonprim = NULL;
    }
    if (pods_local_nonprim) {
        v2_pods_metric_source_free(pods_local_nonprim);
        pods_local_nonprim = NULL;
    }
    if (resource_local_nonprim) {
        v2_resource_metric_source_free(resource_local_nonprim);
        resource_local_nonprim = NULL;
    }
    return NULL;

}
