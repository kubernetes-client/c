/*
 * v1_job_scheduling_configuration.h
 *
 * JobSchedulingConfiguration composes the reusable workload-aware scheduling building blocks.
 */

#ifndef _v1_job_scheduling_configuration_H_
#define _v1_job_scheduling_configuration_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_job_scheduling_configuration_t v1_job_scheduling_configuration_t;

#include "v1alpha3_workload_pod_group_disruption_mode.h"
#include "v1alpha3_workload_pod_group_resource_claim.h"
#include "v1alpha3_workload_pod_group_scheduling_constraints.h"
#include "v1alpha3_workload_pod_group_scheduling_policy.h"



typedef struct v1_job_scheduling_configuration_t {
    struct v1alpha3_workload_pod_group_disruption_mode_t *disruption_mode; //model
    list_t *resource_claims; //nonprimitive container
    struct v1alpha3_workload_pod_group_scheduling_constraints_t *scheduling_constraints; //model
    struct v1alpha3_workload_pod_group_scheduling_policy_t *scheduling_policy; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1_job_scheduling_configuration_t;

__attribute__((deprecated)) v1_job_scheduling_configuration_t *v1_job_scheduling_configuration_create(
    v1alpha3_workload_pod_group_disruption_mode_t *disruption_mode,
    list_t *resource_claims,
    v1alpha3_workload_pod_group_scheduling_constraints_t *scheduling_constraints,
    v1alpha3_workload_pod_group_scheduling_policy_t *scheduling_policy
);

void v1_job_scheduling_configuration_free(v1_job_scheduling_configuration_t *v1_job_scheduling_configuration);

v1_job_scheduling_configuration_t *v1_job_scheduling_configuration_parseFromJSON(cJSON *v1_job_scheduling_configurationJSON);

cJSON *v1_job_scheduling_configuration_convertToJSON(v1_job_scheduling_configuration_t *v1_job_scheduling_configuration);

#endif /* _v1_job_scheduling_configuration_H_ */

