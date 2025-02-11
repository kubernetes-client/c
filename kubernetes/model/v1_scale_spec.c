#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_scale_spec.h"



static v1_scale_spec_t *v1_scale_spec_create_internal(
    int replicas
    ) {
    v1_scale_spec_t *v1_scale_spec_local_var = malloc(sizeof(v1_scale_spec_t));
    if (!v1_scale_spec_local_var) {
        return NULL;
    }
    v1_scale_spec_local_var->replicas = replicas;

    v1_scale_spec_local_var->_library_owned = 1;
    return v1_scale_spec_local_var;
}

__attribute__((deprecated)) v1_scale_spec_t *v1_scale_spec_create(
    int replicas
    ) {
    return v1_scale_spec_create_internal (
        replicas
        );
}

void v1_scale_spec_free(v1_scale_spec_t *v1_scale_spec) {
    if(NULL == v1_scale_spec){
        return ;
    }
    if(v1_scale_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_scale_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    free(v1_scale_spec);
}

cJSON *v1_scale_spec_convertToJSON(v1_scale_spec_t *v1_scale_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_scale_spec->replicas
    if(v1_scale_spec->replicas) {
    if(cJSON_AddNumberToObject(item, "replicas", v1_scale_spec->replicas) == NULL) {
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

v1_scale_spec_t *v1_scale_spec_parseFromJSON(cJSON *v1_scale_specJSON){

    v1_scale_spec_t *v1_scale_spec_local_var = NULL;

    // v1_scale_spec->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(v1_scale_specJSON, "replicas");
    if (cJSON_IsNull(replicas)) {
        replicas = NULL;
    }
    if (replicas) { 
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }
    }


    v1_scale_spec_local_var = v1_scale_spec_create_internal (
        replicas ? replicas->valuedouble : 0
        );

    return v1_scale_spec_local_var;
end:
    return NULL;

}
