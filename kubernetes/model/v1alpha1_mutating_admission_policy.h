/*
 * v1alpha1_mutating_admission_policy.h
 *
 * MutatingAdmissionPolicy describes the definition of an admission mutation policy that mutates the object coming into admission chain.
 */

#ifndef _v1alpha1_mutating_admission_policy_H_
#define _v1alpha1_mutating_admission_policy_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_mutating_admission_policy_t v1alpha1_mutating_admission_policy_t;

#include "v1_object_meta.h"
#include "v1alpha1_mutating_admission_policy_spec.h"



typedef struct v1alpha1_mutating_admission_policy_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1alpha1_mutating_admission_policy_spec_t *spec; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha1_mutating_admission_policy_t;

__attribute__((deprecated)) v1alpha1_mutating_admission_policy_t *v1alpha1_mutating_admission_policy_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha1_mutating_admission_policy_spec_t *spec
);

void v1alpha1_mutating_admission_policy_free(v1alpha1_mutating_admission_policy_t *v1alpha1_mutating_admission_policy);

v1alpha1_mutating_admission_policy_t *v1alpha1_mutating_admission_policy_parseFromJSON(cJSON *v1alpha1_mutating_admission_policyJSON);

cJSON *v1alpha1_mutating_admission_policy_convertToJSON(v1alpha1_mutating_admission_policy_t *v1alpha1_mutating_admission_policy);

#endif /* _v1alpha1_mutating_admission_policy_H_ */

