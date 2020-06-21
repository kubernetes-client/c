/*
 * v1_deployment.h
 *
 * Deployment enables declarative updates for Pods and ReplicaSets.
 */

#ifndef _v1_deployment_H_
#define _v1_deployment_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_deployment_t v1_deployment_t;

#include "v1_deployment_spec.h"
#include "v1_deployment_status.h"
#include "v1_object_meta.h"



typedef struct v1_deployment_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1_deployment_spec_t *spec; //model
    struct v1_deployment_status_t *status; //model

} v1_deployment_t;

v1_deployment_t *v1_deployment_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_deployment_spec_t *spec,
    v1_deployment_status_t *status
);

void v1_deployment_free(v1_deployment_t *v1_deployment);

v1_deployment_t *v1_deployment_parseFromJSON(cJSON *v1_deploymentJSON);

cJSON *v1_deployment_convertToJSON(v1_deployment_t *v1_deployment);

#endif /* _v1_deployment_H_ */

