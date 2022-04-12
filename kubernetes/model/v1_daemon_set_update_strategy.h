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

// Enum TYPE for v1_daemon_set_update_strategy

typedef enum  { kubernetes_v1_daemon_set_update_strategy_TYPE_NULL = 0, kubernetes_v1_daemon_set_update_strategy_TYPE_OnDelete, kubernetes_v1_daemon_set_update_strategy_TYPE_RollingUpdate } kubernetes_v1_daemon_set_update_strategy_TYPE_e;

char* v1_daemon_set_update_strategy_type_ToString(kubernetes_v1_daemon_set_update_strategy_TYPE_e type);

kubernetes_v1_daemon_set_update_strategy_TYPE_e v1_daemon_set_update_strategy_type_FromString(char* type);



typedef struct v1_daemon_set_update_strategy_t {
    struct v1_rolling_update_daemon_set_t *rolling_update; //model
    kubernetes_v1_daemon_set_update_strategy_TYPE_e type; //enum

} v1_daemon_set_update_strategy_t;

v1_daemon_set_update_strategy_t *v1_daemon_set_update_strategy_create(
    v1_rolling_update_daemon_set_t *rolling_update,
    kubernetes_v1_daemon_set_update_strategy_TYPE_e type
);

void v1_daemon_set_update_strategy_free(v1_daemon_set_update_strategy_t *v1_daemon_set_update_strategy);

v1_daemon_set_update_strategy_t *v1_daemon_set_update_strategy_parseFromJSON(cJSON *v1_daemon_set_update_strategyJSON);

cJSON *v1_daemon_set_update_strategy_convertToJSON(v1_daemon_set_update_strategy_t *v1_daemon_set_update_strategy);

#endif /* _v1_daemon_set_update_strategy_H_ */

