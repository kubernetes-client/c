/*
 * v1beta1_mutating_webhook.h
 *
 * MutatingWebhook describes an admission webhook and the resources and operations it applies to.
 */

#ifndef _v1beta1_mutating_webhook_H_
#define _v1beta1_mutating_webhook_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_mutating_webhook_t v1beta1_mutating_webhook_t;

#include "admissionregistration_v1beta1_webhook_client_config.h"
#include "v1_label_selector.h"
#include "v1beta1_rule_with_operations.h"



typedef struct v1beta1_mutating_webhook_t {
    list_t *admission_review_versions; //primitive container
    struct admissionregistration_v1beta1_webhook_client_config_t *client_config; //model
    char *failure_policy; // string
    char *match_policy; // string
    char *name; // string
    struct v1_label_selector_t *namespace_selector; //model
    struct v1_label_selector_t *object_selector; //model
    char *reinvocation_policy; // string
    list_t *rules; //nonprimitive container
    char *side_effects; // string
    int timeout_seconds; //numeric

} v1beta1_mutating_webhook_t;

v1beta1_mutating_webhook_t *v1beta1_mutating_webhook_create(
    list_t *admission_review_versions,
    admissionregistration_v1beta1_webhook_client_config_t *client_config,
    char *failure_policy,
    char *match_policy,
    char *name,
    v1_label_selector_t *namespace_selector,
    v1_label_selector_t *object_selector,
    char *reinvocation_policy,
    list_t *rules,
    char *side_effects,
    int timeout_seconds
);

void v1beta1_mutating_webhook_free(v1beta1_mutating_webhook_t *v1beta1_mutating_webhook);

v1beta1_mutating_webhook_t *v1beta1_mutating_webhook_parseFromJSON(cJSON *v1beta1_mutating_webhookJSON);

cJSON *v1beta1_mutating_webhook_convertToJSON(v1beta1_mutating_webhook_t *v1beta1_mutating_webhook);

#endif /* _v1beta1_mutating_webhook_H_ */

