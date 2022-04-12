/*
 * v1_taint.h
 *
 * The node this Taint is attached to has the \&quot;effect\&quot; on any pod that does not tolerate the Taint.
 */

#ifndef _v1_taint_H_
#define _v1_taint_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_taint_t v1_taint_t;


// Enum EFFECT for v1_taint

typedef enum  { kubernetes_v1_taint_EFFECT_NULL = 0, kubernetes_v1_taint_EFFECT_NoExecute, kubernetes_v1_taint_EFFECT_NoSchedule, kubernetes_v1_taint_EFFECT_PreferNoSchedule } kubernetes_v1_taint_EFFECT_e;

char* v1_taint_effect_ToString(kubernetes_v1_taint_EFFECT_e effect);

kubernetes_v1_taint_EFFECT_e v1_taint_effect_FromString(char* effect);



typedef struct v1_taint_t {
    kubernetes_v1_taint_EFFECT_e effect; //enum
    char *key; // string
    char *time_added; //date time
    char *value; // string

} v1_taint_t;

v1_taint_t *v1_taint_create(
    kubernetes_v1_taint_EFFECT_e effect,
    char *key,
    char *time_added,
    char *value
);

void v1_taint_free(v1_taint_t *v1_taint);

v1_taint_t *v1_taint_parseFromJSON(cJSON *v1_taintJSON);

cJSON *v1_taint_convertToJSON(v1_taint_t *v1_taint);

#endif /* _v1_taint_H_ */

