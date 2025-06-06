/*
 * v1beta2_device.h
 *
 * Device represents one individual hardware instance that can be selected based on its attributes. Besides the name, exactly one field must be set.
 */

#ifndef _v1beta2_device_H_
#define _v1beta2_device_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta2_device_t v1beta2_device_t;

#include "v1_node_selector.h"
#include "v1beta2_device_attribute.h"
#include "v1beta2_device_capacity.h"
#include "v1beta2_device_counter_consumption.h"
#include "v1beta2_device_taint.h"



typedef struct v1beta2_device_t {
    int all_nodes; //boolean
    list_t* attributes; //map
    list_t* capacity; //map
    list_t *consumes_counters; //nonprimitive container
    char *name; // string
    char *node_name; // string
    struct v1_node_selector_t *node_selector; //model
    list_t *taints; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta2_device_t;

__attribute__((deprecated)) v1beta2_device_t *v1beta2_device_create(
    int all_nodes,
    list_t* attributes,
    list_t* capacity,
    list_t *consumes_counters,
    char *name,
    char *node_name,
    v1_node_selector_t *node_selector,
    list_t *taints
);

void v1beta2_device_free(v1beta2_device_t *v1beta2_device);

v1beta2_device_t *v1beta2_device_parseFromJSON(cJSON *v1beta2_deviceJSON);

cJSON *v1beta2_device_convertToJSON(v1beta2_device_t *v1beta2_device);

#endif /* _v1beta2_device_H_ */

