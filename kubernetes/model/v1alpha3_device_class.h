/*
 * v1alpha3_device_class.h
 *
 * DeviceClass is a vendor- or admin-provided resource that contains device configuration and selectors. It can be referenced in the device requests of a claim to apply these presets. Cluster scoped.  This is an alpha type and requires enabling the DynamicResourceAllocation feature gate.
 */

#ifndef _v1alpha3_device_class_H_
#define _v1alpha3_device_class_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_device_class_t v1alpha3_device_class_t;

#include "v1_object_meta.h"
#include "v1alpha3_device_class_spec.h"



typedef struct v1alpha3_device_class_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1alpha3_device_class_spec_t *spec; //model

} v1alpha3_device_class_t;

v1alpha3_device_class_t *v1alpha3_device_class_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha3_device_class_spec_t *spec
);

void v1alpha3_device_class_free(v1alpha3_device_class_t *v1alpha3_device_class);

v1alpha3_device_class_t *v1alpha3_device_class_parseFromJSON(cJSON *v1alpha3_device_classJSON);

cJSON *v1alpha3_device_class_convertToJSON(v1alpha3_device_class_t *v1alpha3_device_class);

#endif /* _v1alpha3_device_class_H_ */

