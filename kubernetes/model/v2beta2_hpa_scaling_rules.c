#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2beta2_hpa_scaling_rules.h"



v2beta2_hpa_scaling_rules_t *v2beta2_hpa_scaling_rules_create(
    list_t *policies,
    char *select_policy,
    int stabilization_window_seconds
    ) {
    v2beta2_hpa_scaling_rules_t *v2beta2_hpa_scaling_rules_local_var = malloc(sizeof(v2beta2_hpa_scaling_rules_t));
    if (!v2beta2_hpa_scaling_rules_local_var) {
        return NULL;
    }
    v2beta2_hpa_scaling_rules_local_var->policies = policies;
    v2beta2_hpa_scaling_rules_local_var->select_policy = select_policy;
    v2beta2_hpa_scaling_rules_local_var->stabilization_window_seconds = stabilization_window_seconds;

    return v2beta2_hpa_scaling_rules_local_var;
}


void v2beta2_hpa_scaling_rules_free(v2beta2_hpa_scaling_rules_t *v2beta2_hpa_scaling_rules) {
    if(NULL == v2beta2_hpa_scaling_rules){
        return ;
    }
    listEntry_t *listEntry;
    if (v2beta2_hpa_scaling_rules->policies) {
        list_ForEach(listEntry, v2beta2_hpa_scaling_rules->policies) {
            v2beta2_hpa_scaling_policy_free(listEntry->data);
        }
        list_freeList(v2beta2_hpa_scaling_rules->policies);
        v2beta2_hpa_scaling_rules->policies = NULL;
    }
    if (v2beta2_hpa_scaling_rules->select_policy) {
        free(v2beta2_hpa_scaling_rules->select_policy);
        v2beta2_hpa_scaling_rules->select_policy = NULL;
    }
    free(v2beta2_hpa_scaling_rules);
}

cJSON *v2beta2_hpa_scaling_rules_convertToJSON(v2beta2_hpa_scaling_rules_t *v2beta2_hpa_scaling_rules) {
    cJSON *item = cJSON_CreateObject();

    // v2beta2_hpa_scaling_rules->policies
    if(v2beta2_hpa_scaling_rules->policies) {
    cJSON *policies = cJSON_AddArrayToObject(item, "policies");
    if(policies == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *policiesListEntry;
    if (v2beta2_hpa_scaling_rules->policies) {
    list_ForEach(policiesListEntry, v2beta2_hpa_scaling_rules->policies) {
    cJSON *itemLocal = v2beta2_hpa_scaling_policy_convertToJSON(policiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(policies, itemLocal);
    }
    }
    }


    // v2beta2_hpa_scaling_rules->select_policy
    if(v2beta2_hpa_scaling_rules->select_policy) {
    if(cJSON_AddStringToObject(item, "selectPolicy", v2beta2_hpa_scaling_rules->select_policy) == NULL) {
    goto fail; //String
    }
    }


    // v2beta2_hpa_scaling_rules->stabilization_window_seconds
    if(v2beta2_hpa_scaling_rules->stabilization_window_seconds) {
    if(cJSON_AddNumberToObject(item, "stabilizationWindowSeconds", v2beta2_hpa_scaling_rules->stabilization_window_seconds) == NULL) {
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

v2beta2_hpa_scaling_rules_t *v2beta2_hpa_scaling_rules_parseFromJSON(cJSON *v2beta2_hpa_scaling_rulesJSON){

    v2beta2_hpa_scaling_rules_t *v2beta2_hpa_scaling_rules_local_var = NULL;

    // define the local list for v2beta2_hpa_scaling_rules->policies
    list_t *policiesList = NULL;

    // v2beta2_hpa_scaling_rules->policies
    cJSON *policies = cJSON_GetObjectItemCaseSensitive(v2beta2_hpa_scaling_rulesJSON, "policies");
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
        v2beta2_hpa_scaling_policy_t *policiesItem = v2beta2_hpa_scaling_policy_parseFromJSON(policies_local_nonprimitive);

        list_addElement(policiesList, policiesItem);
    }
    }

    // v2beta2_hpa_scaling_rules->select_policy
    cJSON *select_policy = cJSON_GetObjectItemCaseSensitive(v2beta2_hpa_scaling_rulesJSON, "selectPolicy");
    if (select_policy) { 
    if(!cJSON_IsString(select_policy))
    {
    goto end; //String
    }
    }

    // v2beta2_hpa_scaling_rules->stabilization_window_seconds
    cJSON *stabilization_window_seconds = cJSON_GetObjectItemCaseSensitive(v2beta2_hpa_scaling_rulesJSON, "stabilizationWindowSeconds");
    if (stabilization_window_seconds) { 
    if(!cJSON_IsNumber(stabilization_window_seconds))
    {
    goto end; //Numeric
    }
    }


    v2beta2_hpa_scaling_rules_local_var = v2beta2_hpa_scaling_rules_create (
        policies ? policiesList : NULL,
        select_policy ? strdup(select_policy->valuestring) : NULL,
        stabilization_window_seconds ? stabilization_window_seconds->valuedouble : 0
        );

    return v2beta2_hpa_scaling_rules_local_var;
end:
    if (policiesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, policiesList) {
            v2beta2_hpa_scaling_policy_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(policiesList);
        policiesList = NULL;
    }
    return NULL;

}
