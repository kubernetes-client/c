/*
 * v1beta1_device_claim_configuration.h
 *
 * DeviceClaimConfiguration is used for configuration parameters in DeviceClaim.
 */

#ifndef _v1beta1_device_claim_configuration_H_
#define _v1beta1_device_claim_configuration_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_device_claim_configuration_t v1beta1_device_claim_configuration_t;

#include "v1beta1_opaque_device_configuration.h"



typedef struct v1beta1_device_claim_configuration_t {
    struct v1beta1_opaque_device_configuration_t *opaque; //model
    list_t *requests; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_device_claim_configuration_t;

__attribute__((deprecated)) v1beta1_device_claim_configuration_t *v1beta1_device_claim_configuration_create(
    v1beta1_opaque_device_configuration_t *opaque,
    list_t *requests
);

void v1beta1_device_claim_configuration_free(v1beta1_device_claim_configuration_t *v1beta1_device_claim_configuration);

v1beta1_device_claim_configuration_t *v1beta1_device_claim_configuration_parseFromJSON(cJSON *v1beta1_device_claim_configurationJSON);

cJSON *v1beta1_device_claim_configuration_convertToJSON(v1beta1_device_claim_configuration_t *v1beta1_device_claim_configuration);

#endif /* _v1beta1_device_claim_configuration_H_ */

