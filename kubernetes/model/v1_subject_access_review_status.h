/*
 * v1_subject_access_review_status.h
 *
 * SubjectAccessReviewStatus
 */

#ifndef _v1_subject_access_review_status_H_
#define _v1_subject_access_review_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_subject_access_review_status_t v1_subject_access_review_status_t;




typedef struct v1_subject_access_review_status_t {
    int allowed; //boolean
    int denied; //boolean
    char *evaluation_error; // string
    char *reason; // string

} v1_subject_access_review_status_t;

v1_subject_access_review_status_t *v1_subject_access_review_status_create(
    int allowed,
    int denied,
    char *evaluation_error,
    char *reason
);

void v1_subject_access_review_status_free(v1_subject_access_review_status_t *v1_subject_access_review_status);

v1_subject_access_review_status_t *v1_subject_access_review_status_parseFromJSON(cJSON *v1_subject_access_review_statusJSON);

cJSON *v1_subject_access_review_status_convertToJSON(v1_subject_access_review_status_t *v1_subject_access_review_status);

#endif /* _v1_subject_access_review_status_H_ */

