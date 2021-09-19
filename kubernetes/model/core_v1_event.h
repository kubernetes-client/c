/*
 * core_v1_event.h
 *
 * Event is a report of an event somewhere in the cluster.  Events have a limited retention time and triggers and messages may evolve with time.  Event consumers should not rely on the timing of an event with a given Reason reflecting a consistent underlying trigger, or the continued existence of events with that Reason.  Events should be treated as informative, best-effort, supplemental data.
 */

#ifndef _core_v1_event_H_
#define _core_v1_event_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct core_v1_event_t core_v1_event_t;

#include "core_v1_event_series.h"
#include "v1_event_source.h"
#include "v1_object_meta.h"
#include "v1_object_reference.h"



typedef struct core_v1_event_t {
    char *action; // string
    char *api_version; // string
    int count; //numeric
    char *event_time; //date time
    char *first_timestamp; //date time
    struct v1_object_reference_t *involved_object; //model
    char *kind; // string
    char *last_timestamp; //date time
    char *message; // string
    struct v1_object_meta_t *metadata; //model
    char *reason; // string
    struct v1_object_reference_t *related; //model
    char *reporting_component; // string
    char *reporting_instance; // string
    struct core_v1_event_series_t *series; //model
    struct v1_event_source_t *source; //model
    char *type; // string

} core_v1_event_t;

core_v1_event_t *core_v1_event_create(
    char *action,
    char *api_version,
    int count,
    char *event_time,
    char *first_timestamp,
    v1_object_reference_t *involved_object,
    char *kind,
    char *last_timestamp,
    char *message,
    v1_object_meta_t *metadata,
    char *reason,
    v1_object_reference_t *related,
    char *reporting_component,
    char *reporting_instance,
    core_v1_event_series_t *series,
    v1_event_source_t *source,
    char *type
);

void core_v1_event_free(core_v1_event_t *core_v1_event);

core_v1_event_t *core_v1_event_parseFromJSON(cJSON *core_v1_eventJSON);

cJSON *core_v1_event_convertToJSON(core_v1_event_t *core_v1_event);

#endif /* _core_v1_event_H_ */

