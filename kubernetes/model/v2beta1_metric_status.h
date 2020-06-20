/*
 * v2beta1_metric_status.h
 *
 * MetricStatus describes the last-read state of a single metric.
 */

#ifndef _v2beta1_metric_status_H_
#define _v2beta1_metric_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2beta1_metric_status_t v2beta1_metric_status_t;

#include "v2beta1_external_metric_status.h"
#include "v2beta1_object_metric_status.h"
#include "v2beta1_pods_metric_status.h"
#include "v2beta1_resource_metric_status.h"



typedef struct v2beta1_metric_status_t {
    struct v2beta1_external_metric_status_t *external; //model
    struct v2beta1_object_metric_status_t *object; //model
    struct v2beta1_pods_metric_status_t *pods; //model
    struct v2beta1_resource_metric_status_t *resource; //model
    char *type; // string

} v2beta1_metric_status_t;

v2beta1_metric_status_t *v2beta1_metric_status_create(
    v2beta1_external_metric_status_t *external,
    v2beta1_object_metric_status_t *object,
    v2beta1_pods_metric_status_t *pods,
    v2beta1_resource_metric_status_t *resource,
    char *type
);

void v2beta1_metric_status_free(v2beta1_metric_status_t *v2beta1_metric_status);

v2beta1_metric_status_t *v2beta1_metric_status_parseFromJSON(cJSON *v2beta1_metric_statusJSON);

cJSON *v2beta1_metric_status_convertToJSON(v2beta1_metric_status_t *v2beta1_metric_status);

#endif /* _v2beta1_metric_status_H_ */

