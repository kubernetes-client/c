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

#include "v1_se_linux_options.h"
#include "v1_sysctl.h"
#include "v1_windows_security_context_options.h"



typedef struct v1_pod_security_context_t {
    long fs_group; //numeric
    long run_as_group; //numeric
    int run_as_non_root; //boolean
    long run_as_user; //numeric
    struct v1_se_linux_options_t *se_linux_options; //model
    list_t *supplemental_groups; //primitive container
    list_t *sysctls; //nonprimitive container
    struct v1_windows_security_context_options_t *windows_options; //model

} v1_pod_security_context_t;

v1_pod_security_context_t *v1_pod_security_context_create(
    long fs_group,
    long run_as_group,
    int run_as_non_root,
    long run_as_user,
    v1_se_linux_options_t *se_linux_options,
    list_t *supplemental_groups,
    list_t *sysctls,
    v1_windows_security_context_options_t *windows_options
);

void v1_pod_security_context_free(v1_pod_security_context_t *v1_pod_security_context);

v1_pod_security_context_t *v1_pod_security_context_parseFromJSON(cJSON *v1_pod_security_contextJSON);

cJSON *v1_pod_security_context_convertToJSON(v1_pod_security_context_t *v1_pod_security_context);

#endif /* _v1_pod_security_context_H_ */

