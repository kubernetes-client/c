/*
 * v1_tcp_socket_action.h
 *
 * TCPSocketAction describes an action based on opening a socket
 */

#ifndef _v1_tcp_socket_action_H_
#define _v1_tcp_socket_action_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "object.h"



typedef struct v1_tcp_socket_action_t {
    char *host; // string
    object_t *port; //object

} v1_tcp_socket_action_t;

v1_tcp_socket_action_t *v1_tcp_socket_action_create(
    char *host,
    object_t *port
);

void v1_tcp_socket_action_free(v1_tcp_socket_action_t *v1_tcp_socket_action);

v1_tcp_socket_action_t *v1_tcp_socket_action_parseFromJSON(cJSON *v1_tcp_socket_actionJSON);

cJSON *v1_tcp_socket_action_convertToJSON(v1_tcp_socket_action_t *v1_tcp_socket_action);

#endif /* _v1_tcp_socket_action_H_ */

