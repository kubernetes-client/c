/*
 * v1alpha1_storage_version_status.h
 *
 * API server instances report the versions they can decode and the version they encode objects to when persisting objects in the backend.
 */

#ifndef _v1alpha1_storage_version_status_H_
#define _v1alpha1_storage_version_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_storage_version_status_t v1alpha1_storage_version_status_t;

#include "v1alpha1_server_storage_version.h"
#include "v1alpha1_storage_version_condition.h"



typedef struct v1alpha1_storage_version_status_t {
    char *common_encoding_version; // string
    list_t *conditions; //nonprimitive container
    list_t *storage_versions; //nonprimitive container

} v1alpha1_storage_version_status_t;

v1alpha1_storage_version_status_t *v1alpha1_storage_version_status_create(
    char *common_encoding_version,
    list_t *conditions,
    list_t *storage_versions
);

void v1alpha1_storage_version_status_free(v1alpha1_storage_version_status_t *v1alpha1_storage_version_status);

v1alpha1_storage_version_status_t *v1alpha1_storage_version_status_parseFromJSON(cJSON *v1alpha1_storage_version_statusJSON);

cJSON *v1alpha1_storage_version_status_convertToJSON(v1alpha1_storage_version_status_t *v1alpha1_storage_version_status);

#endif /* _v1alpha1_storage_version_status_H_ */

