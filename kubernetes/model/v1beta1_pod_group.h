/*
 * v1beta1_pod_group.h
 *
 * PodGroup represents a runtime instance of pods grouped together. PodGroups are created by workload controllers (Job, LWS, JobSet, etc...) from Workload.podGroupTemplates. PodGroup API enablement is toggled by the GenericWorkload feature gate.
 */

#ifndef _v1beta1_pod_group_H_
#define _v1beta1_pod_group_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_pod_group_t v1beta1_pod_group_t;

#include "v1_object_meta.h"
#include "v1beta1_pod_group_spec.h"
#include "v1beta1_pod_group_status.h"



typedef struct v1beta1_pod_group_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1beta1_pod_group_spec_t *spec; //model
    struct v1beta1_pod_group_status_t *status; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_pod_group_t;

__attribute__((deprecated)) v1beta1_pod_group_t *v1beta1_pod_group_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta1_pod_group_spec_t *spec,
    v1beta1_pod_group_status_t *status
);

void v1beta1_pod_group_free(v1beta1_pod_group_t *v1beta1_pod_group);

v1beta1_pod_group_t *v1beta1_pod_group_parseFromJSON(cJSON *v1beta1_pod_groupJSON);

cJSON *v1beta1_pod_group_convertToJSON(v1beta1_pod_group_t *v1beta1_pod_group);

#endif /* _v1beta1_pod_group_H_ */

