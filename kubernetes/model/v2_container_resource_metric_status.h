/*
 * v2_container_resource_metric_status.h
 *
 * ContainerResourceMetricStatus indicates the current value of a resource metric known to Kubernetes, as specified in requests and limits, describing a single container in each pod in the current scale target (e.g. CPU or memory).  Such metrics are built in to Kubernetes, and have special scaling options on top of those available to normal per-pod metrics using the \&quot;pods\&quot; source.
 */

#ifndef _v2_container_resource_metric_status_H_
#define _v2_container_resource_metric_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2_container_resource_metric_status_t v2_container_resource_metric_status_t;

#include "v2_metric_value_status.h"



typedef struct v2_container_resource_metric_status_t {
    char *container; // string
    struct v2_metric_value_status_t *current; //model
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v2_container_resource_metric_status_t;

__attribute__((deprecated)) v2_container_resource_metric_status_t *v2_container_resource_metric_status_create(
    char *container,
    v2_metric_value_status_t *current,
    char *name
);

void v2_container_resource_metric_status_free(v2_container_resource_metric_status_t *v2_container_resource_metric_status);

v2_container_resource_metric_status_t *v2_container_resource_metric_status_parseFromJSON(cJSON *v2_container_resource_metric_statusJSON);

cJSON *v2_container_resource_metric_status_convertToJSON(v2_container_resource_metric_status_t *v2_container_resource_metric_status);

#endif /* _v2_container_resource_metric_status_H_ */

