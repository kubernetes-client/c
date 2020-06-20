/*
 * v1beta2_deployment_status.h
 *
 * DeploymentStatus is the most recently observed status of the Deployment.
 */

#ifndef _v1beta2_deployment_status_H_
#define _v1beta2_deployment_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta2_deployment_status_t v1beta2_deployment_status_t;

#include "v1beta2_deployment_condition.h"



typedef struct v1beta2_deployment_status_t {
    int available_replicas; //numeric
    int collision_count; //numeric
    list_t *conditions; //nonprimitive container
    long observed_generation; //numeric
    int ready_replicas; //numeric
    int replicas; //numeric
    int unavailable_replicas; //numeric
    int updated_replicas; //numeric

} v1beta2_deployment_status_t;

v1beta2_deployment_status_t *v1beta2_deployment_status_create(
    int available_replicas,
    int collision_count,
    list_t *conditions,
    long observed_generation,
    int ready_replicas,
    int replicas,
    int unavailable_replicas,
    int updated_replicas
);

void v1beta2_deployment_status_free(v1beta2_deployment_status_t *v1beta2_deployment_status);

v1beta2_deployment_status_t *v1beta2_deployment_status_parseFromJSON(cJSON *v1beta2_deployment_statusJSON);

cJSON *v1beta2_deployment_status_convertToJSON(v1beta2_deployment_status_t *v1beta2_deployment_status);

#endif /* _v1beta2_deployment_status_H_ */

