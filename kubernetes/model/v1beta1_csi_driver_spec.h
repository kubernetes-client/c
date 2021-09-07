/*
 * v1beta1_csi_driver_spec.h
 *
 * CSIDriverSpec is the specification of a CSIDriver.
 */

#ifndef _v1beta1_csi_driver_spec_H_
#define _v1beta1_csi_driver_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_csi_driver_spec_t v1beta1_csi_driver_spec_t;




typedef struct v1beta1_csi_driver_spec_t {
    int attach_required; //boolean
    int pod_info_on_mount; //boolean
    list_t *volume_lifecycle_modes; //primitive container

} v1beta1_csi_driver_spec_t;

v1beta1_csi_driver_spec_t *v1beta1_csi_driver_spec_create(
    int attach_required,
    int pod_info_on_mount,
    list_t *volume_lifecycle_modes
);

void v1beta1_csi_driver_spec_free(v1beta1_csi_driver_spec_t *v1beta1_csi_driver_spec);

v1beta1_csi_driver_spec_t *v1beta1_csi_driver_spec_parseFromJSON(cJSON *v1beta1_csi_driver_specJSON);

cJSON *v1beta1_csi_driver_spec_convertToJSON(v1beta1_csi_driver_spec_t *v1beta1_csi_driver_spec);

#endif /* _v1beta1_csi_driver_spec_H_ */

