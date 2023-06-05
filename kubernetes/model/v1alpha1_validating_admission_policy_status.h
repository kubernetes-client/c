/*
 * v1alpha1_validating_admission_policy_status.h
 *
 * ValidatingAdmissionPolicyStatus represents the status of a ValidatingAdmissionPolicy.
 */

#ifndef _v1alpha1_validating_admission_policy_status_H_
#define _v1alpha1_validating_admission_policy_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_validating_admission_policy_status_t v1alpha1_validating_admission_policy_status_t;

#include "v1_condition.h"
#include "v1alpha1_type_checking.h"



typedef struct v1alpha1_validating_admission_policy_status_t {
    list_t *conditions; //nonprimitive container
    long observed_generation; //numeric
    struct v1alpha1_type_checking_t *type_checking; //model

} v1alpha1_validating_admission_policy_status_t;

v1alpha1_validating_admission_policy_status_t *v1alpha1_validating_admission_policy_status_create(
    list_t *conditions,
    long observed_generation,
    v1alpha1_type_checking_t *type_checking
);

void v1alpha1_validating_admission_policy_status_free(v1alpha1_validating_admission_policy_status_t *v1alpha1_validating_admission_policy_status);

v1alpha1_validating_admission_policy_status_t *v1alpha1_validating_admission_policy_status_parseFromJSON(cJSON *v1alpha1_validating_admission_policy_statusJSON);

cJSON *v1alpha1_validating_admission_policy_status_convertToJSON(v1alpha1_validating_admission_policy_status_t *v1alpha1_validating_admission_policy_status);

#endif /* _v1alpha1_validating_admission_policy_status_H_ */

