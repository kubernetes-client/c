/*
 * v1alpha1_priority_level_configuration_spec.h
 *
 * PriorityLevelConfigurationSpec specifies the configuration of a priority level.
 */

#ifndef _v1alpha1_priority_level_configuration_spec_H_
#define _v1alpha1_priority_level_configuration_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_priority_level_configuration_spec_t v1alpha1_priority_level_configuration_spec_t;

#include "v1alpha1_limited_priority_level_configuration.h"



typedef struct v1alpha1_priority_level_configuration_spec_t {
    struct v1alpha1_limited_priority_level_configuration_t *limited; //model
    char *type; // string

} v1alpha1_priority_level_configuration_spec_t;

v1alpha1_priority_level_configuration_spec_t *v1alpha1_priority_level_configuration_spec_create(
    v1alpha1_limited_priority_level_configuration_t *limited,
    char *type
);

void v1alpha1_priority_level_configuration_spec_free(v1alpha1_priority_level_configuration_spec_t *v1alpha1_priority_level_configuration_spec);

v1alpha1_priority_level_configuration_spec_t *v1alpha1_priority_level_configuration_spec_parseFromJSON(cJSON *v1alpha1_priority_level_configuration_specJSON);

cJSON *v1alpha1_priority_level_configuration_spec_convertToJSON(v1alpha1_priority_level_configuration_spec_t *v1alpha1_priority_level_configuration_spec);

#endif /* _v1alpha1_priority_level_configuration_spec_H_ */

