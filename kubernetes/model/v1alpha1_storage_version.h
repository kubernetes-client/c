/*
 * v1alpha1_storage_version.h
 *
 * Storage version of a specific resource.
 */

#ifndef _v1alpha1_storage_version_H_
#define _v1alpha1_storage_version_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_storage_version_t v1alpha1_storage_version_t;

#include "object.h"
#include "v1_object_meta.h"
#include "v1alpha1_storage_version_status.h"



typedef struct v1alpha1_storage_version_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    object_t *spec; //object
    struct v1alpha1_storage_version_status_t *status; //model

} v1alpha1_storage_version_t;

v1alpha1_storage_version_t *v1alpha1_storage_version_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    object_t *spec,
    v1alpha1_storage_version_status_t *status
);

void v1alpha1_storage_version_free(v1alpha1_storage_version_t *v1alpha1_storage_version);

v1alpha1_storage_version_t *v1alpha1_storage_version_parseFromJSON(cJSON *v1alpha1_storage_versionJSON);

cJSON *v1alpha1_storage_version_convertToJSON(v1alpha1_storage_version_t *v1alpha1_storage_version);

#endif /* _v1alpha1_storage_version_H_ */

