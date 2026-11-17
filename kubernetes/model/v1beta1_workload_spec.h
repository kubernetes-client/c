/*
 * v1beta1_workload_spec.h
 *
 * WorkloadSpec defines the desired state of a Workload.
 */

#ifndef _v1beta1_workload_spec_H_
#define _v1beta1_workload_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_workload_spec_t v1beta1_workload_spec_t;

#include "v1beta1_composite_pod_group_template.h"
#include "v1beta1_pod_group_template.h"
#include "v1beta1_typed_local_object_reference.h"



typedef struct v1beta1_workload_spec_t {
    list_t *composite_pod_group_templates; //nonprimitive container
    struct v1beta1_typed_local_object_reference_t *controller_ref; //model
    list_t *pod_group_templates; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_workload_spec_t;

__attribute__((deprecated)) v1beta1_workload_spec_t *v1beta1_workload_spec_create(
    list_t *composite_pod_group_templates,
    v1beta1_typed_local_object_reference_t *controller_ref,
    list_t *pod_group_templates
);

void v1beta1_workload_spec_free(v1beta1_workload_spec_t *v1beta1_workload_spec);

v1beta1_workload_spec_t *v1beta1_workload_spec_parseFromJSON(cJSON *v1beta1_workload_specJSON);

cJSON *v1beta1_workload_spec_convertToJSON(v1beta1_workload_spec_t *v1beta1_workload_spec);

#endif /* _v1beta1_workload_spec_H_ */

