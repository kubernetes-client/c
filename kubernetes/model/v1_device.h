/*
 * v1_device.h
 *
 * Device represents one individual hardware instance that can be selected based on its attributes. Besides the name, exactly one field must be set.
 */

#ifndef _v1_device_H_
#define _v1_device_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_device_t v1_device_t;

#include "v1_device_attribute.h"
#include "v1_device_capacity.h"
#include "v1_device_counter_consumption.h"
#include "v1_device_taint.h"
#include "v1_node_selector.h"



typedef struct v1_device_t {
    int all_nodes; //boolean
    int allow_multiple_allocations; //boolean
    list_t* attributes; //map
    list_t *binding_conditions; //primitive container
    list_t *binding_failure_conditions; //primitive container
    int binds_to_node; //boolean
    list_t* capacity; //map
    list_t *consumes_counters; //nonprimitive container
    char *name; // string
    char *node_name; // string
    struct v1_node_selector_t *node_selector; //model
    list_t *taints; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1_device_t;

__attribute__((deprecated)) v1_device_t *v1_device_create(
    int all_nodes,
    int allow_multiple_allocations,
    list_t* attributes,
    list_t *binding_conditions,
    list_t *binding_failure_conditions,
    int binds_to_node,
    list_t* capacity,
    list_t *consumes_counters,
    char *name,
    char *node_name,
    v1_node_selector_t *node_selector,
    list_t *taints
);

void v1_device_free(v1_device_t *v1_device);

v1_device_t *v1_device_parseFromJSON(cJSON *v1_deviceJSON);

cJSON *v1_device_convertToJSON(v1_device_t *v1_device);

#endif /* _v1_device_H_ */

