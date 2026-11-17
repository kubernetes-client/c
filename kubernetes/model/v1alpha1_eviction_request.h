/*
 * v1alpha1_eviction_request.h
 *
 * EvictionRequest defines a request that should ideally result in a graceful eviction of a .spec.target (e.g. termination of a pod).  The evictionrequest-controller observes intents of all EvictionRequests and transforms them into Evictions.   - .spec.requester is set as a label on the Eviction for easier lookup.   - Each target can have a set of responders assigned to it. Eviction objects are observed by     these responders, who implement the eviction logic and update the Eviction&#39;s status with     progress.  There is many-to-many relationship between EvictionRequests and Evictions in general. And many-to-one if the target is a  pod.  If all requesters withdraw their eviction intent for a common target, the eviction will be canceled. Deleting an EvictionRequest also counts as a withdrawal. Once all EvictionRequest of a target are removed, the corresponding Evictions are eventually garbage collected.
 */

#ifndef _v1alpha1_eviction_request_H_
#define _v1alpha1_eviction_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_eviction_request_t v1alpha1_eviction_request_t;

#include "v1_object_meta.h"
#include "v1alpha1_eviction_request_spec.h"
#include "v1alpha1_eviction_request_status.h"



typedef struct v1alpha1_eviction_request_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1alpha1_eviction_request_spec_t *spec; //model
    struct v1alpha1_eviction_request_status_t *status; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha1_eviction_request_t;

__attribute__((deprecated)) v1alpha1_eviction_request_t *v1alpha1_eviction_request_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha1_eviction_request_spec_t *spec,
    v1alpha1_eviction_request_status_t *status
);

void v1alpha1_eviction_request_free(v1alpha1_eviction_request_t *v1alpha1_eviction_request);

v1alpha1_eviction_request_t *v1alpha1_eviction_request_parseFromJSON(cJSON *v1alpha1_eviction_requestJSON);

cJSON *v1alpha1_eviction_request_convertToJSON(v1alpha1_eviction_request_t *v1alpha1_eviction_request);

#endif /* _v1alpha1_eviction_request_H_ */

