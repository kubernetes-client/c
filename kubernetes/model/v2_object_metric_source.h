/*
 * v2_object_metric_source.h
 *
 * ObjectMetricSource indicates how to scale on a metric describing a kubernetes object (for example, hits-per-second on an Ingress object).
 */

#ifndef _v2_object_metric_source_H_
#define _v2_object_metric_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2_object_metric_source_t v2_object_metric_source_t;

#include "v2_cross_version_object_reference.h"
#include "v2_metric_identifier.h"
#include "v2_metric_target.h"



typedef struct v2_object_metric_source_t {
    struct v2_cross_version_object_reference_t *described_object; //model
    struct v2_metric_identifier_t *metric; //model
    struct v2_metric_target_t *target; //model

} v2_object_metric_source_t;

v2_object_metric_source_t *v2_object_metric_source_create(
    v2_cross_version_object_reference_t *described_object,
    v2_metric_identifier_t *metric,
    v2_metric_target_t *target
);

void v2_object_metric_source_free(v2_object_metric_source_t *v2_object_metric_source);

v2_object_metric_source_t *v2_object_metric_source_parseFromJSON(cJSON *v2_object_metric_sourceJSON);

cJSON *v2_object_metric_source_convertToJSON(v2_object_metric_source_t *v2_object_metric_source);

#endif /* _v2_object_metric_source_H_ */

