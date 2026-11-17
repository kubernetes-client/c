/*
 * v1alpha1_eviction.h
 *
 * Eviction initiates an eviction process, which should ideally result in a graceful eviction of a .spec.target (e.g. termination of a pod).  The evictionrequest-controller observes intents of all EvictionRequests and transforms them into Evictions. It manages the Eviction lifecycle. Requesters are preserved in .status.requesters even after they have withdrawn their request. If all requesters withdraw their eviction intent for a common target, the eviction will be canceled. Once all EvictionRequest corresponding to this Eviction .spec.target have been removed, this Eviction object will eventually be garbage collected.  If the target is a pod, the .status.targetResponders is populated from Pod&#39;s .spec.evictionResponders.  Responders should observe and communicate through the .status to help with the eviction of the target when they see their state &#x3D;&#x3D; Active in .status.targetResponders. ResponderStatus struct should then be periodically updated to indicate the progress or completion of the eviction process by each responder in .status.responders. If .status.responders[].heartbeatTime is not updated within the heartbeat deadline defined by the Eviction API (currently 20 minutes), the eviction is passed over to the next responder with a lower priority.  If there are no other responders and the target is a pod, the last default imperative-eviction.k8s.io/evictor responder with a priority of 100 will evict the pod using the imperative Eviction API (pods/&lt;name&gt;/eviction subresource).
 */

#ifndef _v1alpha1_eviction_H_
#define _v1alpha1_eviction_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_eviction_t v1alpha1_eviction_t;

#include "v1_object_meta.h"
#include "v1alpha1_eviction_spec.h"
#include "v1alpha1_eviction_status.h"



typedef struct v1alpha1_eviction_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1alpha1_eviction_spec_t *spec; //model
    struct v1alpha1_eviction_status_t *status; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha1_eviction_t;

__attribute__((deprecated)) v1alpha1_eviction_t *v1alpha1_eviction_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha1_eviction_spec_t *spec,
    v1alpha1_eviction_status_t *status
);

void v1alpha1_eviction_free(v1alpha1_eviction_t *v1alpha1_eviction);

v1alpha1_eviction_t *v1alpha1_eviction_parseFromJSON(cJSON *v1alpha1_evictionJSON);

cJSON *v1alpha1_eviction_convertToJSON(v1alpha1_eviction_t *v1alpha1_eviction);

#endif /* _v1alpha1_eviction_H_ */

