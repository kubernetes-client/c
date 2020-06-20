/*
 * v1beta1_self_subject_rules_review.h
 *
 * SelfSubjectRulesReview enumerates the set of actions the current user can perform within a namespace. The returned list of actions may be incomplete depending on the server&#39;s authorization mode, and any errors experienced during the evaluation. SelfSubjectRulesReview should be used by UIs to show/hide actions, or to quickly let an end user reason about their permissions. It should NOT Be used by external systems to drive authorization decisions as this raises confused deputy, cache lifetime/revocation, and correctness concerns. SubjectAccessReview, and LocalAccessReview are the correct way to defer authorization decisions to the API server.
 */

#ifndef _v1beta1_self_subject_rules_review_H_
#define _v1beta1_self_subject_rules_review_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_self_subject_rules_review_t v1beta1_self_subject_rules_review_t;

#include "v1_object_meta.h"
#include "v1beta1_self_subject_rules_review_spec.h"
#include "v1beta1_subject_rules_review_status.h"



typedef struct v1beta1_self_subject_rules_review_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1beta1_self_subject_rules_review_spec_t *spec; //model
    struct v1beta1_subject_rules_review_status_t *status; //model

} v1beta1_self_subject_rules_review_t;

v1beta1_self_subject_rules_review_t *v1beta1_self_subject_rules_review_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta1_self_subject_rules_review_spec_t *spec,
    v1beta1_subject_rules_review_status_t *status
);

void v1beta1_self_subject_rules_review_free(v1beta1_self_subject_rules_review_t *v1beta1_self_subject_rules_review);

v1beta1_self_subject_rules_review_t *v1beta1_self_subject_rules_review_parseFromJSON(cJSON *v1beta1_self_subject_rules_reviewJSON);

cJSON *v1beta1_self_subject_rules_review_convertToJSON(v1beta1_self_subject_rules_review_t *v1beta1_self_subject_rules_review);

#endif /* _v1beta1_self_subject_rules_review_H_ */

