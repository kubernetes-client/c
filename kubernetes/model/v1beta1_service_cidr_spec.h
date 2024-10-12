/*
 * v1beta1_service_cidr_spec.h
 *
 * ServiceCIDRSpec define the CIDRs the user wants to use for allocating ClusterIPs for Services.
 */

#ifndef _v1beta1_service_cidr_spec_H_
#define _v1beta1_service_cidr_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_service_cidr_spec_t v1beta1_service_cidr_spec_t;




typedef struct v1beta1_service_cidr_spec_t {
    list_t *cidrs; //primitive container

} v1beta1_service_cidr_spec_t;

v1beta1_service_cidr_spec_t *v1beta1_service_cidr_spec_create(
    list_t *cidrs
);

void v1beta1_service_cidr_spec_free(v1beta1_service_cidr_spec_t *v1beta1_service_cidr_spec);

v1beta1_service_cidr_spec_t *v1beta1_service_cidr_spec_parseFromJSON(cJSON *v1beta1_service_cidr_specJSON);

cJSON *v1beta1_service_cidr_spec_convertToJSON(v1beta1_service_cidr_spec_t *v1beta1_service_cidr_spec);

#endif /* _v1beta1_service_cidr_spec_H_ */

