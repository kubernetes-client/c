/*
 * v2_horizontal_pod_autoscaler.h
 *
 * HorizontalPodAutoscaler is the configuration for a horizontal pod autoscaler, which automatically manages the replica count of any resource implementing the scale subresource based on the metrics specified.
 */

#ifndef _v2_horizontal_pod_autoscaler_H_
#define _v2_horizontal_pod_autoscaler_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2_horizontal_pod_autoscaler_t v2_horizontal_pod_autoscaler_t;

#include "v1_object_meta.h"
#include "v2_horizontal_pod_autoscaler_spec.h"
#include "v2_horizontal_pod_autoscaler_status.h"



typedef struct v2_horizontal_pod_autoscaler_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v2_horizontal_pod_autoscaler_spec_t *spec; //model
    struct v2_horizontal_pod_autoscaler_status_t *status; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v2_horizontal_pod_autoscaler_t;

__attribute__((deprecated)) v2_horizontal_pod_autoscaler_t *v2_horizontal_pod_autoscaler_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v2_horizontal_pod_autoscaler_spec_t *spec,
    v2_horizontal_pod_autoscaler_status_t *status
);

void v2_horizontal_pod_autoscaler_free(v2_horizontal_pod_autoscaler_t *v2_horizontal_pod_autoscaler);

v2_horizontal_pod_autoscaler_t *v2_horizontal_pod_autoscaler_parseFromJSON(cJSON *v2_horizontal_pod_autoscalerJSON);

cJSON *v2_horizontal_pod_autoscaler_convertToJSON(v2_horizontal_pod_autoscaler_t *v2_horizontal_pod_autoscaler);

#endif /* _v2_horizontal_pod_autoscaler_H_ */

