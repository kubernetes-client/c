/*
 * v1_daemon_set_update_strategy.h
 *
 * DaemonSetUpdateStrategy is a struct used to control the update strategy for a DaemonSet.
 */

#ifndef _v1_daemon_set_update_strategy_H_
#define _v1_daemon_set_update_strategy_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_daemon_set_update_strategy_t v1_daemon_set_update_strategy_t;

#include "v1_rolling_update_daemon_set.h"



typedef struct v1_daemon_set_update_strategy_t {
    struct v1_rolling_update_daemon_set_t *rolling_update; //model
    char *type; // string

} v1_daemon_set_update_strategy_t;

v1_daemon_set_update_strategy_t *v1_daemon_set_update_strategy_create(
    v1_rolling_update_daemon_set_t *rolling_update,
    char *type
);

void v1_daemon_set_update_strategy_free(v1_daemon_set_update_strategy_t *v1_daemon_set_update_strategy);

v1_daemon_set_update_strategy_t *v1_daemon_set_update_strategy_parseFromJSON(cJSON *v1_daemon_set_update_strategyJSON);

cJSON *v1_daemon_set_update_strategy_convertToJSON(v1_daemon_set_update_strategy_t *v1_daemon_set_update_strategy);

#endif /* _v1_daemon_set_update_strategy_H_ */

