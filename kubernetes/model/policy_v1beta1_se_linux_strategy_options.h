/*
 * policy_v1beta1_se_linux_strategy_options.h
 *
 * SELinuxStrategyOptions defines the strategy type and any options used to create the strategy.
 */

#ifndef _policy_v1beta1_se_linux_strategy_options_H_
#define _policy_v1beta1_se_linux_strategy_options_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct policy_v1beta1_se_linux_strategy_options_t policy_v1beta1_se_linux_strategy_options_t;

#include "v1_se_linux_options.h"



typedef struct policy_v1beta1_se_linux_strategy_options_t {
    char *rule; // string
    struct v1_se_linux_options_t *se_linux_options; //model

} policy_v1beta1_se_linux_strategy_options_t;

policy_v1beta1_se_linux_strategy_options_t *policy_v1beta1_se_linux_strategy_options_create(
    char *rule,
    v1_se_linux_options_t *se_linux_options
);

void policy_v1beta1_se_linux_strategy_options_free(policy_v1beta1_se_linux_strategy_options_t *policy_v1beta1_se_linux_strategy_options);

policy_v1beta1_se_linux_strategy_options_t *policy_v1beta1_se_linux_strategy_options_parseFromJSON(cJSON *policy_v1beta1_se_linux_strategy_optionsJSON);

cJSON *policy_v1beta1_se_linux_strategy_options_convertToJSON(policy_v1beta1_se_linux_strategy_options_t *policy_v1beta1_se_linux_strategy_options);

#endif /* _policy_v1beta1_se_linux_strategy_options_H_ */

