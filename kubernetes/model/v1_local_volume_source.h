/*
 * v1_local_volume_source.h
 *
 * Local represents directly-attached storage with node affinity (Beta feature)
 */

#ifndef _v1_local_volume_source_H_
#define _v1_local_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_local_volume_source_t v1_local_volume_source_t;




typedef struct v1_local_volume_source_t {
    char *fs_type; // string
    char *path; // string

} v1_local_volume_source_t;

v1_local_volume_source_t *v1_local_volume_source_create(
    char *fs_type,
    char *path
);

void v1_local_volume_source_free(v1_local_volume_source_t *v1_local_volume_source);

v1_local_volume_source_t *v1_local_volume_source_parseFromJSON(cJSON *v1_local_volume_sourceJSON);

cJSON *v1_local_volume_source_convertToJSON(v1_local_volume_source_t *v1_local_volume_source);

#endif /* _v1_local_volume_source_H_ */

