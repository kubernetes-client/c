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


// Enum TYPE for v1_seccomp_profile

typedef enum  { kubernetes_v1_seccomp_profile_TYPE_NULL = 0, kubernetes_v1_seccomp_profile_TYPE_Localhost, kubernetes_v1_seccomp_profile_TYPE_RuntimeDefault, kubernetes_v1_seccomp_profile_TYPE_Unconfined } kubernetes_v1_seccomp_profile_TYPE_e;

char* v1_seccomp_profile_type_ToString(kubernetes_v1_seccomp_profile_TYPE_e type);

kubernetes_v1_seccomp_profile_TYPE_e v1_seccomp_profile_type_FromString(char* type);



typedef struct v1_seccomp_profile_t {
    char *localhost_profile; // string
    kubernetes_v1_seccomp_profile_TYPE_e type; //enum

} v1_seccomp_profile_t;

v1_seccomp_profile_t *v1_seccomp_profile_create(
    char *localhost_profile,
    kubernetes_v1_seccomp_profile_TYPE_e type
);

void v1_seccomp_profile_free(v1_seccomp_profile_t *v1_seccomp_profile);

v1_seccomp_profile_t *v1_seccomp_profile_parseFromJSON(cJSON *v1_seccomp_profileJSON);

cJSON *v1_seccomp_profile_convertToJSON(v1_seccomp_profile_t *v1_seccomp_profile);

#endif /* _v1_seccomp_profile_H_ */

