/*
 * v1_image_volume_status.h
 *
 * ImageVolumeStatus represents the image-based volume status.
 */

#ifndef _v1_image_volume_status_H_
#define _v1_image_volume_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_image_volume_status_t v1_image_volume_status_t;




typedef struct v1_image_volume_status_t {
    char *image_ref; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_image_volume_status_t;

__attribute__((deprecated)) v1_image_volume_status_t *v1_image_volume_status_create(
    char *image_ref
);

void v1_image_volume_status_free(v1_image_volume_status_t *v1_image_volume_status);

v1_image_volume_status_t *v1_image_volume_status_parseFromJSON(cJSON *v1_image_volume_statusJSON);

cJSON *v1_image_volume_status_convertToJSON(v1_image_volume_status_t *v1_image_volume_status);

#endif /* _v1_image_volume_status_H_ */

