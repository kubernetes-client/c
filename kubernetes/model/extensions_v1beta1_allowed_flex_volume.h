/*
 * extensions_v1beta1_allowed_flex_volume.h
 *
 * AllowedFlexVolume represents a single Flexvolume that is allowed to be used. Deprecated: use AllowedFlexVolume from policy API Group instead.
 */

#ifndef _extensions_v1beta1_allowed_flex_volume_H_
#define _extensions_v1beta1_allowed_flex_volume_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct extensions_v1beta1_allowed_flex_volume_t {
    char *driver; // string

} extensions_v1beta1_allowed_flex_volume_t;

extensions_v1beta1_allowed_flex_volume_t *extensions_v1beta1_allowed_flex_volume_create(
    char *driver
);

void extensions_v1beta1_allowed_flex_volume_free(extensions_v1beta1_allowed_flex_volume_t *extensions_v1beta1_allowed_flex_volume);

extensions_v1beta1_allowed_flex_volume_t *extensions_v1beta1_allowed_flex_volume_parseFromJSON(cJSON *extensions_v1beta1_allowed_flex_volumeJSON);

cJSON *extensions_v1beta1_allowed_flex_volume_convertToJSON(extensions_v1beta1_allowed_flex_volume_t *extensions_v1beta1_allowed_flex_volume);

#endif /* _extensions_v1beta1_allowed_flex_volume_H_ */

