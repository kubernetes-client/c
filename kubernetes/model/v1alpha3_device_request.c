#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_device_request.h"



v1alpha3_device_request_t *v1alpha3_device_request_create(
    int admin_access,
    char *allocation_mode,
    long count,
    char *device_class_name,
    char *name,
    list_t *selectors
    ) {
    v1alpha3_device_request_t *v1alpha3_device_request_local_var = malloc(sizeof(v1alpha3_device_request_t));
    if (!v1alpha3_device_request_local_var) {
        return NULL;
    }
    v1alpha3_device_request_local_var->admin_access = admin_access;
    v1alpha3_device_request_local_var->allocation_mode = allocation_mode;
    v1alpha3_device_request_local_var->count = count;
    v1alpha3_device_request_local_var->device_class_name = device_class_name;
    v1alpha3_device_request_local_var->name = name;
    v1alpha3_device_request_local_var->selectors = selectors;

    return v1alpha3_device_request_local_var;
}


void v1alpha3_device_request_free(v1alpha3_device_request_t *v1alpha3_device_request) {
    if(NULL == v1alpha3_device_request){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_device_request->allocation_mode) {
        free(v1alpha3_device_request->allocation_mode);
        v1alpha3_device_request->allocation_mode = NULL;
    }
    if (v1alpha3_device_request->device_class_name) {
        free(v1alpha3_device_request->device_class_name);
        v1alpha3_device_request->device_class_name = NULL;
    }
    if (v1alpha3_device_request->name) {
        free(v1alpha3_device_request->name);
        v1alpha3_device_request->name = NULL;
    }
    if (v1alpha3_device_request->selectors) {
        list_ForEach(listEntry, v1alpha3_device_request->selectors) {
            v1alpha3_device_selector_free(listEntry->data);
        }
        list_freeList(v1alpha3_device_request->selectors);
        v1alpha3_device_request->selectors = NULL;
    }
    free(v1alpha3_device_request);
}

cJSON *v1alpha3_device_request_convertToJSON(v1alpha3_device_request_t *v1alpha3_device_request) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_device_request->admin_access
    if(v1alpha3_device_request->admin_access) {
    if(cJSON_AddBoolToObject(item, "adminAccess", v1alpha3_device_request->admin_access) == NULL) {
    goto fail; //Bool
    }
    }


    // v1alpha3_device_request->allocation_mode
    if(v1alpha3_device_request->allocation_mode) {
    if(cJSON_AddStringToObject(item, "allocationMode", v1alpha3_device_request->allocation_mode) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_device_request->count
    if(v1alpha3_device_request->count) {
    if(cJSON_AddNumberToObject(item, "count", v1alpha3_device_request->count) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1alpha3_device_request->device_class_name
    if (!v1alpha3_device_request->device_class_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "deviceClassName", v1alpha3_device_request->device_class_name) == NULL) {
    goto fail; //String
    }


    // v1alpha3_device_request->name
    if (!v1alpha3_device_request->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1alpha3_device_request->name) == NULL) {
    goto fail; //String
    }


    // v1alpha3_device_request->selectors
    if(v1alpha3_device_request->selectors) {
    cJSON *selectors = cJSON_AddArrayToObject(item, "selectors");
    if(selectors == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *selectorsListEntry;
    if (v1alpha3_device_request->selectors) {
    list_ForEach(selectorsListEntry, v1alpha3_device_request->selectors) {
    cJSON *itemLocal = v1alpha3_device_selector_convertToJSON(selectorsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(selectors, itemLocal);
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

v1alpha3_device_request_t *v1alpha3_device_request_parseFromJSON(cJSON *v1alpha3_device_requestJSON){

    v1alpha3_device_request_t *v1alpha3_device_request_local_var = NULL;

    // define the local list for v1alpha3_device_request->selectors
    list_t *selectorsList = NULL;

    // v1alpha3_device_request->admin_access
    cJSON *admin_access = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_requestJSON, "adminAccess");
    if (admin_access) { 
    if(!cJSON_IsBool(admin_access))
    {
    goto end; //Bool
    }
    }

    // v1alpha3_device_request->allocation_mode
    cJSON *allocation_mode = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_requestJSON, "allocationMode");
    if (allocation_mode) { 
    if(!cJSON_IsString(allocation_mode) && !cJSON_IsNull(allocation_mode))
    {
    goto end; //String
    }
    }

    // v1alpha3_device_request->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_requestJSON, "count");
    if (count) { 
    if(!cJSON_IsNumber(count))
    {
    goto end; //Numeric
    }
    }

    // v1alpha3_device_request->device_class_name
    cJSON *device_class_name = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_requestJSON, "deviceClassName");
    if (!device_class_name) {
        goto end;
    }

    
    if(!cJSON_IsString(device_class_name))
    {
    goto end; //String
    }

    // v1alpha3_device_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_requestJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1alpha3_device_request->selectors
    cJSON *selectors = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_requestJSON, "selectors");
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


    v1alpha3_device_request_local_var = v1alpha3_device_request_create (
        admin_access ? admin_access->valueint : 0,
        allocation_mode && !cJSON_IsNull(allocation_mode) ? strdup(allocation_mode->valuestring) : NULL,
        count ? count->valuedouble : 0,
        strdup(device_class_name->valuestring),
        strdup(name->valuestring),
        selectors ? selectorsList : NULL
        );

    return v1alpha3_device_request_local_var;
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
    return NULL;

}
