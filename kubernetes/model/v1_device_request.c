#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_device_request.h"



static v1_device_request_t *v1_device_request_create_internal(
    v1_exact_device_request_t *exactly,
    list_t *first_available,
    char *name
    ) {
    v1_device_request_t *v1_device_request_local_var = malloc(sizeof(v1_device_request_t));
    if (!v1_device_request_local_var) {
        return NULL;
    }
    v1_device_request_local_var->exactly = exactly;
    v1_device_request_local_var->first_available = first_available;
    v1_device_request_local_var->name = name;

    v1_device_request_local_var->_library_owned = 1;
    return v1_device_request_local_var;
}

__attribute__((deprecated)) v1_device_request_t *v1_device_request_create(
    v1_exact_device_request_t *exactly,
    list_t *first_available,
    char *name
    ) {
    return v1_device_request_create_internal (
        exactly,
        first_available,
        name
        );
}

void v1_device_request_free(v1_device_request_t *v1_device_request) {
    if(NULL == v1_device_request){
        return ;
    }
    if(v1_device_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_device_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_device_request->exactly) {
        v1_exact_device_request_free(v1_device_request->exactly);
        v1_device_request->exactly = NULL;
    }
    if (v1_device_request->first_available) {
        list_ForEach(listEntry, v1_device_request->first_available) {
            v1_device_sub_request_free(listEntry->data);
        }
        list_freeList(v1_device_request->first_available);
        v1_device_request->first_available = NULL;
    }
    if (v1_device_request->name) {
        free(v1_device_request->name);
        v1_device_request->name = NULL;
    }
    free(v1_device_request);
}

cJSON *v1_device_request_convertToJSON(v1_device_request_t *v1_device_request) {
    cJSON *item = cJSON_CreateObject();

    // v1_device_request->exactly
    if(v1_device_request->exactly) {
    cJSON *exactly_local_JSON = v1_exact_device_request_convertToJSON(v1_device_request->exactly);
    if(exactly_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "exactly", exactly_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_device_request->first_available
    if(v1_device_request->first_available) {
    cJSON *first_available = cJSON_AddArrayToObject(item, "firstAvailable");
    if(first_available == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *first_availableListEntry;
    if (v1_device_request->first_available) {
    list_ForEach(first_availableListEntry, v1_device_request->first_available) {
    cJSON *itemLocal = v1_device_sub_request_convertToJSON(first_availableListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(first_available, itemLocal);
    }
    }
    }


    // v1_device_request->name
    if (!v1_device_request->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_device_request->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_device_request_t *v1_device_request_parseFromJSON(cJSON *v1_device_requestJSON){

    v1_device_request_t *v1_device_request_local_var = NULL;

    // define the local variable for v1_device_request->exactly
    v1_exact_device_request_t *exactly_local_nonprim = NULL;

    // define the local list for v1_device_request->first_available
    list_t *first_availableList = NULL;

    // v1_device_request->exactly
    cJSON *exactly = cJSON_GetObjectItemCaseSensitive(v1_device_requestJSON, "exactly");
    if (cJSON_IsNull(exactly)) {
        exactly = NULL;
    }
    if (exactly) { 
    exactly_local_nonprim = v1_exact_device_request_parseFromJSON(exactly); //nonprimitive
    }

    // v1_device_request->first_available
    cJSON *first_available = cJSON_GetObjectItemCaseSensitive(v1_device_requestJSON, "firstAvailable");
    if (cJSON_IsNull(first_available)) {
        first_available = NULL;
    }
    if (first_available) { 
    cJSON *first_available_local_nonprimitive = NULL;
    if(!cJSON_IsArray(first_available)){
        goto end; //nonprimitive container
    }

    first_availableList = list_createList();

    cJSON_ArrayForEach(first_available_local_nonprimitive,first_available )
    {
        if(!cJSON_IsObject(first_available_local_nonprimitive)){
            goto end;
        }
        v1_device_sub_request_t *first_availableItem = v1_device_sub_request_parseFromJSON(first_available_local_nonprimitive);

        list_addElement(first_availableList, first_availableItem);
    }
    }

    // v1_device_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_device_requestJSON, "name");
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


    v1_device_request_local_var = v1_device_request_create_internal (
        exactly ? exactly_local_nonprim : NULL,
        first_available ? first_availableList : NULL,
        strdup(name->valuestring)
        );

    return v1_device_request_local_var;
end:
    if (exactly_local_nonprim) {
        v1_exact_device_request_free(exactly_local_nonprim);
        exactly_local_nonprim = NULL;
    }
    if (first_availableList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, first_availableList) {
            v1_device_sub_request_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(first_availableList);
        first_availableList = NULL;
    }
    return NULL;

}
