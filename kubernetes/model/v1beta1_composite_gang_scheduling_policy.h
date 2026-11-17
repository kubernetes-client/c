/*
 * v1beta1_composite_gang_scheduling_policy.h
 *
 * CompositeGangSchedulingPolicy indicates that the groups belonging to the composite group should be scheduled using all-or-nothing semantics.
 */

#ifndef _v1beta1_composite_gang_scheduling_policy_H_
#define _v1beta1_composite_gang_scheduling_policy_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_composite_gang_scheduling_policy_t v1beta1_composite_gang_scheduling_policy_t;




typedef struct v1beta1_composite_gang_scheduling_policy_t {
    int *min_group_count; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_composite_gang_scheduling_policy_t;

__attribute__((deprecated)) v1beta1_composite_gang_scheduling_policy_t *v1beta1_composite_gang_scheduling_policy_create(
    int *min_group_count
);

void v1beta1_composite_gang_scheduling_policy_free(v1beta1_composite_gang_scheduling_policy_t *v1beta1_composite_gang_scheduling_policy);

v1beta1_composite_gang_scheduling_policy_t *v1beta1_composite_gang_scheduling_policy_parseFromJSON(cJSON *v1beta1_composite_gang_scheduling_policyJSON);

cJSON *v1beta1_composite_gang_scheduling_policy_convertToJSON(v1beta1_composite_gang_scheduling_policy_t *v1beta1_composite_gang_scheduling_policy);

#endif /* _v1beta1_composite_gang_scheduling_policy_H_ */

