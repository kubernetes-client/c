/*
 * v1_config_map_volume_source.h
 *
 * Adapts a ConfigMap into a volume.  The contents of the target ConfigMap&#39;s Data field will be presented in a volume as files using the keys in the Data field as the file names, unless the items element is populated with specific mappings of keys to paths. ConfigMap volumes support ownership management and SELinux relabeling.
 */

#ifndef _v1_config_map_volume_source_H_
#define _v1_config_map_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_config_map_volume_source_t v1_config_map_volume_source_t;

#include "v1_key_to_path.h"



typedef struct v1_config_map_volume_source_t {
    int default_mode; //numeric
    list_t *items; //nonprimitive container
    char *name; // string
    int optional; //boolean

} v1_config_map_volume_source_t;

v1_config_map_volume_source_t *v1_config_map_volume_source_create(
    int default_mode,
    list_t *items,
    char *name,
    int optional
);

void v1_config_map_volume_source_free(v1_config_map_volume_source_t *v1_config_map_volume_source);

v1_config_map_volume_source_t *v1_config_map_volume_source_parseFromJSON(cJSON *v1_config_map_volume_sourceJSON);

cJSON *v1_config_map_volume_source_convertToJSON(v1_config_map_volume_source_t *v1_config_map_volume_source);

#endif /* _v1_config_map_volume_source_H_ */

