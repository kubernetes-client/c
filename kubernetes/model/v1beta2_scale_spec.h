/*
 * v1beta2_scale_spec.h
 *
 * ScaleSpec describes the attributes of a scale subresource
 */

#ifndef _v1beta2_scale_spec_H_
#define _v1beta2_scale_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1beta2_scale_spec_t {
    int replicas; //numeric

} v1beta2_scale_spec_t;

v1beta2_scale_spec_t *v1beta2_scale_spec_create(
    int replicas
);

void v1beta2_scale_spec_free(v1beta2_scale_spec_t *v1beta2_scale_spec);

v1beta2_scale_spec_t *v1beta2_scale_spec_parseFromJSON(cJSON *v1beta2_scale_specJSON);

cJSON *v1beta2_scale_spec_convertToJSON(v1beta2_scale_spec_t *v1beta2_scale_spec);

#endif /* _v1beta2_scale_spec_H_ */

