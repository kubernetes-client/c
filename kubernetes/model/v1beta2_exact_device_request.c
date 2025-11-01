#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_exact_device_request.h"



static v1beta2_exact_device_request_t *v1beta2_exact_device_request_create_internal(
    int admin_access,
    char *allocation_mode,
    v1beta2_capacity_requirements_t *capacity,
    long count,
    char *device_class_name,
    list_t *selectors,
    list_t *tolerations
    ) {
    v1beta2_exact_device_request_t *v1beta2_exact_device_request_local_var = malloc(sizeof(v1beta2_exact_device_request_t));
    if (!v1beta2_exact_device_request_local_var) {
        return NULL;
    }
    v1beta2_exact_device_request_local_var->admin_access = admin_access;
    v1beta2_exact_device_request_local_var->allocation_mode = allocation_mode;
    v1beta2_exact_device_request_local_var->capacity = capacity;
    v1beta2_exact_device_request_local_var->count = count;
    v1beta2_exact_device_request_local_var->device_class_name = device_class_name;
    v1beta2_exact_device_request_local_var->selectors = selectors;
    v1beta2_exact_device_request_local_var->tolerations = tolerations;

    v1beta2_exact_device_request_local_var->_library_owned = 1;
    return v1beta2_exact_device_request_local_var;
}

__attribute__((deprecated)) v1beta2_exact_device_request_t *v1beta2_exact_device_request_create(
    int admin_access,
    char *allocation_mode,
    v1beta2_capacity_requirements_t *capacity,
    long count,
    char *device_class_name,
    list_t *selectors,
    list_t *tolerations
    ) {
    return v1beta2_exact_device_request_create_internal (
        admin_access,
        allocation_mode,
        capacity,
        count,
        device_class_name,
        selectors,
        tolerations
        );
}

void v1beta2_exact_device_request_free(v1beta2_exact_device_request_t *v1beta2_exact_device_request) {
    if(NULL == v1beta2_exact_device_request){
        return ;
    }
    if(v1beta2_exact_device_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta2_exact_device_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta2_exact_device_request->allocation_mode) {
        free(v1beta2_exact_device_request->allocation_mode);
        v1beta2_exact_device_request->allocation_mode = NULL;
    }
    if (v1beta2_exact_device_request->capacity) {
        v1beta2_capacity_requirements_free(v1beta2_exact_device_request->capacity);
        v1beta2_exact_device_request->capacity = NULL;
    }
    if (v1beta2_exact_device_request->device_class_name) {
        free(v1beta2_exact_device_request->device_class_name);
        v1beta2_exact_device_request->device_class_name = NULL;
    }
    if (v1beta2_exact_device_request->selectors) {
        list_ForEach(listEntry, v1beta2_exact_device_request->selectors) {
            v1beta2_device_selector_free(listEntry->data);
        }
        list_freeList(v1beta2_exact_device_request->selectors);
        v1beta2_exact_device_request->selectors = NULL;
    }
    if (v1beta2_exact_device_request->tolerations) {
        list_ForEach(listEntry, v1beta2_exact_device_request->tolerations) {
            v1beta2_device_toleration_free(listEntry->data);
        }
        list_freeList(v1beta2_exact_device_request->tolerations);
        v1beta2_exact_device_request->tolerations = NULL;
    }
    free(v1beta2_exact_device_request);
}

cJSON *v1beta2_exact_device_request_convertToJSON(v1beta2_exact_device_request_t *v1beta2_exact_device_request) {
    cJSON *item = cJSON_CreateObject();

    // v1beta2_exact_device_request->admin_access
    if(v1beta2_exact_device_request->admin_access) {
    if(cJSON_AddBoolToObject(item, "adminAccess", v1beta2_exact_device_request->admin_access) == NULL) {
    goto fail; //Bool
    }
    }


    // v1beta2_exact_device_request->allocation_mode
    if(v1beta2_exact_device_request->allocation_mode) {
    if(cJSON_AddStringToObject(item, "allocationMode", v1beta2_exact_device_request->allocation_mode) == NULL) {
    goto fail; //String
    }
    }


    // v1beta2_exact_device_request->capacity
    if(v1beta2_exact_device_request->capacity) {
    cJSON *capacity_local_JSON = v1beta2_capacity_requirements_convertToJSON(v1beta2_exact_device_request->capacity);
    if(capacity_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "capacity", capacity_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta2_exact_device_request->count
    if(v1beta2_exact_device_request->count) {
    if(cJSON_AddNumberToObject(item, "count", v1beta2_exact_device_request->count) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1beta2_exact_device_request->device_class_name
    if (!v1beta2_exact_device_request->device_class_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "deviceClassName", v1beta2_exact_device_request->device_class_name) == NULL) {
    goto fail; //String
    }


    // v1beta2_exact_device_request->selectors
    if(v1beta2_exact_device_request->selectors) {
    cJSON *selectors = cJSON_AddArrayToObject(item, "selectors");
    if(selectors == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *selectorsListEntry;
    if (v1beta2_exact_device_request->selectors) {
    list_ForEach(selectorsListEntry, v1beta2_exact_device_request->selectors) {
    cJSON *itemLocal = v1beta2_device_selector_convertToJSON(selectorsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(selectors, itemLocal);
    }
    }
    }


    // v1beta2_exact_device_request->tolerations
    if(v1beta2_exact_device_request->tolerations) {
    cJSON *tolerations = cJSON_AddArrayToObject(item, "tolerations");
    if(tolerations == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *tolerationsListEntry;
    if (v1beta2_exact_device_request->tolerations) {
    list_ForEach(tolerationsListEntry, v1beta2_exact_device_request->tolerations) {
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

v1beta2_exact_device_request_t *v1beta2_exact_device_request_parseFromJSON(cJSON *v1beta2_exact_device_requestJSON){

    v1beta2_exact_device_request_t *v1beta2_exact_device_request_local_var = NULL;

    // define the local variable for v1beta2_exact_device_request->capacity
    v1beta2_capacity_requirements_t *capacity_local_nonprim = NULL;

    // define the local list for v1beta2_exact_device_request->selectors
    list_t *selectorsList = NULL;

    // define the local list for v1beta2_exact_device_request->tolerations
    list_t *tolerationsList = NULL;

    // v1beta2_exact_device_request->admin_access
    cJSON *admin_access = cJSON_GetObjectItemCaseSensitive(v1beta2_exact_device_requestJSON, "adminAccess");
    if (cJSON_IsNull(admin_access)) {
        admin_access = NULL;
    }
    if (admin_access) { 
    if(!cJSON_IsBool(admin_access))
    {
    goto end; //Bool
    }
    }

    // v1beta2_exact_device_request->allocation_mode
    cJSON *allocation_mode = cJSON_GetObjectItemCaseSensitive(v1beta2_exact_device_requestJSON, "allocationMode");
    if (cJSON_IsNull(allocation_mode)) {
        allocation_mode = NULL;
    }
    if (allocation_mode) { 
    if(!cJSON_IsString(allocation_mode) && !cJSON_IsNull(allocation_mode))
    {
    goto end; //String
    }
    }

    // v1beta2_exact_device_request->capacity
    cJSON *capacity = cJSON_GetObjectItemCaseSensitive(v1beta2_exact_device_requestJSON, "capacity");
    if (cJSON_IsNull(capacity)) {
        capacity = NULL;
    }
    if (capacity) { 
    capacity_local_nonprim = v1beta2_capacity_requirements_parseFromJSON(capacity); //nonprimitive
    }

    // v1beta2_exact_device_request->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(v1beta2_exact_device_requestJSON, "count");
    if (cJSON_IsNull(count)) {
        count = NULL;
    }
    if (count) { 
    if(!cJSON_IsNumber(count))
    {
    goto end; //Numeric
    }
    }

    // v1beta2_exact_device_request->device_class_name
    cJSON *device_class_name = cJSON_GetObjectItemCaseSensitive(v1beta2_exact_device_requestJSON, "deviceClassName");
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

    // v1beta2_exact_device_request->selectors
    cJSON *selectors = cJSON_GetObjectItemCaseSensitive(v1beta2_exact_device_requestJSON, "selectors");
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

    // v1beta2_exact_device_request->tolerations
    cJSON *tolerations = cJSON_GetObjectItemCaseSensitive(v1beta2_exact_device_requestJSON, "tolerations");
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


    v1beta2_exact_device_request_local_var = v1beta2_exact_device_request_create_internal (
        admin_access ? admin_access->valueint : 0,
        allocation_mode && !cJSON_IsNull(allocation_mode) ? strdup(allocation_mode->valuestring) : NULL,
        capacity ? capacity_local_nonprim : NULL,
        count ? count->valuedouble : 0,
        strdup(device_class_name->valuestring),
        selectors ? selectorsList : NULL,
        tolerations ? tolerationsList : NULL
        );

    return v1beta2_exact_device_request_local_var;
end:
    if (capacity_local_nonprim) {
        v1beta2_capacity_requirements_free(capacity_local_nonprim);
        capacity_local_nonprim = NULL;
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
