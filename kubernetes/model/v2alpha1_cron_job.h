/*
 * v2alpha1_cron_job.h
 *
 * CronJob represents the configuration of a single cron job.
 */

#ifndef _v2alpha1_cron_job_H_
#define _v2alpha1_cron_job_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2alpha1_cron_job_t v2alpha1_cron_job_t;

#include "v1_object_meta.h"
#include "v2alpha1_cron_job_spec.h"
#include "v2alpha1_cron_job_status.h"



typedef struct v2alpha1_cron_job_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v2alpha1_cron_job_spec_t *spec; //model
    struct v2alpha1_cron_job_status_t *status; //model

} v2alpha1_cron_job_t;

v2alpha1_cron_job_t *v2alpha1_cron_job_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v2alpha1_cron_job_spec_t *spec,
    v2alpha1_cron_job_status_t *status
);

void v2alpha1_cron_job_free(v2alpha1_cron_job_t *v2alpha1_cron_job);

v2alpha1_cron_job_t *v2alpha1_cron_job_parseFromJSON(cJSON *v2alpha1_cron_jobJSON);

cJSON *v2alpha1_cron_job_convertToJSON(v2alpha1_cron_job_t *v2alpha1_cron_job);

#endif /* _v2alpha1_cron_job_H_ */

