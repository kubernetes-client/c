/*
 * v1alpha1_flow_schema.h
 *
 * FlowSchema defines the schema of a group of flows. Note that a flow is made up of a set of inbound API requests with similar attributes and is identified by a pair of strings: the name of the FlowSchema and a \&quot;flow distinguisher\&quot;.
 */

#ifndef _v1alpha1_flow_schema_H_
#define _v1alpha1_flow_schema_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_flow_schema_t v1alpha1_flow_schema_t;

#include "v1_object_meta.h"
#include "v1alpha1_flow_schema_spec.h"
#include "v1alpha1_flow_schema_status.h"



typedef struct v1alpha1_flow_schema_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1alpha1_flow_schema_spec_t *spec; //model
    struct v1alpha1_flow_schema_status_t *status; //model

} v1alpha1_flow_schema_t;

v1alpha1_flow_schema_t *v1alpha1_flow_schema_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha1_flow_schema_spec_t *spec,
    v1alpha1_flow_schema_status_t *status
);

void v1alpha1_flow_schema_free(v1alpha1_flow_schema_t *v1alpha1_flow_schema);

v1alpha1_flow_schema_t *v1alpha1_flow_schema_parseFromJSON(cJSON *v1alpha1_flow_schemaJSON);

cJSON *v1alpha1_flow_schema_convertToJSON(v1alpha1_flow_schema_t *v1alpha1_flow_schema);

#endif /* _v1alpha1_flow_schema_H_ */

