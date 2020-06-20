/*
 * v2beta1_object_metric_status.h
 *
 * ObjectMetricStatus indicates the current value of a metric describing a kubernetes object (for example, hits-per-second on an Ingress object).
 */

#ifndef _v2beta1_object_metric_status_H_
#define _v2beta1_object_metric_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2beta1_object_metric_status_t v2beta1_object_metric_status_t;

#include "v1_label_selector.h"
#include "v2beta1_cross_version_object_reference.h"



typedef struct v2beta1_object_metric_status_t {
    char *average_value; // string
    char *current_value; // string
    char *metric_name; // string
    struct v1_label_selector_t *selector; //model
    struct v2beta1_cross_version_object_reference_t *target; //model

} v2beta1_object_metric_status_t;

v2beta1_object_metric_status_t *v2beta1_object_metric_status_create(
    char *average_value,
    char *current_value,
    char *metric_name,
    v1_label_selector_t *selector,
    v2beta1_cross_version_object_reference_t *target
);

void v2beta1_object_metric_status_free(v2beta1_object_metric_status_t *v2beta1_object_metric_status);

v2beta1_object_metric_status_t *v2beta1_object_metric_status_parseFromJSON(cJSON *v2beta1_object_metric_statusJSON);

cJSON *v2beta1_object_metric_status_convertToJSON(v2beta1_object_metric_status_t *v2beta1_object_metric_status);

#endif /* _v2beta1_object_metric_status_H_ */

