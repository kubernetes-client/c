/*
 * v1beta2_priority_level_configuration_reference.h
 *
 * PriorityLevelConfigurationReference contains information that points to the \&quot;request-priority\&quot; being used.
 */

#ifndef _v1beta2_priority_level_configuration_reference_H_
#define _v1beta2_priority_level_configuration_reference_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta2_priority_level_configuration_reference_t v1beta2_priority_level_configuration_reference_t;




typedef struct v1beta2_priority_level_configuration_reference_t {
    char *name; // string

} v1beta2_priority_level_configuration_reference_t;

v1beta2_priority_level_configuration_reference_t *v1beta2_priority_level_configuration_reference_create(
    char *name
);

void v1beta2_priority_level_configuration_reference_free(v1beta2_priority_level_configuration_reference_t *v1beta2_priority_level_configuration_reference);

v1beta2_priority_level_configuration_reference_t *v1beta2_priority_level_configuration_reference_parseFromJSON(cJSON *v1beta2_priority_level_configuration_referenceJSON);

cJSON *v1beta2_priority_level_configuration_reference_convertToJSON(v1beta2_priority_level_configuration_reference_t *v1beta2_priority_level_configuration_reference);

#endif /* _v1beta2_priority_level_configuration_reference_H_ */

