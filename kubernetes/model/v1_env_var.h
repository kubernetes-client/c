/*
 * v1_env_var.h
 *
 * EnvVar represents an environment variable present in a Container.
 */

#ifndef _v1_env_var_H_
#define _v1_env_var_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_env_var_t v1_env_var_t;

#include "v1_env_var_source.h"



typedef struct v1_env_var_t {
    char *name; // string
    char *value; // string
    struct v1_env_var_source_t *value_from; //model

} v1_env_var_t;

v1_env_var_t *v1_env_var_create(
    char *name,
    char *value,
    v1_env_var_source_t *value_from
);

void v1_env_var_free(v1_env_var_t *v1_env_var);

v1_env_var_t *v1_env_var_parseFromJSON(cJSON *v1_env_varJSON);

cJSON *v1_env_var_convertToJSON(v1_env_var_t *v1_env_var);

#endif /* _v1_env_var_H_ */

