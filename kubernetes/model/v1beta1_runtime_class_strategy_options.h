/*
 * v1beta1_runtime_class_strategy_options.h
 *
 * RuntimeClassStrategyOptions define the strategy that will dictate the allowable RuntimeClasses for a pod.
 */

#ifndef _v1beta1_runtime_class_strategy_options_H_
#define _v1beta1_runtime_class_strategy_options_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_runtime_class_strategy_options_t v1beta1_runtime_class_strategy_options_t;




typedef struct v1beta1_runtime_class_strategy_options_t {
    list_t *allowed_runtime_class_names; //primitive container
    char *default_runtime_class_name; // string

} v1beta1_runtime_class_strategy_options_t;

v1beta1_runtime_class_strategy_options_t *v1beta1_runtime_class_strategy_options_create(
    list_t *allowed_runtime_class_names,
    char *default_runtime_class_name
);

void v1beta1_runtime_class_strategy_options_free(v1beta1_runtime_class_strategy_options_t *v1beta1_runtime_class_strategy_options);

v1beta1_runtime_class_strategy_options_t *v1beta1_runtime_class_strategy_options_parseFromJSON(cJSON *v1beta1_runtime_class_strategy_optionsJSON);

cJSON *v1beta1_runtime_class_strategy_options_convertToJSON(v1beta1_runtime_class_strategy_options_t *v1beta1_runtime_class_strategy_options);

#endif /* _v1beta1_runtime_class_strategy_options_H_ */

