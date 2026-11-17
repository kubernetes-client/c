#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_storage_version_migration.h"



static v1_storage_version_migration_t *v1_storage_version_migration_create_internal(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_storage_version_migration_spec_t *spec,
    v1_storage_version_migration_status_t *status
    ) {
    v1_storage_version_migration_t *v1_storage_version_migration_local_var = malloc(sizeof(v1_storage_version_migration_t));
    if (!v1_storage_version_migration_local_var) {
        return NULL;
    }
    memset(v1_storage_version_migration_local_var, 0, sizeof(v1_storage_version_migration_t));
    v1_storage_version_migration_local_var->_library_owned = 1;
    v1_storage_version_migration_local_var->api_version = api_version;
    v1_storage_version_migration_local_var->kind = kind;
    v1_storage_version_migration_local_var->metadata = metadata;
    v1_storage_version_migration_local_var->spec = spec;
    v1_storage_version_migration_local_var->status = status;
    return v1_storage_version_migration_local_var;
}

__attribute__((deprecated)) v1_storage_version_migration_t *v1_storage_version_migration_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_storage_version_migration_spec_t *spec,
    v1_storage_version_migration_status_t *status
    ) {
    v1_storage_version_migration_t *result = v1_storage_version_migration_create_internal (
        api_version,
        kind,
        metadata,
        spec,
        status
        );
    if (!result) {
    }
    return result;
}

void v1_storage_version_migration_free(v1_storage_version_migration_t *v1_storage_version_migration) {
    if(NULL == v1_storage_version_migration){
        return ;
    }
    if(v1_storage_version_migration->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_storage_version_migration_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_storage_version_migration->api_version) {
        free(v1_storage_version_migration->api_version);
        v1_storage_version_migration->api_version = NULL;
    }
    if (v1_storage_version_migration->kind) {
        free(v1_storage_version_migration->kind);
        v1_storage_version_migration->kind = NULL;
    }
    if (v1_storage_version_migration->metadata) {
        v1_object_meta_free(v1_storage_version_migration->metadata);
        v1_storage_version_migration->metadata = NULL;
    }
    if (v1_storage_version_migration->spec) {
        v1_storage_version_migration_spec_free(v1_storage_version_migration->spec);
        v1_storage_version_migration->spec = NULL;
    }
    if (v1_storage_version_migration->status) {
        v1_storage_version_migration_status_free(v1_storage_version_migration->status);
        v1_storage_version_migration->status = NULL;
    }
    free(v1_storage_version_migration);
}

cJSON *v1_storage_version_migration_convertToJSON(v1_storage_version_migration_t *v1_storage_version_migration) {
    cJSON *item = cJSON_CreateObject();

    // v1_storage_version_migration->api_version
    if(v1_storage_version_migration->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_storage_version_migration->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_storage_version_migration->kind
    if(v1_storage_version_migration->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_storage_version_migration->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_storage_version_migration->metadata
    if(v1_storage_version_migration->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_storage_version_migration->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_storage_version_migration->spec
    if(v1_storage_version_migration->spec) {
    cJSON *spec_local_JSON = v1_storage_version_migration_spec_convertToJSON(v1_storage_version_migration->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_storage_version_migration->status
    if(v1_storage_version_migration->status) {
    cJSON *status_local_JSON = v1_storage_version_migration_status_convertToJSON(v1_storage_version_migration->status);
    if(status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
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

v1_storage_version_migration_t *v1_storage_version_migration_parseFromJSON(cJSON *v1_storage_version_migrationJSON){

    v1_storage_version_migration_t *v1_storage_version_migration_local_var = NULL;

    char *api_version_local_str = NULL;

    char *kind_local_str = NULL;

    // define the local variable for v1_storage_version_migration->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1_storage_version_migration->spec
    v1_storage_version_migration_spec_t *spec_local_nonprim = NULL;

    // define the local variable for v1_storage_version_migration->status
    v1_storage_version_migration_status_t *status_local_nonprim = NULL;

    // v1_storage_version_migration->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_storage_version_migrationJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_storage_version_migration->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_storage_version_migrationJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_storage_version_migration->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_storage_version_migrationJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_storage_version_migration->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1_storage_version_migrationJSON, "spec");
    if (cJSON_IsNull(spec)) {
        spec = NULL;
    }
    if (spec) { 
    spec_local_nonprim = v1_storage_version_migration_spec_parseFromJSON(spec); //nonprimitive
    }

    // v1_storage_version_migration->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_storage_version_migrationJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = v1_storage_version_migration_status_parseFromJSON(status); //nonprimitive
    }


    if (api_version && !cJSON_IsNull(api_version)) api_version_local_str = strdup(api_version->valuestring);
    if (kind && !cJSON_IsNull(kind)) kind_local_str = strdup(kind->valuestring);

    v1_storage_version_migration_local_var = v1_storage_version_migration_create_internal (
        api_version_local_str,
        kind_local_str,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    if (!v1_storage_version_migration_local_var) {
        goto end;
    }

    return v1_storage_version_migration_local_var;
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
    if (spec_local_nonprim) {
        v1_storage_version_migration_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        v1_storage_version_migration_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
