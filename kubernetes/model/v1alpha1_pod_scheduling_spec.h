/*
 * v1alpha1_pod_scheduling_spec.h
 *
 * PodSchedulingSpec describes where resources for the Pod are needed.
 */

#ifndef _v1alpha1_pod_scheduling_spec_H_
#define _v1alpha1_pod_scheduling_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_pod_scheduling_spec_t v1alpha1_pod_scheduling_spec_t;




typedef struct v1alpha1_pod_scheduling_spec_t {
    list_t *potential_nodes; //primitive container
    char *selected_node; // string

} v1alpha1_pod_scheduling_spec_t;

v1alpha1_pod_scheduling_spec_t *v1alpha1_pod_scheduling_spec_create(
    list_t *potential_nodes,
    char *selected_node
);

void v1alpha1_pod_scheduling_spec_free(v1alpha1_pod_scheduling_spec_t *v1alpha1_pod_scheduling_spec);

v1alpha1_pod_scheduling_spec_t *v1alpha1_pod_scheduling_spec_parseFromJSON(cJSON *v1alpha1_pod_scheduling_specJSON);

cJSON *v1alpha1_pod_scheduling_spec_convertToJSON(v1alpha1_pod_scheduling_spec_t *v1alpha1_pod_scheduling_spec);

#endif /* _v1alpha1_pod_scheduling_spec_H_ */

