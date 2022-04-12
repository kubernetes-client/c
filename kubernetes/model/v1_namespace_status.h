/*
 * v1_namespace_status.h
 *
 * NamespaceStatus is information about the current status of a Namespace.
 */

#ifndef _v1_namespace_status_H_
#define _v1_namespace_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_namespace_status_t v1_namespace_status_t;

#include "v1_namespace_condition.h"

// Enum PHASE for v1_namespace_status

typedef enum  { kubernetes_v1_namespace_status_PHASE_NULL = 0, kubernetes_v1_namespace_status_PHASE_Active, kubernetes_v1_namespace_status_PHASE_Terminating } kubernetes_v1_namespace_status_PHASE_e;

char* v1_namespace_status_phase_ToString(kubernetes_v1_namespace_status_PHASE_e phase);

kubernetes_v1_namespace_status_PHASE_e v1_namespace_status_phase_FromString(char* phase);



typedef struct v1_namespace_status_t {
    list_t *conditions; //nonprimitive container
    kubernetes_v1_namespace_status_PHASE_e phase; //enum

} v1_namespace_status_t;

v1_namespace_status_t *v1_namespace_status_create(
    list_t *conditions,
    kubernetes_v1_namespace_status_PHASE_e phase
);

void v1_namespace_status_free(v1_namespace_status_t *v1_namespace_status);

v1_namespace_status_t *v1_namespace_status_parseFromJSON(cJSON *v1_namespace_statusJSON);

cJSON *v1_namespace_status_convertToJSON(v1_namespace_status_t *v1_namespace_status);

#endif /* _v1_namespace_status_H_ */

