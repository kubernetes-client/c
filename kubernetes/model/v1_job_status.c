#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_job_status.h"



static v1_job_status_t *v1_job_status_create_internal(
    int *active,
    char *completed_indexes,
    char *completion_time,
    list_t *conditions,
    int *failed,
    char *failed_indexes,
    int *ready,
    char *start_time,
    int *succeeded,
    int *terminating,
    v1_uncounted_terminated_pods_t *uncounted_terminated_pods
    ) {
    v1_job_status_t *v1_job_status_local_var = malloc(sizeof(v1_job_status_t));
    if (!v1_job_status_local_var) {
        return NULL;
    }
    memset(v1_job_status_local_var, 0, sizeof(v1_job_status_t));
    v1_job_status_local_var->_library_owned = 1;
    v1_job_status_local_var->active = active;
    v1_job_status_local_var->completed_indexes = completed_indexes;
    v1_job_status_local_var->completion_time = completion_time;
    v1_job_status_local_var->conditions = conditions;
    v1_job_status_local_var->failed = failed;
    v1_job_status_local_var->failed_indexes = failed_indexes;
    v1_job_status_local_var->ready = ready;
    v1_job_status_local_var->start_time = start_time;
    v1_job_status_local_var->succeeded = succeeded;
    v1_job_status_local_var->terminating = terminating;
    v1_job_status_local_var->uncounted_terminated_pods = uncounted_terminated_pods;
    return v1_job_status_local_var;
}

__attribute__((deprecated)) v1_job_status_t *v1_job_status_create(
    int *active,
    char *completed_indexes,
    char *completion_time,
    list_t *conditions,
    int *failed,
    char *failed_indexes,
    int *ready,
    char *start_time,
    int *succeeded,
    int *terminating,
    v1_uncounted_terminated_pods_t *uncounted_terminated_pods
    ) {
    int *active_copy = NULL;
    if (active) {
        active_copy = malloc(sizeof(int));
        if (active_copy) *active_copy = *active;
    }
    int *failed_copy = NULL;
    if (failed) {
        failed_copy = malloc(sizeof(int));
        if (failed_copy) *failed_copy = *failed;
    }
    int *ready_copy = NULL;
    if (ready) {
        ready_copy = malloc(sizeof(int));
        if (ready_copy) *ready_copy = *ready;
    }
    int *succeeded_copy = NULL;
    if (succeeded) {
        succeeded_copy = malloc(sizeof(int));
        if (succeeded_copy) *succeeded_copy = *succeeded;
    }
    int *terminating_copy = NULL;
    if (terminating) {
        terminating_copy = malloc(sizeof(int));
        if (terminating_copy) *terminating_copy = *terminating;
    }
    v1_job_status_t *result = v1_job_status_create_internal (
        active_copy,
        completed_indexes,
        completion_time,
        conditions,
        failed_copy,
        failed_indexes,
        ready_copy,
        start_time,
        succeeded_copy,
        terminating_copy,
        uncounted_terminated_pods
        );
    if (!result) {
        free(active_copy);
        free(failed_copy);
        free(ready_copy);
        free(succeeded_copy);
        free(terminating_copy);
    }
    return result;
}

void v1_job_status_free(v1_job_status_t *v1_job_status) {
    if(NULL == v1_job_status){
        return ;
    }
    if(v1_job_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_job_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_job_status->active) {
        free(v1_job_status->active);
        v1_job_status->active = NULL;
    }
    if (v1_job_status->completed_indexes) {
        free(v1_job_status->completed_indexes);
        v1_job_status->completed_indexes = NULL;
    }
    if (v1_job_status->completion_time) {
        free(v1_job_status->completion_time);
        v1_job_status->completion_time = NULL;
    }
    if (v1_job_status->conditions) {
        list_ForEach(listEntry, v1_job_status->conditions) {
            v1_job_condition_free(listEntry->data);
        }
        list_freeList(v1_job_status->conditions);
        v1_job_status->conditions = NULL;
    }
    if (v1_job_status->failed) {
        free(v1_job_status->failed);
        v1_job_status->failed = NULL;
    }
    if (v1_job_status->failed_indexes) {
        free(v1_job_status->failed_indexes);
        v1_job_status->failed_indexes = NULL;
    }
    if (v1_job_status->ready) {
        free(v1_job_status->ready);
        v1_job_status->ready = NULL;
    }
    if (v1_job_status->start_time) {
        free(v1_job_status->start_time);
        v1_job_status->start_time = NULL;
    }
    if (v1_job_status->succeeded) {
        free(v1_job_status->succeeded);
        v1_job_status->succeeded = NULL;
    }
    if (v1_job_status->terminating) {
        free(v1_job_status->terminating);
        v1_job_status->terminating = NULL;
    }
    if (v1_job_status->uncounted_terminated_pods) {
        v1_uncounted_terminated_pods_free(v1_job_status->uncounted_terminated_pods);
        v1_job_status->uncounted_terminated_pods = NULL;
    }
    free(v1_job_status);
}

cJSON *v1_job_status_convertToJSON(v1_job_status_t *v1_job_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_job_status->active
    if(v1_job_status->active) {
    if(cJSON_AddNumberToObject(item, "active", *v1_job_status->active) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_job_status->completed_indexes
    if(v1_job_status->completed_indexes) {
    if(cJSON_AddStringToObject(item, "completedIndexes", v1_job_status->completed_indexes) == NULL) {
    goto fail; //String
    }
    }


    // v1_job_status->completion_time
    if(v1_job_status->completion_time) {
    if(cJSON_AddStringToObject(item, "completionTime", v1_job_status->completion_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1_job_status->conditions
    if(v1_job_status->conditions) {
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1_job_status->conditions) {
    list_ForEach(conditionsListEntry, v1_job_status->conditions) {
    cJSON *itemLocal = v1_job_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
    }


    // v1_job_status->failed
    if(v1_job_status->failed) {
    if(cJSON_AddNumberToObject(item, "failed", *v1_job_status->failed) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_job_status->failed_indexes
    if(v1_job_status->failed_indexes) {
    if(cJSON_AddStringToObject(item, "failedIndexes", v1_job_status->failed_indexes) == NULL) {
    goto fail; //String
    }
    }


    // v1_job_status->ready
    if(v1_job_status->ready) {
    if(cJSON_AddNumberToObject(item, "ready", *v1_job_status->ready) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_job_status->start_time
    if(v1_job_status->start_time) {
    if(cJSON_AddStringToObject(item, "startTime", v1_job_status->start_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1_job_status->succeeded
    if(v1_job_status->succeeded) {
    if(cJSON_AddNumberToObject(item, "succeeded", *v1_job_status->succeeded) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_job_status->terminating
    if(v1_job_status->terminating) {
    if(cJSON_AddNumberToObject(item, "terminating", *v1_job_status->terminating) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_job_status->uncounted_terminated_pods
    if(v1_job_status->uncounted_terminated_pods) {
    cJSON *uncounted_terminated_pods_local_JSON = v1_uncounted_terminated_pods_convertToJSON(v1_job_status->uncounted_terminated_pods);
    if(uncounted_terminated_pods_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "uncountedTerminatedPods", uncounted_terminated_pods_local_JSON);
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

v1_job_status_t *v1_job_status_parseFromJSON(cJSON *v1_job_statusJSON){

    v1_job_status_t *v1_job_status_local_var = NULL;

    // define the local variable for v1_job_status->active
    int *active_local_var = NULL;

    char *completed_indexes_local_str = NULL;

    char *completion_time_local_str = NULL;

    // define the local list for v1_job_status->conditions
    list_t *conditionsList = NULL;

    // define the local variable for v1_job_status->failed
    int *failed_local_var = NULL;

    char *failed_indexes_local_str = NULL;

    // define the local variable for v1_job_status->ready
    int *ready_local_var = NULL;

    char *start_time_local_str = NULL;

    // define the local variable for v1_job_status->succeeded
    int *succeeded_local_var = NULL;

    // define the local variable for v1_job_status->terminating
    int *terminating_local_var = NULL;

    // define the local variable for v1_job_status->uncounted_terminated_pods
    v1_uncounted_terminated_pods_t *uncounted_terminated_pods_local_nonprim = NULL;

    // v1_job_status->active
    cJSON *active = cJSON_GetObjectItemCaseSensitive(v1_job_statusJSON, "active");
    if (cJSON_IsNull(active)) {
        active = NULL;
    }
    if (active) { 
    if(!cJSON_IsNumber(active))
    {
    goto end; //Numeric
    }
    active_local_var = malloc(sizeof(int));
    if(!active_local_var)
    {
        goto end;
    }
    *active_local_var = active->valuedouble;
    }

    // v1_job_status->completed_indexes
    cJSON *completed_indexes = cJSON_GetObjectItemCaseSensitive(v1_job_statusJSON, "completedIndexes");
    if (cJSON_IsNull(completed_indexes)) {
        completed_indexes = NULL;
    }
    if (completed_indexes) { 
    if(!cJSON_IsString(completed_indexes) && !cJSON_IsNull(completed_indexes))
    {
    goto end; //String
    }
    }

    // v1_job_status->completion_time
    cJSON *completion_time = cJSON_GetObjectItemCaseSensitive(v1_job_statusJSON, "completionTime");
    if (cJSON_IsNull(completion_time)) {
        completion_time = NULL;
    }
    if (completion_time) { 
    if(!cJSON_IsString(completion_time) && !cJSON_IsNull(completion_time))
    {
    goto end; //DateTime
    }
    }

    // v1_job_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1_job_statusJSON, "conditions");
    if (cJSON_IsNull(conditions)) {
        conditions = NULL;
    }
    if (conditions) { 
    cJSON *conditions_local_nonprimitive = NULL;
    if(!cJSON_IsArray(conditions)){
        goto end; //nonprimitive container
    }

    conditionsList = list_createList();

    cJSON_ArrayForEach(conditions_local_nonprimitive,conditions )
    {
        if(!cJSON_IsObject(conditions_local_nonprimitive)){
            goto end;
        }
        v1_job_condition_t *conditionsItem = v1_job_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1_job_status->failed
    cJSON *failed = cJSON_GetObjectItemCaseSensitive(v1_job_statusJSON, "failed");
    if (cJSON_IsNull(failed)) {
        failed = NULL;
    }
    if (failed) { 
    if(!cJSON_IsNumber(failed))
    {
    goto end; //Numeric
    }
    failed_local_var = malloc(sizeof(int));
    if(!failed_local_var)
    {
        goto end;
    }
    *failed_local_var = failed->valuedouble;
    }

    // v1_job_status->failed_indexes
    cJSON *failed_indexes = cJSON_GetObjectItemCaseSensitive(v1_job_statusJSON, "failedIndexes");
    if (cJSON_IsNull(failed_indexes)) {
        failed_indexes = NULL;
    }
    if (failed_indexes) { 
    if(!cJSON_IsString(failed_indexes) && !cJSON_IsNull(failed_indexes))
    {
    goto end; //String
    }
    }

    // v1_job_status->ready
    cJSON *ready = cJSON_GetObjectItemCaseSensitive(v1_job_statusJSON, "ready");
    if (cJSON_IsNull(ready)) {
        ready = NULL;
    }
    if (ready) { 
    if(!cJSON_IsNumber(ready))
    {
    goto end; //Numeric
    }
    ready_local_var = malloc(sizeof(int));
    if(!ready_local_var)
    {
        goto end;
    }
    *ready_local_var = ready->valuedouble;
    }

    // v1_job_status->start_time
    cJSON *start_time = cJSON_GetObjectItemCaseSensitive(v1_job_statusJSON, "startTime");
    if (cJSON_IsNull(start_time)) {
        start_time = NULL;
    }
    if (start_time) { 
    if(!cJSON_IsString(start_time) && !cJSON_IsNull(start_time))
    {
    goto end; //DateTime
    }
    }

    // v1_job_status->succeeded
    cJSON *succeeded = cJSON_GetObjectItemCaseSensitive(v1_job_statusJSON, "succeeded");
    if (cJSON_IsNull(succeeded)) {
        succeeded = NULL;
    }
    if (succeeded) { 
    if(!cJSON_IsNumber(succeeded))
    {
    goto end; //Numeric
    }
    succeeded_local_var = malloc(sizeof(int));
    if(!succeeded_local_var)
    {
        goto end;
    }
    *succeeded_local_var = succeeded->valuedouble;
    }

    // v1_job_status->terminating
    cJSON *terminating = cJSON_GetObjectItemCaseSensitive(v1_job_statusJSON, "terminating");
    if (cJSON_IsNull(terminating)) {
        terminating = NULL;
    }
    if (terminating) { 
    if(!cJSON_IsNumber(terminating))
    {
    goto end; //Numeric
    }
    terminating_local_var = malloc(sizeof(int));
    if(!terminating_local_var)
    {
        goto end;
    }
    *terminating_local_var = terminating->valuedouble;
    }

    // v1_job_status->uncounted_terminated_pods
    cJSON *uncounted_terminated_pods = cJSON_GetObjectItemCaseSensitive(v1_job_statusJSON, "uncountedTerminatedPods");
    if (cJSON_IsNull(uncounted_terminated_pods)) {
        uncounted_terminated_pods = NULL;
    }
    if (uncounted_terminated_pods) { 
    uncounted_terminated_pods_local_nonprim = v1_uncounted_terminated_pods_parseFromJSON(uncounted_terminated_pods); //nonprimitive
    }


    if (completed_indexes && !cJSON_IsNull(completed_indexes)) completed_indexes_local_str = strdup(completed_indexes->valuestring);
    if (completion_time && !cJSON_IsNull(completion_time)) completion_time_local_str = strdup(completion_time->valuestring);
    if (failed_indexes && !cJSON_IsNull(failed_indexes)) failed_indexes_local_str = strdup(failed_indexes->valuestring);
    if (start_time && !cJSON_IsNull(start_time)) start_time_local_str = strdup(start_time->valuestring);

    v1_job_status_local_var = v1_job_status_create_internal (
        active_local_var,
        completed_indexes_local_str,
        completion_time_local_str,
        conditions ? conditionsList : NULL,
        failed_local_var,
        failed_indexes_local_str,
        ready_local_var,
        start_time_local_str,
        succeeded_local_var,
        terminating_local_var,
        uncounted_terminated_pods ? uncounted_terminated_pods_local_nonprim : NULL
        );

    if (!v1_job_status_local_var) {
        goto end;
    }

    return v1_job_status_local_var;
end:
    if (active_local_var) {
        free(active_local_var);
        active_local_var = NULL;
    }
    if (completed_indexes_local_str) {
        free(completed_indexes_local_str);
        completed_indexes_local_str = NULL;
    }
    if (completion_time_local_str) {
        free(completion_time_local_str);
        completion_time_local_str = NULL;
    }
    if (conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, conditionsList) {
            v1_job_condition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(conditionsList);
        conditionsList = NULL;
    }
    if (failed_local_var) {
        free(failed_local_var);
        failed_local_var = NULL;
    }
    if (failed_indexes_local_str) {
        free(failed_indexes_local_str);
        failed_indexes_local_str = NULL;
    }
    if (ready_local_var) {
        free(ready_local_var);
        ready_local_var = NULL;
    }
    if (start_time_local_str) {
        free(start_time_local_str);
        start_time_local_str = NULL;
    }
    if (succeeded_local_var) {
        free(succeeded_local_var);
        succeeded_local_var = NULL;
    }
    if (terminating_local_var) {
        free(terminating_local_var);
        terminating_local_var = NULL;
    }
    if (uncounted_terminated_pods_local_nonprim) {
        v1_uncounted_terminated_pods_free(uncounted_terminated_pods_local_nonprim);
        uncounted_terminated_pods_local_nonprim = NULL;
    }
    return NULL;

}
