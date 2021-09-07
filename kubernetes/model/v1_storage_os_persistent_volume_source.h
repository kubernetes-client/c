/*
 * v1_storage_os_persistent_volume_source.h
 *
 * Represents a StorageOS persistent volume resource.
 */

#ifndef _v1_storage_os_persistent_volume_source_H_
#define _v1_storage_os_persistent_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_storage_os_persistent_volume_source_t v1_storage_os_persistent_volume_source_t;

#include "v1_object_reference.h"



typedef struct v1_storage_os_persistent_volume_source_t {
    char *fs_type; // string
    int read_only; //boolean
    struct v1_object_reference_t *secret_ref; //model
    char *volume_name; // string
    char *volume_namespace; // string

} v1_storage_os_persistent_volume_source_t;

v1_storage_os_persistent_volume_source_t *v1_storage_os_persistent_volume_source_create(
    char *fs_type,
    int read_only,
    v1_object_reference_t *secret_ref,
    char *volume_name,
    char *volume_namespace
);

void v1_storage_os_persistent_volume_source_free(v1_storage_os_persistent_volume_source_t *v1_storage_os_persistent_volume_source);

v1_storage_os_persistent_volume_source_t *v1_storage_os_persistent_volume_source_parseFromJSON(cJSON *v1_storage_os_persistent_volume_sourceJSON);

cJSON *v1_storage_os_persistent_volume_source_convertToJSON(v1_storage_os_persistent_volume_source_t *v1_storage_os_persistent_volume_source);

#endif /* _v1_storage_os_persistent_volume_source_H_ */

