#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha2_resource_class_parameters.h"



v1alpha2_resource_class_parameters_t *v1alpha2_resource_class_parameters_create(
    char *api_version,
    list_t *filters,
    v1alpha2_resource_class_parameters_reference_t *generated_from,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *vendor_parameters
    ) {
    v1alpha2_resource_class_parameters_t *v1alpha2_resource_class_parameters_local_var = malloc(sizeof(v1alpha2_resource_class_parameters_t));
    if (!v1alpha2_resource_class_parameters_local_var) {
        return NULL;
    }
    v1alpha2_resource_class_parameters_local_var->api_version = api_version;
    v1alpha2_resource_class_parameters_local_var->filters = filters;
    v1alpha2_resource_class_parameters_local_var->generated_from = generated_from;
    v1alpha2_resource_class_parameters_local_var->kind = kind;
    v1alpha2_resource_class_parameters_local_var->metadata = metadata;
    v1alpha2_resource_class_parameters_local_var->vendor_parameters = vendor_parameters;

    return v1alpha2_resource_class_parameters_local_var;
}


void v1alpha2_resource_class_parameters_free(v1alpha2_resource_class_parameters_t *v1alpha2_resource_class_parameters) {
    if(NULL == v1alpha2_resource_class_parameters){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha2_resource_class_parameters->api_version) {
        free(v1alpha2_resource_class_parameters->api_version);
        v1alpha2_resource_class_parameters->api_version = NULL;
    }
    if (v1alpha2_resource_class_parameters->filters) {
        list_ForEach(listEntry, v1alpha2_resource_class_parameters->filters) {
            v1alpha2_resource_filter_free(listEntry->data);
        }
        list_freeList(v1alpha2_resource_class_parameters->filters);
        v1alpha2_resource_class_parameters->filters = NULL;
    }
    if (v1alpha2_resource_class_parameters->generated_from) {
        v1alpha2_resource_class_parameters_reference_free(v1alpha2_resource_class_parameters->generated_from);
        v1alpha2_resource_class_parameters->generated_from = NULL;
    }
    if (v1alpha2_resource_class_parameters->kind) {
        free(v1alpha2_resource_class_parameters->kind);
        v1alpha2_resource_class_parameters->kind = NULL;
    }
    if (v1alpha2_resource_class_parameters->metadata) {
        v1_object_meta_free(v1alpha2_resource_class_parameters->metadata);
        v1alpha2_resource_class_parameters->metadata = NULL;
    }
    if (v1alpha2_resource_class_parameters->vendor_parameters) {
        list_ForEach(listEntry, v1alpha2_resource_class_parameters->vendor_parameters) {
            v1alpha2_vendor_parameters_free(listEntry->data);
        }
        list_freeList(v1alpha2_resource_class_parameters->vendor_parameters);
        v1alpha2_resource_class_parameters->vendor_parameters = NULL;
    }
    free(v1alpha2_resource_class_parameters);
}

cJSON *v1alpha2_resource_class_parameters_convertToJSON(v1alpha2_resource_class_parameters_t *v1alpha2_resource_class_parameters) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha2_resource_class_parameters->api_version
    if(v1alpha2_resource_class_parameters->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1alpha2_resource_class_parameters->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha2_resource_class_parameters->filters
    if(v1alpha2_resource_class_parameters->filters) {
    cJSON *filters = cJSON_AddArrayToObject(item, "filters");
    if(filters == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *filtersListEntry;
    if (v1alpha2_resource_class_parameters->filters) {
    list_ForEach(filtersListEntry, v1alpha2_resource_class_parameters->filters) {
    cJSON *itemLocal = v1alpha2_resource_filter_convertToJSON(filtersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(filters, itemLocal);
    }
    }
    }


    // v1alpha2_resource_class_parameters->generated_from
    if(v1alpha2_resource_class_parameters->generated_from) {
    cJSON *generated_from_local_JSON = v1alpha2_resource_class_parameters_reference_convertToJSON(v1alpha2_resource_class_parameters->generated_from);
    if(generated_from_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "generatedFrom", generated_from_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha2_resource_class_parameters->kind
    if(v1alpha2_resource_class_parameters->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1alpha2_resource_class_parameters->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha2_resource_class_parameters->metadata
    if(v1alpha2_resource_class_parameters->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1alpha2_resource_class_parameters->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha2_resource_class_parameters->vendor_parameters
    if(v1alpha2_resource_class_parameters->vendor_parameters) {
    cJSON *vendor_parameters = cJSON_AddArrayToObject(item, "vendorParameters");
    if(vendor_parameters == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *vendor_parametersListEntry;
    if (v1alpha2_resource_class_parameters->vendor_parameters) {
    list_ForEach(vendor_parametersListEntry, v1alpha2_resource_class_parameters->vendor_parameters) {
    cJSON *itemLocal = v1alpha2_vendor_parameters_convertToJSON(vendor_parametersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(vendor_parameters, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha2_resource_class_parameters_t *v1alpha2_resource_class_parameters_parseFromJSON(cJSON *v1alpha2_resource_class_parametersJSON){

    v1alpha2_resource_class_parameters_t *v1alpha2_resource_class_parameters_local_var = NULL;

    // define the local list for v1alpha2_resource_class_parameters->filters
    list_t *filtersList = NULL;

    // define the local variable for v1alpha2_resource_class_parameters->generated_from
    v1alpha2_resource_class_parameters_reference_t *generated_from_local_nonprim = NULL;

    // define the local variable for v1alpha2_resource_class_parameters->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local list for v1alpha2_resource_class_parameters->vendor_parameters
    list_t *vendor_parametersList = NULL;

    // v1alpha2_resource_class_parameters->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1alpha2_resource_class_parametersJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1alpha2_resource_class_parameters->filters
    cJSON *filters = cJSON_GetObjectItemCaseSensitive(v1alpha2_resource_class_parametersJSON, "filters");
    if (filters) { 
    cJSON *filters_local_nonprimitive = NULL;
    if(!cJSON_IsArray(filters)){
        goto end; //nonprimitive container
    }

    filtersList = list_createList();

    cJSON_ArrayForEach(filters_local_nonprimitive,filters )
    {
        if(!cJSON_IsObject(filters_local_nonprimitive)){
            goto end;
        }
        v1alpha2_resource_filter_t *filtersItem = v1alpha2_resource_filter_parseFromJSON(filters_local_nonprimitive);

        list_addElement(filtersList, filtersItem);
    }
    }

    // v1alpha2_resource_class_parameters->generated_from
    cJSON *generated_from = cJSON_GetObjectItemCaseSensitive(v1alpha2_resource_class_parametersJSON, "generatedFrom");
    if (generated_from) { 
    generated_from_local_nonprim = v1alpha2_resource_class_parameters_reference_parseFromJSON(generated_from); //nonprimitive
    }

    // v1alpha2_resource_class_parameters->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha2_resource_class_parametersJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1alpha2_resource_class_parameters->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1alpha2_resource_class_parametersJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1alpha2_resource_class_parameters->vendor_parameters
    cJSON *vendor_parameters = cJSON_GetObjectItemCaseSensitive(v1alpha2_resource_class_parametersJSON, "vendorParameters");
    if (vendor_parameters) { 
    cJSON *vendor_parameters_local_nonprimitive = NULL;
    if(!cJSON_IsArray(vendor_parameters)){
        goto end; //nonprimitive container
    }

    vendor_parametersList = list_createList();

    cJSON_ArrayForEach(vendor_parameters_local_nonprimitive,vendor_parameters )
    {
        if(!cJSON_IsObject(vendor_parameters_local_nonprimitive)){
            goto end;
        }
        v1alpha2_vendor_parameters_t *vendor_parametersItem = v1alpha2_vendor_parameters_parseFromJSON(vendor_parameters_local_nonprimitive);

        list_addElement(vendor_parametersList, vendor_parametersItem);
    }
    }


    v1alpha2_resource_class_parameters_local_var = v1alpha2_resource_class_parameters_create (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        filters ? filtersList : NULL,
        generated_from ? generated_from_local_nonprim : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        vendor_parameters ? vendor_parametersList : NULL
        );

    return v1alpha2_resource_class_parameters_local_var;
end:
    if (filtersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, filtersList) {
            v1alpha2_resource_filter_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(filtersList);
        filtersList = NULL;
    }
    if (generated_from_local_nonprim) {
        v1alpha2_resource_class_parameters_reference_free(generated_from_local_nonprim);
        generated_from_local_nonprim = NULL;
    }
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (vendor_parametersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, vendor_parametersList) {
            v1alpha2_vendor_parameters_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(vendor_parametersList);
        vendor_parametersList = NULL;
    }
    return NULL;

}
