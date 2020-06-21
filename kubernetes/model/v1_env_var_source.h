/*
 * v1_env_var_source.h
 *
 * EnvVarSource represents a source for the value of an EnvVar.
 */

#ifndef _v1_env_var_source_H_
#define _v1_env_var_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_env_var_source_t v1_env_var_source_t;

#include "v1_config_map_key_selector.h"
#include "v1_object_field_selector.h"
#include "v1_resource_field_selector.h"
#include "v1_secret_key_selector.h"



typedef struct v1_env_var_source_t {
    struct v1_config_map_key_selector_t *config_map_key_ref; //model
    struct v1_object_field_selector_t *field_ref; //model
    struct v1_resource_field_selector_t *resource_field_ref; //model
    struct v1_secret_key_selector_t *secret_key_ref; //model

} v1_env_var_source_t;

v1_env_var_source_t *v1_env_var_source_create(
    v1_config_map_key_selector_t *config_map_key_ref,
    v1_object_field_selector_t *field_ref,
    v1_resource_field_selector_t *resource_field_ref,
    v1_secret_key_selector_t *secret_key_ref
);

void v1_env_var_source_free(v1_env_var_source_t *v1_env_var_source);

v1_env_var_source_t *v1_env_var_source_parseFromJSON(cJSON *v1_env_var_sourceJSON);

cJSON *v1_env_var_source_convertToJSON(v1_env_var_source_t *v1_env_var_source);

#endif /* _v1_env_var_source_H_ */

