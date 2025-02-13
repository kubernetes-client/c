#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_disruption_budget_spec.h"



static v1_pod_disruption_budget_spec_t *v1_pod_disruption_budget_spec_create_internal(
    int_or_string_t *max_unavailable,
    int_or_string_t *min_available,
    v1_label_selector_t *selector,
    char *unhealthy_pod_eviction_policy
    ) {
    v1_pod_disruption_budget_spec_t *v1_pod_disruption_budget_spec_local_var = malloc(sizeof(v1_pod_disruption_budget_spec_t));
    if (!v1_pod_disruption_budget_spec_local_var) {
        return NULL;
    }
    v1_pod_disruption_budget_spec_local_var->max_unavailable = max_unavailable;
    v1_pod_disruption_budget_spec_local_var->min_available = min_available;
    v1_pod_disruption_budget_spec_local_var->selector = selector;
    v1_pod_disruption_budget_spec_local_var->unhealthy_pod_eviction_policy = unhealthy_pod_eviction_policy;

    v1_pod_disruption_budget_spec_local_var->_library_owned = 1;
    return v1_pod_disruption_budget_spec_local_var;
}

__attribute__((deprecated)) v1_pod_disruption_budget_spec_t *v1_pod_disruption_budget_spec_create(
    int_or_string_t *max_unavailable,
    int_or_string_t *min_available,
    v1_label_selector_t *selector,
    char *unhealthy_pod_eviction_policy
    ) {
    return v1_pod_disruption_budget_spec_create_internal (
        max_unavailable,
        min_available,
        selector,
        unhealthy_pod_eviction_policy
        );
}

void v1_pod_disruption_budget_spec_free(v1_pod_disruption_budget_spec_t *v1_pod_disruption_budget_spec) {
    if(NULL == v1_pod_disruption_budget_spec){
        return ;
    }
    if(v1_pod_disruption_budget_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_pod_disruption_budget_spec_free");
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
    if (v1_pod_disruption_budget_spec->unhealthy_pod_eviction_policy) {
        free(v1_pod_disruption_budget_spec->unhealthy_pod_eviction_policy);
        v1_pod_disruption_budget_spec->unhealthy_pod_eviction_policy = NULL;
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


    // v1_pod_disruption_budget_spec->unhealthy_pod_eviction_policy
    if(v1_pod_disruption_budget_spec->unhealthy_pod_eviction_policy) {
    if(cJSON_AddStringToObject(item, "unhealthyPodEvictionPolicy", v1_pod_disruption_budget_spec->unhealthy_pod_eviction_policy) == NULL) {
    goto fail; //String
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
    if (cJSON_IsNull(max_unavailable)) {
        max_unavailable = NULL;
    }
    if (max_unavailable) { 
    max_unavailable_local_nonprim = int_or_string_parseFromJSON(max_unavailable); //custom
    }

    // v1_pod_disruption_budget_spec->min_available
    cJSON *min_available = cJSON_GetObjectItemCaseSensitive(v1_pod_disruption_budget_specJSON, "minAvailable");
    if (cJSON_IsNull(min_available)) {
        min_available = NULL;
    }
    if (min_available) { 
    min_available_local_nonprim = int_or_string_parseFromJSON(min_available); //custom
    }

    // v1_pod_disruption_budget_spec->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1_pod_disruption_budget_specJSON, "selector");
    if (cJSON_IsNull(selector)) {
        selector = NULL;
    }
    if (selector) { 
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive
    }

    // v1_pod_disruption_budget_spec->unhealthy_pod_eviction_policy
    cJSON *unhealthy_pod_eviction_policy = cJSON_GetObjectItemCaseSensitive(v1_pod_disruption_budget_specJSON, "unhealthyPodEvictionPolicy");
    if (cJSON_IsNull(unhealthy_pod_eviction_policy)) {
        unhealthy_pod_eviction_policy = NULL;
    }
    if (unhealthy_pod_eviction_policy) { 
    if(!cJSON_IsString(unhealthy_pod_eviction_policy) && !cJSON_IsNull(unhealthy_pod_eviction_policy))
    {
    goto end; //String
    }
    }


    v1_pod_disruption_budget_spec_local_var = v1_pod_disruption_budget_spec_create_internal (
        max_unavailable ? max_unavailable_local_nonprim : NULL,
        min_available ? min_available_local_nonprim : NULL,
        selector ? selector_local_nonprim : NULL,
        unhealthy_pod_eviction_policy && !cJSON_IsNull(unhealthy_pod_eviction_policy) ? strdup(unhealthy_pod_eviction_policy->valuestring) : NULL
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
