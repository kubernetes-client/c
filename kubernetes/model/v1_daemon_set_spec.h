/*
 * v1_daemon_set_spec.h
 *
 * DaemonSetSpec is the specification of a daemon set.
 */

#ifndef _v1_daemon_set_spec_H_
#define _v1_daemon_set_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_daemon_set_spec_t v1_daemon_set_spec_t;

#include "v1_daemon_set_update_strategy.h"
#include "v1_label_selector.h"
#include "v1_pod_template_spec.h"



typedef struct v1_daemon_set_spec_t {
    int min_ready_seconds; //numeric
    int revision_history_limit; //numeric
    struct v1_label_selector_t *selector; //model
    struct v1_pod_template_spec_t *_template; //model
    struct v1_daemon_set_update_strategy_t *update_strategy; //model

} v1_daemon_set_spec_t;

v1_daemon_set_spec_t *v1_daemon_set_spec_create(
    int min_ready_seconds,
    int revision_history_limit,
    v1_label_selector_t *selector,
    v1_pod_template_spec_t *_template,
    v1_daemon_set_update_strategy_t *update_strategy
);

void v1_daemon_set_spec_free(v1_daemon_set_spec_t *v1_daemon_set_spec);

v1_daemon_set_spec_t *v1_daemon_set_spec_parseFromJSON(cJSON *v1_daemon_set_specJSON);

cJSON *v1_daemon_set_spec_convertToJSON(v1_daemon_set_spec_t *v1_daemon_set_spec);

#endif /* _v1_daemon_set_spec_H_ */

