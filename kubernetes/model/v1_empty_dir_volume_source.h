/*
 * v1_empty_dir_volume_source.h
 *
 * Represents an empty directory for a pod. Empty directory volumes support ownership management and SELinux relabeling.
 */

#ifndef _v1_empty_dir_volume_source_H_
#define _v1_empty_dir_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_empty_dir_volume_source_t v1_empty_dir_volume_source_t;




typedef struct v1_empty_dir_volume_source_t {
    char *medium; // string
    char *size_limit; // string

} v1_empty_dir_volume_source_t;

v1_empty_dir_volume_source_t *v1_empty_dir_volume_source_create(
    char *medium,
    char *size_limit
);

void v1_empty_dir_volume_source_free(v1_empty_dir_volume_source_t *v1_empty_dir_volume_source);

v1_empty_dir_volume_source_t *v1_empty_dir_volume_source_parseFromJSON(cJSON *v1_empty_dir_volume_sourceJSON);

cJSON *v1_empty_dir_volume_source_convertToJSON(v1_empty_dir_volume_source_t *v1_empty_dir_volume_source);

#endif /* _v1_empty_dir_volume_source_H_ */

