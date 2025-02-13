/*
 * v1_pod_disruption_budget_status.h
 *
 * PodDisruptionBudgetStatus represents information about the status of a PodDisruptionBudget. Status may trail the actual state of a system.
 */

#ifndef _v1_pod_disruption_budget_status_H_
#define _v1_pod_disruption_budget_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_pod_disruption_budget_status_t v1_pod_disruption_budget_status_t;

#include "v1_condition.h"



typedef struct v1_pod_disruption_budget_status_t {
    list_t *conditions; //nonprimitive container
    int current_healthy; //numeric
    int desired_healthy; //numeric
    list_t* disrupted_pods; //map
    int disruptions_allowed; //numeric
    int expected_pods; //numeric
    long observed_generation; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} v1_pod_disruption_budget_status_t;

__attribute__((deprecated)) v1_pod_disruption_budget_status_t *v1_pod_disruption_budget_status_create(
    list_t *conditions,
    int current_healthy,
    int desired_healthy,
    list_t* disrupted_pods,
    int disruptions_allowed,
    int expected_pods,
    long observed_generation
);

void v1_pod_disruption_budget_status_free(v1_pod_disruption_budget_status_t *v1_pod_disruption_budget_status);

v1_pod_disruption_budget_status_t *v1_pod_disruption_budget_status_parseFromJSON(cJSON *v1_pod_disruption_budget_statusJSON);

cJSON *v1_pod_disruption_budget_status_convertToJSON(v1_pod_disruption_budget_status_t *v1_pod_disruption_budget_status);

#endif /* _v1_pod_disruption_budget_status_H_ */

