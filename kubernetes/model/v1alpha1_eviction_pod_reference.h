/*
 * v1alpha1_eviction_pod_reference.h
 *
 * EvictionPodReference contains enough information to locate the referenced pod inside the same namespace.
 */

#ifndef _v1alpha1_eviction_pod_reference_H_
#define _v1alpha1_eviction_pod_reference_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_eviction_pod_reference_t v1alpha1_eviction_pod_reference_t;




typedef struct v1alpha1_eviction_pod_reference_t {
    char *name; // string
    char *uid; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha1_eviction_pod_reference_t;

__attribute__((deprecated)) v1alpha1_eviction_pod_reference_t *v1alpha1_eviction_pod_reference_create(
    char *name,
    char *uid
);

void v1alpha1_eviction_pod_reference_free(v1alpha1_eviction_pod_reference_t *v1alpha1_eviction_pod_reference);

v1alpha1_eviction_pod_reference_t *v1alpha1_eviction_pod_reference_parseFromJSON(cJSON *v1alpha1_eviction_pod_referenceJSON);

cJSON *v1alpha1_eviction_pod_reference_convertToJSON(v1alpha1_eviction_pod_reference_t *v1alpha1_eviction_pod_reference);

#endif /* _v1alpha1_eviction_pod_reference_H_ */

