/*
 * v1_rbd_persistent_volume_source.h
 *
 * Represents a Rados Block Device mount that lasts the lifetime of a pod. RBD volumes support ownership management and SELinux relabeling.
 */

#ifndef _v1_rbd_persistent_volume_source_H_
#define _v1_rbd_persistent_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_rbd_persistent_volume_source_t v1_rbd_persistent_volume_source_t;

#include "v1_secret_reference.h"



typedef struct v1_rbd_persistent_volume_source_t {
    char *fs_type; // string
    char *image; // string
    char *keyring; // string
    list_t *monitors; //primitive container
    char *pool; // string
    int read_only; //boolean
    struct v1_secret_reference_t *secret_ref; //model
    char *user; // string

} v1_rbd_persistent_volume_source_t;

v1_rbd_persistent_volume_source_t *v1_rbd_persistent_volume_source_create(
    char *fs_type,
    char *image,
    char *keyring,
    list_t *monitors,
    char *pool,
    int read_only,
    v1_secret_reference_t *secret_ref,
    char *user
);

void v1_rbd_persistent_volume_source_free(v1_rbd_persistent_volume_source_t *v1_rbd_persistent_volume_source);

v1_rbd_persistent_volume_source_t *v1_rbd_persistent_volume_source_parseFromJSON(cJSON *v1_rbd_persistent_volume_sourceJSON);

cJSON *v1_rbd_persistent_volume_source_convertToJSON(v1_rbd_persistent_volume_source_t *v1_rbd_persistent_volume_source);

#endif /* _v1_rbd_persistent_volume_source_H_ */

