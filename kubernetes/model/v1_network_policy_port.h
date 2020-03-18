/*
 * v1_network_policy_port.h
 *
 * NetworkPolicyPort describes a port to allow traffic on
 */

#ifndef _v1_network_policy_port_H_
#define _v1_network_policy_port_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "object.h"



typedef struct v1_network_policy_port_t {
    object_t *port; //object
    char *protocol; // string

} v1_network_policy_port_t;

v1_network_policy_port_t *v1_network_policy_port_create(
    object_t *port,
    char *protocol
);

void v1_network_policy_port_free(v1_network_policy_port_t *v1_network_policy_port);

v1_network_policy_port_t *v1_network_policy_port_parseFromJSON(cJSON *v1_network_policy_portJSON);

cJSON *v1_network_policy_port_convertToJSON(v1_network_policy_port_t *v1_network_policy_port);

#endif /* _v1_network_policy_port_H_ */

