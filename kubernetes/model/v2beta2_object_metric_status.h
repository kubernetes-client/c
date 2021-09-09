/*
 * v2beta2_object_metric_status.h
 *
 * ObjectMetricStatus indicates the current value of a metric describing a kubernetes object (for example, hits-per-second on an Ingress object).
 */

#ifndef _v2beta2_object_metric_status_H_
#define _v2beta2_object_metric_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2beta2_object_metric_status_t v2beta2_object_metric_status_t;

#include "v2beta2_cross_version_object_reference.h"
#include "v2beta2_metric_identifier.h"
#include "v2beta2_metric_value_status.h"



typedef struct v2beta2_object_metric_status_t {
    struct v2beta2_metric_value_status_t *current; //model
    struct v2beta2_cross_version_object_reference_t *described_object; //model
    struct v2beta2_metric_identifier_t *metric; //model

} v2beta2_object_metric_status_t;

v2beta2_object_metric_status_t *v2beta2_object_metric_status_create(
    v2beta2_metric_value_status_t *current,
    v2beta2_cross_version_object_reference_t *described_object,
    v2beta2_metric_identifier_t *metric
);

void v2beta2_object_metric_status_free(v2beta2_object_metric_status_t *v2beta2_object_metric_status);

v2beta2_object_metric_status_t *v2beta2_object_metric_status_parseFromJSON(cJSON *v2beta2_object_metric_statusJSON);

cJSON *v2beta2_object_metric_status_convertToJSON(v2beta2_object_metric_status_t *v2beta2_object_metric_status);

#endif /* _v2beta2_object_metric_status_H_ */

