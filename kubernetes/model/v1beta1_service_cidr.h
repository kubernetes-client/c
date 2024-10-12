/*
 * v1beta1_service_cidr.h
 *
 * ServiceCIDR defines a range of IP addresses using CIDR format (e.g. 192.168.0.0/24 or 2001:db2::/64). This range is used to allocate ClusterIPs to Service objects.
 */

#ifndef _v1beta1_service_cidr_H_
#define _v1beta1_service_cidr_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_service_cidr_t v1beta1_service_cidr_t;

#include "v1_object_meta.h"
#include "v1beta1_service_cidr_spec.h"
#include "v1beta1_service_cidr_status.h"



typedef struct v1beta1_service_cidr_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1beta1_service_cidr_spec_t *spec; //model
    struct v1beta1_service_cidr_status_t *status; //model

} v1beta1_service_cidr_t;

v1beta1_service_cidr_t *v1beta1_service_cidr_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta1_service_cidr_spec_t *spec,
    v1beta1_service_cidr_status_t *status
);

void v1beta1_service_cidr_free(v1beta1_service_cidr_t *v1beta1_service_cidr);

v1beta1_service_cidr_t *v1beta1_service_cidr_parseFromJSON(cJSON *v1beta1_service_cidrJSON);

cJSON *v1beta1_service_cidr_convertToJSON(v1beta1_service_cidr_t *v1beta1_service_cidr);

#endif /* _v1beta1_service_cidr_H_ */

