/*
 * v1_rolling_update_daemon_set.h
 *
 * Spec to control the desired behavior of daemon set rolling update.
 */

#ifndef _v1_rolling_update_daemon_set_H_
#define _v1_rolling_update_daemon_set_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_rolling_update_daemon_set_t v1_rolling_update_daemon_set_t;

#include "int_or_string.h"



typedef struct v1_rolling_update_daemon_set_t {
    int_or_string_t *max_surge; // custom
    int_or_string_t *max_unavailable; // custom

} v1_rolling_update_daemon_set_t;

v1_rolling_update_daemon_set_t *v1_rolling_update_daemon_set_create(
    int_or_string_t *max_surge,
    int_or_string_t *max_unavailable
);

void v1_rolling_update_daemon_set_free(v1_rolling_update_daemon_set_t *v1_rolling_update_daemon_set);

v1_rolling_update_daemon_set_t *v1_rolling_update_daemon_set_parseFromJSON(cJSON *v1_rolling_update_daemon_setJSON);

cJSON *v1_rolling_update_daemon_set_convertToJSON(v1_rolling_update_daemon_set_t *v1_rolling_update_daemon_set);

#endif /* _v1_rolling_update_daemon_set_H_ */

