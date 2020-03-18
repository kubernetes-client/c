/*
 * extensions_v1beta1_allowed_csi_driver.h
 *
 * AllowedCSIDriver represents a single inline CSI Driver that is allowed to be used.
 */

#ifndef _extensions_v1beta1_allowed_csi_driver_H_
#define _extensions_v1beta1_allowed_csi_driver_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct extensions_v1beta1_allowed_csi_driver_t {
    char *name; // string

} extensions_v1beta1_allowed_csi_driver_t;

extensions_v1beta1_allowed_csi_driver_t *extensions_v1beta1_allowed_csi_driver_create(
    char *name
);

void extensions_v1beta1_allowed_csi_driver_free(extensions_v1beta1_allowed_csi_driver_t *extensions_v1beta1_allowed_csi_driver);

extensions_v1beta1_allowed_csi_driver_t *extensions_v1beta1_allowed_csi_driver_parseFromJSON(cJSON *extensions_v1beta1_allowed_csi_driverJSON);

cJSON *extensions_v1beta1_allowed_csi_driver_convertToJSON(extensions_v1beta1_allowed_csi_driver_t *extensions_v1beta1_allowed_csi_driver);

#endif /* _extensions_v1beta1_allowed_csi_driver_H_ */

