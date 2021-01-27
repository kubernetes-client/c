#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_ingress.h"



extensions_v1beta1_ingress_t *extensions_v1beta1_ingress_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    extensions_v1beta1_ingress_spec_t *spec,
    extensions_v1beta1_ingress_status_t *status
    ) {
    extensions_v1beta1_ingress_t *extensions_v1beta1_ingress_local_var = malloc(sizeof(extensions_v1beta1_ingress_t));
    if (!extensions_v1beta1_ingress_local_var) {
        return NULL;
    }
    extensions_v1beta1_ingress_local_var->api_version = api_version;
    extensions_v1beta1_ingress_local_var->kind = kind;
    extensions_v1beta1_ingress_local_var->metadata = metadata;
    extensions_v1beta1_ingress_local_var->spec = spec;
    extensions_v1beta1_ingress_local_var->status = status;

    return extensions_v1beta1_ingress_local_var;
}


void extensions_v1beta1_ingress_free(extensions_v1beta1_ingress_t *extensions_v1beta1_ingress) {
    if(NULL == extensions_v1beta1_ingress){
        return ;
    }
    listEntry_t *listEntry;
    if (extensions_v1beta1_ingress->api_version) {
        free(extensions_v1beta1_ingress->api_version);
        extensions_v1beta1_ingress->api_version = NULL;
    }
    if (extensions_v1beta1_ingress->kind) {
        free(extensions_v1beta1_ingress->kind);
        extensions_v1beta1_ingress->kind = NULL;
    }
    if (extensions_v1beta1_ingress->metadata) {
        v1_object_meta_free(extensions_v1beta1_ingress->metadata);
        extensions_v1beta1_ingress->metadata = NULL;
    }
    if (extensions_v1beta1_ingress->spec) {
        extensions_v1beta1_ingress_spec_free(extensions_v1beta1_ingress->spec);
        extensions_v1beta1_ingress->spec = NULL;
    }
    if (extensions_v1beta1_ingress->status) {
        extensions_v1beta1_ingress_status_free(extensions_v1beta1_ingress->status);
        extensions_v1beta1_ingress->status = NULL;
    }
    free(extensions_v1beta1_ingress);
}

cJSON *extensions_v1beta1_ingress_convertToJSON(extensions_v1beta1_ingress_t *extensions_v1beta1_ingress) {
    cJSON *item = cJSON_CreateObject();

    // extensions_v1beta1_ingress->api_version
    if(extensions_v1beta1_ingress->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", extensions_v1beta1_ingress->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // extensions_v1beta1_ingress->kind
    if(extensions_v1beta1_ingress->kind) { 
    if(cJSON_AddStringToObject(item, "kind", extensions_v1beta1_ingress->kind) == NULL) {
    goto fail; //String
    }
     } 


    // extensions_v1beta1_ingress->metadata
    if(extensions_v1beta1_ingress->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(extensions_v1beta1_ingress->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // extensions_v1beta1_ingress->spec
    if(extensions_v1beta1_ingress->spec) { 
    cJSON *spec_local_JSON = extensions_v1beta1_ingress_spec_convertToJSON(extensions_v1beta1_ingress->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // extensions_v1beta1_ingress->status
    if(extensions_v1beta1_ingress->status) { 
    cJSON *status_local_JSON = extensions_v1beta1_ingress_status_convertToJSON(extensions_v1beta1_ingress->status);
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

extensions_v1beta1_ingress_t *extensions_v1beta1_ingress_parseFromJSON(cJSON *extensions_v1beta1_ingressJSON){

    extensions_v1beta1_ingress_t *extensions_v1beta1_ingress_local_var = NULL;

    // extensions_v1beta1_ingress->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_ingressJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // extensions_v1beta1_ingress->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_ingressJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // extensions_v1beta1_ingress->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_ingressJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // extensions_v1beta1_ingress->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_ingressJSON, "spec");
    extensions_v1beta1_ingress_spec_t *spec_local_nonprim = NULL;
    if (spec) { 
    spec_local_nonprim = extensions_v1beta1_ingress_spec_parseFromJSON(spec); //nonprimitive
    }

    // extensions_v1beta1_ingress->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_ingressJSON, "status");
    extensions_v1beta1_ingress_status_t *status_local_nonprim = NULL;
    if (status) { 
    status_local_nonprim = extensions_v1beta1_ingress_status_parseFromJSON(status); //nonprimitive
    }


    extensions_v1beta1_ingress_local_var = extensions_v1beta1_ingress_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return extensions_v1beta1_ingress_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        extensions_v1beta1_ingress_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        extensions_v1beta1_ingress_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
