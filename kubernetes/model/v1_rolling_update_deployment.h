/*
 * v1_rolling_update_deployment.h
 *
 * Spec to control the desired behavior of rolling update.
 */

#ifndef _v1_rolling_update_deployment_H_
#define _v1_rolling_update_deployment_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_rolling_update_deployment_t v1_rolling_update_deployment_t;

#include "int_or_string.h"



typedef struct v1_rolling_update_deployment_t {
    int_or_string_t *max_surge; // custom
    int_or_string_t *max_unavailable; // custom

} v1_rolling_update_deployment_t;

v1_rolling_update_deployment_t *v1_rolling_update_deployment_create(
    int_or_string_t *max_surge,
    int_or_string_t *max_unavailable
);

void v1_rolling_update_deployment_free(v1_rolling_update_deployment_t *v1_rolling_update_deployment);

v1_rolling_update_deployment_t *v1_rolling_update_deployment_parseFromJSON(cJSON *v1_rolling_update_deploymentJSON);

cJSON *v1_rolling_update_deployment_convertToJSON(v1_rolling_update_deployment_t *v1_rolling_update_deployment);

#endif /* _v1_rolling_update_deployment_H_ */

