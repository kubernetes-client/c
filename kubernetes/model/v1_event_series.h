/*
 * v1_event_series.h
 *
 * EventSeries contain information on series of events, i.e. thing that was/is happening continuously for some time.
 */

#ifndef _v1_event_series_H_
#define _v1_event_series_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_event_series_t v1_event_series_t;




typedef struct v1_event_series_t {
    int count; //numeric
    char *last_observed_time; //date time
    char *state; // string

} v1_event_series_t;

v1_event_series_t *v1_event_series_create(
    int count,
    char *last_observed_time,
    char *state
);

void v1_event_series_free(v1_event_series_t *v1_event_series);

v1_event_series_t *v1_event_series_parseFromJSON(cJSON *v1_event_seriesJSON);

cJSON *v1_event_series_convertToJSON(v1_event_series_t *v1_event_series);

#endif /* _v1_event_series_H_ */

