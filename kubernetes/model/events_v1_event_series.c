#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "events_v1_event_series.h"



static events_v1_event_series_t *events_v1_event_series_create_internal(
    int *count,
    char *last_observed_time
    ) {
    events_v1_event_series_t *events_v1_event_series_local_var = malloc(sizeof(events_v1_event_series_t));
    if (!events_v1_event_series_local_var) {
        return NULL;
    }
    memset(events_v1_event_series_local_var, 0, sizeof(events_v1_event_series_t));
    events_v1_event_series_local_var->_library_owned = 1;
    events_v1_event_series_local_var->count = count;
    events_v1_event_series_local_var->last_observed_time = last_observed_time;
    return events_v1_event_series_local_var;
}

__attribute__((deprecated)) events_v1_event_series_t *events_v1_event_series_create(
    int *count,
    char *last_observed_time
    ) {
    int *count_copy = NULL;
    if (count) {
        count_copy = malloc(sizeof(int));
        if (count_copy) *count_copy = *count;
    }
    events_v1_event_series_t *result = events_v1_event_series_create_internal (
        count_copy,
        last_observed_time
        );
    if (!result) {
        free(count_copy);
    }
    return result;
}

void events_v1_event_series_free(events_v1_event_series_t *events_v1_event_series) {
    if(NULL == events_v1_event_series){
        return ;
    }
    if(events_v1_event_series->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "events_v1_event_series_free");
        return ;
    }
    listEntry_t *listEntry;
    if (events_v1_event_series->count) {
        free(events_v1_event_series->count);
        events_v1_event_series->count = NULL;
    }
    if (events_v1_event_series->last_observed_time) {
        free(events_v1_event_series->last_observed_time);
        events_v1_event_series->last_observed_time = NULL;
    }
    free(events_v1_event_series);
}

cJSON *events_v1_event_series_convertToJSON(events_v1_event_series_t *events_v1_event_series) {
    cJSON *item = cJSON_CreateObject();

    // events_v1_event_series->count
    if (!events_v1_event_series->count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "count", *events_v1_event_series->count) == NULL) {
    goto fail; //Numeric
    }


    // events_v1_event_series->last_observed_time
    if (!events_v1_event_series->last_observed_time) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "lastObservedTime", events_v1_event_series->last_observed_time) == NULL) {
    goto fail; //Date-Time
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

events_v1_event_series_t *events_v1_event_series_parseFromJSON(cJSON *events_v1_event_seriesJSON){

    events_v1_event_series_t *events_v1_event_series_local_var = NULL;

    // define the local variable for events_v1_event_series->count
    int *count_local_var = NULL;

    char *last_observed_time_local_str = NULL;

    // events_v1_event_series->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(events_v1_event_seriesJSON, "count");
    if (cJSON_IsNull(count)) {
        count = NULL;
    }
    if (!count) {
        goto end;
    }

    
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

    // events_v1_event_series->last_observed_time
    cJSON *last_observed_time = cJSON_GetObjectItemCaseSensitive(events_v1_event_seriesJSON, "lastObservedTime");
    if (cJSON_IsNull(last_observed_time)) {
        last_observed_time = NULL;
    }
    if (!last_observed_time) {
        goto end;
    }

    
    if(!cJSON_IsString(last_observed_time) && !cJSON_IsNull(last_observed_time))
    {
    goto end; //DateTime
    }


    if (last_observed_time && !cJSON_IsNull(last_observed_time)) last_observed_time_local_str = strdup(last_observed_time->valuestring);

    events_v1_event_series_local_var = events_v1_event_series_create_internal (
        count_local_var,
        last_observed_time_local_str
        );

    if (!events_v1_event_series_local_var) {
        goto end;
    }

    return events_v1_event_series_local_var;
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
