#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_device_sub_request.h"



static v1alpha3_device_sub_request_t *v1alpha3_device_sub_request_create_internal(
    char *allocation_mode,
    long count,
    char *device_class_name,
    char *name,
    list_t *selectors,
    list_t *tolerations
    ) {
    v1alpha3_device_sub_request_t *v1alpha3_device_sub_request_local_var = malloc(sizeof(v1alpha3_device_sub_request_t));
    if (!v1alpha3_device_sub_request_local_var) {
        return NULL;
    }
    v1alpha3_device_sub_request_local_var->allocation_mode = allocation_mode;
    v1alpha3_device_sub_request_local_var->count = count;
    v1alpha3_device_sub_request_local_var->device_class_name = device_class_name;
    v1alpha3_device_sub_request_local_var->name = name;
    v1alpha3_device_sub_request_local_var->selectors = selectors;
    v1alpha3_device_sub_request_local_var->tolerations = tolerations;

    v1alpha3_device_sub_request_local_var->_library_owned = 1;
    return v1alpha3_device_sub_request_local_var;
}

__attribute__((deprecated)) v1alpha3_device_sub_request_t *v1alpha3_device_sub_request_create(
    char *allocation_mode,
    long count,
    char *device_class_name,
    char *name,
    list_t *selectors,
    list_t *tolerations
    ) {
    return v1alpha3_device_sub_request_create_internal (
        allocation_mode,
        count,
        device_class_name,
        name,
        selectors,
        tolerations
        );
}

void v1alpha3_device_sub_request_free(v1alpha3_device_sub_request_t *v1alpha3_device_sub_request) {
    if(NULL == v1alpha3_device_sub_request){
        return ;
    }
    if(v1alpha3_device_sub_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha3_device_sub_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_device_sub_request->allocation_mode) {
        free(v1alpha3_device_sub_request->allocation_mode);
        v1alpha3_device_sub_request->allocation_mode = NULL;
    }
    if (v1alpha3_device_sub_request->device_class_name) {
        free(v1alpha3_device_sub_request->device_class_name);
        v1alpha3_device_sub_request->device_class_name = NULL;
    }
    if (v1alpha3_device_sub_request->name) {
        free(v1alpha3_device_sub_request->name);
        v1alpha3_device_sub_request->name = NULL;
    }
    if (v1alpha3_device_sub_request->selectors) {
        list_ForEach(listEntry, v1alpha3_device_sub_request->selectors) {
            v1alpha3_device_selector_free(listEntry->data);
        }
        list_freeList(v1alpha3_device_sub_request->selectors);
        v1alpha3_device_sub_request->selectors = NULL;
    }
    if (v1alpha3_device_sub_request->tolerations) {
        list_ForEach(listEntry, v1alpha3_device_sub_request->tolerations) {
            v1alpha3_device_toleration_free(listEntry->data);
        }
        list_freeList(v1alpha3_device_sub_request->tolerations);
        v1alpha3_device_sub_request->tolerations = NULL;
    }
    free(v1alpha3_device_sub_request);
}

cJSON *v1alpha3_device_sub_request_convertToJSON(v1alpha3_device_sub_request_t *v1alpha3_device_sub_request) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_device_sub_request->allocation_mode
    if(v1alpha3_device_sub_request->allocation_mode) {
    if(cJSON_AddStringToObject(item, "allocationMode", v1alpha3_device_sub_request->allocation_mode) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_device_sub_request->count
    if(v1alpha3_device_sub_request->count) {
    if(cJSON_AddNumberToObject(item, "count", v1alpha3_device_sub_request->count) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1alpha3_device_sub_request->device_class_name
    if (!v1alpha3_device_sub_request->device_class_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "deviceClassName", v1alpha3_device_sub_request->device_class_name) == NULL) {
    goto fail; //String
    }


    // v1alpha3_device_sub_request->name
    if (!v1alpha3_device_sub_request->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1alpha3_device_sub_request->name) == NULL) {
    goto fail; //String
    }


    // v1alpha3_device_sub_request->selectors
    if(v1alpha3_device_sub_request->selectors) {
    cJSON *selectors = cJSON_AddArrayToObject(item, "selectors");
    if(selectors == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *selectorsListEntry;
    if (v1alpha3_device_sub_request->selectors) {
    list_ForEach(selectorsListEntry, v1alpha3_device_sub_request->selectors) {
    cJSON *itemLocal = v1alpha3_device_selector_convertToJSON(selectorsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(selectors, itemLocal);
    }
    }
    }


    // v1alpha3_device_sub_request->tolerations
    if(v1alpha3_device_sub_request->tolerations) {
    cJSON *tolerations = cJSON_AddArrayToObject(item, "tolerations");
    if(tolerations == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *tolerationsListEntry;
    if (v1alpha3_device_sub_request->tolerations) {
    list_ForEach(tolerationsListEntry, v1alpha3_device_sub_request->tolerations) {
    cJSON *itemLocal = v1alpha3_device_toleration_convertToJSON(tolerationsListEntry->data);
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

v1alpha3_device_sub_request_t *v1alpha3_device_sub_request_parseFromJSON(cJSON *v1alpha3_device_sub_requestJSON){

    v1alpha3_device_sub_request_t *v1alpha3_device_sub_request_local_var = NULL;

    // define the local list for v1alpha3_device_sub_request->selectors
    list_t *selectorsList = NULL;

    // define the local list for v1alpha3_device_sub_request->tolerations
    list_t *tolerationsList = NULL;

    // v1alpha3_device_sub_request->allocation_mode
    cJSON *allocation_mode = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_sub_requestJSON, "allocationMode");
    if (cJSON_IsNull(allocation_mode)) {
        allocation_mode = NULL;
    }
    if (allocation_mode) { 
    if(!cJSON_IsString(allocation_mode) && !cJSON_IsNull(allocation_mode))
    {
    goto end; //String
    }
    }

    // v1alpha3_device_sub_request->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_sub_requestJSON, "count");
    if (cJSON_IsNull(count)) {
        count = NULL;
    }
    if (count) { 
    if(!cJSON_IsNumber(count))
    {
    goto end; //Numeric
    }
    }

    // v1alpha3_device_sub_request->device_class_name
    cJSON *device_class_name = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_sub_requestJSON, "deviceClassName");
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

    // v1alpha3_device_sub_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_sub_requestJSON, "name");
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

    // v1alpha3_device_sub_request->selectors
    cJSON *selectors = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_sub_requestJSON, "selectors");
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
        v1alpha3_device_selector_t *selectorsItem = v1alpha3_device_selector_parseFromJSON(selectors_local_nonprimitive);

        list_addElement(selectorsList, selectorsItem);
    }
    }

    // v1alpha3_device_sub_request->tolerations
    cJSON *tolerations = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_sub_requestJSON, "tolerations");
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
        v1alpha3_device_toleration_t *tolerationsItem = v1alpha3_device_toleration_parseFromJSON(tolerations_local_nonprimitive);

        list_addElement(tolerationsList, tolerationsItem);
    }
    }


    v1alpha3_device_sub_request_local_var = v1alpha3_device_sub_request_create_internal (
        allocation_mode && !cJSON_IsNull(allocation_mode) ? strdup(allocation_mode->valuestring) : NULL,
        count ? count->valuedouble : 0,
        strdup(device_class_name->valuestring),
        strdup(name->valuestring),
        selectors ? selectorsList : NULL,
        tolerations ? tolerationsList : NULL
        );

    return v1alpha3_device_sub_request_local_var;
end:
    if (selectorsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, selectorsList) {
            v1alpha3_device_selector_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(selectorsList);
        selectorsList = NULL;
    }
    if (tolerationsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, tolerationsList) {
            v1alpha3_device_toleration_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(tolerationsList);
        tolerationsList = NULL;
    }
    return NULL;

}
