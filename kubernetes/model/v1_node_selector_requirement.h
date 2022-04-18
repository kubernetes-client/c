/*
 * v1_node_selector_requirement.h
 *
 * A node selector requirement is a selector that contains values, a key, and an operator that relates the key and values.
 */

#ifndef _v1_node_selector_requirement_H_
#define _v1_node_selector_requirement_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_node_selector_requirement_t v1_node_selector_requirement_t;


// Enum OPERATOR for v1_node_selector_requirement

typedef enum  { kubernetes_v1_node_selector_requirement_OPERATOR_NULL = 0, kubernetes_v1_node_selector_requirement_OPERATOR_DoesNotExist, kubernetes_v1_node_selector_requirement_OPERATOR_Exists, kubernetes_v1_node_selector_requirement_OPERATOR_Gt, kubernetes_v1_node_selector_requirement_OPERATOR_In, kubernetes_v1_node_selector_requirement_OPERATOR_Lt, kubernetes_v1_node_selector_requirement_OPERATOR_NotIn } kubernetes_v1_node_selector_requirement_OPERATOR_e;

char* v1_node_selector_requirement__operator_ToString(kubernetes_v1_node_selector_requirement_OPERATOR_e _operator);

kubernetes_v1_node_selector_requirement_OPERATOR_e v1_node_selector_requirement__operator_FromString(char* _operator);



typedef struct v1_node_selector_requirement_t {
    char *key; // string
    kubernetes_v1_node_selector_requirement_OPERATOR_e _operator; //enum
    list_t *values; //primitive container

} v1_node_selector_requirement_t;

v1_node_selector_requirement_t *v1_node_selector_requirement_create(
    char *key,
    kubernetes_v1_node_selector_requirement_OPERATOR_e _operator,
    list_t *values
);

void v1_node_selector_requirement_free(v1_node_selector_requirement_t *v1_node_selector_requirement);

v1_node_selector_requirement_t *v1_node_selector_requirement_parseFromJSON(cJSON *v1_node_selector_requirementJSON);

cJSON *v1_node_selector_requirement_convertToJSON(v1_node_selector_requirement_t *v1_node_selector_requirement);

#endif /* _v1_node_selector_requirement_H_ */

