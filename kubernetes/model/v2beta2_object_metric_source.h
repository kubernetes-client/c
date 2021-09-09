/*
 * v2beta2_object_metric_source.h
 *
 * ObjectMetricSource indicates how to scale on a metric describing a kubernetes object (for example, hits-per-second on an Ingress object).
 */

#ifndef _v2beta2_object_metric_source_H_
#define _v2beta2_object_metric_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2beta2_object_metric_source_t v2beta2_object_metric_source_t;

#include "v2beta2_cross_version_object_reference.h"
#include "v2beta2_metric_identifier.h"
#include "v2beta2_metric_target.h"



typedef struct v2beta2_object_metric_source_t {
    struct v2beta2_cross_version_object_reference_t *described_object; //model
    struct v2beta2_metric_identifier_t *metric; //model
    struct v2beta2_metric_target_t *target; //model

} v2beta2_object_metric_source_t;

v2beta2_object_metric_source_t *v2beta2_object_metric_source_create(
    v2beta2_cross_version_object_reference_t *described_object,
    v2beta2_metric_identifier_t *metric,
    v2beta2_metric_target_t *target
);

void v2beta2_object_metric_source_free(v2beta2_object_metric_source_t *v2beta2_object_metric_source);

v2beta2_object_metric_source_t *v2beta2_object_metric_source_parseFromJSON(cJSON *v2beta2_object_metric_sourceJSON);

cJSON *v2beta2_object_metric_source_convertToJSON(v2beta2_object_metric_source_t *v2beta2_object_metric_source);

#endif /* _v2beta2_object_metric_source_H_ */

