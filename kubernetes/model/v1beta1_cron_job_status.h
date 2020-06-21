/*
 * v1beta1_cron_job_status.h
 *
 * CronJobStatus represents the current state of a cron job.
 */

#ifndef _v1beta1_cron_job_status_H_
#define _v1beta1_cron_job_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_cron_job_status_t v1beta1_cron_job_status_t;

#include "v1_object_reference.h"



typedef struct v1beta1_cron_job_status_t {
    list_t *active; //nonprimitive container
    char *last_schedule_time; //date time

} v1beta1_cron_job_status_t;

v1beta1_cron_job_status_t *v1beta1_cron_job_status_create(
    list_t *active,
    char *last_schedule_time
);

void v1beta1_cron_job_status_free(v1beta1_cron_job_status_t *v1beta1_cron_job_status);

v1beta1_cron_job_status_t *v1beta1_cron_job_status_parseFromJSON(cJSON *v1beta1_cron_job_statusJSON);

cJSON *v1beta1_cron_job_status_convertToJSON(v1beta1_cron_job_status_t *v1beta1_cron_job_status);

#endif /* _v1beta1_cron_job_status_H_ */

