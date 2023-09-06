/*
 * v1_host_ip.h
 *
 * HostIP represents a single IP address allocated to the host.
 */

#ifndef _v1_host_ip_H_
#define _v1_host_ip_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_host_ip_t v1_host_ip_t;




typedef struct v1_host_ip_t {
    char *ip; // string

} v1_host_ip_t;

v1_host_ip_t *v1_host_ip_create(
    char *ip
);

void v1_host_ip_free(v1_host_ip_t *v1_host_ip);

v1_host_ip_t *v1_host_ip_parseFromJSON(cJSON *v1_host_ipJSON);

cJSON *v1_host_ip_convertToJSON(v1_host_ip_t *v1_host_ip);

#endif /* _v1_host_ip_H_ */

