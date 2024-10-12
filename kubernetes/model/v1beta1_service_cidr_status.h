/*
 * v1beta1_service_cidr_status.h
 *
 * ServiceCIDRStatus describes the current state of the ServiceCIDR.
 */

#ifndef _v1beta1_service_cidr_status_H_
#define _v1beta1_service_cidr_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_service_cidr_status_t v1beta1_service_cidr_status_t;

#include "v1_condition.h"



typedef struct v1beta1_service_cidr_status_t {
    list_t *conditions; //nonprimitive container

} v1beta1_service_cidr_status_t;

v1beta1_service_cidr_status_t *v1beta1_service_cidr_status_create(
    list_t *conditions
);

void v1beta1_service_cidr_status_free(v1beta1_service_cidr_status_t *v1beta1_service_cidr_status);

v1beta1_service_cidr_status_t *v1beta1_service_cidr_status_parseFromJSON(cJSON *v1beta1_service_cidr_statusJSON);

cJSON *v1beta1_service_cidr_status_convertToJSON(v1beta1_service_cidr_status_t *v1beta1_service_cidr_status);

#endif /* _v1beta1_service_cidr_status_H_ */

