/*
 * v1_endpoint_slice.h
 *
 * EndpointSlice represents a set of service endpoints. Most EndpointSlices are created by the EndpointSlice controller to represent the Pods selected by Service objects. For a given service there may be multiple EndpointSlice objects which must be joined to produce the full set of endpoints; you can find all of the slices for a given service by listing EndpointSlices in the service&#39;s namespace whose &#x60;kubernetes.io/service-name&#x60; label contains the service&#39;s name.
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



typedef struct v1_endpoint_slice_t {
    char *address_type; // string
    char *api_version; // string
    list_t *endpoints; //nonprimitive container
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    list_t *ports; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1_endpoint_slice_t;

__attribute__((deprecated)) v1_endpoint_slice_t *v1_endpoint_slice_create(
    char *address_type,
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

