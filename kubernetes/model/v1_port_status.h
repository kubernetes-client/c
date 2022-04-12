/*
 * v1_port_status.h
 *
 * 
 */

#ifndef _v1_port_status_H_
#define _v1_port_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_port_status_t v1_port_status_t;


// Enum PROTOCOL for v1_port_status

typedef enum  { kubernetes_v1_port_status_PROTOCOL_NULL = 0, kubernetes_v1_port_status_PROTOCOL_SCTP, kubernetes_v1_port_status_PROTOCOL_TCP, kubernetes_v1_port_status_PROTOCOL_UDP } kubernetes_v1_port_status_PROTOCOL_e;

char* v1_port_status_protocol_ToString(kubernetes_v1_port_status_PROTOCOL_e protocol);

kubernetes_v1_port_status_PROTOCOL_e v1_port_status_protocol_FromString(char* protocol);



typedef struct v1_port_status_t {
    char *error; // string
    int port; //numeric
    kubernetes_v1_port_status_PROTOCOL_e protocol; //enum

} v1_port_status_t;

v1_port_status_t *v1_port_status_create(
    char *error,
    int port,
    kubernetes_v1_port_status_PROTOCOL_e protocol
);

void v1_port_status_free(v1_port_status_t *v1_port_status);

v1_port_status_t *v1_port_status_parseFromJSON(cJSON *v1_port_statusJSON);

cJSON *v1_port_status_convertToJSON(v1_port_status_t *v1_port_status);

#endif /* _v1_port_status_H_ */

