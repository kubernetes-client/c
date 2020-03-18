/*
 * apps_v1beta1_rollback_config.h
 *
 * DEPRECATED.
 */

#ifndef _apps_v1beta1_rollback_config_H_
#define _apps_v1beta1_rollback_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct apps_v1beta1_rollback_config_t {
    long revision; //numeric

} apps_v1beta1_rollback_config_t;

apps_v1beta1_rollback_config_t *apps_v1beta1_rollback_config_create(
    long revision
);

void apps_v1beta1_rollback_config_free(apps_v1beta1_rollback_config_t *apps_v1beta1_rollback_config);

apps_v1beta1_rollback_config_t *apps_v1beta1_rollback_config_parseFromJSON(cJSON *apps_v1beta1_rollback_configJSON);

cJSON *apps_v1beta1_rollback_config_convertToJSON(apps_v1beta1_rollback_config_t *apps_v1beta1_rollback_config);

#endif /* _apps_v1beta1_rollback_config_H_ */

