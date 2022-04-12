/*
 * v1_job_condition.h
 *
 * JobCondition describes current state of a job.
 */

#ifndef _v1_job_condition_H_
#define _v1_job_condition_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_job_condition_t v1_job_condition_t;


// Enum TYPE for v1_job_condition

typedef enum  { kubernetes_v1_job_condition_TYPE_NULL = 0, kubernetes_v1_job_condition_TYPE_Complete, kubernetes_v1_job_condition_TYPE_Failed, kubernetes_v1_job_condition_TYPE_Suspended } kubernetes_v1_job_condition_TYPE_e;

char* v1_job_condition_type_ToString(kubernetes_v1_job_condition_TYPE_e type);

kubernetes_v1_job_condition_TYPE_e v1_job_condition_type_FromString(char* type);



typedef struct v1_job_condition_t {
    char *last_probe_time; //date time
    char *last_transition_time; //date time
    char *message; // string
    char *reason; // string
    char *status; // string
    kubernetes_v1_job_condition_TYPE_e type; //enum

} v1_job_condition_t;

v1_job_condition_t *v1_job_condition_create(
    char *last_probe_time,
    char *last_transition_time,
    char *message,
    char *reason,
    char *status,
    kubernetes_v1_job_condition_TYPE_e type
);

void v1_job_condition_free(v1_job_condition_t *v1_job_condition);

v1_job_condition_t *v1_job_condition_parseFromJSON(cJSON *v1_job_conditionJSON);

cJSON *v1_job_condition_convertToJSON(v1_job_condition_t *v1_job_condition);

#endif /* _v1_job_condition_H_ */

