/*
 * v2_metric_identifier.h
 *
 * MetricIdentifier defines the name and optionally selector for a metric
 */

#ifndef _v2_metric_identifier_H_
#define _v2_metric_identifier_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2_metric_identifier_t v2_metric_identifier_t;

#include "v1_label_selector.h"



typedef struct v2_metric_identifier_t {
    char *name; // string
    struct v1_label_selector_t *selector; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v2_metric_identifier_t;

__attribute__((deprecated)) v2_metric_identifier_t *v2_metric_identifier_create(
    char *name,
    v1_label_selector_t *selector
);

void v2_metric_identifier_free(v2_metric_identifier_t *v2_metric_identifier);

v2_metric_identifier_t *v2_metric_identifier_parseFromJSON(cJSON *v2_metric_identifierJSON);

cJSON *v2_metric_identifier_convertToJSON(v2_metric_identifier_t *v2_metric_identifier);

#endif /* _v2_metric_identifier_H_ */

