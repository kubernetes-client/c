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

#include "object.h"



typedef struct v1_service_port_t {
    char *name; // string
    int node_port; //numeric
    int port; //numeric
    char *protocol; // string
    object_t *target_port; //object

} v1_service_port_t;

v1_service_port_t *v1_service_port_create(
    char *name,
    int node_port,
    int port,
    char *protocol,
    object_t *target_port
);

void v1_service_port_free(v1_service_port_t *v1_service_port);

v1_service_port_t *v1_service_port_parseFromJSON(cJSON *v1_service_portJSON);

cJSON *v1_service_port_convertToJSON(v1_service_port_t *v1_service_port);

#endif /* _v1_service_port_H_ */

