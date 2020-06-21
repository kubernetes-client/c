/*
 * v1_replica_set_status.h
 *
 * ReplicaSetStatus represents the current status of a ReplicaSet.
 */

#ifndef _v1_replica_set_status_H_
#define _v1_replica_set_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_replica_set_status_t v1_replica_set_status_t;

#include "v1_replica_set_condition.h"



typedef struct v1_replica_set_status_t {
    int available_replicas; //numeric
    list_t *conditions; //nonprimitive container
    int fully_labeled_replicas; //numeric
    long observed_generation; //numeric
    int ready_replicas; //numeric
    int replicas; //numeric

} v1_replica_set_status_t;

v1_replica_set_status_t *v1_replica_set_status_create(
    int available_replicas,
    list_t *conditions,
    int fully_labeled_replicas,
    long observed_generation,
    int ready_replicas,
    int replicas
);

void v1_replica_set_status_free(v1_replica_set_status_t *v1_replica_set_status);

v1_replica_set_status_t *v1_replica_set_status_parseFromJSON(cJSON *v1_replica_set_statusJSON);

cJSON *v1_replica_set_status_convertToJSON(v1_replica_set_status_t *v1_replica_set_status);

#endif /* _v1_replica_set_status_H_ */

