/*
 * v1alpha1_self_subject_review.h
 *
 * SelfSubjectReview contains the user information that the kube-apiserver has about the user making this request. When using impersonation, users will receive the user info of the user being impersonated.
 */

#ifndef _v1alpha1_self_subject_review_H_
#define _v1alpha1_self_subject_review_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_self_subject_review_t v1alpha1_self_subject_review_t;

#include "v1_object_meta.h"
#include "v1alpha1_self_subject_review_status.h"



typedef struct v1alpha1_self_subject_review_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1alpha1_self_subject_review_status_t *status; //model

} v1alpha1_self_subject_review_t;

v1alpha1_self_subject_review_t *v1alpha1_self_subject_review_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha1_self_subject_review_status_t *status
);

void v1alpha1_self_subject_review_free(v1alpha1_self_subject_review_t *v1alpha1_self_subject_review);

v1alpha1_self_subject_review_t *v1alpha1_self_subject_review_parseFromJSON(cJSON *v1alpha1_self_subject_reviewJSON);

cJSON *v1alpha1_self_subject_review_convertToJSON(v1alpha1_self_subject_review_t *v1alpha1_self_subject_review);

#endif /* _v1alpha1_self_subject_review_H_ */

