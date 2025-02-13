#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_api_resource_list.h"



static v1_api_resource_list_t *v1_api_resource_list_create_internal(
    char *api_version,
    char *group_version,
    char *kind,
    list_t *resources
    ) {
    v1_api_resource_list_t *v1_api_resource_list_local_var = malloc(sizeof(v1_api_resource_list_t));
    if (!v1_api_resource_list_local_var) {
        return NULL;
    }
    v1_api_resource_list_local_var->api_version = api_version;
    v1_api_resource_list_local_var->group_version = group_version;
    v1_api_resource_list_local_var->kind = kind;
    v1_api_resource_list_local_var->resources = resources;

    v1_api_resource_list_local_var->_library_owned = 1;
    return v1_api_resource_list_local_var;
}

__attribute__((deprecated)) v1_api_resource_list_t *v1_api_resource_list_create(
    char *api_version,
    char *group_version,
    char *kind,
    list_t *resources
    ) {
    return v1_api_resource_list_create_internal (
        api_version,
        group_version,
        kind,
        resources
        );
}

void v1_api_resource_list_free(v1_api_resource_list_t *v1_api_resource_list) {
    if(NULL == v1_api_resource_list){
        return ;
    }
    if(v1_api_resource_list->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_api_resource_list_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_api_resource_list->api_version) {
        free(v1_api_resource_list->api_version);
        v1_api_resource_list->api_version = NULL;
    }
    if (v1_api_resource_list->group_version) {
        free(v1_api_resource_list->group_version);
        v1_api_resource_list->group_version = NULL;
    }
    if (v1_api_resource_list->kind) {
        free(v1_api_resource_list->kind);
        v1_api_resource_list->kind = NULL;
    }
    if (v1_api_resource_list->resources) {
        list_ForEach(listEntry, v1_api_resource_list->resources) {
            v1_api_resource_free(listEntry->data);
        }
        list_freeList(v1_api_resource_list->resources);
        v1_api_resource_list->resources = NULL;
    }
    free(v1_api_resource_list);
}

cJSON *v1_api_resource_list_convertToJSON(v1_api_resource_list_t *v1_api_resource_list) {
    cJSON *item = cJSON_CreateObject();

    // v1_api_resource_list->api_version
    if(v1_api_resource_list->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_api_resource_list->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_api_resource_list->group_version
    if (!v1_api_resource_list->group_version) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "groupVersion", v1_api_resource_list->group_version) == NULL) {
    goto fail; //String
    }


    // v1_api_resource_list->kind
    if(v1_api_resource_list->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_api_resource_list->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_api_resource_list->resources
    if (!v1_api_resource_list->resources) {
        goto fail;
    }
    cJSON *resources = cJSON_AddArrayToObject(item, "resources");
    if(resources == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resourcesListEntry;
    if (v1_api_resource_list->resources) {
    list_ForEach(resourcesListEntry, v1_api_resource_list->resources) {
    cJSON *itemLocal = v1_api_resource_convertToJSON(resourcesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(resources, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_api_resource_list_t *v1_api_resource_list_parseFromJSON(cJSON *v1_api_resource_listJSON){

    v1_api_resource_list_t *v1_api_resource_list_local_var = NULL;

    // define the local list for v1_api_resource_list->resources
    list_t *resourcesList = NULL;

    // v1_api_resource_list->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_api_resource_listJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_api_resource_list->group_version
    cJSON *group_version = cJSON_GetObjectItemCaseSensitive(v1_api_resource_listJSON, "groupVersion");
    if (cJSON_IsNull(group_version)) {
        group_version = NULL;
    }
    if (!group_version) {
        goto end;
    }

    
    if(!cJSON_IsString(group_version))
    {
    goto end; //String
    }

    // v1_api_resource_list->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_api_resource_listJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_api_resource_list->resources
    cJSON *resources = cJSON_GetObjectItemCaseSensitive(v1_api_resource_listJSON, "resources");
    if (cJSON_IsNull(resources)) {
        resources = NULL;
    }
    if (!resources) {
        goto end;
    }

    
    cJSON *resources_local_nonprimitive = NULL;
    if(!cJSON_IsArray(resources)){
        goto end; //nonprimitive container
    }

    resourcesList = list_createList();

    cJSON_ArrayForEach(resources_local_nonprimitive,resources )
    {
        if(!cJSON_IsObject(resources_local_nonprimitive)){
            goto end;
        }
        v1_api_resource_t *resourcesItem = v1_api_resource_parseFromJSON(resources_local_nonprimitive);

        list_addElement(resourcesList, resourcesItem);
    }


    v1_api_resource_list_local_var = v1_api_resource_list_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        strdup(group_version->valuestring),
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        resourcesList
        );

    return v1_api_resource_list_local_var;
end:
    if (resourcesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resourcesList) {
            v1_api_resource_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resourcesList);
        resourcesList = NULL;
    }
    return NULL;

}
