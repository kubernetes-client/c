#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_job_spec.h"



static v1_job_spec_t *v1_job_spec_create_internal(
    long *active_deadline_seconds,
    int *backoff_limit,
    int *backoff_limit_per_index,
    char *completion_mode,
    int *completions,
    char *managed_by,
    int *manual_selector,
    int *max_failed_indexes,
    int *parallelism,
    v1_pod_failure_policy_t *pod_failure_policy,
    char *pod_replacement_policy,
    v1_job_scheduling_configuration_t *scheduling,
    v1_label_selector_t *selector,
    v1_success_policy_t *success_policy,
    int *suspend,
    v1_pod_template_spec_t *_template,
    int *ttl_seconds_after_finished
    ) {
    v1_job_spec_t *v1_job_spec_local_var = malloc(sizeof(v1_job_spec_t));
    if (!v1_job_spec_local_var) {
        return NULL;
    }
    memset(v1_job_spec_local_var, 0, sizeof(v1_job_spec_t));
    v1_job_spec_local_var->_library_owned = 1;
    v1_job_spec_local_var->active_deadline_seconds = active_deadline_seconds;
    v1_job_spec_local_var->backoff_limit = backoff_limit;
    v1_job_spec_local_var->backoff_limit_per_index = backoff_limit_per_index;
    v1_job_spec_local_var->completion_mode = completion_mode;
    v1_job_spec_local_var->completions = completions;
    v1_job_spec_local_var->managed_by = managed_by;
    v1_job_spec_local_var->manual_selector = manual_selector;
    v1_job_spec_local_var->max_failed_indexes = max_failed_indexes;
    v1_job_spec_local_var->parallelism = parallelism;
    v1_job_spec_local_var->pod_failure_policy = pod_failure_policy;
    v1_job_spec_local_var->pod_replacement_policy = pod_replacement_policy;
    v1_job_spec_local_var->scheduling = scheduling;
    v1_job_spec_local_var->selector = selector;
    v1_job_spec_local_var->success_policy = success_policy;
    v1_job_spec_local_var->suspend = suspend;
    v1_job_spec_local_var->_template = _template;
    v1_job_spec_local_var->ttl_seconds_after_finished = ttl_seconds_after_finished;
    return v1_job_spec_local_var;
}

__attribute__((deprecated)) v1_job_spec_t *v1_job_spec_create(
    long *active_deadline_seconds,
    int *backoff_limit,
    int *backoff_limit_per_index,
    char *completion_mode,
    int *completions,
    char *managed_by,
    int *manual_selector,
    int *max_failed_indexes,
    int *parallelism,
    v1_pod_failure_policy_t *pod_failure_policy,
    char *pod_replacement_policy,
    v1_job_scheduling_configuration_t *scheduling,
    v1_label_selector_t *selector,
    v1_success_policy_t *success_policy,
    int *suspend,
    v1_pod_template_spec_t *_template,
    int *ttl_seconds_after_finished
    ) {
    long *active_deadline_seconds_copy = NULL;
    if (active_deadline_seconds) {
        active_deadline_seconds_copy = malloc(sizeof(long));
        if (active_deadline_seconds_copy) *active_deadline_seconds_copy = *active_deadline_seconds;
    }
    int *backoff_limit_copy = NULL;
    if (backoff_limit) {
        backoff_limit_copy = malloc(sizeof(int));
        if (backoff_limit_copy) *backoff_limit_copy = *backoff_limit;
    }
    int *backoff_limit_per_index_copy = NULL;
    if (backoff_limit_per_index) {
        backoff_limit_per_index_copy = malloc(sizeof(int));
        if (backoff_limit_per_index_copy) *backoff_limit_per_index_copy = *backoff_limit_per_index;
    }
    int *completions_copy = NULL;
    if (completions) {
        completions_copy = malloc(sizeof(int));
        if (completions_copy) *completions_copy = *completions;
    }
    int *manual_selector_copy = NULL;
    if (manual_selector) {
        manual_selector_copy = malloc(sizeof(int));
        if (manual_selector_copy) *manual_selector_copy = *manual_selector;
    }
    int *max_failed_indexes_copy = NULL;
    if (max_failed_indexes) {
        max_failed_indexes_copy = malloc(sizeof(int));
        if (max_failed_indexes_copy) *max_failed_indexes_copy = *max_failed_indexes;
    }
    int *parallelism_copy = NULL;
    if (parallelism) {
        parallelism_copy = malloc(sizeof(int));
        if (parallelism_copy) *parallelism_copy = *parallelism;
    }
    int *suspend_copy = NULL;
    if (suspend) {
        suspend_copy = malloc(sizeof(int));
        if (suspend_copy) *suspend_copy = *suspend;
    }
    int *ttl_seconds_after_finished_copy = NULL;
    if (ttl_seconds_after_finished) {
        ttl_seconds_after_finished_copy = malloc(sizeof(int));
        if (ttl_seconds_after_finished_copy) *ttl_seconds_after_finished_copy = *ttl_seconds_after_finished;
    }
    v1_job_spec_t *result = v1_job_spec_create_internal (
        active_deadline_seconds_copy,
        backoff_limit_copy,
        backoff_limit_per_index_copy,
        completion_mode,
        completions_copy,
        managed_by,
        manual_selector_copy,
        max_failed_indexes_copy,
        parallelism_copy,
        pod_failure_policy,
        pod_replacement_policy,
        scheduling,
        selector,
        success_policy,
        suspend_copy,
        _template,
        ttl_seconds_after_finished_copy
        );
    if (!result) {
        free(active_deadline_seconds_copy);
        free(backoff_limit_copy);
        free(backoff_limit_per_index_copy);
        free(completions_copy);
        free(manual_selector_copy);
        free(max_failed_indexes_copy);
        free(parallelism_copy);
        free(suspend_copy);
        free(ttl_seconds_after_finished_copy);
    }
    return result;
}

void v1_job_spec_free(v1_job_spec_t *v1_job_spec) {
    if(NULL == v1_job_spec){
        return ;
    }
    if(v1_job_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_job_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_job_spec->active_deadline_seconds) {
        free(v1_job_spec->active_deadline_seconds);
        v1_job_spec->active_deadline_seconds = NULL;
    }
    if (v1_job_spec->backoff_limit) {
        free(v1_job_spec->backoff_limit);
        v1_job_spec->backoff_limit = NULL;
    }
    if (v1_job_spec->backoff_limit_per_index) {
        free(v1_job_spec->backoff_limit_per_index);
        v1_job_spec->backoff_limit_per_index = NULL;
    }
    if (v1_job_spec->completion_mode) {
        free(v1_job_spec->completion_mode);
        v1_job_spec->completion_mode = NULL;
    }
    if (v1_job_spec->completions) {
        free(v1_job_spec->completions);
        v1_job_spec->completions = NULL;
    }
    if (v1_job_spec->managed_by) {
        free(v1_job_spec->managed_by);
        v1_job_spec->managed_by = NULL;
    }
    if (v1_job_spec->manual_selector) {
        free(v1_job_spec->manual_selector);
        v1_job_spec->manual_selector = NULL;
    }
    if (v1_job_spec->max_failed_indexes) {
        free(v1_job_spec->max_failed_indexes);
        v1_job_spec->max_failed_indexes = NULL;
    }
    if (v1_job_spec->parallelism) {
        free(v1_job_spec->parallelism);
        v1_job_spec->parallelism = NULL;
    }
    if (v1_job_spec->pod_failure_policy) {
        v1_pod_failure_policy_free(v1_job_spec->pod_failure_policy);
        v1_job_spec->pod_failure_policy = NULL;
    }
    if (v1_job_spec->pod_replacement_policy) {
        free(v1_job_spec->pod_replacement_policy);
        v1_job_spec->pod_replacement_policy = NULL;
    }
    if (v1_job_spec->scheduling) {
        v1_job_scheduling_configuration_free(v1_job_spec->scheduling);
        v1_job_spec->scheduling = NULL;
    }
    if (v1_job_spec->selector) {
        v1_label_selector_free(v1_job_spec->selector);
        v1_job_spec->selector = NULL;
    }
    if (v1_job_spec->success_policy) {
        v1_success_policy_free(v1_job_spec->success_policy);
        v1_job_spec->success_policy = NULL;
    }
    if (v1_job_spec->suspend) {
        free(v1_job_spec->suspend);
        v1_job_spec->suspend = NULL;
    }
    if (v1_job_spec->_template) {
        v1_pod_template_spec_free(v1_job_spec->_template);
        v1_job_spec->_template = NULL;
    }
    if (v1_job_spec->ttl_seconds_after_finished) {
        free(v1_job_spec->ttl_seconds_after_finished);
        v1_job_spec->ttl_seconds_after_finished = NULL;
    }
    free(v1_job_spec);
}

cJSON *v1_job_spec_convertToJSON(v1_job_spec_t *v1_job_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_job_spec->active_deadline_seconds
    if(v1_job_spec->active_deadline_seconds) {
    if(cJSON_AddNumberToObject(item, "activeDeadlineSeconds", *v1_job_spec->active_deadline_seconds) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_job_spec->backoff_limit
    if(v1_job_spec->backoff_limit) {
    if(cJSON_AddNumberToObject(item, "backoffLimit", *v1_job_spec->backoff_limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_job_spec->backoff_limit_per_index
    if(v1_job_spec->backoff_limit_per_index) {
    if(cJSON_AddNumberToObject(item, "backoffLimitPerIndex", *v1_job_spec->backoff_limit_per_index) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_job_spec->completion_mode
    if(v1_job_spec->completion_mode) {
    if(cJSON_AddStringToObject(item, "completionMode", v1_job_spec->completion_mode) == NULL) {
    goto fail; //String
    }
    }


    // v1_job_spec->completions
    if(v1_job_spec->completions) {
    if(cJSON_AddNumberToObject(item, "completions", *v1_job_spec->completions) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_job_spec->managed_by
    if(v1_job_spec->managed_by) {
    if(cJSON_AddStringToObject(item, "managedBy", v1_job_spec->managed_by) == NULL) {
    goto fail; //String
    }
    }


    // v1_job_spec->manual_selector
    if(v1_job_spec->manual_selector) {
    if(cJSON_AddBoolToObject(item, "manualSelector", *v1_job_spec->manual_selector) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_job_spec->max_failed_indexes
    if(v1_job_spec->max_failed_indexes) {
    if(cJSON_AddNumberToObject(item, "maxFailedIndexes", *v1_job_spec->max_failed_indexes) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_job_spec->parallelism
    if(v1_job_spec->parallelism) {
    if(cJSON_AddNumberToObject(item, "parallelism", *v1_job_spec->parallelism) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_job_spec->pod_failure_policy
    if(v1_job_spec->pod_failure_policy) {
    cJSON *pod_failure_policy_local_JSON = v1_pod_failure_policy_convertToJSON(v1_job_spec->pod_failure_policy);
    if(pod_failure_policy_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "podFailurePolicy", pod_failure_policy_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_job_spec->pod_replacement_policy
    if(v1_job_spec->pod_replacement_policy) {
    if(cJSON_AddStringToObject(item, "podReplacementPolicy", v1_job_spec->pod_replacement_policy) == NULL) {
    goto fail; //String
    }
    }


    // v1_job_spec->scheduling
    if(v1_job_spec->scheduling) {
    cJSON *scheduling_local_JSON = v1_job_scheduling_configuration_convertToJSON(v1_job_spec->scheduling);
    if(scheduling_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "scheduling", scheduling_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_job_spec->selector
    if(v1_job_spec->selector) {
    cJSON *selector_local_JSON = v1_label_selector_convertToJSON(v1_job_spec->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "selector", selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_job_spec->success_policy
    if(v1_job_spec->success_policy) {
    cJSON *success_policy_local_JSON = v1_success_policy_convertToJSON(v1_job_spec->success_policy);
    if(success_policy_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "successPolicy", success_policy_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_job_spec->suspend
    if(v1_job_spec->suspend) {
    if(cJSON_AddBoolToObject(item, "suspend", *v1_job_spec->suspend) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_job_spec->_template
    if (!v1_job_spec->_template) {
        goto fail;
    }
    cJSON *_template_local_JSON = v1_pod_template_spec_convertToJSON(v1_job_spec->_template);
    if(_template_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "template", _template_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1_job_spec->ttl_seconds_after_finished
    if(v1_job_spec->ttl_seconds_after_finished) {
    if(cJSON_AddNumberToObject(item, "ttlSecondsAfterFinished", *v1_job_spec->ttl_seconds_after_finished) == NULL) {
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

v1_job_spec_t *v1_job_spec_parseFromJSON(cJSON *v1_job_specJSON){

    v1_job_spec_t *v1_job_spec_local_var = NULL;

    // define the local variable for v1_job_spec->active_deadline_seconds
    long *active_deadline_seconds_local_var = NULL;

    // define the local variable for v1_job_spec->backoff_limit
    int *backoff_limit_local_var = NULL;

    // define the local variable for v1_job_spec->backoff_limit_per_index
    int *backoff_limit_per_index_local_var = NULL;

    char *completion_mode_local_str = NULL;

    // define the local variable for v1_job_spec->completions
    int *completions_local_var = NULL;

    char *managed_by_local_str = NULL;

    // define the local variable for v1_job_spec->manual_selector
    int *manual_selector_local_var = NULL;

    // define the local variable for v1_job_spec->max_failed_indexes
    int *max_failed_indexes_local_var = NULL;

    // define the local variable for v1_job_spec->parallelism
    int *parallelism_local_var = NULL;

    // define the local variable for v1_job_spec->pod_failure_policy
    v1_pod_failure_policy_t *pod_failure_policy_local_nonprim = NULL;

    char *pod_replacement_policy_local_str = NULL;

    // define the local variable for v1_job_spec->scheduling
    v1_job_scheduling_configuration_t *scheduling_local_nonprim = NULL;

    // define the local variable for v1_job_spec->selector
    v1_label_selector_t *selector_local_nonprim = NULL;

    // define the local variable for v1_job_spec->success_policy
    v1_success_policy_t *success_policy_local_nonprim = NULL;

    // define the local variable for v1_job_spec->suspend
    int *suspend_local_var = NULL;

    // define the local variable for v1_job_spec->_template
    v1_pod_template_spec_t *_template_local_nonprim = NULL;

    // define the local variable for v1_job_spec->ttl_seconds_after_finished
    int *ttl_seconds_after_finished_local_var = NULL;

    // v1_job_spec->active_deadline_seconds
    cJSON *active_deadline_seconds = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "activeDeadlineSeconds");
    if (cJSON_IsNull(active_deadline_seconds)) {
        active_deadline_seconds = NULL;
    }
    if (active_deadline_seconds) { 
    if(!cJSON_IsNumber(active_deadline_seconds))
    {
    goto end; //Numeric
    }
    active_deadline_seconds_local_var = malloc(sizeof(long));
    if(!active_deadline_seconds_local_var)
    {
        goto end;
    }
    *active_deadline_seconds_local_var = active_deadline_seconds->valuedouble;
    }

    // v1_job_spec->backoff_limit
    cJSON *backoff_limit = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "backoffLimit");
    if (cJSON_IsNull(backoff_limit)) {
        backoff_limit = NULL;
    }
    if (backoff_limit) { 
    if(!cJSON_IsNumber(backoff_limit))
    {
    goto end; //Numeric
    }
    backoff_limit_local_var = malloc(sizeof(int));
    if(!backoff_limit_local_var)
    {
        goto end;
    }
    *backoff_limit_local_var = backoff_limit->valuedouble;
    }

    // v1_job_spec->backoff_limit_per_index
    cJSON *backoff_limit_per_index = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "backoffLimitPerIndex");
    if (cJSON_IsNull(backoff_limit_per_index)) {
        backoff_limit_per_index = NULL;
    }
    if (backoff_limit_per_index) { 
    if(!cJSON_IsNumber(backoff_limit_per_index))
    {
    goto end; //Numeric
    }
    backoff_limit_per_index_local_var = malloc(sizeof(int));
    if(!backoff_limit_per_index_local_var)
    {
        goto end;
    }
    *backoff_limit_per_index_local_var = backoff_limit_per_index->valuedouble;
    }

    // v1_job_spec->completion_mode
    cJSON *completion_mode = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "completionMode");
    if (cJSON_IsNull(completion_mode)) {
        completion_mode = NULL;
    }
    if (completion_mode) { 
    if(!cJSON_IsString(completion_mode) && !cJSON_IsNull(completion_mode))
    {
    goto end; //String
    }
    }

    // v1_job_spec->completions
    cJSON *completions = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "completions");
    if (cJSON_IsNull(completions)) {
        completions = NULL;
    }
    if (completions) { 
    if(!cJSON_IsNumber(completions))
    {
    goto end; //Numeric
    }
    completions_local_var = malloc(sizeof(int));
    if(!completions_local_var)
    {
        goto end;
    }
    *completions_local_var = completions->valuedouble;
    }

    // v1_job_spec->managed_by
    cJSON *managed_by = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "managedBy");
    if (cJSON_IsNull(managed_by)) {
        managed_by = NULL;
    }
    if (managed_by) { 
    if(!cJSON_IsString(managed_by) && !cJSON_IsNull(managed_by))
    {
    goto end; //String
    }
    }

    // v1_job_spec->manual_selector
    cJSON *manual_selector = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "manualSelector");
    if (cJSON_IsNull(manual_selector)) {
        manual_selector = NULL;
    }
    if (manual_selector) { 
    if(!cJSON_IsBool(manual_selector))
    {
    goto end; //Bool
    }
    manual_selector_local_var = malloc(sizeof(int));
    if(!manual_selector_local_var)
    {
        goto end;
    }
    *manual_selector_local_var = manual_selector->valueint;
    }

    // v1_job_spec->max_failed_indexes
    cJSON *max_failed_indexes = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "maxFailedIndexes");
    if (cJSON_IsNull(max_failed_indexes)) {
        max_failed_indexes = NULL;
    }
    if (max_failed_indexes) { 
    if(!cJSON_IsNumber(max_failed_indexes))
    {
    goto end; //Numeric
    }
    max_failed_indexes_local_var = malloc(sizeof(int));
    if(!max_failed_indexes_local_var)
    {
        goto end;
    }
    *max_failed_indexes_local_var = max_failed_indexes->valuedouble;
    }

    // v1_job_spec->parallelism
    cJSON *parallelism = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "parallelism");
    if (cJSON_IsNull(parallelism)) {
        parallelism = NULL;
    }
    if (parallelism) { 
    if(!cJSON_IsNumber(parallelism))
    {
    goto end; //Numeric
    }
    parallelism_local_var = malloc(sizeof(int));
    if(!parallelism_local_var)
    {
        goto end;
    }
    *parallelism_local_var = parallelism->valuedouble;
    }

    // v1_job_spec->pod_failure_policy
    cJSON *pod_failure_policy = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "podFailurePolicy");
    if (cJSON_IsNull(pod_failure_policy)) {
        pod_failure_policy = NULL;
    }
    if (pod_failure_policy) { 
    pod_failure_policy_local_nonprim = v1_pod_failure_policy_parseFromJSON(pod_failure_policy); //nonprimitive
    }

    // v1_job_spec->pod_replacement_policy
    cJSON *pod_replacement_policy = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "podReplacementPolicy");
    if (cJSON_IsNull(pod_replacement_policy)) {
        pod_replacement_policy = NULL;
    }
    if (pod_replacement_policy) { 
    if(!cJSON_IsString(pod_replacement_policy) && !cJSON_IsNull(pod_replacement_policy))
    {
    goto end; //String
    }
    }

    // v1_job_spec->scheduling
    cJSON *scheduling = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "scheduling");
    if (cJSON_IsNull(scheduling)) {
        scheduling = NULL;
    }
    if (scheduling) { 
    scheduling_local_nonprim = v1_job_scheduling_configuration_parseFromJSON(scheduling); //nonprimitive
    }

    // v1_job_spec->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "selector");
    if (cJSON_IsNull(selector)) {
        selector = NULL;
    }
    if (selector) { 
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive
    }

    // v1_job_spec->success_policy
    cJSON *success_policy = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "successPolicy");
    if (cJSON_IsNull(success_policy)) {
        success_policy = NULL;
    }
    if (success_policy) { 
    success_policy_local_nonprim = v1_success_policy_parseFromJSON(success_policy); //nonprimitive
    }

    // v1_job_spec->suspend
    cJSON *suspend = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "suspend");
    if (cJSON_IsNull(suspend)) {
        suspend = NULL;
    }
    if (suspend) { 
    if(!cJSON_IsBool(suspend))
    {
    goto end; //Bool
    }
    suspend_local_var = malloc(sizeof(int));
    if(!suspend_local_var)
    {
        goto end;
    }
    *suspend_local_var = suspend->valueint;
    }

    // v1_job_spec->_template
    cJSON *_template = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "template");
    if (cJSON_IsNull(_template)) {
        _template = NULL;
    }
    if (!_template) {
        goto end;
    }

    
    _template_local_nonprim = v1_pod_template_spec_parseFromJSON(_template); //nonprimitive

    // v1_job_spec->ttl_seconds_after_finished
    cJSON *ttl_seconds_after_finished = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "ttlSecondsAfterFinished");
    if (cJSON_IsNull(ttl_seconds_after_finished)) {
        ttl_seconds_after_finished = NULL;
    }
    if (ttl_seconds_after_finished) { 
    if(!cJSON_IsNumber(ttl_seconds_after_finished))
    {
    goto end; //Numeric
    }
    ttl_seconds_after_finished_local_var = malloc(sizeof(int));
    if(!ttl_seconds_after_finished_local_var)
    {
        goto end;
    }
    *ttl_seconds_after_finished_local_var = ttl_seconds_after_finished->valuedouble;
    }


    if (completion_mode && !cJSON_IsNull(completion_mode)) completion_mode_local_str = strdup(completion_mode->valuestring);
    if (managed_by && !cJSON_IsNull(managed_by)) managed_by_local_str = strdup(managed_by->valuestring);
    if (pod_replacement_policy && !cJSON_IsNull(pod_replacement_policy)) pod_replacement_policy_local_str = strdup(pod_replacement_policy->valuestring);

    v1_job_spec_local_var = v1_job_spec_create_internal (
        active_deadline_seconds_local_var,
        backoff_limit_local_var,
        backoff_limit_per_index_local_var,
        completion_mode_local_str,
        completions_local_var,
        managed_by_local_str,
        manual_selector_local_var,
        max_failed_indexes_local_var,
        parallelism_local_var,
        pod_failure_policy ? pod_failure_policy_local_nonprim : NULL,
        pod_replacement_policy_local_str,
        scheduling ? scheduling_local_nonprim : NULL,
        selector ? selector_local_nonprim : NULL,
        success_policy ? success_policy_local_nonprim : NULL,
        suspend_local_var,
        _template_local_nonprim,
        ttl_seconds_after_finished_local_var
        );

    if (!v1_job_spec_local_var) {
        goto end;
    }

    return v1_job_spec_local_var;
end:
    if (active_deadline_seconds_local_var) {
        free(active_deadline_seconds_local_var);
        active_deadline_seconds_local_var = NULL;
    }
    if (backoff_limit_local_var) {
        free(backoff_limit_local_var);
        backoff_limit_local_var = NULL;
    }
    if (backoff_limit_per_index_local_var) {
        free(backoff_limit_per_index_local_var);
        backoff_limit_per_index_local_var = NULL;
    }
    if (completion_mode_local_str) {
        free(completion_mode_local_str);
        completion_mode_local_str = NULL;
    }
    if (completions_local_var) {
        free(completions_local_var);
        completions_local_var = NULL;
    }
    if (managed_by_local_str) {
        free(managed_by_local_str);
        managed_by_local_str = NULL;
    }
    if (manual_selector_local_var) {
        free(manual_selector_local_var);
        manual_selector_local_var = NULL;
    }
    if (max_failed_indexes_local_var) {
        free(max_failed_indexes_local_var);
        max_failed_indexes_local_var = NULL;
    }
    if (parallelism_local_var) {
        free(parallelism_local_var);
        parallelism_local_var = NULL;
    }
    if (pod_failure_policy_local_nonprim) {
        v1_pod_failure_policy_free(pod_failure_policy_local_nonprim);
        pod_failure_policy_local_nonprim = NULL;
    }
    if (pod_replacement_policy_local_str) {
        free(pod_replacement_policy_local_str);
        pod_replacement_policy_local_str = NULL;
    }
    if (scheduling_local_nonprim) {
        v1_job_scheduling_configuration_free(scheduling_local_nonprim);
        scheduling_local_nonprim = NULL;
    }
    if (selector_local_nonprim) {
        v1_label_selector_free(selector_local_nonprim);
        selector_local_nonprim = NULL;
    }
    if (success_policy_local_nonprim) {
        v1_success_policy_free(success_policy_local_nonprim);
        success_policy_local_nonprim = NULL;
    }
    if (suspend_local_var) {
        free(suspend_local_var);
        suspend_local_var = NULL;
    }
    if (_template_local_nonprim) {
        v1_pod_template_spec_free(_template_local_nonprim);
        _template_local_nonprim = NULL;
    }
    if (ttl_seconds_after_finished_local_var) {
        free(ttl_seconds_after_finished_local_var);
        ttl_seconds_after_finished_local_var = NULL;
    }
    return NULL;

}
