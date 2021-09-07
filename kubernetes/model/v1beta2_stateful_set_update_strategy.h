/*
 * v1beta2_stateful_set_update_strategy.h
 *
 * StatefulSetUpdateStrategy indicates the strategy that the StatefulSet controller will use to perform updates. It includes any additional parameters necessary to perform the update for the indicated strategy.
 */

#ifndef _v1beta2_stateful_set_update_strategy_H_
#define _v1beta2_stateful_set_update_strategy_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta2_stateful_set_update_strategy_t v1beta2_stateful_set_update_strategy_t;

#include "v1beta2_rolling_update_stateful_set_strategy.h"



typedef struct v1beta2_stateful_set_update_strategy_t {
    struct v1beta2_rolling_update_stateful_set_strategy_t *rolling_update; //model
    char *type; // string

} v1beta2_stateful_set_update_strategy_t;

v1beta2_stateful_set_update_strategy_t *v1beta2_stateful_set_update_strategy_create(
    v1beta2_rolling_update_stateful_set_strategy_t *rolling_update,
    char *type
);

void v1beta2_stateful_set_update_strategy_free(v1beta2_stateful_set_update_strategy_t *v1beta2_stateful_set_update_strategy);

v1beta2_stateful_set_update_strategy_t *v1beta2_stateful_set_update_strategy_parseFromJSON(cJSON *v1beta2_stateful_set_update_strategyJSON);

cJSON *v1beta2_stateful_set_update_strategy_convertToJSON(v1beta2_stateful_set_update_strategy_t *v1beta2_stateful_set_update_strategy);

#endif /* _v1beta2_stateful_set_update_strategy_H_ */

