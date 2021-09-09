/*
 * v1alpha1_audit_sink.h
 *
 * AuditSink represents a cluster level audit sink
 */

#ifndef _v1alpha1_audit_sink_H_
#define _v1alpha1_audit_sink_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_audit_sink_t v1alpha1_audit_sink_t;

#include "v1_object_meta.h"
#include "v1alpha1_audit_sink_spec.h"



typedef struct v1alpha1_audit_sink_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1alpha1_audit_sink_spec_t *spec; //model

} v1alpha1_audit_sink_t;

v1alpha1_audit_sink_t *v1alpha1_audit_sink_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha1_audit_sink_spec_t *spec
);

void v1alpha1_audit_sink_free(v1alpha1_audit_sink_t *v1alpha1_audit_sink);

v1alpha1_audit_sink_t *v1alpha1_audit_sink_parseFromJSON(cJSON *v1alpha1_audit_sinkJSON);

cJSON *v1alpha1_audit_sink_convertToJSON(v1alpha1_audit_sink_t *v1alpha1_audit_sink);

#endif /* _v1alpha1_audit_sink_H_ */

