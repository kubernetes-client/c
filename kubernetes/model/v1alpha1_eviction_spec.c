#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_eviction_spec.h"



static v1alpha1_eviction_spec_t *v1alpha1_eviction_spec_create_internal(
    v1alpha1_eviction_target_t *target
    ) {
    v1alpha1_eviction_spec_t *v1alpha1_eviction_spec_local_var = malloc(sizeof(v1alpha1_eviction_spec_t));
    if (!v1alpha1_eviction_spec_local_var) {
        return NULL;
    }
    memset(v1alpha1_eviction_spec_local_var, 0, sizeof(v1alpha1_eviction_spec_t));
    v1alpha1_eviction_spec_local_var->_library_owned = 1;
    v1alpha1_eviction_spec_local_var->target = target;
    return v1alpha1_eviction_spec_local_var;
}

__attribute__((deprecated)) v1alpha1_eviction_spec_t *v1alpha1_eviction_spec_create(
    v1alpha1_eviction_target_t *target
    ) {
    v1alpha1_eviction_spec_t *result = v1alpha1_eviction_spec_create_internal (
        target
        );
    if (!result) {
    }
    return result;
}

void v1alpha1_eviction_spec_free(v1alpha1_eviction_spec_t *v1alpha1_eviction_spec) {
    if(NULL == v1alpha1_eviction_spec){
        return ;
    }
    if(v1alpha1_eviction_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha1_eviction_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_eviction_spec->target) {
        v1alpha1_eviction_target_free(v1alpha1_eviction_spec->target);
        v1alpha1_eviction_spec->target = NULL;
    }
    free(v1alpha1_eviction_spec);
}

cJSON *v1alpha1_eviction_spec_convertToJSON(v1alpha1_eviction_spec_t *v1alpha1_eviction_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_eviction_spec->target
    if (!v1alpha1_eviction_spec->target) {
        goto fail;
    }
    cJSON *target_local_JSON = v1alpha1_eviction_target_convertToJSON(v1alpha1_eviction_spec->target);
    if(target_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "target", target_local_JSON);
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

v1alpha1_eviction_spec_t *v1alpha1_eviction_spec_parseFromJSON(cJSON *v1alpha1_eviction_specJSON){

    v1alpha1_eviction_spec_t *v1alpha1_eviction_spec_local_var = NULL;

    // define the local variable for v1alpha1_eviction_spec->target
    v1alpha1_eviction_target_t *target_local_nonprim = NULL;

    // v1alpha1_eviction_spec->target
    cJSON *target = cJSON_GetObjectItemCaseSensitive(v1alpha1_eviction_specJSON, "target");
    if (cJSON_IsNull(target)) {
        target = NULL;
    }
    if (!target) {
        goto end;
    }

    
    target_local_nonprim = v1alpha1_eviction_target_parseFromJSON(target); //nonprimitive



    v1alpha1_eviction_spec_local_var = v1alpha1_eviction_spec_create_internal (
        target_local_nonprim
        );

    if (!v1alpha1_eviction_spec_local_var) {
        goto end;
    }

    return v1alpha1_eviction_spec_local_var;
end:
    if (target_local_nonprim) {
        v1alpha1_eviction_target_free(target_local_nonprim);
        target_local_nonprim = NULL;
    }
    return NULL;

}
