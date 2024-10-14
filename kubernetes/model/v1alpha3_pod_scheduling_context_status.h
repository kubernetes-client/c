/*
 * v1alpha3_pod_scheduling_context_status.h
 *
 * PodSchedulingContextStatus describes where resources for the Pod can be allocated.
 */

#ifndef _v1alpha3_pod_scheduling_context_status_H_
#define _v1alpha3_pod_scheduling_context_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_pod_scheduling_context_status_t v1alpha3_pod_scheduling_context_status_t;

#include "v1alpha3_resource_claim_scheduling_status.h"



typedef struct v1alpha3_pod_scheduling_context_status_t {
    list_t *resource_claims; //nonprimitive container

} v1alpha3_pod_scheduling_context_status_t;

v1alpha3_pod_scheduling_context_status_t *v1alpha3_pod_scheduling_context_status_create(
    list_t *resource_claims
);

void v1alpha3_pod_scheduling_context_status_free(v1alpha3_pod_scheduling_context_status_t *v1alpha3_pod_scheduling_context_status);

v1alpha3_pod_scheduling_context_status_t *v1alpha3_pod_scheduling_context_status_parseFromJSON(cJSON *v1alpha3_pod_scheduling_context_statusJSON);

cJSON *v1alpha3_pod_scheduling_context_status_convertToJSON(v1alpha3_pod_scheduling_context_status_t *v1alpha3_pod_scheduling_context_status);

#endif /* _v1alpha3_pod_scheduling_context_status_H_ */

