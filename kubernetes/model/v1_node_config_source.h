/*
 * v1_node_config_source.h
 *
 * NodeConfigSource specifies a source of node configuration. Exactly one subfield (excluding metadata) must be non-nil.
 */

#ifndef _v1_node_config_source_H_
#define _v1_node_config_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_node_config_source_t v1_node_config_source_t;

#include "v1_config_map_node_config_source.h"



typedef struct v1_node_config_source_t {
    struct v1_config_map_node_config_source_t *config_map; //model

} v1_node_config_source_t;

v1_node_config_source_t *v1_node_config_source_create(
    v1_config_map_node_config_source_t *config_map
);

void v1_node_config_source_free(v1_node_config_source_t *v1_node_config_source);

v1_node_config_source_t *v1_node_config_source_parseFromJSON(cJSON *v1_node_config_sourceJSON);

cJSON *v1_node_config_source_convertToJSON(v1_node_config_source_t *v1_node_config_source);

#endif /* _v1_node_config_source_H_ */

