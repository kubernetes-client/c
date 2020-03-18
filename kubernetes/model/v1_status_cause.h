/*
 * v1_status_cause.h
 *
 * StatusCause provides more information about an api.Status failure, including cases when multiple errors are encountered.
 */

#ifndef _v1_status_cause_H_
#define _v1_status_cause_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_status_cause_t {
    char *field; // string
    char *message; // string
    char *reason; // string

} v1_status_cause_t;

v1_status_cause_t *v1_status_cause_create(
    char *field,
    char *message,
    char *reason
);

void v1_status_cause_free(v1_status_cause_t *v1_status_cause);

v1_status_cause_t *v1_status_cause_parseFromJSON(cJSON *v1_status_causeJSON);

cJSON *v1_status_cause_convertToJSON(v1_status_cause_t *v1_status_cause);

#endif /* _v1_status_cause_H_ */

