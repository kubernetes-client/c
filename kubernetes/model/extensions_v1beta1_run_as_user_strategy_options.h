/*
 * extensions_v1beta1_run_as_user_strategy_options.h
 *
 * RunAsUserStrategyOptions defines the strategy type and any options used to create the strategy. Deprecated: use RunAsUserStrategyOptions from policy API Group instead.
 */

#ifndef _extensions_v1beta1_run_as_user_strategy_options_H_
#define _extensions_v1beta1_run_as_user_strategy_options_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct extensions_v1beta1_run_as_user_strategy_options_t extensions_v1beta1_run_as_user_strategy_options_t;

#include "extensions_v1beta1_id_range.h"



typedef struct extensions_v1beta1_run_as_user_strategy_options_t {
    list_t *ranges; //nonprimitive container
    char *rule; // string

} extensions_v1beta1_run_as_user_strategy_options_t;

extensions_v1beta1_run_as_user_strategy_options_t *extensions_v1beta1_run_as_user_strategy_options_create(
    list_t *ranges,
    char *rule
);

void extensions_v1beta1_run_as_user_strategy_options_free(extensions_v1beta1_run_as_user_strategy_options_t *extensions_v1beta1_run_as_user_strategy_options);

extensions_v1beta1_run_as_user_strategy_options_t *extensions_v1beta1_run_as_user_strategy_options_parseFromJSON(cJSON *extensions_v1beta1_run_as_user_strategy_optionsJSON);

cJSON *extensions_v1beta1_run_as_user_strategy_options_convertToJSON(extensions_v1beta1_run_as_user_strategy_options_t *extensions_v1beta1_run_as_user_strategy_options);

#endif /* _extensions_v1beta1_run_as_user_strategy_options_H_ */

