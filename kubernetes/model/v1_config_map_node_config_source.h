/*
 * v1_config_map_node_config_source.h
 *
 * ConfigMapNodeConfigSource contains the information to reference a ConfigMap as a config source for the Node.
 */

#ifndef _v1_config_map_node_config_source_H_
#define _v1_config_map_node_config_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_config_map_node_config_source_t v1_config_map_node_config_source_t;




typedef struct v1_config_map_node_config_source_t {
    char *kubelet_config_key; // string
    char *name; // string
    char *_namespace; // string
    char *resource_version; // string
    char *uid; // string

} v1_config_map_node_config_source_t;

v1_config_map_node_config_source_t *v1_config_map_node_config_source_create(
    char *kubelet_config_key,
    char *name,
    char *_namespace,
    char *resource_version,
    char *uid
);

void v1_config_map_node_config_source_free(v1_config_map_node_config_source_t *v1_config_map_node_config_source);

v1_config_map_node_config_source_t *v1_config_map_node_config_source_parseFromJSON(cJSON *v1_config_map_node_config_sourceJSON);

cJSON *v1_config_map_node_config_source_convertToJSON(v1_config_map_node_config_source_t *v1_config_map_node_config_source);

#endif /* _v1_config_map_node_config_source_H_ */

