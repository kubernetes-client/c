/*
 * extensions_v1beta1_rollback_config.h
 *
 * DEPRECATED.
 */

#ifndef _extensions_v1beta1_rollback_config_H_
#define _extensions_v1beta1_rollback_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct extensions_v1beta1_rollback_config_t {
    long revision; //numeric

} extensions_v1beta1_rollback_config_t;

extensions_v1beta1_rollback_config_t *extensions_v1beta1_rollback_config_create(
    long revision
);

void extensions_v1beta1_rollback_config_free(extensions_v1beta1_rollback_config_t *extensions_v1beta1_rollback_config);

extensions_v1beta1_rollback_config_t *extensions_v1beta1_rollback_config_parseFromJSON(cJSON *extensions_v1beta1_rollback_configJSON);

cJSON *extensions_v1beta1_rollback_config_convertToJSON(extensions_v1beta1_rollback_config_t *extensions_v1beta1_rollback_config);

#endif /* _extensions_v1beta1_rollback_config_H_ */

