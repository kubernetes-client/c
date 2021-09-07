/*
 * v1alpha1_flow_schema_status.h
 *
 * FlowSchemaStatus represents the current state of a FlowSchema.
 */

#ifndef _v1alpha1_flow_schema_status_H_
#define _v1alpha1_flow_schema_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_flow_schema_status_t v1alpha1_flow_schema_status_t;

#include "v1alpha1_flow_schema_condition.h"



typedef struct v1alpha1_flow_schema_status_t {
    list_t *conditions; //nonprimitive container

} v1alpha1_flow_schema_status_t;

v1alpha1_flow_schema_status_t *v1alpha1_flow_schema_status_create(
    list_t *conditions
);

void v1alpha1_flow_schema_status_free(v1alpha1_flow_schema_status_t *v1alpha1_flow_schema_status);

v1alpha1_flow_schema_status_t *v1alpha1_flow_schema_status_parseFromJSON(cJSON *v1alpha1_flow_schema_statusJSON);

cJSON *v1alpha1_flow_schema_status_convertToJSON(v1alpha1_flow_schema_status_t *v1alpha1_flow_schema_status);

#endif /* _v1alpha1_flow_schema_status_H_ */

