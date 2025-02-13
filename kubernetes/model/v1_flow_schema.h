/*
 * v1_flow_schema.h
 *
 * FlowSchema defines the schema of a group of flows. Note that a flow is made up of a set of inbound API requests with similar attributes and is identified by a pair of strings: the name of the FlowSchema and a \&quot;flow distinguisher\&quot;.
 */

#ifndef _v1_flow_schema_H_
#define _v1_flow_schema_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_flow_schema_t v1_flow_schema_t;

#include "v1_flow_schema_spec.h"
#include "v1_flow_schema_status.h"
#include "v1_object_meta.h"



typedef struct v1_flow_schema_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1_flow_schema_spec_t *spec; //model
    struct v1_flow_schema_status_t *status; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1_flow_schema_t;

__attribute__((deprecated)) v1_flow_schema_t *v1_flow_schema_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_flow_schema_spec_t *spec,
    v1_flow_schema_status_t *status
);

void v1_flow_schema_free(v1_flow_schema_t *v1_flow_schema);

v1_flow_schema_t *v1_flow_schema_parseFromJSON(cJSON *v1_flow_schemaJSON);

cJSON *v1_flow_schema_convertToJSON(v1_flow_schema_t *v1_flow_schema);

#endif /* _v1_flow_schema_H_ */

