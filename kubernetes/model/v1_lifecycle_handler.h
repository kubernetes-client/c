/*
 * v1_lifecycle_handler.h
 *
 * LifecycleHandler defines a specific action that should be taken in a lifecycle hook. One and only one of the fields, except TCPSocket must be specified.
 */

#ifndef _v1_lifecycle_handler_H_
#define _v1_lifecycle_handler_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_lifecycle_handler_t v1_lifecycle_handler_t;

#include "v1_exec_action.h"
#include "v1_http_get_action.h"
#include "v1_sleep_action.h"
#include "v1_tcp_socket_action.h"



typedef struct v1_lifecycle_handler_t {
    struct v1_exec_action_t *exec; //model
    struct v1_http_get_action_t *http_get; //model
    struct v1_sleep_action_t *sleep; //model
    struct v1_tcp_socket_action_t *tcp_socket; //model

} v1_lifecycle_handler_t;

v1_lifecycle_handler_t *v1_lifecycle_handler_create(
    v1_exec_action_t *exec,
    v1_http_get_action_t *http_get,
    v1_sleep_action_t *sleep,
    v1_tcp_socket_action_t *tcp_socket
);

void v1_lifecycle_handler_free(v1_lifecycle_handler_t *v1_lifecycle_handler);

v1_lifecycle_handler_t *v1_lifecycle_handler_parseFromJSON(cJSON *v1_lifecycle_handlerJSON);

cJSON *v1_lifecycle_handler_convertToJSON(v1_lifecycle_handler_t *v1_lifecycle_handler);

#endif /* _v1_lifecycle_handler_H_ */

