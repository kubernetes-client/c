/*
 * v1alpha1_eviction_request_spec.h
 *
 * EvictionRequestSpec is a specification of an EvictionRequest.
 */

#ifndef _v1alpha1_eviction_request_spec_H_
#define _v1alpha1_eviction_request_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_eviction_request_spec_t v1alpha1_eviction_request_spec_t;

#include "v1alpha1_eviction_request_target.h"



typedef struct v1alpha1_eviction_request_spec_t {
    char *intent; // string
    char *requester; // string
    struct v1alpha1_eviction_request_target_t *target; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha1_eviction_request_spec_t;

__attribute__((deprecated)) v1alpha1_eviction_request_spec_t *v1alpha1_eviction_request_spec_create(
    char *intent,
    char *requester,
    v1alpha1_eviction_request_target_t *target
);

void v1alpha1_eviction_request_spec_free(v1alpha1_eviction_request_spec_t *v1alpha1_eviction_request_spec);

v1alpha1_eviction_request_spec_t *v1alpha1_eviction_request_spec_parseFromJSON(cJSON *v1alpha1_eviction_request_specJSON);

cJSON *v1alpha1_eviction_request_spec_convertToJSON(v1alpha1_eviction_request_spec_t *v1alpha1_eviction_request_spec);

#endif /* _v1alpha1_eviction_request_spec_H_ */

