#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_lease.h"



v1_lease_t *v1_lease_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_lease_spec_t *spec
    ) {
    v1_lease_t *v1_lease_local_var = malloc(sizeof(v1_lease_t));
    if (!v1_lease_local_var) {
        return NULL;
    }
    v1_lease_local_var->api_version = api_version;
    v1_lease_local_var->kind = kind;
    v1_lease_local_var->metadata = metadata;
    v1_lease_local_var->spec = spec;

    return v1_lease_local_var;
}


void v1_lease_free(v1_lease_t *v1_lease) {
    if(NULL == v1_lease){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_lease->api_version) {
        free(v1_lease->api_version);
        v1_lease->api_version = NULL;
    }
    if (v1_lease->kind) {
        free(v1_lease->kind);
        v1_lease->kind = NULL;
    }
    if (v1_lease->metadata) {
        v1_object_meta_free(v1_lease->metadata);
        v1_lease->metadata = NULL;
    }
    if (v1_lease->spec) {
        v1_lease_spec_free(v1_lease->spec);
        v1_lease->spec = NULL;
    }
    free(v1_lease);
}

cJSON *v1_lease_convertToJSON(v1_lease_t *v1_lease) {
    cJSON *item = cJSON_CreateObject();

    // v1_lease->api_version
    if(v1_lease->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_lease->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // v1_lease->kind
    if(v1_lease->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_lease->kind) == NULL) {
    goto fail; //String
    }
     } 


    // v1_lease->metadata
    if(v1_lease->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_lease->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_lease->spec
    if(v1_lease->spec) { 
    cJSON *spec_local_JSON = v1_lease_spec_convertToJSON(v1_lease->spec);
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

v1_lease_t *v1_lease_parseFromJSON(cJSON *v1_leaseJSON){

    v1_lease_t *v1_lease_local_var = NULL;

    // v1_lease->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_leaseJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v1_lease->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_leaseJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_lease->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_leaseJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_lease->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1_leaseJSON, "spec");
    v1_lease_spec_t *spec_local_nonprim = NULL;
    if (spec) { 
    spec_local_nonprim = v1_lease_spec_parseFromJSON(spec); //nonprimitive
    }


    v1_lease_local_var = v1_lease_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL
        );

    return v1_lease_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1_lease_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    return NULL;

}
