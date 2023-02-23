/*
 * v1_ingress_status.h
 *
 * IngressStatus describe the current state of the Ingress.
 */

#ifndef _v1_ingress_status_H_
#define _v1_ingress_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_ingress_status_t v1_ingress_status_t;

#include "v1_ingress_load_balancer_status.h"



typedef struct v1_ingress_status_t {
    struct v1_ingress_load_balancer_status_t *load_balancer; //model

} v1_ingress_status_t;

v1_ingress_status_t *v1_ingress_status_create(
    v1_ingress_load_balancer_status_t *load_balancer
);

void v1_ingress_status_free(v1_ingress_status_t *v1_ingress_status);

v1_ingress_status_t *v1_ingress_status_parseFromJSON(cJSON *v1_ingress_statusJSON);

cJSON *v1_ingress_status_convertToJSON(v1_ingress_status_t *v1_ingress_status);

#endif /* _v1_ingress_status_H_ */

