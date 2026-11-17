#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_composite_pod_group_spec.h"



static v1alpha3_composite_pod_group_spec_t *v1alpha3_composite_pod_group_spec_create_internal(
    v1alpha3_composite_disruption_mode_t *disruption_mode,
    char *parent_composite_pod_group_name,
    char *preemption_policy,
    int *priority,
    char *priority_class_name,
    v1alpha3_composite_pod_group_scheduling_constraints_t *scheduling_constraints,
    v1alpha3_composite_pod_group_scheduling_policy_t *scheduling_policy,
    v1alpha3_workload_reference_t *workload_ref
    ) {
    v1alpha3_composite_pod_group_spec_t *v1alpha3_composite_pod_group_spec_local_var = malloc(sizeof(v1alpha3_composite_pod_group_spec_t));
    if (!v1alpha3_composite_pod_group_spec_local_var) {
        return NULL;
    }
    memset(v1alpha3_composite_pod_group_spec_local_var, 0, sizeof(v1alpha3_composite_pod_group_spec_t));
    v1alpha3_composite_pod_group_spec_local_var->_library_owned = 1;
    v1alpha3_composite_pod_group_spec_local_var->disruption_mode = disruption_mode;
    v1alpha3_composite_pod_group_spec_local_var->parent_composite_pod_group_name = parent_composite_pod_group_name;
    v1alpha3_composite_pod_group_spec_local_var->preemption_policy = preemption_policy;
    v1alpha3_composite_pod_group_spec_local_var->priority = priority;
    v1alpha3_composite_pod_group_spec_local_var->priority_class_name = priority_class_name;
    v1alpha3_composite_pod_group_spec_local_var->scheduling_constraints = scheduling_constraints;
    v1alpha3_composite_pod_group_spec_local_var->scheduling_policy = scheduling_policy;
    v1alpha3_composite_pod_group_spec_local_var->workload_ref = workload_ref;
    return v1alpha3_composite_pod_group_spec_local_var;
}

__attribute__((deprecated)) v1alpha3_composite_pod_group_spec_t *v1alpha3_composite_pod_group_spec_create(
    v1alpha3_composite_disruption_mode_t *disruption_mode,
    char *parent_composite_pod_group_name,
    char *preemption_policy,
    int *priority,
    char *priority_class_name,
    v1alpha3_composite_pod_group_scheduling_constraints_t *scheduling_constraints,
    v1alpha3_composite_pod_group_scheduling_policy_t *scheduling_policy,
    v1alpha3_workload_reference_t *workload_ref
    ) {
    int *priority_copy = NULL;
    if (priority) {
        priority_copy = malloc(sizeof(int));
        if (priority_copy) *priority_copy = *priority;
    }
    v1alpha3_composite_pod_group_spec_t *result = v1alpha3_composite_pod_group_spec_create_internal (
        disruption_mode,
        parent_composite_pod_group_name,
        preemption_policy,
        priority_copy,
        priority_class_name,
        scheduling_constraints,
        scheduling_policy,
        workload_ref
        );
    if (!result) {
        free(priority_copy);
    }
    return result;
}

void v1alpha3_composite_pod_group_spec_free(v1alpha3_composite_pod_group_spec_t *v1alpha3_composite_pod_group_spec) {
    if(NULL == v1alpha3_composite_pod_group_spec){
        return ;
    }
    if(v1alpha3_composite_pod_group_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha3_composite_pod_group_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_composite_pod_group_spec->disruption_mode) {
        v1alpha3_composite_disruption_mode_free(v1alpha3_composite_pod_group_spec->disruption_mode);
        v1alpha3_composite_pod_group_spec->disruption_mode = NULL;
    }
    if (v1alpha3_composite_pod_group_spec->parent_composite_pod_group_name) {
        free(v1alpha3_composite_pod_group_spec->parent_composite_pod_group_name);
        v1alpha3_composite_pod_group_spec->parent_composite_pod_group_name = NULL;
    }
    if (v1alpha3_composite_pod_group_spec->preemption_policy) {
        free(v1alpha3_composite_pod_group_spec->preemption_policy);
        v1alpha3_composite_pod_group_spec->preemption_policy = NULL;
    }
    if (v1alpha3_composite_pod_group_spec->priority) {
        free(v1alpha3_composite_pod_group_spec->priority);
        v1alpha3_composite_pod_group_spec->priority = NULL;
    }
    if (v1alpha3_composite_pod_group_spec->priority_class_name) {
        free(v1alpha3_composite_pod_group_spec->priority_class_name);
        v1alpha3_composite_pod_group_spec->priority_class_name = NULL;
    }
    if (v1alpha3_composite_pod_group_spec->scheduling_constraints) {
        v1alpha3_composite_pod_group_scheduling_constraints_free(v1alpha3_composite_pod_group_spec->scheduling_constraints);
        v1alpha3_composite_pod_group_spec->scheduling_constraints = NULL;
    }
    if (v1alpha3_composite_pod_group_spec->scheduling_policy) {
        v1alpha3_composite_pod_group_scheduling_policy_free(v1alpha3_composite_pod_group_spec->scheduling_policy);
        v1alpha3_composite_pod_group_spec->scheduling_policy = NULL;
    }
    if (v1alpha3_composite_pod_group_spec->workload_ref) {
        v1alpha3_workload_reference_free(v1alpha3_composite_pod_group_spec->workload_ref);
        v1alpha3_composite_pod_group_spec->workload_ref = NULL;
    }
    free(v1alpha3_composite_pod_group_spec);
}

cJSON *v1alpha3_composite_pod_group_spec_convertToJSON(v1alpha3_composite_pod_group_spec_t *v1alpha3_composite_pod_group_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_composite_pod_group_spec->disruption_mode
    if(v1alpha3_composite_pod_group_spec->disruption_mode) {
    cJSON *disruption_mode_local_JSON = v1alpha3_composite_disruption_mode_convertToJSON(v1alpha3_composite_pod_group_spec->disruption_mode);
    if(disruption_mode_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "disruptionMode", disruption_mode_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha3_composite_pod_group_spec->parent_composite_pod_group_name
    if(v1alpha3_composite_pod_group_spec->parent_composite_pod_group_name) {
    if(cJSON_AddStringToObject(item, "parentCompositePodGroupName", v1alpha3_composite_pod_group_spec->parent_composite_pod_group_name) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_composite_pod_group_spec->preemption_policy
    if(v1alpha3_composite_pod_group_spec->preemption_policy) {
    if(cJSON_AddStringToObject(item, "preemptionPolicy", v1alpha3_composite_pod_group_spec->preemption_policy) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_composite_pod_group_spec->priority
    if(v1alpha3_composite_pod_group_spec->priority) {
    if(cJSON_AddNumberToObject(item, "priority", *v1alpha3_composite_pod_group_spec->priority) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1alpha3_composite_pod_group_spec->priority_class_name
    if(v1alpha3_composite_pod_group_spec->priority_class_name) {
    if(cJSON_AddStringToObject(item, "priorityClassName", v1alpha3_composite_pod_group_spec->priority_class_name) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_composite_pod_group_spec->scheduling_constraints
    if(v1alpha3_composite_pod_group_spec->scheduling_constraints) {
    cJSON *scheduling_constraints_local_JSON = v1alpha3_composite_pod_group_scheduling_constraints_convertToJSON(v1alpha3_composite_pod_group_spec->scheduling_constraints);
    if(scheduling_constraints_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "schedulingConstraints", scheduling_constraints_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha3_composite_pod_group_spec->scheduling_policy
    if (!v1alpha3_composite_pod_group_spec->scheduling_policy) {
        goto fail;
    }
    cJSON *scheduling_policy_local_JSON = v1alpha3_composite_pod_group_scheduling_policy_convertToJSON(v1alpha3_composite_pod_group_spec->scheduling_policy);
    if(scheduling_policy_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "schedulingPolicy", scheduling_policy_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1alpha3_composite_pod_group_spec->workload_ref
    if (!v1alpha3_composite_pod_group_spec->workload_ref) {
        goto fail;
    }
    cJSON *workload_ref_local_JSON = v1alpha3_workload_reference_convertToJSON(v1alpha3_composite_pod_group_spec->workload_ref);
    if(workload_ref_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "workloadRef", workload_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha3_composite_pod_group_spec_t *v1alpha3_composite_pod_group_spec_parseFromJSON(cJSON *v1alpha3_composite_pod_group_specJSON){

    v1alpha3_composite_pod_group_spec_t *v1alpha3_composite_pod_group_spec_local_var = NULL;

    // define the local variable for v1alpha3_composite_pod_group_spec->disruption_mode
    v1alpha3_composite_disruption_mode_t *disruption_mode_local_nonprim = NULL;

    char *parent_composite_pod_group_name_local_str = NULL;

    char *preemption_policy_local_str = NULL;

    // define the local variable for v1alpha3_composite_pod_group_spec->priority
    int *priority_local_var = NULL;

    char *priority_class_name_local_str = NULL;

    // define the local variable for v1alpha3_composite_pod_group_spec->scheduling_constraints
    v1alpha3_composite_pod_group_scheduling_constraints_t *scheduling_constraints_local_nonprim = NULL;

    // define the local variable for v1alpha3_composite_pod_group_spec->scheduling_policy
    v1alpha3_composite_pod_group_scheduling_policy_t *scheduling_policy_local_nonprim = NULL;

    // define the local variable for v1alpha3_composite_pod_group_spec->workload_ref
    v1alpha3_workload_reference_t *workload_ref_local_nonprim = NULL;

    // v1alpha3_composite_pod_group_spec->disruption_mode
    cJSON *disruption_mode = cJSON_GetObjectItemCaseSensitive(v1alpha3_composite_pod_group_specJSON, "disruptionMode");
    if (cJSON_IsNull(disruption_mode)) {
        disruption_mode = NULL;
    }
    if (disruption_mode) { 
    disruption_mode_local_nonprim = v1alpha3_composite_disruption_mode_parseFromJSON(disruption_mode); //nonprimitive
    }

    // v1alpha3_composite_pod_group_spec->parent_composite_pod_group_name
    cJSON *parent_composite_pod_group_name = cJSON_GetObjectItemCaseSensitive(v1alpha3_composite_pod_group_specJSON, "parentCompositePodGroupName");
    if (cJSON_IsNull(parent_composite_pod_group_name)) {
        parent_composite_pod_group_name = NULL;
    }
    if (parent_composite_pod_group_name) { 
    if(!cJSON_IsString(parent_composite_pod_group_name) && !cJSON_IsNull(parent_composite_pod_group_name))
    {
    goto end; //String
    }
    }

    // v1alpha3_composite_pod_group_spec->preemption_policy
    cJSON *preemption_policy = cJSON_GetObjectItemCaseSensitive(v1alpha3_composite_pod_group_specJSON, "preemptionPolicy");
    if (cJSON_IsNull(preemption_policy)) {
        preemption_policy = NULL;
    }
    if (preemption_policy) { 
    if(!cJSON_IsString(preemption_policy) && !cJSON_IsNull(preemption_policy))
    {
    goto end; //String
    }
    }

    // v1alpha3_composite_pod_group_spec->priority
    cJSON *priority = cJSON_GetObjectItemCaseSensitive(v1alpha3_composite_pod_group_specJSON, "priority");
    if (cJSON_IsNull(priority)) {
        priority = NULL;
    }
    if (priority) { 
    if(!cJSON_IsNumber(priority))
    {
    goto end; //Numeric
    }
    priority_local_var = malloc(sizeof(int));
    if(!priority_local_var)
    {
        goto end;
    }
    *priority_local_var = priority->valuedouble;
    }

    // v1alpha3_composite_pod_group_spec->priority_class_name
    cJSON *priority_class_name = cJSON_GetObjectItemCaseSensitive(v1alpha3_composite_pod_group_specJSON, "priorityClassName");
    if (cJSON_IsNull(priority_class_name)) {
        priority_class_name = NULL;
    }
    if (priority_class_name) { 
    if(!cJSON_IsString(priority_class_name) && !cJSON_IsNull(priority_class_name))
    {
    goto end; //String
    }
    }

    // v1alpha3_composite_pod_group_spec->scheduling_constraints
    cJSON *scheduling_constraints = cJSON_GetObjectItemCaseSensitive(v1alpha3_composite_pod_group_specJSON, "schedulingConstraints");
    if (cJSON_IsNull(scheduling_constraints)) {
        scheduling_constraints = NULL;
    }
    if (scheduling_constraints) { 
    scheduling_constraints_local_nonprim = v1alpha3_composite_pod_group_scheduling_constraints_parseFromJSON(scheduling_constraints); //nonprimitive
    }

    // v1alpha3_composite_pod_group_spec->scheduling_policy
    cJSON *scheduling_policy = cJSON_GetObjectItemCaseSensitive(v1alpha3_composite_pod_group_specJSON, "schedulingPolicy");
    if (cJSON_IsNull(scheduling_policy)) {
        scheduling_policy = NULL;
    }
    if (!scheduling_policy) {
        goto end;
    }

    
    scheduling_policy_local_nonprim = v1alpha3_composite_pod_group_scheduling_policy_parseFromJSON(scheduling_policy); //nonprimitive

    // v1alpha3_composite_pod_group_spec->workload_ref
    cJSON *workload_ref = cJSON_GetObjectItemCaseSensitive(v1alpha3_composite_pod_group_specJSON, "workloadRef");
    if (cJSON_IsNull(workload_ref)) {
        workload_ref = NULL;
    }
    if (!workload_ref) {
        goto end;
    }

    
    workload_ref_local_nonprim = v1alpha3_workload_reference_parseFromJSON(workload_ref); //nonprimitive


    if (parent_composite_pod_group_name && !cJSON_IsNull(parent_composite_pod_group_name)) parent_composite_pod_group_name_local_str = strdup(parent_composite_pod_group_name->valuestring);
    if (preemption_policy && !cJSON_IsNull(preemption_policy)) preemption_policy_local_str = strdup(preemption_policy->valuestring);
    if (priority_class_name && !cJSON_IsNull(priority_class_name)) priority_class_name_local_str = strdup(priority_class_name->valuestring);

    v1alpha3_composite_pod_group_spec_local_var = v1alpha3_composite_pod_group_spec_create_internal (
        disruption_mode ? disruption_mode_local_nonprim : NULL,
        parent_composite_pod_group_name_local_str,
        preemption_policy_local_str,
        priority_local_var,
        priority_class_name_local_str,
        scheduling_constraints ? scheduling_constraints_local_nonprim : NULL,
        scheduling_policy_local_nonprim,
        workload_ref_local_nonprim
        );

    if (!v1alpha3_composite_pod_group_spec_local_var) {
        goto end;
    }

    return v1alpha3_composite_pod_group_spec_local_var;
end:
    if (disruption_mode_local_nonprim) {
        v1alpha3_composite_disruption_mode_free(disruption_mode_local_nonprim);
        disruption_mode_local_nonprim = NULL;
    }
    if (parent_composite_pod_group_name_local_str) {
        free(parent_composite_pod_group_name_local_str);
        parent_composite_pod_group_name_local_str = NULL;
    }
    if (preemption_policy_local_str) {
        free(preemption_policy_local_str);
        preemption_policy_local_str = NULL;
    }
    if (priority_local_var) {
        free(priority_local_var);
        priority_local_var = NULL;
    }
    if (priority_class_name_local_str) {
        free(priority_class_name_local_str);
        priority_class_name_local_str = NULL;
    }
    if (scheduling_constraints_local_nonprim) {
        v1alpha3_composite_pod_group_scheduling_constraints_free(scheduling_constraints_local_nonprim);
        scheduling_constraints_local_nonprim = NULL;
    }
    if (scheduling_policy_local_nonprim) {
        v1alpha3_composite_pod_group_scheduling_policy_free(scheduling_policy_local_nonprim);
        scheduling_policy_local_nonprim = NULL;
    }
    if (workload_ref_local_nonprim) {
        v1alpha3_workload_reference_free(workload_ref_local_nonprim);
        workload_ref_local_nonprim = NULL;
    }
    return NULL;

}
