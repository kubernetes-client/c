/*
 * v1_host_path_volume_source.h
 *
 * Represents a host path mapped into a pod. Host path volumes do not support ownership management or SELinux relabeling.
 */

#ifndef _v1_host_path_volume_source_H_
#define _v1_host_path_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_host_path_volume_source_t {
    char *path; // string
    char *type; // string

} v1_host_path_volume_source_t;

v1_host_path_volume_source_t *v1_host_path_volume_source_create(
    char *path,
    char *type
);

void v1_host_path_volume_source_free(v1_host_path_volume_source_t *v1_host_path_volume_source);

v1_host_path_volume_source_t *v1_host_path_volume_source_parseFromJSON(cJSON *v1_host_path_volume_sourceJSON);

cJSON *v1_host_path_volume_source_convertToJSON(v1_host_path_volume_source_t *v1_host_path_volume_source);

#endif /* _v1_host_path_volume_source_H_ */

