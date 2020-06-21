/*
 * v1beta1_cron_job.h
 *
 * CronJob represents the configuration of a single cron job.
 */

#ifndef _v1beta1_cron_job_H_
#define _v1beta1_cron_job_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_cron_job_t v1beta1_cron_job_t;

#include "v1_object_meta.h"
#include "v1beta1_cron_job_spec.h"
#include "v1beta1_cron_job_status.h"



typedef struct v1beta1_cron_job_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1beta1_cron_job_spec_t *spec; //model
    struct v1beta1_cron_job_status_t *status; //model

} v1beta1_cron_job_t;

v1beta1_cron_job_t *v1beta1_cron_job_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta1_cron_job_spec_t *spec,
    v1beta1_cron_job_status_t *status
);

void v1beta1_cron_job_free(v1beta1_cron_job_t *v1beta1_cron_job);

v1beta1_cron_job_t *v1beta1_cron_job_parseFromJSON(cJSON *v1beta1_cron_jobJSON);

cJSON *v1beta1_cron_job_convertToJSON(v1beta1_cron_job_t *v1beta1_cron_job);

#endif /* _v1beta1_cron_job_H_ */

