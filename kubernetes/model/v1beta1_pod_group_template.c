#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_pod_group_template.h"



static v1beta1_pod_group_template_t *v1beta1_pod_group_template_create_internal(
    v1beta1_disruption_mode_t *disruption_mode,
    char *name,
    char *preemption_policy,
    int *priority,
    char *priority_class_name,
    list_t *resource_claims,
    v1beta1_pod_group_scheduling_constraints_t *scheduling_constraints,
    v1beta1_pod_group_scheduling_policy_t *scheduling_policy
    ) {
    v1beta1_pod_group_template_t *v1beta1_pod_group_template_local_var = malloc(sizeof(v1beta1_pod_group_template_t));
    if (!v1beta1_pod_group_template_local_var) {
        return NULL;
    }
    memset(v1beta1_pod_group_template_local_var, 0, sizeof(v1beta1_pod_group_template_t));
    v1beta1_pod_group_template_local_var->_library_owned = 1;
    v1beta1_pod_group_template_local_var->disruption_mode = disruption_mode;
    v1beta1_pod_group_template_local_var->name = name;
    v1beta1_pod_group_template_local_var->preemption_policy = preemption_policy;
    v1beta1_pod_group_template_local_var->priority = priority;
    v1beta1_pod_group_template_local_var->priority_class_name = priority_class_name;
    v1beta1_pod_group_template_local_var->resource_claims = resource_claims;
    v1beta1_pod_group_template_local_var->scheduling_constraints = scheduling_constraints;
    v1beta1_pod_group_template_local_var->scheduling_policy = scheduling_policy;
    return v1beta1_pod_group_template_local_var;
}

__attribute__((deprecated)) v1beta1_pod_group_template_t *v1beta1_pod_group_template_create(
    v1beta1_disruption_mode_t *disruption_mode,
    char *name,
    char *preemption_policy,
    int *priority,
    char *priority_class_name,
    list_t *resource_claims,
    v1beta1_pod_group_scheduling_constraints_t *scheduling_constraints,
    v1beta1_pod_group_scheduling_policy_t *scheduling_policy
    ) {
    int *priority_copy = NULL;
    if (priority) {
        priority_copy = malloc(sizeof(int));
        if (priority_copy) *priority_copy = *priority;
    }
    v1beta1_pod_group_template_t *result = v1beta1_pod_group_template_create_internal (
        disruption_mode,
        name,
        preemption_policy,
        priority_copy,
        priority_class_name,
        resource_claims,
        scheduling_constraints,
        scheduling_policy
        );
    if (!result) {
        free(priority_copy);
    }
    return result;
}

void v1beta1_pod_group_template_free(v1beta1_pod_group_template_t *v1beta1_pod_group_template) {
    if(NULL == v1beta1_pod_group_template){
        return ;
    }
    if(v1beta1_pod_group_template->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta1_pod_group_template_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_pod_group_template->disruption_mode) {
        v1beta1_disruption_mode_free(v1beta1_pod_group_template->disruption_mode);
        v1beta1_pod_group_template->disruption_mode = NULL;
    }
    if (v1beta1_pod_group_template->name) {
        free(v1beta1_pod_group_template->name);
        v1beta1_pod_group_template->name = NULL;
    }
    if (v1beta1_pod_group_template->preemption_policy) {
        free(v1beta1_pod_group_template->preemption_policy);
        v1beta1_pod_group_template->preemption_policy = NULL;
    }
    if (v1beta1_pod_group_template->priority) {
        free(v1beta1_pod_group_template->priority);
        v1beta1_pod_group_template->priority = NULL;
    }
    if (v1beta1_pod_group_template->priority_class_name) {
        free(v1beta1_pod_group_template->priority_class_name);
        v1beta1_pod_group_template->priority_class_name = NULL;
    }
    if (v1beta1_pod_group_template->resource_claims) {
        list_ForEach(listEntry, v1beta1_pod_group_template->resource_claims) {
            v1beta1_pod_group_resource_claim_free(listEntry->data);
        }
        list_freeList(v1beta1_pod_group_template->resource_claims);
        v1beta1_pod_group_template->resource_claims = NULL;
    }
    if (v1beta1_pod_group_template->scheduling_constraints) {
        v1beta1_pod_group_scheduling_constraints_free(v1beta1_pod_group_template->scheduling_constraints);
        v1beta1_pod_group_template->scheduling_constraints = NULL;
    }
    if (v1beta1_pod_group_template->scheduling_policy) {
        v1beta1_pod_group_scheduling_policy_free(v1beta1_pod_group_template->scheduling_policy);
        v1beta1_pod_group_template->scheduling_policy = NULL;
    }
    free(v1beta1_pod_group_template);
}

cJSON *v1beta1_pod_group_template_convertToJSON(v1beta1_pod_group_template_t *v1beta1_pod_group_template) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_pod_group_template->disruption_mode
    if(v1beta1_pod_group_template->disruption_mode) {
    cJSON *disruption_mode_local_JSON = v1beta1_disruption_mode_convertToJSON(v1beta1_pod_group_template->disruption_mode);
    if(disruption_mode_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "disruptionMode", disruption_mode_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta1_pod_group_template->name
    if (!v1beta1_pod_group_template->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1beta1_pod_group_template->name) == NULL) {
    goto fail; //String
    }


    // v1beta1_pod_group_template->preemption_policy
    if(v1beta1_pod_group_template->preemption_policy) {
    if(cJSON_AddStringToObject(item, "preemptionPolicy", v1beta1_pod_group_template->preemption_policy) == NULL) {
    goto fail; //String
    }
    }


    // v1beta1_pod_group_template->priority
    if(v1beta1_pod_group_template->priority) {
    if(cJSON_AddNumberToObject(item, "priority", *v1beta1_pod_group_template->priority) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1beta1_pod_group_template->priority_class_name
    if(v1beta1_pod_group_template->priority_class_name) {
    if(cJSON_AddStringToObject(item, "priorityClassName", v1beta1_pod_group_template->priority_class_name) == NULL) {
    goto fail; //String
    }
    }


    // v1beta1_pod_group_template->resource_claims
    if(v1beta1_pod_group_template->resource_claims) {
    cJSON *resource_claims = cJSON_AddArrayToObject(item, "resourceClaims");
    if(resource_claims == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resource_claimsListEntry;
    if (v1beta1_pod_group_template->resource_claims) {
    list_ForEach(resource_claimsListEntry, v1beta1_pod_group_template->resource_claims) {
    cJSON *itemLocal = v1beta1_pod_group_resource_claim_convertToJSON(resource_claimsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(resource_claims, itemLocal);
    }
    }
    }


    // v1beta1_pod_group_template->scheduling_constraints
    if(v1beta1_pod_group_template->scheduling_constraints) {
    cJSON *scheduling_constraints_local_JSON = v1beta1_pod_group_scheduling_constraints_convertToJSON(v1beta1_pod_group_template->scheduling_constraints);
    if(scheduling_constraints_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "schedulingConstraints", scheduling_constraints_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta1_pod_group_template->scheduling_policy
    if (!v1beta1_pod_group_template->scheduling_policy) {
        goto fail;
    }
    cJSON *scheduling_policy_local_JSON = v1beta1_pod_group_scheduling_policy_convertToJSON(v1beta1_pod_group_template->scheduling_policy);
    if(scheduling_policy_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "schedulingPolicy", scheduling_policy_local_JSON);
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

v1beta1_pod_group_template_t *v1beta1_pod_group_template_parseFromJSON(cJSON *v1beta1_pod_group_templateJSON){

    v1beta1_pod_group_template_t *v1beta1_pod_group_template_local_var = NULL;

    // define the local variable for v1beta1_pod_group_template->disruption_mode
    v1beta1_disruption_mode_t *disruption_mode_local_nonprim = NULL;

    char *name_local_str = NULL;

    char *preemption_policy_local_str = NULL;

    // define the local variable for v1beta1_pod_group_template->priority
    int *priority_local_var = NULL;

    char *priority_class_name_local_str = NULL;

    // define the local list for v1beta1_pod_group_template->resource_claims
    list_t *resource_claimsList = NULL;

    // define the local variable for v1beta1_pod_group_template->scheduling_constraints
    v1beta1_pod_group_scheduling_constraints_t *scheduling_constraints_local_nonprim = NULL;

    // define the local variable for v1beta1_pod_group_template->scheduling_policy
    v1beta1_pod_group_scheduling_policy_t *scheduling_policy_local_nonprim = NULL;

    // v1beta1_pod_group_template->disruption_mode
    cJSON *disruption_mode = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_group_templateJSON, "disruptionMode");
    if (cJSON_IsNull(disruption_mode)) {
        disruption_mode = NULL;
    }
    if (disruption_mode) { 
    disruption_mode_local_nonprim = v1beta1_disruption_mode_parseFromJSON(disruption_mode); //nonprimitive
    }

    // v1beta1_pod_group_template->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_group_templateJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1beta1_pod_group_template->preemption_policy
    cJSON *preemption_policy = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_group_templateJSON, "preemptionPolicy");
    if (cJSON_IsNull(preemption_policy)) {
        preemption_policy = NULL;
    }
    if (preemption_policy) { 
    if(!cJSON_IsString(preemption_policy) && !cJSON_IsNull(preemption_policy))
    {
    goto end; //String
    }
    }

    // v1beta1_pod_group_template->priority
    cJSON *priority = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_group_templateJSON, "priority");
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

    // v1beta1_pod_group_template->priority_class_name
    cJSON *priority_class_name = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_group_templateJSON, "priorityClassName");
    if (cJSON_IsNull(priority_class_name)) {
        priority_class_name = NULL;
    }
    if (priority_class_name) { 
    if(!cJSON_IsString(priority_class_name) && !cJSON_IsNull(priority_class_name))
    {
    goto end; //String
    }
    }

    // v1beta1_pod_group_template->resource_claims
    cJSON *resource_claims = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_group_templateJSON, "resourceClaims");
    if (cJSON_IsNull(resource_claims)) {
        resource_claims = NULL;
    }
    if (resource_claims) { 
    cJSON *resource_claims_local_nonprimitive = NULL;
    if(!cJSON_IsArray(resource_claims)){
        goto end; //nonprimitive container
    }

    resource_claimsList = list_createList();

    cJSON_ArrayForEach(resource_claims_local_nonprimitive,resource_claims )
    {
        if(!cJSON_IsObject(resource_claims_local_nonprimitive)){
            goto end;
        }
        v1beta1_pod_group_resource_claim_t *resource_claimsItem = v1beta1_pod_group_resource_claim_parseFromJSON(resource_claims_local_nonprimitive);

        list_addElement(resource_claimsList, resource_claimsItem);
    }
    }

    // v1beta1_pod_group_template->scheduling_constraints
    cJSON *scheduling_constraints = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_group_templateJSON, "schedulingConstraints");
    if (cJSON_IsNull(scheduling_constraints)) {
        scheduling_constraints = NULL;
    }
    if (scheduling_constraints) { 
    scheduling_constraints_local_nonprim = v1beta1_pod_group_scheduling_constraints_parseFromJSON(scheduling_constraints); //nonprimitive
    }

    // v1beta1_pod_group_template->scheduling_policy
    cJSON *scheduling_policy = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_group_templateJSON, "schedulingPolicy");
    if (cJSON_IsNull(scheduling_policy)) {
        scheduling_policy = NULL;
    }
    if (!scheduling_policy) {
        goto end;
    }

    
    scheduling_policy_local_nonprim = v1beta1_pod_group_scheduling_policy_parseFromJSON(scheduling_policy); //nonprimitive


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (preemption_policy && !cJSON_IsNull(preemption_policy)) preemption_policy_local_str = strdup(preemption_policy->valuestring);
    if (priority_class_name && !cJSON_IsNull(priority_class_name)) priority_class_name_local_str = strdup(priority_class_name->valuestring);

    v1beta1_pod_group_template_local_var = v1beta1_pod_group_template_create_internal (
        disruption_mode ? disruption_mode_local_nonprim : NULL,
        name_local_str,
        preemption_policy_local_str,
        priority_local_var,
        priority_class_name_local_str,
        resource_claims ? resource_claimsList : NULL,
        scheduling_constraints ? scheduling_constraints_local_nonprim : NULL,
        scheduling_policy_local_nonprim
        );

    if (!v1beta1_pod_group_template_local_var) {
        goto end;
    }

    return v1beta1_pod_group_template_local_var;
end:
    if (disruption_mode_local_nonprim) {
        v1beta1_disruption_mode_free(disruption_mode_local_nonprim);
        disruption_mode_local_nonprim = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
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
    if (resource_claimsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resource_claimsList) {
            v1beta1_pod_group_resource_claim_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resource_claimsList);
        resource_claimsList = NULL;
    }
    if (scheduling_constraints_local_nonprim) {
        v1beta1_pod_group_scheduling_constraints_free(scheduling_constraints_local_nonprim);
        scheduling_constraints_local_nonprim = NULL;
    }
    if (scheduling_policy_local_nonprim) {
        v1beta1_pod_group_scheduling_policy_free(scheduling_policy_local_nonprim);
        scheduling_policy_local_nonprim = NULL;
    }
    return NULL;

}
