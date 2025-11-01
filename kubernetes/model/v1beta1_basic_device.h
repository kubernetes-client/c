/*
 * v1beta1_basic_device.h
 *
 * BasicDevice defines one device instance.
 */

#ifndef _v1beta1_basic_device_H_
#define _v1beta1_basic_device_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_basic_device_t v1beta1_basic_device_t;

#include "v1_node_selector.h"
#include "v1beta1_device_attribute.h"
#include "v1beta1_device_capacity.h"
#include "v1beta1_device_counter_consumption.h"
#include "v1beta1_device_taint.h"



typedef struct v1beta1_basic_device_t {
    int all_nodes; //boolean
    int allow_multiple_allocations; //boolean
    list_t* attributes; //map
    list_t *binding_conditions; //primitive container
    list_t *binding_failure_conditions; //primitive container
    int binds_to_node; //boolean
    list_t* capacity; //map
    list_t *consumes_counters; //nonprimitive container
    char *node_name; // string
    struct v1_node_selector_t *node_selector; //model
    list_t *taints; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_basic_device_t;

__attribute__((deprecated)) v1beta1_basic_device_t *v1beta1_basic_device_create(
    int all_nodes,
    int allow_multiple_allocations,
    list_t* attributes,
    list_t *binding_conditions,
    list_t *binding_failure_conditions,
    int binds_to_node,
    list_t* capacity,
    list_t *consumes_counters,
    char *node_name,
    v1_node_selector_t *node_selector,
    list_t *taints
);

void v1beta1_basic_device_free(v1beta1_basic_device_t *v1beta1_basic_device);

v1beta1_basic_device_t *v1beta1_basic_device_parseFromJSON(cJSON *v1beta1_basic_deviceJSON);

cJSON *v1beta1_basic_device_convertToJSON(v1beta1_basic_device_t *v1beta1_basic_device);

#endif /* _v1beta1_basic_device_H_ */

