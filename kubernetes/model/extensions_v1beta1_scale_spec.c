#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_scale_spec.h"



extensions_v1beta1_scale_spec_t *extensions_v1beta1_scale_spec_create(
    int replicas
    ) {
    extensions_v1beta1_scale_spec_t *extensions_v1beta1_scale_spec_local_var = malloc(sizeof(extensions_v1beta1_scale_spec_t));
    if (!extensions_v1beta1_scale_spec_local_var) {
        return NULL;
    }
    extensions_v1beta1_scale_spec_local_var->replicas = replicas;

    return extensions_v1beta1_scale_spec_local_var;
}


void extensions_v1beta1_scale_spec_free(extensions_v1beta1_scale_spec_t *extensions_v1beta1_scale_spec) {
    if(NULL == extensions_v1beta1_scale_spec){
        return ;
    }
    listEntry_t *listEntry;
    free(extensions_v1beta1_scale_spec);
}

cJSON *extensions_v1beta1_scale_spec_convertToJSON(extensions_v1beta1_scale_spec_t *extensions_v1beta1_scale_spec) {
    cJSON *item = cJSON_CreateObject();

    // extensions_v1beta1_scale_spec->replicas
    if(extensions_v1beta1_scale_spec->replicas) { 
    if(cJSON_AddNumberToObject(item, "replicas", extensions_v1beta1_scale_spec->replicas) == NULL) {
    goto fail; //Numeric
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

extensions_v1beta1_scale_spec_t *extensions_v1beta1_scale_spec_parseFromJSON(cJSON *extensions_v1beta1_scale_specJSON){

    extensions_v1beta1_scale_spec_t *extensions_v1beta1_scale_spec_local_var = NULL;

    // extensions_v1beta1_scale_spec->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_scale_specJSON, "replicas");
    if (replicas) { 
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }
    }


    extensions_v1beta1_scale_spec_local_var = extensions_v1beta1_scale_spec_create (
        replicas ? replicas->valuedouble : 0
        );

    return extensions_v1beta1_scale_spec_local_var;
end:
    return NULL;

}
