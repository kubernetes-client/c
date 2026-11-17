#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "core_v1_event_series.h"



static core_v1_event_series_t *core_v1_event_series_create_internal(
    int *count,
    char *last_observed_time
    ) {
    core_v1_event_series_t *core_v1_event_series_local_var = malloc(sizeof(core_v1_event_series_t));
    if (!core_v1_event_series_local_var) {
        return NULL;
    }
    memset(core_v1_event_series_local_var, 0, sizeof(core_v1_event_series_t));
    core_v1_event_series_local_var->_library_owned = 1;
    core_v1_event_series_local_var->count = count;
    core_v1_event_series_local_var->last_observed_time = last_observed_time;
    return core_v1_event_series_local_var;
}

__attribute__((deprecated)) core_v1_event_series_t *core_v1_event_series_create(
    int *count,
    char *last_observed_time
    ) {
    int *count_copy = NULL;
    if (count) {
        count_copy = malloc(sizeof(int));
        if (count_copy) *count_copy = *count;
    }
    core_v1_event_series_t *result = core_v1_event_series_create_internal (
        count_copy,
        last_observed_time
        );
    if (!result) {
        free(count_copy);
    }
    return result;
}

void core_v1_event_series_free(core_v1_event_series_t *core_v1_event_series) {
    if(NULL == core_v1_event_series){
        return ;
    }
    if(core_v1_event_series->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "core_v1_event_series_free");
        return ;
    }
    listEntry_t *listEntry;
    if (core_v1_event_series->count) {
        free(core_v1_event_series->count);
        core_v1_event_series->count = NULL;
    }
    if (core_v1_event_series->last_observed_time) {
        free(core_v1_event_series->last_observed_time);
        core_v1_event_series->last_observed_time = NULL;
    }
    free(core_v1_event_series);
}

cJSON *core_v1_event_series_convertToJSON(core_v1_event_series_t *core_v1_event_series) {
    cJSON *item = cJSON_CreateObject();

    // core_v1_event_series->count
    if(core_v1_event_series->count) {
    if(cJSON_AddNumberToObject(item, "count", *core_v1_event_series->count) == NULL) {
    goto fail; //Numeric
    }
    }


    // core_v1_event_series->last_observed_time
    if(core_v1_event_series->last_observed_time) {
    if(cJSON_AddStringToObject(item, "lastObservedTime", core_v1_event_series->last_observed_time) == NULL) {
    goto fail; //Date-Time
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

core_v1_event_series_t *core_v1_event_series_parseFromJSON(cJSON *core_v1_event_seriesJSON){

    core_v1_event_series_t *core_v1_event_series_local_var = NULL;

    // define the local variable for core_v1_event_series->count
    int *count_local_var = NULL;

    char *last_observed_time_local_str = NULL;

    // core_v1_event_series->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(core_v1_event_seriesJSON, "count");
    if (cJSON_IsNull(count)) {
        count = NULL;
    }
    if (count) { 
    if(!cJSON_IsNumber(count))
    {
    goto end; //Numeric
    }
    count_local_var = malloc(sizeof(int));
    if(!count_local_var)
    {
        goto end;
    }
    *count_local_var = count->valuedouble;
    }

    // core_v1_event_series->last_observed_time
    cJSON *last_observed_time = cJSON_GetObjectItemCaseSensitive(core_v1_event_seriesJSON, "lastObservedTime");
    if (cJSON_IsNull(last_observed_time)) {
        last_observed_time = NULL;
    }
    if (last_observed_time) { 
    if(!cJSON_IsString(last_observed_time) && !cJSON_IsNull(last_observed_time))
    {
    goto end; //DateTime
    }
    }


    if (last_observed_time && !cJSON_IsNull(last_observed_time)) last_observed_time_local_str = strdup(last_observed_time->valuestring);

    core_v1_event_series_local_var = core_v1_event_series_create_internal (
        count_local_var,
        last_observed_time_local_str
        );

    if (!core_v1_event_series_local_var) {
        goto end;
    }

    return core_v1_event_series_local_var;
end:
    if (count_local_var) {
        free(count_local_var);
        count_local_var = NULL;
    }
    if (last_observed_time_local_str) {
        free(last_observed_time_local_str);
        last_observed_time_local_str = NULL;
    }
    return NULL;

}
