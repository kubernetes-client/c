/*
 * rbac_v1_subject.h
 *
 * Subject contains a reference to the object or user identities a role binding applies to.  This can either hold a direct API object reference, or a value for non-objects such as user and group names.
 */

#ifndef _rbac_v1_subject_H_
#define _rbac_v1_subject_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct rbac_v1_subject_t rbac_v1_subject_t;




typedef struct rbac_v1_subject_t {
    char *api_group; // string
    char *kind; // string
    char *name; // string
    char *_namespace; // string

    int _library_owned; // Is the library responsible for freeing this object?
} rbac_v1_subject_t;

__attribute__((deprecated)) rbac_v1_subject_t *rbac_v1_subject_create(
    char *api_group,
    char *kind,
    char *name,
    char *_namespace
);

void rbac_v1_subject_free(rbac_v1_subject_t *rbac_v1_subject);

rbac_v1_subject_t *rbac_v1_subject_parseFromJSON(cJSON *rbac_v1_subjectJSON);

cJSON *rbac_v1_subject_convertToJSON(rbac_v1_subject_t *rbac_v1_subject);

#endif /* _rbac_v1_subject_H_ */

