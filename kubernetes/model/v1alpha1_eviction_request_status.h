/*
 * v1alpha1_eviction_request_status.h
 *
 * EvictionRequestStatus represents the last observed status of the eviction request.
 */

#ifndef _v1alpha1_eviction_request_status_H_
#define _v1alpha1_eviction_request_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_eviction_request_status_t v1alpha1_eviction_request_status_t;

#include "v1_condition.h"



typedef struct v1alpha1_eviction_request_status_t {
    list_t *conditions; //nonprimitive container
    long *observed_generation; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha1_eviction_request_status_t;

__attribute__((deprecated)) v1alpha1_eviction_request_status_t *v1alpha1_eviction_request_status_create(
    list_t *conditions,
    long *observed_generation
);

void v1alpha1_eviction_request_status_free(v1alpha1_eviction_request_status_t *v1alpha1_eviction_request_status);

v1alpha1_eviction_request_status_t *v1alpha1_eviction_request_status_parseFromJSON(cJSON *v1alpha1_eviction_request_statusJSON);

cJSON *v1alpha1_eviction_request_status_convertToJSON(v1alpha1_eviction_request_status_t *v1alpha1_eviction_request_status);

#endif /* _v1alpha1_eviction_request_status_H_ */

