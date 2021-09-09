/*
 * v1_service_status.h
 *
 * ServiceStatus represents the current status of a service.
 */

#ifndef _v1_service_status_H_
#define _v1_service_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_service_status_t v1_service_status_t;

#include "v1_load_balancer_status.h"



typedef struct v1_service_status_t {
    struct v1_load_balancer_status_t *load_balancer; //model

} v1_service_status_t;

v1_service_status_t *v1_service_status_create(
    v1_load_balancer_status_t *load_balancer
);

void v1_service_status_free(v1_service_status_t *v1_service_status);

v1_service_status_t *v1_service_status_parseFromJSON(cJSON *v1_service_statusJSON);

cJSON *v1_service_status_convertToJSON(v1_service_status_t *v1_service_status);

#endif /* _v1_service_status_H_ */

