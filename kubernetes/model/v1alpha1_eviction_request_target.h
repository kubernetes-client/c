/*
 * v1alpha1_eviction_request_target.h
 *
 * EvictionRequestTarget contains a reference to an object that should be evicted.
 */

#ifndef _v1alpha1_eviction_request_target_H_
#define _v1alpha1_eviction_request_target_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_eviction_request_target_t v1alpha1_eviction_request_target_t;

#include "v1alpha1_eviction_request_pod_reference.h"



typedef struct v1alpha1_eviction_request_target_t {
    struct v1alpha1_eviction_request_pod_reference_t *pod; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha1_eviction_request_target_t;

__attribute__((deprecated)) v1alpha1_eviction_request_target_t *v1alpha1_eviction_request_target_create(
    v1alpha1_eviction_request_pod_reference_t *pod
);

void v1alpha1_eviction_request_target_free(v1alpha1_eviction_request_target_t *v1alpha1_eviction_request_target);

v1alpha1_eviction_request_target_t *v1alpha1_eviction_request_target_parseFromJSON(cJSON *v1alpha1_eviction_request_targetJSON);

cJSON *v1alpha1_eviction_request_target_convertToJSON(v1alpha1_eviction_request_target_t *v1alpha1_eviction_request_target);

#endif /* _v1alpha1_eviction_request_target_H_ */

