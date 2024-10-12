#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_resource_claim_list.h"



v1alpha3_resource_claim_list_t *v1alpha3_resource_claim_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
    ) {
    v1alpha3_resource_claim_list_t *v1alpha3_resource_claim_list_local_var = malloc(sizeof(v1alpha3_resource_claim_list_t));
    if (!v1alpha3_resource_claim_list_local_var) {
        return NULL;
    }
    v1alpha3_resource_claim_list_local_var->api_version = api_version;
    v1alpha3_resource_claim_list_local_var->items = items;
    v1alpha3_resource_claim_list_local_var->kind = kind;
    v1alpha3_resource_claim_list_local_var->metadata = metadata;

    return v1alpha3_resource_claim_list_local_var;
}


void v1alpha3_resource_claim_list_free(v1alpha3_resource_claim_list_t *v1alpha3_resource_claim_list) {
    if(NULL == v1alpha3_resource_claim_list){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_resource_claim_list->api_version) {
        free(v1alpha3_resource_claim_list->api_version);
        v1alpha3_resource_claim_list->api_version = NULL;
    }
    if (v1alpha3_resource_claim_list->items) {
        list_ForEach(listEntry, v1alpha3_resource_claim_list->items) {
            v1alpha3_resource_claim_free(listEntry->data);
        }
        list_freeList(v1alpha3_resource_claim_list->items);
        v1alpha3_resource_claim_list->items = NULL;
    }
    if (v1alpha3_resource_claim_list->kind) {
        free(v1alpha3_resource_claim_list->kind);
        v1alpha3_resource_claim_list->kind = NULL;
    }
    if (v1alpha3_resource_claim_list->metadata) {
        v1_list_meta_free(v1alpha3_resource_claim_list->metadata);
        v1alpha3_resource_claim_list->metadata = NULL;
    }
    free(v1alpha3_resource_claim_list);
}

cJSON *v1alpha3_resource_claim_list_convertToJSON(v1alpha3_resource_claim_list_t *v1alpha3_resource_claim_list) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_resource_claim_list->api_version
    if(v1alpha3_resource_claim_list->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1alpha3_resource_claim_list->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_resource_claim_list->items
    if (!v1alpha3_resource_claim_list->items) {
        goto fail;
    }
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (v1alpha3_resource_claim_list->items) {
    list_ForEach(itemsListEntry, v1alpha3_resource_claim_list->items) {
    cJSON *itemLocal = v1alpha3_resource_claim_convertToJSON(itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(items, itemLocal);
    }
    }


    // v1alpha3_resource_claim_list->kind
    if(v1alpha3_resource_claim_list->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1alpha3_resource_claim_list->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_resource_claim_list->metadata
    if(v1alpha3_resource_claim_list->metadata) {
    cJSON *metadata_local_JSON = v1_list_meta_convertToJSON(v1alpha3_resource_claim_list->metadata);
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

v1alpha3_resource_claim_list_t *v1alpha3_resource_claim_list_parseFromJSON(cJSON *v1alpha3_resource_claim_listJSON){

    v1alpha3_resource_claim_list_t *v1alpha3_resource_claim_list_local_var = NULL;

    // define the local list for v1alpha3_resource_claim_list->items
    list_t *itemsList = NULL;

    // define the local variable for v1alpha3_resource_claim_list->metadata
    v1_list_meta_t *metadata_local_nonprim = NULL;

    // v1alpha3_resource_claim_list->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_claim_listJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1alpha3_resource_claim_list->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_claim_listJSON, "items");
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
        v1alpha3_resource_claim_t *itemsItem = v1alpha3_resource_claim_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }

    // v1alpha3_resource_claim_list->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_claim_listJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1alpha3_resource_claim_list->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_claim_listJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_list_meta_parseFromJSON(metadata); //nonprimitive
    }


    v1alpha3_resource_claim_list_local_var = v1alpha3_resource_claim_list_create (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        itemsList,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL
        );

    return v1alpha3_resource_claim_list_local_var;
end:
    if (itemsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, itemsList) {
            v1alpha3_resource_claim_free(listEntry->data);
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
