/*
 * v1alpha2_allocation_result.h
 *
 * AllocationResult contains attributes of an allocated resource.
 */

#ifndef _v1alpha2_allocation_result_H_
#define _v1alpha2_allocation_result_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha2_allocation_result_t v1alpha2_allocation_result_t;

#include "v1_node_selector.h"
#include "v1alpha2_resource_handle.h"



typedef struct v1alpha2_allocation_result_t {
    struct v1_node_selector_t *available_on_nodes; //model
    list_t *resource_handles; //nonprimitive container
    int shareable; //boolean

} v1alpha2_allocation_result_t;

v1alpha2_allocation_result_t *v1alpha2_allocation_result_create(
    v1_node_selector_t *available_on_nodes,
    list_t *resource_handles,
    int shareable
);

void v1alpha2_allocation_result_free(v1alpha2_allocation_result_t *v1alpha2_allocation_result);

v1alpha2_allocation_result_t *v1alpha2_allocation_result_parseFromJSON(cJSON *v1alpha2_allocation_resultJSON);

cJSON *v1alpha2_allocation_result_convertToJSON(v1alpha2_allocation_result_t *v1alpha2_allocation_result);

#endif /* _v1alpha2_allocation_result_H_ */

