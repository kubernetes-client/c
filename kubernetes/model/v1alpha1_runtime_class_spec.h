/*
 * v1alpha1_runtime_class_spec.h
 *
 * RuntimeClassSpec is a specification of a RuntimeClass. It contains parameters that are required to describe the RuntimeClass to the Container Runtime Interface (CRI) implementation, as well as any other components that need to understand how the pod will be run. The RuntimeClassSpec is immutable.
 */

#ifndef _v1alpha1_runtime_class_spec_H_
#define _v1alpha1_runtime_class_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_runtime_class_spec_t v1alpha1_runtime_class_spec_t;

#include "v1alpha1_overhead.h"
#include "v1alpha1_scheduling.h"



typedef struct v1alpha1_runtime_class_spec_t {
    struct v1alpha1_overhead_t *overhead; //model
    char *runtime_handler; // string
    struct v1alpha1_scheduling_t *scheduling; //model

} v1alpha1_runtime_class_spec_t;

v1alpha1_runtime_class_spec_t *v1alpha1_runtime_class_spec_create(
    v1alpha1_overhead_t *overhead,
    char *runtime_handler,
    v1alpha1_scheduling_t *scheduling
);

void v1alpha1_runtime_class_spec_free(v1alpha1_runtime_class_spec_t *v1alpha1_runtime_class_spec);

v1alpha1_runtime_class_spec_t *v1alpha1_runtime_class_spec_parseFromJSON(cJSON *v1alpha1_runtime_class_specJSON);

cJSON *v1alpha1_runtime_class_spec_convertToJSON(v1alpha1_runtime_class_spec_t *v1alpha1_runtime_class_spec);

#endif /* _v1alpha1_runtime_class_spec_H_ */

