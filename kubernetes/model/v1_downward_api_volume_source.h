/*
 * v1_downward_api_volume_source.h
 *
 * DownwardAPIVolumeSource represents a volume containing downward API info. Downward API volumes support ownership management and SELinux relabeling.
 */

#ifndef _v1_downward_api_volume_source_H_
#define _v1_downward_api_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_downward_api_volume_source_t v1_downward_api_volume_source_t;

#include "v1_downward_api_volume_file.h"



typedef struct v1_downward_api_volume_source_t {
    int default_mode; //numeric
    list_t *items; //nonprimitive container

} v1_downward_api_volume_source_t;

v1_downward_api_volume_source_t *v1_downward_api_volume_source_create(
    int default_mode,
    list_t *items
);

void v1_downward_api_volume_source_free(v1_downward_api_volume_source_t *v1_downward_api_volume_source);

v1_downward_api_volume_source_t *v1_downward_api_volume_source_parseFromJSON(cJSON *v1_downward_api_volume_sourceJSON);

cJSON *v1_downward_api_volume_source_convertToJSON(v1_downward_api_volume_source_t *v1_downward_api_volume_source);

#endif /* _v1_downward_api_volume_source_H_ */

