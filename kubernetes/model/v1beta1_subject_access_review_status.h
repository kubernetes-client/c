/*
 * v1beta1_subject_access_review_status.h
 *
 * SubjectAccessReviewStatus
 */

#ifndef _v1beta1_subject_access_review_status_H_
#define _v1beta1_subject_access_review_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_subject_access_review_status_t v1beta1_subject_access_review_status_t;




typedef struct v1beta1_subject_access_review_status_t {
    int allowed; //boolean
    int denied; //boolean
    char *evaluation_error; // string
    char *reason; // string

} v1beta1_subject_access_review_status_t;

v1beta1_subject_access_review_status_t *v1beta1_subject_access_review_status_create(
    int allowed,
    int denied,
    char *evaluation_error,
    char *reason
);

void v1beta1_subject_access_review_status_free(v1beta1_subject_access_review_status_t *v1beta1_subject_access_review_status);

v1beta1_subject_access_review_status_t *v1beta1_subject_access_review_status_parseFromJSON(cJSON *v1beta1_subject_access_review_statusJSON);

cJSON *v1beta1_subject_access_review_status_convertToJSON(v1beta1_subject_access_review_status_t *v1beta1_subject_access_review_status);

#endif /* _v1beta1_subject_access_review_status_H_ */

