#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_ephemeral_volume_source.h"



v1_ephemeral_volume_source_t *v1_ephemeral_volume_source_create(
    v1_persistent_volume_claim_template_t *volume_claim_template
    ) {
    v1_ephemeral_volume_source_t *v1_ephemeral_volume_source_local_var = malloc(sizeof(v1_ephemeral_volume_source_t));
    if (!v1_ephemeral_volume_source_local_var) {
        return NULL;
    }
    v1_ephemeral_volume_source_local_var->volume_claim_template = volume_claim_template;

    return v1_ephemeral_volume_source_local_var;
}


void v1_ephemeral_volume_source_free(v1_ephemeral_volume_source_t *v1_ephemeral_volume_source) {
    if(NULL == v1_ephemeral_volume_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_ephemeral_volume_source->volume_claim_template) {
        v1_persistent_volume_claim_template_free(v1_ephemeral_volume_source->volume_claim_template);
        v1_ephemeral_volume_source->volume_claim_template = NULL;
    }
    free(v1_ephemeral_volume_source);
}

cJSON *v1_ephemeral_volume_source_convertToJSON(v1_ephemeral_volume_source_t *v1_ephemeral_volume_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_ephemeral_volume_source->volume_claim_template
    if(v1_ephemeral_volume_source->volume_claim_template) { 
    cJSON *volume_claim_template_local_JSON = v1_persistent_volume_claim_template_convertToJSON(v1_ephemeral_volume_source->volume_claim_template);
    if(volume_claim_template_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "volumeClaimTemplate", volume_claim_template_local_JSON);
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

v1_ephemeral_volume_source_t *v1_ephemeral_volume_source_parseFromJSON(cJSON *v1_ephemeral_volume_sourceJSON){

    v1_ephemeral_volume_source_t *v1_ephemeral_volume_source_local_var = NULL;

    // define the local variable for v1_ephemeral_volume_source->volume_claim_template
    v1_persistent_volume_claim_template_t *volume_claim_template_local_nonprim = NULL;

    // v1_ephemeral_volume_source->volume_claim_template
    cJSON *volume_claim_template = cJSON_GetObjectItemCaseSensitive(v1_ephemeral_volume_sourceJSON, "volumeClaimTemplate");
    if (volume_claim_template) { 
    volume_claim_template_local_nonprim = v1_persistent_volume_claim_template_parseFromJSON(volume_claim_template); //nonprimitive
    }


    v1_ephemeral_volume_source_local_var = v1_ephemeral_volume_source_create (
        volume_claim_template ? volume_claim_template_local_nonprim : NULL
        );

    return v1_ephemeral_volume_source_local_var;
end:
    if (volume_claim_template_local_nonprim) {
        v1_persistent_volume_claim_template_free(volume_claim_template_local_nonprim);
        volume_claim_template_local_nonprim = NULL;
    }
    return NULL;

}
