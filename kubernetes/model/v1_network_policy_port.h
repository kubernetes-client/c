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
#include "../include/binary.h"

typedef struct v1_network_policy_port_t v1_network_policy_port_t;

#include "int_or_string.h"



typedef struct v1_network_policy_port_t {
    int end_port; //numeric
    int_or_string_t *port; // custom
    char *protocol; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_network_policy_port_t;

__attribute__((deprecated)) v1_network_policy_port_t *v1_network_policy_port_create(
    int end_port,
    int_or_string_t *port,
    char *protocol
);

void v1_network_policy_port_free(v1_network_policy_port_t *v1_network_policy_port);

v1_network_policy_port_t *v1_network_policy_port_parseFromJSON(cJSON *v1_network_policy_portJSON);

cJSON *v1_network_policy_port_convertToJSON(v1_network_policy_port_t *v1_network_policy_port);

#endif /* _v1_network_policy_port_H_ */

