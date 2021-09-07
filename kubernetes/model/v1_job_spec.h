/*
 * v1_job_spec.h
 *
 * JobSpec describes how the job execution will look like.
 */

#ifndef _v1_job_spec_H_
#define _v1_job_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_job_spec_t v1_job_spec_t;

#include "v1_label_selector.h"
#include "v1_pod_template_spec.h"



typedef struct v1_job_spec_t {
    long active_deadline_seconds; //numeric
    int backoff_limit; //numeric
    int completions; //numeric
    int manual_selector; //boolean
    int parallelism; //numeric
    struct v1_label_selector_t *selector; //model
    struct v1_pod_template_spec_t *_template; //model
    int ttl_seconds_after_finished; //numeric

} v1_job_spec_t;

v1_job_spec_t *v1_job_spec_create(
    long active_deadline_seconds,
    int backoff_limit,
    int completions,
    int manual_selector,
    int parallelism,
    v1_label_selector_t *selector,
    v1_pod_template_spec_t *_template,
    int ttl_seconds_after_finished
);

void v1_job_spec_free(v1_job_spec_t *v1_job_spec);

v1_job_spec_t *v1_job_spec_parseFromJSON(cJSON *v1_job_specJSON);

cJSON *v1_job_spec_convertToJSON(v1_job_spec_t *v1_job_spec);

#endif /* _v1_job_spec_H_ */

