/*
 * v2alpha1_job_template_spec.h
 *
 * JobTemplateSpec describes the data a Job should have when created from a template
 */

#ifndef _v2alpha1_job_template_spec_H_
#define _v2alpha1_job_template_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2alpha1_job_template_spec_t v2alpha1_job_template_spec_t;

#include "v1_job_spec.h"
#include "v1_object_meta.h"



typedef struct v2alpha1_job_template_spec_t {
    struct v1_object_meta_t *metadata; //model
    struct v1_job_spec_t *spec; //model

} v2alpha1_job_template_spec_t;

v2alpha1_job_template_spec_t *v2alpha1_job_template_spec_create(
    v1_object_meta_t *metadata,
    v1_job_spec_t *spec
);

void v2alpha1_job_template_spec_free(v2alpha1_job_template_spec_t *v2alpha1_job_template_spec);

v2alpha1_job_template_spec_t *v2alpha1_job_template_spec_parseFromJSON(cJSON *v2alpha1_job_template_specJSON);

cJSON *v2alpha1_job_template_spec_convertToJSON(v2alpha1_job_template_spec_t *v2alpha1_job_template_spec);

#endif /* _v2alpha1_job_template_spec_H_ */

