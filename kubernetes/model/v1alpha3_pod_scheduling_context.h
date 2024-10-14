/*
 * v1alpha3_pod_scheduling_context.h
 *
 * PodSchedulingContext objects hold information that is needed to schedule a Pod with ResourceClaims that use \&quot;WaitForFirstConsumer\&quot; allocation mode.  This is an alpha type and requires enabling the DRAControlPlaneController feature gate.
 */

#ifndef _v1alpha3_pod_scheduling_context_H_
#define _v1alpha3_pod_scheduling_context_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_pod_scheduling_context_t v1alpha3_pod_scheduling_context_t;

#include "v1_object_meta.h"
#include "v1alpha3_pod_scheduling_context_spec.h"
#include "v1alpha3_pod_scheduling_context_status.h"



typedef struct v1alpha3_pod_scheduling_context_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1alpha3_pod_scheduling_context_spec_t *spec; //model
    struct v1alpha3_pod_scheduling_context_status_t *status; //model

} v1alpha3_pod_scheduling_context_t;

v1alpha3_pod_scheduling_context_t *v1alpha3_pod_scheduling_context_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha3_pod_scheduling_context_spec_t *spec,
    v1alpha3_pod_scheduling_context_status_t *status
);

void v1alpha3_pod_scheduling_context_free(v1alpha3_pod_scheduling_context_t *v1alpha3_pod_scheduling_context);

v1alpha3_pod_scheduling_context_t *v1alpha3_pod_scheduling_context_parseFromJSON(cJSON *v1alpha3_pod_scheduling_contextJSON);

cJSON *v1alpha3_pod_scheduling_context_convertToJSON(v1alpha3_pod_scheduling_context_t *v1alpha3_pod_scheduling_context);

#endif /* _v1alpha3_pod_scheduling_context_H_ */

