/*
 * v1_pod_os.h
 *
 * PodOS defines the OS parameters of a pod.
 */

#ifndef _v1_pod_os_H_
#define _v1_pod_os_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_pod_os_t v1_pod_os_t;




typedef struct v1_pod_os_t {
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_pod_os_t;

__attribute__((deprecated)) v1_pod_os_t *v1_pod_os_create(
    char *name
);

void v1_pod_os_free(v1_pod_os_t *v1_pod_os);

v1_pod_os_t *v1_pod_os_parseFromJSON(cJSON *v1_pod_osJSON);

cJSON *v1_pod_os_convertToJSON(v1_pod_os_t *v1_pod_os);

#endif /* _v1_pod_os_H_ */

