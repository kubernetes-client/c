#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_template_spec.h"



v1_pod_template_spec_t *v1_pod_template_spec_create(
    v1_object_meta_t *metadata,
    v1_pod_spec_t *spec
    ) {
    v1_pod_template_spec_t *v1_pod_template_spec_local_var = malloc(sizeof(v1_pod_template_spec_t));
    if (!v1_pod_template_spec_local_var) {
        return NULL;
    }
    v1_pod_template_spec_local_var->metadata = metadata;
    v1_pod_template_spec_local_var->spec = spec;

    return v1_pod_template_spec_local_var;
}


void v1_pod_template_spec_free(v1_pod_template_spec_t *v1_pod_template_spec) {
    if(NULL == v1_pod_template_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_pod_template_spec->metadata) {
        v1_object_meta_free(v1_pod_template_spec->metadata);
        v1_pod_template_spec->metadata = NULL;
    }
    if (v1_pod_template_spec->spec) {
        v1_pod_spec_free(v1_pod_template_spec->spec);
        v1_pod_template_spec->spec = NULL;
    }
    free(v1_pod_template_spec);
}

cJSON *v1_pod_template_spec_convertToJSON(v1_pod_template_spec_t *v1_pod_template_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_pod_template_spec->metadata
    if(v1_pod_template_spec->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_pod_template_spec->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_pod_template_spec->spec
    if(v1_pod_template_spec->spec) { 
    cJSON *spec_local_JSON = v1_pod_spec_convertToJSON(v1_pod_template_spec->spec);
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

v1_pod_template_spec_t *v1_pod_template_spec_parseFromJSON(cJSON *v1_pod_template_specJSON){

    v1_pod_template_spec_t *v1_pod_template_spec_local_var = NULL;

    // v1_pod_template_spec->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_pod_template_specJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_pod_template_spec->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1_pod_template_specJSON, "spec");
    v1_pod_spec_t *spec_local_nonprim = NULL;
    if (spec) { 
    spec_local_nonprim = v1_pod_spec_parseFromJSON(spec); //nonprimitive
    }


    v1_pod_template_spec_local_var = v1_pod_template_spec_create (
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL
        );

    return v1_pod_template_spec_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1_pod_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    return NULL;

}
