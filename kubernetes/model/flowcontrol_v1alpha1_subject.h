/*
 * flowcontrol_v1alpha1_subject.h
 *
 * Subject matches the originator of a request, as identified by the request authentication system. There are three ways of matching an originator; by user, group, or service account.
 */

#ifndef _flowcontrol_v1alpha1_subject_H_
#define _flowcontrol_v1alpha1_subject_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct flowcontrol_v1alpha1_subject_t flowcontrol_v1alpha1_subject_t;

#include "v1alpha1_group_subject.h"
#include "v1alpha1_service_account_subject.h"
#include "v1alpha1_user_subject.h"



typedef struct flowcontrol_v1alpha1_subject_t {
    struct v1alpha1_group_subject_t *group; //model
    char *kind; // string
    struct v1alpha1_service_account_subject_t *service_account; //model
    struct v1alpha1_user_subject_t *user; //model

} flowcontrol_v1alpha1_subject_t;

flowcontrol_v1alpha1_subject_t *flowcontrol_v1alpha1_subject_create(
    v1alpha1_group_subject_t *group,
    char *kind,
    v1alpha1_service_account_subject_t *service_account,
    v1alpha1_user_subject_t *user
);

void flowcontrol_v1alpha1_subject_free(flowcontrol_v1alpha1_subject_t *flowcontrol_v1alpha1_subject);

flowcontrol_v1alpha1_subject_t *flowcontrol_v1alpha1_subject_parseFromJSON(cJSON *flowcontrol_v1alpha1_subjectJSON);

cJSON *flowcontrol_v1alpha1_subject_convertToJSON(flowcontrol_v1alpha1_subject_t *flowcontrol_v1alpha1_subject);

#endif /* _flowcontrol_v1alpha1_subject_H_ */

