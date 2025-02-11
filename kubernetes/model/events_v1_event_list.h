/*
 * events_v1_event_list.h
 *
 * EventList is a list of Event objects.
 */

#ifndef _events_v1_event_list_H_
#define _events_v1_event_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct events_v1_event_list_t events_v1_event_list_t;

#include "events_v1_event.h"
#include "v1_list_meta.h"



typedef struct events_v1_event_list_t {
    char *api_version; // string
    list_t *items; //nonprimitive container
    char *kind; // string
    struct v1_list_meta_t *metadata; //model

    int _library_owned; // Is the library responsible for freeing this object?
} events_v1_event_list_t;

__attribute__((deprecated)) events_v1_event_list_t *events_v1_event_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
);

void events_v1_event_list_free(events_v1_event_list_t *events_v1_event_list);

events_v1_event_list_t *events_v1_event_list_parseFromJSON(cJSON *events_v1_event_listJSON);

cJSON *events_v1_event_list_convertToJSON(events_v1_event_list_t *events_v1_event_list);

#endif /* _events_v1_event_list_H_ */

