/*
 * apps_v1beta1_deployment_condition.h
 *
 * DeploymentCondition describes the state of a deployment at a certain point.
 */

#ifndef _apps_v1beta1_deployment_condition_H_
#define _apps_v1beta1_deployment_condition_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct apps_v1beta1_deployment_condition_t apps_v1beta1_deployment_condition_t;




typedef struct apps_v1beta1_deployment_condition_t {
    char *last_transition_time; //date time
    char *last_update_time; //date time
    char *message; // string
    char *reason; // string
    char *status; // string
    char *type; // string

} apps_v1beta1_deployment_condition_t;

apps_v1beta1_deployment_condition_t *apps_v1beta1_deployment_condition_create(
    char *last_transition_time,
    char *last_update_time,
    char *message,
    char *reason,
    char *status,
    char *type
);

void apps_v1beta1_deployment_condition_free(apps_v1beta1_deployment_condition_t *apps_v1beta1_deployment_condition);

apps_v1beta1_deployment_condition_t *apps_v1beta1_deployment_condition_parseFromJSON(cJSON *apps_v1beta1_deployment_conditionJSON);

cJSON *apps_v1beta1_deployment_condition_convertToJSON(apps_v1beta1_deployment_condition_t *apps_v1beta1_deployment_condition);

#endif /* _apps_v1beta1_deployment_condition_H_ */

