/*
 * v1beta1_se_linux_strategy_options.h
 *
 * SELinuxStrategyOptions defines the strategy type and any options used to create the strategy.
 */

#ifndef _v1beta1_se_linux_strategy_options_H_
#define _v1beta1_se_linux_strategy_options_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_se_linux_strategy_options_t v1beta1_se_linux_strategy_options_t;

#include "v1_se_linux_options.h"



typedef struct v1beta1_se_linux_strategy_options_t {
    char *rule; // string
    struct v1_se_linux_options_t *se_linux_options; //model

} v1beta1_se_linux_strategy_options_t;

v1beta1_se_linux_strategy_options_t *v1beta1_se_linux_strategy_options_create(
    char *rule,
    v1_se_linux_options_t *se_linux_options
);

void v1beta1_se_linux_strategy_options_free(v1beta1_se_linux_strategy_options_t *v1beta1_se_linux_strategy_options);

v1beta1_se_linux_strategy_options_t *v1beta1_se_linux_strategy_options_parseFromJSON(cJSON *v1beta1_se_linux_strategy_optionsJSON);

cJSON *v1beta1_se_linux_strategy_options_convertToJSON(v1beta1_se_linux_strategy_options_t *v1beta1_se_linux_strategy_options);

#endif /* _v1beta1_se_linux_strategy_options_H_ */

