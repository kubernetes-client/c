/*
 * policy_v1beta1_host_port_range.h
 *
 * HostPortRange defines a range of host ports that will be enabled by a policy for pods to use.  It requires both the start and end to be defined.
 */

#ifndef _policy_v1beta1_host_port_range_H_
#define _policy_v1beta1_host_port_range_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct policy_v1beta1_host_port_range_t {
    int max; //numeric
    int min; //numeric

} policy_v1beta1_host_port_range_t;

policy_v1beta1_host_port_range_t *policy_v1beta1_host_port_range_create(
    int max,
    int min
);

void policy_v1beta1_host_port_range_free(policy_v1beta1_host_port_range_t *policy_v1beta1_host_port_range);

policy_v1beta1_host_port_range_t *policy_v1beta1_host_port_range_parseFromJSON(cJSON *policy_v1beta1_host_port_rangeJSON);

cJSON *policy_v1beta1_host_port_range_convertToJSON(policy_v1beta1_host_port_range_t *policy_v1beta1_host_port_range);

#endif /* _policy_v1beta1_host_port_range_H_ */

