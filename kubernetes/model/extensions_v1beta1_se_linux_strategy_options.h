/*
 * extensions_v1beta1_se_linux_strategy_options.h
 *
 * SELinuxStrategyOptions defines the strategy type and any options used to create the strategy. Deprecated: use SELinuxStrategyOptions from policy API Group instead.
 */

#ifndef _extensions_v1beta1_se_linux_strategy_options_H_
#define _extensions_v1beta1_se_linux_strategy_options_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct extensions_v1beta1_se_linux_strategy_options_t extensions_v1beta1_se_linux_strategy_options_t;

#include "v1_se_linux_options.h"



typedef struct extensions_v1beta1_se_linux_strategy_options_t {
    char *rule; // string
    struct v1_se_linux_options_t *se_linux_options; //model

} extensions_v1beta1_se_linux_strategy_options_t;

extensions_v1beta1_se_linux_strategy_options_t *extensions_v1beta1_se_linux_strategy_options_create(
    char *rule,
    v1_se_linux_options_t *se_linux_options
);

void extensions_v1beta1_se_linux_strategy_options_free(extensions_v1beta1_se_linux_strategy_options_t *extensions_v1beta1_se_linux_strategy_options);

extensions_v1beta1_se_linux_strategy_options_t *extensions_v1beta1_se_linux_strategy_options_parseFromJSON(cJSON *extensions_v1beta1_se_linux_strategy_optionsJSON);

cJSON *extensions_v1beta1_se_linux_strategy_options_convertToJSON(extensions_v1beta1_se_linux_strategy_options_t *extensions_v1beta1_se_linux_strategy_options);

#endif /* _extensions_v1beta1_se_linux_strategy_options_H_ */

