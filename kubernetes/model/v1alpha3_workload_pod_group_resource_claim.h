/*
 * v1alpha3_workload_pod_group_resource_claim.h
 *
 * WorkloadPodGroupResourceClaim references a dynamic resource claim that is shared across pods in the group.
 */

#ifndef _v1alpha3_workload_pod_group_resource_claim_H_
#define _v1alpha3_workload_pod_group_resource_claim_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_workload_pod_group_resource_claim_t v1alpha3_workload_pod_group_resource_claim_t;




typedef struct v1alpha3_workload_pod_group_resource_claim_t {
    char *name; // string
    char *resource_claim_name; // string
    char *resource_claim_template_name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha3_workload_pod_group_resource_claim_t;

__attribute__((deprecated)) v1alpha3_workload_pod_group_resource_claim_t *v1alpha3_workload_pod_group_resource_claim_create(
    char *name,
    char *resource_claim_name,
    char *resource_claim_template_name
);

void v1alpha3_workload_pod_group_resource_claim_free(v1alpha3_workload_pod_group_resource_claim_t *v1alpha3_workload_pod_group_resource_claim);

v1alpha3_workload_pod_group_resource_claim_t *v1alpha3_workload_pod_group_resource_claim_parseFromJSON(cJSON *v1alpha3_workload_pod_group_resource_claimJSON);

cJSON *v1alpha3_workload_pod_group_resource_claim_convertToJSON(v1alpha3_workload_pod_group_resource_claim_t *v1alpha3_workload_pod_group_resource_claim);

#endif /* _v1alpha3_workload_pod_group_resource_claim_H_ */

