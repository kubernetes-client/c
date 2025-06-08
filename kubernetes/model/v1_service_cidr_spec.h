/*
 * v1_service_cidr_spec.h
 *
 * ServiceCIDRSpec define the CIDRs the user wants to use for allocating ClusterIPs for Services.
 */

#ifndef _v1_service_cidr_spec_H_
#define _v1_service_cidr_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_service_cidr_spec_t v1_service_cidr_spec_t;




typedef struct v1_service_cidr_spec_t {
    list_t *cidrs; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1_service_cidr_spec_t;

__attribute__((deprecated)) v1_service_cidr_spec_t *v1_service_cidr_spec_create(
    list_t *cidrs
);

void v1_service_cidr_spec_free(v1_service_cidr_spec_t *v1_service_cidr_spec);

v1_service_cidr_spec_t *v1_service_cidr_spec_parseFromJSON(cJSON *v1_service_cidr_specJSON);

cJSON *v1_service_cidr_spec_convertToJSON(v1_service_cidr_spec_t *v1_service_cidr_spec);

#endif /* _v1_service_cidr_spec_H_ */

