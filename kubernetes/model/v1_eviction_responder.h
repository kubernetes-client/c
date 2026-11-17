/*
 * v1_eviction_responder.h
 *
 * EvictionResponder allows you to specify the responder reacting to an Eviction. Responders should observe and communicate through the Eviction Resource API to help with the graceful eviction of a target (e.g. termination of a pod).
 */

#ifndef _v1_eviction_responder_H_
#define _v1_eviction_responder_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_eviction_responder_t v1_eviction_responder_t;




typedef struct v1_eviction_responder_t {
    char *name; // string
    int *priority; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} v1_eviction_responder_t;

__attribute__((deprecated)) v1_eviction_responder_t *v1_eviction_responder_create(
    char *name,
    int *priority
);

void v1_eviction_responder_free(v1_eviction_responder_t *v1_eviction_responder);

v1_eviction_responder_t *v1_eviction_responder_parseFromJSON(cJSON *v1_eviction_responderJSON);

cJSON *v1_eviction_responder_convertToJSON(v1_eviction_responder_t *v1_eviction_responder);

#endif /* _v1_eviction_responder_H_ */

