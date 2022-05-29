/*
 * v1_deployment_strategy.h
 *
 * DeploymentStrategy describes how to replace existing pods with new ones.
 */

#ifndef _v1_deployment_strategy_H_
#define _v1_deployment_strategy_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_deployment_strategy_t v1_deployment_strategy_t;

#include "v1_rolling_update_deployment.h"



typedef struct v1_deployment_strategy_t {
    struct v1_rolling_update_deployment_t *rolling_update; //model
    char *type; // string

} v1_deployment_strategy_t;

v1_deployment_strategy_t *v1_deployment_strategy_create(
    v1_rolling_update_deployment_t *rolling_update,
    char *type
);

void v1_deployment_strategy_free(v1_deployment_strategy_t *v1_deployment_strategy);

v1_deployment_strategy_t *v1_deployment_strategy_parseFromJSON(cJSON *v1_deployment_strategyJSON);

cJSON *v1_deployment_strategy_convertToJSON(v1_deployment_strategy_t *v1_deployment_strategy);

#endif /* _v1_deployment_strategy_H_ */

