/*
 * v2_pods_metric_status.h
 *
 * PodsMetricStatus indicates the current value of a metric describing each pod in the current scale target (for example, transactions-processed-per-second).
 */

#ifndef _v2_pods_metric_status_H_
#define _v2_pods_metric_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2_pods_metric_status_t v2_pods_metric_status_t;

#include "v2_metric_identifier.h"
#include "v2_metric_value_status.h"



typedef struct v2_pods_metric_status_t {
    struct v2_metric_value_status_t *current; //model
    struct v2_metric_identifier_t *metric; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v2_pods_metric_status_t;

__attribute__((deprecated)) v2_pods_metric_status_t *v2_pods_metric_status_create(
    v2_metric_value_status_t *current,
    v2_metric_identifier_t *metric
);

void v2_pods_metric_status_free(v2_pods_metric_status_t *v2_pods_metric_status);

v2_pods_metric_status_t *v2_pods_metric_status_parseFromJSON(cJSON *v2_pods_metric_statusJSON);

cJSON *v2_pods_metric_status_convertToJSON(v2_pods_metric_status_t *v2_pods_metric_status);

#endif /* _v2_pods_metric_status_H_ */

