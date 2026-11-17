#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_eviction_request_target.h"



static v1alpha1_eviction_request_target_t *v1alpha1_eviction_request_target_create_internal(
    v1alpha1_eviction_request_pod_reference_t *pod
    ) {
    v1alpha1_eviction_request_target_t *v1alpha1_eviction_request_target_local_var = malloc(sizeof(v1alpha1_eviction_request_target_t));
    if (!v1alpha1_eviction_request_target_local_var) {
        return NULL;
    }
    memset(v1alpha1_eviction_request_target_local_var, 0, sizeof(v1alpha1_eviction_request_target_t));
    v1alpha1_eviction_request_target_local_var->_library_owned = 1;
    v1alpha1_eviction_request_target_local_var->pod = pod;
    return v1alpha1_eviction_request_target_local_var;
}

__attribute__((deprecated)) v1alpha1_eviction_request_target_t *v1alpha1_eviction_request_target_create(
    v1alpha1_eviction_request_pod_reference_t *pod
    ) {
    v1alpha1_eviction_request_target_t *result = v1alpha1_eviction_request_target_create_internal (
        pod
        );
    if (!result) {
    }
    return result;
}

void v1alpha1_eviction_request_target_free(v1alpha1_eviction_request_target_t *v1alpha1_eviction_request_target) {
    if(NULL == v1alpha1_eviction_request_target){
        return ;
    }
    if(v1alpha1_eviction_request_target->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha1_eviction_request_target_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_eviction_request_target->pod) {
        v1alpha1_eviction_request_pod_reference_free(v1alpha1_eviction_request_target->pod);
        v1alpha1_eviction_request_target->pod = NULL;
    }
    free(v1alpha1_eviction_request_target);
}

cJSON *v1alpha1_eviction_request_target_convertToJSON(v1alpha1_eviction_request_target_t *v1alpha1_eviction_request_target) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_eviction_request_target->pod
    if(v1alpha1_eviction_request_target->pod) {
    cJSON *pod_local_JSON = v1alpha1_eviction_request_pod_reference_convertToJSON(v1alpha1_eviction_request_target->pod);
    if(pod_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "pod", pod_local_JSON);
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

v1alpha1_eviction_request_target_t *v1alpha1_eviction_request_target_parseFromJSON(cJSON *v1alpha1_eviction_request_targetJSON){

    v1alpha1_eviction_request_target_t *v1alpha1_eviction_request_target_local_var = NULL;

    // define the local variable for v1alpha1_eviction_request_target->pod
    v1alpha1_eviction_request_pod_reference_t *pod_local_nonprim = NULL;

    // v1alpha1_eviction_request_target->pod
    cJSON *pod = cJSON_GetObjectItemCaseSensitive(v1alpha1_eviction_request_targetJSON, "pod");
    if (cJSON_IsNull(pod)) {
        pod = NULL;
    }
    if (pod) { 
    pod_local_nonprim = v1alpha1_eviction_request_pod_reference_parseFromJSON(pod); //nonprimitive
    }



    v1alpha1_eviction_request_target_local_var = v1alpha1_eviction_request_target_create_internal (
        pod ? pod_local_nonprim : NULL
        );

    if (!v1alpha1_eviction_request_target_local_var) {
        goto end;
    }

    return v1alpha1_eviction_request_target_local_var;
end:
    if (pod_local_nonprim) {
        v1alpha1_eviction_request_pod_reference_free(pod_local_nonprim);
        pod_local_nonprim = NULL;
    }
    return NULL;

}
