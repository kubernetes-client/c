/*
 * v1_scale_status.h
 *
 * ScaleStatus represents the current status of a scale subresource.
 */

#ifndef _v1_scale_status_H_
#define _v1_scale_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_scale_status_t v1_scale_status_t;




typedef struct v1_scale_status_t {
    int replicas; //numeric
    char *selector; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_scale_status_t;

__attribute__((deprecated)) v1_scale_status_t *v1_scale_status_create(
    int replicas,
    char *selector
);

void v1_scale_status_free(v1_scale_status_t *v1_scale_status);

v1_scale_status_t *v1_scale_status_parseFromJSON(cJSON *v1_scale_statusJSON);

cJSON *v1_scale_status_convertToJSON(v1_scale_status_t *v1_scale_status);

#endif /* _v1_scale_status_H_ */

