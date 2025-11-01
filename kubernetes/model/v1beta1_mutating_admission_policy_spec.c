#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_mutating_admission_policy_spec.h"



static v1beta1_mutating_admission_policy_spec_t *v1beta1_mutating_admission_policy_spec_create_internal(
    char *failure_policy,
    list_t *match_conditions,
    v1beta1_match_resources_t *match_constraints,
    list_t *mutations,
    v1beta1_param_kind_t *param_kind,
    char *reinvocation_policy,
    list_t *variables
    ) {
    v1beta1_mutating_admission_policy_spec_t *v1beta1_mutating_admission_policy_spec_local_var = malloc(sizeof(v1beta1_mutating_admission_policy_spec_t));
    if (!v1beta1_mutating_admission_policy_spec_local_var) {
        return NULL;
    }
    v1beta1_mutating_admission_policy_spec_local_var->failure_policy = failure_policy;
    v1beta1_mutating_admission_policy_spec_local_var->match_conditions = match_conditions;
    v1beta1_mutating_admission_policy_spec_local_var->match_constraints = match_constraints;
    v1beta1_mutating_admission_policy_spec_local_var->mutations = mutations;
    v1beta1_mutating_admission_policy_spec_local_var->param_kind = param_kind;
    v1beta1_mutating_admission_policy_spec_local_var->reinvocation_policy = reinvocation_policy;
    v1beta1_mutating_admission_policy_spec_local_var->variables = variables;

    v1beta1_mutating_admission_policy_spec_local_var->_library_owned = 1;
    return v1beta1_mutating_admission_policy_spec_local_var;
}

__attribute__((deprecated)) v1beta1_mutating_admission_policy_spec_t *v1beta1_mutating_admission_policy_spec_create(
    char *failure_policy,
    list_t *match_conditions,
    v1beta1_match_resources_t *match_constraints,
    list_t *mutations,
    v1beta1_param_kind_t *param_kind,
    char *reinvocation_policy,
    list_t *variables
    ) {
    return v1beta1_mutating_admission_policy_spec_create_internal (
        failure_policy,
        match_conditions,
        match_constraints,
        mutations,
        param_kind,
        reinvocation_policy,
        variables
        );
}

void v1beta1_mutating_admission_policy_spec_free(v1beta1_mutating_admission_policy_spec_t *v1beta1_mutating_admission_policy_spec) {
    if(NULL == v1beta1_mutating_admission_policy_spec){
        return ;
    }
    if(v1beta1_mutating_admission_policy_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta1_mutating_admission_policy_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_mutating_admission_policy_spec->failure_policy) {
        free(v1beta1_mutating_admission_policy_spec->failure_policy);
        v1beta1_mutating_admission_policy_spec->failure_policy = NULL;
    }
    if (v1beta1_mutating_admission_policy_spec->match_conditions) {
        list_ForEach(listEntry, v1beta1_mutating_admission_policy_spec->match_conditions) {
            v1beta1_match_condition_free(listEntry->data);
        }
        list_freeList(v1beta1_mutating_admission_policy_spec->match_conditions);
        v1beta1_mutating_admission_policy_spec->match_conditions = NULL;
    }
    if (v1beta1_mutating_admission_policy_spec->match_constraints) {
        v1beta1_match_resources_free(v1beta1_mutating_admission_policy_spec->match_constraints);
        v1beta1_mutating_admission_policy_spec->match_constraints = NULL;
    }
    if (v1beta1_mutating_admission_policy_spec->mutations) {
        list_ForEach(listEntry, v1beta1_mutating_admission_policy_spec->mutations) {
            v1beta1_mutation_free(listEntry->data);
        }
        list_freeList(v1beta1_mutating_admission_policy_spec->mutations);
        v1beta1_mutating_admission_policy_spec->mutations = NULL;
    }
    if (v1beta1_mutating_admission_policy_spec->param_kind) {
        v1beta1_param_kind_free(v1beta1_mutating_admission_policy_spec->param_kind);
        v1beta1_mutating_admission_policy_spec->param_kind = NULL;
    }
    if (v1beta1_mutating_admission_policy_spec->reinvocation_policy) {
        free(v1beta1_mutating_admission_policy_spec->reinvocation_policy);
        v1beta1_mutating_admission_policy_spec->reinvocation_policy = NULL;
    }
    if (v1beta1_mutating_admission_policy_spec->variables) {
        list_ForEach(listEntry, v1beta1_mutating_admission_policy_spec->variables) {
            v1beta1_variable_free(listEntry->data);
        }
        list_freeList(v1beta1_mutating_admission_policy_spec->variables);
        v1beta1_mutating_admission_policy_spec->variables = NULL;
    }
    free(v1beta1_mutating_admission_policy_spec);
}

cJSON *v1beta1_mutating_admission_policy_spec_convertToJSON(v1beta1_mutating_admission_policy_spec_t *v1beta1_mutating_admission_policy_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_mutating_admission_policy_spec->failure_policy
    if(v1beta1_mutating_admission_policy_spec->failure_policy) {
    if(cJSON_AddStringToObject(item, "failurePolicy", v1beta1_mutating_admission_policy_spec->failure_policy) == NULL) {
    goto fail; //String
    }
    }


    // v1beta1_mutating_admission_policy_spec->match_conditions
    if(v1beta1_mutating_admission_policy_spec->match_conditions) {
    cJSON *match_conditions = cJSON_AddArrayToObject(item, "matchConditions");
    if(match_conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *match_conditionsListEntry;
    if (v1beta1_mutating_admission_policy_spec->match_conditions) {
    list_ForEach(match_conditionsListEntry, v1beta1_mutating_admission_policy_spec->match_conditions) {
    cJSON *itemLocal = v1beta1_match_condition_convertToJSON(match_conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(match_conditions, itemLocal);
    }
    }
    }


    // v1beta1_mutating_admission_policy_spec->match_constraints
    if(v1beta1_mutating_admission_policy_spec->match_constraints) {
    cJSON *match_constraints_local_JSON = v1beta1_match_resources_convertToJSON(v1beta1_mutating_admission_policy_spec->match_constraints);
    if(match_constraints_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "matchConstraints", match_constraints_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta1_mutating_admission_policy_spec->mutations
    if(v1beta1_mutating_admission_policy_spec->mutations) {
    cJSON *mutations = cJSON_AddArrayToObject(item, "mutations");
    if(mutations == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *mutationsListEntry;
    if (v1beta1_mutating_admission_policy_spec->mutations) {
    list_ForEach(mutationsListEntry, v1beta1_mutating_admission_policy_spec->mutations) {
    cJSON *itemLocal = v1beta1_mutation_convertToJSON(mutationsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(mutations, itemLocal);
    }
    }
    }


    // v1beta1_mutating_admission_policy_spec->param_kind
    if(v1beta1_mutating_admission_policy_spec->param_kind) {
    cJSON *param_kind_local_JSON = v1beta1_param_kind_convertToJSON(v1beta1_mutating_admission_policy_spec->param_kind);
    if(param_kind_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "paramKind", param_kind_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta1_mutating_admission_policy_spec->reinvocation_policy
    if(v1beta1_mutating_admission_policy_spec->reinvocation_policy) {
    if(cJSON_AddStringToObject(item, "reinvocationPolicy", v1beta1_mutating_admission_policy_spec->reinvocation_policy) == NULL) {
    goto fail; //String
    }
    }


    // v1beta1_mutating_admission_policy_spec->variables
    if(v1beta1_mutating_admission_policy_spec->variables) {
    cJSON *variables = cJSON_AddArrayToObject(item, "variables");
    if(variables == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *variablesListEntry;
    if (v1beta1_mutating_admission_policy_spec->variables) {
    list_ForEach(variablesListEntry, v1beta1_mutating_admission_policy_spec->variables) {
    cJSON *itemLocal = v1beta1_variable_convertToJSON(variablesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(variables, itemLocal);
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

v1beta1_mutating_admission_policy_spec_t *v1beta1_mutating_admission_policy_spec_parseFromJSON(cJSON *v1beta1_mutating_admission_policy_specJSON){

    v1beta1_mutating_admission_policy_spec_t *v1beta1_mutating_admission_policy_spec_local_var = NULL;

    // define the local list for v1beta1_mutating_admission_policy_spec->match_conditions
    list_t *match_conditionsList = NULL;

    // define the local variable for v1beta1_mutating_admission_policy_spec->match_constraints
    v1beta1_match_resources_t *match_constraints_local_nonprim = NULL;

    // define the local list for v1beta1_mutating_admission_policy_spec->mutations
    list_t *mutationsList = NULL;

    // define the local variable for v1beta1_mutating_admission_policy_spec->param_kind
    v1beta1_param_kind_t *param_kind_local_nonprim = NULL;

    // define the local list for v1beta1_mutating_admission_policy_spec->variables
    list_t *variablesList = NULL;

    // v1beta1_mutating_admission_policy_spec->failure_policy
    cJSON *failure_policy = cJSON_GetObjectItemCaseSensitive(v1beta1_mutating_admission_policy_specJSON, "failurePolicy");
    if (cJSON_IsNull(failure_policy)) {
        failure_policy = NULL;
    }
    if (failure_policy) { 
    if(!cJSON_IsString(failure_policy) && !cJSON_IsNull(failure_policy))
    {
    goto end; //String
    }
    }

    // v1beta1_mutating_admission_policy_spec->match_conditions
    cJSON *match_conditions = cJSON_GetObjectItemCaseSensitive(v1beta1_mutating_admission_policy_specJSON, "matchConditions");
    if (cJSON_IsNull(match_conditions)) {
        match_conditions = NULL;
    }
    if (match_conditions) { 
    cJSON *match_conditions_local_nonprimitive = NULL;
    if(!cJSON_IsArray(match_conditions)){
        goto end; //nonprimitive container
    }

    match_conditionsList = list_createList();

    cJSON_ArrayForEach(match_conditions_local_nonprimitive,match_conditions )
    {
        if(!cJSON_IsObject(match_conditions_local_nonprimitive)){
            goto end;
        }
        v1beta1_match_condition_t *match_conditionsItem = v1beta1_match_condition_parseFromJSON(match_conditions_local_nonprimitive);

        list_addElement(match_conditionsList, match_conditionsItem);
    }
    }

    // v1beta1_mutating_admission_policy_spec->match_constraints
    cJSON *match_constraints = cJSON_GetObjectItemCaseSensitive(v1beta1_mutating_admission_policy_specJSON, "matchConstraints");
    if (cJSON_IsNull(match_constraints)) {
        match_constraints = NULL;
    }
    if (match_constraints) { 
    match_constraints_local_nonprim = v1beta1_match_resources_parseFromJSON(match_constraints); //nonprimitive
    }

    // v1beta1_mutating_admission_policy_spec->mutations
    cJSON *mutations = cJSON_GetObjectItemCaseSensitive(v1beta1_mutating_admission_policy_specJSON, "mutations");
    if (cJSON_IsNull(mutations)) {
        mutations = NULL;
    }
    if (mutations) { 
    cJSON *mutations_local_nonprimitive = NULL;
    if(!cJSON_IsArray(mutations)){
        goto end; //nonprimitive container
    }

    mutationsList = list_createList();

    cJSON_ArrayForEach(mutations_local_nonprimitive,mutations )
    {
        if(!cJSON_IsObject(mutations_local_nonprimitive)){
            goto end;
        }
        v1beta1_mutation_t *mutationsItem = v1beta1_mutation_parseFromJSON(mutations_local_nonprimitive);

        list_addElement(mutationsList, mutationsItem);
    }
    }

    // v1beta1_mutating_admission_policy_spec->param_kind
    cJSON *param_kind = cJSON_GetObjectItemCaseSensitive(v1beta1_mutating_admission_policy_specJSON, "paramKind");
    if (cJSON_IsNull(param_kind)) {
        param_kind = NULL;
    }
    if (param_kind) { 
    param_kind_local_nonprim = v1beta1_param_kind_parseFromJSON(param_kind); //nonprimitive
    }

    // v1beta1_mutating_admission_policy_spec->reinvocation_policy
    cJSON *reinvocation_policy = cJSON_GetObjectItemCaseSensitive(v1beta1_mutating_admission_policy_specJSON, "reinvocationPolicy");
    if (cJSON_IsNull(reinvocation_policy)) {
        reinvocation_policy = NULL;
    }
    if (reinvocation_policy) { 
    if(!cJSON_IsString(reinvocation_policy) && !cJSON_IsNull(reinvocation_policy))
    {
    goto end; //String
    }
    }

    // v1beta1_mutating_admission_policy_spec->variables
    cJSON *variables = cJSON_GetObjectItemCaseSensitive(v1beta1_mutating_admission_policy_specJSON, "variables");
    if (cJSON_IsNull(variables)) {
        variables = NULL;
    }
    if (variables) { 
    cJSON *variables_local_nonprimitive = NULL;
    if(!cJSON_IsArray(variables)){
        goto end; //nonprimitive container
    }

    variablesList = list_createList();

    cJSON_ArrayForEach(variables_local_nonprimitive,variables )
    {
        if(!cJSON_IsObject(variables_local_nonprimitive)){
            goto end;
        }
        v1beta1_variable_t *variablesItem = v1beta1_variable_parseFromJSON(variables_local_nonprimitive);

        list_addElement(variablesList, variablesItem);
    }
    }


    v1beta1_mutating_admission_policy_spec_local_var = v1beta1_mutating_admission_policy_spec_create_internal (
        failure_policy && !cJSON_IsNull(failure_policy) ? strdup(failure_policy->valuestring) : NULL,
        match_conditions ? match_conditionsList : NULL,
        match_constraints ? match_constraints_local_nonprim : NULL,
        mutations ? mutationsList : NULL,
        param_kind ? param_kind_local_nonprim : NULL,
        reinvocation_policy && !cJSON_IsNull(reinvocation_policy) ? strdup(reinvocation_policy->valuestring) : NULL,
        variables ? variablesList : NULL
        );

    return v1beta1_mutating_admission_policy_spec_local_var;
end:
    if (match_conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, match_conditionsList) {
            v1beta1_match_condition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(match_conditionsList);
        match_conditionsList = NULL;
    }
    if (match_constraints_local_nonprim) {
        v1beta1_match_resources_free(match_constraints_local_nonprim);
        match_constraints_local_nonprim = NULL;
    }
    if (mutationsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, mutationsList) {
            v1beta1_mutation_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(mutationsList);
        mutationsList = NULL;
    }
    if (param_kind_local_nonprim) {
        v1beta1_param_kind_free(param_kind_local_nonprim);
        param_kind_local_nonprim = NULL;
    }
    if (variablesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, variablesList) {
            v1beta1_variable_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(variablesList);
        variablesList = NULL;
    }
    return NULL;

}
