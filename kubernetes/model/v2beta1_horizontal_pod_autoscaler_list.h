/*
 * v2beta1_horizontal_pod_autoscaler_list.h
 *
 * HorizontalPodAutoscaler is a list of horizontal pod autoscaler objects.
 */

#ifndef _v2beta1_horizontal_pod_autoscaler_list_H_
#define _v2beta1_horizontal_pod_autoscaler_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2beta1_horizontal_pod_autoscaler_list_t v2beta1_horizontal_pod_autoscaler_list_t;

#include "v1_list_meta.h"
#include "v2beta1_horizontal_pod_autoscaler.h"



typedef struct v2beta1_horizontal_pod_autoscaler_list_t {
    char *api_version; // string
    list_t *items; //nonprimitive container
    char *kind; // string
    struct v1_list_meta_t *metadata; //model

} v2beta1_horizontal_pod_autoscaler_list_t;

v2beta1_horizontal_pod_autoscaler_list_t *v2beta1_horizontal_pod_autoscaler_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
);

void v2beta1_horizontal_pod_autoscaler_list_free(v2beta1_horizontal_pod_autoscaler_list_t *v2beta1_horizontal_pod_autoscaler_list);

v2beta1_horizontal_pod_autoscaler_list_t *v2beta1_horizontal_pod_autoscaler_list_parseFromJSON(cJSON *v2beta1_horizontal_pod_autoscaler_listJSON);

cJSON *v2beta1_horizontal_pod_autoscaler_list_convertToJSON(v2beta1_horizontal_pod_autoscaler_list_t *v2beta1_horizontal_pod_autoscaler_list);

#endif /* _v2beta1_horizontal_pod_autoscaler_list_H_ */

