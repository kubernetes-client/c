#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_flow_schema_spec.h"



static v1_flow_schema_spec_t *v1_flow_schema_spec_create_internal(
    v1_flow_distinguisher_method_t *distinguisher_method,
    int matching_precedence,
    v1_priority_level_configuration_reference_t *priority_level_configuration,
    list_t *rules
    ) {
    v1_flow_schema_spec_t *v1_flow_schema_spec_local_var = malloc(sizeof(v1_flow_schema_spec_t));
    if (!v1_flow_schema_spec_local_var) {
        return NULL;
    }
    v1_flow_schema_spec_local_var->distinguisher_method = distinguisher_method;
    v1_flow_schema_spec_local_var->matching_precedence = matching_precedence;
    v1_flow_schema_spec_local_var->priority_level_configuration = priority_level_configuration;
    v1_flow_schema_spec_local_var->rules = rules;

    v1_flow_schema_spec_local_var->_library_owned = 1;
    return v1_flow_schema_spec_local_var;
}

__attribute__((deprecated)) v1_flow_schema_spec_t *v1_flow_schema_spec_create(
    v1_flow_distinguisher_method_t *distinguisher_method,
    int matching_precedence,
    v1_priority_level_configuration_reference_t *priority_level_configuration,
    list_t *rules
    ) {
    return v1_flow_schema_spec_create_internal (
        distinguisher_method,
        matching_precedence,
        priority_level_configuration,
        rules
        );
}

void v1_flow_schema_spec_free(v1_flow_schema_spec_t *v1_flow_schema_spec) {
    if(NULL == v1_flow_schema_spec){
        return ;
    }
    if(v1_flow_schema_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_flow_schema_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_flow_schema_spec->distinguisher_method) {
        v1_flow_distinguisher_method_free(v1_flow_schema_spec->distinguisher_method);
        v1_flow_schema_spec->distinguisher_method = NULL;
    }
    if (v1_flow_schema_spec->priority_level_configuration) {
        v1_priority_level_configuration_reference_free(v1_flow_schema_spec->priority_level_configuration);
        v1_flow_schema_spec->priority_level_configuration = NULL;
    }
    if (v1_flow_schema_spec->rules) {
        list_ForEach(listEntry, v1_flow_schema_spec->rules) {
            v1_policy_rules_with_subjects_free(listEntry->data);
        }
        list_freeList(v1_flow_schema_spec->rules);
        v1_flow_schema_spec->rules = NULL;
    }
    free(v1_flow_schema_spec);
}

cJSON *v1_flow_schema_spec_convertToJSON(v1_flow_schema_spec_t *v1_flow_schema_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_flow_schema_spec->distinguisher_method
    if(v1_flow_schema_spec->distinguisher_method) {
    cJSON *distinguisher_method_local_JSON = v1_flow_distinguisher_method_convertToJSON(v1_flow_schema_spec->distinguisher_method);
    if(distinguisher_method_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "distinguisherMethod", distinguisher_method_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_flow_schema_spec->matching_precedence
    if(v1_flow_schema_spec->matching_precedence) {
    if(cJSON_AddNumberToObject(item, "matchingPrecedence", v1_flow_schema_spec->matching_precedence) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_flow_schema_spec->priority_level_configuration
    if (!v1_flow_schema_spec->priority_level_configuration) {
        goto fail;
    }
    cJSON *priority_level_configuration_local_JSON = v1_priority_level_configuration_reference_convertToJSON(v1_flow_schema_spec->priority_level_configuration);
    if(priority_level_configuration_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "priorityLevelConfiguration", priority_level_configuration_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1_flow_schema_spec->rules
    if(v1_flow_schema_spec->rules) {
    cJSON *rules = cJSON_AddArrayToObject(item, "rules");
    if(rules == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *rulesListEntry;
    if (v1_flow_schema_spec->rules) {
    list_ForEach(rulesListEntry, v1_flow_schema_spec->rules) {
    cJSON *itemLocal = v1_policy_rules_with_subjects_convertToJSON(rulesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(rules, itemLocal);
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

v1_flow_schema_spec_t *v1_flow_schema_spec_parseFromJSON(cJSON *v1_flow_schema_specJSON){

    v1_flow_schema_spec_t *v1_flow_schema_spec_local_var = NULL;

    // define the local variable for v1_flow_schema_spec->distinguisher_method
    v1_flow_distinguisher_method_t *distinguisher_method_local_nonprim = NULL;

    // define the local variable for v1_flow_schema_spec->priority_level_configuration
    v1_priority_level_configuration_reference_t *priority_level_configuration_local_nonprim = NULL;

    // define the local list for v1_flow_schema_spec->rules
    list_t *rulesList = NULL;

    // v1_flow_schema_spec->distinguisher_method
    cJSON *distinguisher_method = cJSON_GetObjectItemCaseSensitive(v1_flow_schema_specJSON, "distinguisherMethod");
    if (cJSON_IsNull(distinguisher_method)) {
        distinguisher_method = NULL;
    }
    if (distinguisher_method) { 
    distinguisher_method_local_nonprim = v1_flow_distinguisher_method_parseFromJSON(distinguisher_method); //nonprimitive
    }

    // v1_flow_schema_spec->matching_precedence
    cJSON *matching_precedence = cJSON_GetObjectItemCaseSensitive(v1_flow_schema_specJSON, "matchingPrecedence");
    if (cJSON_IsNull(matching_precedence)) {
        matching_precedence = NULL;
    }
    if (matching_precedence) { 
    if(!cJSON_IsNumber(matching_precedence))
    {
    goto end; //Numeric
    }
    }

    // v1_flow_schema_spec->priority_level_configuration
    cJSON *priority_level_configuration = cJSON_GetObjectItemCaseSensitive(v1_flow_schema_specJSON, "priorityLevelConfiguration");
    if (cJSON_IsNull(priority_level_configuration)) {
        priority_level_configuration = NULL;
    }
    if (!priority_level_configuration) {
        goto end;
    }

    
    priority_level_configuration_local_nonprim = v1_priority_level_configuration_reference_parseFromJSON(priority_level_configuration); //nonprimitive

    // v1_flow_schema_spec->rules
    cJSON *rules = cJSON_GetObjectItemCaseSensitive(v1_flow_schema_specJSON, "rules");
    if (cJSON_IsNull(rules)) {
        rules = NULL;
    }
    if (rules) { 
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
        v1_policy_rules_with_subjects_t *rulesItem = v1_policy_rules_with_subjects_parseFromJSON(rules_local_nonprimitive);

        list_addElement(rulesList, rulesItem);
    }
    }


    v1_flow_schema_spec_local_var = v1_flow_schema_spec_create_internal (
        distinguisher_method ? distinguisher_method_local_nonprim : NULL,
        matching_precedence ? matching_precedence->valuedouble : 0,
        priority_level_configuration_local_nonprim,
        rules ? rulesList : NULL
        );

    return v1_flow_schema_spec_local_var;
end:
    if (distinguisher_method_local_nonprim) {
        v1_flow_distinguisher_method_free(distinguisher_method_local_nonprim);
        distinguisher_method_local_nonprim = NULL;
    }
    if (priority_level_configuration_local_nonprim) {
        v1_priority_level_configuration_reference_free(priority_level_configuration_local_nonprim);
        priority_level_configuration_local_nonprim = NULL;
    }
    if (rulesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, rulesList) {
            v1_policy_rules_with_subjects_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(rulesList);
        rulesList = NULL;
    }
    return NULL;

}
