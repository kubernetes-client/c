/*
 * policy_v1beta1_runtime_class_strategy_options.h
 *
 * RuntimeClassStrategyOptions define the strategy that will dictate the allowable RuntimeClasses for a pod.
 */

#ifndef _policy_v1beta1_runtime_class_strategy_options_H_
#define _policy_v1beta1_runtime_class_strategy_options_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct policy_v1beta1_runtime_class_strategy_options_t policy_v1beta1_runtime_class_strategy_options_t;




typedef struct policy_v1beta1_runtime_class_strategy_options_t {
    list_t *allowed_runtime_class_names; //primitive container
    char *default_runtime_class_name; // string

} policy_v1beta1_runtime_class_strategy_options_t;

policy_v1beta1_runtime_class_strategy_options_t *policy_v1beta1_runtime_class_strategy_options_create(
    list_t *allowed_runtime_class_names,
    char *default_runtime_class_name
);

void policy_v1beta1_runtime_class_strategy_options_free(policy_v1beta1_runtime_class_strategy_options_t *policy_v1beta1_runtime_class_strategy_options);

policy_v1beta1_runtime_class_strategy_options_t *policy_v1beta1_runtime_class_strategy_options_parseFromJSON(cJSON *policy_v1beta1_runtime_class_strategy_optionsJSON);

cJSON *policy_v1beta1_runtime_class_strategy_options_convertToJSON(policy_v1beta1_runtime_class_strategy_options_t *policy_v1beta1_runtime_class_strategy_options);

#endif /* _policy_v1beta1_runtime_class_strategy_options_H_ */

