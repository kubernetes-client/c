/*
 * v1beta1_run_as_group_strategy_options.h
 *
 * RunAsGroupStrategyOptions defines the strategy type and any options used to create the strategy.
 */

#ifndef _v1beta1_run_as_group_strategy_options_H_
#define _v1beta1_run_as_group_strategy_options_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_run_as_group_strategy_options_t v1beta1_run_as_group_strategy_options_t;

#include "v1beta1_id_range.h"



typedef struct v1beta1_run_as_group_strategy_options_t {
    list_t *ranges; //nonprimitive container
    char *rule; // string

} v1beta1_run_as_group_strategy_options_t;

v1beta1_run_as_group_strategy_options_t *v1beta1_run_as_group_strategy_options_create(
    list_t *ranges,
    char *rule
);

void v1beta1_run_as_group_strategy_options_free(v1beta1_run_as_group_strategy_options_t *v1beta1_run_as_group_strategy_options);

v1beta1_run_as_group_strategy_options_t *v1beta1_run_as_group_strategy_options_parseFromJSON(cJSON *v1beta1_run_as_group_strategy_optionsJSON);

cJSON *v1beta1_run_as_group_strategy_options_convertToJSON(v1beta1_run_as_group_strategy_options_t *v1beta1_run_as_group_strategy_options);

#endif /* _v1beta1_run_as_group_strategy_options_H_ */

