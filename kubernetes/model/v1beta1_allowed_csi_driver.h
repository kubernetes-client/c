/*
 * v1beta1_allowed_csi_driver.h
 *
 * AllowedCSIDriver represents a single inline CSI Driver that is allowed to be used.
 */

#ifndef _v1beta1_allowed_csi_driver_H_
#define _v1beta1_allowed_csi_driver_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_allowed_csi_driver_t v1beta1_allowed_csi_driver_t;




typedef struct v1beta1_allowed_csi_driver_t {
    char *name; // string

} v1beta1_allowed_csi_driver_t;

v1beta1_allowed_csi_driver_t *v1beta1_allowed_csi_driver_create(
    char *name
);

void v1beta1_allowed_csi_driver_free(v1beta1_allowed_csi_driver_t *v1beta1_allowed_csi_driver);

v1beta1_allowed_csi_driver_t *v1beta1_allowed_csi_driver_parseFromJSON(cJSON *v1beta1_allowed_csi_driverJSON);

cJSON *v1beta1_allowed_csi_driver_convertToJSON(v1beta1_allowed_csi_driver_t *v1beta1_allowed_csi_driver);

#endif /* _v1beta1_allowed_csi_driver_H_ */

