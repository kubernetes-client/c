#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_storage_version_migration.h"



v1alpha1_storage_version_migration_t *v1alpha1_storage_version_migration_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha1_storage_version_migration_spec_t *spec,
    v1alpha1_storage_version_migration_status_t *status
    ) {
    v1alpha1_storage_version_migration_t *v1alpha1_storage_version_migration_local_var = malloc(sizeof(v1alpha1_storage_version_migration_t));
    if (!v1alpha1_storage_version_migration_local_var) {
        return NULL;
    }
    v1alpha1_storage_version_migration_local_var->api_version = api_version;
    v1alpha1_storage_version_migration_local_var->kind = kind;
    v1alpha1_storage_version_migration_local_var->metadata = metadata;
    v1alpha1_storage_version_migration_local_var->spec = spec;
    v1alpha1_storage_version_migration_local_var->status = status;

    return v1alpha1_storage_version_migration_local_var;
}


void v1alpha1_storage_version_migration_free(v1alpha1_storage_version_migration_t *v1alpha1_storage_version_migration) {
    if(NULL == v1alpha1_storage_version_migration){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_storage_version_migration->api_version) {
        free(v1alpha1_storage_version_migration->api_version);
        v1alpha1_storage_version_migration->api_version = NULL;
    }
    if (v1alpha1_storage_version_migration->kind) {
        free(v1alpha1_storage_version_migration->kind);
        v1alpha1_storage_version_migration->kind = NULL;
    }
    if (v1alpha1_storage_version_migration->metadata) {
        v1_object_meta_free(v1alpha1_storage_version_migration->metadata);
        v1alpha1_storage_version_migration->metadata = NULL;
    }
    if (v1alpha1_storage_version_migration->spec) {
        v1alpha1_storage_version_migration_spec_free(v1alpha1_storage_version_migration->spec);
        v1alpha1_storage_version_migration->spec = NULL;
    }
    if (v1alpha1_storage_version_migration->status) {
        v1alpha1_storage_version_migration_status_free(v1alpha1_storage_version_migration->status);
        v1alpha1_storage_version_migration->status = NULL;
    }
    free(v1alpha1_storage_version_migration);
}

cJSON *v1alpha1_storage_version_migration_convertToJSON(v1alpha1_storage_version_migration_t *v1alpha1_storage_version_migration) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_storage_version_migration->api_version
    if(v1alpha1_storage_version_migration->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1alpha1_storage_version_migration->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_storage_version_migration->kind
    if(v1alpha1_storage_version_migration->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1alpha1_storage_version_migration->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_storage_version_migration->metadata
    if(v1alpha1_storage_version_migration->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1alpha1_storage_version_migration->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha1_storage_version_migration->spec
    if(v1alpha1_storage_version_migration->spec) {
    cJSON *spec_local_JSON = v1alpha1_storage_version_migration_spec_convertToJSON(v1alpha1_storage_version_migration->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha1_storage_version_migration->status
    if(v1alpha1_storage_version_migration->status) {
    cJSON *status_local_JSON = v1alpha1_storage_version_migration_status_convertToJSON(v1alpha1_storage_version_migration->status);
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

v1alpha1_storage_version_migration_t *v1alpha1_storage_version_migration_parseFromJSON(cJSON *v1alpha1_storage_version_migrationJSON){

    v1alpha1_storage_version_migration_t *v1alpha1_storage_version_migration_local_var = NULL;

    // define the local variable for v1alpha1_storage_version_migration->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1alpha1_storage_version_migration->spec
    v1alpha1_storage_version_migration_spec_t *spec_local_nonprim = NULL;

    // define the local variable for v1alpha1_storage_version_migration->status
    v1alpha1_storage_version_migration_status_t *status_local_nonprim = NULL;

    // v1alpha1_storage_version_migration->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1alpha1_storage_version_migrationJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1alpha1_storage_version_migration->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha1_storage_version_migrationJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1alpha1_storage_version_migration->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1alpha1_storage_version_migrationJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1alpha1_storage_version_migration->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1alpha1_storage_version_migrationJSON, "spec");
    if (spec) { 
    spec_local_nonprim = v1alpha1_storage_version_migration_spec_parseFromJSON(spec); //nonprimitive
    }

    // v1alpha1_storage_version_migration->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1alpha1_storage_version_migrationJSON, "status");
    if (status) { 
    status_local_nonprim = v1alpha1_storage_version_migration_status_parseFromJSON(status); //nonprimitive
    }


    v1alpha1_storage_version_migration_local_var = v1alpha1_storage_version_migration_create (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return v1alpha1_storage_version_migration_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1alpha1_storage_version_migration_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        v1alpha1_storage_version_migration_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
