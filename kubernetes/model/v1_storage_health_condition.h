/*
 * v1_storage_health_condition.h
 *
 * StorageHealthCondition represents an adverse health condition reported by a CSI driver for its storage backend on a node.
 */

#ifndef _v1_storage_health_condition_H_
#define _v1_storage_health_condition_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_storage_health_condition_t v1_storage_health_condition_t;




typedef struct v1_storage_health_condition_t {
    char *access_mode; // string
    char *last_transition_time; //date time
    char *message; // string
    char *reason; // string
    char *status; // string
    char *volume_mode; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_storage_health_condition_t;

__attribute__((deprecated)) v1_storage_health_condition_t *v1_storage_health_condition_create(
    char *access_mode,
    char *last_transition_time,
    char *message,
    char *reason,
    char *status,
    char *volume_mode
);

void v1_storage_health_condition_free(v1_storage_health_condition_t *v1_storage_health_condition);

v1_storage_health_condition_t *v1_storage_health_condition_parseFromJSON(cJSON *v1_storage_health_conditionJSON);

cJSON *v1_storage_health_condition_convertToJSON(v1_storage_health_condition_t *v1_storage_health_condition);

#endif /* _v1_storage_health_condition_H_ */

