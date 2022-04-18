#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "events_v1_event_series.h"



events_v1_event_series_t *events_v1_event_series_create(
    int count,
    char *last_observed_time
    ) {
    events_v1_event_series_t *events_v1_event_series_local_var = malloc(sizeof(events_v1_event_series_t));
    if (!events_v1_event_series_local_var) {
        return NULL;
    }
    events_v1_event_series_local_var->count = count;
    events_v1_event_series_local_var->last_observed_time = last_observed_time;

    return events_v1_event_series_local_var;
}


void events_v1_event_series_free(events_v1_event_series_t *events_v1_event_series) {
    if(NULL == events_v1_event_series){
        return ;
    }
    listEntry_t *listEntry;
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
    if(cJSON_AddNumberToObject(item, "count", events_v1_event_series->count) == NULL) {
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

    // events_v1_event_series->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(events_v1_event_seriesJSON, "count");
    if (!count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(count))
    {
    goto end; //Numeric
    }

    // events_v1_event_series->last_observed_time
    cJSON *last_observed_time = cJSON_GetObjectItemCaseSensitive(events_v1_event_seriesJSON, "lastObservedTime");
    if (!last_observed_time) {
        goto end;
    }

    
    if(!cJSON_IsString(last_observed_time))
    {
    goto end; //DateTime
    }


    events_v1_event_series_local_var = events_v1_event_series_create (
        count->valuedouble,
        strdup(last_observed_time->valuestring)
        );

    return events_v1_event_series_local_var;
end:
    return NULL;

}
