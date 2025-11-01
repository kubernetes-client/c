/*
 * v1beta1_mutating_admission_policy_spec.h
 *
 * MutatingAdmissionPolicySpec is the specification of the desired behavior of the admission policy.
 */

#ifndef _v1beta1_mutating_admission_policy_spec_H_
#define _v1beta1_mutating_admission_policy_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_mutating_admission_policy_spec_t v1beta1_mutating_admission_policy_spec_t;

#include "v1beta1_match_condition.h"
#include "v1beta1_match_resources.h"
#include "v1beta1_mutation.h"
#include "v1beta1_param_kind.h"
#include "v1beta1_variable.h"



typedef struct v1beta1_mutating_admission_policy_spec_t {
    char *failure_policy; // string
    list_t *match_conditions; //nonprimitive container
    struct v1beta1_match_resources_t *match_constraints; //model
    list_t *mutations; //nonprimitive container
    struct v1beta1_param_kind_t *param_kind; //model
    char *reinvocation_policy; // string
    list_t *variables; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_mutating_admission_policy_spec_t;

__attribute__((deprecated)) v1beta1_mutating_admission_policy_spec_t *v1beta1_mutating_admission_policy_spec_create(
    char *failure_policy,
    list_t *match_conditions,
    v1beta1_match_resources_t *match_constraints,
    list_t *mutations,
    v1beta1_param_kind_t *param_kind,
    char *reinvocation_policy,
    list_t *variables
);

void v1beta1_mutating_admission_policy_spec_free(v1beta1_mutating_admission_policy_spec_t *v1beta1_mutating_admission_policy_spec);

v1beta1_mutating_admission_policy_spec_t *v1beta1_mutating_admission_policy_spec_parseFromJSON(cJSON *v1beta1_mutating_admission_policy_specJSON);

cJSON *v1beta1_mutating_admission_policy_spec_convertToJSON(v1beta1_mutating_admission_policy_spec_t *v1beta1_mutating_admission_policy_spec);

#endif /* _v1beta1_mutating_admission_policy_spec_H_ */

