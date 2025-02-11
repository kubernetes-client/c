#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_resource_status.h"



static v1_resource_status_t *v1_resource_status_create_internal(
    char *name,
    list_t *resources
    ) {
    v1_resource_status_t *v1_resource_status_local_var = malloc(sizeof(v1_resource_status_t));
    if (!v1_resource_status_local_var) {
        return NULL;
    }
    v1_resource_status_local_var->name = name;
    v1_resource_status_local_var->resources = resources;

    v1_resource_status_local_var->_library_owned = 1;
    return v1_resource_status_local_var;
}

__attribute__((deprecated)) v1_resource_status_t *v1_resource_status_create(
    char *name,
    list_t *resources
    ) {
    return v1_resource_status_create_internal (
        name,
        resources
        );
}

void v1_resource_status_free(v1_resource_status_t *v1_resource_status) {
    if(NULL == v1_resource_status){
        return ;
    }
    if(v1_resource_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_resource_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_resource_status->name) {
        free(v1_resource_status->name);
        v1_resource_status->name = NULL;
    }
    if (v1_resource_status->resources) {
        list_ForEach(listEntry, v1_resource_status->resources) {
            v1_resource_health_free(listEntry->data);
        }
        list_freeList(v1_resource_status->resources);
        v1_resource_status->resources = NULL;
    }
    free(v1_resource_status);
}

cJSON *v1_resource_status_convertToJSON(v1_resource_status_t *v1_resource_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_resource_status->name
    if (!v1_resource_status->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_resource_status->name) == NULL) {
    goto fail; //String
    }


    // v1_resource_status->resources
    if(v1_resource_status->resources) {
    cJSON *resources = cJSON_AddArrayToObject(item, "resources");
    if(resources == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resourcesListEntry;
    if (v1_resource_status->resources) {
    list_ForEach(resourcesListEntry, v1_resource_status->resources) {
    cJSON *itemLocal = v1_resource_health_convertToJSON(resourcesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(resources, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_resource_status_t *v1_resource_status_parseFromJSON(cJSON *v1_resource_statusJSON){

    v1_resource_status_t *v1_resource_status_local_var = NULL;

    // define the local list for v1_resource_status->resources
    list_t *resourcesList = NULL;

    // v1_resource_status->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_resource_statusJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_resource_status->resources
    cJSON *resources = cJSON_GetObjectItemCaseSensitive(v1_resource_statusJSON, "resources");
    if (cJSON_IsNull(resources)) {
        resources = NULL;
    }
    if (resources) { 
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
        v1_resource_health_t *resourcesItem = v1_resource_health_parseFromJSON(resources_local_nonprimitive);

        list_addElement(resourcesList, resourcesItem);
    }
    }


    v1_resource_status_local_var = v1_resource_status_create_internal (
        strdup(name->valuestring),
        resources ? resourcesList : NULL
        );

    return v1_resource_status_local_var;
end:
    if (resourcesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resourcesList) {
            v1_resource_health_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resourcesList);
        resourcesList = NULL;
    }
    return NULL;

}
