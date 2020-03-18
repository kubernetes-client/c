/*
 * v1_watch_event.h
 *
 * Event represents a single event to a watched resource.
 */

#ifndef _v1_watch_event_H_
#define _v1_watch_event_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "object.h"



typedef struct v1_watch_event_t {
    object_t *object; //object
    char *type; // string

} v1_watch_event_t;

v1_watch_event_t *v1_watch_event_create(
    object_t *object,
    char *type
);

void v1_watch_event_free(v1_watch_event_t *v1_watch_event);

v1_watch_event_t *v1_watch_event_parseFromJSON(cJSON *v1_watch_eventJSON);

cJSON *v1_watch_event_convertToJSON(v1_watch_event_t *v1_watch_event);

#endif /* _v1_watch_event_H_ */

