/*
 * v1_pod_ip.h
 *
 * IP address information for entries in the (plural) PodIPs field. Each entry includes:    IP: An IP address allocated to the pod. Routable at least within the cluster.
 */

#ifndef _v1_pod_ip_H_
#define _v1_pod_ip_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_pod_ip_t {
    char *ip; // string

} v1_pod_ip_t;

v1_pod_ip_t *v1_pod_ip_create(
    char *ip
);

void v1_pod_ip_free(v1_pod_ip_t *v1_pod_ip);

v1_pod_ip_t *v1_pod_ip_parseFromJSON(cJSON *v1_pod_ipJSON);

cJSON *v1_pod_ip_convertToJSON(v1_pod_ip_t *v1_pod_ip);

#endif /* _v1_pod_ip_H_ */

