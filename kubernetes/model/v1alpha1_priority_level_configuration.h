/*
 * v1alpha1_priority_level_configuration.h
 *
 * PriorityLevelConfiguration represents the configuration of a priority level.
 */

#ifndef _v1alpha1_priority_level_configuration_H_
#define _v1alpha1_priority_level_configuration_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_priority_level_configuration_t v1alpha1_priority_level_configuration_t;

#include "v1_object_meta.h"
#include "v1alpha1_priority_level_configuration_spec.h"
#include "v1alpha1_priority_level_configuration_status.h"



typedef struct v1alpha1_priority_level_configuration_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1alpha1_priority_level_configuration_spec_t *spec; //model
    struct v1alpha1_priority_level_configuration_status_t *status; //model

} v1alpha1_priority_level_configuration_t;

v1alpha1_priority_level_configuration_t *v1alpha1_priority_level_configuration_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha1_priority_level_configuration_spec_t *spec,
    v1alpha1_priority_level_configuration_status_t *status
);

void v1alpha1_priority_level_configuration_free(v1alpha1_priority_level_configuration_t *v1alpha1_priority_level_configuration);

v1alpha1_priority_level_configuration_t *v1alpha1_priority_level_configuration_parseFromJSON(cJSON *v1alpha1_priority_level_configurationJSON);

cJSON *v1alpha1_priority_level_configuration_convertToJSON(v1alpha1_priority_level_configuration_t *v1alpha1_priority_level_configuration);

#endif /* _v1alpha1_priority_level_configuration_H_ */

