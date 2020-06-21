/*
 * v1_replication_controller_status.h
 *
 * ReplicationControllerStatus represents the current status of a replication controller.
 */

#ifndef _v1_replication_controller_status_H_
#define _v1_replication_controller_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_replication_controller_status_t v1_replication_controller_status_t;

#include "v1_replication_controller_condition.h"



typedef struct v1_replication_controller_status_t {
    int available_replicas; //numeric
    list_t *conditions; //nonprimitive container
    int fully_labeled_replicas; //numeric
    long observed_generation; //numeric
    int ready_replicas; //numeric
    int replicas; //numeric

} v1_replication_controller_status_t;

v1_replication_controller_status_t *v1_replication_controller_status_create(
    int available_replicas,
    list_t *conditions,
    int fully_labeled_replicas,
    long observed_generation,
    int ready_replicas,
    int replicas
);

void v1_replication_controller_status_free(v1_replication_controller_status_t *v1_replication_controller_status);

v1_replication_controller_status_t *v1_replication_controller_status_parseFromJSON(cJSON *v1_replication_controller_statusJSON);

cJSON *v1_replication_controller_status_convertToJSON(v1_replication_controller_status_t *v1_replication_controller_status);

#endif /* _v1_replication_controller_status_H_ */

