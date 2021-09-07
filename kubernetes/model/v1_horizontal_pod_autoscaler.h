/*
 * v1_horizontal_pod_autoscaler.h
 *
 * configuration of a horizontal pod autoscaler.
 */

#ifndef _v1_horizontal_pod_autoscaler_H_
#define _v1_horizontal_pod_autoscaler_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_horizontal_pod_autoscaler_t v1_horizontal_pod_autoscaler_t;

#include "v1_horizontal_pod_autoscaler_spec.h"
#include "v1_horizontal_pod_autoscaler_status.h"
#include "v1_object_meta.h"



typedef struct v1_horizontal_pod_autoscaler_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1_horizontal_pod_autoscaler_spec_t *spec; //model
    struct v1_horizontal_pod_autoscaler_status_t *status; //model

} v1_horizontal_pod_autoscaler_t;

v1_horizontal_pod_autoscaler_t *v1_horizontal_pod_autoscaler_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_horizontal_pod_autoscaler_spec_t *spec,
    v1_horizontal_pod_autoscaler_status_t *status
);

void v1_horizontal_pod_autoscaler_free(v1_horizontal_pod_autoscaler_t *v1_horizontal_pod_autoscaler);

v1_horizontal_pod_autoscaler_t *v1_horizontal_pod_autoscaler_parseFromJSON(cJSON *v1_horizontal_pod_autoscalerJSON);

cJSON *v1_horizontal_pod_autoscaler_convertToJSON(v1_horizontal_pod_autoscaler_t *v1_horizontal_pod_autoscaler);

#endif /* _v1_horizontal_pod_autoscaler_H_ */

