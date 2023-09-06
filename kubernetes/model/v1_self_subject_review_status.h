/*
 * v1_self_subject_review_status.h
 *
 * SelfSubjectReviewStatus is filled by the kube-apiserver and sent back to a user.
 */

#ifndef _v1_self_subject_review_status_H_
#define _v1_self_subject_review_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_self_subject_review_status_t v1_self_subject_review_status_t;

#include "v1_user_info.h"



typedef struct v1_self_subject_review_status_t {
    struct v1_user_info_t *user_info; //model

} v1_self_subject_review_status_t;

v1_self_subject_review_status_t *v1_self_subject_review_status_create(
    v1_user_info_t *user_info
);

void v1_self_subject_review_status_free(v1_self_subject_review_status_t *v1_self_subject_review_status);

v1_self_subject_review_status_t *v1_self_subject_review_status_parseFromJSON(cJSON *v1_self_subject_review_statusJSON);

cJSON *v1_self_subject_review_status_convertToJSON(v1_self_subject_review_status_t *v1_self_subject_review_status);

#endif /* _v1_self_subject_review_status_H_ */

