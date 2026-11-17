#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_cron_job_spec.h"



static v1_cron_job_spec_t *v1_cron_job_spec_create_internal(
    char *concurrency_policy,
    int *failed_jobs_history_limit,
    v1_job_template_spec_t *job_template,
    char *schedule,
    long *starting_deadline_seconds,
    int *successful_jobs_history_limit,
    int *suspend,
    char *time_zone
    ) {
    v1_cron_job_spec_t *v1_cron_job_spec_local_var = malloc(sizeof(v1_cron_job_spec_t));
    if (!v1_cron_job_spec_local_var) {
        return NULL;
    }
    memset(v1_cron_job_spec_local_var, 0, sizeof(v1_cron_job_spec_t));
    v1_cron_job_spec_local_var->_library_owned = 1;
    v1_cron_job_spec_local_var->concurrency_policy = concurrency_policy;
    v1_cron_job_spec_local_var->failed_jobs_history_limit = failed_jobs_history_limit;
    v1_cron_job_spec_local_var->job_template = job_template;
    v1_cron_job_spec_local_var->schedule = schedule;
    v1_cron_job_spec_local_var->starting_deadline_seconds = starting_deadline_seconds;
    v1_cron_job_spec_local_var->successful_jobs_history_limit = successful_jobs_history_limit;
    v1_cron_job_spec_local_var->suspend = suspend;
    v1_cron_job_spec_local_var->time_zone = time_zone;
    return v1_cron_job_spec_local_var;
}

__attribute__((deprecated)) v1_cron_job_spec_t *v1_cron_job_spec_create(
    char *concurrency_policy,
    int *failed_jobs_history_limit,
    v1_job_template_spec_t *job_template,
    char *schedule,
    long *starting_deadline_seconds,
    int *successful_jobs_history_limit,
    int *suspend,
    char *time_zone
    ) {
    int *failed_jobs_history_limit_copy = NULL;
    if (failed_jobs_history_limit) {
        failed_jobs_history_limit_copy = malloc(sizeof(int));
        if (failed_jobs_history_limit_copy) *failed_jobs_history_limit_copy = *failed_jobs_history_limit;
    }
    long *starting_deadline_seconds_copy = NULL;
    if (starting_deadline_seconds) {
        starting_deadline_seconds_copy = malloc(sizeof(long));
        if (starting_deadline_seconds_copy) *starting_deadline_seconds_copy = *starting_deadline_seconds;
    }
    int *successful_jobs_history_limit_copy = NULL;
    if (successful_jobs_history_limit) {
        successful_jobs_history_limit_copy = malloc(sizeof(int));
        if (successful_jobs_history_limit_copy) *successful_jobs_history_limit_copy = *successful_jobs_history_limit;
    }
    int *suspend_copy = NULL;
    if (suspend) {
        suspend_copy = malloc(sizeof(int));
        if (suspend_copy) *suspend_copy = *suspend;
    }
    v1_cron_job_spec_t *result = v1_cron_job_spec_create_internal (
        concurrency_policy,
        failed_jobs_history_limit_copy,
        job_template,
        schedule,
        starting_deadline_seconds_copy,
        successful_jobs_history_limit_copy,
        suspend_copy,
        time_zone
        );
    if (!result) {
        free(failed_jobs_history_limit_copy);
        free(starting_deadline_seconds_copy);
        free(successful_jobs_history_limit_copy);
        free(suspend_copy);
    }
    return result;
}

void v1_cron_job_spec_free(v1_cron_job_spec_t *v1_cron_job_spec) {
    if(NULL == v1_cron_job_spec){
        return ;
    }
    if(v1_cron_job_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_cron_job_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_cron_job_spec->concurrency_policy) {
        free(v1_cron_job_spec->concurrency_policy);
        v1_cron_job_spec->concurrency_policy = NULL;
    }
    if (v1_cron_job_spec->failed_jobs_history_limit) {
        free(v1_cron_job_spec->failed_jobs_history_limit);
        v1_cron_job_spec->failed_jobs_history_limit = NULL;
    }
    if (v1_cron_job_spec->job_template) {
        v1_job_template_spec_free(v1_cron_job_spec->job_template);
        v1_cron_job_spec->job_template = NULL;
    }
    if (v1_cron_job_spec->schedule) {
        free(v1_cron_job_spec->schedule);
        v1_cron_job_spec->schedule = NULL;
    }
    if (v1_cron_job_spec->starting_deadline_seconds) {
        free(v1_cron_job_spec->starting_deadline_seconds);
        v1_cron_job_spec->starting_deadline_seconds = NULL;
    }
    if (v1_cron_job_spec->successful_jobs_history_limit) {
        free(v1_cron_job_spec->successful_jobs_history_limit);
        v1_cron_job_spec->successful_jobs_history_limit = NULL;
    }
    if (v1_cron_job_spec->suspend) {
        free(v1_cron_job_spec->suspend);
        v1_cron_job_spec->suspend = NULL;
    }
    if (v1_cron_job_spec->time_zone) {
        free(v1_cron_job_spec->time_zone);
        v1_cron_job_spec->time_zone = NULL;
    }
    free(v1_cron_job_spec);
}

cJSON *v1_cron_job_spec_convertToJSON(v1_cron_job_spec_t *v1_cron_job_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_cron_job_spec->concurrency_policy
    if(v1_cron_job_spec->concurrency_policy) {
    if(cJSON_AddStringToObject(item, "concurrencyPolicy", v1_cron_job_spec->concurrency_policy) == NULL) {
    goto fail; //String
    }
    }


    // v1_cron_job_spec->failed_jobs_history_limit
    if(v1_cron_job_spec->failed_jobs_history_limit) {
    if(cJSON_AddNumberToObject(item, "failedJobsHistoryLimit", *v1_cron_job_spec->failed_jobs_history_limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_cron_job_spec->job_template
    if (!v1_cron_job_spec->job_template) {
        goto fail;
    }
    cJSON *job_template_local_JSON = v1_job_template_spec_convertToJSON(v1_cron_job_spec->job_template);
    if(job_template_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "jobTemplate", job_template_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1_cron_job_spec->schedule
    if (!v1_cron_job_spec->schedule) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "schedule", v1_cron_job_spec->schedule) == NULL) {
    goto fail; //String
    }


    // v1_cron_job_spec->starting_deadline_seconds
    if(v1_cron_job_spec->starting_deadline_seconds) {
    if(cJSON_AddNumberToObject(item, "startingDeadlineSeconds", *v1_cron_job_spec->starting_deadline_seconds) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_cron_job_spec->successful_jobs_history_limit
    if(v1_cron_job_spec->successful_jobs_history_limit) {
    if(cJSON_AddNumberToObject(item, "successfulJobsHistoryLimit", *v1_cron_job_spec->successful_jobs_history_limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_cron_job_spec->suspend
    if(v1_cron_job_spec->suspend) {
    if(cJSON_AddBoolToObject(item, "suspend", *v1_cron_job_spec->suspend) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_cron_job_spec->time_zone
    if(v1_cron_job_spec->time_zone) {
    if(cJSON_AddStringToObject(item, "timeZone", v1_cron_job_spec->time_zone) == NULL) {
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

v1_cron_job_spec_t *v1_cron_job_spec_parseFromJSON(cJSON *v1_cron_job_specJSON){

    v1_cron_job_spec_t *v1_cron_job_spec_local_var = NULL;

    char *concurrency_policy_local_str = NULL;

    // define the local variable for v1_cron_job_spec->failed_jobs_history_limit
    int *failed_jobs_history_limit_local_var = NULL;

    // define the local variable for v1_cron_job_spec->job_template
    v1_job_template_spec_t *job_template_local_nonprim = NULL;

    char *schedule_local_str = NULL;

    // define the local variable for v1_cron_job_spec->starting_deadline_seconds
    long *starting_deadline_seconds_local_var = NULL;

    // define the local variable for v1_cron_job_spec->successful_jobs_history_limit
    int *successful_jobs_history_limit_local_var = NULL;

    // define the local variable for v1_cron_job_spec->suspend
    int *suspend_local_var = NULL;

    char *time_zone_local_str = NULL;

    // v1_cron_job_spec->concurrency_policy
    cJSON *concurrency_policy = cJSON_GetObjectItemCaseSensitive(v1_cron_job_specJSON, "concurrencyPolicy");
    if (cJSON_IsNull(concurrency_policy)) {
        concurrency_policy = NULL;
    }
    if (concurrency_policy) { 
    if(!cJSON_IsString(concurrency_policy) && !cJSON_IsNull(concurrency_policy))
    {
    goto end; //String
    }
    }

    // v1_cron_job_spec->failed_jobs_history_limit
    cJSON *failed_jobs_history_limit = cJSON_GetObjectItemCaseSensitive(v1_cron_job_specJSON, "failedJobsHistoryLimit");
    if (cJSON_IsNull(failed_jobs_history_limit)) {
        failed_jobs_history_limit = NULL;
    }
    if (failed_jobs_history_limit) { 
    if(!cJSON_IsNumber(failed_jobs_history_limit))
    {
    goto end; //Numeric
    }
    failed_jobs_history_limit_local_var = malloc(sizeof(int));
    if(!failed_jobs_history_limit_local_var)
    {
        goto end;
    }
    *failed_jobs_history_limit_local_var = failed_jobs_history_limit->valuedouble;
    }

    // v1_cron_job_spec->job_template
    cJSON *job_template = cJSON_GetObjectItemCaseSensitive(v1_cron_job_specJSON, "jobTemplate");
    if (cJSON_IsNull(job_template)) {
        job_template = NULL;
    }
    if (!job_template) {
        goto end;
    }

    
    job_template_local_nonprim = v1_job_template_spec_parseFromJSON(job_template); //nonprimitive

    // v1_cron_job_spec->schedule
    cJSON *schedule = cJSON_GetObjectItemCaseSensitive(v1_cron_job_specJSON, "schedule");
    if (cJSON_IsNull(schedule)) {
        schedule = NULL;
    }
    if (!schedule) {
        goto end;
    }

    
    if(!cJSON_IsString(schedule))
    {
    goto end; //String
    }

    // v1_cron_job_spec->starting_deadline_seconds
    cJSON *starting_deadline_seconds = cJSON_GetObjectItemCaseSensitive(v1_cron_job_specJSON, "startingDeadlineSeconds");
    if (cJSON_IsNull(starting_deadline_seconds)) {
        starting_deadline_seconds = NULL;
    }
    if (starting_deadline_seconds) { 
    if(!cJSON_IsNumber(starting_deadline_seconds))
    {
    goto end; //Numeric
    }
    starting_deadline_seconds_local_var = malloc(sizeof(long));
    if(!starting_deadline_seconds_local_var)
    {
        goto end;
    }
    *starting_deadline_seconds_local_var = starting_deadline_seconds->valuedouble;
    }

    // v1_cron_job_spec->successful_jobs_history_limit
    cJSON *successful_jobs_history_limit = cJSON_GetObjectItemCaseSensitive(v1_cron_job_specJSON, "successfulJobsHistoryLimit");
    if (cJSON_IsNull(successful_jobs_history_limit)) {
        successful_jobs_history_limit = NULL;
    }
    if (successful_jobs_history_limit) { 
    if(!cJSON_IsNumber(successful_jobs_history_limit))
    {
    goto end; //Numeric
    }
    successful_jobs_history_limit_local_var = malloc(sizeof(int));
    if(!successful_jobs_history_limit_local_var)
    {
        goto end;
    }
    *successful_jobs_history_limit_local_var = successful_jobs_history_limit->valuedouble;
    }

    // v1_cron_job_spec->suspend
    cJSON *suspend = cJSON_GetObjectItemCaseSensitive(v1_cron_job_specJSON, "suspend");
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

    // v1_cron_job_spec->time_zone
    cJSON *time_zone = cJSON_GetObjectItemCaseSensitive(v1_cron_job_specJSON, "timeZone");
    if (cJSON_IsNull(time_zone)) {
        time_zone = NULL;
    }
    if (time_zone) { 
    if(!cJSON_IsString(time_zone) && !cJSON_IsNull(time_zone))
    {
    goto end; //String
    }
    }


    if (concurrency_policy && !cJSON_IsNull(concurrency_policy)) concurrency_policy_local_str = strdup(concurrency_policy->valuestring);
    if (schedule && !cJSON_IsNull(schedule)) schedule_local_str = strdup(schedule->valuestring);
    if (time_zone && !cJSON_IsNull(time_zone)) time_zone_local_str = strdup(time_zone->valuestring);

    v1_cron_job_spec_local_var = v1_cron_job_spec_create_internal (
        concurrency_policy_local_str,
        failed_jobs_history_limit_local_var,
        job_template_local_nonprim,
        schedule_local_str,
        starting_deadline_seconds_local_var,
        successful_jobs_history_limit_local_var,
        suspend_local_var,
        time_zone_local_str
        );

    if (!v1_cron_job_spec_local_var) {
        goto end;
    }

    return v1_cron_job_spec_local_var;
end:
    if (concurrency_policy_local_str) {
        free(concurrency_policy_local_str);
        concurrency_policy_local_str = NULL;
    }
    if (failed_jobs_history_limit_local_var) {
        free(failed_jobs_history_limit_local_var);
        failed_jobs_history_limit_local_var = NULL;
    }
    if (job_template_local_nonprim) {
        v1_job_template_spec_free(job_template_local_nonprim);
        job_template_local_nonprim = NULL;
    }
    if (schedule_local_str) {
        free(schedule_local_str);
        schedule_local_str = NULL;
    }
    if (starting_deadline_seconds_local_var) {
        free(starting_deadline_seconds_local_var);
        starting_deadline_seconds_local_var = NULL;
    }
    if (successful_jobs_history_limit_local_var) {
        free(successful_jobs_history_limit_local_var);
        successful_jobs_history_limit_local_var = NULL;
    }
    if (suspend_local_var) {
        free(suspend_local_var);
        suspend_local_var = NULL;
    }
    if (time_zone_local_str) {
        free(time_zone_local_str);
        time_zone_local_str = NULL;
    }
    return NULL;

}
