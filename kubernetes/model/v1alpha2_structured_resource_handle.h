/*
 * v1alpha2_structured_resource_handle.h
 *
 * StructuredResourceHandle is the in-tree representation of the allocation result.
 */

#ifndef _v1alpha2_structured_resource_handle_H_
#define _v1alpha2_structured_resource_handle_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha2_structured_resource_handle_t v1alpha2_structured_resource_handle_t;

#include "object.h"
#include "v1alpha2_driver_allocation_result.h"



typedef struct v1alpha2_structured_resource_handle_t {
    char *node_name; // string
    list_t *results; //nonprimitive container
    object_t *vendor_claim_parameters; //object
    object_t *vendor_class_parameters; //object

} v1alpha2_structured_resource_handle_t;

v1alpha2_structured_resource_handle_t *v1alpha2_structured_resource_handle_create(
    char *node_name,
    list_t *results,
    object_t *vendor_claim_parameters,
    object_t *vendor_class_parameters
);

void v1alpha2_structured_resource_handle_free(v1alpha2_structured_resource_handle_t *v1alpha2_structured_resource_handle);

v1alpha2_structured_resource_handle_t *v1alpha2_structured_resource_handle_parseFromJSON(cJSON *v1alpha2_structured_resource_handleJSON);

cJSON *v1alpha2_structured_resource_handle_convertToJSON(v1alpha2_structured_resource_handle_t *v1alpha2_structured_resource_handle);

#endif /* _v1alpha2_structured_resource_handle_H_ */

