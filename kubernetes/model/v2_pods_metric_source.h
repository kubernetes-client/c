/*
 * v2_pods_metric_source.h
 *
 * PodsMetricSource indicates how to scale on a metric describing each pod in the current scale target (for example, transactions-processed-per-second). The values will be averaged together before being compared to the target value.
 */

#ifndef _v2_pods_metric_source_H_
#define _v2_pods_metric_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2_pods_metric_source_t v2_pods_metric_source_t;

#include "v2_metric_identifier.h"
#include "v2_metric_target.h"



typedef struct v2_pods_metric_source_t {
    struct v2_metric_identifier_t *metric; //model
    struct v2_metric_target_t *target; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v2_pods_metric_source_t;

__attribute__((deprecated)) v2_pods_metric_source_t *v2_pods_metric_source_create(
    v2_metric_identifier_t *metric,
    v2_metric_target_t *target
);

void v2_pods_metric_source_free(v2_pods_metric_source_t *v2_pods_metric_source);

v2_pods_metric_source_t *v2_pods_metric_source_parseFromJSON(cJSON *v2_pods_metric_sourceJSON);

cJSON *v2_pods_metric_source_convertToJSON(v2_pods_metric_source_t *v2_pods_metric_source);

#endif /* _v2_pods_metric_source_H_ */

