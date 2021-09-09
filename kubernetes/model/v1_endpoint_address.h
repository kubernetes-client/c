/*
 * v1_endpoint_address.h
 *
 * EndpointAddress is a tuple that describes single IP address.
 */

#ifndef _v1_endpoint_address_H_
#define _v1_endpoint_address_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_endpoint_address_t v1_endpoint_address_t;

#include "v1_object_reference.h"



typedef struct v1_endpoint_address_t {
    char *hostname; // string
    char *ip; // string
    char *node_name; // string
    struct v1_object_reference_t *target_ref; //model

} v1_endpoint_address_t;

v1_endpoint_address_t *v1_endpoint_address_create(
    char *hostname,
    char *ip,
    char *node_name,
    v1_object_reference_t *target_ref
);

void v1_endpoint_address_free(v1_endpoint_address_t *v1_endpoint_address);

v1_endpoint_address_t *v1_endpoint_address_parseFromJSON(cJSON *v1_endpoint_addressJSON);

cJSON *v1_endpoint_address_convertToJSON(v1_endpoint_address_t *v1_endpoint_address);

#endif /* _v1_endpoint_address_H_ */

