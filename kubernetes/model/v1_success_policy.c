#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_success_policy.h"



static v1_success_policy_t *v1_success_policy_create_internal(
    list_t *rules
    ) {
    v1_success_policy_t *v1_success_policy_local_var = malloc(sizeof(v1_success_policy_t));
    if (!v1_success_policy_local_var) {
        return NULL;
    }
    v1_success_policy_local_var->rules = rules;

    v1_success_policy_local_var->_library_owned = 1;
    return v1_success_policy_local_var;
}

__attribute__((deprecated)) v1_success_policy_t *v1_success_policy_create(
    list_t *rules
    ) {
    return v1_success_policy_create_internal (
        rules
        );
}

void v1_success_policy_free(v1_success_policy_t *v1_success_policy) {
    if(NULL == v1_success_policy){
        return ;
    }
    if(v1_success_policy->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_success_policy_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_success_policy->rules) {
        list_ForEach(listEntry, v1_success_policy->rules) {
            v1_success_policy_rule_free(listEntry->data);
        }
        list_freeList(v1_success_policy->rules);
        v1_success_policy->rules = NULL;
    }
    free(v1_success_policy);
}

cJSON *v1_success_policy_convertToJSON(v1_success_policy_t *v1_success_policy) {
    cJSON *item = cJSON_CreateObject();

    // v1_success_policy->rules
    if (!v1_success_policy->rules) {
        goto fail;
    }
    cJSON *rules = cJSON_AddArrayToObject(item, "rules");
    if(rules == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *rulesListEntry;
    if (v1_success_policy->rules) {
    list_ForEach(rulesListEntry, v1_success_policy->rules) {
    cJSON *itemLocal = v1_success_policy_rule_convertToJSON(rulesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(rules, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_success_policy_t *v1_success_policy_parseFromJSON(cJSON *v1_success_policyJSON){

    v1_success_policy_t *v1_success_policy_local_var = NULL;

    // define the local list for v1_success_policy->rules
    list_t *rulesList = NULL;

    // v1_success_policy->rules
    cJSON *rules = cJSON_GetObjectItemCaseSensitive(v1_success_policyJSON, "rules");
    if (cJSON_IsNull(rules)) {
        rules = NULL;
    }
    if (!rules) {
        goto end;
    }

    
    cJSON *rules_local_nonprimitive = NULL;
    if(!cJSON_IsArray(rules)){
        goto end; //nonprimitive container
    }

    rulesList = list_createList();

    cJSON_ArrayForEach(rules_local_nonprimitive,rules )
    {
        if(!cJSON_IsObject(rules_local_nonprimitive)){
            goto end;
        }
        v1_success_policy_rule_t *rulesItem = v1_success_policy_rule_parseFromJSON(rules_local_nonprimitive);

        list_addElement(rulesList, rulesItem);
    }


    v1_success_policy_local_var = v1_success_policy_create_internal (
        rulesList
        );

    return v1_success_policy_local_var;
end:
    if (rulesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, rulesList) {
            v1_success_policy_rule_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(rulesList);
        rulesList = NULL;
    }
    return NULL;

}
