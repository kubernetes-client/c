/*
 * v1_config_map_projection.h
 *
 * Adapts a ConfigMap into a projected volume.  The contents of the target ConfigMap&#39;s Data field will be presented in a projected volume as files using the keys in the Data field as the file names, unless the items element is populated with specific mappings of keys to paths. Note that this is identical to a configmap volume source without the default mode.
 */

#ifndef _v1_config_map_projection_H_
#define _v1_config_map_projection_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_key_to_path.h"



typedef struct v1_config_map_projection_t {
    list_t *items; //nonprimitive container
    char *name; // string
    int optional; //boolean

} v1_config_map_projection_t;

v1_config_map_projection_t *v1_config_map_projection_create(
    list_t *items,
    char *name,
    int optional
);

void v1_config_map_projection_free(v1_config_map_projection_t *v1_config_map_projection);

v1_config_map_projection_t *v1_config_map_projection_parseFromJSON(cJSON *v1_config_map_projectionJSON);

cJSON *v1_config_map_projection_convertToJSON(v1_config_map_projection_t *v1_config_map_projection);

#endif /* _v1_config_map_projection_H_ */

