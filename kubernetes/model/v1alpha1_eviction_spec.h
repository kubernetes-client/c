/*
 * v1alpha1_eviction_spec.h
 *
 * EvictionSpec is a specification of an Eviction.
 */

#ifndef _v1alpha1_eviction_spec_H_
#define _v1alpha1_eviction_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_eviction_spec_t v1alpha1_eviction_spec_t;

#include "v1alpha1_eviction_target.h"



typedef struct v1alpha1_eviction_spec_t {
    struct v1alpha1_eviction_target_t *target; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha1_eviction_spec_t;

__attribute__((deprecated)) v1alpha1_eviction_spec_t *v1alpha1_eviction_spec_create(
    v1alpha1_eviction_target_t *target
);

void v1alpha1_eviction_spec_free(v1alpha1_eviction_spec_t *v1alpha1_eviction_spec);

v1alpha1_eviction_spec_t *v1alpha1_eviction_spec_parseFromJSON(cJSON *v1alpha1_eviction_specJSON);

cJSON *v1alpha1_eviction_spec_convertToJSON(v1alpha1_eviction_spec_t *v1alpha1_eviction_spec);

#endif /* _v1alpha1_eviction_spec_H_ */

