/*
 * apps_v1beta1_deployment_rollback.h
 *
 * DEPRECATED. DeploymentRollback stores the information required to rollback a deployment.
 */

#ifndef _apps_v1beta1_deployment_rollback_H_
#define _apps_v1beta1_deployment_rollback_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct apps_v1beta1_deployment_rollback_t apps_v1beta1_deployment_rollback_t;

#include "apps_v1beta1_rollback_config.h"



typedef struct apps_v1beta1_deployment_rollback_t {
    char *api_version; // string
    char *kind; // string
    char *name; // string
    struct apps_v1beta1_rollback_config_t *rollback_to; //model
    list_t* updated_annotations; //map

} apps_v1beta1_deployment_rollback_t;

apps_v1beta1_deployment_rollback_t *apps_v1beta1_deployment_rollback_create(
    char *api_version,
    char *kind,
    char *name,
    apps_v1beta1_rollback_config_t *rollback_to,
    list_t* updated_annotations
);

void apps_v1beta1_deployment_rollback_free(apps_v1beta1_deployment_rollback_t *apps_v1beta1_deployment_rollback);

apps_v1beta1_deployment_rollback_t *apps_v1beta1_deployment_rollback_parseFromJSON(cJSON *apps_v1beta1_deployment_rollbackJSON);

cJSON *apps_v1beta1_deployment_rollback_convertToJSON(apps_v1beta1_deployment_rollback_t *apps_v1beta1_deployment_rollback);

#endif /* _apps_v1beta1_deployment_rollback_H_ */

