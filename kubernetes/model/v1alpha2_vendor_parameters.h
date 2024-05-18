/*
 * v1alpha2_vendor_parameters.h
 *
 * VendorParameters are opaque parameters for one particular driver.
 */

#ifndef _v1alpha2_vendor_parameters_H_
#define _v1alpha2_vendor_parameters_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha2_vendor_parameters_t v1alpha2_vendor_parameters_t;

#include "object.h"



typedef struct v1alpha2_vendor_parameters_t {
    char *driver_name; // string
    object_t *parameters; //object

} v1alpha2_vendor_parameters_t;

v1alpha2_vendor_parameters_t *v1alpha2_vendor_parameters_create(
    char *driver_name,
    object_t *parameters
);

void v1alpha2_vendor_parameters_free(v1alpha2_vendor_parameters_t *v1alpha2_vendor_parameters);

v1alpha2_vendor_parameters_t *v1alpha2_vendor_parameters_parseFromJSON(cJSON *v1alpha2_vendor_parametersJSON);

cJSON *v1alpha2_vendor_parameters_convertToJSON(v1alpha2_vendor_parameters_t *v1alpha2_vendor_parameters);

#endif /* _v1alpha2_vendor_parameters_H_ */

