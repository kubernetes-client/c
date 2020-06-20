/*
 * v1beta1_local_subject_access_review.h
 *
 * LocalSubjectAccessReview checks whether or not a user or group can perform an action in a given namespace. Having a namespace scoped resource makes it much easier to grant namespace scoped policy that includes permissions checking.
 */

#ifndef _v1beta1_local_subject_access_review_H_
#define _v1beta1_local_subject_access_review_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_local_subject_access_review_t v1beta1_local_subject_access_review_t;

#include "v1_object_meta.h"
#include "v1beta1_subject_access_review_spec.h"
#include "v1beta1_subject_access_review_status.h"



typedef struct v1beta1_local_subject_access_review_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1beta1_subject_access_review_spec_t *spec; //model
    struct v1beta1_subject_access_review_status_t *status; //model

} v1beta1_local_subject_access_review_t;

v1beta1_local_subject_access_review_t *v1beta1_local_subject_access_review_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta1_subject_access_review_spec_t *spec,
    v1beta1_subject_access_review_status_t *status
);

void v1beta1_local_subject_access_review_free(v1beta1_local_subject_access_review_t *v1beta1_local_subject_access_review);

v1beta1_local_subject_access_review_t *v1beta1_local_subject_access_review_parseFromJSON(cJSON *v1beta1_local_subject_access_reviewJSON);

cJSON *v1beta1_local_subject_access_review_convertToJSON(v1beta1_local_subject_access_review_t *v1beta1_local_subject_access_review);

#endif /* _v1beta1_local_subject_access_review_H_ */

