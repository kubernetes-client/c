/*
 * v2beta2_metric_target.h
 *
 * MetricTarget defines the target value, average value, or average utilization of a specific metric
 */

#ifndef _v2beta2_metric_target_H_
#define _v2beta2_metric_target_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2beta2_metric_target_t v2beta2_metric_target_t;




typedef struct v2beta2_metric_target_t {
    int average_utilization; //numeric
    char *average_value; // string
    char *type; // string
    char *value; // string

} v2beta2_metric_target_t;

v2beta2_metric_target_t *v2beta2_metric_target_create(
    int average_utilization,
    char *average_value,
    char *type,
    char *value
);

void v2beta2_metric_target_free(v2beta2_metric_target_t *v2beta2_metric_target);

v2beta2_metric_target_t *v2beta2_metric_target_parseFromJSON(cJSON *v2beta2_metric_targetJSON);

cJSON *v2beta2_metric_target_convertToJSON(v2beta2_metric_target_t *v2beta2_metric_target);

#endif /* _v2beta2_metric_target_H_ */

