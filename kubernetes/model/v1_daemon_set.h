/*
 * v1_daemon_set.h
 *
 * DaemonSet represents the configuration of a daemon set.
 */

#ifndef _v1_daemon_set_H_
#define _v1_daemon_set_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_daemon_set_t v1_daemon_set_t;

#include "v1_daemon_set_spec.h"
#include "v1_daemon_set_status.h"
#include "v1_object_meta.h"



typedef struct v1_daemon_set_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1_daemon_set_spec_t *spec; //model
    struct v1_daemon_set_status_t *status; //model

} v1_daemon_set_t;

v1_daemon_set_t *v1_daemon_set_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_daemon_set_spec_t *spec,
    v1_daemon_set_status_t *status
);

void v1_daemon_set_free(v1_daemon_set_t *v1_daemon_set);

v1_daemon_set_t *v1_daemon_set_parseFromJSON(cJSON *v1_daemon_setJSON);

cJSON *v1_daemon_set_convertToJSON(v1_daemon_set_t *v1_daemon_set);

#endif /* _v1_daemon_set_H_ */

