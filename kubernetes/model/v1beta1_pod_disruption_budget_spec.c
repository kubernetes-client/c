#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_pod_disruption_budget_spec.h"



v1beta1_pod_disruption_budget_spec_t *v1beta1_pod_disruption_budget_spec_create(
    object_t *max_unavailable,
    object_t *min_available,
    v1_label_selector_t *selector
    ) {
    v1beta1_pod_disruption_budget_spec_t *v1beta1_pod_disruption_budget_spec_local_var = malloc(sizeof(v1beta1_pod_disruption_budget_spec_t));
    if (!v1beta1_pod_disruption_budget_spec_local_var) {
        return NULL;
    }
    v1beta1_pod_disruption_budget_spec_local_var->max_unavailable = max_unavailable;
    v1beta1_pod_disruption_budget_spec_local_var->min_available = min_available;
    v1beta1_pod_disruption_budget_spec_local_var->selector = selector;

    return v1beta1_pod_disruption_budget_spec_local_var;
}


void v1beta1_pod_disruption_budget_spec_free(v1beta1_pod_disruption_budget_spec_t *v1beta1_pod_disruption_budget_spec) {
    if(NULL == v1beta1_pod_disruption_budget_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_pod_disruption_budget_spec->max_unavailable) {
        object_free(v1beta1_pod_disruption_budget_spec->max_unavailable);
        v1beta1_pod_disruption_budget_spec->max_unavailable = NULL;
    }
    if (v1beta1_pod_disruption_budget_spec->min_available) {
        object_free(v1beta1_pod_disruption_budget_spec->min_available);
        v1beta1_pod_disruption_budget_spec->min_available = NULL;
    }
    if (v1beta1_pod_disruption_budget_spec->selector) {
        v1_label_selector_free(v1beta1_pod_disruption_budget_spec->selector);
        v1beta1_pod_disruption_budget_spec->selector = NULL;
    }
    free(v1beta1_pod_disruption_budget_spec);
}

cJSON *v1beta1_pod_disruption_budget_spec_convertToJSON(v1beta1_pod_disruption_budget_spec_t *v1beta1_pod_disruption_budget_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_pod_disruption_budget_spec->max_unavailable
    if(v1beta1_pod_disruption_budget_spec->max_unavailable) { 
    cJSON *max_unavailable_object = object_convertToJSON(v1beta1_pod_disruption_budget_spec->max_unavailable);
    if(max_unavailable_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "maxUnavailable", max_unavailable_object);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1beta1_pod_disruption_budget_spec->min_available
    if(v1beta1_pod_disruption_budget_spec->min_available) { 
    cJSON *min_available_object = object_convertToJSON(v1beta1_pod_disruption_budget_spec->min_available);
    if(min_available_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "minAvailable", min_available_object);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1beta1_pod_disruption_budget_spec->selector
    if(v1beta1_pod_disruption_budget_spec->selector) { 
    cJSON *selector_local_JSON = v1_label_selector_convertToJSON(v1beta1_pod_disruption_budget_spec->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "selector", selector_local_JSON);
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

v1beta1_pod_disruption_budget_spec_t *v1beta1_pod_disruption_budget_spec_parseFromJSON(cJSON *v1beta1_pod_disruption_budget_specJSON){

    v1beta1_pod_disruption_budget_spec_t *v1beta1_pod_disruption_budget_spec_local_var = NULL;

    // v1beta1_pod_disruption_budget_spec->max_unavailable
    cJSON *max_unavailable = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_disruption_budget_specJSON, "maxUnavailable");
    object_t *max_unavailable_local_object = NULL;
    if (max_unavailable) { 
    max_unavailable_local_object = object_parseFromJSON(max_unavailable); //object
    }

    // v1beta1_pod_disruption_budget_spec->min_available
    cJSON *min_available = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_disruption_budget_specJSON, "minAvailable");
    object_t *min_available_local_object = NULL;
    if (min_available) { 
    min_available_local_object = object_parseFromJSON(min_available); //object
    }

    // v1beta1_pod_disruption_budget_spec->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_disruption_budget_specJSON, "selector");
    v1_label_selector_t *selector_local_nonprim = NULL;
    if (selector) { 
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive
    }


    v1beta1_pod_disruption_budget_spec_local_var = v1beta1_pod_disruption_budget_spec_create (
        max_unavailable ? max_unavailable_local_object : NULL,
        min_available ? min_available_local_object : NULL,
        selector ? selector_local_nonprim : NULL
        );

    return v1beta1_pod_disruption_budget_spec_local_var;
end:
    if (selector_local_nonprim) {
        v1_label_selector_free(selector_local_nonprim);
        selector_local_nonprim = NULL;
    }
    return NULL;

}
