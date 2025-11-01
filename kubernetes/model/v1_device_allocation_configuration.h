/*
 * v1_device_allocation_configuration.h
 *
 * DeviceAllocationConfiguration gets embedded in an AllocationResult.
 */

#ifndef _v1_device_allocation_configuration_H_
#define _v1_device_allocation_configuration_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_device_allocation_configuration_t v1_device_allocation_configuration_t;

#include "v1_opaque_device_configuration.h"



typedef struct v1_device_allocation_configuration_t {
    struct v1_opaque_device_configuration_t *opaque; //model
    list_t *requests; //primitive container
    char *source; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_device_allocation_configuration_t;

__attribute__((deprecated)) v1_device_allocation_configuration_t *v1_device_allocation_configuration_create(
    v1_opaque_device_configuration_t *opaque,
    list_t *requests,
    char *source
);

void v1_device_allocation_configuration_free(v1_device_allocation_configuration_t *v1_device_allocation_configuration);

v1_device_allocation_configuration_t *v1_device_allocation_configuration_parseFromJSON(cJSON *v1_device_allocation_configurationJSON);

cJSON *v1_device_allocation_configuration_convertToJSON(v1_device_allocation_configuration_t *v1_device_allocation_configuration);

#endif /* _v1_device_allocation_configuration_H_ */

