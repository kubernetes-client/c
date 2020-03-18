/*
 * apps_v1beta1_scale_spec.h
 *
 * ScaleSpec describes the attributes of a scale subresource
 */

#ifndef _apps_v1beta1_scale_spec_H_
#define _apps_v1beta1_scale_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct apps_v1beta1_scale_spec_t {
    int replicas; //numeric

} apps_v1beta1_scale_spec_t;

apps_v1beta1_scale_spec_t *apps_v1beta1_scale_spec_create(
    int replicas
);

void apps_v1beta1_scale_spec_free(apps_v1beta1_scale_spec_t *apps_v1beta1_scale_spec);

apps_v1beta1_scale_spec_t *apps_v1beta1_scale_spec_parseFromJSON(cJSON *apps_v1beta1_scale_specJSON);

cJSON *apps_v1beta1_scale_spec_convertToJSON(apps_v1beta1_scale_spec_t *apps_v1beta1_scale_spec);

#endif /* _apps_v1beta1_scale_spec_H_ */

