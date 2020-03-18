/*
 * v1_persistent_volume_status.h
 *
 * PersistentVolumeStatus is the current status of a persistent volume.
 */

#ifndef _v1_persistent_volume_status_H_
#define _v1_persistent_volume_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_persistent_volume_status_t {
    char *message; // string
    char *phase; // string
    char *reason; // string

} v1_persistent_volume_status_t;

v1_persistent_volume_status_t *v1_persistent_volume_status_create(
    char *message,
    char *phase,
    char *reason
);

void v1_persistent_volume_status_free(v1_persistent_volume_status_t *v1_persistent_volume_status);

v1_persistent_volume_status_t *v1_persistent_volume_status_parseFromJSON(cJSON *v1_persistent_volume_statusJSON);

cJSON *v1_persistent_volume_status_convertToJSON(v1_persistent_volume_status_t *v1_persistent_volume_status);

#endif /* _v1_persistent_volume_status_H_ */

