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
#include "../include/binary.h"

typedef struct v1_persistent_volume_status_t v1_persistent_volume_status_t;




typedef struct v1_persistent_volume_status_t {
    char *last_phase_transition_time; //date time
    char *message; // string
    char *phase; // string
    char *reason; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_persistent_volume_status_t;

__attribute__((deprecated)) v1_persistent_volume_status_t *v1_persistent_volume_status_create(
    char *last_phase_transition_time,
    char *message,
    char *phase,
    char *reason
);

void v1_persistent_volume_status_free(v1_persistent_volume_status_t *v1_persistent_volume_status);

v1_persistent_volume_status_t *v1_persistent_volume_status_parseFromJSON(cJSON *v1_persistent_volume_statusJSON);

cJSON *v1_persistent_volume_status_convertToJSON(v1_persistent_volume_status_t *v1_persistent_volume_status);

#endif /* _v1_persistent_volume_status_H_ */

