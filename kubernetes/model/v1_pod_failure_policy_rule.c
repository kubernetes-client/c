#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_failure_policy_rule.h"



v1_pod_failure_policy_rule_t *v1_pod_failure_policy_rule_create(
    char *action,
    v1_pod_failure_policy_on_exit_codes_requirement_t *on_exit_codes,
    list_t *on_pod_conditions
    ) {
    v1_pod_failure_policy_rule_t *v1_pod_failure_policy_rule_local_var = malloc(sizeof(v1_pod_failure_policy_rule_t));
    if (!v1_pod_failure_policy_rule_local_var) {
        return NULL;
    }
    v1_pod_failure_policy_rule_local_var->action = action;
    v1_pod_failure_policy_rule_local_var->on_exit_codes = on_exit_codes;
    v1_pod_failure_policy_rule_local_var->on_pod_conditions = on_pod_conditions;

    return v1_pod_failure_policy_rule_local_var;
}


void v1_pod_failure_policy_rule_free(v1_pod_failure_policy_rule_t *v1_pod_failure_policy_rule) {
    if(NULL == v1_pod_failure_policy_rule){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_pod_failure_policy_rule->action) {
        free(v1_pod_failure_policy_rule->action);
        v1_pod_failure_policy_rule->action = NULL;
    }
    if (v1_pod_failure_policy_rule->on_exit_codes) {
        v1_pod_failure_policy_on_exit_codes_requirement_free(v1_pod_failure_policy_rule->on_exit_codes);
        v1_pod_failure_policy_rule->on_exit_codes = NULL;
    }
    if (v1_pod_failure_policy_rule->on_pod_conditions) {
        list_ForEach(listEntry, v1_pod_failure_policy_rule->on_pod_conditions) {
            v1_pod_failure_policy_on_pod_conditions_pattern_free(listEntry->data);
        }
        list_freeList(v1_pod_failure_policy_rule->on_pod_conditions);
        v1_pod_failure_policy_rule->on_pod_conditions = NULL;
    }
    free(v1_pod_failure_policy_rule);
}

cJSON *v1_pod_failure_policy_rule_convertToJSON(v1_pod_failure_policy_rule_t *v1_pod_failure_policy_rule) {
    cJSON *item = cJSON_CreateObject();

    // v1_pod_failure_policy_rule->action
    if (!v1_pod_failure_policy_rule->action) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "action", v1_pod_failure_policy_rule->action) == NULL) {
    goto fail; //String
    }


    // v1_pod_failure_policy_rule->on_exit_codes
    if(v1_pod_failure_policy_rule->on_exit_codes) {
    cJSON *on_exit_codes_local_JSON = v1_pod_failure_policy_on_exit_codes_requirement_convertToJSON(v1_pod_failure_policy_rule->on_exit_codes);
    if(on_exit_codes_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "onExitCodes", on_exit_codes_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_pod_failure_policy_rule->on_pod_conditions
    if(v1_pod_failure_policy_rule->on_pod_conditions) {
    cJSON *on_pod_conditions = cJSON_AddArrayToObject(item, "onPodConditions");
    if(on_pod_conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *on_pod_conditionsListEntry;
    if (v1_pod_failure_policy_rule->on_pod_conditions) {
    list_ForEach(on_pod_conditionsListEntry, v1_pod_failure_policy_rule->on_pod_conditions) {
    cJSON *itemLocal = v1_pod_failure_policy_on_pod_conditions_pattern_convertToJSON(on_pod_conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(on_pod_conditions, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_pod_failure_policy_rule_t *v1_pod_failure_policy_rule_parseFromJSON(cJSON *v1_pod_failure_policy_ruleJSON){

    v1_pod_failure_policy_rule_t *v1_pod_failure_policy_rule_local_var = NULL;

    // define the local variable for v1_pod_failure_policy_rule->on_exit_codes
    v1_pod_failure_policy_on_exit_codes_requirement_t *on_exit_codes_local_nonprim = NULL;

    // define the local list for v1_pod_failure_policy_rule->on_pod_conditions
    list_t *on_pod_conditionsList = NULL;

    // v1_pod_failure_policy_rule->action
    cJSON *action = cJSON_GetObjectItemCaseSensitive(v1_pod_failure_policy_ruleJSON, "action");
    if (!action) {
        goto end;
    }

    
    if(!cJSON_IsString(action))
    {
    goto end; //String
    }

    // v1_pod_failure_policy_rule->on_exit_codes
    cJSON *on_exit_codes = cJSON_GetObjectItemCaseSensitive(v1_pod_failure_policy_ruleJSON, "onExitCodes");
    if (on_exit_codes) { 
    on_exit_codes_local_nonprim = v1_pod_failure_policy_on_exit_codes_requirement_parseFromJSON(on_exit_codes); //nonprimitive
    }

    // v1_pod_failure_policy_rule->on_pod_conditions
    cJSON *on_pod_conditions = cJSON_GetObjectItemCaseSensitive(v1_pod_failure_policy_ruleJSON, "onPodConditions");
    if (on_pod_conditions) { 
    cJSON *on_pod_conditions_local_nonprimitive = NULL;
    if(!cJSON_IsArray(on_pod_conditions)){
        goto end; //nonprimitive container
    }

    on_pod_conditionsList = list_createList();

    cJSON_ArrayForEach(on_pod_conditions_local_nonprimitive,on_pod_conditions )
    {
        if(!cJSON_IsObject(on_pod_conditions_local_nonprimitive)){
            goto end;
        }
        v1_pod_failure_policy_on_pod_conditions_pattern_t *on_pod_conditionsItem = v1_pod_failure_policy_on_pod_conditions_pattern_parseFromJSON(on_pod_conditions_local_nonprimitive);

        list_addElement(on_pod_conditionsList, on_pod_conditionsItem);
    }
    }


    v1_pod_failure_policy_rule_local_var = v1_pod_failure_policy_rule_create (
        strdup(action->valuestring),
        on_exit_codes ? on_exit_codes_local_nonprim : NULL,
        on_pod_conditions ? on_pod_conditionsList : NULL
        );

    return v1_pod_failure_policy_rule_local_var;
end:
    if (on_exit_codes_local_nonprim) {
        v1_pod_failure_policy_on_exit_codes_requirement_free(on_exit_codes_local_nonprim);
        on_exit_codes_local_nonprim = NULL;
    }
    if (on_pod_conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, on_pod_conditionsList) {
            v1_pod_failure_policy_on_pod_conditions_pattern_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(on_pod_conditionsList);
        on_pod_conditionsList = NULL;
    }
    return NULL;

}
