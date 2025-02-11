/*
 * v1_load_balancer_ingress.h
 *
 * LoadBalancerIngress represents the status of a load-balancer ingress point: traffic intended for the service should be sent to an ingress point.
 */

#ifndef _v1_load_balancer_ingress_H_
#define _v1_load_balancer_ingress_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_load_balancer_ingress_t v1_load_balancer_ingress_t;

#include "v1_port_status.h"



typedef struct v1_load_balancer_ingress_t {
    char *hostname; // string
    char *ip; // string
    char *ip_mode; // string
    list_t *ports; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1_load_balancer_ingress_t;

__attribute__((deprecated)) v1_load_balancer_ingress_t *v1_load_balancer_ingress_create(
    char *hostname,
    char *ip,
    char *ip_mode,
    list_t *ports
);

void v1_load_balancer_ingress_free(v1_load_balancer_ingress_t *v1_load_balancer_ingress);

v1_load_balancer_ingress_t *v1_load_balancer_ingress_parseFromJSON(cJSON *v1_load_balancer_ingressJSON);

cJSON *v1_load_balancer_ingress_convertToJSON(v1_load_balancer_ingress_t *v1_load_balancer_ingress);

#endif /* _v1_load_balancer_ingress_H_ */

