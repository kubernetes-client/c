/*
 * v1_node_runtime_handler.h
 *
 * NodeRuntimeHandler is a set of runtime handler information.
 */

#ifndef _v1_node_runtime_handler_H_
#define _v1_node_runtime_handler_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_node_runtime_handler_t v1_node_runtime_handler_t;

#include "v1_node_runtime_handler_features.h"



typedef struct v1_node_runtime_handler_t {
    struct v1_node_runtime_handler_features_t *features; //model
    char *name; // string

} v1_node_runtime_handler_t;

v1_node_runtime_handler_t *v1_node_runtime_handler_create(
    v1_node_runtime_handler_features_t *features,
    char *name
);

void v1_node_runtime_handler_free(v1_node_runtime_handler_t *v1_node_runtime_handler);

v1_node_runtime_handler_t *v1_node_runtime_handler_parseFromJSON(cJSON *v1_node_runtime_handlerJSON);

cJSON *v1_node_runtime_handler_convertToJSON(v1_node_runtime_handler_t *v1_node_runtime_handler);

#endif /* _v1_node_runtime_handler_H_ */

