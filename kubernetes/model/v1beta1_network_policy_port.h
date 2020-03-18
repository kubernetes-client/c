/*
 * v1beta1_network_policy_port.h
 *
 * DEPRECATED 1.9 - This group version of NetworkPolicyPort is deprecated by networking/v1/NetworkPolicyPort.
 */

#ifndef _v1beta1_network_policy_port_H_
#define _v1beta1_network_policy_port_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "object.h"



typedef struct v1beta1_network_policy_port_t {
    object_t *port; //object
    char *protocol; // string

} v1beta1_network_policy_port_t;

v1beta1_network_policy_port_t *v1beta1_network_policy_port_create(
    object_t *port,
    char *protocol
);

void v1beta1_network_policy_port_free(v1beta1_network_policy_port_t *v1beta1_network_policy_port);

v1beta1_network_policy_port_t *v1beta1_network_policy_port_parseFromJSON(cJSON *v1beta1_network_policy_portJSON);

cJSON *v1beta1_network_policy_port_convertToJSON(v1beta1_network_policy_port_t *v1beta1_network_policy_port);

#endif /* _v1beta1_network_policy_port_H_ */

