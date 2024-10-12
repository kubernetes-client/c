/*
 * v1_image_volume_source.h
 *
 * ImageVolumeSource represents a image volume resource.
 */

#ifndef _v1_image_volume_source_H_
#define _v1_image_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_image_volume_source_t v1_image_volume_source_t;




typedef struct v1_image_volume_source_t {
    char *pull_policy; // string
    char *reference; // string

} v1_image_volume_source_t;

v1_image_volume_source_t *v1_image_volume_source_create(
    char *pull_policy,
    char *reference
);

void v1_image_volume_source_free(v1_image_volume_source_t *v1_image_volume_source);

v1_image_volume_source_t *v1_image_volume_source_parseFromJSON(cJSON *v1_image_volume_sourceJSON);

cJSON *v1_image_volume_source_convertToJSON(v1_image_volume_source_t *v1_image_volume_source);

#endif /* _v1_image_volume_source_H_ */

