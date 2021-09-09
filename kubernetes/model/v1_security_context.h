/*
 * v1_security_context.h
 *
 * SecurityContext holds security configuration that will be applied to a container. Some fields are present in both SecurityContext and PodSecurityContext.  When both are set, the values in SecurityContext take precedence.
 */

#ifndef _v1_security_context_H_
#define _v1_security_context_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_security_context_t v1_security_context_t;

#include "v1_capabilities.h"
#include "v1_se_linux_options.h"
#include "v1_windows_security_context_options.h"



typedef struct v1_security_context_t {
    int allow_privilege_escalation; //boolean
    struct v1_capabilities_t *capabilities; //model
    int privileged; //boolean
    char *proc_mount; // string
    int read_only_root_filesystem; //boolean
    long run_as_group; //numeric
    int run_as_non_root; //boolean
    long run_as_user; //numeric
    struct v1_se_linux_options_t *se_linux_options; //model
    struct v1_windows_security_context_options_t *windows_options; //model

} v1_security_context_t;

v1_security_context_t *v1_security_context_create(
    int allow_privilege_escalation,
    v1_capabilities_t *capabilities,
    int privileged,
    char *proc_mount,
    int read_only_root_filesystem,
    long run_as_group,
    int run_as_non_root,
    long run_as_user,
    v1_se_linux_options_t *se_linux_options,
    v1_windows_security_context_options_t *windows_options
);

void v1_security_context_free(v1_security_context_t *v1_security_context);

v1_security_context_t *v1_security_context_parseFromJSON(cJSON *v1_security_contextJSON);

cJSON *v1_security_context_convertToJSON(v1_security_context_t *v1_security_context);

#endif /* _v1_security_context_H_ */

