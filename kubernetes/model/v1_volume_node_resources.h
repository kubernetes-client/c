/*
 * v1_volume_node_resources.h
 *
 * VolumeNodeResources is a set of resource limits for scheduling of volumes.
 */

#ifndef _v1_volume_node_resources_H_
#define _v1_volume_node_resources_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_volume_node_resources_t v1_volume_node_resources_t;




typedef struct v1_volume_node_resources_t {
    int count; //numeric

} v1_volume_node_resources_t;

v1_volume_node_resources_t *v1_volume_node_resources_create(
    int count
);

void v1_volume_node_resources_free(v1_volume_node_resources_t *v1_volume_node_resources);

v1_volume_node_resources_t *v1_volume_node_resources_parseFromJSON(cJSON *v1_volume_node_resourcesJSON);

cJSON *v1_volume_node_resources_convertToJSON(v1_volume_node_resources_t *v1_volume_node_resources);

#endif /* _v1_volume_node_resources_H_ */

