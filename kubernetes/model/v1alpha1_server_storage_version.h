/*
 * v1alpha1_server_storage_version.h
 *
 * An API server instance reports the version it can decode and the version it encodes objects to when persisting objects in the backend.
 */

#ifndef _v1alpha1_server_storage_version_H_
#define _v1alpha1_server_storage_version_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_server_storage_version_t v1alpha1_server_storage_version_t;




typedef struct v1alpha1_server_storage_version_t {
    char *api_server_id; // string
    list_t *decodable_versions; //primitive container
    char *encoding_version; // string
    list_t *served_versions; //primitive container

} v1alpha1_server_storage_version_t;

v1alpha1_server_storage_version_t *v1alpha1_server_storage_version_create(
    char *api_server_id,
    list_t *decodable_versions,
    char *encoding_version,
    list_t *served_versions
);

void v1alpha1_server_storage_version_free(v1alpha1_server_storage_version_t *v1alpha1_server_storage_version);

v1alpha1_server_storage_version_t *v1alpha1_server_storage_version_parseFromJSON(cJSON *v1alpha1_server_storage_versionJSON);

cJSON *v1alpha1_server_storage_version_convertToJSON(v1alpha1_server_storage_version_t *v1alpha1_server_storage_version);

#endif /* _v1alpha1_server_storage_version_H_ */

