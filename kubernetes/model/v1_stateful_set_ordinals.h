/*
 * v1_stateful_set_ordinals.h
 *
 * StatefulSetOrdinals describes the policy used for replica ordinal assignment in this StatefulSet.
 */

#ifndef _v1_stateful_set_ordinals_H_
#define _v1_stateful_set_ordinals_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_stateful_set_ordinals_t v1_stateful_set_ordinals_t;




typedef struct v1_stateful_set_ordinals_t {
    int start; //numeric

} v1_stateful_set_ordinals_t;

v1_stateful_set_ordinals_t *v1_stateful_set_ordinals_create(
    int start
);

void v1_stateful_set_ordinals_free(v1_stateful_set_ordinals_t *v1_stateful_set_ordinals);

v1_stateful_set_ordinals_t *v1_stateful_set_ordinals_parseFromJSON(cJSON *v1_stateful_set_ordinalsJSON);

cJSON *v1_stateful_set_ordinals_convertToJSON(v1_stateful_set_ordinals_t *v1_stateful_set_ordinals);

#endif /* _v1_stateful_set_ordinals_H_ */

