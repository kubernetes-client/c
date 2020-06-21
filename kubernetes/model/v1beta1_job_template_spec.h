/*
 * v1beta1_job_template_spec.h
 *
 * JobTemplateSpec describes the data a Job should have when created from a template
 */

#ifndef _v1beta1_job_template_spec_H_
#define _v1beta1_job_template_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_job_template_spec_t v1beta1_job_template_spec_t;

#include "v1_job_spec.h"
#include "v1_object_meta.h"



typedef struct v1beta1_job_template_spec_t {
    struct v1_object_meta_t *metadata; //model
    struct v1_job_spec_t *spec; //model

} v1beta1_job_template_spec_t;

v1beta1_job_template_spec_t *v1beta1_job_template_spec_create(
    v1_object_meta_t *metadata,
    v1_job_spec_t *spec
);

void v1beta1_job_template_spec_free(v1beta1_job_template_spec_t *v1beta1_job_template_spec);

v1beta1_job_template_spec_t *v1beta1_job_template_spec_parseFromJSON(cJSON *v1beta1_job_template_specJSON);

cJSON *v1beta1_job_template_spec_convertToJSON(v1beta1_job_template_spec_t *v1beta1_job_template_spec);

#endif /* _v1beta1_job_template_spec_H_ */

