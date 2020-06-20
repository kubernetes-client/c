/*
 * v1beta1_event.h
 *
 * Event is a report of an event somewhere in the cluster. It generally denotes some state change in the system.
 */

#ifndef _v1beta1_event_H_
#define _v1beta1_event_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_event_t v1beta1_event_t;

#include "v1_event_source.h"
#include "v1_object_meta.h"
#include "v1_object_reference.h"
#include "v1beta1_event_series.h"



typedef struct v1beta1_event_t {
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
    struct v1beta1_event_series_t *series; //model
    char *type; // string

} v1beta1_event_t;

v1beta1_event_t *v1beta1_event_create(
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
    v1beta1_event_series_t *series,
    char *type
);

void v1beta1_event_free(v1beta1_event_t *v1beta1_event);

v1beta1_event_t *v1beta1_event_parseFromJSON(cJSON *v1beta1_eventJSON);

cJSON *v1beta1_event_convertToJSON(v1beta1_event_t *v1beta1_event);

#endif /* _v1beta1_event_H_ */

