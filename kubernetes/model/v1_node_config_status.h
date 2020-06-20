/*
 * v1_node_config_status.h
 *
 * NodeConfigStatus describes the status of the config assigned by Node.Spec.ConfigSource.
 */

#ifndef _v1_node_config_status_H_
#define _v1_node_config_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_node_config_status_t v1_node_config_status_t;

#include "v1_node_config_source.h"



typedef struct v1_node_config_status_t {
    struct v1_node_config_source_t *active; //model
    struct v1_node_config_source_t *assigned; //model
    char *error; // string
    struct v1_node_config_source_t *last_known_good; //model

} v1_node_config_status_t;

v1_node_config_status_t *v1_node_config_status_create(
    v1_node_config_source_t *active,
    v1_node_config_source_t *assigned,
    char *error,
    v1_node_config_source_t *last_known_good
);

void v1_node_config_status_free(v1_node_config_status_t *v1_node_config_status);

v1_node_config_status_t *v1_node_config_status_parseFromJSON(cJSON *v1_node_config_statusJSON);

cJSON *v1_node_config_status_convertToJSON(v1_node_config_status_t *v1_node_config_status);

#endif /* _v1_node_config_status_H_ */

