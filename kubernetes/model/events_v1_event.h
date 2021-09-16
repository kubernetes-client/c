/*
 * events_v1_event.h
 *
 * Event is a report of an event somewhere in the cluster. It generally denotes some state change in the system. Events have a limited retention time and triggers and messages may evolve with time.  Event consumers should not rely on the timing of an event with a given Reason reflecting a consistent underlying trigger, or the continued existence of events with that Reason.  Events should be treated as informative, best-effort, supplemental data.
 */

#ifndef _events_v1_event_H_
#define _events_v1_event_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct events_v1_event_t events_v1_event_t;

#include "events_v1_event_series.h"
#include "v1_event_source.h"
#include "v1_object_meta.h"
#include "v1_object_reference.h"



typedef struct events_v1_event_t {
    char *action; // string
    char *api_version; // string
    int deprecated_count; //numeric
    char *deprecated_first_timestamp; //date time
    char *deprecated_last_timestamp; //date time
    struct v1_event_source_t *deprecated_source; //model
    char *event_time; //date time
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    char *note; // string
    char *reason; // string
    struct v1_object_reference_t *regarding; //model
    struct v1_object_reference_t *related; //model
    char *reporting_controller; // string
    char *reporting_instance; // string
    struct events_v1_event_series_t *series; //model
    char *type; // string

} events_v1_event_t;

events_v1_event_t *events_v1_event_create(
    char *action,
    char *api_version,
    int deprecated_count,
    char *deprecated_first_timestamp,
    char *deprecated_last_timestamp,
    v1_event_source_t *deprecated_source,
    char *event_time,
    char *kind,
    v1_object_meta_t *metadata,
    char *note,
    char *reason,
    v1_object_reference_t *regarding,
    v1_object_reference_t *related,
    char *reporting_controller,
    char *reporting_instance,
    events_v1_event_series_t *series,
    char *type
);

void events_v1_event_free(events_v1_event_t *events_v1_event);

events_v1_event_t *events_v1_event_parseFromJSON(cJSON *events_v1_eventJSON);

cJSON *events_v1_event_convertToJSON(events_v1_event_t *events_v1_event);

#endif /* _events_v1_event_H_ */

