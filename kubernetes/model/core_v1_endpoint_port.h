/*
 * core_v1_endpoint_port.h
 *
 * EndpointPort is a tuple that describes a single port.
 */

#ifndef _core_v1_endpoint_port_H_
#define _core_v1_endpoint_port_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct core_v1_endpoint_port_t core_v1_endpoint_port_t;


// Enum PROTOCOL for core_v1_endpoint_port

typedef enum  { kubernetes_core_v1_endpoint_port_PROTOCOL_NULL = 0, kubernetes_core_v1_endpoint_port_PROTOCOL_SCTP, kubernetes_core_v1_endpoint_port_PROTOCOL_TCP, kubernetes_core_v1_endpoint_port_PROTOCOL_UDP } kubernetes_core_v1_endpoint_port_PROTOCOL_e;

char* core_v1_endpoint_port_protocol_ToString(kubernetes_core_v1_endpoint_port_PROTOCOL_e protocol);

kubernetes_core_v1_endpoint_port_PROTOCOL_e core_v1_endpoint_port_protocol_FromString(char* protocol);



typedef struct core_v1_endpoint_port_t {
    char *app_protocol; // string
    char *name; // string
    int port; //numeric
    kubernetes_core_v1_endpoint_port_PROTOCOL_e protocol; //enum

} core_v1_endpoint_port_t;

core_v1_endpoint_port_t *core_v1_endpoint_port_create(
    char *app_protocol,
    char *name,
    int port,
    kubernetes_core_v1_endpoint_port_PROTOCOL_e protocol
);

void core_v1_endpoint_port_free(core_v1_endpoint_port_t *core_v1_endpoint_port);

core_v1_endpoint_port_t *core_v1_endpoint_port_parseFromJSON(cJSON *core_v1_endpoint_portJSON);

cJSON *core_v1_endpoint_port_convertToJSON(core_v1_endpoint_port_t *core_v1_endpoint_port);

#endif /* _core_v1_endpoint_port_H_ */

