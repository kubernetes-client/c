/*
 * v1alpha1_group_subject.h
 *
 * GroupSubject holds detailed information for group-kind subject.
 */

#ifndef _v1alpha1_group_subject_H_
#define _v1alpha1_group_subject_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_group_subject_t v1alpha1_group_subject_t;




typedef struct v1alpha1_group_subject_t {
    char *name; // string

} v1alpha1_group_subject_t;

v1alpha1_group_subject_t *v1alpha1_group_subject_create(
    char *name
);

void v1alpha1_group_subject_free(v1alpha1_group_subject_t *v1alpha1_group_subject);

v1alpha1_group_subject_t *v1alpha1_group_subject_parseFromJSON(cJSON *v1alpha1_group_subjectJSON);

cJSON *v1alpha1_group_subject_convertToJSON(v1alpha1_group_subject_t *v1alpha1_group_subject);

#endif /* _v1alpha1_group_subject_H_ */

