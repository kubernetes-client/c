/*
 * v1beta1_allowed_host_path.h
 *
 * AllowedHostPath defines the host volume conditions that will be enabled by a policy for pods to use. It requires the path prefix to be defined.
 */

#ifndef _v1beta1_allowed_host_path_H_
#define _v1beta1_allowed_host_path_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_allowed_host_path_t v1beta1_allowed_host_path_t;




typedef struct v1beta1_allowed_host_path_t {
    char *path_prefix; // string
    int read_only; //boolean

} v1beta1_allowed_host_path_t;

v1beta1_allowed_host_path_t *v1beta1_allowed_host_path_create(
    char *path_prefix,
    int read_only
);

void v1beta1_allowed_host_path_free(v1beta1_allowed_host_path_t *v1beta1_allowed_host_path);

v1beta1_allowed_host_path_t *v1beta1_allowed_host_path_parseFromJSON(cJSON *v1beta1_allowed_host_pathJSON);

cJSON *v1beta1_allowed_host_path_convertToJSON(v1beta1_allowed_host_path_t *v1beta1_allowed_host_path);

#endif /* _v1beta1_allowed_host_path_H_ */

