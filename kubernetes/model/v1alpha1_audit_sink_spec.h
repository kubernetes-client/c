/*
 * v1alpha1_audit_sink_spec.h
 *
 * AuditSinkSpec holds the spec for the audit sink
 */

#ifndef _v1alpha1_audit_sink_spec_H_
#define _v1alpha1_audit_sink_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_audit_sink_spec_t v1alpha1_audit_sink_spec_t;

#include "v1alpha1_policy.h"
#include "v1alpha1_webhook.h"



typedef struct v1alpha1_audit_sink_spec_t {
    struct v1alpha1_policy_t *policy; //model
    struct v1alpha1_webhook_t *webhook; //model

} v1alpha1_audit_sink_spec_t;

v1alpha1_audit_sink_spec_t *v1alpha1_audit_sink_spec_create(
    v1alpha1_policy_t *policy,
    v1alpha1_webhook_t *webhook
);

void v1alpha1_audit_sink_spec_free(v1alpha1_audit_sink_spec_t *v1alpha1_audit_sink_spec);

v1alpha1_audit_sink_spec_t *v1alpha1_audit_sink_spec_parseFromJSON(cJSON *v1alpha1_audit_sink_specJSON);

cJSON *v1alpha1_audit_sink_spec_convertToJSON(v1alpha1_audit_sink_spec_t *v1alpha1_audit_sink_spec);

#endif /* _v1alpha1_audit_sink_spec_H_ */

