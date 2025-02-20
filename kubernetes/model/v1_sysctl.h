/*
 * v1_sysctl.h
 *
 * Sysctl defines a kernel parameter to be set
 */

#ifndef _v1_sysctl_H_
#define _v1_sysctl_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_sysctl_t v1_sysctl_t;




typedef struct v1_sysctl_t {
    char *name; // string
    char *value; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_sysctl_t;

__attribute__((deprecated)) v1_sysctl_t *v1_sysctl_create(
    char *name,
    char *value
);

void v1_sysctl_free(v1_sysctl_t *v1_sysctl);

v1_sysctl_t *v1_sysctl_parseFromJSON(cJSON *v1_sysctlJSON);

cJSON *v1_sysctl_convertToJSON(v1_sysctl_t *v1_sysctl);

#endif /* _v1_sysctl_H_ */

