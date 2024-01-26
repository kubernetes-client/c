#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_service_cidr.h"



v1alpha1_service_cidr_t *v1alpha1_service_cidr_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha1_service_cidr_spec_t *spec,
    v1alpha1_service_cidr_status_t *status
    ) {
    v1alpha1_service_cidr_t *v1alpha1_service_cidr_local_var = malloc(sizeof(v1alpha1_service_cidr_t));
    if (!v1alpha1_service_cidr_local_var) {
        return NULL;
    }
    v1alpha1_service_cidr_local_var->api_version = api_version;
    v1alpha1_service_cidr_local_var->kind = kind;
    v1alpha1_service_cidr_local_var->metadata = metadata;
    v1alpha1_service_cidr_local_var->spec = spec;
    v1alpha1_service_cidr_local_var->status = status;

    return v1alpha1_service_cidr_local_var;
}


void v1alpha1_service_cidr_free(v1alpha1_service_cidr_t *v1alpha1_service_cidr) {
    if(NULL == v1alpha1_service_cidr){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_service_cidr->api_version) {
        free(v1alpha1_service_cidr->api_version);
        v1alpha1_service_cidr->api_version = NULL;
    }
    if (v1alpha1_service_cidr->kind) {
        free(v1alpha1_service_cidr->kind);
        v1alpha1_service_cidr->kind = NULL;
    }
    if (v1alpha1_service_cidr->metadata) {
        v1_object_meta_free(v1alpha1_service_cidr->metadata);
        v1alpha1_service_cidr->metadata = NULL;
    }
    if (v1alpha1_service_cidr->spec) {
        v1alpha1_service_cidr_spec_free(v1alpha1_service_cidr->spec);
        v1alpha1_service_cidr->spec = NULL;
    }
    if (v1alpha1_service_cidr->status) {
        v1alpha1_service_cidr_status_free(v1alpha1_service_cidr->status);
        v1alpha1_service_cidr->status = NULL;
    }
    free(v1alpha1_service_cidr);
}

cJSON *v1alpha1_service_cidr_convertToJSON(v1alpha1_service_cidr_t *v1alpha1_service_cidr) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_service_cidr->api_version
    if(v1alpha1_service_cidr->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1alpha1_service_cidr->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_service_cidr->kind
    if(v1alpha1_service_cidr->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1alpha1_service_cidr->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_service_cidr->metadata
    if(v1alpha1_service_cidr->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1alpha1_service_cidr->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha1_service_cidr->spec
    if(v1alpha1_service_cidr->spec) {
    cJSON *spec_local_JSON = v1alpha1_service_cidr_spec_convertToJSON(v1alpha1_service_cidr->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha1_service_cidr->status
    if(v1alpha1_service_cidr->status) {
    cJSON *status_local_JSON = v1alpha1_service_cidr_status_convertToJSON(v1alpha1_service_cidr->status);
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

v1alpha1_service_cidr_t *v1alpha1_service_cidr_parseFromJSON(cJSON *v1alpha1_service_cidrJSON){

    v1alpha1_service_cidr_t *v1alpha1_service_cidr_local_var = NULL;

    // define the local variable for v1alpha1_service_cidr->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1alpha1_service_cidr->spec
    v1alpha1_service_cidr_spec_t *spec_local_nonprim = NULL;

    // define the local variable for v1alpha1_service_cidr->status
    v1alpha1_service_cidr_status_t *status_local_nonprim = NULL;

    // v1alpha1_service_cidr->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1alpha1_service_cidrJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1alpha1_service_cidr->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha1_service_cidrJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1alpha1_service_cidr->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1alpha1_service_cidrJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1alpha1_service_cidr->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1alpha1_service_cidrJSON, "spec");
    if (spec) { 
    spec_local_nonprim = v1alpha1_service_cidr_spec_parseFromJSON(spec); //nonprimitive
    }

    // v1alpha1_service_cidr->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1alpha1_service_cidrJSON, "status");
    if (status) { 
    status_local_nonprim = v1alpha1_service_cidr_status_parseFromJSON(status); //nonprimitive
    }


    v1alpha1_service_cidr_local_var = v1alpha1_service_cidr_create (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return v1alpha1_service_cidr_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1alpha1_service_cidr_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        v1alpha1_service_cidr_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
