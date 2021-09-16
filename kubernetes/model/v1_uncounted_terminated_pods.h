/*
 * v1_uncounted_terminated_pods.h
 *
 * UncountedTerminatedPods holds UIDs of Pods that have terminated but haven&#39;t been accounted in Job status counters.
 */

#ifndef _v1_uncounted_terminated_pods_H_
#define _v1_uncounted_terminated_pods_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_uncounted_terminated_pods_t v1_uncounted_terminated_pods_t;




typedef struct v1_uncounted_terminated_pods_t {
    list_t *failed; //primitive container
    list_t *succeeded; //primitive container

} v1_uncounted_terminated_pods_t;

v1_uncounted_terminated_pods_t *v1_uncounted_terminated_pods_create(
    list_t *failed,
    list_t *succeeded
);

void v1_uncounted_terminated_pods_free(v1_uncounted_terminated_pods_t *v1_uncounted_terminated_pods);

v1_uncounted_terminated_pods_t *v1_uncounted_terminated_pods_parseFromJSON(cJSON *v1_uncounted_terminated_podsJSON);

cJSON *v1_uncounted_terminated_pods_convertToJSON(v1_uncounted_terminated_pods_t *v1_uncounted_terminated_pods);

#endif /* _v1_uncounted_terminated_pods_H_ */

