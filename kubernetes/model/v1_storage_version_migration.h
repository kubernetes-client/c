/*
 * v1_storage_version_migration.h
 *
 * StorageVersionMigration represents a migration of stored data to the latest storage version.
 */

#ifndef _v1_storage_version_migration_H_
#define _v1_storage_version_migration_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_storage_version_migration_t v1_storage_version_migration_t;

#include "v1_object_meta.h"
#include "v1_storage_version_migration_spec.h"
#include "v1_storage_version_migration_status.h"



typedef struct v1_storage_version_migration_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1_storage_version_migration_spec_t *spec; //model
    struct v1_storage_version_migration_status_t *status; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1_storage_version_migration_t;

__attribute__((deprecated)) v1_storage_version_migration_t *v1_storage_version_migration_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_storage_version_migration_spec_t *spec,
    v1_storage_version_migration_status_t *status
);

void v1_storage_version_migration_free(v1_storage_version_migration_t *v1_storage_version_migration);

v1_storage_version_migration_t *v1_storage_version_migration_parseFromJSON(cJSON *v1_storage_version_migrationJSON);

cJSON *v1_storage_version_migration_convertToJSON(v1_storage_version_migration_t *v1_storage_version_migration);

#endif /* _v1_storage_version_migration_H_ */

