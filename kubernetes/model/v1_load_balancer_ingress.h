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



typedef struct v1_load_balancer_ingress_t {
    char *hostname; // string
    char *ip; // string

} v1_load_balancer_ingress_t;

v1_load_balancer_ingress_t *v1_load_balancer_ingress_create(
    char *hostname,
    char *ip
);

void v1_load_balancer_ingress_free(v1_load_balancer_ingress_t *v1_load_balancer_ingress);

v1_load_balancer_ingress_t *v1_load_balancer_ingress_parseFromJSON(cJSON *v1_load_balancer_ingressJSON);

cJSON *v1_load_balancer_ingress_convertToJSON(v1_load_balancer_ingress_t *v1_load_balancer_ingress);

#endif /* _v1_load_balancer_ingress_H_ */

