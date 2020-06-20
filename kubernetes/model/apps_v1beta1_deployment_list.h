/*
 * apps_v1beta1_deployment_list.h
 *
 * DeploymentList is a list of Deployments.
 */

#ifndef _apps_v1beta1_deployment_list_H_
#define _apps_v1beta1_deployment_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct apps_v1beta1_deployment_list_t apps_v1beta1_deployment_list_t;

#include "apps_v1beta1_deployment.h"
#include "v1_list_meta.h"



typedef struct apps_v1beta1_deployment_list_t {
    char *api_version; // string
    list_t *items; //nonprimitive container
    char *kind; // string
    struct v1_list_meta_t *metadata; //model

} apps_v1beta1_deployment_list_t;

apps_v1beta1_deployment_list_t *apps_v1beta1_deployment_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
);

void apps_v1beta1_deployment_list_free(apps_v1beta1_deployment_list_t *apps_v1beta1_deployment_list);

apps_v1beta1_deployment_list_t *apps_v1beta1_deployment_list_parseFromJSON(cJSON *apps_v1beta1_deployment_listJSON);

cJSON *apps_v1beta1_deployment_list_convertToJSON(apps_v1beta1_deployment_list_t *apps_v1beta1_deployment_list);

#endif /* _apps_v1beta1_deployment_list_H_ */

