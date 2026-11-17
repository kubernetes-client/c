#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2beta1_api_group_discovery_list.h"



static v2beta1_api_group_discovery_list_t *v2beta1_api_group_discovery_list_create_internal(
    char *api_version,
    char *kind,
    v1_list_meta_t *metadata,
    list_t *items
    ) {
    v2beta1_api_group_discovery_list_t *v2beta1_api_group_discovery_list_local_var = malloc(sizeof(v2beta1_api_group_discovery_list_t));
    if (!v2beta1_api_group_discovery_list_local_var) {
        return NULL;
    }
    memset(v2beta1_api_group_discovery_list_local_var, 0, sizeof(v2beta1_api_group_discovery_list_t));
    v2beta1_api_group_discovery_list_local_var->_library_owned = 1;
    v2beta1_api_group_discovery_list_local_var->api_version = api_version;
    v2beta1_api_group_discovery_list_local_var->kind = kind;
    v2beta1_api_group_discovery_list_local_var->metadata = metadata;
    v2beta1_api_group_discovery_list_local_var->items = items;
    return v2beta1_api_group_discovery_list_local_var;
}

__attribute__((deprecated)) v2beta1_api_group_discovery_list_t *v2beta1_api_group_discovery_list_create(
    char *api_version,
    char *kind,
    v1_list_meta_t *metadata,
    list_t *items
    ) {
    v2beta1_api_group_discovery_list_t *result = v2beta1_api_group_discovery_list_create_internal (
        api_version,
        kind,
        metadata,
        items
        );
    if (!result) {
    }
    return result;
}

void v2beta1_api_group_discovery_list_free(v2beta1_api_group_discovery_list_t *v2beta1_api_group_discovery_list) {
    if(NULL == v2beta1_api_group_discovery_list){
        return ;
    }
    if(v2beta1_api_group_discovery_list->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v2beta1_api_group_discovery_list_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v2beta1_api_group_discovery_list->api_version) {
        free(v2beta1_api_group_discovery_list->api_version);
        v2beta1_api_group_discovery_list->api_version = NULL;
    }
    if (v2beta1_api_group_discovery_list->kind) {
        free(v2beta1_api_group_discovery_list->kind);
        v2beta1_api_group_discovery_list->kind = NULL;
    }
    if (v2beta1_api_group_discovery_list->metadata) {
        v1_list_meta_free(v2beta1_api_group_discovery_list->metadata);
        v2beta1_api_group_discovery_list->metadata = NULL;
    }
    if (v2beta1_api_group_discovery_list->items) {
        list_ForEach(listEntry, v2beta1_api_group_discovery_list->items) {
            v2beta1_api_group_discovery_free(listEntry->data);
        }
        list_freeList(v2beta1_api_group_discovery_list->items);
        v2beta1_api_group_discovery_list->items = NULL;
    }
    free(v2beta1_api_group_discovery_list);
}

cJSON *v2beta1_api_group_discovery_list_convertToJSON(v2beta1_api_group_discovery_list_t *v2beta1_api_group_discovery_list) {
    cJSON *item = cJSON_CreateObject();

    // v2beta1_api_group_discovery_list->api_version
    if(v2beta1_api_group_discovery_list->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v2beta1_api_group_discovery_list->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v2beta1_api_group_discovery_list->kind
    if(v2beta1_api_group_discovery_list->kind) {
    if(cJSON_AddStringToObject(item, "kind", v2beta1_api_group_discovery_list->kind) == NULL) {
    goto fail; //String
    }
    }


    // v2beta1_api_group_discovery_list->metadata
    if(v2beta1_api_group_discovery_list->metadata) {
    cJSON *metadata_local_JSON = v1_list_meta_convertToJSON(v2beta1_api_group_discovery_list->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v2beta1_api_group_discovery_list->items
    if (!v2beta1_api_group_discovery_list->items) {
        goto fail;
    }
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (v2beta1_api_group_discovery_list->items) {
    list_ForEach(itemsListEntry, v2beta1_api_group_discovery_list->items) {
    cJSON *itemLocal = v2beta1_api_group_discovery_convertToJSON(itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(items, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v2beta1_api_group_discovery_list_t *v2beta1_api_group_discovery_list_parseFromJSON(cJSON *v2beta1_api_group_discovery_listJSON){

    v2beta1_api_group_discovery_list_t *v2beta1_api_group_discovery_list_local_var = NULL;

    char *api_version_local_str = NULL;

    char *kind_local_str = NULL;

    // define the local variable for v2beta1_api_group_discovery_list->metadata
    v1_list_meta_t *metadata_local_nonprim = NULL;

    // define the local list for v2beta1_api_group_discovery_list->items
    list_t *itemsList = NULL;

    // v2beta1_api_group_discovery_list->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v2beta1_api_group_discovery_listJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v2beta1_api_group_discovery_list->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v2beta1_api_group_discovery_listJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v2beta1_api_group_discovery_list->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v2beta1_api_group_discovery_listJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_list_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v2beta1_api_group_discovery_list->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(v2beta1_api_group_discovery_listJSON, "items");
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
        v2beta1_api_group_discovery_t *itemsItem = v2beta1_api_group_discovery_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }


    if (api_version && !cJSON_IsNull(api_version)) api_version_local_str = strdup(api_version->valuestring);
    if (kind && !cJSON_IsNull(kind)) kind_local_str = strdup(kind->valuestring);

    v2beta1_api_group_discovery_list_local_var = v2beta1_api_group_discovery_list_create_internal (
        api_version_local_str,
        kind_local_str,
        metadata ? metadata_local_nonprim : NULL,
        itemsList
        );

    if (!v2beta1_api_group_discovery_list_local_var) {
        goto end;
    }

    return v2beta1_api_group_discovery_list_local_var;
end:
    if (api_version_local_str) {
        free(api_version_local_str);
        api_version_local_str = NULL;
    }
    if (kind_local_str) {
        free(kind_local_str);
        kind_local_str = NULL;
    }
    if (metadata_local_nonprim) {
        v1_list_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (itemsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, itemsList) {
            v2beta1_api_group_discovery_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(itemsList);
        itemsList = NULL;
    }
    return NULL;

}
