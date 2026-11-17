/*
 * v1_storage_version_migration_spec.h
 *
 * Spec of the storage version migration.
 */

#ifndef _v1_storage_version_migration_spec_H_
#define _v1_storage_version_migration_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_storage_version_migration_spec_t v1_storage_version_migration_spec_t;

#include "v1_group_resource.h"



typedef struct v1_storage_version_migration_spec_t {
    struct v1_group_resource_t *resource; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1_storage_version_migration_spec_t;

__attribute__((deprecated)) v1_storage_version_migration_spec_t *v1_storage_version_migration_spec_create(
    v1_group_resource_t *resource
);

void v1_storage_version_migration_spec_free(v1_storage_version_migration_spec_t *v1_storage_version_migration_spec);

v1_storage_version_migration_spec_t *v1_storage_version_migration_spec_parseFromJSON(cJSON *v1_storage_version_migration_specJSON);

cJSON *v1_storage_version_migration_spec_convertToJSON(v1_storage_version_migration_spec_t *v1_storage_version_migration_spec);

#endif /* _v1_storage_version_migration_spec_H_ */

