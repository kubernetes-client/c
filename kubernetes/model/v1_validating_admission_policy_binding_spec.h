/*
 * v1_validating_admission_policy_binding_spec.h
 *
 * ValidatingAdmissionPolicyBindingSpec is the specification of the ValidatingAdmissionPolicyBinding.
 */

#ifndef _v1_validating_admission_policy_binding_spec_H_
#define _v1_validating_admission_policy_binding_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_validating_admission_policy_binding_spec_t v1_validating_admission_policy_binding_spec_t;

#include "v1_match_resources.h"
#include "v1_param_ref.h"



typedef struct v1_validating_admission_policy_binding_spec_t {
    struct v1_match_resources_t *match_resources; //model
    struct v1_param_ref_t *param_ref; //model
    char *policy_name; // string
    list_t *validation_actions; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1_validating_admission_policy_binding_spec_t;

__attribute__((deprecated)) v1_validating_admission_policy_binding_spec_t *v1_validating_admission_policy_binding_spec_create(
    v1_match_resources_t *match_resources,
    v1_param_ref_t *param_ref,
    char *policy_name,
    list_t *validation_actions
);

void v1_validating_admission_policy_binding_spec_free(v1_validating_admission_policy_binding_spec_t *v1_validating_admission_policy_binding_spec);

v1_validating_admission_policy_binding_spec_t *v1_validating_admission_policy_binding_spec_parseFromJSON(cJSON *v1_validating_admission_policy_binding_specJSON);

cJSON *v1_validating_admission_policy_binding_spec_convertToJSON(v1_validating_admission_policy_binding_spec_t *v1_validating_admission_policy_binding_spec);

#endif /* _v1_validating_admission_policy_binding_spec_H_ */

