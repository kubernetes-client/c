/*
 * policy_v1beta1_allowed_host_path.h
 *
 * AllowedHostPath defines the host volume conditions that will be enabled by a policy for pods to use. It requires the path prefix to be defined.
 */

#ifndef _policy_v1beta1_allowed_host_path_H_
#define _policy_v1beta1_allowed_host_path_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct policy_v1beta1_allowed_host_path_t policy_v1beta1_allowed_host_path_t;




typedef struct policy_v1beta1_allowed_host_path_t {
    char *path_prefix; // string
    int read_only; //boolean

} policy_v1beta1_allowed_host_path_t;

policy_v1beta1_allowed_host_path_t *policy_v1beta1_allowed_host_path_create(
    char *path_prefix,
    int read_only
);

void policy_v1beta1_allowed_host_path_free(policy_v1beta1_allowed_host_path_t *policy_v1beta1_allowed_host_path);

policy_v1beta1_allowed_host_path_t *policy_v1beta1_allowed_host_path_parseFromJSON(cJSON *policy_v1beta1_allowed_host_pathJSON);

cJSON *policy_v1beta1_allowed_host_path_convertToJSON(policy_v1beta1_allowed_host_path_t *policy_v1beta1_allowed_host_path);

#endif /* _policy_v1beta1_allowed_host_path_H_ */

