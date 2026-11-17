/*
 * v1_volume_status.h
 *
 * VolumeStatus represents the status of a mounted volume. At most one of its members must be specified.
 */

#ifndef _v1_volume_status_H_
#define _v1_volume_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_volume_status_t v1_volume_status_t;

#include "v1_image_volume_status.h"



typedef struct v1_volume_status_t {
    struct v1_image_volume_status_t *image; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1_volume_status_t;

__attribute__((deprecated)) v1_volume_status_t *v1_volume_status_create(
    v1_image_volume_status_t *image
);

void v1_volume_status_free(v1_volume_status_t *v1_volume_status);

v1_volume_status_t *v1_volume_status_parseFromJSON(cJSON *v1_volume_statusJSON);

cJSON *v1_volume_status_convertToJSON(v1_volume_status_t *v1_volume_status);

#endif /* _v1_volume_status_H_ */

