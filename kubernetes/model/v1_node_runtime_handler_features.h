/*
 * v1_node_runtime_handler_features.h
 *
 * NodeRuntimeHandlerFeatures is a set of features implemented by the runtime handler.
 */

#ifndef _v1_node_runtime_handler_features_H_
#define _v1_node_runtime_handler_features_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_node_runtime_handler_features_t v1_node_runtime_handler_features_t;




typedef struct v1_node_runtime_handler_features_t {
    int recursive_read_only_mounts; //boolean
    int user_namespaces; //boolean

} v1_node_runtime_handler_features_t;

v1_node_runtime_handler_features_t *v1_node_runtime_handler_features_create(
    int recursive_read_only_mounts,
    int user_namespaces
);

void v1_node_runtime_handler_features_free(v1_node_runtime_handler_features_t *v1_node_runtime_handler_features);

v1_node_runtime_handler_features_t *v1_node_runtime_handler_features_parseFromJSON(cJSON *v1_node_runtime_handler_featuresJSON);

cJSON *v1_node_runtime_handler_features_convertToJSON(v1_node_runtime_handler_features_t *v1_node_runtime_handler_features);

#endif /* _v1_node_runtime_handler_features_H_ */

