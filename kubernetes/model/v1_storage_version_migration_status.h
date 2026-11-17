/*
 * v1_storage_version_migration_status.h
 *
 * Status of the storage version migration.
 */

#ifndef _v1_storage_version_migration_status_H_
#define _v1_storage_version_migration_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_storage_version_migration_status_t v1_storage_version_migration_status_t;

#include "v1_condition.h"



typedef struct v1_storage_version_migration_status_t {
    list_t *conditions; //nonprimitive container
    char *resource_version; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_storage_version_migration_status_t;

__attribute__((deprecated)) v1_storage_version_migration_status_t *v1_storage_version_migration_status_create(
    list_t *conditions,
    char *resource_version
);

void v1_storage_version_migration_status_free(v1_storage_version_migration_status_t *v1_storage_version_migration_status);

v1_storage_version_migration_status_t *v1_storage_version_migration_status_parseFromJSON(cJSON *v1_storage_version_migration_statusJSON);

cJSON *v1_storage_version_migration_status_convertToJSON(v1_storage_version_migration_status_t *v1_storage_version_migration_status);

#endif /* _v1_storage_version_migration_status_H_ */

