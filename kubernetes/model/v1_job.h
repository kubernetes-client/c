/*
 * v1_job.h
 *
 * Job represents the configuration of a single job.
 */

#ifndef _v1_job_H_
#define _v1_job_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_job_t v1_job_t;

#include "v1_job_spec.h"
#include "v1_job_status.h"
#include "v1_object_meta.h"



typedef struct v1_job_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1_job_spec_t *spec; //model
    struct v1_job_status_t *status; //model

} v1_job_t;

v1_job_t *v1_job_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_job_spec_t *spec,
    v1_job_status_t *status
);

void v1_job_free(v1_job_t *v1_job);

v1_job_t *v1_job_parseFromJSON(cJSON *v1_jobJSON);

cJSON *v1_job_convertToJSON(v1_job_t *v1_job);

#endif /* _v1_job_H_ */

