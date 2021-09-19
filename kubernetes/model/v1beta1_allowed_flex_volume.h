/*
 * v1beta1_allowed_flex_volume.h
 *
 * AllowedFlexVolume represents a single Flexvolume that is allowed to be used.
 */

#ifndef _v1beta1_allowed_flex_volume_H_
#define _v1beta1_allowed_flex_volume_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_allowed_flex_volume_t v1beta1_allowed_flex_volume_t;




typedef struct v1beta1_allowed_flex_volume_t {
    char *driver; // string

} v1beta1_allowed_flex_volume_t;

v1beta1_allowed_flex_volume_t *v1beta1_allowed_flex_volume_create(
    char *driver
);

void v1beta1_allowed_flex_volume_free(v1beta1_allowed_flex_volume_t *v1beta1_allowed_flex_volume);

v1beta1_allowed_flex_volume_t *v1beta1_allowed_flex_volume_parseFromJSON(cJSON *v1beta1_allowed_flex_volumeJSON);

cJSON *v1beta1_allowed_flex_volume_convertToJSON(v1beta1_allowed_flex_volume_t *v1beta1_allowed_flex_volume);

#endif /* _v1beta1_allowed_flex_volume_H_ */

