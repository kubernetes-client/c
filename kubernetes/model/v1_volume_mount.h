/*
 * v1_volume_mount.h
 *
 * VolumeMount describes a mounting of a Volume within a container.
 */

#ifndef _v1_volume_mount_H_
#define _v1_volume_mount_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_volume_mount_t v1_volume_mount_t;




typedef struct v1_volume_mount_t {
    char *mount_path; // string
    char *mount_propagation; // string
    char *name; // string
    int read_only; //boolean
    char *sub_path; // string
    char *sub_path_expr; // string

} v1_volume_mount_t;

v1_volume_mount_t *v1_volume_mount_create(
    char *mount_path,
    char *mount_propagation,
    char *name,
    int read_only,
    char *sub_path,
    char *sub_path_expr
);

void v1_volume_mount_free(v1_volume_mount_t *v1_volume_mount);

v1_volume_mount_t *v1_volume_mount_parseFromJSON(cJSON *v1_volume_mountJSON);

cJSON *v1_volume_mount_convertToJSON(v1_volume_mount_t *v1_volume_mount);

#endif /* _v1_volume_mount_H_ */

