/*
 * v1_container_port.h
 *
 * ContainerPort represents a network port in a single container.
 */

#ifndef _v1_container_port_H_
#define _v1_container_port_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_container_port_t v1_container_port_t;




typedef struct v1_container_port_t {
    int container_port; //numeric
    char *host_ip; // string
    int host_port; //numeric
    char *name; // string
    char *protocol; // string

} v1_container_port_t;

v1_container_port_t *v1_container_port_create(
    int container_port,
    char *host_ip,
    int host_port,
    char *name,
    char *protocol
);

void v1_container_port_free(v1_container_port_t *v1_container_port);

v1_container_port_t *v1_container_port_parseFromJSON(cJSON *v1_container_portJSON);

cJSON *v1_container_port_convertToJSON(v1_container_port_t *v1_container_port);

#endif /* _v1_container_port_H_ */

