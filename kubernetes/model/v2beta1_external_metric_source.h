/*
 * v2beta1_external_metric_source.h
 *
 * ExternalMetricSource indicates how to scale on a metric not associated with any Kubernetes object (for example length of queue in cloud messaging service, or QPS from loadbalancer running outside of cluster). Exactly one \&quot;target\&quot; type should be set.
 */

#ifndef _v2beta1_external_metric_source_H_
#define _v2beta1_external_metric_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2beta1_external_metric_source_t v2beta1_external_metric_source_t;

#include "v1_label_selector.h"



typedef struct v2beta1_external_metric_source_t {
    char *metric_name; // string
    struct v1_label_selector_t *metric_selector; //model
    char *target_average_value; // string
    char *target_value; // string

} v2beta1_external_metric_source_t;

v2beta1_external_metric_source_t *v2beta1_external_metric_source_create(
    char *metric_name,
    v1_label_selector_t *metric_selector,
    char *target_average_value,
    char *target_value
);

void v2beta1_external_metric_source_free(v2beta1_external_metric_source_t *v2beta1_external_metric_source);

v2beta1_external_metric_source_t *v2beta1_external_metric_source_parseFromJSON(cJSON *v2beta1_external_metric_sourceJSON);

cJSON *v2beta1_external_metric_source_convertToJSON(v2beta1_external_metric_source_t *v2beta1_external_metric_source);

#endif /* _v2beta1_external_metric_source_H_ */

