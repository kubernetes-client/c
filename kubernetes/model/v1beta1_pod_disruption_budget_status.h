/*
 * v1beta1_pod_disruption_budget_status.h
 *
 * PodDisruptionBudgetStatus represents information about the status of a PodDisruptionBudget. Status may trail the actual state of a system.
 */

#ifndef _v1beta1_pod_disruption_budget_status_H_
#define _v1beta1_pod_disruption_budget_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_pod_disruption_budget_status_t v1beta1_pod_disruption_budget_status_t;




typedef struct v1beta1_pod_disruption_budget_status_t {
    int current_healthy; //numeric
    int desired_healthy; //numeric
    list_t* disrupted_pods; //map
    int disruptions_allowed; //numeric
    int expected_pods; //numeric
    long observed_generation; //numeric

} v1beta1_pod_disruption_budget_status_t;

v1beta1_pod_disruption_budget_status_t *v1beta1_pod_disruption_budget_status_create(
    int current_healthy,
    int desired_healthy,
    list_t* disrupted_pods,
    int disruptions_allowed,
    int expected_pods,
    long observed_generation
);

void v1beta1_pod_disruption_budget_status_free(v1beta1_pod_disruption_budget_status_t *v1beta1_pod_disruption_budget_status);

v1beta1_pod_disruption_budget_status_t *v1beta1_pod_disruption_budget_status_parseFromJSON(cJSON *v1beta1_pod_disruption_budget_statusJSON);

cJSON *v1beta1_pod_disruption_budget_status_convertToJSON(v1beta1_pod_disruption_budget_status_t *v1beta1_pod_disruption_budget_status);

#endif /* _v1beta1_pod_disruption_budget_status_H_ */

