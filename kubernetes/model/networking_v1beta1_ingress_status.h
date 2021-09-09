/*
 * networking_v1beta1_ingress_status.h
 *
 * IngressStatus describe the current state of the Ingress.
 */

#ifndef _networking_v1beta1_ingress_status_H_
#define _networking_v1beta1_ingress_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct networking_v1beta1_ingress_status_t networking_v1beta1_ingress_status_t;

#include "v1_load_balancer_status.h"



typedef struct networking_v1beta1_ingress_status_t {
    struct v1_load_balancer_status_t *load_balancer; //model

} networking_v1beta1_ingress_status_t;

networking_v1beta1_ingress_status_t *networking_v1beta1_ingress_status_create(
    v1_load_balancer_status_t *load_balancer
);

void networking_v1beta1_ingress_status_free(networking_v1beta1_ingress_status_t *networking_v1beta1_ingress_status);

networking_v1beta1_ingress_status_t *networking_v1beta1_ingress_status_parseFromJSON(cJSON *networking_v1beta1_ingress_statusJSON);

cJSON *networking_v1beta1_ingress_status_convertToJSON(networking_v1beta1_ingress_status_t *networking_v1beta1_ingress_status);

#endif /* _networking_v1beta1_ingress_status_H_ */

