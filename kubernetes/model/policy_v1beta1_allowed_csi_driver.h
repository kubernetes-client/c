/*
 * policy_v1beta1_allowed_csi_driver.h
 *
 * AllowedCSIDriver represents a single inline CSI Driver that is allowed to be used.
 */

#ifndef _policy_v1beta1_allowed_csi_driver_H_
#define _policy_v1beta1_allowed_csi_driver_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct policy_v1beta1_allowed_csi_driver_t {
    char *name; // string

} policy_v1beta1_allowed_csi_driver_t;

policy_v1beta1_allowed_csi_driver_t *policy_v1beta1_allowed_csi_driver_create(
    char *name
);

void policy_v1beta1_allowed_csi_driver_free(policy_v1beta1_allowed_csi_driver_t *policy_v1beta1_allowed_csi_driver);

policy_v1beta1_allowed_csi_driver_t *policy_v1beta1_allowed_csi_driver_parseFromJSON(cJSON *policy_v1beta1_allowed_csi_driverJSON);

cJSON *policy_v1beta1_allowed_csi_driver_convertToJSON(policy_v1beta1_allowed_csi_driver_t *policy_v1beta1_allowed_csi_driver);

#endif /* _policy_v1beta1_allowed_csi_driver_H_ */

