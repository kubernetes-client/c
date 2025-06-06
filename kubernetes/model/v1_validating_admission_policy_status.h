/*
 * v1_validating_admission_policy_status.h
 *
 * ValidatingAdmissionPolicyStatus represents the status of an admission validation policy.
 */

#ifndef _v1_validating_admission_policy_status_H_
#define _v1_validating_admission_policy_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_validating_admission_policy_status_t v1_validating_admission_policy_status_t;

#include "v1_condition.h"
#include "v1_type_checking.h"



typedef struct v1_validating_admission_policy_status_t {
    list_t *conditions; //nonprimitive container
    long observed_generation; //numeric
    struct v1_type_checking_t *type_checking; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1_validating_admission_policy_status_t;

__attribute__((deprecated)) v1_validating_admission_policy_status_t *v1_validating_admission_policy_status_create(
    list_t *conditions,
    long observed_generation,
    v1_type_checking_t *type_checking
);

void v1_validating_admission_policy_status_free(v1_validating_admission_policy_status_t *v1_validating_admission_policy_status);

v1_validating_admission_policy_status_t *v1_validating_admission_policy_status_parseFromJSON(cJSON *v1_validating_admission_policy_statusJSON);

cJSON *v1_validating_admission_policy_status_convertToJSON(v1_validating_admission_policy_status_t *v1_validating_admission_policy_status);

#endif /* _v1_validating_admission_policy_status_H_ */

