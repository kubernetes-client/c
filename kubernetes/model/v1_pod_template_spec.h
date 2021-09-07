/*
 * v1_pod_template_spec.h
 *
 * PodTemplateSpec describes the data a pod should have when created from a template
 */

#ifndef _v1_pod_template_spec_H_
#define _v1_pod_template_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_pod_template_spec_t v1_pod_template_spec_t;

#include "v1_object_meta.h"
#include "v1_pod_spec.h"



typedef struct v1_pod_template_spec_t {
    struct v1_object_meta_t *metadata; //model
    struct v1_pod_spec_t *spec; //model

} v1_pod_template_spec_t;

v1_pod_template_spec_t *v1_pod_template_spec_create(
    v1_object_meta_t *metadata,
    v1_pod_spec_t *spec
);

void v1_pod_template_spec_free(v1_pod_template_spec_t *v1_pod_template_spec);

v1_pod_template_spec_t *v1_pod_template_spec_parseFromJSON(cJSON *v1_pod_template_specJSON);

cJSON *v1_pod_template_spec_convertToJSON(v1_pod_template_spec_t *v1_pod_template_spec);

#endif /* _v1_pod_template_spec_H_ */

