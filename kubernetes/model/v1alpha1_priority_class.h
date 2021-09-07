/*
 * v1alpha1_priority_class.h
 *
 * DEPRECATED - This group version of PriorityClass is deprecated by scheduling.k8s.io/v1/PriorityClass. PriorityClass defines mapping from a priority class name to the priority integer value. The value can be any valid integer.
 */

#ifndef _v1alpha1_priority_class_H_
#define _v1alpha1_priority_class_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_priority_class_t v1alpha1_priority_class_t;

#include "v1_object_meta.h"



typedef struct v1alpha1_priority_class_t {
    char *api_version; // string
    char *description; // string
    int global_default; //boolean
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    char *preemption_policy; // string
    int value; //numeric

} v1alpha1_priority_class_t;

v1alpha1_priority_class_t *v1alpha1_priority_class_create(
    char *api_version,
    char *description,
    int global_default,
    char *kind,
    v1_object_meta_t *metadata,
    char *preemption_policy,
    int value
);

void v1alpha1_priority_class_free(v1alpha1_priority_class_t *v1alpha1_priority_class);

v1alpha1_priority_class_t *v1alpha1_priority_class_parseFromJSON(cJSON *v1alpha1_priority_classJSON);

cJSON *v1alpha1_priority_class_convertToJSON(v1alpha1_priority_class_t *v1alpha1_priority_class);

#endif /* _v1alpha1_priority_class_H_ */

