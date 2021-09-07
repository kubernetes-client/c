/*
 * v1_flex_persistent_volume_source.h
 *
 * FlexPersistentVolumeSource represents a generic persistent volume resource that is provisioned/attached using an exec based plugin.
 */

#ifndef _v1_flex_persistent_volume_source_H_
#define _v1_flex_persistent_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_flex_persistent_volume_source_t v1_flex_persistent_volume_source_t;

#include "v1_secret_reference.h"



typedef struct v1_flex_persistent_volume_source_t {
    char *driver; // string
    char *fs_type; // string
    list_t* options; //map
    int read_only; //boolean
    struct v1_secret_reference_t *secret_ref; //model

} v1_flex_persistent_volume_source_t;

v1_flex_persistent_volume_source_t *v1_flex_persistent_volume_source_create(
    char *driver,
    char *fs_type,
    list_t* options,
    int read_only,
    v1_secret_reference_t *secret_ref
);

void v1_flex_persistent_volume_source_free(v1_flex_persistent_volume_source_t *v1_flex_persistent_volume_source);

v1_flex_persistent_volume_source_t *v1_flex_persistent_volume_source_parseFromJSON(cJSON *v1_flex_persistent_volume_sourceJSON);

cJSON *v1_flex_persistent_volume_source_convertToJSON(v1_flex_persistent_volume_source_t *v1_flex_persistent_volume_source);

#endif /* _v1_flex_persistent_volume_source_H_ */

