/*
 * apps_v1beta1_deployment_spec.h
 *
 * DeploymentSpec is the specification of the desired behavior of the Deployment.
 */

#ifndef _apps_v1beta1_deployment_spec_H_
#define _apps_v1beta1_deployment_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct apps_v1beta1_deployment_spec_t apps_v1beta1_deployment_spec_t;

#include "apps_v1beta1_deployment_strategy.h"
#include "apps_v1beta1_rollback_config.h"
#include "v1_label_selector.h"
#include "v1_pod_template_spec.h"



typedef struct apps_v1beta1_deployment_spec_t {
    int min_ready_seconds; //numeric
    int paused; //boolean
    int progress_deadline_seconds; //numeric
    int replicas; //numeric
    int revision_history_limit; //numeric
    struct apps_v1beta1_rollback_config_t *rollback_to; //model
    struct v1_label_selector_t *selector; //model
    struct apps_v1beta1_deployment_strategy_t *strategy; //model
    struct v1_pod_template_spec_t *_template; //model

} apps_v1beta1_deployment_spec_t;

apps_v1beta1_deployment_spec_t *apps_v1beta1_deployment_spec_create(
    int min_ready_seconds,
    int paused,
    int progress_deadline_seconds,
    int replicas,
    int revision_history_limit,
    apps_v1beta1_rollback_config_t *rollback_to,
    v1_label_selector_t *selector,
    apps_v1beta1_deployment_strategy_t *strategy,
    v1_pod_template_spec_t *_template
);

void apps_v1beta1_deployment_spec_free(apps_v1beta1_deployment_spec_t *apps_v1beta1_deployment_spec);

apps_v1beta1_deployment_spec_t *apps_v1beta1_deployment_spec_parseFromJSON(cJSON *apps_v1beta1_deployment_specJSON);

cJSON *apps_v1beta1_deployment_spec_convertToJSON(apps_v1beta1_deployment_spec_t *apps_v1beta1_deployment_spec);

#endif /* _apps_v1beta1_deployment_spec_H_ */

