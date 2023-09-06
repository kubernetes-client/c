/*
 * v1beta1_validating_admission_policy_binding_spec.h
 *
 * ValidatingAdmissionPolicyBindingSpec is the specification of the ValidatingAdmissionPolicyBinding.
 */

#ifndef _v1beta1_validating_admission_policy_binding_spec_H_
#define _v1beta1_validating_admission_policy_binding_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_validating_admission_policy_binding_spec_t v1beta1_validating_admission_policy_binding_spec_t;

#include "v1beta1_match_resources.h"
#include "v1beta1_param_ref.h"



typedef struct v1beta1_validating_admission_policy_binding_spec_t {
    struct v1beta1_match_resources_t *match_resources; //model
    struct v1beta1_param_ref_t *param_ref; //model
    char *policy_name; // string
    list_t *validation_actions; //primitive container

} v1beta1_validating_admission_policy_binding_spec_t;

v1beta1_validating_admission_policy_binding_spec_t *v1beta1_validating_admission_policy_binding_spec_create(
    v1beta1_match_resources_t *match_resources,
    v1beta1_param_ref_t *param_ref,
    char *policy_name,
    list_t *validation_actions
);

void v1beta1_validating_admission_policy_binding_spec_free(v1beta1_validating_admission_policy_binding_spec_t *v1beta1_validating_admission_policy_binding_spec);

v1beta1_validating_admission_policy_binding_spec_t *v1beta1_validating_admission_policy_binding_spec_parseFromJSON(cJSON *v1beta1_validating_admission_policy_binding_specJSON);

cJSON *v1beta1_validating_admission_policy_binding_spec_convertToJSON(v1beta1_validating_admission_policy_binding_spec_t *v1beta1_validating_admission_policy_binding_spec);

#endif /* _v1beta1_validating_admission_policy_binding_spec_H_ */

