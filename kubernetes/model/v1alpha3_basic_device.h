/*
 * v1alpha3_basic_device.h
 *
 * BasicDevice defines one device instance.
 */

#ifndef _v1alpha3_basic_device_H_
#define _v1alpha3_basic_device_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_basic_device_t v1alpha3_basic_device_t;

#include "v1_node_selector.h"
#include "v1alpha3_device_attribute.h"
#include "v1alpha3_device_counter_consumption.h"
#include "v1alpha3_device_taint.h"



typedef struct v1alpha3_basic_device_t {
    int all_nodes; //boolean
    list_t* attributes; //map
    list_t* capacity; //map
    list_t *consumes_counters; //nonprimitive container
    char *node_name; // string
    struct v1_node_selector_t *node_selector; //model
    list_t *taints; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha3_basic_device_t;

__attribute__((deprecated)) v1alpha3_basic_device_t *v1alpha3_basic_device_create(
    int all_nodes,
    list_t* attributes,
    list_t* capacity,
    list_t *consumes_counters,
    char *node_name,
    v1_node_selector_t *node_selector,
    list_t *taints
);

void v1alpha3_basic_device_free(v1alpha3_basic_device_t *v1alpha3_basic_device);

v1alpha3_basic_device_t *v1alpha3_basic_device_parseFromJSON(cJSON *v1alpha3_basic_deviceJSON);

cJSON *v1alpha3_basic_device_convertToJSON(v1alpha3_basic_device_t *v1alpha3_basic_device);

#endif /* _v1alpha3_basic_device_H_ */

