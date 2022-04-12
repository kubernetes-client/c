/*
 * v2_external_metric_status.h
 *
 * ExternalMetricStatus indicates the current value of a global metric not associated with any Kubernetes object.
 */

#ifndef _v2_external_metric_status_H_
#define _v2_external_metric_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2_external_metric_status_t v2_external_metric_status_t;

#include "v2_metric_identifier.h"
#include "v2_metric_value_status.h"



typedef struct v2_external_metric_status_t {
    struct v2_metric_value_status_t *current; //model
    struct v2_metric_identifier_t *metric; //model

} v2_external_metric_status_t;

v2_external_metric_status_t *v2_external_metric_status_create(
    v2_metric_value_status_t *current,
    v2_metric_identifier_t *metric
);

void v2_external_metric_status_free(v2_external_metric_status_t *v2_external_metric_status);

v2_external_metric_status_t *v2_external_metric_status_parseFromJSON(cJSON *v2_external_metric_statusJSON);

cJSON *v2_external_metric_status_convertToJSON(v2_external_metric_status_t *v2_external_metric_status);

#endif /* _v2_external_metric_status_H_ */

