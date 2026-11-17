/*
 * v1alpha3_workload_pod_group_disruption_mode.h
 *
 * WorkloadPodGroupDisruptionMode defines how individual pods within a group can be disrupted. Exactly one mode must be set.
 */

#ifndef _v1alpha3_workload_pod_group_disruption_mode_H_
#define _v1alpha3_workload_pod_group_disruption_mode_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_workload_pod_group_disruption_mode_t v1alpha3_workload_pod_group_disruption_mode_t;

#include "object.h"



typedef struct v1alpha3_workload_pod_group_disruption_mode_t {
    object_t *all; //object
    object_t *single; //object

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha3_workload_pod_group_disruption_mode_t;

__attribute__((deprecated)) v1alpha3_workload_pod_group_disruption_mode_t *v1alpha3_workload_pod_group_disruption_mode_create(
    object_t *all,
    object_t *single
);

void v1alpha3_workload_pod_group_disruption_mode_free(v1alpha3_workload_pod_group_disruption_mode_t *v1alpha3_workload_pod_group_disruption_mode);

v1alpha3_workload_pod_group_disruption_mode_t *v1alpha3_workload_pod_group_disruption_mode_parseFromJSON(cJSON *v1alpha3_workload_pod_group_disruption_modeJSON);

cJSON *v1alpha3_workload_pod_group_disruption_mode_convertToJSON(v1alpha3_workload_pod_group_disruption_mode_t *v1alpha3_workload_pod_group_disruption_mode);

#endif /* _v1alpha3_workload_pod_group_disruption_mode_H_ */

