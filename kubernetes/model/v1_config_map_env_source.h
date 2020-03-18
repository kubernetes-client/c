/*
 * v1_config_map_env_source.h
 *
 * ConfigMapEnvSource selects a ConfigMap to populate the environment variables with.  The contents of the target ConfigMap&#39;s Data field will represent the key-value pairs as environment variables.
 */

#ifndef _v1_config_map_env_source_H_
#define _v1_config_map_env_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_config_map_env_source_t {
    char *name; // string
    int optional; //boolean

} v1_config_map_env_source_t;

v1_config_map_env_source_t *v1_config_map_env_source_create(
    char *name,
    int optional
);

void v1_config_map_env_source_free(v1_config_map_env_source_t *v1_config_map_env_source);

v1_config_map_env_source_t *v1_config_map_env_source_parseFromJSON(cJSON *v1_config_map_env_sourceJSON);

cJSON *v1_config_map_env_source_convertToJSON(v1_config_map_env_source_t *v1_config_map_env_source);

#endif /* _v1_config_map_env_source_H_ */

