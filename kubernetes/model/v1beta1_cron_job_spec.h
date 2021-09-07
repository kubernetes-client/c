/*
 * v1beta1_cron_job_spec.h
 *
 * CronJobSpec describes how the job execution will look like and when it will actually run.
 */

#ifndef _v1beta1_cron_job_spec_H_
#define _v1beta1_cron_job_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_cron_job_spec_t v1beta1_cron_job_spec_t;

#include "v1beta1_job_template_spec.h"



typedef struct v1beta1_cron_job_spec_t {
    char *concurrency_policy; // string
    int failed_jobs_history_limit; //numeric
    struct v1beta1_job_template_spec_t *job_template; //model
    char *schedule; // string
    long starting_deadline_seconds; //numeric
    int successful_jobs_history_limit; //numeric
    int suspend; //boolean

} v1beta1_cron_job_spec_t;

v1beta1_cron_job_spec_t *v1beta1_cron_job_spec_create(
    char *concurrency_policy,
    int failed_jobs_history_limit,
    v1beta1_job_template_spec_t *job_template,
    char *schedule,
    long starting_deadline_seconds,
    int successful_jobs_history_limit,
    int suspend
);

void v1beta1_cron_job_spec_free(v1beta1_cron_job_spec_t *v1beta1_cron_job_spec);

v1beta1_cron_job_spec_t *v1beta1_cron_job_spec_parseFromJSON(cJSON *v1beta1_cron_job_specJSON);

cJSON *v1beta1_cron_job_spec_convertToJSON(v1beta1_cron_job_spec_t *v1beta1_cron_job_spec);

#endif /* _v1beta1_cron_job_spec_H_ */

