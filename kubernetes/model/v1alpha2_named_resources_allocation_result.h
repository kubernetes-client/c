/*
 * v1alpha2_named_resources_allocation_result.h
 *
 * NamedResourcesAllocationResult is used in AllocationResultModel.
 */

#ifndef _v1alpha2_named_resources_allocation_result_H_
#define _v1alpha2_named_resources_allocation_result_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha2_named_resources_allocation_result_t v1alpha2_named_resources_allocation_result_t;




typedef struct v1alpha2_named_resources_allocation_result_t {
    char *name; // string

} v1alpha2_named_resources_allocation_result_t;

v1alpha2_named_resources_allocation_result_t *v1alpha2_named_resources_allocation_result_create(
    char *name
);

void v1alpha2_named_resources_allocation_result_free(v1alpha2_named_resources_allocation_result_t *v1alpha2_named_resources_allocation_result);

v1alpha2_named_resources_allocation_result_t *v1alpha2_named_resources_allocation_result_parseFromJSON(cJSON *v1alpha2_named_resources_allocation_resultJSON);

cJSON *v1alpha2_named_resources_allocation_result_convertToJSON(v1alpha2_named_resources_allocation_result_t *v1alpha2_named_resources_allocation_result);

#endif /* _v1alpha2_named_resources_allocation_result_H_ */

