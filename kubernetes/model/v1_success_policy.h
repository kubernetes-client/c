/*
 * v1_success_policy.h
 *
 * SuccessPolicy describes when a Job can be declared as succeeded based on the success of some indexes.
 */

#ifndef _v1_success_policy_H_
#define _v1_success_policy_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_success_policy_t v1_success_policy_t;

#include "v1_success_policy_rule.h"



typedef struct v1_success_policy_t {
    list_t *rules; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1_success_policy_t;

__attribute__((deprecated)) v1_success_policy_t *v1_success_policy_create(
    list_t *rules
);

void v1_success_policy_free(v1_success_policy_t *v1_success_policy);

v1_success_policy_t *v1_success_policy_parseFromJSON(cJSON *v1_success_policyJSON);

cJSON *v1_success_policy_convertToJSON(v1_success_policy_t *v1_success_policy);

#endif /* _v1_success_policy_H_ */

