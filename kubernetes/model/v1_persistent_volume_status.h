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


// Enum PHASE for v1_persistent_volume_status

typedef enum  { kubernetes_v1_persistent_volume_status_PHASE_NULL = 0, kubernetes_v1_persistent_volume_status_PHASE_Available, kubernetes_v1_persistent_volume_status_PHASE_Bound, kubernetes_v1_persistent_volume_status_PHASE_Failed, kubernetes_v1_persistent_volume_status_PHASE_Pending, kubernetes_v1_persistent_volume_status_PHASE_Released } kubernetes_v1_persistent_volume_status_PHASE_e;

char* v1_persistent_volume_status_phase_ToString(kubernetes_v1_persistent_volume_status_PHASE_e phase);

kubernetes_v1_persistent_volume_status_PHASE_e v1_persistent_volume_status_phase_FromString(char* phase);



typedef struct v1_persistent_volume_status_t {
    char *message; // string
    kubernetes_v1_persistent_volume_status_PHASE_e phase; //enum
    char *reason; // string

} v1_persistent_volume_status_t;

v1_persistent_volume_status_t *v1_persistent_volume_status_create(
    char *message,
    kubernetes_v1_persistent_volume_status_PHASE_e phase,
    char *reason
);

void v1_persistent_volume_status_free(v1_persistent_volume_status_t *v1_persistent_volume_status);

v1_persistent_volume_status_t *v1_persistent_volume_status_parseFromJSON(cJSON *v1_persistent_volume_statusJSON);

cJSON *v1_persistent_volume_status_convertToJSON(v1_persistent_volume_status_t *v1_persistent_volume_status);

#endif /* _v1_persistent_volume_status_H_ */

