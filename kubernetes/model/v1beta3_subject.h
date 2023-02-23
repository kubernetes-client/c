/*
 * v1beta3_subject.h
 *
 * Subject matches the originator of a request, as identified by the request authentication system. There are three ways of matching an originator; by user, group, or service account.
 */

#ifndef _v1beta3_subject_H_
#define _v1beta3_subject_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta3_subject_t v1beta3_subject_t;

#include "v1beta3_group_subject.h"
#include "v1beta3_service_account_subject.h"
#include "v1beta3_user_subject.h"



typedef struct v1beta3_subject_t {
    struct v1beta3_group_subject_t *group; //model
    char *kind; // string
    struct v1beta3_service_account_subject_t *service_account; //model
    struct v1beta3_user_subject_t *user; //model

} v1beta3_subject_t;

v1beta3_subject_t *v1beta3_subject_create(
    v1beta3_group_subject_t *group,
    char *kind,
    v1beta3_service_account_subject_t *service_account,
    v1beta3_user_subject_t *user
);

void v1beta3_subject_free(v1beta3_subject_t *v1beta3_subject);

v1beta3_subject_t *v1beta3_subject_parseFromJSON(cJSON *v1beta3_subjectJSON);

cJSON *v1beta3_subject_convertToJSON(v1beta3_subject_t *v1beta3_subject);

#endif /* _v1beta3_subject_H_ */

