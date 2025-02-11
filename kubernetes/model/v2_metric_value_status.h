/*
 * v2_metric_value_status.h
 *
 * MetricValueStatus holds the current value for a metric
 */

#ifndef _v2_metric_value_status_H_
#define _v2_metric_value_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2_metric_value_status_t v2_metric_value_status_t;




typedef struct v2_metric_value_status_t {
    int average_utilization; //numeric
    char *average_value; // string
    char *value; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v2_metric_value_status_t;

__attribute__((deprecated)) v2_metric_value_status_t *v2_metric_value_status_create(
    int average_utilization,
    char *average_value,
    char *value
);

void v2_metric_value_status_free(v2_metric_value_status_t *v2_metric_value_status);

v2_metric_value_status_t *v2_metric_value_status_parseFromJSON(cJSON *v2_metric_value_statusJSON);

cJSON *v2_metric_value_status_convertToJSON(v2_metric_value_status_t *v2_metric_value_status);

#endif /* _v2_metric_value_status_H_ */

