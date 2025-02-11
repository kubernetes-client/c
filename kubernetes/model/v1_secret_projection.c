#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_secret_projection.h"



static v1_secret_projection_t *v1_secret_projection_create_internal(
    list_t *items,
    char *name,
    int optional
    ) {
    v1_secret_projection_t *v1_secret_projection_local_var = malloc(sizeof(v1_secret_projection_t));
    if (!v1_secret_projection_local_var) {
        return NULL;
    }
    v1_secret_projection_local_var->items = items;
    v1_secret_projection_local_var->name = name;
    v1_secret_projection_local_var->optional = optional;

    v1_secret_projection_local_var->_library_owned = 1;
    return v1_secret_projection_local_var;
}

__attribute__((deprecated)) v1_secret_projection_t *v1_secret_projection_create(
    list_t *items,
    char *name,
    int optional
    ) {
    return v1_secret_projection_create_internal (
        items,
        name,
        optional
        );
}

void v1_secret_projection_free(v1_secret_projection_t *v1_secret_projection) {
    if(NULL == v1_secret_projection){
        return ;
    }
    if(v1_secret_projection->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_secret_projection_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_secret_projection->items) {
        list_ForEach(listEntry, v1_secret_projection->items) {
            v1_key_to_path_free(listEntry->data);
        }
        list_freeList(v1_secret_projection->items);
        v1_secret_projection->items = NULL;
    }
    if (v1_secret_projection->name) {
        free(v1_secret_projection->name);
        v1_secret_projection->name = NULL;
    }
    free(v1_secret_projection);
}

cJSON *v1_secret_projection_convertToJSON(v1_secret_projection_t *v1_secret_projection) {
    cJSON *item = cJSON_CreateObject();

    // v1_secret_projection->items
    if(v1_secret_projection->items) {
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (v1_secret_projection->items) {
    list_ForEach(itemsListEntry, v1_secret_projection->items) {
    cJSON *itemLocal = v1_key_to_path_convertToJSON(itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(items, itemLocal);
    }
    }
    }


    // v1_secret_projection->name
    if(v1_secret_projection->name) {
    if(cJSON_AddStringToObject(item, "name", v1_secret_projection->name) == NULL) {
    goto fail; //String
    }
    }


    // v1_secret_projection->optional
    if(v1_secret_projection->optional) {
    if(cJSON_AddBoolToObject(item, "optional", v1_secret_projection->optional) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_secret_projection_t *v1_secret_projection_parseFromJSON(cJSON *v1_secret_projectionJSON){

    v1_secret_projection_t *v1_secret_projection_local_var = NULL;

    // define the local list for v1_secret_projection->items
    list_t *itemsList = NULL;

    // v1_secret_projection->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(v1_secret_projectionJSON, "items");
    if (cJSON_IsNull(items)) {
        items = NULL;
    }
    if (items) { 
    cJSON *items_local_nonprimitive = NULL;
    if(!cJSON_IsArray(items)){
        goto end; //nonprimitive container
    }

    itemsList = list_createList();

    cJSON_ArrayForEach(items_local_nonprimitive,items )
    {
        if(!cJSON_IsObject(items_local_nonprimitive)){
            goto end;
        }
        v1_key_to_path_t *itemsItem = v1_key_to_path_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }
    }

    // v1_secret_projection->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_secret_projectionJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // v1_secret_projection->optional
    cJSON *optional = cJSON_GetObjectItemCaseSensitive(v1_secret_projectionJSON, "optional");
    if (cJSON_IsNull(optional)) {
        optional = NULL;
    }
    if (optional) { 
    if(!cJSON_IsBool(optional))
    {
    goto end; //Bool
    }
    }


    v1_secret_projection_local_var = v1_secret_projection_create_internal (
        items ? itemsList : NULL,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        optional ? optional->valueint : 0
        );

    return v1_secret_projection_local_var;
end:
    if (itemsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, itemsList) {
            v1_key_to_path_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(itemsList);
        itemsList = NULL;
    }
    return NULL;

}
