#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_config_map_projection.h"



v1_config_map_projection_t *v1_config_map_projection_create(
    list_t *items,
    char *name,
    int optional
    ) {
    v1_config_map_projection_t *v1_config_map_projection_local_var = malloc(sizeof(v1_config_map_projection_t));
    if (!v1_config_map_projection_local_var) {
        return NULL;
    }
    v1_config_map_projection_local_var->items = items;
    v1_config_map_projection_local_var->name = name;
    v1_config_map_projection_local_var->optional = optional;

    return v1_config_map_projection_local_var;
}


void v1_config_map_projection_free(v1_config_map_projection_t *v1_config_map_projection) {
    if(NULL == v1_config_map_projection){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_config_map_projection->items) {
        list_ForEach(listEntry, v1_config_map_projection->items) {
            v1_key_to_path_free(listEntry->data);
        }
        list_free(v1_config_map_projection->items);
        v1_config_map_projection->items = NULL;
    }
    if (v1_config_map_projection->name) {
        free(v1_config_map_projection->name);
        v1_config_map_projection->name = NULL;
    }
    free(v1_config_map_projection);
}

cJSON *v1_config_map_projection_convertToJSON(v1_config_map_projection_t *v1_config_map_projection) {
    cJSON *item = cJSON_CreateObject();

    // v1_config_map_projection->items
    if(v1_config_map_projection->items) { 
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (v1_config_map_projection->items) {
    list_ForEach(itemsListEntry, v1_config_map_projection->items) {
    cJSON *itemLocal = v1_key_to_path_convertToJSON(itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(items, itemLocal);
    }
    }
     } 


    // v1_config_map_projection->name
    if(v1_config_map_projection->name) { 
    if(cJSON_AddStringToObject(item, "name", v1_config_map_projection->name) == NULL) {
    goto fail; //String
    }
     } 


    // v1_config_map_projection->optional
    if(v1_config_map_projection->optional) { 
    if(cJSON_AddBoolToObject(item, "optional", v1_config_map_projection->optional) == NULL) {
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

v1_config_map_projection_t *v1_config_map_projection_parseFromJSON(cJSON *v1_config_map_projectionJSON){

    v1_config_map_projection_t *v1_config_map_projection_local_var = NULL;

    // v1_config_map_projection->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(v1_config_map_projectionJSON, "items");
    list_t *itemsList;
    if (items) { 
    cJSON *items_local_nonprimitive;
    if(!cJSON_IsArray(items)){
        goto end; //nonprimitive container
    }

    itemsList = list_create();

    cJSON_ArrayForEach(items_local_nonprimitive,items )
    {
        if(!cJSON_IsObject(items_local_nonprimitive)){
            goto end;
        }
        v1_key_to_path_t *itemsItem = v1_key_to_path_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }
    }

    // v1_config_map_projection->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_config_map_projectionJSON, "name");
    if (name) { 
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }
    }

    // v1_config_map_projection->optional
    cJSON *optional = cJSON_GetObjectItemCaseSensitive(v1_config_map_projectionJSON, "optional");
    if (optional) { 
    if(!cJSON_IsBool(optional))
    {
    goto end; //Bool
    }
    }


    v1_config_map_projection_local_var = v1_config_map_projection_create (
        items ? itemsList : NULL,
        name ? strdup(name->valuestring) : NULL,
        optional ? optional->valueint : 0
        );

    return v1_config_map_projection_local_var;
end:
    return NULL;

}
