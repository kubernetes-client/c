/*
 * extensions_v1beta1_host_port_range.h
 *
 * HostPortRange defines a range of host ports that will be enabled by a policy for pods to use.  It requires both the start and end to be defined. Deprecated: use HostPortRange from policy API Group instead.
 */

#ifndef _extensions_v1beta1_host_port_range_H_
#define _extensions_v1beta1_host_port_range_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct extensions_v1beta1_host_port_range_t {
    int max; //numeric
    int min; //numeric

} extensions_v1beta1_host_port_range_t;

extensions_v1beta1_host_port_range_t *extensions_v1beta1_host_port_range_create(
    int max,
    int min
);

void extensions_v1beta1_host_port_range_free(extensions_v1beta1_host_port_range_t *extensions_v1beta1_host_port_range);

extensions_v1beta1_host_port_range_t *extensions_v1beta1_host_port_range_parseFromJSON(cJSON *extensions_v1beta1_host_port_rangeJSON);

cJSON *extensions_v1beta1_host_port_range_convertToJSON(extensions_v1beta1_host_port_range_t *extensions_v1beta1_host_port_range);

#endif /* _extensions_v1beta1_host_port_range_H_ */

