/*
 * v1alpha1_validating_admission_policy_binding_spec.h
 *
 * ValidatingAdmissionPolicyBindingSpec is the specification of the ValidatingAdmissionPolicyBinding.
 */

#ifndef _v1alpha1_validating_admission_policy_binding_spec_H_
#define _v1alpha1_validating_admission_policy_binding_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_validating_admission_policy_binding_spec_t v1alpha1_validating_admission_policy_binding_spec_t;

#include "v1alpha1_match_resources.h"
#include "v1alpha1_param_ref.h"



typedef struct v1alpha1_validating_admission_policy_binding_spec_t {
    struct v1alpha1_match_resources_t *match_resources; //model
    struct v1alpha1_param_ref_t *param_ref; //model
    char *policy_name; // string

} v1alpha1_validating_admission_policy_binding_spec_t;

v1alpha1_validating_admission_policy_binding_spec_t *v1alpha1_validating_admission_policy_binding_spec_create(
    v1alpha1_match_resources_t *match_resources,
    v1alpha1_param_ref_t *param_ref,
    char *policy_name
);

void v1alpha1_validating_admission_policy_binding_spec_free(v1alpha1_validating_admission_policy_binding_spec_t *v1alpha1_validating_admission_policy_binding_spec);

v1alpha1_validating_admission_policy_binding_spec_t *v1alpha1_validating_admission_policy_binding_spec_parseFromJSON(cJSON *v1alpha1_validating_admission_policy_binding_specJSON);

cJSON *v1alpha1_validating_admission_policy_binding_spec_convertToJSON(v1alpha1_validating_admission_policy_binding_spec_t *v1alpha1_validating_admission_policy_binding_spec);

#endif /* _v1alpha1_validating_admission_policy_binding_spec_H_ */

