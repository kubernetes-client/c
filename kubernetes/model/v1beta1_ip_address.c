#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_ip_address.h"



static v1beta1_ip_address_t *v1beta1_ip_address_create_internal(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta1_ip_address_spec_t *spec
    ) {
    v1beta1_ip_address_t *v1beta1_ip_address_local_var = malloc(sizeof(v1beta1_ip_address_t));
    if (!v1beta1_ip_address_local_var) {
        return NULL;
    }
    v1beta1_ip_address_local_var->api_version = api_version;
    v1beta1_ip_address_local_var->kind = kind;
    v1beta1_ip_address_local_var->metadata = metadata;
    v1beta1_ip_address_local_var->spec = spec;

    v1beta1_ip_address_local_var->_library_owned = 1;
    return v1beta1_ip_address_local_var;
}

__attribute__((deprecated)) v1beta1_ip_address_t *v1beta1_ip_address_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta1_ip_address_spec_t *spec
    ) {
    return v1beta1_ip_address_create_internal (
        api_version,
        kind,
        metadata,
        spec
        );
}

void v1beta1_ip_address_free(v1beta1_ip_address_t *v1beta1_ip_address) {
    if(NULL == v1beta1_ip_address){
        return ;
    }
    if(v1beta1_ip_address->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta1_ip_address_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_ip_address->api_version) {
        free(v1beta1_ip_address->api_version);
        v1beta1_ip_address->api_version = NULL;
    }
    if (v1beta1_ip_address->kind) {
        free(v1beta1_ip_address->kind);
        v1beta1_ip_address->kind = NULL;
    }
    if (v1beta1_ip_address->metadata) {
        v1_object_meta_free(v1beta1_ip_address->metadata);
        v1beta1_ip_address->metadata = NULL;
    }
    if (v1beta1_ip_address->spec) {
        v1beta1_ip_address_spec_free(v1beta1_ip_address->spec);
        v1beta1_ip_address->spec = NULL;
    }
    free(v1beta1_ip_address);
}

cJSON *v1beta1_ip_address_convertToJSON(v1beta1_ip_address_t *v1beta1_ip_address) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_ip_address->api_version
    if(v1beta1_ip_address->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1beta1_ip_address->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1beta1_ip_address->kind
    if(v1beta1_ip_address->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1beta1_ip_address->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1beta1_ip_address->metadata
    if(v1beta1_ip_address->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1beta1_ip_address->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta1_ip_address->spec
    if(v1beta1_ip_address->spec) {
    cJSON *spec_local_JSON = v1beta1_ip_address_spec_convertToJSON(v1beta1_ip_address->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
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

v1beta1_ip_address_t *v1beta1_ip_address_parseFromJSON(cJSON *v1beta1_ip_addressJSON){

    v1beta1_ip_address_t *v1beta1_ip_address_local_var = NULL;

    // define the local variable for v1beta1_ip_address->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1beta1_ip_address->spec
    v1beta1_ip_address_spec_t *spec_local_nonprim = NULL;

    // v1beta1_ip_address->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1beta1_ip_addressJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1beta1_ip_address->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1beta1_ip_addressJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1beta1_ip_address->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1beta1_ip_addressJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1beta1_ip_address->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1beta1_ip_addressJSON, "spec");
    if (cJSON_IsNull(spec)) {
        spec = NULL;
    }
    if (spec) { 
    spec_local_nonprim = v1beta1_ip_address_spec_parseFromJSON(spec); //nonprimitive
    }


    v1beta1_ip_address_local_var = v1beta1_ip_address_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL
        );

    return v1beta1_ip_address_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1beta1_ip_address_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    return NULL;

}
