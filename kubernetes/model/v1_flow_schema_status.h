/*
 * v1_flow_schema_status.h
 *
 * FlowSchemaStatus represents the current state of a FlowSchema.
 */

#ifndef _v1_flow_schema_status_H_
#define _v1_flow_schema_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_flow_schema_status_t v1_flow_schema_status_t;

#include "v1_flow_schema_condition.h"



typedef struct v1_flow_schema_status_t {
    list_t *conditions; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1_flow_schema_status_t;

__attribute__((deprecated)) v1_flow_schema_status_t *v1_flow_schema_status_create(
    list_t *conditions
);

void v1_flow_schema_status_free(v1_flow_schema_status_t *v1_flow_schema_status);

v1_flow_schema_status_t *v1_flow_schema_status_parseFromJSON(cJSON *v1_flow_schema_statusJSON);

cJSON *v1_flow_schema_status_convertToJSON(v1_flow_schema_status_t *v1_flow_schema_status);

#endif /* _v1_flow_schema_status_H_ */

