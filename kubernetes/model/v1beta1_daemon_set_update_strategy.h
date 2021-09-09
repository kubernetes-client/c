/*
 * v1beta1_daemon_set_update_strategy.h
 *
 * 
 */

#ifndef _v1beta1_daemon_set_update_strategy_H_
#define _v1beta1_daemon_set_update_strategy_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_daemon_set_update_strategy_t v1beta1_daemon_set_update_strategy_t;

#include "v1beta1_rolling_update_daemon_set.h"



typedef struct v1beta1_daemon_set_update_strategy_t {
    struct v1beta1_rolling_update_daemon_set_t *rolling_update; //model
    char *type; // string

} v1beta1_daemon_set_update_strategy_t;

v1beta1_daemon_set_update_strategy_t *v1beta1_daemon_set_update_strategy_create(
    v1beta1_rolling_update_daemon_set_t *rolling_update,
    char *type
);

void v1beta1_daemon_set_update_strategy_free(v1beta1_daemon_set_update_strategy_t *v1beta1_daemon_set_update_strategy);

v1beta1_daemon_set_update_strategy_t *v1beta1_daemon_set_update_strategy_parseFromJSON(cJSON *v1beta1_daemon_set_update_strategyJSON);

cJSON *v1beta1_daemon_set_update_strategy_convertToJSON(v1beta1_daemon_set_update_strategy_t *v1beta1_daemon_set_update_strategy);

#endif /* _v1beta1_daemon_set_update_strategy_H_ */

