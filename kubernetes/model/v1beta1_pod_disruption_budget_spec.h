/*
 * v1beta1_pod_disruption_budget_spec.h
 *
 * PodDisruptionBudgetSpec is a description of a PodDisruptionBudget.
 */

#ifndef _v1beta1_pod_disruption_budget_spec_H_
#define _v1beta1_pod_disruption_budget_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_pod_disruption_budget_spec_t v1beta1_pod_disruption_budget_spec_t;

#include "object.h"
#include "v1_label_selector.h"



typedef struct v1beta1_pod_disruption_budget_spec_t {
    object_t *max_unavailable; //object
    object_t *min_available; //object
    struct v1_label_selector_t *selector; //model

} v1beta1_pod_disruption_budget_spec_t;

v1beta1_pod_disruption_budget_spec_t *v1beta1_pod_disruption_budget_spec_create(
    object_t *max_unavailable,
    object_t *min_available,
    v1_label_selector_t *selector
);

void v1beta1_pod_disruption_budget_spec_free(v1beta1_pod_disruption_budget_spec_t *v1beta1_pod_disruption_budget_spec);

v1beta1_pod_disruption_budget_spec_t *v1beta1_pod_disruption_budget_spec_parseFromJSON(cJSON *v1beta1_pod_disruption_budget_specJSON);

cJSON *v1beta1_pod_disruption_budget_spec_convertToJSON(v1beta1_pod_disruption_budget_spec_t *v1beta1_pod_disruption_budget_spec);

#endif /* _v1beta1_pod_disruption_budget_spec_H_ */

