#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha2_resource_class.h"



v1alpha2_resource_class_t *v1alpha2_resource_class_create(
    char *api_version,
    char *driver_name,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha2_resource_class_parameters_reference_t *parameters_ref,
    int structured_parameters,
    v1_node_selector_t *suitable_nodes
    ) {
    v1alpha2_resource_class_t *v1alpha2_resource_class_local_var = malloc(sizeof(v1alpha2_resource_class_t));
    if (!v1alpha2_resource_class_local_var) {
        return NULL;
    }
    v1alpha2_resource_class_local_var->api_version = api_version;
    v1alpha2_resource_class_local_var->driver_name = driver_name;
    v1alpha2_resource_class_local_var->kind = kind;
    v1alpha2_resource_class_local_var->metadata = metadata;
    v1alpha2_resource_class_local_var->parameters_ref = parameters_ref;
    v1alpha2_resource_class_local_var->structured_parameters = structured_parameters;
    v1alpha2_resource_class_local_var->suitable_nodes = suitable_nodes;

    return v1alpha2_resource_class_local_var;
}


void v1alpha2_resource_class_free(v1alpha2_resource_class_t *v1alpha2_resource_class) {
    if(NULL == v1alpha2_resource_class){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha2_resource_class->api_version) {
        free(v1alpha2_resource_class->api_version);
        v1alpha2_resource_class->api_version = NULL;
    }
    if (v1alpha2_resource_class->driver_name) {
        free(v1alpha2_resource_class->driver_name);
        v1alpha2_resource_class->driver_name = NULL;
    }
    if (v1alpha2_resource_class->kind) {
        free(v1alpha2_resource_class->kind);
        v1alpha2_resource_class->kind = NULL;
    }
    if (v1alpha2_resource_class->metadata) {
        v1_object_meta_free(v1alpha2_resource_class->metadata);
        v1alpha2_resource_class->metadata = NULL;
    }
    if (v1alpha2_resource_class->parameters_ref) {
        v1alpha2_resource_class_parameters_reference_free(v1alpha2_resource_class->parameters_ref);
        v1alpha2_resource_class->parameters_ref = NULL;
    }
    if (v1alpha2_resource_class->suitable_nodes) {
        v1_node_selector_free(v1alpha2_resource_class->suitable_nodes);
        v1alpha2_resource_class->suitable_nodes = NULL;
    }
    free(v1alpha2_resource_class);
}

cJSON *v1alpha2_resource_class_convertToJSON(v1alpha2_resource_class_t *v1alpha2_resource_class) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha2_resource_class->api_version
    if(v1alpha2_resource_class->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1alpha2_resource_class->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha2_resource_class->driver_name
    if (!v1alpha2_resource_class->driver_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "driverName", v1alpha2_resource_class->driver_name) == NULL) {
    goto fail; //String
    }


    // v1alpha2_resource_class->kind
    if(v1alpha2_resource_class->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1alpha2_resource_class->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha2_resource_class->metadata
    if(v1alpha2_resource_class->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1alpha2_resource_class->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha2_resource_class->parameters_ref
    if(v1alpha2_resource_class->parameters_ref) {
    cJSON *parameters_ref_local_JSON = v1alpha2_resource_class_parameters_reference_convertToJSON(v1alpha2_resource_class->parameters_ref);
    if(parameters_ref_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "parametersRef", parameters_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha2_resource_class->structured_parameters
    if(v1alpha2_resource_class->structured_parameters) {
    if(cJSON_AddBoolToObject(item, "structuredParameters", v1alpha2_resource_class->structured_parameters) == NULL) {
    goto fail; //Bool
    }
    }


    // v1alpha2_resource_class->suitable_nodes
    if(v1alpha2_resource_class->suitable_nodes) {
    cJSON *suitable_nodes_local_JSON = v1_node_selector_convertToJSON(v1alpha2_resource_class->suitable_nodes);
    if(suitable_nodes_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "suitableNodes", suitable_nodes_local_JSON);
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

v1alpha2_resource_class_t *v1alpha2_resource_class_parseFromJSON(cJSON *v1alpha2_resource_classJSON){

    v1alpha2_resource_class_t *v1alpha2_resource_class_local_var = NULL;

    // define the local variable for v1alpha2_resource_class->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1alpha2_resource_class->parameters_ref
    v1alpha2_resource_class_parameters_reference_t *parameters_ref_local_nonprim = NULL;

    // define the local variable for v1alpha2_resource_class->suitable_nodes
    v1_node_selector_t *suitable_nodes_local_nonprim = NULL;

    // v1alpha2_resource_class->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1alpha2_resource_classJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1alpha2_resource_class->driver_name
    cJSON *driver_name = cJSON_GetObjectItemCaseSensitive(v1alpha2_resource_classJSON, "driverName");
    if (!driver_name) {
        goto end;
    }

    
    if(!cJSON_IsString(driver_name))
    {
    goto end; //String
    }

    // v1alpha2_resource_class->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha2_resource_classJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1alpha2_resource_class->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1alpha2_resource_classJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1alpha2_resource_class->parameters_ref
    cJSON *parameters_ref = cJSON_GetObjectItemCaseSensitive(v1alpha2_resource_classJSON, "parametersRef");
    if (parameters_ref) { 
    parameters_ref_local_nonprim = v1alpha2_resource_class_parameters_reference_parseFromJSON(parameters_ref); //nonprimitive
    }

    // v1alpha2_resource_class->structured_parameters
    cJSON *structured_parameters = cJSON_GetObjectItemCaseSensitive(v1alpha2_resource_classJSON, "structuredParameters");
    if (structured_parameters) { 
    if(!cJSON_IsBool(structured_parameters))
    {
    goto end; //Bool
    }
    }

    // v1alpha2_resource_class->suitable_nodes
    cJSON *suitable_nodes = cJSON_GetObjectItemCaseSensitive(v1alpha2_resource_classJSON, "suitableNodes");
    if (suitable_nodes) { 
    suitable_nodes_local_nonprim = v1_node_selector_parseFromJSON(suitable_nodes); //nonprimitive
    }


    v1alpha2_resource_class_local_var = v1alpha2_resource_class_create (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        strdup(driver_name->valuestring),
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        parameters_ref ? parameters_ref_local_nonprim : NULL,
        structured_parameters ? structured_parameters->valueint : 0,
        suitable_nodes ? suitable_nodes_local_nonprim : NULL
        );

    return v1alpha2_resource_class_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (parameters_ref_local_nonprim) {
        v1alpha2_resource_class_parameters_reference_free(parameters_ref_local_nonprim);
        parameters_ref_local_nonprim = NULL;
    }
    if (suitable_nodes_local_nonprim) {
        v1_node_selector_free(suitable_nodes_local_nonprim);
        suitable_nodes_local_nonprim = NULL;
    }
    return NULL;

}
