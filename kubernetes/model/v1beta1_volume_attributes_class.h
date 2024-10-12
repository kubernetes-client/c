/*
 * v1beta1_volume_attributes_class.h
 *
 * VolumeAttributesClass represents a specification of mutable volume attributes defined by the CSI driver. The class can be specified during dynamic provisioning of PersistentVolumeClaims, and changed in the PersistentVolumeClaim spec after provisioning.
 */

#ifndef _v1beta1_volume_attributes_class_H_
#define _v1beta1_volume_attributes_class_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_volume_attributes_class_t v1beta1_volume_attributes_class_t;

#include "v1_object_meta.h"



typedef struct v1beta1_volume_attributes_class_t {
    char *api_version; // string
    char *driver_name; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    list_t* parameters; //map

} v1beta1_volume_attributes_class_t;

v1beta1_volume_attributes_class_t *v1beta1_volume_attributes_class_create(
    char *api_version,
    char *driver_name,
    char *kind,
    v1_object_meta_t *metadata,
    list_t* parameters
);

void v1beta1_volume_attributes_class_free(v1beta1_volume_attributes_class_t *v1beta1_volume_attributes_class);

v1beta1_volume_attributes_class_t *v1beta1_volume_attributes_class_parseFromJSON(cJSON *v1beta1_volume_attributes_classJSON);

cJSON *v1beta1_volume_attributes_class_convertToJSON(v1beta1_volume_attributes_class_t *v1beta1_volume_attributes_class);

#endif /* _v1beta1_volume_attributes_class_H_ */

