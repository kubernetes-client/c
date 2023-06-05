/*
 * v1_container_resize_policy.h
 *
 * ContainerResizePolicy represents resource resize policy for the container.
 */

#ifndef _v1_container_resize_policy_H_
#define _v1_container_resize_policy_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_container_resize_policy_t v1_container_resize_policy_t;




typedef struct v1_container_resize_policy_t {
    char *resource_name; // string
    char *restart_policy; // string

} v1_container_resize_policy_t;

v1_container_resize_policy_t *v1_container_resize_policy_create(
    char *resource_name,
    char *restart_policy
);

void v1_container_resize_policy_free(v1_container_resize_policy_t *v1_container_resize_policy);

v1_container_resize_policy_t *v1_container_resize_policy_parseFromJSON(cJSON *v1_container_resize_policyJSON);

cJSON *v1_container_resize_policy_convertToJSON(v1_container_resize_policy_t *v1_container_resize_policy);

#endif /* _v1_container_resize_policy_H_ */

