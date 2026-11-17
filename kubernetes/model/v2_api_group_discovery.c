#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2_api_group_discovery.h"



static v2_api_group_discovery_t *v2_api_group_discovery_create_internal(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *versions
    ) {
    v2_api_group_discovery_t *v2_api_group_discovery_local_var = malloc(sizeof(v2_api_group_discovery_t));
    if (!v2_api_group_discovery_local_var) {
        return NULL;
    }
    memset(v2_api_group_discovery_local_var, 0, sizeof(v2_api_group_discovery_t));
    v2_api_group_discovery_local_var->_library_owned = 1;
    v2_api_group_discovery_local_var->api_version = api_version;
    v2_api_group_discovery_local_var->kind = kind;
    v2_api_group_discovery_local_var->metadata = metadata;
    v2_api_group_discovery_local_var->versions = versions;
    return v2_api_group_discovery_local_var;
}

__attribute__((deprecated)) v2_api_group_discovery_t *v2_api_group_discovery_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *versions
    ) {
    v2_api_group_discovery_t *result = v2_api_group_discovery_create_internal (
        api_version,
        kind,
        metadata,
        versions
        );
    if (!result) {
    }
    return result;
}

void v2_api_group_discovery_free(v2_api_group_discovery_t *v2_api_group_discovery) {
    if(NULL == v2_api_group_discovery){
        return ;
    }
    if(v2_api_group_discovery->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v2_api_group_discovery_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v2_api_group_discovery->api_version) {
        free(v2_api_group_discovery->api_version);
        v2_api_group_discovery->api_version = NULL;
    }
    if (v2_api_group_discovery->kind) {
        free(v2_api_group_discovery->kind);
        v2_api_group_discovery->kind = NULL;
    }
    if (v2_api_group_discovery->metadata) {
        v1_object_meta_free(v2_api_group_discovery->metadata);
        v2_api_group_discovery->metadata = NULL;
    }
    if (v2_api_group_discovery->versions) {
        list_ForEach(listEntry, v2_api_group_discovery->versions) {
            v2_api_version_discovery_free(listEntry->data);
        }
        list_freeList(v2_api_group_discovery->versions);
        v2_api_group_discovery->versions = NULL;
    }
    free(v2_api_group_discovery);
}

cJSON *v2_api_group_discovery_convertToJSON(v2_api_group_discovery_t *v2_api_group_discovery) {
    cJSON *item = cJSON_CreateObject();

    // v2_api_group_discovery->api_version
    if(v2_api_group_discovery->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v2_api_group_discovery->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v2_api_group_discovery->kind
    if(v2_api_group_discovery->kind) {
    if(cJSON_AddStringToObject(item, "kind", v2_api_group_discovery->kind) == NULL) {
    goto fail; //String
    }
    }


    // v2_api_group_discovery->metadata
    if(v2_api_group_discovery->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v2_api_group_discovery->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v2_api_group_discovery->versions
    if(v2_api_group_discovery->versions) {
    cJSON *versions = cJSON_AddArrayToObject(item, "versions");
    if(versions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *versionsListEntry;
    if (v2_api_group_discovery->versions) {
    list_ForEach(versionsListEntry, v2_api_group_discovery->versions) {
    cJSON *itemLocal = v2_api_version_discovery_convertToJSON(versionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(versions, itemLocal);
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

v2_api_group_discovery_t *v2_api_group_discovery_parseFromJSON(cJSON *v2_api_group_discoveryJSON){

    v2_api_group_discovery_t *v2_api_group_discovery_local_var = NULL;

    char *api_version_local_str = NULL;

    char *kind_local_str = NULL;

    // define the local variable for v2_api_group_discovery->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local list for v2_api_group_discovery->versions
    list_t *versionsList = NULL;

    // v2_api_group_discovery->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v2_api_group_discoveryJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v2_api_group_discovery->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v2_api_group_discoveryJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v2_api_group_discovery->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v2_api_group_discoveryJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v2_api_group_discovery->versions
    cJSON *versions = cJSON_GetObjectItemCaseSensitive(v2_api_group_discoveryJSON, "versions");
    if (cJSON_IsNull(versions)) {
        versions = NULL;
    }
    if (versions) { 
    cJSON *versions_local_nonprimitive = NULL;
    if(!cJSON_IsArray(versions)){
        goto end; //nonprimitive container
    }

    versionsList = list_createList();

    cJSON_ArrayForEach(versions_local_nonprimitive,versions )
    {
        if(!cJSON_IsObject(versions_local_nonprimitive)){
            goto end;
        }
        v2_api_version_discovery_t *versionsItem = v2_api_version_discovery_parseFromJSON(versions_local_nonprimitive);

        list_addElement(versionsList, versionsItem);
    }
    }


    if (api_version && !cJSON_IsNull(api_version)) api_version_local_str = strdup(api_version->valuestring);
    if (kind && !cJSON_IsNull(kind)) kind_local_str = strdup(kind->valuestring);

    v2_api_group_discovery_local_var = v2_api_group_discovery_create_internal (
        api_version_local_str,
        kind_local_str,
        metadata ? metadata_local_nonprim : NULL,
        versions ? versionsList : NULL
        );

    if (!v2_api_group_discovery_local_var) {
        goto end;
    }

    return v2_api_group_discovery_local_var;
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
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (versionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, versionsList) {
            v2_api_version_discovery_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(versionsList);
        versionsList = NULL;
    }
    return NULL;

}
