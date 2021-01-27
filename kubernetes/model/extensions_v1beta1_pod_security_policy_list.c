#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_pod_security_policy_list.h"



extensions_v1beta1_pod_security_policy_list_t *extensions_v1beta1_pod_security_policy_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
    ) {
    extensions_v1beta1_pod_security_policy_list_t *extensions_v1beta1_pod_security_policy_list_local_var = malloc(sizeof(extensions_v1beta1_pod_security_policy_list_t));
    if (!extensions_v1beta1_pod_security_policy_list_local_var) {
        return NULL;
    }
    extensions_v1beta1_pod_security_policy_list_local_var->api_version = api_version;
    extensions_v1beta1_pod_security_policy_list_local_var->items = items;
    extensions_v1beta1_pod_security_policy_list_local_var->kind = kind;
    extensions_v1beta1_pod_security_policy_list_local_var->metadata = metadata;

    return extensions_v1beta1_pod_security_policy_list_local_var;
}


void extensions_v1beta1_pod_security_policy_list_free(extensions_v1beta1_pod_security_policy_list_t *extensions_v1beta1_pod_security_policy_list) {
    if(NULL == extensions_v1beta1_pod_security_policy_list){
        return ;
    }
    listEntry_t *listEntry;
    if (extensions_v1beta1_pod_security_policy_list->api_version) {
        free(extensions_v1beta1_pod_security_policy_list->api_version);
        extensions_v1beta1_pod_security_policy_list->api_version = NULL;
    }
    if (extensions_v1beta1_pod_security_policy_list->items) {
        list_ForEach(listEntry, extensions_v1beta1_pod_security_policy_list->items) {
            extensions_v1beta1_pod_security_policy_free(listEntry->data);
        }
        list_free(extensions_v1beta1_pod_security_policy_list->items);
        extensions_v1beta1_pod_security_policy_list->items = NULL;
    }
    if (extensions_v1beta1_pod_security_policy_list->kind) {
        free(extensions_v1beta1_pod_security_policy_list->kind);
        extensions_v1beta1_pod_security_policy_list->kind = NULL;
    }
    if (extensions_v1beta1_pod_security_policy_list->metadata) {
        v1_list_meta_free(extensions_v1beta1_pod_security_policy_list->metadata);
        extensions_v1beta1_pod_security_policy_list->metadata = NULL;
    }
    free(extensions_v1beta1_pod_security_policy_list);
}

cJSON *extensions_v1beta1_pod_security_policy_list_convertToJSON(extensions_v1beta1_pod_security_policy_list_t *extensions_v1beta1_pod_security_policy_list) {
    cJSON *item = cJSON_CreateObject();

    // extensions_v1beta1_pod_security_policy_list->api_version
    if(extensions_v1beta1_pod_security_policy_list->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", extensions_v1beta1_pod_security_policy_list->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // extensions_v1beta1_pod_security_policy_list->items
    if (!extensions_v1beta1_pod_security_policy_list->items) {
        goto fail;
    }
    
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (extensions_v1beta1_pod_security_policy_list->items) {
    list_ForEach(itemsListEntry, extensions_v1beta1_pod_security_policy_list->items) {
    cJSON *itemLocal = extensions_v1beta1_pod_security_policy_convertToJSON(itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(items, itemLocal);
    }
    }


    // extensions_v1beta1_pod_security_policy_list->kind
    if(extensions_v1beta1_pod_security_policy_list->kind) { 
    if(cJSON_AddStringToObject(item, "kind", extensions_v1beta1_pod_security_policy_list->kind) == NULL) {
    goto fail; //String
    }
     } 


    // extensions_v1beta1_pod_security_policy_list->metadata
    if(extensions_v1beta1_pod_security_policy_list->metadata) { 
    cJSON *metadata_local_JSON = v1_list_meta_convertToJSON(extensions_v1beta1_pod_security_policy_list->metadata);
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

extensions_v1beta1_pod_security_policy_list_t *extensions_v1beta1_pod_security_policy_list_parseFromJSON(cJSON *extensions_v1beta1_pod_security_policy_listJSON){

    extensions_v1beta1_pod_security_policy_list_t *extensions_v1beta1_pod_security_policy_list_local_var = NULL;

    // extensions_v1beta1_pod_security_policy_list->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_pod_security_policy_listJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // extensions_v1beta1_pod_security_policy_list->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_pod_security_policy_listJSON, "items");
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
        extensions_v1beta1_pod_security_policy_t *itemsItem = extensions_v1beta1_pod_security_policy_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }

    // extensions_v1beta1_pod_security_policy_list->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_pod_security_policy_listJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // extensions_v1beta1_pod_security_policy_list->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_pod_security_policy_listJSON, "metadata");
    v1_list_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_list_meta_parseFromJSON(metadata); //nonprimitive
    }


    extensions_v1beta1_pod_security_policy_list_local_var = extensions_v1beta1_pod_security_policy_list_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        itemsList,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL
        );

    return extensions_v1beta1_pod_security_policy_list_local_var;
end:
    if (metadata_local_nonprim) {
        v1_list_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    return NULL;

}
