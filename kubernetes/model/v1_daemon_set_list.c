#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_daemon_set_list.h"



static v1_daemon_set_list_t *v1_daemon_set_list_create_internal(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
    ) {
    v1_daemon_set_list_t *v1_daemon_set_list_local_var = malloc(sizeof(v1_daemon_set_list_t));
    if (!v1_daemon_set_list_local_var) {
        return NULL;
    }
    v1_daemon_set_list_local_var->api_version = api_version;
    v1_daemon_set_list_local_var->items = items;
    v1_daemon_set_list_local_var->kind = kind;
    v1_daemon_set_list_local_var->metadata = metadata;

    v1_daemon_set_list_local_var->_library_owned = 1;
    return v1_daemon_set_list_local_var;
}

__attribute__((deprecated)) v1_daemon_set_list_t *v1_daemon_set_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
    ) {
    return v1_daemon_set_list_create_internal (
        api_version,
        items,
        kind,
        metadata
        );
}

void v1_daemon_set_list_free(v1_daemon_set_list_t *v1_daemon_set_list) {
    if(NULL == v1_daemon_set_list){
        return ;
    }
    if(v1_daemon_set_list->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_daemon_set_list_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_daemon_set_list->api_version) {
        free(v1_daemon_set_list->api_version);
        v1_daemon_set_list->api_version = NULL;
    }
    if (v1_daemon_set_list->items) {
        list_ForEach(listEntry, v1_daemon_set_list->items) {
            v1_daemon_set_free(listEntry->data);
        }
        list_freeList(v1_daemon_set_list->items);
        v1_daemon_set_list->items = NULL;
    }
    if (v1_daemon_set_list->kind) {
        free(v1_daemon_set_list->kind);
        v1_daemon_set_list->kind = NULL;
    }
    if (v1_daemon_set_list->metadata) {
        v1_list_meta_free(v1_daemon_set_list->metadata);
        v1_daemon_set_list->metadata = NULL;
    }
    free(v1_daemon_set_list);
}

cJSON *v1_daemon_set_list_convertToJSON(v1_daemon_set_list_t *v1_daemon_set_list) {
    cJSON *item = cJSON_CreateObject();

    // v1_daemon_set_list->api_version
    if(v1_daemon_set_list->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_daemon_set_list->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_daemon_set_list->items
    if (!v1_daemon_set_list->items) {
        goto fail;
    }
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (v1_daemon_set_list->items) {
    list_ForEach(itemsListEntry, v1_daemon_set_list->items) {
    cJSON *itemLocal = v1_daemon_set_convertToJSON(itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(items, itemLocal);
    }
    }


    // v1_daemon_set_list->kind
    if(v1_daemon_set_list->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_daemon_set_list->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_daemon_set_list->metadata
    if(v1_daemon_set_list->metadata) {
    cJSON *metadata_local_JSON = v1_list_meta_convertToJSON(v1_daemon_set_list->metadata);
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

v1_daemon_set_list_t *v1_daemon_set_list_parseFromJSON(cJSON *v1_daemon_set_listJSON){

    v1_daemon_set_list_t *v1_daemon_set_list_local_var = NULL;

    // define the local list for v1_daemon_set_list->items
    list_t *itemsList = NULL;

    // define the local variable for v1_daemon_set_list->metadata
    v1_list_meta_t *metadata_local_nonprim = NULL;

    // v1_daemon_set_list->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_listJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_daemon_set_list->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_listJSON, "items");
    if (cJSON_IsNull(items)) {
        items = NULL;
    }
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
        v1_daemon_set_t *itemsItem = v1_daemon_set_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }

    // v1_daemon_set_list->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_listJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_daemon_set_list->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_listJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_list_meta_parseFromJSON(metadata); //nonprimitive
    }


    v1_daemon_set_list_local_var = v1_daemon_set_list_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        itemsList,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL
        );

    return v1_daemon_set_list_local_var;
end:
    if (itemsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, itemsList) {
            v1_daemon_set_free(listEntry->data);
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
