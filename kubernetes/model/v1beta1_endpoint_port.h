/*
 * v1beta1_endpoint_port.h
 *
 * EndpointPort represents a Port used by an EndpointSlice
 */

#ifndef _v1beta1_endpoint_port_H_
#define _v1beta1_endpoint_port_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_endpoint_port_t v1beta1_endpoint_port_t;




typedef struct v1beta1_endpoint_port_t {
    char *app_protocol; // string
    char *name; // string
    int port; //numeric
    char *protocol; // string

} v1beta1_endpoint_port_t;

v1beta1_endpoint_port_t *v1beta1_endpoint_port_create(
    char *app_protocol,
    char *name,
    int port,
    char *protocol
);

void v1beta1_endpoint_port_free(v1beta1_endpoint_port_t *v1beta1_endpoint_port);

v1beta1_endpoint_port_t *v1beta1_endpoint_port_parseFromJSON(cJSON *v1beta1_endpoint_portJSON);

cJSON *v1beta1_endpoint_port_convertToJSON(v1beta1_endpoint_port_t *v1beta1_endpoint_port);

#endif /* _v1beta1_endpoint_port_H_ */

