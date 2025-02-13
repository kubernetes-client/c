#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_api_versions.h"



static v1_api_versions_t *v1_api_versions_create_internal(
    char *api_version,
    char *kind,
    list_t *server_address_by_client_cidrs,
    list_t *versions
    ) {
    v1_api_versions_t *v1_api_versions_local_var = malloc(sizeof(v1_api_versions_t));
    if (!v1_api_versions_local_var) {
        return NULL;
    }
    v1_api_versions_local_var->api_version = api_version;
    v1_api_versions_local_var->kind = kind;
    v1_api_versions_local_var->server_address_by_client_cidrs = server_address_by_client_cidrs;
    v1_api_versions_local_var->versions = versions;

    v1_api_versions_local_var->_library_owned = 1;
    return v1_api_versions_local_var;
}

__attribute__((deprecated)) v1_api_versions_t *v1_api_versions_create(
    char *api_version,
    char *kind,
    list_t *server_address_by_client_cidrs,
    list_t *versions
    ) {
    return v1_api_versions_create_internal (
        api_version,
        kind,
        server_address_by_client_cidrs,
        versions
        );
}

void v1_api_versions_free(v1_api_versions_t *v1_api_versions) {
    if(NULL == v1_api_versions){
        return ;
    }
    if(v1_api_versions->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_api_versions_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_api_versions->api_version) {
        free(v1_api_versions->api_version);
        v1_api_versions->api_version = NULL;
    }
    if (v1_api_versions->kind) {
        free(v1_api_versions->kind);
        v1_api_versions->kind = NULL;
    }
    if (v1_api_versions->server_address_by_client_cidrs) {
        list_ForEach(listEntry, v1_api_versions->server_address_by_client_cidrs) {
            v1_server_address_by_client_cidr_free(listEntry->data);
        }
        list_freeList(v1_api_versions->server_address_by_client_cidrs);
        v1_api_versions->server_address_by_client_cidrs = NULL;
    }
    if (v1_api_versions->versions) {
        list_ForEach(listEntry, v1_api_versions->versions) {
            free(listEntry->data);
        }
        list_freeList(v1_api_versions->versions);
        v1_api_versions->versions = NULL;
    }
    free(v1_api_versions);
}

cJSON *v1_api_versions_convertToJSON(v1_api_versions_t *v1_api_versions) {
    cJSON *item = cJSON_CreateObject();

    // v1_api_versions->api_version
    if(v1_api_versions->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_api_versions->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_api_versions->kind
    if(v1_api_versions->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_api_versions->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_api_versions->server_address_by_client_cidrs
    if (!v1_api_versions->server_address_by_client_cidrs) {
        goto fail;
    }
    cJSON *server_address_by_client_cidrs = cJSON_AddArrayToObject(item, "serverAddressByClientCIDRs");
    if(server_address_by_client_cidrs == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *server_address_by_client_cidrsListEntry;
    if (v1_api_versions->server_address_by_client_cidrs) {
    list_ForEach(server_address_by_client_cidrsListEntry, v1_api_versions->server_address_by_client_cidrs) {
    cJSON *itemLocal = v1_server_address_by_client_cidr_convertToJSON(server_address_by_client_cidrsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(server_address_by_client_cidrs, itemLocal);
    }
    }


    // v1_api_versions->versions
    if (!v1_api_versions->versions) {
        goto fail;
    }
    cJSON *versions = cJSON_AddArrayToObject(item, "versions");
    if(versions == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *versionsListEntry;
    list_ForEach(versionsListEntry, v1_api_versions->versions) {
    if(cJSON_AddStringToObject(versions, "", versionsListEntry->data) == NULL)
    {
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

v1_api_versions_t *v1_api_versions_parseFromJSON(cJSON *v1_api_versionsJSON){

    v1_api_versions_t *v1_api_versions_local_var = NULL;

    // define the local list for v1_api_versions->server_address_by_client_cidrs
    list_t *server_address_by_client_cidrsList = NULL;

    // define the local list for v1_api_versions->versions
    list_t *versionsList = NULL;

    // v1_api_versions->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_api_versionsJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_api_versions->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_api_versionsJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_api_versions->server_address_by_client_cidrs
    cJSON *server_address_by_client_cidrs = cJSON_GetObjectItemCaseSensitive(v1_api_versionsJSON, "serverAddressByClientCIDRs");
    if (cJSON_IsNull(server_address_by_client_cidrs)) {
        server_address_by_client_cidrs = NULL;
    }
    if (!server_address_by_client_cidrs) {
        goto end;
    }

    
    cJSON *server_address_by_client_cidrs_local_nonprimitive = NULL;
    if(!cJSON_IsArray(server_address_by_client_cidrs)){
        goto end; //nonprimitive container
    }

    server_address_by_client_cidrsList = list_createList();

    cJSON_ArrayForEach(server_address_by_client_cidrs_local_nonprimitive,server_address_by_client_cidrs )
    {
        if(!cJSON_IsObject(server_address_by_client_cidrs_local_nonprimitive)){
            goto end;
        }
        v1_server_address_by_client_cidr_t *server_address_by_client_cidrsItem = v1_server_address_by_client_cidr_parseFromJSON(server_address_by_client_cidrs_local_nonprimitive);

        list_addElement(server_address_by_client_cidrsList, server_address_by_client_cidrsItem);
    }

    // v1_api_versions->versions
    cJSON *versions = cJSON_GetObjectItemCaseSensitive(v1_api_versionsJSON, "versions");
    if (cJSON_IsNull(versions)) {
        versions = NULL;
    }
    if (!versions) {
        goto end;
    }

    
    cJSON *versions_local = NULL;
    if(!cJSON_IsArray(versions)) {
        goto end;//primitive container
    }
    versionsList = list_createList();

    cJSON_ArrayForEach(versions_local, versions)
    {
        if(!cJSON_IsString(versions_local))
        {
            goto end;
        }
        list_addElement(versionsList , strdup(versions_local->valuestring));
    }


    v1_api_versions_local_var = v1_api_versions_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        server_address_by_client_cidrsList,
        versionsList
        );

    return v1_api_versions_local_var;
end:
    if (server_address_by_client_cidrsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, server_address_by_client_cidrsList) {
            v1_server_address_by_client_cidr_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(server_address_by_client_cidrsList);
        server_address_by_client_cidrsList = NULL;
    }
    if (versionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, versionsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(versionsList);
        versionsList = NULL;
    }
    return NULL;

}
