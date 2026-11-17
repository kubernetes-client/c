/*
 * v1alpha3_composite_pod_group.h
 *
 * CompositePodGroup represents a runtime instance of pod groups grouped together. CompositePodGroups are created by workload controllers (LWS, JobSet, etc...) from Workload.compositePodGroupTemplates. CompositePodGroup API enablement is toggled by the CompositePodGroup feature gate.
 */

#ifndef _v1alpha3_composite_pod_group_H_
#define _v1alpha3_composite_pod_group_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_composite_pod_group_t v1alpha3_composite_pod_group_t;

#include "v1_object_meta.h"
#include "v1alpha3_composite_pod_group_spec.h"
#include "v1alpha3_composite_pod_group_status.h"



typedef struct v1alpha3_composite_pod_group_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1alpha3_composite_pod_group_spec_t *spec; //model
    struct v1alpha3_composite_pod_group_status_t *status; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha3_composite_pod_group_t;

__attribute__((deprecated)) v1alpha3_composite_pod_group_t *v1alpha3_composite_pod_group_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha3_composite_pod_group_spec_t *spec,
    v1alpha3_composite_pod_group_status_t *status
);

void v1alpha3_composite_pod_group_free(v1alpha3_composite_pod_group_t *v1alpha3_composite_pod_group);

v1alpha3_composite_pod_group_t *v1alpha3_composite_pod_group_parseFromJSON(cJSON *v1alpha3_composite_pod_groupJSON);

cJSON *v1alpha3_composite_pod_group_convertToJSON(v1alpha3_composite_pod_group_t *v1alpha3_composite_pod_group);

#endif /* _v1alpha3_composite_pod_group_H_ */

