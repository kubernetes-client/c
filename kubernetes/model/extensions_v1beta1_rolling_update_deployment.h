/*
 * extensions_v1beta1_rolling_update_deployment.h
 *
 * Spec to control the desired behavior of rolling update.
 */

#ifndef _extensions_v1beta1_rolling_update_deployment_H_
#define _extensions_v1beta1_rolling_update_deployment_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct extensions_v1beta1_rolling_update_deployment_t extensions_v1beta1_rolling_update_deployment_t;

#include "object.h"



typedef struct extensions_v1beta1_rolling_update_deployment_t {
    object_t *max_surge; //object
    object_t *max_unavailable; //object

} extensions_v1beta1_rolling_update_deployment_t;

extensions_v1beta1_rolling_update_deployment_t *extensions_v1beta1_rolling_update_deployment_create(
    object_t *max_surge,
    object_t *max_unavailable
);

void extensions_v1beta1_rolling_update_deployment_free(extensions_v1beta1_rolling_update_deployment_t *extensions_v1beta1_rolling_update_deployment);

extensions_v1beta1_rolling_update_deployment_t *extensions_v1beta1_rolling_update_deployment_parseFromJSON(cJSON *extensions_v1beta1_rolling_update_deploymentJSON);

cJSON *extensions_v1beta1_rolling_update_deployment_convertToJSON(extensions_v1beta1_rolling_update_deployment_t *extensions_v1beta1_rolling_update_deployment);

#endif /* _extensions_v1beta1_rolling_update_deployment_H_ */

