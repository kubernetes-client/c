/*
 * v1alpha1_policy_rules_with_subjects.h
 *
 * PolicyRulesWithSubjects prescribes a test that applies to a request to an apiserver. The test considers the subject making the request, the verb being requested, and the resource to be acted upon. This PolicyRulesWithSubjects matches a request if and only if both (a) at least one member of subjects matches the request and (b) at least one member of resourceRules or nonResourceRules matches the request.
 */

#ifndef _v1alpha1_policy_rules_with_subjects_H_
#define _v1alpha1_policy_rules_with_subjects_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_policy_rules_with_subjects_t v1alpha1_policy_rules_with_subjects_t;

#include "flowcontrol_v1alpha1_subject.h"
#include "v1alpha1_non_resource_policy_rule.h"
#include "v1alpha1_resource_policy_rule.h"



typedef struct v1alpha1_policy_rules_with_subjects_t {
    list_t *non_resource_rules; //nonprimitive container
    list_t *resource_rules; //nonprimitive container
    list_t *subjects; //nonprimitive container

} v1alpha1_policy_rules_with_subjects_t;

v1alpha1_policy_rules_with_subjects_t *v1alpha1_policy_rules_with_subjects_create(
    list_t *non_resource_rules,
    list_t *resource_rules,
    list_t *subjects
);

void v1alpha1_policy_rules_with_subjects_free(v1alpha1_policy_rules_with_subjects_t *v1alpha1_policy_rules_with_subjects);

v1alpha1_policy_rules_with_subjects_t *v1alpha1_policy_rules_with_subjects_parseFromJSON(cJSON *v1alpha1_policy_rules_with_subjectsJSON);

cJSON *v1alpha1_policy_rules_with_subjects_convertToJSON(v1alpha1_policy_rules_with_subjects_t *v1alpha1_policy_rules_with_subjects);

#endif /* _v1alpha1_policy_rules_with_subjects_H_ */

