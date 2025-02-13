/*
 * v2_metric_status.h
 *
 * MetricStatus describes the last-read state of a single metric.
 */

#ifndef _v2_metric_status_H_
#define _v2_metric_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2_metric_status_t v2_metric_status_t;

#include "v2_container_resource_metric_status.h"
#include "v2_external_metric_status.h"
#include "v2_object_metric_status.h"
#include "v2_pods_metric_status.h"
#include "v2_resource_metric_status.h"



typedef struct v2_metric_status_t {
    struct v2_container_resource_metric_status_t *container_resource; //model
    struct v2_external_metric_status_t *external; //model
    struct v2_object_metric_status_t *object; //model
    struct v2_pods_metric_status_t *pods; //model
    struct v2_resource_metric_status_t *resource; //model
    char *type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v2_metric_status_t;

__attribute__((deprecated)) v2_metric_status_t *v2_metric_status_create(
    v2_container_resource_metric_status_t *container_resource,
    v2_external_metric_status_t *external,
    v2_object_metric_status_t *object,
    v2_pods_metric_status_t *pods,
    v2_resource_metric_status_t *resource,
    char *type
);

void v2_metric_status_free(v2_metric_status_t *v2_metric_status);

v2_metric_status_t *v2_metric_status_parseFromJSON(cJSON *v2_metric_statusJSON);

cJSON *v2_metric_status_convertToJSON(v2_metric_status_t *v2_metric_status);

#endif /* _v2_metric_status_H_ */

