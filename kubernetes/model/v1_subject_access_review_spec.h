/*
 * v1_subject_access_review_spec.h
 *
 * SubjectAccessReviewSpec is a description of the access request.  Exactly one of ResourceAuthorizationAttributes and NonResourceAuthorizationAttributes must be set
 */

#ifndef _v1_subject_access_review_spec_H_
#define _v1_subject_access_review_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_subject_access_review_spec_t v1_subject_access_review_spec_t;

#include "v1_non_resource_attributes.h"
#include "v1_resource_attributes.h"



typedef struct v1_subject_access_review_spec_t {
    list_t* extra; //map
    list_t *groups; //primitive container
    struct v1_non_resource_attributes_t *non_resource_attributes; //model
    struct v1_resource_attributes_t *resource_attributes; //model
    char *uid; // string
    char *user; // string

} v1_subject_access_review_spec_t;

v1_subject_access_review_spec_t *v1_subject_access_review_spec_create(
    list_t* extra,
    list_t *groups,
    v1_non_resource_attributes_t *non_resource_attributes,
    v1_resource_attributes_t *resource_attributes,
    char *uid,
    char *user
);

void v1_subject_access_review_spec_free(v1_subject_access_review_spec_t *v1_subject_access_review_spec);

v1_subject_access_review_spec_t *v1_subject_access_review_spec_parseFromJSON(cJSON *v1_subject_access_review_specJSON);

cJSON *v1_subject_access_review_spec_convertToJSON(v1_subject_access_review_spec_t *v1_subject_access_review_spec);

#endif /* _v1_subject_access_review_spec_H_ */

