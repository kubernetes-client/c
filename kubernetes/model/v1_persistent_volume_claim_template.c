#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_persistent_volume_claim_template.h"



v1_persistent_volume_claim_template_t *v1_persistent_volume_claim_template_create(
    v1_object_meta_t *metadata,
    v1_persistent_volume_claim_spec_t *spec
    ) {
    v1_persistent_volume_claim_template_t *v1_persistent_volume_claim_template_local_var = malloc(sizeof(v1_persistent_volume_claim_template_t));
    if (!v1_persistent_volume_claim_template_local_var) {
        return NULL;
    }
    v1_persistent_volume_claim_template_local_var->metadata = metadata;
    v1_persistent_volume_claim_template_local_var->spec = spec;

    return v1_persistent_volume_claim_template_local_var;
}


void v1_persistent_volume_claim_template_free(v1_persistent_volume_claim_template_t *v1_persistent_volume_claim_template) {
    if(NULL == v1_persistent_volume_claim_template){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_persistent_volume_claim_template->metadata) {
        v1_object_meta_free(v1_persistent_volume_claim_template->metadata);
        v1_persistent_volume_claim_template->metadata = NULL;
    }
    if (v1_persistent_volume_claim_template->spec) {
        v1_persistent_volume_claim_spec_free(v1_persistent_volume_claim_template->spec);
        v1_persistent_volume_claim_template->spec = NULL;
    }
    free(v1_persistent_volume_claim_template);
}

cJSON *v1_persistent_volume_claim_template_convertToJSON(v1_persistent_volume_claim_template_t *v1_persistent_volume_claim_template) {
    cJSON *item = cJSON_CreateObject();

    // v1_persistent_volume_claim_template->metadata
    if(v1_persistent_volume_claim_template->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_persistent_volume_claim_template->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_claim_template->spec
    if (!v1_persistent_volume_claim_template->spec) {
        goto fail;
    }
    cJSON *spec_local_JSON = v1_persistent_volume_claim_spec_convertToJSON(v1_persistent_volume_claim_template->spec);
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

v1_persistent_volume_claim_template_t *v1_persistent_volume_claim_template_parseFromJSON(cJSON *v1_persistent_volume_claim_templateJSON){

    v1_persistent_volume_claim_template_t *v1_persistent_volume_claim_template_local_var = NULL;

    // define the local variable for v1_persistent_volume_claim_template->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_claim_template->spec
    v1_persistent_volume_claim_spec_t *spec_local_nonprim = NULL;

    // v1_persistent_volume_claim_template->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_claim_templateJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_persistent_volume_claim_template->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_claim_templateJSON, "spec");
    if (!spec) {
        goto end;
    }

    
    spec_local_nonprim = v1_persistent_volume_claim_spec_parseFromJSON(spec); //nonprimitive


    v1_persistent_volume_claim_template_local_var = v1_persistent_volume_claim_template_create (
        metadata ? metadata_local_nonprim : NULL,
        spec_local_nonprim
        );

    return v1_persistent_volume_claim_template_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1_persistent_volume_claim_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    return NULL;

}
