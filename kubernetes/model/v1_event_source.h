/*
 * v1_event_source.h
 *
 * EventSource contains information for an event.
 */

#ifndef _v1_event_source_H_
#define _v1_event_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_event_source_t v1_event_source_t;




typedef struct v1_event_source_t {
    char *component; // string
    char *host; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_event_source_t;

__attribute__((deprecated)) v1_event_source_t *v1_event_source_create(
    char *component,
    char *host
);

void v1_event_source_free(v1_event_source_t *v1_event_source);

v1_event_source_t *v1_event_source_parseFromJSON(cJSON *v1_event_sourceJSON);

cJSON *v1_event_source_convertToJSON(v1_event_source_t *v1_event_source);

#endif /* _v1_event_source_H_ */

