/*
 * v2beta2_resource_metric_source.h
 *
 * ResourceMetricSource indicates how to scale on a resource metric known to Kubernetes, as specified in requests and limits, describing each pod in the current scale target (e.g. CPU or memory).  The values will be averaged together before being compared to the target.  Such metrics are built in to Kubernetes, and have special scaling options on top of those available to normal per-pod metrics using the \&quot;pods\&quot; source.  Only one \&quot;target\&quot; type should be set.
 */

#ifndef _v2beta2_resource_metric_source_H_
#define _v2beta2_resource_metric_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2beta2_resource_metric_source_t v2beta2_resource_metric_source_t;

#include "v2beta2_metric_target.h"



typedef struct v2beta2_resource_metric_source_t {
    char *name; // string
    struct v2beta2_metric_target_t *target; //model

} v2beta2_resource_metric_source_t;

v2beta2_resource_metric_source_t *v2beta2_resource_metric_source_create(
    char *name,
    v2beta2_metric_target_t *target
);

void v2beta2_resource_metric_source_free(v2beta2_resource_metric_source_t *v2beta2_resource_metric_source);

v2beta2_resource_metric_source_t *v2beta2_resource_metric_source_parseFromJSON(cJSON *v2beta2_resource_metric_sourceJSON);

cJSON *v2beta2_resource_metric_source_convertToJSON(v2beta2_resource_metric_source_t *v2beta2_resource_metric_source);

#endif /* _v2beta2_resource_metric_source_H_ */

