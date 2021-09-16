/*
 * discovery_v1_endpoint_port.h
 *
 * EndpointPort represents a Port used by an EndpointSlice
 */

#ifndef _discovery_v1_endpoint_port_H_
#define _discovery_v1_endpoint_port_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct discovery_v1_endpoint_port_t discovery_v1_endpoint_port_t;




typedef struct discovery_v1_endpoint_port_t {
    char *app_protocol; // string
    char *name; // string
    int port; //numeric
    char *protocol; // string

} discovery_v1_endpoint_port_t;

discovery_v1_endpoint_port_t *discovery_v1_endpoint_port_create(
    char *app_protocol,
    char *name,
    int port,
    char *protocol
);

void discovery_v1_endpoint_port_free(discovery_v1_endpoint_port_t *discovery_v1_endpoint_port);

discovery_v1_endpoint_port_t *discovery_v1_endpoint_port_parseFromJSON(cJSON *discovery_v1_endpoint_portJSON);

cJSON *discovery_v1_endpoint_port_convertToJSON(discovery_v1_endpoint_port_t *discovery_v1_endpoint_port);

#endif /* _discovery_v1_endpoint_port_H_ */

