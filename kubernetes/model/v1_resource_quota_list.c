#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_resource_quota_list.h"



v1_resource_quota_list_t *v1_resource_quota_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
    ) {
    v1_resource_quota_list_t *v1_resource_quota_list_local_var = malloc(sizeof(v1_resource_quota_list_t));
    if (!v1_resource_quota_list_local_var) {
        return NULL;
    }
    v1_resource_quota_list_local_var->api_version = api_version;
    v1_resource_quota_list_local_var->items = items;
    v1_resource_quota_list_local_var->kind = kind;
    v1_resource_quota_list_local_var->metadata = metadata;

    return v1_resource_quota_list_local_var;
}


void v1_resource_quota_list_free(v1_resource_quota_list_t *v1_resource_quota_list) {
    if(NULL == v1_resource_quota_list){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_resource_quota_list->api_version) {
        free(v1_resource_quota_list->api_version);
        v1_resource_quota_list->api_version = NULL;
    }
    if (v1_resource_quota_list->items) {
        list_ForEach(listEntry, v1_resource_quota_list->items) {
            v1_resource_quota_free(listEntry->data);
        }
        list_free(v1_resource_quota_list->items);
        v1_resource_quota_list->items = NULL;
    }
    if (v1_resource_quota_list->kind) {
        free(v1_resource_quota_list->kind);
        v1_resource_quota_list->kind = NULL;
    }
    if (v1_resource_quota_list->metadata) {
        v1_list_meta_free(v1_resource_quota_list->metadata);
        v1_resource_quota_list->metadata = NULL;
    }
    free(v1_resource_quota_list);
}

cJSON *v1_resource_quota_list_convertToJSON(v1_resource_quota_list_t *v1_resource_quota_list) {
    cJSON *item = cJSON_CreateObject();

    // v1_resource_quota_list->api_version
    if(v1_resource_quota_list->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_resource_quota_list->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // v1_resource_quota_list->items
    if (!v1_resource_quota_list->items) {
        goto fail;
    }
    
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (v1_resource_quota_list->items) {
    list_ForEach(itemsListEntry, v1_resource_quota_list->items) {
    cJSON *itemLocal = v1_resource_quota_convertToJSON(itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(items, itemLocal);
    }
    }


    // v1_resource_quota_list->kind
    if(v1_resource_quota_list->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_resource_quota_list->kind) == NULL) {
    goto fail; //String
    }
     } 


    // v1_resource_quota_list->metadata
    if(v1_resource_quota_list->metadata) { 
    cJSON *metadata_local_JSON = v1_list_meta_convertToJSON(v1_resource_quota_list->metadata);
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

v1_resource_quota_list_t *v1_resource_quota_list_parseFromJSON(cJSON *v1_resource_quota_listJSON){

    v1_resource_quota_list_t *v1_resource_quota_list_local_var = NULL;

    // v1_resource_quota_list->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_resource_quota_listJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v1_resource_quota_list->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(v1_resource_quota_listJSON, "items");
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
        v1_resource_quota_t *itemsItem = v1_resource_quota_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }

    // v1_resource_quota_list->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_resource_quota_listJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_resource_quota_list->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_resource_quota_listJSON, "metadata");
    v1_list_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_list_meta_parseFromJSON(metadata); //nonprimitive
    }


    v1_resource_quota_list_local_var = v1_resource_quota_list_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        itemsList,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL
        );

    return v1_resource_quota_list_local_var;
end:
    if (metadata_local_nonprim) {
        v1_list_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    return NULL;

}
