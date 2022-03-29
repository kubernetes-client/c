#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "core_v1_event_list.h"



core_v1_event_list_t *core_v1_event_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
    ) {
    core_v1_event_list_t *core_v1_event_list_local_var = malloc(sizeof(core_v1_event_list_t));
    if (!core_v1_event_list_local_var) {
        return NULL;
    }
    core_v1_event_list_local_var->api_version = api_version;
    core_v1_event_list_local_var->items = items;
    core_v1_event_list_local_var->kind = kind;
    core_v1_event_list_local_var->metadata = metadata;

    return core_v1_event_list_local_var;
}


void core_v1_event_list_free(core_v1_event_list_t *core_v1_event_list) {
    if(NULL == core_v1_event_list){
        return ;
    }
    listEntry_t *listEntry;
    if (core_v1_event_list->api_version) {
        free(core_v1_event_list->api_version);
        core_v1_event_list->api_version = NULL;
    }
    if (core_v1_event_list->items) {
        list_ForEach(listEntry, core_v1_event_list->items) {
            core_v1_event_free(listEntry->data);
        }
        list_freeList(core_v1_event_list->items);
        core_v1_event_list->items = NULL;
    }
    if (core_v1_event_list->kind) {
        free(core_v1_event_list->kind);
        core_v1_event_list->kind = NULL;
    }
    if (core_v1_event_list->metadata) {
        v1_list_meta_free(core_v1_event_list->metadata);
        core_v1_event_list->metadata = NULL;
    }
    free(core_v1_event_list);
}

cJSON *core_v1_event_list_convertToJSON(core_v1_event_list_t *core_v1_event_list) {
    cJSON *item = cJSON_CreateObject();

    // core_v1_event_list->api_version
    if(core_v1_event_list->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", core_v1_event_list->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // core_v1_event_list->items
    if (!core_v1_event_list->items) {
        goto fail;
    }
    
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (core_v1_event_list->items) {
    list_ForEach(itemsListEntry, core_v1_event_list->items) {
    cJSON *itemLocal = core_v1_event_convertToJSON(itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(items, itemLocal);
    }
    }


    // core_v1_event_list->kind
    if(core_v1_event_list->kind) { 
    if(cJSON_AddStringToObject(item, "kind", core_v1_event_list->kind) == NULL) {
    goto fail; //String
    }
     } 


    // core_v1_event_list->metadata
    if(core_v1_event_list->metadata) { 
    cJSON *metadata_local_JSON = v1_list_meta_convertToJSON(core_v1_event_list->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
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

core_v1_event_list_t *core_v1_event_list_parseFromJSON(cJSON *core_v1_event_listJSON){

    core_v1_event_list_t *core_v1_event_list_local_var = NULL;

    // define the local list for core_v1_event_list->items
    list_t *itemsList = NULL;

    // define the local variable for core_v1_event_list->metadata
    v1_list_meta_t *metadata_local_nonprim = NULL;

    // core_v1_event_list->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(core_v1_event_listJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // core_v1_event_list->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(core_v1_event_listJSON, "items");
    if (!items) {
        goto end;
    }

    
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
        core_v1_event_t *itemsItem = core_v1_event_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }

    // core_v1_event_list->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(core_v1_event_listJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // core_v1_event_list->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(core_v1_event_listJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_list_meta_parseFromJSON(metadata); //nonprimitive
    }


    core_v1_event_list_local_var = core_v1_event_list_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        itemsList,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL
        );

    return core_v1_event_list_local_var;
end:
    if (itemsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, itemsList) {
            core_v1_event_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(itemsList);
        itemsList = NULL;
    }
    if (metadata_local_nonprim) {
        v1_list_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    return NULL;

}
