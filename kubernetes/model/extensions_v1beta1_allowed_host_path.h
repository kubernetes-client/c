/*
 * extensions_v1beta1_allowed_host_path.h
 *
 * AllowedHostPath defines the host volume conditions that will be enabled by a policy for pods to use. It requires the path prefix to be defined. Deprecated: use AllowedHostPath from policy API Group instead.
 */

#ifndef _extensions_v1beta1_allowed_host_path_H_
#define _extensions_v1beta1_allowed_host_path_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct extensions_v1beta1_allowed_host_path_t extensions_v1beta1_allowed_host_path_t;




typedef struct extensions_v1beta1_allowed_host_path_t {
    char *path_prefix; // string
    int read_only; //boolean

} extensions_v1beta1_allowed_host_path_t;

extensions_v1beta1_allowed_host_path_t *extensions_v1beta1_allowed_host_path_create(
    char *path_prefix,
    int read_only
);

void extensions_v1beta1_allowed_host_path_free(extensions_v1beta1_allowed_host_path_t *extensions_v1beta1_allowed_host_path);

extensions_v1beta1_allowed_host_path_t *extensions_v1beta1_allowed_host_path_parseFromJSON(cJSON *extensions_v1beta1_allowed_host_pathJSON);

cJSON *extensions_v1beta1_allowed_host_path_convertToJSON(extensions_v1beta1_allowed_host_path_t *extensions_v1beta1_allowed_host_path);

#endif /* _extensions_v1beta1_allowed_host_path_H_ */

