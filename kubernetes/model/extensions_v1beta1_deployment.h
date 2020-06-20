/*
 * extensions_v1beta1_deployment.h
 *
 * DEPRECATED - This group version of Deployment is deprecated by apps/v1beta2/Deployment. See the release notes for more information. Deployment enables declarative updates for Pods and ReplicaSets.
 */

#ifndef _extensions_v1beta1_deployment_H_
#define _extensions_v1beta1_deployment_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct extensions_v1beta1_deployment_t extensions_v1beta1_deployment_t;

#include "extensions_v1beta1_deployment_spec.h"
#include "extensions_v1beta1_deployment_status.h"
#include "v1_object_meta.h"



typedef struct extensions_v1beta1_deployment_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct extensions_v1beta1_deployment_spec_t *spec; //model
    struct extensions_v1beta1_deployment_status_t *status; //model

} extensions_v1beta1_deployment_t;

extensions_v1beta1_deployment_t *extensions_v1beta1_deployment_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    extensions_v1beta1_deployment_spec_t *spec,
    extensions_v1beta1_deployment_status_t *status
);

void extensions_v1beta1_deployment_free(extensions_v1beta1_deployment_t *extensions_v1beta1_deployment);

extensions_v1beta1_deployment_t *extensions_v1beta1_deployment_parseFromJSON(cJSON *extensions_v1beta1_deploymentJSON);

cJSON *extensions_v1beta1_deployment_convertToJSON(extensions_v1beta1_deployment_t *extensions_v1beta1_deployment);

#endif /* _extensions_v1beta1_deployment_H_ */

