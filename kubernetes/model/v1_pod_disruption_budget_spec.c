#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_disruption_budget_spec.h"



v1_pod_disruption_budget_spec_t *v1_pod_disruption_budget_spec_create(
    int_or_string_t *max_unavailable,
    int_or_string_t *min_available,
    v1_label_selector_t *selector
    ) {
    v1_pod_disruption_budget_spec_t *v1_pod_disruption_budget_spec_local_var = malloc(sizeof(v1_pod_disruption_budget_spec_t));
    if (!v1_pod_disruption_budget_spec_local_var) {
        return NULL;
    }
    v1_pod_disruption_budget_spec_local_var->max_unavailable = max_unavailable;
    v1_pod_disruption_budget_spec_local_var->min_available = min_available;
    v1_pod_disruption_budget_spec_local_var->selector = selector;

    return v1_pod_disruption_budget_spec_local_var;
}


void v1_pod_disruption_budget_spec_free(v1_pod_disruption_budget_spec_t *v1_pod_disruption_budget_spec) {
    if(NULL == v1_pod_disruption_budget_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_pod_disruption_budget_spec->max_unavailable) {
        int_or_string_free(v1_pod_disruption_budget_spec->max_unavailable);
        v1_pod_disruption_budget_spec->max_unavailable = NULL;
    }
    if (v1_pod_disruption_budget_spec->min_available) {
        int_or_string_free(v1_pod_disruption_budget_spec->min_available);
        v1_pod_disruption_budget_spec->min_available = NULL;
    }
    if (v1_pod_disruption_budget_spec->selector) {
        v1_label_selector_free(v1_pod_disruption_budget_spec->selector);
        v1_pod_disruption_budget_spec->selector = NULL;
    }
    free(v1_pod_disruption_budget_spec);
}

cJSON *v1_pod_disruption_budget_spec_convertToJSON(v1_pod_disruption_budget_spec_t *v1_pod_disruption_budget_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_pod_disruption_budget_spec->max_unavailable
    if(v1_pod_disruption_budget_spec->max_unavailable) { 
    cJSON *max_unavailable_local_JSON = int_or_string_convertToJSON(v1_pod_disruption_budget_spec->max_unavailable);
    if(max_unavailable_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "maxUnavailable", max_unavailable_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
     } 


    // v1_pod_disruption_budget_spec->min_available
    if(v1_pod_disruption_budget_spec->min_available) { 
    cJSON *min_available_local_JSON = int_or_string_convertToJSON(v1_pod_disruption_budget_spec->min_available);
    if(min_available_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "minAvailable", min_available_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
     } 


    // v1_pod_disruption_budget_spec->selector
    if(v1_pod_disruption_budget_spec->selector) { 
    cJSON *selector_local_JSON = v1_label_selector_convertToJSON(v1_pod_disruption_budget_spec->selector);
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

v1_pod_disruption_budget_spec_t *v1_pod_disruption_budget_spec_parseFromJSON(cJSON *v1_pod_disruption_budget_specJSON){

    v1_pod_disruption_budget_spec_t *v1_pod_disruption_budget_spec_local_var = NULL;

    // define the local variable for v1_pod_disruption_budget_spec->max_unavailable
    int_or_string_t *max_unavailable_local_nonprim = NULL;

    // define the local variable for v1_pod_disruption_budget_spec->min_available
    int_or_string_t *min_available_local_nonprim = NULL;

    // define the local variable for v1_pod_disruption_budget_spec->selector
    v1_label_selector_t *selector_local_nonprim = NULL;

    // v1_pod_disruption_budget_spec->max_unavailable
    cJSON *max_unavailable = cJSON_GetObjectItemCaseSensitive(v1_pod_disruption_budget_specJSON, "maxUnavailable");
    if (max_unavailable) { 
    max_unavailable_local_nonprim = int_or_string_parseFromJSON(max_unavailable); //custom
    }

    // v1_pod_disruption_budget_spec->min_available
    cJSON *min_available = cJSON_GetObjectItemCaseSensitive(v1_pod_disruption_budget_specJSON, "minAvailable");
    if (min_available) { 
    min_available_local_nonprim = int_or_string_parseFromJSON(min_available); //custom
    }

    // v1_pod_disruption_budget_spec->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1_pod_disruption_budget_specJSON, "selector");
    if (selector) { 
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive
    }


    v1_pod_disruption_budget_spec_local_var = v1_pod_disruption_budget_spec_create (
        max_unavailable ? max_unavailable_local_nonprim : NULL,
        min_available ? min_available_local_nonprim : NULL,
        selector ? selector_local_nonprim : NULL
        );

    return v1_pod_disruption_budget_spec_local_var;
end:
    if (max_unavailable_local_nonprim) {
        int_or_string_free(max_unavailable_local_nonprim);
        max_unavailable_local_nonprim = NULL;
    }
    if (min_available_local_nonprim) {
        int_or_string_free(min_available_local_nonprim);
        min_available_local_nonprim = NULL;
    }
    if (selector_local_nonprim) {
        v1_label_selector_free(selector_local_nonprim);
        selector_local_nonprim = NULL;
    }
    return NULL;

}
