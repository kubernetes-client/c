#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "apps_v1beta1_deployment_list.h"



apps_v1beta1_deployment_list_t *apps_v1beta1_deployment_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
    ) {
    apps_v1beta1_deployment_list_t *apps_v1beta1_deployment_list_local_var = malloc(sizeof(apps_v1beta1_deployment_list_t));
    if (!apps_v1beta1_deployment_list_local_var) {
        return NULL;
    }
    apps_v1beta1_deployment_list_local_var->api_version = api_version;
    apps_v1beta1_deployment_list_local_var->items = items;
    apps_v1beta1_deployment_list_local_var->kind = kind;
    apps_v1beta1_deployment_list_local_var->metadata = metadata;

    return apps_v1beta1_deployment_list_local_var;
}


void apps_v1beta1_deployment_list_free(apps_v1beta1_deployment_list_t *apps_v1beta1_deployment_list) {
    if(NULL == apps_v1beta1_deployment_list){
        return ;
    }
    listEntry_t *listEntry;
    if (apps_v1beta1_deployment_list->api_version) {
        free(apps_v1beta1_deployment_list->api_version);
        apps_v1beta1_deployment_list->api_version = NULL;
    }
    if (apps_v1beta1_deployment_list->items) {
        list_ForEach(listEntry, apps_v1beta1_deployment_list->items) {
            apps_v1beta1_deployment_free(listEntry->data);
        }
        list_free(apps_v1beta1_deployment_list->items);
        apps_v1beta1_deployment_list->items = NULL;
    }
    if (apps_v1beta1_deployment_list->kind) {
        free(apps_v1beta1_deployment_list->kind);
        apps_v1beta1_deployment_list->kind = NULL;
    }
    if (apps_v1beta1_deployment_list->metadata) {
        v1_list_meta_free(apps_v1beta1_deployment_list->metadata);
        apps_v1beta1_deployment_list->metadata = NULL;
    }
    free(apps_v1beta1_deployment_list);
}

cJSON *apps_v1beta1_deployment_list_convertToJSON(apps_v1beta1_deployment_list_t *apps_v1beta1_deployment_list) {
    cJSON *item = cJSON_CreateObject();

    // apps_v1beta1_deployment_list->api_version
    if(apps_v1beta1_deployment_list->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", apps_v1beta1_deployment_list->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // apps_v1beta1_deployment_list->items
    if (!apps_v1beta1_deployment_list->items) {
        goto fail;
    }
    
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (apps_v1beta1_deployment_list->items) {
    list_ForEach(itemsListEntry, apps_v1beta1_deployment_list->items) {
    cJSON *itemLocal = apps_v1beta1_deployment_convertToJSON(itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(items, itemLocal);
    }
    }


    // apps_v1beta1_deployment_list->kind
    if(apps_v1beta1_deployment_list->kind) { 
    if(cJSON_AddStringToObject(item, "kind", apps_v1beta1_deployment_list->kind) == NULL) {
    goto fail; //String
    }
     } 


    // apps_v1beta1_deployment_list->metadata
    if(apps_v1beta1_deployment_list->metadata) { 
    cJSON *metadata_local_JSON = v1_list_meta_convertToJSON(apps_v1beta1_deployment_list->metadata);
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

apps_v1beta1_deployment_list_t *apps_v1beta1_deployment_list_parseFromJSON(cJSON *apps_v1beta1_deployment_listJSON){

    apps_v1beta1_deployment_list_t *apps_v1beta1_deployment_list_local_var = NULL;

    // apps_v1beta1_deployment_list->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_listJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // apps_v1beta1_deployment_list->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_listJSON, "items");
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
        apps_v1beta1_deployment_t *itemsItem = apps_v1beta1_deployment_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }

    // apps_v1beta1_deployment_list->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_listJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // apps_v1beta1_deployment_list->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_listJSON, "metadata");
    v1_list_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_list_meta_parseFromJSON(metadata); //nonprimitive
    }


    apps_v1beta1_deployment_list_local_var = apps_v1beta1_deployment_list_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        itemsList,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL
        );

    return apps_v1beta1_deployment_list_local_var;
end:
    if (metadata_local_nonprim) {
        v1_list_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    return NULL;

}
