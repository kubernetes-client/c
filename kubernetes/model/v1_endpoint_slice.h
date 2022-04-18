/*
 * v1_endpoint_slice.h
 *
 * EndpointSlice represents a subset of the endpoints that implement a service. For a given service there may be multiple EndpointSlice objects, selected by labels, which must be joined to produce the full set of endpoints.
 */

#ifndef _v1_endpoint_slice_H_
#define _v1_endpoint_slice_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_endpoint_slice_t v1_endpoint_slice_t;

#include "discovery_v1_endpoint_port.h"
#include "v1_endpoint.h"
#include "v1_object_meta.h"

// Enum ADDRESSTYPE for v1_endpoint_slice

typedef enum  { kubernetes_v1_endpoint_slice_ADDRESSTYPE_NULL = 0, kubernetes_v1_endpoint_slice_ADDRESSTYPE_FQDN, kubernetes_v1_endpoint_slice_ADDRESSTYPE_IPv4, kubernetes_v1_endpoint_slice_ADDRESSTYPE_IPv6 } kubernetes_v1_endpoint_slice_ADDRESSTYPE_e;

char* v1_endpoint_slice_address_type_ToString(kubernetes_v1_endpoint_slice_ADDRESSTYPE_e address_type);

kubernetes_v1_endpoint_slice_ADDRESSTYPE_e v1_endpoint_slice_address_type_FromString(char* address_type);



typedef struct v1_endpoint_slice_t {
    kubernetes_v1_endpoint_slice_ADDRESSTYPE_e address_type; //enum
    char *api_version; // string
    list_t *endpoints; //nonprimitive container
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    list_t *ports; //nonprimitive container

} v1_endpoint_slice_t;

v1_endpoint_slice_t *v1_endpoint_slice_create(
    kubernetes_v1_endpoint_slice_ADDRESSTYPE_e address_type,
    char *api_version,
    list_t *endpoints,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *ports
);

void v1_endpoint_slice_free(v1_endpoint_slice_t *v1_endpoint_slice);

v1_endpoint_slice_t *v1_endpoint_slice_parseFromJSON(cJSON *v1_endpoint_sliceJSON);

cJSON *v1_endpoint_slice_convertToJSON(v1_endpoint_slice_t *v1_endpoint_slice);

#endif /* _v1_endpoint_slice_H_ */

