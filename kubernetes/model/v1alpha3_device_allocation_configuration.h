/*
 * v1alpha3_device_allocation_configuration.h
 *
 * DeviceAllocationConfiguration gets embedded in an AllocationResult.
 */

#ifndef _v1alpha3_device_allocation_configuration_H_
#define _v1alpha3_device_allocation_configuration_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_device_allocation_configuration_t v1alpha3_device_allocation_configuration_t;

#include "v1alpha3_opaque_device_configuration.h"



typedef struct v1alpha3_device_allocation_configuration_t {
    struct v1alpha3_opaque_device_configuration_t *opaque; //model
    list_t *requests; //primitive container
    char *source; // string

} v1alpha3_device_allocation_configuration_t;

v1alpha3_device_allocation_configuration_t *v1alpha3_device_allocation_configuration_create(
    v1alpha3_opaque_device_configuration_t *opaque,
    list_t *requests,
    char *source
);

void v1alpha3_device_allocation_configuration_free(v1alpha3_device_allocation_configuration_t *v1alpha3_device_allocation_configuration);

v1alpha3_device_allocation_configuration_t *v1alpha3_device_allocation_configuration_parseFromJSON(cJSON *v1alpha3_device_allocation_configurationJSON);

cJSON *v1alpha3_device_allocation_configuration_convertToJSON(v1alpha3_device_allocation_configuration_t *v1alpha3_device_allocation_configuration);

#endif /* _v1alpha3_device_allocation_configuration_H_ */

