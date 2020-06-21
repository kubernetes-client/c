/*
 * v1beta1_csi_driver.h
 *
 * CSIDriver captures information about a Container Storage Interface (CSI) volume driver deployed on the cluster. CSI drivers do not need to create the CSIDriver object directly. Instead they may use the cluster-driver-registrar sidecar container. When deployed with a CSI driver it automatically creates a CSIDriver object representing the driver. Kubernetes attach detach controller uses this object to determine whether attach is required. Kubelet uses this object to determine whether pod information needs to be passed on mount. CSIDriver objects are non-namespaced.
 */

#ifndef _v1beta1_csi_driver_H_
#define _v1beta1_csi_driver_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_csi_driver_t v1beta1_csi_driver_t;

#include "v1_object_meta.h"
#include "v1beta1_csi_driver_spec.h"



typedef struct v1beta1_csi_driver_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1beta1_csi_driver_spec_t *spec; //model

} v1beta1_csi_driver_t;

v1beta1_csi_driver_t *v1beta1_csi_driver_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta1_csi_driver_spec_t *spec
);

void v1beta1_csi_driver_free(v1beta1_csi_driver_t *v1beta1_csi_driver);

v1beta1_csi_driver_t *v1beta1_csi_driver_parseFromJSON(cJSON *v1beta1_csi_driverJSON);

cJSON *v1beta1_csi_driver_convertToJSON(v1beta1_csi_driver_t *v1beta1_csi_driver);

#endif /* _v1beta1_csi_driver_H_ */

