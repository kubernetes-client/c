#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_workload_pod_group_disruption_mode.h"



static v1alpha3_workload_pod_group_disruption_mode_t *v1alpha3_workload_pod_group_disruption_mode_create_internal(
    object_t *all,
    object_t *single
    ) {
    v1alpha3_workload_pod_group_disruption_mode_t *v1alpha3_workload_pod_group_disruption_mode_local_var = malloc(sizeof(v1alpha3_workload_pod_group_disruption_mode_t));
    if (!v1alpha3_workload_pod_group_disruption_mode_local_var) {
        return NULL;
    }
    memset(v1alpha3_workload_pod_group_disruption_mode_local_var, 0, sizeof(v1alpha3_workload_pod_group_disruption_mode_t));
    v1alpha3_workload_pod_group_disruption_mode_local_var->_library_owned = 1;
    v1alpha3_workload_pod_group_disruption_mode_local_var->all = all;
    v1alpha3_workload_pod_group_disruption_mode_local_var->single = single;
    return v1alpha3_workload_pod_group_disruption_mode_local_var;
}

__attribute__((deprecated)) v1alpha3_workload_pod_group_disruption_mode_t *v1alpha3_workload_pod_group_disruption_mode_create(
    object_t *all,
    object_t *single
    ) {
    v1alpha3_workload_pod_group_disruption_mode_t *result = v1alpha3_workload_pod_group_disruption_mode_create_internal (
        all,
        single
        );
    if (!result) {
    }
    return result;
}

void v1alpha3_workload_pod_group_disruption_mode_free(v1alpha3_workload_pod_group_disruption_mode_t *v1alpha3_workload_pod_group_disruption_mode) {
    if(NULL == v1alpha3_workload_pod_group_disruption_mode){
        return ;
    }
    if(v1alpha3_workload_pod_group_disruption_mode->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha3_workload_pod_group_disruption_mode_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_workload_pod_group_disruption_mode->all) {
        object_free(v1alpha3_workload_pod_group_disruption_mode->all);
        v1alpha3_workload_pod_group_disruption_mode->all = NULL;
    }
    if (v1alpha3_workload_pod_group_disruption_mode->single) {
        object_free(v1alpha3_workload_pod_group_disruption_mode->single);
        v1alpha3_workload_pod_group_disruption_mode->single = NULL;
    }
    free(v1alpha3_workload_pod_group_disruption_mode);
}

cJSON *v1alpha3_workload_pod_group_disruption_mode_convertToJSON(v1alpha3_workload_pod_group_disruption_mode_t *v1alpha3_workload_pod_group_disruption_mode) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_workload_pod_group_disruption_mode->all
    if(v1alpha3_workload_pod_group_disruption_mode->all) {
    cJSON *all_object = object_convertToJSON(v1alpha3_workload_pod_group_disruption_mode->all);
    if(all_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "all", all_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha3_workload_pod_group_disruption_mode->single
    if(v1alpha3_workload_pod_group_disruption_mode->single) {
    cJSON *single_object = object_convertToJSON(v1alpha3_workload_pod_group_disruption_mode->single);
    if(single_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "single", single_object);
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

v1alpha3_workload_pod_group_disruption_mode_t *v1alpha3_workload_pod_group_disruption_mode_parseFromJSON(cJSON *v1alpha3_workload_pod_group_disruption_modeJSON){

    v1alpha3_workload_pod_group_disruption_mode_t *v1alpha3_workload_pod_group_disruption_mode_local_var = NULL;

    // v1alpha3_workload_pod_group_disruption_mode->all
    cJSON *all = cJSON_GetObjectItemCaseSensitive(v1alpha3_workload_pod_group_disruption_modeJSON, "all");
    if (cJSON_IsNull(all)) {
        all = NULL;
    }
    object_t *all_local_object = NULL;
    if (all) { 
    all_local_object = object_parseFromJSON(all); //object
    }

    // v1alpha3_workload_pod_group_disruption_mode->single
    cJSON *single = cJSON_GetObjectItemCaseSensitive(v1alpha3_workload_pod_group_disruption_modeJSON, "single");
    if (cJSON_IsNull(single)) {
        single = NULL;
    }
    object_t *single_local_object = NULL;
    if (single) { 
    single_local_object = object_parseFromJSON(single); //object
    }



    v1alpha3_workload_pod_group_disruption_mode_local_var = v1alpha3_workload_pod_group_disruption_mode_create_internal (
        all ? all_local_object : NULL,
        single ? single_local_object : NULL
        );

    if (!v1alpha3_workload_pod_group_disruption_mode_local_var) {
        goto end;
    }

    return v1alpha3_workload_pod_group_disruption_mode_local_var;
end:
    return NULL;

}
