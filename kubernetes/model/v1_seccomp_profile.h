/*
 * v1_seccomp_profile.h
 *
 * SeccompProfile defines a pod/container&#39;s seccomp profile settings. Only one profile source may be set.
 */

#ifndef _v1_seccomp_profile_H_
#define _v1_seccomp_profile_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_seccomp_profile_t v1_seccomp_profile_t;




typedef struct v1_seccomp_profile_t {
    char *localhost_profile; // string
    char *type; // string

} v1_seccomp_profile_t;

v1_seccomp_profile_t *v1_seccomp_profile_create(
    char *localhost_profile,
    char *type
);

void v1_seccomp_profile_free(v1_seccomp_profile_t *v1_seccomp_profile);

v1_seccomp_profile_t *v1_seccomp_profile_parseFromJSON(cJSON *v1_seccomp_profileJSON);

cJSON *v1_seccomp_profile_convertToJSON(v1_seccomp_profile_t *v1_seccomp_profile);

#endif /* _v1_seccomp_profile_H_ */

