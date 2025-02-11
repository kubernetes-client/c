#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_csi_driver.h"



static v1_csi_driver_t *v1_csi_driver_create_internal(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_csi_driver_spec_t *spec
    ) {
    v1_csi_driver_t *v1_csi_driver_local_var = malloc(sizeof(v1_csi_driver_t));
    if (!v1_csi_driver_local_var) {
        return NULL;
    }
    v1_csi_driver_local_var->api_version = api_version;
    v1_csi_driver_local_var->kind = kind;
    v1_csi_driver_local_var->metadata = metadata;
    v1_csi_driver_local_var->spec = spec;

    v1_csi_driver_local_var->_library_owned = 1;
    return v1_csi_driver_local_var;
}

__attribute__((deprecated)) v1_csi_driver_t *v1_csi_driver_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_csi_driver_spec_t *spec
    ) {
    return v1_csi_driver_create_internal (
        api_version,
        kind,
        metadata,
        spec
        );
}

void v1_csi_driver_free(v1_csi_driver_t *v1_csi_driver) {
    if(NULL == v1_csi_driver){
        return ;
    }
    if(v1_csi_driver->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_csi_driver_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_csi_driver->api_version) {
        free(v1_csi_driver->api_version);
        v1_csi_driver->api_version = NULL;
    }
    if (v1_csi_driver->kind) {
        free(v1_csi_driver->kind);
        v1_csi_driver->kind = NULL;
    }
    if (v1_csi_driver->metadata) {
        v1_object_meta_free(v1_csi_driver->metadata);
        v1_csi_driver->metadata = NULL;
    }
    if (v1_csi_driver->spec) {
        v1_csi_driver_spec_free(v1_csi_driver->spec);
        v1_csi_driver->spec = NULL;
    }
    free(v1_csi_driver);
}

cJSON *v1_csi_driver_convertToJSON(v1_csi_driver_t *v1_csi_driver) {
    cJSON *item = cJSON_CreateObject();

    // v1_csi_driver->api_version
    if(v1_csi_driver->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_csi_driver->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_csi_driver->kind
    if(v1_csi_driver->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_csi_driver->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_csi_driver->metadata
    if(v1_csi_driver->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_csi_driver->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_csi_driver->spec
    if (!v1_csi_driver->spec) {
        goto fail;
    }
    cJSON *spec_local_JSON = v1_csi_driver_spec_convertToJSON(v1_csi_driver->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_csi_driver_t *v1_csi_driver_parseFromJSON(cJSON *v1_csi_driverJSON){

    v1_csi_driver_t *v1_csi_driver_local_var = NULL;

    // define the local variable for v1_csi_driver->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1_csi_driver->spec
    v1_csi_driver_spec_t *spec_local_nonprim = NULL;

    // v1_csi_driver->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_csi_driverJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_csi_driver->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_csi_driverJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_csi_driver->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_csi_driverJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_csi_driver->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1_csi_driverJSON, "spec");
    if (cJSON_IsNull(spec)) {
        spec = NULL;
    }
    if (!spec) {
        goto end;
    }

    
    spec_local_nonprim = v1_csi_driver_spec_parseFromJSON(spec); //nonprimitive


    v1_csi_driver_local_var = v1_csi_driver_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec_local_nonprim
        );

    return v1_csi_driver_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1_csi_driver_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    return NULL;

}
