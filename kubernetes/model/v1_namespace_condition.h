/*
 * v1_namespace_condition.h
 *
 * NamespaceCondition contains details about state of namespace.
 */

#ifndef _v1_namespace_condition_H_
#define _v1_namespace_condition_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_namespace_condition_t v1_namespace_condition_t;


// Enum TYPE for v1_namespace_condition

typedef enum  { kubernetes_v1_namespace_condition_TYPE_NULL = 0, kubernetes_v1_namespace_condition_TYPE_NamespaceContentRemaining, kubernetes_v1_namespace_condition_TYPE_NamespaceDeletionContentFailure, kubernetes_v1_namespace_condition_TYPE_NamespaceDeletionDiscoveryFailure, kubernetes_v1_namespace_condition_TYPE_NamespaceDeletionGroupVersionParsingFailure, kubernetes_v1_namespace_condition_TYPE_NamespaceFinalizersRemaining } kubernetes_v1_namespace_condition_TYPE_e;

char* v1_namespace_condition_type_ToString(kubernetes_v1_namespace_condition_TYPE_e type);

kubernetes_v1_namespace_condition_TYPE_e v1_namespace_condition_type_FromString(char* type);



typedef struct v1_namespace_condition_t {
    char *last_transition_time; //date time
    char *message; // string
    char *reason; // string
    char *status; // string
    kubernetes_v1_namespace_condition_TYPE_e type; //enum

} v1_namespace_condition_t;

v1_namespace_condition_t *v1_namespace_condition_create(
    char *last_transition_time,
    char *message,
    char *reason,
    char *status,
    kubernetes_v1_namespace_condition_TYPE_e type
);

void v1_namespace_condition_free(v1_namespace_condition_t *v1_namespace_condition);

v1_namespace_condition_t *v1_namespace_condition_parseFromJSON(cJSON *v1_namespace_conditionJSON);

cJSON *v1_namespace_condition_convertToJSON(v1_namespace_condition_t *v1_namespace_condition);

#endif /* _v1_namespace_condition_H_ */

