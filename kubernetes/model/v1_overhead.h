/*
 * v1_overhead.h
 *
 * Overhead structure represents the resource overhead associated with running a pod.
 */

#ifndef _v1_overhead_H_
#define _v1_overhead_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_overhead_t v1_overhead_t;




typedef struct v1_overhead_t {
    list_t* pod_fixed; //map

} v1_overhead_t;

v1_overhead_t *v1_overhead_create(
    list_t* pod_fixed
);

void v1_overhead_free(v1_overhead_t *v1_overhead);

v1_overhead_t *v1_overhead_parseFromJSON(cJSON *v1_overheadJSON);

cJSON *v1_overhead_convertToJSON(v1_overhead_t *v1_overhead);

#endif /* _v1_overhead_H_ */

