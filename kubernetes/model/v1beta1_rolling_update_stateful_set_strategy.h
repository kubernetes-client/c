/*
 * v1beta1_rolling_update_stateful_set_strategy.h
 *
 * RollingUpdateStatefulSetStrategy is used to communicate parameter for RollingUpdateStatefulSetStrategyType.
 */

#ifndef _v1beta1_rolling_update_stateful_set_strategy_H_
#define _v1beta1_rolling_update_stateful_set_strategy_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1beta1_rolling_update_stateful_set_strategy_t {
    int partition; //numeric

} v1beta1_rolling_update_stateful_set_strategy_t;

v1beta1_rolling_update_stateful_set_strategy_t *v1beta1_rolling_update_stateful_set_strategy_create(
    int partition
);

void v1beta1_rolling_update_stateful_set_strategy_free(v1beta1_rolling_update_stateful_set_strategy_t *v1beta1_rolling_update_stateful_set_strategy);

v1beta1_rolling_update_stateful_set_strategy_t *v1beta1_rolling_update_stateful_set_strategy_parseFromJSON(cJSON *v1beta1_rolling_update_stateful_set_strategyJSON);

cJSON *v1beta1_rolling_update_stateful_set_strategy_convertToJSON(v1beta1_rolling_update_stateful_set_strategy_t *v1beta1_rolling_update_stateful_set_strategy);

#endif /* _v1beta1_rolling_update_stateful_set_strategy_H_ */

