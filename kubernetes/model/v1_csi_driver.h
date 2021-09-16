/*
 * v1_csi_driver.h
 *
 * CSIDriver captures information about a Container Storage Interface (CSI) volume driver deployed on the cluster. Kubernetes attach detach controller uses this object to determine whether attach is required. Kubelet uses this object to determine whether pod information needs to be passed on mount. CSIDriver objects are non-namespaced.
 */

#ifndef _v1_csi_driver_H_
#define _v1_csi_driver_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_csi_driver_t v1_csi_driver_t;

#include "v1_csi_driver_spec.h"
#include "v1_object_meta.h"



typedef struct v1_csi_driver_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1_csi_driver_spec_t *spec; //model

} v1_csi_driver_t;

v1_csi_driver_t *v1_csi_driver_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_csi_driver_spec_t *spec
);

void v1_csi_driver_free(v1_csi_driver_t *v1_csi_driver);

v1_csi_driver_t *v1_csi_driver_parseFromJSON(cJSON *v1_csi_driverJSON);

cJSON *v1_csi_driver_convertToJSON(v1_csi_driver_t *v1_csi_driver);

#endif /* _v1_csi_driver_H_ */

