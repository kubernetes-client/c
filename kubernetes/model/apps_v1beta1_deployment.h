/*
 * apps_v1beta1_deployment.h
 *
 * DEPRECATED - This group version of Deployment is deprecated by apps/v1beta2/Deployment. See the release notes for more information. Deployment enables declarative updates for Pods and ReplicaSets.
 */

#ifndef _apps_v1beta1_deployment_H_
#define _apps_v1beta1_deployment_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct apps_v1beta1_deployment_t apps_v1beta1_deployment_t;

#include "apps_v1beta1_deployment_spec.h"
#include "apps_v1beta1_deployment_status.h"
#include "v1_object_meta.h"



typedef struct apps_v1beta1_deployment_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct apps_v1beta1_deployment_spec_t *spec; //model
    struct apps_v1beta1_deployment_status_t *status; //model

} apps_v1beta1_deployment_t;

apps_v1beta1_deployment_t *apps_v1beta1_deployment_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    apps_v1beta1_deployment_spec_t *spec,
    apps_v1beta1_deployment_status_t *status
);

void apps_v1beta1_deployment_free(apps_v1beta1_deployment_t *apps_v1beta1_deployment);

apps_v1beta1_deployment_t *apps_v1beta1_deployment_parseFromJSON(cJSON *apps_v1beta1_deploymentJSON);

cJSON *apps_v1beta1_deployment_convertToJSON(apps_v1beta1_deployment_t *apps_v1beta1_deployment);

#endif /* _apps_v1beta1_deployment_H_ */

