/*
 * v1_ephemeral_container.h
 *
 * An EphemeralContainer is a temporary container that you may add to an existing Pod for user-initiated activities such as debugging. Ephemeral containers have no resource or scheduling guarantees, and they will not be restarted when they exit or when a Pod is removed or restarted. The kubelet may evict a Pod if an ephemeral container causes the Pod to exceed its resource allocation.  To add an ephemeral container, use the ephemeralcontainers subresource of an existing Pod. Ephemeral containers may not be removed or restarted.  This is a beta feature available on clusters that haven&#39;t disabled the EphemeralContainers feature gate.
 */

#ifndef _v1_ephemeral_container_H_
#define _v1_ephemeral_container_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_ephemeral_container_t v1_ephemeral_container_t;

#include "v1_container_port.h"
#include "v1_env_from_source.h"
#include "v1_env_var.h"
#include "v1_lifecycle.h"
#include "v1_probe.h"
#include "v1_resource_requirements.h"
#include "v1_security_context.h"
#include "v1_volume_device.h"
#include "v1_volume_mount.h"

// Enum IMAGEPULLPOLICY for v1_ephemeral_container

typedef enum  { kubernetes_v1_ephemeral_container_IMAGEPULLPOLICY_NULL = 0, kubernetes_v1_ephemeral_container_IMAGEPULLPOLICY_Always, kubernetes_v1_ephemeral_container_IMAGEPULLPOLICY_IfNotPresent, kubernetes_v1_ephemeral_container_IMAGEPULLPOLICY_Never } kubernetes_v1_ephemeral_container_IMAGEPULLPOLICY_e;

char* v1_ephemeral_container_image_pull_policy_ToString(kubernetes_v1_ephemeral_container_IMAGEPULLPOLICY_e image_pull_policy);

kubernetes_v1_ephemeral_container_IMAGEPULLPOLICY_e v1_ephemeral_container_image_pull_policy_FromString(char* image_pull_policy);

// Enum TERMINATIONMESSAGEPOLICY for v1_ephemeral_container

typedef enum  { kubernetes_v1_ephemeral_container_TERMINATIONMESSAGEPOLICY_NULL = 0, kubernetes_v1_ephemeral_container_TERMINATIONMESSAGEPOLICY_FallbackToLogsOnError, kubernetes_v1_ephemeral_container_TERMINATIONMESSAGEPOLICY_File } kubernetes_v1_ephemeral_container_TERMINATIONMESSAGEPOLICY_e;

char* v1_ephemeral_container_termination_message_policy_ToString(kubernetes_v1_ephemeral_container_TERMINATIONMESSAGEPOLICY_e termination_message_policy);

kubernetes_v1_ephemeral_container_TERMINATIONMESSAGEPOLICY_e v1_ephemeral_container_termination_message_policy_FromString(char* termination_message_policy);



typedef struct v1_ephemeral_container_t {
    list_t *args; //primitive container
    list_t *command; //primitive container
    list_t *env; //nonprimitive container
    list_t *env_from; //nonprimitive container
    char *image; // string
    kubernetes_v1_ephemeral_container_IMAGEPULLPOLICY_e image_pull_policy; //enum
    struct v1_lifecycle_t *lifecycle; //model
    struct v1_probe_t *liveness_probe; //model
    char *name; // string
    list_t *ports; //nonprimitive container
    struct v1_probe_t *readiness_probe; //model
    struct v1_resource_requirements_t *resources; //model
    struct v1_security_context_t *security_context; //model
    struct v1_probe_t *startup_probe; //model
    int _stdin; //boolean
    int stdin_once; //boolean
    char *target_container_name; // string
    char *termination_message_path; // string
    kubernetes_v1_ephemeral_container_TERMINATIONMESSAGEPOLICY_e termination_message_policy; //enum
    int tty; //boolean
    list_t *volume_devices; //nonprimitive container
    list_t *volume_mounts; //nonprimitive container
    char *working_dir; // string

} v1_ephemeral_container_t;

v1_ephemeral_container_t *v1_ephemeral_container_create(
    list_t *args,
    list_t *command,
    list_t *env,
    list_t *env_from,
    char *image,
    kubernetes_v1_ephemeral_container_IMAGEPULLPOLICY_e image_pull_policy,
    v1_lifecycle_t *lifecycle,
    v1_probe_t *liveness_probe,
    char *name,
    list_t *ports,
    v1_probe_t *readiness_probe,
    v1_resource_requirements_t *resources,
    v1_security_context_t *security_context,
    v1_probe_t *startup_probe,
    int _stdin,
    int stdin_once,
    char *target_container_name,
    char *termination_message_path,
    kubernetes_v1_ephemeral_container_TERMINATIONMESSAGEPOLICY_e termination_message_policy,
    int tty,
    list_t *volume_devices,
    list_t *volume_mounts,
    char *working_dir
);

void v1_ephemeral_container_free(v1_ephemeral_container_t *v1_ephemeral_container);

v1_ephemeral_container_t *v1_ephemeral_container_parseFromJSON(cJSON *v1_ephemeral_containerJSON);

cJSON *v1_ephemeral_container_convertToJSON(v1_ephemeral_container_t *v1_ephemeral_container);

#endif /* _v1_ephemeral_container_H_ */

