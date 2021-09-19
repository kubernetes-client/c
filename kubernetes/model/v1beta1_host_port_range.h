/*
 * v1beta1_host_port_range.h
 *
 * HostPortRange defines a range of host ports that will be enabled by a policy for pods to use.  It requires both the start and end to be defined.
 */

#ifndef _v1beta1_host_port_range_H_
#define _v1beta1_host_port_range_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_host_port_range_t v1beta1_host_port_range_t;




typedef struct v1beta1_host_port_range_t {
    int max; //numeric
    int min; //numeric

} v1beta1_host_port_range_t;

v1beta1_host_port_range_t *v1beta1_host_port_range_create(
    int max,
    int min
);

void v1beta1_host_port_range_free(v1beta1_host_port_range_t *v1beta1_host_port_range);

v1beta1_host_port_range_t *v1beta1_host_port_range_parseFromJSON(cJSON *v1beta1_host_port_rangeJSON);

cJSON *v1beta1_host_port_range_convertToJSON(v1beta1_host_port_range_t *v1beta1_host_port_range);

#endif /* _v1beta1_host_port_range_H_ */

