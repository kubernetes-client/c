/*
 * v1_env_from_source.h
 *
 * EnvFromSource represents the source of a set of ConfigMaps
 */

#ifndef _v1_env_from_source_H_
#define _v1_env_from_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_env_from_source_t v1_env_from_source_t;

#include "v1_config_map_env_source.h"
#include "v1_secret_env_source.h"



typedef struct v1_env_from_source_t {
    struct v1_config_map_env_source_t *config_map_ref; //model
    char *prefix; // string
    struct v1_secret_env_source_t *secret_ref; //model

} v1_env_from_source_t;

v1_env_from_source_t *v1_env_from_source_create(
    v1_config_map_env_source_t *config_map_ref,
    char *prefix,
    v1_secret_env_source_t *secret_ref
);

void v1_env_from_source_free(v1_env_from_source_t *v1_env_from_source);

v1_env_from_source_t *v1_env_from_source_parseFromJSON(cJSON *v1_env_from_sourceJSON);

cJSON *v1_env_from_source_convertToJSON(v1_env_from_source_t *v1_env_from_source);

#endif /* _v1_env_from_source_H_ */

