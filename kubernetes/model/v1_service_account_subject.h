/*
 * v1_service_account_subject.h
 *
 * ServiceAccountSubject holds detailed information for service-account-kind subject.
 */

#ifndef _v1_service_account_subject_H_
#define _v1_service_account_subject_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_service_account_subject_t v1_service_account_subject_t;




typedef struct v1_service_account_subject_t {
    char *name; // string
    char *_namespace; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_service_account_subject_t;

__attribute__((deprecated)) v1_service_account_subject_t *v1_service_account_subject_create(
    char *name,
    char *_namespace
);

void v1_service_account_subject_free(v1_service_account_subject_t *v1_service_account_subject);

v1_service_account_subject_t *v1_service_account_subject_parseFromJSON(cJSON *v1_service_account_subjectJSON);

cJSON *v1_service_account_subject_convertToJSON(v1_service_account_subject_t *v1_service_account_subject);

#endif /* _v1_service_account_subject_H_ */

