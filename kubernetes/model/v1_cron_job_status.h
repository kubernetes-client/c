/*
 * v1_cron_job_status.h
 *
 * CronJobStatus represents the current state of a cron job.
 */

#ifndef _v1_cron_job_status_H_
#define _v1_cron_job_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_cron_job_status_t v1_cron_job_status_t;

#include "v1_object_reference.h"



typedef struct v1_cron_job_status_t {
    list_t *active; //nonprimitive container
    char *last_schedule_time; //date time
    char *last_successful_time; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} v1_cron_job_status_t;

__attribute__((deprecated)) v1_cron_job_status_t *v1_cron_job_status_create(
    list_t *active,
    char *last_schedule_time,
    char *last_successful_time
);

void v1_cron_job_status_free(v1_cron_job_status_t *v1_cron_job_status);

v1_cron_job_status_t *v1_cron_job_status_parseFromJSON(cJSON *v1_cron_job_statusJSON);

cJSON *v1_cron_job_status_convertToJSON(v1_cron_job_status_t *v1_cron_job_status);

#endif /* _v1_cron_job_status_H_ */

