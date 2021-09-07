/*
 * v1beta2_daemon_set_status.h
 *
 * DaemonSetStatus represents the current status of a daemon set.
 */

#ifndef _v1beta2_daemon_set_status_H_
#define _v1beta2_daemon_set_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta2_daemon_set_status_t v1beta2_daemon_set_status_t;

#include "v1beta2_daemon_set_condition.h"



typedef struct v1beta2_daemon_set_status_t {
    int collision_count; //numeric
    list_t *conditions; //nonprimitive container
    int current_number_scheduled; //numeric
    int desired_number_scheduled; //numeric
    int number_available; //numeric
    int number_misscheduled; //numeric
    int number_ready; //numeric
    int number_unavailable; //numeric
    long observed_generation; //numeric
    int updated_number_scheduled; //numeric

} v1beta2_daemon_set_status_t;

v1beta2_daemon_set_status_t *v1beta2_daemon_set_status_create(
    int collision_count,
    list_t *conditions,
    int current_number_scheduled,
    int desired_number_scheduled,
    int number_available,
    int number_misscheduled,
    int number_ready,
    int number_unavailable,
    long observed_generation,
    int updated_number_scheduled
);

void v1beta2_daemon_set_status_free(v1beta2_daemon_set_status_t *v1beta2_daemon_set_status);

v1beta2_daemon_set_status_t *v1beta2_daemon_set_status_parseFromJSON(cJSON *v1beta2_daemon_set_statusJSON);

cJSON *v1beta2_daemon_set_status_convertToJSON(v1beta2_daemon_set_status_t *v1beta2_daemon_set_status);

#endif /* _v1beta2_daemon_set_status_H_ */

