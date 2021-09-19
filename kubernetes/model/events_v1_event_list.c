#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "events_v1_event_list.h"



events_v1_event_list_t *events_v1_event_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
    ) {
    events_v1_event_list_t *events_v1_event_list_local_var = malloc(sizeof(events_v1_event_list_t));
    if (!events_v1_event_list_local_var) {
        return NULL;
    }
    events_v1_event_list_local_var->api_version = api_version;
    events_v1_event_list_local_var->items = items;
    events_v1_event_list_local_var->kind = kind;
    events_v1_event_list_local_var->metadata = metadata;

    return events_v1_event_list_local_var;
}


void events_v1_event_list_free(events_v1_event_list_t *events_v1_event_list) {
    if(NULL == events_v1_event_list){
        return ;
    }
    listEntry_t *listEntry;
    if (events_v1_event_list->api_version) {
        free(events_v1_event_list->api_version);
        events_v1_event_list->api_version = NULL;
    }
    if (events_v1_event_list->items) {
        list_ForEach(listEntry, events_v1_event_list->items) {
            events_v1_event_free(listEntry->data);
        }
        list_free(events_v1_event_list->items);
        events_v1_event_list->items = NULL;
    }
    if (events_v1_event_list->kind) {
        free(events_v1_event_list->kind);
        events_v1_event_list->kind = NULL;
    }
    if (events_v1_event_list->metadata) {
        v1_list_meta_free(events_v1_event_list->metadata);
        events_v1_event_list->metadata = NULL;
    }
    free(events_v1_event_list);
}

cJSON *events_v1_event_list_convertToJSON(events_v1_event_list_t *events_v1_event_list) {
    cJSON *item = cJSON_CreateObject();

    // events_v1_event_list->api_version
    if(events_v1_event_list->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", events_v1_event_list->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // events_v1_event_list->items
    if (!events_v1_event_list->items) {
        goto fail;
    }
    
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (events_v1_event_list->items) {
    list_ForEach(itemsListEntry, events_v1_event_list->items) {
    cJSON *itemLocal = events_v1_event_convertToJSON(itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(items, itemLocal);
    }
    }


    // events_v1_event_list->kind
    if(events_v1_event_list->kind) { 
    if(cJSON_AddStringToObject(item, "kind", events_v1_event_list->kind) == NULL) {
    goto fail; //String
    }
     } 


    // events_v1_event_list->metadata
    if(events_v1_event_list->metadata) { 
    cJSON *metadata_local_JSON = v1_list_meta_convertToJSON(events_v1_event_list->metadata);
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

events_v1_event_list_t *events_v1_event_list_parseFromJSON(cJSON *events_v1_event_listJSON){

    events_v1_event_list_t *events_v1_event_list_local_var = NULL;

    // events_v1_event_list->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(events_v1_event_listJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // events_v1_event_list->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(events_v1_event_listJSON, "items");
    if (!items) {
        goto end;
    }

    list_t *itemsList;
    
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
        events_v1_event_t *itemsItem = events_v1_event_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }

    // events_v1_event_list->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(events_v1_event_listJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // events_v1_event_list->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(events_v1_event_listJSON, "metadata");
    v1_list_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_list_meta_parseFromJSON(metadata); //nonprimitive
    }


    events_v1_event_list_local_var = events_v1_event_list_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        itemsList,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL
        );

    return events_v1_event_list_local_var;
end:
    if (metadata_local_nonprim) {
        v1_list_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    return NULL;

}
