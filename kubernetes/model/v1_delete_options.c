#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_delete_options.h"



static v1_delete_options_t *v1_delete_options_create_internal(
    char *api_version,
    list_t *dry_run,
    long *grace_period_seconds,
    int *ignore_store_read_error_with_cluster_breaking_potential,
    char *kind,
    int *orphan_dependents,
    v1_preconditions_t *preconditions,
    char *propagation_policy
    ) {
    v1_delete_options_t *v1_delete_options_local_var = malloc(sizeof(v1_delete_options_t));
    if (!v1_delete_options_local_var) {
        return NULL;
    }
    memset(v1_delete_options_local_var, 0, sizeof(v1_delete_options_t));
    v1_delete_options_local_var->_library_owned = 1;
    v1_delete_options_local_var->api_version = api_version;
    v1_delete_options_local_var->dry_run = dry_run;
    v1_delete_options_local_var->grace_period_seconds = grace_period_seconds;
    v1_delete_options_local_var->ignore_store_read_error_with_cluster_breaking_potential = ignore_store_read_error_with_cluster_breaking_potential;
    v1_delete_options_local_var->kind = kind;
    v1_delete_options_local_var->orphan_dependents = orphan_dependents;
    v1_delete_options_local_var->preconditions = preconditions;
    v1_delete_options_local_var->propagation_policy = propagation_policy;
    return v1_delete_options_local_var;
}

__attribute__((deprecated)) v1_delete_options_t *v1_delete_options_create(
    char *api_version,
    list_t *dry_run,
    long *grace_period_seconds,
    int *ignore_store_read_error_with_cluster_breaking_potential,
    char *kind,
    int *orphan_dependents,
    v1_preconditions_t *preconditions,
    char *propagation_policy
    ) {
    long *grace_period_seconds_copy = NULL;
    if (grace_period_seconds) {
        grace_period_seconds_copy = malloc(sizeof(long));
        if (grace_period_seconds_copy) *grace_period_seconds_copy = *grace_period_seconds;
    }
    int *ignore_store_read_error_with_cluster_breaking_potential_copy = NULL;
    if (ignore_store_read_error_with_cluster_breaking_potential) {
        ignore_store_read_error_with_cluster_breaking_potential_copy = malloc(sizeof(int));
        if (ignore_store_read_error_with_cluster_breaking_potential_copy) *ignore_store_read_error_with_cluster_breaking_potential_copy = *ignore_store_read_error_with_cluster_breaking_potential;
    }
    int *orphan_dependents_copy = NULL;
    if (orphan_dependents) {
        orphan_dependents_copy = malloc(sizeof(int));
        if (orphan_dependents_copy) *orphan_dependents_copy = *orphan_dependents;
    }
    v1_delete_options_t *result = v1_delete_options_create_internal (
        api_version,
        dry_run,
        grace_period_seconds_copy,
        ignore_store_read_error_with_cluster_breaking_potential_copy,
        kind,
        orphan_dependents_copy,
        preconditions,
        propagation_policy
        );
    if (!result) {
        free(grace_period_seconds_copy);
        free(ignore_store_read_error_with_cluster_breaking_potential_copy);
        free(orphan_dependents_copy);
    }
    return result;
}

void v1_delete_options_free(v1_delete_options_t *v1_delete_options) {
    if(NULL == v1_delete_options){
        return ;
    }
    if(v1_delete_options->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_delete_options_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_delete_options->api_version) {
        free(v1_delete_options->api_version);
        v1_delete_options->api_version = NULL;
    }
    if (v1_delete_options->dry_run) {
        list_ForEach(listEntry, v1_delete_options->dry_run) {
            free(listEntry->data);
        }
        list_freeList(v1_delete_options->dry_run);
        v1_delete_options->dry_run = NULL;
    }
    if (v1_delete_options->grace_period_seconds) {
        free(v1_delete_options->grace_period_seconds);
        v1_delete_options->grace_period_seconds = NULL;
    }
    if (v1_delete_options->ignore_store_read_error_with_cluster_breaking_potential) {
        free(v1_delete_options->ignore_store_read_error_with_cluster_breaking_potential);
        v1_delete_options->ignore_store_read_error_with_cluster_breaking_potential = NULL;
    }
    if (v1_delete_options->kind) {
        free(v1_delete_options->kind);
        v1_delete_options->kind = NULL;
    }
    if (v1_delete_options->orphan_dependents) {
        free(v1_delete_options->orphan_dependents);
        v1_delete_options->orphan_dependents = NULL;
    }
    if (v1_delete_options->preconditions) {
        v1_preconditions_free(v1_delete_options->preconditions);
        v1_delete_options->preconditions = NULL;
    }
    if (v1_delete_options->propagation_policy) {
        free(v1_delete_options->propagation_policy);
        v1_delete_options->propagation_policy = NULL;
    }
    free(v1_delete_options);
}

cJSON *v1_delete_options_convertToJSON(v1_delete_options_t *v1_delete_options) {
    cJSON *item = cJSON_CreateObject();

    // v1_delete_options->api_version
    if(v1_delete_options->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_delete_options->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_delete_options->dry_run
    if(v1_delete_options->dry_run) {
    cJSON *dry_run = cJSON_AddArrayToObject(item, "dryRun");
    if(dry_run == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *dry_runListEntry;
    list_ForEach(dry_runListEntry, v1_delete_options->dry_run) {
    if(cJSON_AddStringToObject(dry_run, "", dry_runListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_delete_options->grace_period_seconds
    if(v1_delete_options->grace_period_seconds) {
    if(cJSON_AddNumberToObject(item, "gracePeriodSeconds", *v1_delete_options->grace_period_seconds) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_delete_options->ignore_store_read_error_with_cluster_breaking_potential
    if(v1_delete_options->ignore_store_read_error_with_cluster_breaking_potential) {
    if(cJSON_AddBoolToObject(item, "ignoreStoreReadErrorWithClusterBreakingPotential", *v1_delete_options->ignore_store_read_error_with_cluster_breaking_potential) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_delete_options->kind
    if(v1_delete_options->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_delete_options->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_delete_options->orphan_dependents
    if(v1_delete_options->orphan_dependents) {
    if(cJSON_AddBoolToObject(item, "orphanDependents", *v1_delete_options->orphan_dependents) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_delete_options->preconditions
    if(v1_delete_options->preconditions) {
    cJSON *preconditions_local_JSON = v1_preconditions_convertToJSON(v1_delete_options->preconditions);
    if(preconditions_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "preconditions", preconditions_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_delete_options->propagation_policy
    if(v1_delete_options->propagation_policy) {
    if(cJSON_AddStringToObject(item, "propagationPolicy", v1_delete_options->propagation_policy) == NULL) {
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

v1_delete_options_t *v1_delete_options_parseFromJSON(cJSON *v1_delete_optionsJSON){

    v1_delete_options_t *v1_delete_options_local_var = NULL;

    char *api_version_local_str = NULL;

    // define the local list for v1_delete_options->dry_run
    list_t *dry_runList = NULL;

    // define the local variable for v1_delete_options->grace_period_seconds
    long *grace_period_seconds_local_var = NULL;

    // define the local variable for v1_delete_options->ignore_store_read_error_with_cluster_breaking_potential
    int *ignore_store_read_error_with_cluster_breaking_potential_local_var = NULL;

    char *kind_local_str = NULL;

    // define the local variable for v1_delete_options->orphan_dependents
    int *orphan_dependents_local_var = NULL;

    // define the local variable for v1_delete_options->preconditions
    v1_preconditions_t *preconditions_local_nonprim = NULL;

    char *propagation_policy_local_str = NULL;

    // v1_delete_options->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_delete_optionsJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_delete_options->dry_run
    cJSON *dry_run = cJSON_GetObjectItemCaseSensitive(v1_delete_optionsJSON, "dryRun");
    if (cJSON_IsNull(dry_run)) {
        dry_run = NULL;
    }
    if (dry_run) { 
    cJSON *dry_run_local = NULL;
    if(!cJSON_IsArray(dry_run)) {
        goto end;//primitive container
    }
    dry_runList = list_createList();

    cJSON_ArrayForEach(dry_run_local, dry_run)
    {
        if(!cJSON_IsString(dry_run_local))
        {
            goto end;
        }
        list_addElement(dry_runList , strdup(dry_run_local->valuestring));
    }
    }

    // v1_delete_options->grace_period_seconds
    cJSON *grace_period_seconds = cJSON_GetObjectItemCaseSensitive(v1_delete_optionsJSON, "gracePeriodSeconds");
    if (cJSON_IsNull(grace_period_seconds)) {
        grace_period_seconds = NULL;
    }
    if (grace_period_seconds) { 
    if(!cJSON_IsNumber(grace_period_seconds))
    {
    goto end; //Numeric
    }
    grace_period_seconds_local_var = malloc(sizeof(long));
    if(!grace_period_seconds_local_var)
    {
        goto end;
    }
    *grace_period_seconds_local_var = grace_period_seconds->valuedouble;
    }

    // v1_delete_options->ignore_store_read_error_with_cluster_breaking_potential
    cJSON *ignore_store_read_error_with_cluster_breaking_potential = cJSON_GetObjectItemCaseSensitive(v1_delete_optionsJSON, "ignoreStoreReadErrorWithClusterBreakingPotential");
    if (cJSON_IsNull(ignore_store_read_error_with_cluster_breaking_potential)) {
        ignore_store_read_error_with_cluster_breaking_potential = NULL;
    }
    if (ignore_store_read_error_with_cluster_breaking_potential) { 
    if(!cJSON_IsBool(ignore_store_read_error_with_cluster_breaking_potential))
    {
    goto end; //Bool
    }
    ignore_store_read_error_with_cluster_breaking_potential_local_var = malloc(sizeof(int));
    if(!ignore_store_read_error_with_cluster_breaking_potential_local_var)
    {
        goto end;
    }
    *ignore_store_read_error_with_cluster_breaking_potential_local_var = ignore_store_read_error_with_cluster_breaking_potential->valueint;
    }

    // v1_delete_options->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_delete_optionsJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_delete_options->orphan_dependents
    cJSON *orphan_dependents = cJSON_GetObjectItemCaseSensitive(v1_delete_optionsJSON, "orphanDependents");
    if (cJSON_IsNull(orphan_dependents)) {
        orphan_dependents = NULL;
    }
    if (orphan_dependents) { 
    if(!cJSON_IsBool(orphan_dependents))
    {
    goto end; //Bool
    }
    orphan_dependents_local_var = malloc(sizeof(int));
    if(!orphan_dependents_local_var)
    {
        goto end;
    }
    *orphan_dependents_local_var = orphan_dependents->valueint;
    }

    // v1_delete_options->preconditions
    cJSON *preconditions = cJSON_GetObjectItemCaseSensitive(v1_delete_optionsJSON, "preconditions");
    if (cJSON_IsNull(preconditions)) {
        preconditions = NULL;
    }
    if (preconditions) { 
    preconditions_local_nonprim = v1_preconditions_parseFromJSON(preconditions); //nonprimitive
    }

    // v1_delete_options->propagation_policy
    cJSON *propagation_policy = cJSON_GetObjectItemCaseSensitive(v1_delete_optionsJSON, "propagationPolicy");
    if (cJSON_IsNull(propagation_policy)) {
        propagation_policy = NULL;
    }
    if (propagation_policy) { 
    if(!cJSON_IsString(propagation_policy) && !cJSON_IsNull(propagation_policy))
    {
    goto end; //String
    }
    }


    if (api_version && !cJSON_IsNull(api_version)) api_version_local_str = strdup(api_version->valuestring);
    if (kind && !cJSON_IsNull(kind)) kind_local_str = strdup(kind->valuestring);
    if (propagation_policy && !cJSON_IsNull(propagation_policy)) propagation_policy_local_str = strdup(propagation_policy->valuestring);

    v1_delete_options_local_var = v1_delete_options_create_internal (
        api_version_local_str,
        dry_run ? dry_runList : NULL,
        grace_period_seconds_local_var,
        ignore_store_read_error_with_cluster_breaking_potential_local_var,
        kind_local_str,
        orphan_dependents_local_var,
        preconditions ? preconditions_local_nonprim : NULL,
        propagation_policy_local_str
        );

    if (!v1_delete_options_local_var) {
        goto end;
    }

    return v1_delete_options_local_var;
end:
    if (api_version_local_str) {
        free(api_version_local_str);
        api_version_local_str = NULL;
    }
    if (dry_runList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, dry_runList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(dry_runList);
        dry_runList = NULL;
    }
    if (grace_period_seconds_local_var) {
        free(grace_period_seconds_local_var);
        grace_period_seconds_local_var = NULL;
    }
    if (ignore_store_read_error_with_cluster_breaking_potential_local_var) {
        free(ignore_store_read_error_with_cluster_breaking_potential_local_var);
        ignore_store_read_error_with_cluster_breaking_potential_local_var = NULL;
    }
    if (kind_local_str) {
        free(kind_local_str);
        kind_local_str = NULL;
    }
    if (orphan_dependents_local_var) {
        free(orphan_dependents_local_var);
        orphan_dependents_local_var = NULL;
    }
    if (preconditions_local_nonprim) {
        v1_preconditions_free(preconditions_local_nonprim);
        preconditions_local_nonprim = NULL;
    }
    if (propagation_policy_local_str) {
        free(propagation_policy_local_str);
        propagation_policy_local_str = NULL;
    }
    return NULL;

}
