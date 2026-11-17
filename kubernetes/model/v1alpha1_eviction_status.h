/*
 * v1alpha1_eviction_status.h
 *
 * EvictionStatus represents the last observed status of the eviction request.
 */

#ifndef _v1alpha1_eviction_status_H_
#define _v1alpha1_eviction_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_eviction_status_t v1alpha1_eviction_status_t;

#include "v1_condition.h"
#include "v1alpha1_requester.h"
#include "v1alpha1_responder_status.h"
#include "v1alpha1_target_responder.h"



typedef struct v1alpha1_eviction_status_t {
    list_t *conditions; //nonprimitive container
    long *observed_generation; //numeric
    list_t *requesters; //nonprimitive container
    list_t *responders; //nonprimitive container
    list_t *target_responders; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha1_eviction_status_t;

__attribute__((deprecated)) v1alpha1_eviction_status_t *v1alpha1_eviction_status_create(
    list_t *conditions,
    long *observed_generation,
    list_t *requesters,
    list_t *responders,
    list_t *target_responders
);

void v1alpha1_eviction_status_free(v1alpha1_eviction_status_t *v1alpha1_eviction_status);

v1alpha1_eviction_status_t *v1alpha1_eviction_status_parseFromJSON(cJSON *v1alpha1_eviction_statusJSON);

cJSON *v1alpha1_eviction_status_convertToJSON(v1alpha1_eviction_status_t *v1alpha1_eviction_status);

#endif /* _v1alpha1_eviction_status_H_ */

