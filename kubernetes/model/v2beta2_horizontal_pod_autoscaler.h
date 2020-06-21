/*
 * v2beta2_horizontal_pod_autoscaler.h
 *
 * HorizontalPodAutoscaler is the configuration for a horizontal pod autoscaler, which automatically manages the replica count of any resource implementing the scale subresource based on the metrics specified.
 */

#ifndef _v2beta2_horizontal_pod_autoscaler_H_
#define _v2beta2_horizontal_pod_autoscaler_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2beta2_horizontal_pod_autoscaler_t v2beta2_horizontal_pod_autoscaler_t;

#include "v1_object_meta.h"
#include "v2beta2_horizontal_pod_autoscaler_spec.h"
#include "v2beta2_horizontal_pod_autoscaler_status.h"



typedef struct v2beta2_horizontal_pod_autoscaler_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v2beta2_horizontal_pod_autoscaler_spec_t *spec; //model
    struct v2beta2_horizontal_pod_autoscaler_status_t *status; //model

} v2beta2_horizontal_pod_autoscaler_t;

v2beta2_horizontal_pod_autoscaler_t *v2beta2_horizontal_pod_autoscaler_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v2beta2_horizontal_pod_autoscaler_spec_t *spec,
    v2beta2_horizontal_pod_autoscaler_status_t *status
);

void v2beta2_horizontal_pod_autoscaler_free(v2beta2_horizontal_pod_autoscaler_t *v2beta2_horizontal_pod_autoscaler);

v2beta2_horizontal_pod_autoscaler_t *v2beta2_horizontal_pod_autoscaler_parseFromJSON(cJSON *v2beta2_horizontal_pod_autoscalerJSON);

cJSON *v2beta2_horizontal_pod_autoscaler_convertToJSON(v2beta2_horizontal_pod_autoscaler_t *v2beta2_horizontal_pod_autoscaler);

#endif /* _v2beta2_horizontal_pod_autoscaler_H_ */

