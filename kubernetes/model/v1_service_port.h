/*
 * v1_service_port.h
 *
 * ServicePort contains information on service&#39;s port.
 */

#ifndef _v1_service_port_H_
#define _v1_service_port_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_service_port_t v1_service_port_t;

#include "int_or_string.h"

// Enum PROTOCOL for v1_service_port

typedef enum  { kubernetes_v1_service_port_PROTOCOL_NULL = 0, kubernetes_v1_service_port_PROTOCOL_SCTP, kubernetes_v1_service_port_PROTOCOL_TCP, kubernetes_v1_service_port_PROTOCOL_UDP } kubernetes_v1_service_port_PROTOCOL_e;

char* v1_service_port_protocol_ToString(kubernetes_v1_service_port_PROTOCOL_e protocol);

kubernetes_v1_service_port_PROTOCOL_e v1_service_port_protocol_FromString(char* protocol);



typedef struct v1_service_port_t {
    char *app_protocol; // string
    char *name; // string
    int node_port; //numeric
    int port; //numeric
    kubernetes_v1_service_port_PROTOCOL_e protocol; //enum
    int_or_string_t *target_port; // custom

} v1_service_port_t;

v1_service_port_t *v1_service_port_create(
    char *app_protocol,
    char *name,
    int node_port,
    int port,
    kubernetes_v1_service_port_PROTOCOL_e protocol,
    int_or_string_t *target_port
);

void v1_service_port_free(v1_service_port_t *v1_service_port);

v1_service_port_t *v1_service_port_parseFromJSON(cJSON *v1_service_portJSON);

cJSON *v1_service_port_convertToJSON(v1_service_port_t *v1_service_port);

#endif /* _v1_service_port_H_ */

