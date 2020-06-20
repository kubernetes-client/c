/*
 * extensions_v1beta1_deployment_rollback.h
 *
 * DEPRECATED. DeploymentRollback stores the information required to rollback a deployment.
 */

#ifndef _extensions_v1beta1_deployment_rollback_H_
#define _extensions_v1beta1_deployment_rollback_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct extensions_v1beta1_deployment_rollback_t extensions_v1beta1_deployment_rollback_t;

#include "extensions_v1beta1_rollback_config.h"



typedef struct extensions_v1beta1_deployment_rollback_t {
    char *api_version; // string
    char *kind; // string
    char *name; // string
    struct extensions_v1beta1_rollback_config_t *rollback_to; //model
    list_t* updated_annotations; //map

} extensions_v1beta1_deployment_rollback_t;

extensions_v1beta1_deployment_rollback_t *extensions_v1beta1_deployment_rollback_create(
    char *api_version,
    char *kind,
    char *name,
    extensions_v1beta1_rollback_config_t *rollback_to,
    list_t* updated_annotations
);

void extensions_v1beta1_deployment_rollback_free(extensions_v1beta1_deployment_rollback_t *extensions_v1beta1_deployment_rollback);

extensions_v1beta1_deployment_rollback_t *extensions_v1beta1_deployment_rollback_parseFromJSON(cJSON *extensions_v1beta1_deployment_rollbackJSON);

cJSON *extensions_v1beta1_deployment_rollback_convertToJSON(extensions_v1beta1_deployment_rollback_t *extensions_v1beta1_deployment_rollback);

#endif /* _extensions_v1beta1_deployment_rollback_H_ */

