/*
 * v1alpha3_device_class_spec.h
 *
 * DeviceClassSpec is used in a [DeviceClass] to define what can be allocated and how to configure it.
 */

#ifndef _v1alpha3_device_class_spec_H_
#define _v1alpha3_device_class_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_device_class_spec_t v1alpha3_device_class_spec_t;

#include "v1_node_selector.h"
#include "v1alpha3_device_class_configuration.h"
#include "v1alpha3_device_selector.h"



typedef struct v1alpha3_device_class_spec_t {
    list_t *config; //nonprimitive container
    list_t *selectors; //nonprimitive container
    struct v1_node_selector_t *suitable_nodes; //model

} v1alpha3_device_class_spec_t;

v1alpha3_device_class_spec_t *v1alpha3_device_class_spec_create(
    list_t *config,
    list_t *selectors,
    v1_node_selector_t *suitable_nodes
);

void v1alpha3_device_class_spec_free(v1alpha3_device_class_spec_t *v1alpha3_device_class_spec);

v1alpha3_device_class_spec_t *v1alpha3_device_class_spec_parseFromJSON(cJSON *v1alpha3_device_class_specJSON);

cJSON *v1alpha3_device_class_spec_convertToJSON(v1alpha3_device_class_spec_t *v1alpha3_device_class_spec);

#endif /* _v1alpha3_device_class_spec_H_ */

