/*
 * policy_v1beta1_id_range.h
 *
 * IDRange provides a min/max of an allowed range of IDs.
 */

#ifndef _policy_v1beta1_id_range_H_
#define _policy_v1beta1_id_range_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct policy_v1beta1_id_range_t {
    long max; //numeric
    long min; //numeric

} policy_v1beta1_id_range_t;

policy_v1beta1_id_range_t *policy_v1beta1_id_range_create(
    long max,
    long min
);

void policy_v1beta1_id_range_free(policy_v1beta1_id_range_t *policy_v1beta1_id_range);

policy_v1beta1_id_range_t *policy_v1beta1_id_range_parseFromJSON(cJSON *policy_v1beta1_id_rangeJSON);

cJSON *policy_v1beta1_id_range_convertToJSON(policy_v1beta1_id_range_t *policy_v1beta1_id_range);

#endif /* _policy_v1beta1_id_range_H_ */

