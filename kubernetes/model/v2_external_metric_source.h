/*
 * v2_external_metric_source.h
 *
 * ExternalMetricSource indicates how to scale on a metric not associated with any Kubernetes object (for example length of queue in cloud messaging service, or QPS from loadbalancer running outside of cluster).
 */

#ifndef _v2_external_metric_source_H_
#define _v2_external_metric_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2_external_metric_source_t v2_external_metric_source_t;

#include "v2_metric_identifier.h"
#include "v2_metric_target.h"



typedef struct v2_external_metric_source_t {
    struct v2_metric_identifier_t *metric; //model
    struct v2_metric_target_t *target; //model

} v2_external_metric_source_t;

v2_external_metric_source_t *v2_external_metric_source_create(
    v2_metric_identifier_t *metric,
    v2_metric_target_t *target
);

void v2_external_metric_source_free(v2_external_metric_source_t *v2_external_metric_source);

v2_external_metric_source_t *v2_external_metric_source_parseFromJSON(cJSON *v2_external_metric_sourceJSON);

cJSON *v2_external_metric_source_convertToJSON(v2_external_metric_source_t *v2_external_metric_source);

#endif /* _v2_external_metric_source_H_ */

