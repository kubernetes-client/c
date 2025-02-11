/*
 * v1_priority_level_configuration_spec.h
 *
 * PriorityLevelConfigurationSpec specifies the configuration of a priority level.
 */

#ifndef _v1_priority_level_configuration_spec_H_
#define _v1_priority_level_configuration_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_priority_level_configuration_spec_t v1_priority_level_configuration_spec_t;

#include "v1_exempt_priority_level_configuration.h"
#include "v1_limited_priority_level_configuration.h"



typedef struct v1_priority_level_configuration_spec_t {
    struct v1_exempt_priority_level_configuration_t *exempt; //model
    struct v1_limited_priority_level_configuration_t *limited; //model
    char *type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_priority_level_configuration_spec_t;

__attribute__((deprecated)) v1_priority_level_configuration_spec_t *v1_priority_level_configuration_spec_create(
    v1_exempt_priority_level_configuration_t *exempt,
    v1_limited_priority_level_configuration_t *limited,
    char *type
);

void v1_priority_level_configuration_spec_free(v1_priority_level_configuration_spec_t *v1_priority_level_configuration_spec);

v1_priority_level_configuration_spec_t *v1_priority_level_configuration_spec_parseFromJSON(cJSON *v1_priority_level_configuration_specJSON);

cJSON *v1_priority_level_configuration_spec_convertToJSON(v1_priority_level_configuration_spec_t *v1_priority_level_configuration_spec);

#endif /* _v1_priority_level_configuration_spec_H_ */

