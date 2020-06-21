/*
 * v1_replication_controller.h
 *
 * ReplicationController represents the configuration of a replication controller.
 */

#ifndef _v1_replication_controller_H_
#define _v1_replication_controller_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_replication_controller_t v1_replication_controller_t;

#include "v1_object_meta.h"
#include "v1_replication_controller_spec.h"
#include "v1_replication_controller_status.h"



typedef struct v1_replication_controller_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1_replication_controller_spec_t *spec; //model
    struct v1_replication_controller_status_t *status; //model

} v1_replication_controller_t;

v1_replication_controller_t *v1_replication_controller_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_replication_controller_spec_t *spec,
    v1_replication_controller_status_t *status
);

void v1_replication_controller_free(v1_replication_controller_t *v1_replication_controller);

v1_replication_controller_t *v1_replication_controller_parseFromJSON(cJSON *v1_replication_controllerJSON);

cJSON *v1_replication_controller_convertToJSON(v1_replication_controller_t *v1_replication_controller);

#endif /* _v1_replication_controller_H_ */

