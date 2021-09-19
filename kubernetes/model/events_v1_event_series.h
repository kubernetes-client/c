/*
 * events_v1_event_series.h
 *
 * EventSeries contain information on series of events, i.e. thing that was/is happening continuously for some time. How often to update the EventSeries is up to the event reporters. The default event reporter in \&quot;k8s.io/client-go/tools/events/event_broadcaster.go\&quot; shows how this struct is updated on heartbeats and can guide customized reporter implementations.
 */

#ifndef _events_v1_event_series_H_
#define _events_v1_event_series_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct events_v1_event_series_t events_v1_event_series_t;




typedef struct events_v1_event_series_t {
    int count; //numeric
    char *last_observed_time; //date time

} events_v1_event_series_t;

events_v1_event_series_t *events_v1_event_series_create(
    int count,
    char *last_observed_time
);

void events_v1_event_series_free(events_v1_event_series_t *events_v1_event_series);

events_v1_event_series_t *events_v1_event_series_parseFromJSON(cJSON *events_v1_event_seriesJSON);

cJSON *events_v1_event_series_convertToJSON(events_v1_event_series_t *events_v1_event_series);

#endif /* _events_v1_event_series_H_ */

