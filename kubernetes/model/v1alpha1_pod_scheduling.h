/*
 * v1alpha1_pod_scheduling.h
 *
 * PodScheduling objects hold information that is needed to schedule a Pod with ResourceClaims that use \&quot;WaitForFirstConsumer\&quot; allocation mode.  This is an alpha type and requires enabling the DynamicResourceAllocation feature gate.
 */

#ifndef _v1alpha1_pod_scheduling_H_
#define _v1alpha1_pod_scheduling_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_pod_scheduling_t v1alpha1_pod_scheduling_t;

#include "v1_object_meta.h"
#include "v1alpha1_pod_scheduling_spec.h"
#include "v1alpha1_pod_scheduling_status.h"



typedef struct v1alpha1_pod_scheduling_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1alpha1_pod_scheduling_spec_t *spec; //model
    struct v1alpha1_pod_scheduling_status_t *status; //model

} v1alpha1_pod_scheduling_t;

v1alpha1_pod_scheduling_t *v1alpha1_pod_scheduling_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha1_pod_scheduling_spec_t *spec,
    v1alpha1_pod_scheduling_status_t *status
);

void v1alpha1_pod_scheduling_free(v1alpha1_pod_scheduling_t *v1alpha1_pod_scheduling);

v1alpha1_pod_scheduling_t *v1alpha1_pod_scheduling_parseFromJSON(cJSON *v1alpha1_pod_schedulingJSON);

cJSON *v1alpha1_pod_scheduling_convertToJSON(v1alpha1_pod_scheduling_t *v1alpha1_pod_scheduling);

#endif /* _v1alpha1_pod_scheduling_H_ */

