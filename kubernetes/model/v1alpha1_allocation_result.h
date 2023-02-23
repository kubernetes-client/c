/*
 * v1alpha1_allocation_result.h
 *
 * AllocationResult contains attributed of an allocated resource.
 */

#ifndef _v1alpha1_allocation_result_H_
#define _v1alpha1_allocation_result_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_allocation_result_t v1alpha1_allocation_result_t;

#include "v1_node_selector.h"



typedef struct v1alpha1_allocation_result_t {
    struct v1_node_selector_t *available_on_nodes; //model
    char *resource_handle; // string
    int shareable; //boolean

} v1alpha1_allocation_result_t;

v1alpha1_allocation_result_t *v1alpha1_allocation_result_create(
    v1_node_selector_t *available_on_nodes,
    char *resource_handle,
    int shareable
);

void v1alpha1_allocation_result_free(v1alpha1_allocation_result_t *v1alpha1_allocation_result);

v1alpha1_allocation_result_t *v1alpha1_allocation_result_parseFromJSON(cJSON *v1alpha1_allocation_resultJSON);

cJSON *v1alpha1_allocation_result_convertToJSON(v1alpha1_allocation_result_t *v1alpha1_allocation_result);

#endif /* _v1alpha1_allocation_result_H_ */

