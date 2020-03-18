/*
 * v1_pod_dns_config.h
 *
 * PodDNSConfig defines the DNS parameters of a pod in addition to those generated from DNSPolicy.
 */

#ifndef _v1_pod_dns_config_H_
#define _v1_pod_dns_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_pod_dns_config_option.h"



typedef struct v1_pod_dns_config_t {
    list_t *nameservers; //primitive container
    list_t *options; //nonprimitive container
    list_t *searches; //primitive container

} v1_pod_dns_config_t;

v1_pod_dns_config_t *v1_pod_dns_config_create(
    list_t *nameservers,
    list_t *options,
    list_t *searches
);

void v1_pod_dns_config_free(v1_pod_dns_config_t *v1_pod_dns_config);

v1_pod_dns_config_t *v1_pod_dns_config_parseFromJSON(cJSON *v1_pod_dns_configJSON);

cJSON *v1_pod_dns_config_convertToJSON(v1_pod_dns_config_t *v1_pod_dns_config);

#endif /* _v1_pod_dns_config_H_ */

