/*
 * v1beta1_subject.h
 *
 * Subject contains a reference to the object or user identities a role binding applies to.  This can either hold a direct API object reference, or a value for non-objects such as user and group names.
 */

#ifndef _v1beta1_subject_H_
#define _v1beta1_subject_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_subject_t v1beta1_subject_t;




typedef struct v1beta1_subject_t {
    char *api_group; // string
    char *kind; // string
    char *name; // string
    char *_namespace; // string

} v1beta1_subject_t;

v1beta1_subject_t *v1beta1_subject_create(
    char *api_group,
    char *kind,
    char *name,
    char *_namespace
);

void v1beta1_subject_free(v1beta1_subject_t *v1beta1_subject);

v1beta1_subject_t *v1beta1_subject_parseFromJSON(cJSON *v1beta1_subjectJSON);

cJSON *v1beta1_subject_convertToJSON(v1beta1_subject_t *v1beta1_subject);

#endif /* _v1beta1_subject_H_ */

