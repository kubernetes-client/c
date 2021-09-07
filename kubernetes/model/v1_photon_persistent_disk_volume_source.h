/*
 * v1_photon_persistent_disk_volume_source.h
 *
 * Represents a Photon Controller persistent disk resource.
 */

#ifndef _v1_photon_persistent_disk_volume_source_H_
#define _v1_photon_persistent_disk_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_photon_persistent_disk_volume_source_t v1_photon_persistent_disk_volume_source_t;




typedef struct v1_photon_persistent_disk_volume_source_t {
    char *fs_type; // string
    char *pd_id; // string

} v1_photon_persistent_disk_volume_source_t;

v1_photon_persistent_disk_volume_source_t *v1_photon_persistent_disk_volume_source_create(
    char *fs_type,
    char *pd_id
);

void v1_photon_persistent_disk_volume_source_free(v1_photon_persistent_disk_volume_source_t *v1_photon_persistent_disk_volume_source);

v1_photon_persistent_disk_volume_source_t *v1_photon_persistent_disk_volume_source_parseFromJSON(cJSON *v1_photon_persistent_disk_volume_sourceJSON);

cJSON *v1_photon_persistent_disk_volume_source_convertToJSON(v1_photon_persistent_disk_volume_source_t *v1_photon_persistent_disk_volume_source);

#endif /* _v1_photon_persistent_disk_volume_source_H_ */

