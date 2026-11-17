#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_job_scheduling_configuration.h"



static v1_job_scheduling_configuration_t *v1_job_scheduling_configuration_create_internal(
    v1alpha3_workload_pod_group_disruption_mode_t *disruption_mode,
    list_t *resource_claims,
    v1alpha3_workload_pod_group_scheduling_constraints_t *scheduling_constraints,
    v1alpha3_workload_pod_group_scheduling_policy_t *scheduling_policy
    ) {
    v1_job_scheduling_configuration_t *v1_job_scheduling_configuration_local_var = malloc(sizeof(v1_job_scheduling_configuration_t));
    if (!v1_job_scheduling_configuration_local_var) {
        return NULL;
    }
    memset(v1_job_scheduling_configuration_local_var, 0, sizeof(v1_job_scheduling_configuration_t));
    v1_job_scheduling_configuration_local_var->_library_owned = 1;
    v1_job_scheduling_configuration_local_var->disruption_mode = disruption_mode;
    v1_job_scheduling_configuration_local_var->resource_claims = resource_claims;
    v1_job_scheduling_configuration_local_var->scheduling_constraints = scheduling_constraints;
    v1_job_scheduling_configuration_local_var->scheduling_policy = scheduling_policy;
    return v1_job_scheduling_configuration_local_var;
}

__attribute__((deprecated)) v1_job_scheduling_configuration_t *v1_job_scheduling_configuration_create(
    v1alpha3_workload_pod_group_disruption_mode_t *disruption_mode,
    list_t *resource_claims,
    v1alpha3_workload_pod_group_scheduling_constraints_t *scheduling_constraints,
    v1alpha3_workload_pod_group_scheduling_policy_t *scheduling_policy
    ) {
    v1_job_scheduling_configuration_t *result = v1_job_scheduling_configuration_create_internal (
        disruption_mode,
        resource_claims,
        scheduling_constraints,
        scheduling_policy
        );
    if (!result) {
    }
    return result;
}

void v1_job_scheduling_configuration_free(v1_job_scheduling_configuration_t *v1_job_scheduling_configuration) {
    if(NULL == v1_job_scheduling_configuration){
        return ;
    }
    if(v1_job_scheduling_configuration->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_job_scheduling_configuration_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_job_scheduling_configuration->disruption_mode) {
        v1alpha3_workload_pod_group_disruption_mode_free(v1_job_scheduling_configuration->disruption_mode);
        v1_job_scheduling_configuration->disruption_mode = NULL;
    }
    if (v1_job_scheduling_configuration->resource_claims) {
        list_ForEach(listEntry, v1_job_scheduling_configuration->resource_claims) {
            v1alpha3_workload_pod_group_resource_claim_free(listEntry->data);
        }
        list_freeList(v1_job_scheduling_configuration->resource_claims);
        v1_job_scheduling_configuration->resource_claims = NULL;
    }
    if (v1_job_scheduling_configuration->scheduling_constraints) {
        v1alpha3_workload_pod_group_scheduling_constraints_free(v1_job_scheduling_configuration->scheduling_constraints);
        v1_job_scheduling_configuration->scheduling_constraints = NULL;
    }
    if (v1_job_scheduling_configuration->scheduling_policy) {
        v1alpha3_workload_pod_group_scheduling_policy_free(v1_job_scheduling_configuration->scheduling_policy);
        v1_job_scheduling_configuration->scheduling_policy = NULL;
    }
    free(v1_job_scheduling_configuration);
}

cJSON *v1_job_scheduling_configuration_convertToJSON(v1_job_scheduling_configuration_t *v1_job_scheduling_configuration) {
    cJSON *item = cJSON_CreateObject();

    // v1_job_scheduling_configuration->disruption_mode
    if(v1_job_scheduling_configuration->disruption_mode) {
    cJSON *disruption_mode_local_JSON = v1alpha3_workload_pod_group_disruption_mode_convertToJSON(v1_job_scheduling_configuration->disruption_mode);
    if(disruption_mode_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "disruptionMode", disruption_mode_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_job_scheduling_configuration->resource_claims
    if(v1_job_scheduling_configuration->resource_claims) {
    cJSON *resource_claims = cJSON_AddArrayToObject(item, "resourceClaims");
    if(resource_claims == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resource_claimsListEntry;
    if (v1_job_scheduling_configuration->resource_claims) {
    list_ForEach(resource_claimsListEntry, v1_job_scheduling_configuration->resource_claims) {
    cJSON *itemLocal = v1alpha3_workload_pod_group_resource_claim_convertToJSON(resource_claimsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(resource_claims, itemLocal);
    }
    }
    }


    // v1_job_scheduling_configuration->scheduling_constraints
    if(v1_job_scheduling_configuration->scheduling_constraints) {
    cJSON *scheduling_constraints_local_JSON = v1alpha3_workload_pod_group_scheduling_constraints_convertToJSON(v1_job_scheduling_configuration->scheduling_constraints);
    if(scheduling_constraints_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "schedulingConstraints", scheduling_constraints_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_job_scheduling_configuration->scheduling_policy
    if(v1_job_scheduling_configuration->scheduling_policy) {
    cJSON *scheduling_policy_local_JSON = v1alpha3_workload_pod_group_scheduling_policy_convertToJSON(v1_job_scheduling_configuration->scheduling_policy);
    if(scheduling_policy_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "schedulingPolicy", scheduling_policy_local_JSON);
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

v1_job_scheduling_configuration_t *v1_job_scheduling_configuration_parseFromJSON(cJSON *v1_job_scheduling_configurationJSON){

    v1_job_scheduling_configuration_t *v1_job_scheduling_configuration_local_var = NULL;

    // define the local variable for v1_job_scheduling_configuration->disruption_mode
    v1alpha3_workload_pod_group_disruption_mode_t *disruption_mode_local_nonprim = NULL;

    // define the local list for v1_job_scheduling_configuration->resource_claims
    list_t *resource_claimsList = NULL;

    // define the local variable for v1_job_scheduling_configuration->scheduling_constraints
    v1alpha3_workload_pod_group_scheduling_constraints_t *scheduling_constraints_local_nonprim = NULL;

    // define the local variable for v1_job_scheduling_configuration->scheduling_policy
    v1alpha3_workload_pod_group_scheduling_policy_t *scheduling_policy_local_nonprim = NULL;

    // v1_job_scheduling_configuration->disruption_mode
    cJSON *disruption_mode = cJSON_GetObjectItemCaseSensitive(v1_job_scheduling_configurationJSON, "disruptionMode");
    if (cJSON_IsNull(disruption_mode)) {
        disruption_mode = NULL;
    }
    if (disruption_mode) { 
    disruption_mode_local_nonprim = v1alpha3_workload_pod_group_disruption_mode_parseFromJSON(disruption_mode); //nonprimitive
    }

    // v1_job_scheduling_configuration->resource_claims
    cJSON *resource_claims = cJSON_GetObjectItemCaseSensitive(v1_job_scheduling_configurationJSON, "resourceClaims");
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
        v1alpha3_workload_pod_group_resource_claim_t *resource_claimsItem = v1alpha3_workload_pod_group_resource_claim_parseFromJSON(resource_claims_local_nonprimitive);

        list_addElement(resource_claimsList, resource_claimsItem);
    }
    }

    // v1_job_scheduling_configuration->scheduling_constraints
    cJSON *scheduling_constraints = cJSON_GetObjectItemCaseSensitive(v1_job_scheduling_configurationJSON, "schedulingConstraints");
    if (cJSON_IsNull(scheduling_constraints)) {
        scheduling_constraints = NULL;
    }
    if (scheduling_constraints) { 
    scheduling_constraints_local_nonprim = v1alpha3_workload_pod_group_scheduling_constraints_parseFromJSON(scheduling_constraints); //nonprimitive
    }

    // v1_job_scheduling_configuration->scheduling_policy
    cJSON *scheduling_policy = cJSON_GetObjectItemCaseSensitive(v1_job_scheduling_configurationJSON, "schedulingPolicy");
    if (cJSON_IsNull(scheduling_policy)) {
        scheduling_policy = NULL;
    }
    if (scheduling_policy) { 
    scheduling_policy_local_nonprim = v1alpha3_workload_pod_group_scheduling_policy_parseFromJSON(scheduling_policy); //nonprimitive
    }



    v1_job_scheduling_configuration_local_var = v1_job_scheduling_configuration_create_internal (
        disruption_mode ? disruption_mode_local_nonprim : NULL,
        resource_claims ? resource_claimsList : NULL,
        scheduling_constraints ? scheduling_constraints_local_nonprim : NULL,
        scheduling_policy ? scheduling_policy_local_nonprim : NULL
        );

    if (!v1_job_scheduling_configuration_local_var) {
        goto end;
    }

    return v1_job_scheduling_configuration_local_var;
end:
    if (disruption_mode_local_nonprim) {
        v1alpha3_workload_pod_group_disruption_mode_free(disruption_mode_local_nonprim);
        disruption_mode_local_nonprim = NULL;
    }
    if (resource_claimsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resource_claimsList) {
            v1alpha3_workload_pod_group_resource_claim_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resource_claimsList);
        resource_claimsList = NULL;
    }
    if (scheduling_constraints_local_nonprim) {
        v1alpha3_workload_pod_group_scheduling_constraints_free(scheduling_constraints_local_nonprim);
        scheduling_constraints_local_nonprim = NULL;
    }
    if (scheduling_policy_local_nonprim) {
        v1alpha3_workload_pod_group_scheduling_policy_free(scheduling_policy_local_nonprim);
        scheduling_policy_local_nonprim = NULL;
    }
    return NULL;

}
