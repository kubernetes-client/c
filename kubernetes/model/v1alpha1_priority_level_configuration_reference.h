/*
 * v1alpha1_priority_level_configuration_reference.h
 *
 * PriorityLevelConfigurationReference contains information that points to the \&quot;request-priority\&quot; being used.
 */

#ifndef _v1alpha1_priority_level_configuration_reference_H_
#define _v1alpha1_priority_level_configuration_reference_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_priority_level_configuration_reference_t v1alpha1_priority_level_configuration_reference_t;




typedef struct v1alpha1_priority_level_configuration_reference_t {
    char *name; // string

} v1alpha1_priority_level_configuration_reference_t;

v1alpha1_priority_level_configuration_reference_t *v1alpha1_priority_level_configuration_reference_create(
    char *name
);

void v1alpha1_priority_level_configuration_reference_free(v1alpha1_priority_level_configuration_reference_t *v1alpha1_priority_level_configuration_reference);

v1alpha1_priority_level_configuration_reference_t *v1alpha1_priority_level_configuration_reference_parseFromJSON(cJSON *v1alpha1_priority_level_configuration_referenceJSON);

cJSON *v1alpha1_priority_level_configuration_reference_convertToJSON(v1alpha1_priority_level_configuration_reference_t *v1alpha1_priority_level_configuration_reference);

#endif /* _v1alpha1_priority_level_configuration_reference_H_ */

