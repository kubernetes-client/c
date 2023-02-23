/*
 * v1_pod_disruption_budget_spec.h
 *
 * PodDisruptionBudgetSpec is a description of a PodDisruptionBudget.
 */

#ifndef _v1_pod_disruption_budget_spec_H_
#define _v1_pod_disruption_budget_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_pod_disruption_budget_spec_t v1_pod_disruption_budget_spec_t;

#include "int_or_string.h"
#include "v1_label_selector.h"



typedef struct v1_pod_disruption_budget_spec_t {
    int_or_string_t *max_unavailable; // custom
    int_or_string_t *min_available; // custom
    struct v1_label_selector_t *selector; //model
    char *unhealthy_pod_eviction_policy; // string

} v1_pod_disruption_budget_spec_t;

v1_pod_disruption_budget_spec_t *v1_pod_disruption_budget_spec_create(
    int_or_string_t *max_unavailable,
    int_or_string_t *min_available,
    v1_label_selector_t *selector,
    char *unhealthy_pod_eviction_policy
);

void v1_pod_disruption_budget_spec_free(v1_pod_disruption_budget_spec_t *v1_pod_disruption_budget_spec);

v1_pod_disruption_budget_spec_t *v1_pod_disruption_budget_spec_parseFromJSON(cJSON *v1_pod_disruption_budget_specJSON);

cJSON *v1_pod_disruption_budget_spec_convertToJSON(v1_pod_disruption_budget_spec_t *v1_pod_disruption_budget_spec);

#endif /* _v1_pod_disruption_budget_spec_H_ */

