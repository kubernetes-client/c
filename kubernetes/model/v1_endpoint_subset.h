/*
 * v1_endpoint_subset.h
 *
 * EndpointSubset is a group of addresses with a common set of ports. The expanded set of endpoints is the Cartesian product of Addresses x Ports. For example, given:   {     Addresses: [{\&quot;ip\&quot;: \&quot;10.10.1.1\&quot;}, {\&quot;ip\&quot;: \&quot;10.10.2.2\&quot;}],     Ports:     [{\&quot;name\&quot;: \&quot;a\&quot;, \&quot;port\&quot;: 8675}, {\&quot;name\&quot;: \&quot;b\&quot;, \&quot;port\&quot;: 309}]   } The resulting set of endpoints can be viewed as:     a: [ 10.10.1.1:8675, 10.10.2.2:8675 ],     b: [ 10.10.1.1:309, 10.10.2.2:309 ]
 */

#ifndef _v1_endpoint_subset_H_
#define _v1_endpoint_subset_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_endpoint_subset_t v1_endpoint_subset_t;

#include "v1_endpoint_address.h"
#include "v1_endpoint_port.h"



typedef struct v1_endpoint_subset_t {
    list_t *addresses; //nonprimitive container
    list_t *not_ready_addresses; //nonprimitive container
    list_t *ports; //nonprimitive container

} v1_endpoint_subset_t;

v1_endpoint_subset_t *v1_endpoint_subset_create(
    list_t *addresses,
    list_t *not_ready_addresses,
    list_t *ports
);

void v1_endpoint_subset_free(v1_endpoint_subset_t *v1_endpoint_subset);

v1_endpoint_subset_t *v1_endpoint_subset_parseFromJSON(cJSON *v1_endpoint_subsetJSON);

cJSON *v1_endpoint_subset_convertToJSON(v1_endpoint_subset_t *v1_endpoint_subset);

#endif /* _v1_endpoint_subset_H_ */

