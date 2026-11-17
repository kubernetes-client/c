#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_device_sub_request.h"



static v1beta2_device_sub_request_t *v1beta2_device_sub_request_create_internal(
    char *allocation_mode,
    v1beta2_capacity_requirements_t *capacity,
    long *count,
    list_t *derived_attributes,
    char *device_class_name,
    char *name,
    list_t *selectors,
    list_t *tolerations
    ) {
    v1beta2_device_sub_request_t *v1beta2_device_sub_request_local_var = malloc(sizeof(v1beta2_device_sub_request_t));
    if (!v1beta2_device_sub_request_local_var) {
        return NULL;
    }
    memset(v1beta2_device_sub_request_local_var, 0, sizeof(v1beta2_device_sub_request_t));
    v1beta2_device_sub_request_local_var->_library_owned = 1;
    v1beta2_device_sub_request_local_var->allocation_mode = allocation_mode;
    v1beta2_device_sub_request_local_var->capacity = capacity;
    v1beta2_device_sub_request_local_var->count = count;
    v1beta2_device_sub_request_local_var->derived_attributes = derived_attributes;
    v1beta2_device_sub_request_local_var->device_class_name = device_class_name;
    v1beta2_device_sub_request_local_var->name = name;
    v1beta2_device_sub_request_local_var->selectors = selectors;
    v1beta2_device_sub_request_local_var->tolerations = tolerations;
    return v1beta2_device_sub_request_local_var;
}

__attribute__((deprecated)) v1beta2_device_sub_request_t *v1beta2_device_sub_request_create(
    char *allocation_mode,
    v1beta2_capacity_requirements_t *capacity,
    long *count,
    list_t *derived_attributes,
    char *device_class_name,
    char *name,
    list_t *selectors,
    list_t *tolerations
    ) {
    long *count_copy = NULL;
    if (count) {
        count_copy = malloc(sizeof(long));
        if (count_copy) *count_copy = *count;
    }
    v1beta2_device_sub_request_t *result = v1beta2_device_sub_request_create_internal (
        allocation_mode,
        capacity,
        count_copy,
        derived_attributes,
        device_class_name,
        name,
        selectors,
        tolerations
        );
    if (!result) {
        free(count_copy);
    }
    return result;
}

void v1beta2_device_sub_request_free(v1beta2_device_sub_request_t *v1beta2_device_sub_request) {
    if(NULL == v1beta2_device_sub_request){
        return ;
    }
    if(v1beta2_device_sub_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta2_device_sub_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta2_device_sub_request->allocation_mode) {
        free(v1beta2_device_sub_request->allocation_mode);
        v1beta2_device_sub_request->allocation_mode = NULL;
    }
    if (v1beta2_device_sub_request->capacity) {
        v1beta2_capacity_requirements_free(v1beta2_device_sub_request->capacity);
        v1beta2_device_sub_request->capacity = NULL;
    }
    if (v1beta2_device_sub_request->count) {
        free(v1beta2_device_sub_request->count);
        v1beta2_device_sub_request->count = NULL;
    }
    if (v1beta2_device_sub_request->derived_attributes) {
        list_ForEach(listEntry, v1beta2_device_sub_request->derived_attributes) {
            v1beta2_device_derived_attribute_free(listEntry->data);
        }
        list_freeList(v1beta2_device_sub_request->derived_attributes);
        v1beta2_device_sub_request->derived_attributes = NULL;
    }
    if (v1beta2_device_sub_request->device_class_name) {
        free(v1beta2_device_sub_request->device_class_name);
        v1beta2_device_sub_request->device_class_name = NULL;
    }
    if (v1beta2_device_sub_request->name) {
        free(v1beta2_device_sub_request->name);
        v1beta2_device_sub_request->name = NULL;
    }
    if (v1beta2_device_sub_request->selectors) {
        list_ForEach(listEntry, v1beta2_device_sub_request->selectors) {
            v1beta2_device_selector_free(listEntry->data);
        }
        list_freeList(v1beta2_device_sub_request->selectors);
        v1beta2_device_sub_request->selectors = NULL;
    }
    if (v1beta2_device_sub_request->tolerations) {
        list_ForEach(listEntry, v1beta2_device_sub_request->tolerations) {
            v1beta2_device_toleration_free(listEntry->data);
        }
        list_freeList(v1beta2_device_sub_request->tolerations);
        v1beta2_device_sub_request->tolerations = NULL;
    }
    free(v1beta2_device_sub_request);
}

cJSON *v1beta2_device_sub_request_convertToJSON(v1beta2_device_sub_request_t *v1beta2_device_sub_request) {
    cJSON *item = cJSON_CreateObject();

    // v1beta2_device_sub_request->allocation_mode
    if(v1beta2_device_sub_request->allocation_mode) {
    if(cJSON_AddStringToObject(item, "allocationMode", v1beta2_device_sub_request->allocation_mode) == NULL) {
    goto fail; //String
    }
    }


    // v1beta2_device_sub_request->capacity
    if(v1beta2_device_sub_request->capacity) {
    cJSON *capacity_local_JSON = v1beta2_capacity_requirements_convertToJSON(v1beta2_device_sub_request->capacity);
    if(capacity_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "capacity", capacity_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta2_device_sub_request->count
    if(v1beta2_device_sub_request->count) {
    if(cJSON_AddNumberToObject(item, "count", *v1beta2_device_sub_request->count) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1beta2_device_sub_request->derived_attributes
    if(v1beta2_device_sub_request->derived_attributes) {
    cJSON *derived_attributes = cJSON_AddArrayToObject(item, "derivedAttributes");
    if(derived_attributes == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *derived_attributesListEntry;
    if (v1beta2_device_sub_request->derived_attributes) {
    list_ForEach(derived_attributesListEntry, v1beta2_device_sub_request->derived_attributes) {
    cJSON *itemLocal = v1beta2_device_derived_attribute_convertToJSON(derived_attributesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(derived_attributes, itemLocal);
    }
    }
    }


    // v1beta2_device_sub_request->device_class_name
    if (!v1beta2_device_sub_request->device_class_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "deviceClassName", v1beta2_device_sub_request->device_class_name) == NULL) {
    goto fail; //String
    }


    // v1beta2_device_sub_request->name
    if (!v1beta2_device_sub_request->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1beta2_device_sub_request->name) == NULL) {
    goto fail; //String
    }


    // v1beta2_device_sub_request->selectors
    if(v1beta2_device_sub_request->selectors) {
    cJSON *selectors = cJSON_AddArrayToObject(item, "selectors");
    if(selectors == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *selectorsListEntry;
    if (v1beta2_device_sub_request->selectors) {
    list_ForEach(selectorsListEntry, v1beta2_device_sub_request->selectors) {
    cJSON *itemLocal = v1beta2_device_selector_convertToJSON(selectorsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(selectors, itemLocal);
    }
    }
    }


    // v1beta2_device_sub_request->tolerations
    if(v1beta2_device_sub_request->tolerations) {
    cJSON *tolerations = cJSON_AddArrayToObject(item, "tolerations");
    if(tolerations == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *tolerationsListEntry;
    if (v1beta2_device_sub_request->tolerations) {
    list_ForEach(tolerationsListEntry, v1beta2_device_sub_request->tolerations) {
    cJSON *itemLocal = v1beta2_device_toleration_convertToJSON(tolerationsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(tolerations, itemLocal);
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

v1beta2_device_sub_request_t *v1beta2_device_sub_request_parseFromJSON(cJSON *v1beta2_device_sub_requestJSON){

    v1beta2_device_sub_request_t *v1beta2_device_sub_request_local_var = NULL;

    char *allocation_mode_local_str = NULL;

    // define the local variable for v1beta2_device_sub_request->capacity
    v1beta2_capacity_requirements_t *capacity_local_nonprim = NULL;

    // define the local variable for v1beta2_device_sub_request->count
    long *count_local_var = NULL;

    // define the local list for v1beta2_device_sub_request->derived_attributes
    list_t *derived_attributesList = NULL;

    char *device_class_name_local_str = NULL;

    char *name_local_str = NULL;

    // define the local list for v1beta2_device_sub_request->selectors
    list_t *selectorsList = NULL;

    // define the local list for v1beta2_device_sub_request->tolerations
    list_t *tolerationsList = NULL;

    // v1beta2_device_sub_request->allocation_mode
    cJSON *allocation_mode = cJSON_GetObjectItemCaseSensitive(v1beta2_device_sub_requestJSON, "allocationMode");
    if (cJSON_IsNull(allocation_mode)) {
        allocation_mode = NULL;
    }
    if (allocation_mode) { 
    if(!cJSON_IsString(allocation_mode) && !cJSON_IsNull(allocation_mode))
    {
    goto end; //String
    }
    }

    // v1beta2_device_sub_request->capacity
    cJSON *capacity = cJSON_GetObjectItemCaseSensitive(v1beta2_device_sub_requestJSON, "capacity");
    if (cJSON_IsNull(capacity)) {
        capacity = NULL;
    }
    if (capacity) { 
    capacity_local_nonprim = v1beta2_capacity_requirements_parseFromJSON(capacity); //nonprimitive
    }

    // v1beta2_device_sub_request->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(v1beta2_device_sub_requestJSON, "count");
    if (cJSON_IsNull(count)) {
        count = NULL;
    }
    if (count) { 
    if(!cJSON_IsNumber(count))
    {
    goto end; //Numeric
    }
    count_local_var = malloc(sizeof(long));
    if(!count_local_var)
    {
        goto end;
    }
    *count_local_var = count->valuedouble;
    }

    // v1beta2_device_sub_request->derived_attributes
    cJSON *derived_attributes = cJSON_GetObjectItemCaseSensitive(v1beta2_device_sub_requestJSON, "derivedAttributes");
    if (cJSON_IsNull(derived_attributes)) {
        derived_attributes = NULL;
    }
    if (derived_attributes) { 
    cJSON *derived_attributes_local_nonprimitive = NULL;
    if(!cJSON_IsArray(derived_attributes)){
        goto end; //nonprimitive container
    }

    derived_attributesList = list_createList();

    cJSON_ArrayForEach(derived_attributes_local_nonprimitive,derived_attributes )
    {
        if(!cJSON_IsObject(derived_attributes_local_nonprimitive)){
            goto end;
        }
        v1beta2_device_derived_attribute_t *derived_attributesItem = v1beta2_device_derived_attribute_parseFromJSON(derived_attributes_local_nonprimitive);

        list_addElement(derived_attributesList, derived_attributesItem);
    }
    }

    // v1beta2_device_sub_request->device_class_name
    cJSON *device_class_name = cJSON_GetObjectItemCaseSensitive(v1beta2_device_sub_requestJSON, "deviceClassName");
    if (cJSON_IsNull(device_class_name)) {
        device_class_name = NULL;
    }
    if (!device_class_name) {
        goto end;
    }

    
    if(!cJSON_IsString(device_class_name))
    {
    goto end; //String
    }

    // v1beta2_device_sub_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1beta2_device_sub_requestJSON, "name");
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

    // v1beta2_device_sub_request->selectors
    cJSON *selectors = cJSON_GetObjectItemCaseSensitive(v1beta2_device_sub_requestJSON, "selectors");
    if (cJSON_IsNull(selectors)) {
        selectors = NULL;
    }
    if (selectors) { 
    cJSON *selectors_local_nonprimitive = NULL;
    if(!cJSON_IsArray(selectors)){
        goto end; //nonprimitive container
    }

    selectorsList = list_createList();

    cJSON_ArrayForEach(selectors_local_nonprimitive,selectors )
    {
        if(!cJSON_IsObject(selectors_local_nonprimitive)){
            goto end;
        }
        v1beta2_device_selector_t *selectorsItem = v1beta2_device_selector_parseFromJSON(selectors_local_nonprimitive);

        list_addElement(selectorsList, selectorsItem);
    }
    }

    // v1beta2_device_sub_request->tolerations
    cJSON *tolerations = cJSON_GetObjectItemCaseSensitive(v1beta2_device_sub_requestJSON, "tolerations");
    if (cJSON_IsNull(tolerations)) {
        tolerations = NULL;
    }
    if (tolerations) { 
    cJSON *tolerations_local_nonprimitive = NULL;
    if(!cJSON_IsArray(tolerations)){
        goto end; //nonprimitive container
    }

    tolerationsList = list_createList();

    cJSON_ArrayForEach(tolerations_local_nonprimitive,tolerations )
    {
        if(!cJSON_IsObject(tolerations_local_nonprimitive)){
            goto end;
        }
        v1beta2_device_toleration_t *tolerationsItem = v1beta2_device_toleration_parseFromJSON(tolerations_local_nonprimitive);

        list_addElement(tolerationsList, tolerationsItem);
    }
    }


    if (allocation_mode && !cJSON_IsNull(allocation_mode)) allocation_mode_local_str = strdup(allocation_mode->valuestring);
    if (device_class_name && !cJSON_IsNull(device_class_name)) device_class_name_local_str = strdup(device_class_name->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);

    v1beta2_device_sub_request_local_var = v1beta2_device_sub_request_create_internal (
        allocation_mode_local_str,
        capacity ? capacity_local_nonprim : NULL,
        count_local_var,
        derived_attributes ? derived_attributesList : NULL,
        device_class_name_local_str,
        name_local_str,
        selectors ? selectorsList : NULL,
        tolerations ? tolerationsList : NULL
        );

    if (!v1beta2_device_sub_request_local_var) {
        goto end;
    }

    return v1beta2_device_sub_request_local_var;
end:
    if (allocation_mode_local_str) {
        free(allocation_mode_local_str);
        allocation_mode_local_str = NULL;
    }
    if (capacity_local_nonprim) {
        v1beta2_capacity_requirements_free(capacity_local_nonprim);
        capacity_local_nonprim = NULL;
    }
    if (count_local_var) {
        free(count_local_var);
        count_local_var = NULL;
    }
    if (derived_attributesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, derived_attributesList) {
            v1beta2_device_derived_attribute_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(derived_attributesList);
        derived_attributesList = NULL;
    }
    if (device_class_name_local_str) {
        free(device_class_name_local_str);
        device_class_name_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (selectorsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, selectorsList) {
            v1beta2_device_selector_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(selectorsList);
        selectorsList = NULL;
    }
    if (tolerationsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, tolerationsList) {
            v1beta2_device_toleration_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(tolerationsList);
        tolerationsList = NULL;
    }
    return NULL;

}
