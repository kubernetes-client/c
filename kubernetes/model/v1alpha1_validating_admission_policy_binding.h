/*
 * v1alpha1_validating_admission_policy_binding.h
 *
 * ValidatingAdmissionPolicyBinding binds the ValidatingAdmissionPolicy with paramerized resources. ValidatingAdmissionPolicyBinding and parameter CRDs together define how cluster administrators configure policies for clusters.  For a given admission request, each binding will cause its policy to be evaluated N times, where N is 1 for policies/bindings that don&#39;t use params, otherwise N is the number of parameters selected by the binding.  The CEL expressions of a policy must have a computed CEL cost below the maximum CEL budget. Each evaluation of the policy is given an independent CEL cost budget. Adding/removing policies, bindings, or params can not affect whether a given (policy, binding, param) combination is within its own CEL budget.
 */

#ifndef _v1alpha1_validating_admission_policy_binding_H_
#define _v1alpha1_validating_admission_policy_binding_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_validating_admission_policy_binding_t v1alpha1_validating_admission_policy_binding_t;

#include "v1_object_meta.h"
#include "v1alpha1_validating_admission_policy_binding_spec.h"



typedef struct v1alpha1_validating_admission_policy_binding_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1alpha1_validating_admission_policy_binding_spec_t *spec; //model

} v1alpha1_validating_admission_policy_binding_t;

v1alpha1_validating_admission_policy_binding_t *v1alpha1_validating_admission_policy_binding_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha1_validating_admission_policy_binding_spec_t *spec
);

void v1alpha1_validating_admission_policy_binding_free(v1alpha1_validating_admission_policy_binding_t *v1alpha1_validating_admission_policy_binding);

v1alpha1_validating_admission_policy_binding_t *v1alpha1_validating_admission_policy_binding_parseFromJSON(cJSON *v1alpha1_validating_admission_policy_bindingJSON);

cJSON *v1alpha1_validating_admission_policy_binding_convertToJSON(v1alpha1_validating_admission_policy_binding_t *v1alpha1_validating_admission_policy_binding);

#endif /* _v1alpha1_validating_admission_policy_binding_H_ */

