/*
 * v2beta1_resource_metric_source.h
 *
 * ResourceMetricSource indicates how to scale on a resource metric known to Kubernetes, as specified in requests and limits, describing each pod in the current scale target (e.g. CPU or memory).  The values will be averaged together before being compared to the target.  Such metrics are built in to Kubernetes, and have special scaling options on top of those available to normal per-pod metrics using the \&quot;pods\&quot; source.  Only one \&quot;target\&quot; type should be set.
 */

#ifndef _v2beta1_resource_metric_source_H_
#define _v2beta1_resource_metric_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2beta1_resource_metric_source_t v2beta1_resource_metric_source_t;




typedef struct v2beta1_resource_metric_source_t {
    char *name; // string
    int target_average_utilization; //numeric
    char *target_average_value; // string

} v2beta1_resource_metric_source_t;

v2beta1_resource_metric_source_t *v2beta1_resource_metric_source_create(
    char *name,
    int target_average_utilization,
    char *target_average_value
);

void v2beta1_resource_metric_source_free(v2beta1_resource_metric_source_t *v2beta1_resource_metric_source);

v2beta1_resource_metric_source_t *v2beta1_resource_metric_source_parseFromJSON(cJSON *v2beta1_resource_metric_sourceJSON);

cJSON *v2beta1_resource_metric_source_convertToJSON(v2beta1_resource_metric_source_t *v2beta1_resource_metric_source);

#endif /* _v2beta1_resource_metric_source_H_ */

