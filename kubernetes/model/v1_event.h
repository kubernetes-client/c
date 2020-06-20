/*
 * v1_event.h
 *
 * Event is a report of an event somewhere in the cluster.
 */

#ifndef _v1_event_H_
#define _v1_event_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_event_t v1_event_t;

#include "v1_event_series.h"
#include "v1_event_source.h"
#include "v1_object_meta.h"
#include "v1_object_reference.h"



typedef struct v1_event_t {
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
    struct v1_event_series_t *series; //model
    struct v1_event_source_t *source; //model
    char *type; // string

} v1_event_t;

v1_event_t *v1_event_create(
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
    v1_event_series_t *series,
    v1_event_source_t *source,
    char *type
);

void v1_event_free(v1_event_t *v1_event);

v1_event_t *v1_event_parseFromJSON(cJSON *v1_eventJSON);

cJSON *v1_event_convertToJSON(v1_event_t *v1_event);

#endif /* _v1_event_H_ */

