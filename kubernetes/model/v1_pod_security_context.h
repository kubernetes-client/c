/*
 * v1_pod_security_context.h
 *
 * PodSecurityContext holds pod-level security attributes and common container settings. Some fields are also present in container.securityContext.  Field values of container.securityContext take precedence over field values of PodSecurityContext.
 */

#ifndef _v1_pod_security_context_H_
#define _v1_pod_security_context_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_pod_security_context_t v1_pod_security_context_t;

#include "v1_app_armor_profile.h"
#include "v1_se_linux_options.h"
#include "v1_seccomp_profile.h"
#include "v1_sysctl.h"
#include "v1_windows_security_context_options.h"



typedef struct v1_pod_security_context_t {
    struct v1_app_armor_profile_t *app_armor_profile; //model
    long fs_group; //numeric
    char *fs_group_change_policy; // string
    long run_as_group; //numeric
    int run_as_non_root; //boolean
    long run_as_user; //numeric
    struct v1_se_linux_options_t *se_linux_options; //model
    struct v1_seccomp_profile_t *seccomp_profile; //model
    list_t *supplemental_groups; //primitive container
    char *supplemental_groups_policy; // string
    list_t *sysctls; //nonprimitive container
    struct v1_windows_security_context_options_t *windows_options; //model

} v1_pod_security_context_t;

v1_pod_security_context_t *v1_pod_security_context_create(
    v1_app_armor_profile_t *app_armor_profile,
    long fs_group,
    char *fs_group_change_policy,
    long run_as_group,
    int run_as_non_root,
    long run_as_user,
    v1_se_linux_options_t *se_linux_options,
    v1_seccomp_profile_t *seccomp_profile,
    list_t *supplemental_groups,
    char *supplemental_groups_policy,
    list_t *sysctls,
    v1_windows_security_context_options_t *windows_options
);

void v1_pod_security_context_free(v1_pod_security_context_t *v1_pod_security_context);

v1_pod_security_context_t *v1_pod_security_context_parseFromJSON(cJSON *v1_pod_security_contextJSON);

cJSON *v1_pod_security_context_convertToJSON(v1_pod_security_context_t *v1_pod_security_context);

#endif /* _v1_pod_security_context_H_ */

