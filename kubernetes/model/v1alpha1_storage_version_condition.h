/*
 * v1alpha1_storage_version_condition.h
 *
 * Describes the state of the storageVersion at a certain point.
 */

#ifndef _v1alpha1_storage_version_condition_H_
#define _v1alpha1_storage_version_condition_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_storage_version_condition_t v1alpha1_storage_version_condition_t;




typedef struct v1alpha1_storage_version_condition_t {
    char *last_transition_time; //date time
    char *message; // string
    long observed_generation; //numeric
    char *reason; // string
    char *status; // string
    char *type; // string

} v1alpha1_storage_version_condition_t;

v1alpha1_storage_version_condition_t *v1alpha1_storage_version_condition_create(
    char *last_transition_time,
    char *message,
    long observed_generation,
    char *reason,
    char *status,
    char *type
);

void v1alpha1_storage_version_condition_free(v1alpha1_storage_version_condition_t *v1alpha1_storage_version_condition);

v1alpha1_storage_version_condition_t *v1alpha1_storage_version_condition_parseFromJSON(cJSON *v1alpha1_storage_version_conditionJSON);

cJSON *v1alpha1_storage_version_condition_convertToJSON(v1alpha1_storage_version_condition_t *v1alpha1_storage_version_condition);

#endif /* _v1alpha1_storage_version_condition_H_ */

