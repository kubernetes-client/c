#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_resource_claim_template_spec.h"



static v1alpha3_resource_claim_template_spec_t *v1alpha3_resource_claim_template_spec_create_internal(
    v1_object_meta_t *metadata,
    v1alpha3_resource_claim_spec_t *spec
    ) {
    v1alpha3_resource_claim_template_spec_t *v1alpha3_resource_claim_template_spec_local_var = malloc(sizeof(v1alpha3_resource_claim_template_spec_t));
    if (!v1alpha3_resource_claim_template_spec_local_var) {
        return NULL;
    }
    v1alpha3_resource_claim_template_spec_local_var->metadata = metadata;
    v1alpha3_resource_claim_template_spec_local_var->spec = spec;

    v1alpha3_resource_claim_template_spec_local_var->_library_owned = 1;
    return v1alpha3_resource_claim_template_spec_local_var;
}

__attribute__((deprecated)) v1alpha3_resource_claim_template_spec_t *v1alpha3_resource_claim_template_spec_create(
    v1_object_meta_t *metadata,
    v1alpha3_resource_claim_spec_t *spec
    ) {
    return v1alpha3_resource_claim_template_spec_create_internal (
        metadata,
        spec
        );
}

void v1alpha3_resource_claim_template_spec_free(v1alpha3_resource_claim_template_spec_t *v1alpha3_resource_claim_template_spec) {
    if(NULL == v1alpha3_resource_claim_template_spec){
        return ;
    }
    if(v1alpha3_resource_claim_template_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha3_resource_claim_template_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_resource_claim_template_spec->metadata) {
        v1_object_meta_free(v1alpha3_resource_claim_template_spec->metadata);
        v1alpha3_resource_claim_template_spec->metadata = NULL;
    }
    if (v1alpha3_resource_claim_template_spec->spec) {
        v1alpha3_resource_claim_spec_free(v1alpha3_resource_claim_template_spec->spec);
        v1alpha3_resource_claim_template_spec->spec = NULL;
    }
    free(v1alpha3_resource_claim_template_spec);
}

cJSON *v1alpha3_resource_claim_template_spec_convertToJSON(v1alpha3_resource_claim_template_spec_t *v1alpha3_resource_claim_template_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_resource_claim_template_spec->metadata
    if(v1alpha3_resource_claim_template_spec->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1alpha3_resource_claim_template_spec->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha3_resource_claim_template_spec->spec
    if (!v1alpha3_resource_claim_template_spec->spec) {
        goto fail;
    }
    cJSON *spec_local_JSON = v1alpha3_resource_claim_spec_convertToJSON(v1alpha3_resource_claim_template_spec->spec);
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

v1alpha3_resource_claim_template_spec_t *v1alpha3_resource_claim_template_spec_parseFromJSON(cJSON *v1alpha3_resource_claim_template_specJSON){

    v1alpha3_resource_claim_template_spec_t *v1alpha3_resource_claim_template_spec_local_var = NULL;

    // define the local variable for v1alpha3_resource_claim_template_spec->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1alpha3_resource_claim_template_spec->spec
    v1alpha3_resource_claim_spec_t *spec_local_nonprim = NULL;

    // v1alpha3_resource_claim_template_spec->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_claim_template_specJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1alpha3_resource_claim_template_spec->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_claim_template_specJSON, "spec");
    if (cJSON_IsNull(spec)) {
        spec = NULL;
    }
    if (!spec) {
        goto end;
    }

    
    spec_local_nonprim = v1alpha3_resource_claim_spec_parseFromJSON(spec); //nonprimitive


    v1alpha3_resource_claim_template_spec_local_var = v1alpha3_resource_claim_template_spec_create_internal (
        metadata ? metadata_local_nonprim : NULL,
        spec_local_nonprim
        );

    return v1alpha3_resource_claim_template_spec_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1alpha3_resource_claim_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    return NULL;

}
