#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "apps_v1beta1_scale_spec.h"



apps_v1beta1_scale_spec_t *apps_v1beta1_scale_spec_create(
    int replicas
    ) {
    apps_v1beta1_scale_spec_t *apps_v1beta1_scale_spec_local_var = malloc(sizeof(apps_v1beta1_scale_spec_t));
    if (!apps_v1beta1_scale_spec_local_var) {
        return NULL;
    }
    apps_v1beta1_scale_spec_local_var->replicas = replicas;

    return apps_v1beta1_scale_spec_local_var;
}


void apps_v1beta1_scale_spec_free(apps_v1beta1_scale_spec_t *apps_v1beta1_scale_spec) {
    if(NULL == apps_v1beta1_scale_spec){
        return ;
    }
    listEntry_t *listEntry;
    free(apps_v1beta1_scale_spec);
}

cJSON *apps_v1beta1_scale_spec_convertToJSON(apps_v1beta1_scale_spec_t *apps_v1beta1_scale_spec) {
    cJSON *item = cJSON_CreateObject();

    // apps_v1beta1_scale_spec->replicas
    if(apps_v1beta1_scale_spec->replicas) { 
    if(cJSON_AddNumberToObject(item, "replicas", apps_v1beta1_scale_spec->replicas) == NULL) {
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

apps_v1beta1_scale_spec_t *apps_v1beta1_scale_spec_parseFromJSON(cJSON *apps_v1beta1_scale_specJSON){

    apps_v1beta1_scale_spec_t *apps_v1beta1_scale_spec_local_var = NULL;

    // apps_v1beta1_scale_spec->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_scale_specJSON, "replicas");
    if (replicas) { 
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }
    }


    apps_v1beta1_scale_spec_local_var = apps_v1beta1_scale_spec_create (
        replicas ? replicas->valuedouble : 0
        );

    return apps_v1beta1_scale_spec_local_var;
end:
    return NULL;

}
