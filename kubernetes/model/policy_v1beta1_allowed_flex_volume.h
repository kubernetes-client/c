/*
 * policy_v1beta1_allowed_flex_volume.h
 *
 * AllowedFlexVolume represents a single Flexvolume that is allowed to be used.
 */

#ifndef _policy_v1beta1_allowed_flex_volume_H_
#define _policy_v1beta1_allowed_flex_volume_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct policy_v1beta1_allowed_flex_volume_t {
    char *driver; // string

} policy_v1beta1_allowed_flex_volume_t;

policy_v1beta1_allowed_flex_volume_t *policy_v1beta1_allowed_flex_volume_create(
    char *driver
);

void policy_v1beta1_allowed_flex_volume_free(policy_v1beta1_allowed_flex_volume_t *policy_v1beta1_allowed_flex_volume);

policy_v1beta1_allowed_flex_volume_t *policy_v1beta1_allowed_flex_volume_parseFromJSON(cJSON *policy_v1beta1_allowed_flex_volumeJSON);

cJSON *policy_v1beta1_allowed_flex_volume_convertToJSON(policy_v1beta1_allowed_flex_volume_t *policy_v1beta1_allowed_flex_volume);

#endif /* _policy_v1beta1_allowed_flex_volume_H_ */

