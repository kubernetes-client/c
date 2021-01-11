#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_runtime_class_spec.h"



v1alpha1_runtime_class_spec_t *v1alpha1_runtime_class_spec_create(
    v1alpha1_overhead_t *overhead,
    char *runtime_handler,
    v1alpha1_scheduling_t *scheduling
    ) {
    v1alpha1_runtime_class_spec_t *v1alpha1_runtime_class_spec_local_var = malloc(sizeof(v1alpha1_runtime_class_spec_t));
    if (!v1alpha1_runtime_class_spec_local_var) {
        return NULL;
    }
    v1alpha1_runtime_class_spec_local_var->overhead = overhead;
    v1alpha1_runtime_class_spec_local_var->runtime_handler = runtime_handler;
    v1alpha1_runtime_class_spec_local_var->scheduling = scheduling;

    return v1alpha1_runtime_class_spec_local_var;
}


void v1alpha1_runtime_class_spec_free(v1alpha1_runtime_class_spec_t *v1alpha1_runtime_class_spec) {
    if(NULL == v1alpha1_runtime_class_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_runtime_class_spec->overhead) {
        v1alpha1_overhead_free(v1alpha1_runtime_class_spec->overhead);
        v1alpha1_runtime_class_spec->overhead = NULL;
    }
    if (v1alpha1_runtime_class_spec->runtime_handler) {
        free(v1alpha1_runtime_class_spec->runtime_handler);
        v1alpha1_runtime_class_spec->runtime_handler = NULL;
    }
    if (v1alpha1_runtime_class_spec->scheduling) {
        v1alpha1_scheduling_free(v1alpha1_runtime_class_spec->scheduling);
        v1alpha1_runtime_class_spec->scheduling = NULL;
    }
    free(v1alpha1_runtime_class_spec);
}

cJSON *v1alpha1_runtime_class_spec_convertToJSON(v1alpha1_runtime_class_spec_t *v1alpha1_runtime_class_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_runtime_class_spec->overhead
    if(v1alpha1_runtime_class_spec->overhead) { 
    cJSON *overhead_local_JSON = v1alpha1_overhead_convertToJSON(v1alpha1_runtime_class_spec->overhead);
    if(overhead_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "overhead", overhead_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1alpha1_runtime_class_spec->runtime_handler
    if (!v1alpha1_runtime_class_spec->runtime_handler) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "runtimeHandler", v1alpha1_runtime_class_spec->runtime_handler) == NULL) {
    goto fail; //String
    }


    // v1alpha1_runtime_class_spec->scheduling
    if(v1alpha1_runtime_class_spec->scheduling) { 
    cJSON *scheduling_local_JSON = v1alpha1_scheduling_convertToJSON(v1alpha1_runtime_class_spec->scheduling);
    if(scheduling_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "scheduling", scheduling_local_JSON);
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

v1alpha1_runtime_class_spec_t *v1alpha1_runtime_class_spec_parseFromJSON(cJSON *v1alpha1_runtime_class_specJSON){

    v1alpha1_runtime_class_spec_t *v1alpha1_runtime_class_spec_local_var = NULL;

    // v1alpha1_runtime_class_spec->overhead
    cJSON *overhead = cJSON_GetObjectItemCaseSensitive(v1alpha1_runtime_class_specJSON, "overhead");
    v1alpha1_overhead_t *overhead_local_nonprim = NULL;
    if (overhead) { 
    overhead_local_nonprim = v1alpha1_overhead_parseFromJSON(overhead); //nonprimitive
    }

    // v1alpha1_runtime_class_spec->runtime_handler
    cJSON *runtime_handler = cJSON_GetObjectItemCaseSensitive(v1alpha1_runtime_class_specJSON, "runtimeHandler");
    if (!runtime_handler) {
        goto end;
    }

    
    if(!cJSON_IsString(runtime_handler))
    {
    goto end; //String
    }

    // v1alpha1_runtime_class_spec->scheduling
    cJSON *scheduling = cJSON_GetObjectItemCaseSensitive(v1alpha1_runtime_class_specJSON, "scheduling");
    v1alpha1_scheduling_t *scheduling_local_nonprim = NULL;
    if (scheduling) { 
    scheduling_local_nonprim = v1alpha1_scheduling_parseFromJSON(scheduling); //nonprimitive
    }


    v1alpha1_runtime_class_spec_local_var = v1alpha1_runtime_class_spec_create (
        overhead ? overhead_local_nonprim : NULL,
        strdup(runtime_handler->valuestring),
        scheduling ? scheduling_local_nonprim : NULL
        );

    return v1alpha1_runtime_class_spec_local_var;
end:
    if (overhead_local_nonprim) {
        v1alpha1_overhead_free(overhead_local_nonprim);
        overhead_local_nonprim = NULL;
    }
    if (scheduling_local_nonprim) {
        v1alpha1_scheduling_free(scheduling_local_nonprim);
        scheduling_local_nonprim = NULL;
    }
    return NULL;

}
