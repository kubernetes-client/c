#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_event_series.h"



v1beta1_event_series_t *v1beta1_event_series_create(
    int count,
    char *last_observed_time,
    char *state
    ) {
    v1beta1_event_series_t *v1beta1_event_series_local_var = malloc(sizeof(v1beta1_event_series_t));
    if (!v1beta1_event_series_local_var) {
        return NULL;
    }
    v1beta1_event_series_local_var->count = count;
    v1beta1_event_series_local_var->last_observed_time = last_observed_time;
    v1beta1_event_series_local_var->state = state;

    return v1beta1_event_series_local_var;
}


void v1beta1_event_series_free(v1beta1_event_series_t *v1beta1_event_series) {
    if(NULL == v1beta1_event_series){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_event_series->last_observed_time) {
        free(v1beta1_event_series->last_observed_time);
        v1beta1_event_series->last_observed_time = NULL;
    }
    if (v1beta1_event_series->state) {
        free(v1beta1_event_series->state);
        v1beta1_event_series->state = NULL;
    }
    free(v1beta1_event_series);
}

cJSON *v1beta1_event_series_convertToJSON(v1beta1_event_series_t *v1beta1_event_series) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_event_series->count
    if (!v1beta1_event_series->count) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "count", v1beta1_event_series->count) == NULL) {
    goto fail; //Numeric
    }


    // v1beta1_event_series->last_observed_time
    if (!v1beta1_event_series->last_observed_time) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "lastObservedTime", v1beta1_event_series->last_observed_time) == NULL) {
    goto fail; //Date-Time
    }


    // v1beta1_event_series->state
    if (!v1beta1_event_series->state) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "state", v1beta1_event_series->state) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_event_series_t *v1beta1_event_series_parseFromJSON(cJSON *v1beta1_event_seriesJSON){

    v1beta1_event_series_t *v1beta1_event_series_local_var = NULL;

    // v1beta1_event_series->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(v1beta1_event_seriesJSON, "count");
    if (!count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(count))
    {
    goto end; //Numeric
    }

    // v1beta1_event_series->last_observed_time
    cJSON *last_observed_time = cJSON_GetObjectItemCaseSensitive(v1beta1_event_seriesJSON, "lastObservedTime");
    if (!last_observed_time) {
        goto end;
    }

    
    if(!cJSON_IsString(last_observed_time))
    {
    goto end; //DateTime
    }

    // v1beta1_event_series->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(v1beta1_event_seriesJSON, "state");
    if (!state) {
        goto end;
    }

    
    if(!cJSON_IsString(state))
    {
    goto end; //String
    }


    v1beta1_event_series_local_var = v1beta1_event_series_create (
        count->valuedouble,
        strdup(last_observed_time->valuestring),
        strdup(state->valuestring)
        );

    return v1beta1_event_series_local_var;
end:
    return NULL;

}
