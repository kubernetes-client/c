/*
 * v1_node_system_info.h
 *
 * NodeSystemInfo is a set of ids/uuids to uniquely identify the node.
 */

#ifndef _v1_node_system_info_H_
#define _v1_node_system_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_node_system_info_t v1_node_system_info_t;




typedef struct v1_node_system_info_t {
    char *architecture; // string
    char *boot_id; // string
    char *container_runtime_version; // string
    char *kernel_version; // string
    char *kube_proxy_version; // string
    char *kubelet_version; // string
    char *machine_id; // string
    char *operating_system; // string
    char *os_image; // string
    char *system_uuid; // string

} v1_node_system_info_t;

v1_node_system_info_t *v1_node_system_info_create(
    char *architecture,
    char *boot_id,
    char *container_runtime_version,
    char *kernel_version,
    char *kube_proxy_version,
    char *kubelet_version,
    char *machine_id,
    char *operating_system,
    char *os_image,
    char *system_uuid
);

void v1_node_system_info_free(v1_node_system_info_t *v1_node_system_info);

v1_node_system_info_t *v1_node_system_info_parseFromJSON(cJSON *v1_node_system_infoJSON);

cJSON *v1_node_system_info_convertToJSON(v1_node_system_info_t *v1_node_system_info);

#endif /* _v1_node_system_info_H_ */

