#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_resource_claim_template.h"



v1alpha3_resource_claim_template_t *v1alpha3_resource_claim_template_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha3_resource_claim_template_spec_t *spec
    ) {
    v1alpha3_resource_claim_template_t *v1alpha3_resource_claim_template_local_var = malloc(sizeof(v1alpha3_resource_claim_template_t));
    if (!v1alpha3_resource_claim_template_local_var) {
        return NULL;
    }
    v1alpha3_resource_claim_template_local_var->api_version = api_version;
    v1alpha3_resource_claim_template_local_var->kind = kind;
    v1alpha3_resource_claim_template_local_var->metadata = metadata;
    v1alpha3_resource_claim_template_local_var->spec = spec;

    return v1alpha3_resource_claim_template_local_var;
}


void v1alpha3_resource_claim_template_free(v1alpha3_resource_claim_template_t *v1alpha3_resource_claim_template) {
    if(NULL == v1alpha3_resource_claim_template){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_resource_claim_template->api_version) {
        free(v1alpha3_resource_claim_template->api_version);
        v1alpha3_resource_claim_template->api_version = NULL;
    }
    if (v1alpha3_resource_claim_template->kind) {
        free(v1alpha3_resource_claim_template->kind);
        v1alpha3_resource_claim_template->kind = NULL;
    }
    if (v1alpha3_resource_claim_template->metadata) {
        v1_object_meta_free(v1alpha3_resource_claim_template->metadata);
        v1alpha3_resource_claim_template->metadata = NULL;
    }
    if (v1alpha3_resource_claim_template->spec) {
        v1alpha3_resource_claim_template_spec_free(v1alpha3_resource_claim_template->spec);
        v1alpha3_resource_claim_template->spec = NULL;
    }
    free(v1alpha3_resource_claim_template);
}

cJSON *v1alpha3_resource_claim_template_convertToJSON(v1alpha3_resource_claim_template_t *v1alpha3_resource_claim_template) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_resource_claim_template->api_version
    if(v1alpha3_resource_claim_template->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1alpha3_resource_claim_template->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_resource_claim_template->kind
    if(v1alpha3_resource_claim_template->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1alpha3_resource_claim_template->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_resource_claim_template->metadata
    if(v1alpha3_resource_claim_template->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1alpha3_resource_claim_template->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha3_resource_claim_template->spec
    if (!v1alpha3_resource_claim_template->spec) {
        goto fail;
    }
    cJSON *spec_local_JSON = v1alpha3_resource_claim_template_spec_convertToJSON(v1alpha3_resource_claim_template->spec);
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

v1alpha3_resource_claim_template_t *v1alpha3_resource_claim_template_parseFromJSON(cJSON *v1alpha3_resource_claim_templateJSON){

    v1alpha3_resource_claim_template_t *v1alpha3_resource_claim_template_local_var = NULL;

    // define the local variable for v1alpha3_resource_claim_template->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1alpha3_resource_claim_template->spec
    v1alpha3_resource_claim_template_spec_t *spec_local_nonprim = NULL;

    // v1alpha3_resource_claim_template->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_claim_templateJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1alpha3_resource_claim_template->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_claim_templateJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1alpha3_resource_claim_template->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_claim_templateJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1alpha3_resource_claim_template->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_claim_templateJSON, "spec");
    if (!spec) {
        goto end;
    }

    
    spec_local_nonprim = v1alpha3_resource_claim_template_spec_parseFromJSON(spec); //nonprimitive


    v1alpha3_resource_claim_template_local_var = v1alpha3_resource_claim_template_create (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec_local_nonprim
        );

    return v1alpha3_resource_claim_template_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1alpha3_resource_claim_template_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    return NULL;

}
