/*
 * v1_volume_mount_status.h
 *
 * VolumeMountStatus shows status of volume mounts.
 */

#ifndef _v1_volume_mount_status_H_
#define _v1_volume_mount_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_volume_mount_status_t v1_volume_mount_status_t;

#include "v1_volume_status.h"



typedef struct v1_volume_mount_status_t {
    char *mount_path; // string
    char *name; // string
    int *read_only; //boolean
    char *recursive_read_only; // string
    struct v1_volume_status_t *volume_status; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1_volume_mount_status_t;

__attribute__((deprecated)) v1_volume_mount_status_t *v1_volume_mount_status_create(
    char *mount_path,
    char *name,
    int *read_only,
    char *recursive_read_only,
    v1_volume_status_t *volume_status
);

void v1_volume_mount_status_free(v1_volume_mount_status_t *v1_volume_mount_status);

v1_volume_mount_status_t *v1_volume_mount_status_parseFromJSON(cJSON *v1_volume_mount_statusJSON);

cJSON *v1_volume_mount_status_convertToJSON(v1_volume_mount_status_t *v1_volume_mount_status);

#endif /* _v1_volume_mount_status_H_ */

