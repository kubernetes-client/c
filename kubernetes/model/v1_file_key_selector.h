/*
 * v1_file_key_selector.h
 *
 * FileKeySelector selects a key of the env file.
 */

#ifndef _v1_file_key_selector_H_
#define _v1_file_key_selector_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_file_key_selector_t v1_file_key_selector_t;




typedef struct v1_file_key_selector_t {
    char *key; // string
    int optional; //boolean
    char *path; // string
    char *volume_name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_file_key_selector_t;

__attribute__((deprecated)) v1_file_key_selector_t *v1_file_key_selector_create(
    char *key,
    int optional,
    char *path,
    char *volume_name
);

void v1_file_key_selector_free(v1_file_key_selector_t *v1_file_key_selector);

v1_file_key_selector_t *v1_file_key_selector_parseFromJSON(cJSON *v1_file_key_selectorJSON);

cJSON *v1_file_key_selector_convertToJSON(v1_file_key_selector_t *v1_file_key_selector);

#endif /* _v1_file_key_selector_H_ */

