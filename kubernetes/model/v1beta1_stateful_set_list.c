#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_stateful_set_list.h"



v1beta1_stateful_set_list_t *v1beta1_stateful_set_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
    ) {
    v1beta1_stateful_set_list_t *v1beta1_stateful_set_list_local_var = malloc(sizeof(v1beta1_stateful_set_list_t));
    if (!v1beta1_stateful_set_list_local_var) {
        return NULL;
    }
    v1beta1_stateful_set_list_local_var->api_version = api_version;
    v1beta1_stateful_set_list_local_var->items = items;
    v1beta1_stateful_set_list_local_var->kind = kind;
    v1beta1_stateful_set_list_local_var->metadata = metadata;

    return v1beta1_stateful_set_list_local_var;
}


void v1beta1_stateful_set_list_free(v1beta1_stateful_set_list_t *v1beta1_stateful_set_list) {
    if(NULL == v1beta1_stateful_set_list){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_stateful_set_list->api_version) {
        free(v1beta1_stateful_set_list->api_version);
        v1beta1_stateful_set_list->api_version = NULL;
    }
    if (v1beta1_stateful_set_list->items) {
        list_ForEach(listEntry, v1beta1_stateful_set_list->items) {
            v1beta1_stateful_set_free(listEntry->data);
        }
        list_free(v1beta1_stateful_set_list->items);
        v1beta1_stateful_set_list->items = NULL;
    }
    if (v1beta1_stateful_set_list->kind) {
        free(v1beta1_stateful_set_list->kind);
        v1beta1_stateful_set_list->kind = NULL;
    }
    if (v1beta1_stateful_set_list->metadata) {
        v1_list_meta_free(v1beta1_stateful_set_list->metadata);
        v1beta1_stateful_set_list->metadata = NULL;
    }
    free(v1beta1_stateful_set_list);
}

cJSON *v1beta1_stateful_set_list_convertToJSON(v1beta1_stateful_set_list_t *v1beta1_stateful_set_list) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_stateful_set_list->api_version
    if(v1beta1_stateful_set_list->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1beta1_stateful_set_list->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_stateful_set_list->items
    if (!v1beta1_stateful_set_list->items) {
        goto fail;
    }
    
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (v1beta1_stateful_set_list->items) {
    list_ForEach(itemsListEntry, v1beta1_stateful_set_list->items) {
    cJSON *itemLocal = v1beta1_stateful_set_convertToJSON(itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(items, itemLocal);
    }
    }


    // v1beta1_stateful_set_list->kind
    if(v1beta1_stateful_set_list->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1beta1_stateful_set_list->kind) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_stateful_set_list->metadata
    if(v1beta1_stateful_set_list->metadata) { 
    cJSON *metadata_local_JSON = v1_list_meta_convertToJSON(v1beta1_stateful_set_list->metadata);
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

v1beta1_stateful_set_list_t *v1beta1_stateful_set_list_parseFromJSON(cJSON *v1beta1_stateful_set_listJSON){

    v1beta1_stateful_set_list_t *v1beta1_stateful_set_list_local_var = NULL;

    // v1beta1_stateful_set_list->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1beta1_stateful_set_listJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v1beta1_stateful_set_list->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(v1beta1_stateful_set_listJSON, "items");
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
        v1beta1_stateful_set_t *itemsItem = v1beta1_stateful_set_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }

    // v1beta1_stateful_set_list->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1beta1_stateful_set_listJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1beta1_stateful_set_list->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1beta1_stateful_set_listJSON, "metadata");
    v1_list_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_list_meta_parseFromJSON(metadata); //nonprimitive
    }


    v1beta1_stateful_set_list_local_var = v1beta1_stateful_set_list_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        itemsList,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL
        );

    return v1beta1_stateful_set_list_local_var;
end:
    if (metadata_local_nonprim) {
        v1_list_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    return NULL;

}
