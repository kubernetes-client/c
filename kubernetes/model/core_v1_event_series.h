/*
 * core_v1_event_series.h
 *
 * EventSeries contain information on series of events, i.e. thing that was/is happening continuously for some time.
 */

#ifndef _core_v1_event_series_H_
#define _core_v1_event_series_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct core_v1_event_series_t core_v1_event_series_t;




typedef struct core_v1_event_series_t {
    int count; //numeric
    char *last_observed_time; //date time

} core_v1_event_series_t;

core_v1_event_series_t *core_v1_event_series_create(
    int count,
    char *last_observed_time
);

void core_v1_event_series_free(core_v1_event_series_t *core_v1_event_series);

core_v1_event_series_t *core_v1_event_series_parseFromJSON(cJSON *core_v1_event_seriesJSON);

cJSON *core_v1_event_series_convertToJSON(core_v1_event_series_t *core_v1_event_series);

#endif /* _core_v1_event_series_H_ */

