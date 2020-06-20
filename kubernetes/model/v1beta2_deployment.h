/*
 * v1beta2_deployment.h
 *
 * DEPRECATED - This group version of Deployment is deprecated by apps/v1/Deployment. See the release notes for more information. Deployment enables declarative updates for Pods and ReplicaSets.
 */

#ifndef _v1beta2_deployment_H_
#define _v1beta2_deployment_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta2_deployment_t v1beta2_deployment_t;

#include "v1_object_meta.h"
#include "v1beta2_deployment_spec.h"
#include "v1beta2_deployment_status.h"



typedef struct v1beta2_deployment_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1beta2_deployment_spec_t *spec; //model
    struct v1beta2_deployment_status_t *status; //model

} v1beta2_deployment_t;

v1beta2_deployment_t *v1beta2_deployment_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta2_deployment_spec_t *spec,
    v1beta2_deployment_status_t *status
);

void v1beta2_deployment_free(v1beta2_deployment_t *v1beta2_deployment);

v1beta2_deployment_t *v1beta2_deployment_parseFromJSON(cJSON *v1beta2_deploymentJSON);

cJSON *v1beta2_deployment_convertToJSON(v1beta2_deployment_t *v1beta2_deployment);

#endif /* _v1beta2_deployment_H_ */

