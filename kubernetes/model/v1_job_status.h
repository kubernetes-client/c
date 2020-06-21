/*
 * v1_job_status.h
 *
 * JobStatus represents the current state of a Job.
 */

#ifndef _v1_job_status_H_
#define _v1_job_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_job_status_t v1_job_status_t;

#include "v1_job_condition.h"



typedef struct v1_job_status_t {
    int active; //numeric
    char *completion_time; //date time
    list_t *conditions; //nonprimitive container
    int failed; //numeric
    char *start_time; //date time
    int succeeded; //numeric

} v1_job_status_t;

v1_job_status_t *v1_job_status_create(
    int active,
    char *completion_time,
    list_t *conditions,
    int failed,
    char *start_time,
    int succeeded
);

void v1_job_status_free(v1_job_status_t *v1_job_status);

v1_job_status_t *v1_job_status_parseFromJSON(cJSON *v1_job_statusJSON);

cJSON *v1_job_status_convertToJSON(v1_job_status_t *v1_job_status);

#endif /* _v1_job_status_H_ */

