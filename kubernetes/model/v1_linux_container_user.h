/*
 * v1_linux_container_user.h
 *
 * LinuxContainerUser represents user identity information in Linux containers
 */

#ifndef _v1_linux_container_user_H_
#define _v1_linux_container_user_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_linux_container_user_t v1_linux_container_user_t;




typedef struct v1_linux_container_user_t {
    long gid; //numeric
    list_t *supplemental_groups; //primitive container
    long uid; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} v1_linux_container_user_t;

__attribute__((deprecated)) v1_linux_container_user_t *v1_linux_container_user_create(
    long gid,
    list_t *supplemental_groups,
    long uid
);

void v1_linux_container_user_free(v1_linux_container_user_t *v1_linux_container_user);

v1_linux_container_user_t *v1_linux_container_user_parseFromJSON(cJSON *v1_linux_container_userJSON);

cJSON *v1_linux_container_user_convertToJSON(v1_linux_container_user_t *v1_linux_container_user);

#endif /* _v1_linux_container_user_H_ */

