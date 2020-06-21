/*
 * v1_daemon_endpoint.h
 *
 * DaemonEndpoint contains information about a single Daemon endpoint.
 */

#ifndef _v1_daemon_endpoint_H_
#define _v1_daemon_endpoint_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_daemon_endpoint_t v1_daemon_endpoint_t;




typedef struct v1_daemon_endpoint_t {
    int port; //numeric

} v1_daemon_endpoint_t;

v1_daemon_endpoint_t *v1_daemon_endpoint_create(
    int port
);

void v1_daemon_endpoint_free(v1_daemon_endpoint_t *v1_daemon_endpoint);

v1_daemon_endpoint_t *v1_daemon_endpoint_parseFromJSON(cJSON *v1_daemon_endpointJSON);

cJSON *v1_daemon_endpoint_convertToJSON(v1_daemon_endpoint_t *v1_daemon_endpoint);

#endif /* _v1_daemon_endpoint_H_ */

