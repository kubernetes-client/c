/*
 * extensions_v1beta1_deployment_spec.h
 *
 * DeploymentSpec is the specification of the desired behavior of the Deployment.
 */

#ifndef _extensions_v1beta1_deployment_spec_H_
#define _extensions_v1beta1_deployment_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct extensions_v1beta1_deployment_spec_t extensions_v1beta1_deployment_spec_t;

#include "extensions_v1beta1_deployment_strategy.h"
#include "extensions_v1beta1_rollback_config.h"
#include "v1_label_selector.h"
#include "v1_pod_template_spec.h"



typedef struct extensions_v1beta1_deployment_spec_t {
    int min_ready_seconds; //numeric
    int paused; //boolean
    int progress_deadline_seconds; //numeric
    int replicas; //numeric
    int revision_history_limit; //numeric
    struct extensions_v1beta1_rollback_config_t *rollback_to; //model
    struct v1_label_selector_t *selector; //model
    struct extensions_v1beta1_deployment_strategy_t *strategy; //model
    struct v1_pod_template_spec_t *_template; //model

} extensions_v1beta1_deployment_spec_t;

extensions_v1beta1_deployment_spec_t *extensions_v1beta1_deployment_spec_create(
    int min_ready_seconds,
    int paused,
    int progress_deadline_seconds,
    int replicas,
    int revision_history_limit,
    extensions_v1beta1_rollback_config_t *rollback_to,
    v1_label_selector_t *selector,
    extensions_v1beta1_deployment_strategy_t *strategy,
    v1_pod_template_spec_t *_template
);

void extensions_v1beta1_deployment_spec_free(extensions_v1beta1_deployment_spec_t *extensions_v1beta1_deployment_spec);

extensions_v1beta1_deployment_spec_t *extensions_v1beta1_deployment_spec_parseFromJSON(cJSON *extensions_v1beta1_deployment_specJSON);

cJSON *extensions_v1beta1_deployment_spec_convertToJSON(extensions_v1beta1_deployment_spec_t *extensions_v1beta1_deployment_spec);

#endif /* _extensions_v1beta1_deployment_spec_H_ */

