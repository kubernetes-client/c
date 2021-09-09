/*
 * v2alpha1_cron_job_list.h
 *
 * CronJobList is a collection of cron jobs.
 */

#ifndef _v2alpha1_cron_job_list_H_
#define _v2alpha1_cron_job_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2alpha1_cron_job_list_t v2alpha1_cron_job_list_t;

#include "v1_list_meta.h"
#include "v2alpha1_cron_job.h"



typedef struct v2alpha1_cron_job_list_t {
    char *api_version; // string
    list_t *items; //nonprimitive container
    char *kind; // string
    struct v1_list_meta_t *metadata; //model

} v2alpha1_cron_job_list_t;

v2alpha1_cron_job_list_t *v2alpha1_cron_job_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
);

void v2alpha1_cron_job_list_free(v2alpha1_cron_job_list_t *v2alpha1_cron_job_list);

v2alpha1_cron_job_list_t *v2alpha1_cron_job_list_parseFromJSON(cJSON *v2alpha1_cron_job_listJSON);

cJSON *v2alpha1_cron_job_list_convertToJSON(v2alpha1_cron_job_list_t *v2alpha1_cron_job_list);

#endif /* _v2alpha1_cron_job_list_H_ */

