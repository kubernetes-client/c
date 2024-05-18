/*
 * v1alpha1_migration_condition.h
 *
 * Describes the state of a migration at a certain point.
 */

#ifndef _v1alpha1_migration_condition_H_
#define _v1alpha1_migration_condition_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_migration_condition_t v1alpha1_migration_condition_t;




typedef struct v1alpha1_migration_condition_t {
    char *last_update_time; //date time
    char *message; // string
    char *reason; // string
    char *status; // string
    char *type; // string

} v1alpha1_migration_condition_t;

v1alpha1_migration_condition_t *v1alpha1_migration_condition_create(
    char *last_update_time,
    char *message,
    char *reason,
    char *status,
    char *type
);

void v1alpha1_migration_condition_free(v1alpha1_migration_condition_t *v1alpha1_migration_condition);

v1alpha1_migration_condition_t *v1alpha1_migration_condition_parseFromJSON(cJSON *v1alpha1_migration_conditionJSON);

cJSON *v1alpha1_migration_condition_convertToJSON(v1alpha1_migration_condition_t *v1alpha1_migration_condition);

#endif /* _v1alpha1_migration_condition_H_ */

