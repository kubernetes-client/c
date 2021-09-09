/*
 * apps_v1beta1_deployment_strategy.h
 *
 * DeploymentStrategy describes how to replace existing pods with new ones.
 */

#ifndef _apps_v1beta1_deployment_strategy_H_
#define _apps_v1beta1_deployment_strategy_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct apps_v1beta1_deployment_strategy_t apps_v1beta1_deployment_strategy_t;

#include "apps_v1beta1_rolling_update_deployment.h"



typedef struct apps_v1beta1_deployment_strategy_t {
    struct apps_v1beta1_rolling_update_deployment_t *rolling_update; //model
    char *type; // string

} apps_v1beta1_deployment_strategy_t;

apps_v1beta1_deployment_strategy_t *apps_v1beta1_deployment_strategy_create(
    apps_v1beta1_rolling_update_deployment_t *rolling_update,
    char *type
);

void apps_v1beta1_deployment_strategy_free(apps_v1beta1_deployment_strategy_t *apps_v1beta1_deployment_strategy);

apps_v1beta1_deployment_strategy_t *apps_v1beta1_deployment_strategy_parseFromJSON(cJSON *apps_v1beta1_deployment_strategyJSON);

cJSON *apps_v1beta1_deployment_strategy_convertToJSON(apps_v1beta1_deployment_strategy_t *apps_v1beta1_deployment_strategy);

#endif /* _apps_v1beta1_deployment_strategy_H_ */

