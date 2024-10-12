/*
 * v1alpha3_allocation_result.h
 *
 * AllocationResult contains attributes of an allocated resource.
 */

#ifndef _v1alpha3_allocation_result_H_
#define _v1alpha3_allocation_result_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_allocation_result_t v1alpha3_allocation_result_t;

#include "v1_node_selector.h"
#include "v1alpha3_device_allocation_result.h"



typedef struct v1alpha3_allocation_result_t {
    char *controller; // string
    struct v1alpha3_device_allocation_result_t *devices; //model
    struct v1_node_selector_t *node_selector; //model

} v1alpha3_allocation_result_t;

v1alpha3_allocation_result_t *v1alpha3_allocation_result_create(
    char *controller,
    v1alpha3_device_allocation_result_t *devices,
    v1_node_selector_t *node_selector
);

void v1alpha3_allocation_result_free(v1alpha3_allocation_result_t *v1alpha3_allocation_result);

v1alpha3_allocation_result_t *v1alpha3_allocation_result_parseFromJSON(cJSON *v1alpha3_allocation_resultJSON);

cJSON *v1alpha3_allocation_result_convertToJSON(v1alpha3_allocation_result_t *v1alpha3_allocation_result);

#endif /* _v1alpha3_allocation_result_H_ */

