#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_server_storage_version.h"



v1alpha1_server_storage_version_t *v1alpha1_server_storage_version_create(
    char *api_server_id,
    list_t *decodable_versions,
    char *encoding_version,
    list_t *served_versions
    ) {
    v1alpha1_server_storage_version_t *v1alpha1_server_storage_version_local_var = malloc(sizeof(v1alpha1_server_storage_version_t));
    if (!v1alpha1_server_storage_version_local_var) {
        return NULL;
    }
    v1alpha1_server_storage_version_local_var->api_server_id = api_server_id;
    v1alpha1_server_storage_version_local_var->decodable_versions = decodable_versions;
    v1alpha1_server_storage_version_local_var->encoding_version = encoding_version;
    v1alpha1_server_storage_version_local_var->served_versions = served_versions;

    return v1alpha1_server_storage_version_local_var;
}


void v1alpha1_server_storage_version_free(v1alpha1_server_storage_version_t *v1alpha1_server_storage_version) {
    if(NULL == v1alpha1_server_storage_version){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_server_storage_version->api_server_id) {
        free(v1alpha1_server_storage_version->api_server_id);
        v1alpha1_server_storage_version->api_server_id = NULL;
    }
    if (v1alpha1_server_storage_version->decodable_versions) {
        list_ForEach(listEntry, v1alpha1_server_storage_version->decodable_versions) {
            free(listEntry->data);
        }
        list_freeList(v1alpha1_server_storage_version->decodable_versions);
        v1alpha1_server_storage_version->decodable_versions = NULL;
    }
    if (v1alpha1_server_storage_version->encoding_version) {
        free(v1alpha1_server_storage_version->encoding_version);
        v1alpha1_server_storage_version->encoding_version = NULL;
    }
    if (v1alpha1_server_storage_version->served_versions) {
        list_ForEach(listEntry, v1alpha1_server_storage_version->served_versions) {
            free(listEntry->data);
        }
        list_freeList(v1alpha1_server_storage_version->served_versions);
        v1alpha1_server_storage_version->served_versions = NULL;
    }
    free(v1alpha1_server_storage_version);
}

cJSON *v1alpha1_server_storage_version_convertToJSON(v1alpha1_server_storage_version_t *v1alpha1_server_storage_version) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_server_storage_version->api_server_id
    if(v1alpha1_server_storage_version->api_server_id) {
    if(cJSON_AddStringToObject(item, "apiServerID", v1alpha1_server_storage_version->api_server_id) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_server_storage_version->decodable_versions
    if(v1alpha1_server_storage_version->decodable_versions) {
    cJSON *decodable_versions = cJSON_AddArrayToObject(item, "decodableVersions");
    if(decodable_versions == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *decodable_versionsListEntry;
    list_ForEach(decodable_versionsListEntry, v1alpha1_server_storage_version->decodable_versions) {
    if(cJSON_AddStringToObject(decodable_versions, "", (char*)decodable_versionsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1alpha1_server_storage_version->encoding_version
    if(v1alpha1_server_storage_version->encoding_version) {
    if(cJSON_AddStringToObject(item, "encodingVersion", v1alpha1_server_storage_version->encoding_version) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_server_storage_version->served_versions
    if(v1alpha1_server_storage_version->served_versions) {
    cJSON *served_versions = cJSON_AddArrayToObject(item, "servedVersions");
    if(served_versions == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *served_versionsListEntry;
    list_ForEach(served_versionsListEntry, v1alpha1_server_storage_version->served_versions) {
    if(cJSON_AddStringToObject(served_versions, "", (char*)served_versionsListEntry->data) == NULL)
    {
        goto fail;
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

v1alpha1_server_storage_version_t *v1alpha1_server_storage_version_parseFromJSON(cJSON *v1alpha1_server_storage_versionJSON){

    v1alpha1_server_storage_version_t *v1alpha1_server_storage_version_local_var = NULL;

    // define the local list for v1alpha1_server_storage_version->decodable_versions
    list_t *decodable_versionsList = NULL;

    // define the local list for v1alpha1_server_storage_version->served_versions
    list_t *served_versionsList = NULL;

    // v1alpha1_server_storage_version->api_server_id
    cJSON *api_server_id = cJSON_GetObjectItemCaseSensitive(v1alpha1_server_storage_versionJSON, "apiServerID");
    if (api_server_id) { 
    if(!cJSON_IsString(api_server_id) && !cJSON_IsNull(api_server_id))
    {
    goto end; //String
    }
    }

    // v1alpha1_server_storage_version->decodable_versions
    cJSON *decodable_versions = cJSON_GetObjectItemCaseSensitive(v1alpha1_server_storage_versionJSON, "decodableVersions");
    if (decodable_versions) { 
    cJSON *decodable_versions_local = NULL;
    if(!cJSON_IsArray(decodable_versions)) {
        goto end;//primitive container
    }
    decodable_versionsList = list_createList();

    cJSON_ArrayForEach(decodable_versions_local, decodable_versions)
    {
        if(!cJSON_IsString(decodable_versions_local))
        {
            goto end;
        }
        list_addElement(decodable_versionsList , strdup(decodable_versions_local->valuestring));
    }
    }

    // v1alpha1_server_storage_version->encoding_version
    cJSON *encoding_version = cJSON_GetObjectItemCaseSensitive(v1alpha1_server_storage_versionJSON, "encodingVersion");
    if (encoding_version) { 
    if(!cJSON_IsString(encoding_version) && !cJSON_IsNull(encoding_version))
    {
    goto end; //String
    }
    }

    // v1alpha1_server_storage_version->served_versions
    cJSON *served_versions = cJSON_GetObjectItemCaseSensitive(v1alpha1_server_storage_versionJSON, "servedVersions");
    if (served_versions) { 
    cJSON *served_versions_local = NULL;
    if(!cJSON_IsArray(served_versions)) {
        goto end;//primitive container
    }
    served_versionsList = list_createList();

    cJSON_ArrayForEach(served_versions_local, served_versions)
    {
        if(!cJSON_IsString(served_versions_local))
        {
            goto end;
        }
        list_addElement(served_versionsList , strdup(served_versions_local->valuestring));
    }
    }


    v1alpha1_server_storage_version_local_var = v1alpha1_server_storage_version_create (
        api_server_id && !cJSON_IsNull(api_server_id) ? strdup(api_server_id->valuestring) : NULL,
        decodable_versions ? decodable_versionsList : NULL,
        encoding_version && !cJSON_IsNull(encoding_version) ? strdup(encoding_version->valuestring) : NULL,
        served_versions ? served_versionsList : NULL
        );

    return v1alpha1_server_storage_version_local_var;
end:
    if (decodable_versionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, decodable_versionsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(decodable_versionsList);
        decodable_versionsList = NULL;
    }
    if (served_versionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, served_versionsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(served_versionsList);
        served_versionsList = NULL;
    }
    return NULL;

}
