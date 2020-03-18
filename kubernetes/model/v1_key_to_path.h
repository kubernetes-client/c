/*
 * v1_key_to_path.h
 *
 * Maps a string key to a path within a volume.
 */

#ifndef _v1_key_to_path_H_
#define _v1_key_to_path_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_key_to_path_t {
    char *key; // string
    int mode; //numeric
    char *path; // string

} v1_key_to_path_t;

v1_key_to_path_t *v1_key_to_path_create(
    char *key,
    int mode,
    char *path
);

void v1_key_to_path_free(v1_key_to_path_t *v1_key_to_path);

v1_key_to_path_t *v1_key_to_path_parseFromJSON(cJSON *v1_key_to_pathJSON);

cJSON *v1_key_to_path_convertToJSON(v1_key_to_path_t *v1_key_to_path);

#endif /* _v1_key_to_path_H_ */

