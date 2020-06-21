/*
 * v1_attached_volume.h
 *
 * AttachedVolume describes a volume attached to a node
 */

#ifndef _v1_attached_volume_H_
#define _v1_attached_volume_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_attached_volume_t v1_attached_volume_t;




typedef struct v1_attached_volume_t {
    char *device_path; // string
    char *name; // string

} v1_attached_volume_t;

v1_attached_volume_t *v1_attached_volume_create(
    char *device_path,
    char *name
);

void v1_attached_volume_free(v1_attached_volume_t *v1_attached_volume);

v1_attached_volume_t *v1_attached_volume_parseFromJSON(cJSON *v1_attached_volumeJSON);

cJSON *v1_attached_volume_convertToJSON(v1_attached_volume_t *v1_attached_volume);

#endif /* _v1_attached_volume_H_ */

