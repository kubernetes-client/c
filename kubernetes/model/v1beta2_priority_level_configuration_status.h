/*
 * v1beta2_priority_level_configuration_status.h
 *
 * PriorityLevelConfigurationStatus represents the current state of a \&quot;request-priority\&quot;.
 */

#ifndef _v1beta2_priority_level_configuration_status_H_
#define _v1beta2_priority_level_configuration_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta2_priority_level_configuration_status_t v1beta2_priority_level_configuration_status_t;

#include "v1beta2_priority_level_configuration_condition.h"



typedef struct v1beta2_priority_level_configuration_status_t {
    list_t *conditions; //nonprimitive container

} v1beta2_priority_level_configuration_status_t;

v1beta2_priority_level_configuration_status_t *v1beta2_priority_level_configuration_status_create(
    list_t *conditions
);

void v1beta2_priority_level_configuration_status_free(v1beta2_priority_level_configuration_status_t *v1beta2_priority_level_configuration_status);

v1beta2_priority_level_configuration_status_t *v1beta2_priority_level_configuration_status_parseFromJSON(cJSON *v1beta2_priority_level_configuration_statusJSON);

cJSON *v1beta2_priority_level_configuration_status_convertToJSON(v1beta2_priority_level_configuration_status_t *v1beta2_priority_level_configuration_status);

#endif /* _v1beta2_priority_level_configuration_status_H_ */

