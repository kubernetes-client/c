/*
 * core_v1_event_list.h
 *
 * EventList is a list of events.
 */

#ifndef _core_v1_event_list_H_
#define _core_v1_event_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct core_v1_event_list_t core_v1_event_list_t;

#include "core_v1_event.h"
#include "v1_list_meta.h"



typedef struct core_v1_event_list_t {
    char *api_version; // string
    list_t *items; //nonprimitive container
    char *kind; // string
    struct v1_list_meta_t *metadata; //model

    int _library_owned; // Is the library responsible for freeing this object?
} core_v1_event_list_t;

__attribute__((deprecated)) core_v1_event_list_t *core_v1_event_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
);

void core_v1_event_list_free(core_v1_event_list_t *core_v1_event_list);

core_v1_event_list_t *core_v1_event_list_parseFromJSON(cJSON *core_v1_event_listJSON);

cJSON *core_v1_event_list_convertToJSON(core_v1_event_list_t *core_v1_event_list);

#endif /* _core_v1_event_list_H_ */

