/*
 * v1alpha1_runtime_class.h
 *
 * RuntimeClass defines a class of container runtime supported in the cluster. The RuntimeClass is used to determine which container runtime is used to run all containers in a pod. RuntimeClasses are (currently) manually defined by a user or cluster provisioner, and referenced in the PodSpec. The Kubelet is responsible for resolving the RuntimeClassName reference before running the pod.  For more details, see https://git.k8s.io/enhancements/keps/sig-node/runtime-class.md
 */

#ifndef _v1alpha1_runtime_class_H_
#define _v1alpha1_runtime_class_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_runtime_class_t v1alpha1_runtime_class_t;

#include "v1_object_meta.h"
#include "v1alpha1_runtime_class_spec.h"



typedef struct v1alpha1_runtime_class_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1alpha1_runtime_class_spec_t *spec; //model

} v1alpha1_runtime_class_t;

v1alpha1_runtime_class_t *v1alpha1_runtime_class_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha1_runtime_class_spec_t *spec
);

void v1alpha1_runtime_class_free(v1alpha1_runtime_class_t *v1alpha1_runtime_class);

v1alpha1_runtime_class_t *v1alpha1_runtime_class_parseFromJSON(cJSON *v1alpha1_runtime_classJSON);

cJSON *v1alpha1_runtime_class_convertToJSON(v1alpha1_runtime_class_t *v1alpha1_runtime_class);

#endif /* _v1alpha1_runtime_class_H_ */

