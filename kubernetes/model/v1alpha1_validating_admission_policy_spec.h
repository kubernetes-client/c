/*
 * v1alpha1_validating_admission_policy_spec.h
 *
 * ValidatingAdmissionPolicySpec is the specification of the desired behavior of the AdmissionPolicy.
 */

#ifndef _v1alpha1_validating_admission_policy_spec_H_
#define _v1alpha1_validating_admission_policy_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_validating_admission_policy_spec_t v1alpha1_validating_admission_policy_spec_t;

#include "v1alpha1_audit_annotation.h"
#include "v1alpha1_match_condition.h"
#include "v1alpha1_match_resources.h"
#include "v1alpha1_param_kind.h"
#include "v1alpha1_validation.h"
#include "v1alpha1_variable.h"



typedef struct v1alpha1_validating_admission_policy_spec_t {
    list_t *audit_annotations; //nonprimitive container
    char *failure_policy; // string
    list_t *match_conditions; //nonprimitive container
    struct v1alpha1_match_resources_t *match_constraints; //model
    struct v1alpha1_param_kind_t *param_kind; //model
    list_t *validations; //nonprimitive container
    list_t *variables; //nonprimitive container

} v1alpha1_validating_admission_policy_spec_t;

v1alpha1_validating_admission_policy_spec_t *v1alpha1_validating_admission_policy_spec_create(
    list_t *audit_annotations,
    char *failure_policy,
    list_t *match_conditions,
    v1alpha1_match_resources_t *match_constraints,
    v1alpha1_param_kind_t *param_kind,
    list_t *validations,
    list_t *variables
);

void v1alpha1_validating_admission_policy_spec_free(v1alpha1_validating_admission_policy_spec_t *v1alpha1_validating_admission_policy_spec);

v1alpha1_validating_admission_policy_spec_t *v1alpha1_validating_admission_policy_spec_parseFromJSON(cJSON *v1alpha1_validating_admission_policy_specJSON);

cJSON *v1alpha1_validating_admission_policy_spec_convertToJSON(v1alpha1_validating_admission_policy_spec_t *v1alpha1_validating_admission_policy_spec);

#endif /* _v1alpha1_validating_admission_policy_spec_H_ */

