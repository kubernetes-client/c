/*
 * v1_container_user.h
 *
 * ContainerUser represents user identity information
 */

#ifndef _v1_container_user_H_
#define _v1_container_user_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_container_user_t v1_container_user_t;

#include "v1_linux_container_user.h"



typedef struct v1_container_user_t {
    struct v1_linux_container_user_t *_linux; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1_container_user_t;

__attribute__((deprecated)) v1_container_user_t *v1_container_user_create(
    v1_linux_container_user_t *_linux
);

void v1_container_user_free(v1_container_user_t *v1_container_user);

v1_container_user_t *v1_container_user_parseFromJSON(cJSON *v1_container_userJSON);

cJSON *v1_container_user_convertToJSON(v1_container_user_t *v1_container_user);

#endif /* _v1_container_user_H_ */

