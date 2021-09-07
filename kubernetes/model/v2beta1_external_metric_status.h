/*
 * v2beta1_external_metric_status.h
 *
 * ExternalMetricStatus indicates the current value of a global metric not associated with any Kubernetes object.
 */

#ifndef _v2beta1_external_metric_status_H_
#define _v2beta1_external_metric_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2beta1_external_metric_status_t v2beta1_external_metric_status_t;

#include "v1_label_selector.h"



typedef struct v2beta1_external_metric_status_t {
    char *current_average_value; // string
    char *current_value; // string
    char *metric_name; // string
    struct v1_label_selector_t *metric_selector; //model

} v2beta1_external_metric_status_t;

v2beta1_external_metric_status_t *v2beta1_external_metric_status_create(
    char *current_average_value,
    char *current_value,
    char *metric_name,
    v1_label_selector_t *metric_selector
);

void v2beta1_external_metric_status_free(v2beta1_external_metric_status_t *v2beta1_external_metric_status);

v2beta1_external_metric_status_t *v2beta1_external_metric_status_parseFromJSON(cJSON *v2beta1_external_metric_statusJSON);

cJSON *v2beta1_external_metric_status_convertToJSON(v2beta1_external_metric_status_t *v2beta1_external_metric_status);

#endif /* _v2beta1_external_metric_status_H_ */

