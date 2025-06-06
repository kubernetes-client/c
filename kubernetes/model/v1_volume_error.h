/*
 * v1_volume_error.h
 *
 * VolumeError captures an error encountered during a volume operation.
 */

#ifndef _v1_volume_error_H_
#define _v1_volume_error_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_volume_error_t v1_volume_error_t;




typedef struct v1_volume_error_t {
    int error_code; //numeric
    char *message; // string
    char *time; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} v1_volume_error_t;

__attribute__((deprecated)) v1_volume_error_t *v1_volume_error_create(
    int error_code,
    char *message,
    char *time
);

void v1_volume_error_free(v1_volume_error_t *v1_volume_error);

v1_volume_error_t *v1_volume_error_parseFromJSON(cJSON *v1_volume_errorJSON);

cJSON *v1_volume_error_convertToJSON(v1_volume_error_t *v1_volume_error);

#endif /* _v1_volume_error_H_ */

