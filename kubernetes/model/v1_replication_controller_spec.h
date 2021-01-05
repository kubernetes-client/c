/*
 * v1_replication_controller_spec.h
 *
 * ReplicationControllerSpec is the specification of a replication controller.
 */

#ifndef _v1_replication_controller_spec_H_
#define _v1_replication_controller_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_replication_controller_spec_t v1_replication_controller_spec_t;

#include "v1_pod_template_spec.h"



typedef struct v1_replication_controller_spec_t {
    int min_ready_seconds; //numeric
    int replicas; //numeric
    list_t* selector; //map
    struct v1_pod_template_spec_t *_template; //model

} v1_replication_controller_spec_t;

v1_replication_controller_spec_t *v1_replication_controller_spec_create(
    int min_ready_seconds,
    int replicas,
    list_t* selector,
    v1_pod_template_spec_t *_template
);

void v1_replication_controller_spec_free(v1_replication_controller_spec_t *v1_replication_controller_spec);

v1_replication_controller_spec_t *v1_replication_controller_spec_parseFromJSON(cJSON *v1_replication_controller_specJSON);

cJSON *v1_replication_controller_spec_convertToJSON(v1_replication_controller_spec_t *v1_replication_controller_spec);

#endif /* _v1_replication_controller_spec_H_ */

