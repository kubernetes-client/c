/*
 * v1_node_spec.h
 *
 * NodeSpec describes the attributes that a node is created with.
 */

#ifndef _v1_node_spec_H_
#define _v1_node_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_node_spec_t v1_node_spec_t;

#include "v1_node_config_source.h"
#include "v1_taint.h"



typedef struct v1_node_spec_t {
    struct v1_node_config_source_t *config_source; //model
    char *external_id; // string
    char *pod_cidr; // string
    list_t *pod_cidrs; //primitive container
    char *provider_id; // string
    list_t *taints; //nonprimitive container
    int unschedulable; //boolean

} v1_node_spec_t;

v1_node_spec_t *v1_node_spec_create(
    v1_node_config_source_t *config_source,
    char *external_id,
    char *pod_cidr,
    list_t *pod_cidrs,
    char *provider_id,
    list_t *taints,
    int unschedulable
);

void v1_node_spec_free(v1_node_spec_t *v1_node_spec);

v1_node_spec_t *v1_node_spec_parseFromJSON(cJSON *v1_node_specJSON);

cJSON *v1_node_spec_convertToJSON(v1_node_spec_t *v1_node_spec);

#endif /* _v1_node_spec_H_ */

