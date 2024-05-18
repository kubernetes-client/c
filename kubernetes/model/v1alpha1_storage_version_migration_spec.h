/*
 * v1alpha1_storage_version_migration_spec.h
 *
 * Spec of the storage version migration.
 */

#ifndef _v1alpha1_storage_version_migration_spec_H_
#define _v1alpha1_storage_version_migration_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_storage_version_migration_spec_t v1alpha1_storage_version_migration_spec_t;

#include "v1alpha1_group_version_resource.h"



typedef struct v1alpha1_storage_version_migration_spec_t {
    char *continue_token; // string
    struct v1alpha1_group_version_resource_t *resource; //model

} v1alpha1_storage_version_migration_spec_t;

v1alpha1_storage_version_migration_spec_t *v1alpha1_storage_version_migration_spec_create(
    char *continue_token,
    v1alpha1_group_version_resource_t *resource
);

void v1alpha1_storage_version_migration_spec_free(v1alpha1_storage_version_migration_spec_t *v1alpha1_storage_version_migration_spec);

v1alpha1_storage_version_migration_spec_t *v1alpha1_storage_version_migration_spec_parseFromJSON(cJSON *v1alpha1_storage_version_migration_specJSON);

cJSON *v1alpha1_storage_version_migration_spec_convertToJSON(v1alpha1_storage_version_migration_spec_t *v1alpha1_storage_version_migration_spec);

#endif /* _v1alpha1_storage_version_migration_spec_H_ */

