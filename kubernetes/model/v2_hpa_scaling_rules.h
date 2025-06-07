/*
 * v2_hpa_scaling_rules.h
 *
 * HPAScalingRules configures the scaling behavior for one direction via scaling Policy Rules and a configurable metric tolerance.  Scaling Policy Rules are applied after calculating DesiredReplicas from metrics for the HPA. They can limit the scaling velocity by specifying scaling policies. They can prevent flapping by specifying the stabilization window, so that the number of replicas is not set instantly, instead, the safest value from the stabilization window is chosen.  The tolerance is applied to the metric values and prevents scaling too eagerly for small metric variations. (Note that setting a tolerance requires enabling the alpha HPAConfigurableTolerance feature gate.)
 */

#ifndef _v2_hpa_scaling_rules_H_
#define _v2_hpa_scaling_rules_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2_hpa_scaling_rules_t v2_hpa_scaling_rules_t;

#include "v2_hpa_scaling_policy.h"



typedef struct v2_hpa_scaling_rules_t {
    list_t *policies; //nonprimitive container
    char *select_policy; // string
    int stabilization_window_seconds; //numeric
    char *tolerance; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v2_hpa_scaling_rules_t;

__attribute__((deprecated)) v2_hpa_scaling_rules_t *v2_hpa_scaling_rules_create(
    list_t *policies,
    char *select_policy,
    int stabilization_window_seconds,
    char *tolerance
);

void v2_hpa_scaling_rules_free(v2_hpa_scaling_rules_t *v2_hpa_scaling_rules);

v2_hpa_scaling_rules_t *v2_hpa_scaling_rules_parseFromJSON(cJSON *v2_hpa_scaling_rulesJSON);

cJSON *v2_hpa_scaling_rules_convertToJSON(v2_hpa_scaling_rules_t *v2_hpa_scaling_rules);

#endif /* _v2_hpa_scaling_rules_H_ */

