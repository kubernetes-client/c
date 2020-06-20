/*
 * v1_preconditions.h
 *
 * Preconditions must be fulfilled before an operation (update, delete, etc.) is carried out.
 */

#ifndef _v1_preconditions_H_
#define _v1_preconditions_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_preconditions_t v1_preconditions_t;




typedef struct v1_preconditions_t {
    char *resource_version; // string
    char *uid; // string

} v1_preconditions_t;

v1_preconditions_t *v1_preconditions_create(
    char *resource_version,
    char *uid
);

void v1_preconditions_free(v1_preconditions_t *v1_preconditions);

v1_preconditions_t *v1_preconditions_parseFromJSON(cJSON *v1_preconditionsJSON);

cJSON *v1_preconditions_convertToJSON(v1_preconditions_t *v1_preconditions);

#endif /* _v1_preconditions_H_ */

