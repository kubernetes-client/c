/*
 * v1_stateful_set.h
 *
 * StatefulSet represents a set of pods with consistent identities. Identities are defined as:  - Network: A single stable DNS and hostname.  - Storage: As many VolumeClaims as requested. The StatefulSet guarantees that a given network identity will always map to the same storage identity.
 */

#ifndef _v1_stateful_set_H_
#define _v1_stateful_set_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_stateful_set_t v1_stateful_set_t;

#include "v1_object_meta.h"
#include "v1_stateful_set_spec.h"
#include "v1_stateful_set_status.h"



typedef struct v1_stateful_set_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1_stateful_set_spec_t *spec; //model
    struct v1_stateful_set_status_t *status; //model

} v1_stateful_set_t;

v1_stateful_set_t *v1_stateful_set_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_stateful_set_spec_t *spec,
    v1_stateful_set_status_t *status
);

void v1_stateful_set_free(v1_stateful_set_t *v1_stateful_set);

v1_stateful_set_t *v1_stateful_set_parseFromJSON(cJSON *v1_stateful_setJSON);

cJSON *v1_stateful_set_convertToJSON(v1_stateful_set_t *v1_stateful_set);

#endif /* _v1_stateful_set_H_ */

