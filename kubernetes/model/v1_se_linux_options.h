/*
 * v1_se_linux_options.h
 *
 * SELinuxOptions are the labels to be applied to the container
 */

#ifndef _v1_se_linux_options_H_
#define _v1_se_linux_options_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_se_linux_options_t {
    char *level; // string
    char *role; // string
    char *type; // string
    char *user; // string

} v1_se_linux_options_t;

v1_se_linux_options_t *v1_se_linux_options_create(
    char *level,
    char *role,
    char *type,
    char *user
);

void v1_se_linux_options_free(v1_se_linux_options_t *v1_se_linux_options);

v1_se_linux_options_t *v1_se_linux_options_parseFromJSON(cJSON *v1_se_linux_optionsJSON);

cJSON *v1_se_linux_options_convertToJSON(v1_se_linux_options_t *v1_se_linux_options);

#endif /* _v1_se_linux_options_H_ */

