/*
 * v1_endpoints.h
 *
 * Endpoints is a collection of endpoints that implement the actual service. Example:   Name: \&quot;mysvc\&quot;,   Subsets: [     {       Addresses: [{\&quot;ip\&quot;: \&quot;10.10.1.1\&quot;}, {\&quot;ip\&quot;: \&quot;10.10.2.2\&quot;}],       Ports: [{\&quot;name\&quot;: \&quot;a\&quot;, \&quot;port\&quot;: 8675}, {\&quot;name\&quot;: \&quot;b\&quot;, \&quot;port\&quot;: 309}]     },     {       Addresses: [{\&quot;ip\&quot;: \&quot;10.10.3.3\&quot;}],       Ports: [{\&quot;name\&quot;: \&quot;a\&quot;, \&quot;port\&quot;: 93}, {\&quot;name\&quot;: \&quot;b\&quot;, \&quot;port\&quot;: 76}]     },  ]
 */

#ifndef _v1_endpoints_H_
#define _v1_endpoints_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_endpoints_t v1_endpoints_t;

#include "v1_endpoint_subset.h"
#include "v1_object_meta.h"



typedef struct v1_endpoints_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    list_t *subsets; //nonprimitive container

} v1_endpoints_t;

v1_endpoints_t *v1_endpoints_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *subsets
);

void v1_endpoints_free(v1_endpoints_t *v1_endpoints);

v1_endpoints_t *v1_endpoints_parseFromJSON(cJSON *v1_endpointsJSON);

cJSON *v1_endpoints_convertToJSON(v1_endpoints_t *v1_endpoints);

#endif /* _v1_endpoints_H_ */

