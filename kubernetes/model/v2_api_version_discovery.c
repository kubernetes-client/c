#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2_api_version_discovery.h"



static v2_api_version_discovery_t *v2_api_version_discovery_create_internal(
    char *version,
    list_t *resources,
    char *freshness
    ) {
    v2_api_version_discovery_t *v2_api_version_discovery_local_var = malloc(sizeof(v2_api_version_discovery_t));
    if (!v2_api_version_discovery_local_var) {
        return NULL;
    }
    memset(v2_api_version_discovery_local_var, 0, sizeof(v2_api_version_discovery_t));
    v2_api_version_discovery_local_var->_library_owned = 1;
    v2_api_version_discovery_local_var->version = version;
    v2_api_version_discovery_local_var->resources = resources;
    v2_api_version_discovery_local_var->freshness = freshness;
    return v2_api_version_discovery_local_var;
}

__attribute__((deprecated)) v2_api_version_discovery_t *v2_api_version_discovery_create(
    char *version,
    list_t *resources,
    char *freshness
    ) {
    v2_api_version_discovery_t *result = v2_api_version_discovery_create_internal (
        version,
        resources,
        freshness
        );
    if (!result) {
    }
    return result;
}

void v2_api_version_discovery_free(v2_api_version_discovery_t *v2_api_version_discovery) {
    if(NULL == v2_api_version_discovery){
        return ;
    }
    if(v2_api_version_discovery->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v2_api_version_discovery_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v2_api_version_discovery->version) {
        free(v2_api_version_discovery->version);
        v2_api_version_discovery->version = NULL;
    }
    if (v2_api_version_discovery->resources) {
        list_ForEach(listEntry, v2_api_version_discovery->resources) {
            v2_api_resource_discovery_free(listEntry->data);
        }
        list_freeList(v2_api_version_discovery->resources);
        v2_api_version_discovery->resources = NULL;
    }
    if (v2_api_version_discovery->freshness) {
        free(v2_api_version_discovery->freshness);
        v2_api_version_discovery->freshness = NULL;
    }
    free(v2_api_version_discovery);
}

cJSON *v2_api_version_discovery_convertToJSON(v2_api_version_discovery_t *v2_api_version_discovery) {
    cJSON *item = cJSON_CreateObject();

    // v2_api_version_discovery->version
    if (!v2_api_version_discovery->version) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "version", v2_api_version_discovery->version) == NULL) {
    goto fail; //String
    }


    // v2_api_version_discovery->resources
    if(v2_api_version_discovery->resources) {
    cJSON *resources = cJSON_AddArrayToObject(item, "resources");
    if(resources == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resourcesListEntry;
    if (v2_api_version_discovery->resources) {
    list_ForEach(resourcesListEntry, v2_api_version_discovery->resources) {
    cJSON *itemLocal = v2_api_resource_discovery_convertToJSON(resourcesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(resources, itemLocal);
    }
    }
    }


    // v2_api_version_discovery->freshness
    if(v2_api_version_discovery->freshness) {
    if(cJSON_AddStringToObject(item, "freshness", v2_api_version_discovery->freshness) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v2_api_version_discovery_t *v2_api_version_discovery_parseFromJSON(cJSON *v2_api_version_discoveryJSON){

    v2_api_version_discovery_t *v2_api_version_discovery_local_var = NULL;

    char *version_local_str = NULL;

    // define the local list for v2_api_version_discovery->resources
    list_t *resourcesList = NULL;

    char *freshness_local_str = NULL;

    // v2_api_version_discovery->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(v2_api_version_discoveryJSON, "version");
    if (cJSON_IsNull(version)) {
        version = NULL;
    }
    if (!version) {
        goto end;
    }

    
    if(!cJSON_IsString(version))
    {
    goto end; //String
    }

    // v2_api_version_discovery->resources
    cJSON *resources = cJSON_GetObjectItemCaseSensitive(v2_api_version_discoveryJSON, "resources");
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
        v2_api_resource_discovery_t *resourcesItem = v2_api_resource_discovery_parseFromJSON(resources_local_nonprimitive);

        list_addElement(resourcesList, resourcesItem);
    }
    }

    // v2_api_version_discovery->freshness
    cJSON *freshness = cJSON_GetObjectItemCaseSensitive(v2_api_version_discoveryJSON, "freshness");
    if (cJSON_IsNull(freshness)) {
        freshness = NULL;
    }
    if (freshness) { 
    if(!cJSON_IsString(freshness) && !cJSON_IsNull(freshness))
    {
    goto end; //String
    }
    }


    if (version && !cJSON_IsNull(version)) version_local_str = strdup(version->valuestring);
    if (freshness && !cJSON_IsNull(freshness)) freshness_local_str = strdup(freshness->valuestring);

    v2_api_version_discovery_local_var = v2_api_version_discovery_create_internal (
        version_local_str,
        resources ? resourcesList : NULL,
        freshness_local_str
        );

    if (!v2_api_version_discovery_local_var) {
        goto end;
    }

    return v2_api_version_discovery_local_var;
end:
    if (version_local_str) {
        free(version_local_str);
        version_local_str = NULL;
    }
    if (resourcesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resourcesList) {
            v2_api_resource_discovery_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resourcesList);
        resourcesList = NULL;
    }
    if (freshness_local_str) {
        free(freshness_local_str);
        freshness_local_str = NULL;
    }
    return NULL;

}
