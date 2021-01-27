#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_delete_options.h"



v1_delete_options_t *v1_delete_options_create(
    char *api_version,
    list_t *dry_run,
    long grace_period_seconds,
    char *kind,
    int orphan_dependents,
    v1_preconditions_t *preconditions,
    char *propagation_policy
    ) {
    v1_delete_options_t *v1_delete_options_local_var = malloc(sizeof(v1_delete_options_t));
    if (!v1_delete_options_local_var) {
        return NULL;
    }
    v1_delete_options_local_var->api_version = api_version;
    v1_delete_options_local_var->dry_run = dry_run;
    v1_delete_options_local_var->grace_period_seconds = grace_period_seconds;
    v1_delete_options_local_var->kind = kind;
    v1_delete_options_local_var->orphan_dependents = orphan_dependents;
    v1_delete_options_local_var->preconditions = preconditions;
    v1_delete_options_local_var->propagation_policy = propagation_policy;

    return v1_delete_options_local_var;
}


void v1_delete_options_free(v1_delete_options_t *v1_delete_options) {
    if(NULL == v1_delete_options){
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
        list_free(v1_delete_options->dry_run);
        v1_delete_options->dry_run = NULL;
    }
    if (v1_delete_options->kind) {
        free(v1_delete_options->kind);
        v1_delete_options->kind = NULL;
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
    if(cJSON_AddStringToObject(dry_run, "", (char*)dry_runListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // v1_delete_options->grace_period_seconds
    if(v1_delete_options->grace_period_seconds) { 
    if(cJSON_AddNumberToObject(item, "gracePeriodSeconds", v1_delete_options->grace_period_seconds) == NULL) {
    goto fail; //Numeric
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
    if(cJSON_AddBoolToObject(item, "orphanDependents", v1_delete_options->orphan_dependents) == NULL) {
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

    // v1_delete_options->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_delete_optionsJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v1_delete_options->dry_run
    cJSON *dry_run = cJSON_GetObjectItemCaseSensitive(v1_delete_optionsJSON, "dryRun");
    list_t *dry_runList;
    if (dry_run) { 
    cJSON *dry_run_local;
    if(!cJSON_IsArray(dry_run)) {
        goto end;//primitive container
    }
    dry_runList = list_create();

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
    if (grace_period_seconds) { 
    if(!cJSON_IsNumber(grace_period_seconds))
    {
    goto end; //Numeric
    }
    }

    // v1_delete_options->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_delete_optionsJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_delete_options->orphan_dependents
    cJSON *orphan_dependents = cJSON_GetObjectItemCaseSensitive(v1_delete_optionsJSON, "orphanDependents");
    if (orphan_dependents) { 
    if(!cJSON_IsBool(orphan_dependents))
    {
    goto end; //Bool
    }
    }

    // v1_delete_options->preconditions
    cJSON *preconditions = cJSON_GetObjectItemCaseSensitive(v1_delete_optionsJSON, "preconditions");
    v1_preconditions_t *preconditions_local_nonprim = NULL;
    if (preconditions) { 
    preconditions_local_nonprim = v1_preconditions_parseFromJSON(preconditions); //nonprimitive
    }

    // v1_delete_options->propagation_policy
    cJSON *propagation_policy = cJSON_GetObjectItemCaseSensitive(v1_delete_optionsJSON, "propagationPolicy");
    if (propagation_policy) { 
    if(!cJSON_IsString(propagation_policy))
    {
    goto end; //String
    }
    }


    v1_delete_options_local_var = v1_delete_options_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        dry_run ? dry_runList : NULL,
        grace_period_seconds ? grace_period_seconds->valuedouble : 0,
        kind ? strdup(kind->valuestring) : NULL,
        orphan_dependents ? orphan_dependents->valueint : 0,
        preconditions ? preconditions_local_nonprim : NULL,
        propagation_policy ? strdup(propagation_policy->valuestring) : NULL
        );

    return v1_delete_options_local_var;
end:
    if (preconditions_local_nonprim) {
        v1_preconditions_free(preconditions_local_nonprim);
        preconditions_local_nonprim = NULL;
    }
    return NULL;

}
