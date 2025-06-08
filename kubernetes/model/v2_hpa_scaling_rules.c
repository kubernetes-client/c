#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2_hpa_scaling_rules.h"



static v2_hpa_scaling_rules_t *v2_hpa_scaling_rules_create_internal(
    list_t *policies,
    char *select_policy,
    int stabilization_window_seconds,
    char *tolerance
    ) {
    v2_hpa_scaling_rules_t *v2_hpa_scaling_rules_local_var = malloc(sizeof(v2_hpa_scaling_rules_t));
    if (!v2_hpa_scaling_rules_local_var) {
        return NULL;
    }
    v2_hpa_scaling_rules_local_var->policies = policies;
    v2_hpa_scaling_rules_local_var->select_policy = select_policy;
    v2_hpa_scaling_rules_local_var->stabilization_window_seconds = stabilization_window_seconds;
    v2_hpa_scaling_rules_local_var->tolerance = tolerance;

    v2_hpa_scaling_rules_local_var->_library_owned = 1;
    return v2_hpa_scaling_rules_local_var;
}

__attribute__((deprecated)) v2_hpa_scaling_rules_t *v2_hpa_scaling_rules_create(
    list_t *policies,
    char *select_policy,
    int stabilization_window_seconds,
    char *tolerance
    ) {
    return v2_hpa_scaling_rules_create_internal (
        policies,
        select_policy,
        stabilization_window_seconds,
        tolerance
        );
}

void v2_hpa_scaling_rules_free(v2_hpa_scaling_rules_t *v2_hpa_scaling_rules) {
    if(NULL == v2_hpa_scaling_rules){
        return ;
    }
    if(v2_hpa_scaling_rules->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v2_hpa_scaling_rules_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v2_hpa_scaling_rules->policies) {
        list_ForEach(listEntry, v2_hpa_scaling_rules->policies) {
            v2_hpa_scaling_policy_free(listEntry->data);
        }
        list_freeList(v2_hpa_scaling_rules->policies);
        v2_hpa_scaling_rules->policies = NULL;
    }
    if (v2_hpa_scaling_rules->select_policy) {
        free(v2_hpa_scaling_rules->select_policy);
        v2_hpa_scaling_rules->select_policy = NULL;
    }
    if (v2_hpa_scaling_rules->tolerance) {
        free(v2_hpa_scaling_rules->tolerance);
        v2_hpa_scaling_rules->tolerance = NULL;
    }
    free(v2_hpa_scaling_rules);
}

cJSON *v2_hpa_scaling_rules_convertToJSON(v2_hpa_scaling_rules_t *v2_hpa_scaling_rules) {
    cJSON *item = cJSON_CreateObject();

    // v2_hpa_scaling_rules->policies
    if(v2_hpa_scaling_rules->policies) {
    cJSON *policies = cJSON_AddArrayToObject(item, "policies");
    if(policies == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *policiesListEntry;
    if (v2_hpa_scaling_rules->policies) {
    list_ForEach(policiesListEntry, v2_hpa_scaling_rules->policies) {
    cJSON *itemLocal = v2_hpa_scaling_policy_convertToJSON(policiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(policies, itemLocal);
    }
    }
    }


    // v2_hpa_scaling_rules->select_policy
    if(v2_hpa_scaling_rules->select_policy) {
    if(cJSON_AddStringToObject(item, "selectPolicy", v2_hpa_scaling_rules->select_policy) == NULL) {
    goto fail; //String
    }
    }


    // v2_hpa_scaling_rules->stabilization_window_seconds
    if(v2_hpa_scaling_rules->stabilization_window_seconds) {
    if(cJSON_AddNumberToObject(item, "stabilizationWindowSeconds", v2_hpa_scaling_rules->stabilization_window_seconds) == NULL) {
    goto fail; //Numeric
    }
    }


    // v2_hpa_scaling_rules->tolerance
    if(v2_hpa_scaling_rules->tolerance) {
    if(cJSON_AddStringToObject(item, "tolerance", v2_hpa_scaling_rules->tolerance) == NULL) {
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

v2_hpa_scaling_rules_t *v2_hpa_scaling_rules_parseFromJSON(cJSON *v2_hpa_scaling_rulesJSON){

    v2_hpa_scaling_rules_t *v2_hpa_scaling_rules_local_var = NULL;

    // define the local list for v2_hpa_scaling_rules->policies
    list_t *policiesList = NULL;

    // v2_hpa_scaling_rules->policies
    cJSON *policies = cJSON_GetObjectItemCaseSensitive(v2_hpa_scaling_rulesJSON, "policies");
    if (cJSON_IsNull(policies)) {
        policies = NULL;
    }
    if (policies) { 
    cJSON *policies_local_nonprimitive = NULL;
    if(!cJSON_IsArray(policies)){
        goto end; //nonprimitive container
    }

    policiesList = list_createList();

    cJSON_ArrayForEach(policies_local_nonprimitive,policies )
    {
        if(!cJSON_IsObject(policies_local_nonprimitive)){
            goto end;
        }
        v2_hpa_scaling_policy_t *policiesItem = v2_hpa_scaling_policy_parseFromJSON(policies_local_nonprimitive);

        list_addElement(policiesList, policiesItem);
    }
    }

    // v2_hpa_scaling_rules->select_policy
    cJSON *select_policy = cJSON_GetObjectItemCaseSensitive(v2_hpa_scaling_rulesJSON, "selectPolicy");
    if (cJSON_IsNull(select_policy)) {
        select_policy = NULL;
    }
    if (select_policy) { 
    if(!cJSON_IsString(select_policy) && !cJSON_IsNull(select_policy))
    {
    goto end; //String
    }
    }

    // v2_hpa_scaling_rules->stabilization_window_seconds
    cJSON *stabilization_window_seconds = cJSON_GetObjectItemCaseSensitive(v2_hpa_scaling_rulesJSON, "stabilizationWindowSeconds");
    if (cJSON_IsNull(stabilization_window_seconds)) {
        stabilization_window_seconds = NULL;
    }
    if (stabilization_window_seconds) { 
    if(!cJSON_IsNumber(stabilization_window_seconds))
    {
    goto end; //Numeric
    }
    }

    // v2_hpa_scaling_rules->tolerance
    cJSON *tolerance = cJSON_GetObjectItemCaseSensitive(v2_hpa_scaling_rulesJSON, "tolerance");
    if (cJSON_IsNull(tolerance)) {
        tolerance = NULL;
    }
    if (tolerance) { 
    if(!cJSON_IsString(tolerance) && !cJSON_IsNull(tolerance))
    {
    goto end; //String
    }
    }


    v2_hpa_scaling_rules_local_var = v2_hpa_scaling_rules_create_internal (
        policies ? policiesList : NULL,
        select_policy && !cJSON_IsNull(select_policy) ? strdup(select_policy->valuestring) : NULL,
        stabilization_window_seconds ? stabilization_window_seconds->valuedouble : 0,
        tolerance && !cJSON_IsNull(tolerance) ? strdup(tolerance->valuestring) : NULL
        );

    return v2_hpa_scaling_rules_local_var;
end:
    if (policiesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, policiesList) {
            v2_hpa_scaling_policy_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(policiesList);
        policiesList = NULL;
    }
    return NULL;

}
