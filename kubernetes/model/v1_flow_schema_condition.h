/*
 * v1_flow_schema_condition.h
 *
 * FlowSchemaCondition describes conditions for a FlowSchema.
 */

#ifndef _v1_flow_schema_condition_H_
#define _v1_flow_schema_condition_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_flow_schema_condition_t v1_flow_schema_condition_t;




typedef struct v1_flow_schema_condition_t {
    char *last_transition_time; //date time
    char *message; // string
    char *reason; // string
    char *status; // string
    char *type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_flow_schema_condition_t;

__attribute__((deprecated)) v1_flow_schema_condition_t *v1_flow_schema_condition_create(
    char *last_transition_time,
    char *message,
    char *reason,
    char *status,
    char *type
);

void v1_flow_schema_condition_free(v1_flow_schema_condition_t *v1_flow_schema_condition);

v1_flow_schema_condition_t *v1_flow_schema_condition_parseFromJSON(cJSON *v1_flow_schema_conditionJSON);

cJSON *v1_flow_schema_condition_convertToJSON(v1_flow_schema_condition_t *v1_flow_schema_condition);

#endif /* _v1_flow_schema_condition_H_ */

