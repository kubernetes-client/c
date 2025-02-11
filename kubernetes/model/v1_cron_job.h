/*
 * v1_cron_job.h
 *
 * CronJob represents the configuration of a single cron job.
 */

#ifndef _v1_cron_job_H_
#define _v1_cron_job_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_cron_job_t v1_cron_job_t;

#include "v1_cron_job_spec.h"
#include "v1_cron_job_status.h"
#include "v1_object_meta.h"



typedef struct v1_cron_job_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1_cron_job_spec_t *spec; //model
    struct v1_cron_job_status_t *status; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1_cron_job_t;

__attribute__((deprecated)) v1_cron_job_t *v1_cron_job_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_cron_job_spec_t *spec,
    v1_cron_job_status_t *status
);

void v1_cron_job_free(v1_cron_job_t *v1_cron_job);

v1_cron_job_t *v1_cron_job_parseFromJSON(cJSON *v1_cron_jobJSON);

cJSON *v1_cron_job_convertToJSON(v1_cron_job_t *v1_cron_job);

#endif /* _v1_cron_job_H_ */

