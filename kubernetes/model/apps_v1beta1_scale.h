/*
 * apps_v1beta1_scale.h
 *
 * Scale represents a scaling request for a resource.
 */

#ifndef _apps_v1beta1_scale_H_
#define _apps_v1beta1_scale_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct apps_v1beta1_scale_t apps_v1beta1_scale_t;

#include "apps_v1beta1_scale_spec.h"
#include "apps_v1beta1_scale_status.h"
#include "v1_object_meta.h"



typedef struct apps_v1beta1_scale_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct apps_v1beta1_scale_spec_t *spec; //model
    struct apps_v1beta1_scale_status_t *status; //model

} apps_v1beta1_scale_t;

apps_v1beta1_scale_t *apps_v1beta1_scale_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    apps_v1beta1_scale_spec_t *spec,
    apps_v1beta1_scale_status_t *status
);

void apps_v1beta1_scale_free(apps_v1beta1_scale_t *apps_v1beta1_scale);

apps_v1beta1_scale_t *apps_v1beta1_scale_parseFromJSON(cJSON *apps_v1beta1_scaleJSON);

cJSON *apps_v1beta1_scale_convertToJSON(apps_v1beta1_scale_t *apps_v1beta1_scale);

#endif /* _apps_v1beta1_scale_H_ */

