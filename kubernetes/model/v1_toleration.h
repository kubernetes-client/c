/*
 * v1_toleration.h
 *
 * The pod this Toleration is attached to tolerates any taint that matches the triple &lt;key,value,effect&gt; using the matching operator &lt;operator&gt;.
 */

#ifndef _v1_toleration_H_
#define _v1_toleration_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_toleration_t v1_toleration_t;


// Enum EFFECT for v1_toleration

typedef enum  { kubernetes_v1_toleration_EFFECT_NULL = 0, kubernetes_v1_toleration_EFFECT_NoExecute, kubernetes_v1_toleration_EFFECT_NoSchedule, kubernetes_v1_toleration_EFFECT_PreferNoSchedule } kubernetes_v1_toleration_EFFECT_e;

char* v1_toleration_effect_ToString(kubernetes_v1_toleration_EFFECT_e effect);

kubernetes_v1_toleration_EFFECT_e v1_toleration_effect_FromString(char* effect);

// Enum OPERATOR for v1_toleration

typedef enum  { kubernetes_v1_toleration_OPERATOR_NULL = 0, kubernetes_v1_toleration_OPERATOR_Equal, kubernetes_v1_toleration_OPERATOR_Exists } kubernetes_v1_toleration_OPERATOR_e;

char* v1_toleration__operator_ToString(kubernetes_v1_toleration_OPERATOR_e _operator);

kubernetes_v1_toleration_OPERATOR_e v1_toleration__operator_FromString(char* _operator);



typedef struct v1_toleration_t {
    kubernetes_v1_toleration_EFFECT_e effect; //enum
    char *key; // string
    kubernetes_v1_toleration_OPERATOR_e _operator; //enum
    long toleration_seconds; //numeric
    char *value; // string

} v1_toleration_t;

v1_toleration_t *v1_toleration_create(
    kubernetes_v1_toleration_EFFECT_e effect,
    char *key,
    kubernetes_v1_toleration_OPERATOR_e _operator,
    long toleration_seconds,
    char *value
);

void v1_toleration_free(v1_toleration_t *v1_toleration);

v1_toleration_t *v1_toleration_parseFromJSON(cJSON *v1_tolerationJSON);

cJSON *v1_toleration_convertToJSON(v1_toleration_t *v1_toleration);

#endif /* _v1_toleration_H_ */

