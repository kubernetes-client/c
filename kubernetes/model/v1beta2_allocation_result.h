/*
 * v1beta2_allocation_result.h
 *
 * AllocationResult contains attributes of an allocated resource.
 */

#ifndef _v1beta2_allocation_result_H_
#define _v1beta2_allocation_result_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta2_allocation_result_t v1beta2_allocation_result_t;

#include "v1_node_selector.h"
#include "v1beta2_device_allocation_result.h"



typedef struct v1beta2_allocation_result_t {
    struct v1beta2_device_allocation_result_t *devices; //model
    struct v1_node_selector_t *node_selector; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta2_allocation_result_t;

__attribute__((deprecated)) v1beta2_allocation_result_t *v1beta2_allocation_result_create(
    v1beta2_device_allocation_result_t *devices,
    v1_node_selector_t *node_selector
);

void v1beta2_allocation_result_free(v1beta2_allocation_result_t *v1beta2_allocation_result);

v1beta2_allocation_result_t *v1beta2_allocation_result_parseFromJSON(cJSON *v1beta2_allocation_resultJSON);

cJSON *v1beta2_allocation_result_convertToJSON(v1beta2_allocation_result_t *v1beta2_allocation_result);

#endif /* _v1beta2_allocation_result_H_ */

