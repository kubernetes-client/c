/*
 * v2_metric_spec.h
 *
 * MetricSpec specifies how to scale based on a single metric (only &#x60;type&#x60; and one other matching field should be set at once).
 */

#ifndef _v2_metric_spec_H_
#define _v2_metric_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2_metric_spec_t v2_metric_spec_t;

#include "v2_container_resource_metric_source.h"
#include "v2_external_metric_source.h"
#include "v2_object_metric_source.h"
#include "v2_pods_metric_source.h"
#include "v2_resource_metric_source.h"



typedef struct v2_metric_spec_t {
    struct v2_container_resource_metric_source_t *container_resource; //model
    struct v2_external_metric_source_t *external; //model
    struct v2_object_metric_source_t *object; //model
    struct v2_pods_metric_source_t *pods; //model
    struct v2_resource_metric_source_t *resource; //model
    char *type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v2_metric_spec_t;

__attribute__((deprecated)) v2_metric_spec_t *v2_metric_spec_create(
    v2_container_resource_metric_source_t *container_resource,
    v2_external_metric_source_t *external,
    v2_object_metric_source_t *object,
    v2_pods_metric_source_t *pods,
    v2_resource_metric_source_t *resource,
    char *type
);

void v2_metric_spec_free(v2_metric_spec_t *v2_metric_spec);

v2_metric_spec_t *v2_metric_spec_parseFromJSON(cJSON *v2_metric_specJSON);

cJSON *v2_metric_spec_convertToJSON(v2_metric_spec_t *v2_metric_spec);

#endif /* _v2_metric_spec_H_ */

