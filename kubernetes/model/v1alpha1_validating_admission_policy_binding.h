/*
 * v1alpha1_validating_admission_policy_binding.h
 *
 * ValidatingAdmissionPolicyBinding binds the ValidatingAdmissionPolicy with paramerized resources. ValidatingAdmissionPolicyBinding and parameter CRDs together define how cluster administrators configure policies for clusters.
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

