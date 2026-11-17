/*
 * v1alpha3_workload.h
 *
 * Workload allows for expressing scheduling constraints that should be used when managing the lifecycle of workloads from the scheduling perspective, including scheduling, preemption, eviction and other phases. Workload API enablement is toggled by the GenericWorkload feature gate.
 */

#ifndef _v1alpha3_workload_H_
#define _v1alpha3_workload_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_workload_t v1alpha3_workload_t;

#include "v1_object_meta.h"
#include "v1alpha3_workload_spec.h"



typedef struct v1alpha3_workload_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1alpha3_workload_spec_t *spec; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha3_workload_t;

__attribute__((deprecated)) v1alpha3_workload_t *v1alpha3_workload_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha3_workload_spec_t *spec
);

void v1alpha3_workload_free(v1alpha3_workload_t *v1alpha3_workload);

v1alpha3_workload_t *v1alpha3_workload_parseFromJSON(cJSON *v1alpha3_workloadJSON);

cJSON *v1alpha3_workload_convertToJSON(v1alpha3_workload_t *v1alpha3_workload);

#endif /* _v1alpha3_workload_H_ */

