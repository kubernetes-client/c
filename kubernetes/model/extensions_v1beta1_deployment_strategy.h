/*
 * extensions_v1beta1_deployment_strategy.h
 *
 * DeploymentStrategy describes how to replace existing pods with new ones.
 */

#ifndef _extensions_v1beta1_deployment_strategy_H_
#define _extensions_v1beta1_deployment_strategy_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct extensions_v1beta1_deployment_strategy_t extensions_v1beta1_deployment_strategy_t;

#include "extensions_v1beta1_rolling_update_deployment.h"



typedef struct extensions_v1beta1_deployment_strategy_t {
    struct extensions_v1beta1_rolling_update_deployment_t *rolling_update; //model
    char *type; // string

} extensions_v1beta1_deployment_strategy_t;

extensions_v1beta1_deployment_strategy_t *extensions_v1beta1_deployment_strategy_create(
    extensions_v1beta1_rolling_update_deployment_t *rolling_update,
    char *type
);

void extensions_v1beta1_deployment_strategy_free(extensions_v1beta1_deployment_strategy_t *extensions_v1beta1_deployment_strategy);

extensions_v1beta1_deployment_strategy_t *extensions_v1beta1_deployment_strategy_parseFromJSON(cJSON *extensions_v1beta1_deployment_strategyJSON);

cJSON *extensions_v1beta1_deployment_strategy_convertToJSON(extensions_v1beta1_deployment_strategy_t *extensions_v1beta1_deployment_strategy);

#endif /* _extensions_v1beta1_deployment_strategy_H_ */

