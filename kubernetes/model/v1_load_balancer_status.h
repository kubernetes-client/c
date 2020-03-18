/*
 * v1_load_balancer_status.h
 *
 * LoadBalancerStatus represents the status of a load-balancer.
 */

#ifndef _v1_load_balancer_status_H_
#define _v1_load_balancer_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_load_balancer_ingress.h"



typedef struct v1_load_balancer_status_t {
    list_t *ingress; //nonprimitive container

} v1_load_balancer_status_t;

v1_load_balancer_status_t *v1_load_balancer_status_create(
    list_t *ingress
);

void v1_load_balancer_status_free(v1_load_balancer_status_t *v1_load_balancer_status);

v1_load_balancer_status_t *v1_load_balancer_status_parseFromJSON(cJSON *v1_load_balancer_statusJSON);

cJSON *v1_load_balancer_status_convertToJSON(v1_load_balancer_status_t *v1_load_balancer_status);

#endif /* _v1_load_balancer_status_H_ */

