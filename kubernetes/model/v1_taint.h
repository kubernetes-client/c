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




typedef struct v1_taint_t {
    char *effect; // string
    char *key; // string
    char *time_added; //date time
    char *value; // string

} v1_taint_t;

v1_taint_t *v1_taint_create(
    char *effect,
    char *key,
    char *time_added,
    char *value
);

void v1_taint_free(v1_taint_t *v1_taint);

v1_taint_t *v1_taint_parseFromJSON(cJSON *v1_taintJSON);

cJSON *v1_taint_convertToJSON(v1_taint_t *v1_taint);

#endif /* _v1_taint_H_ */

