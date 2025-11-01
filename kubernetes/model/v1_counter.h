/*
 * v1_counter.h
 *
 * Counter describes a quantity associated with a device.
 */

#ifndef _v1_counter_H_
#define _v1_counter_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_counter_t v1_counter_t;




typedef struct v1_counter_t {
    char *value; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_counter_t;

__attribute__((deprecated)) v1_counter_t *v1_counter_create(
    char *value
);

void v1_counter_free(v1_counter_t *v1_counter);

v1_counter_t *v1_counter_parseFromJSON(cJSON *v1_counterJSON);

cJSON *v1_counter_convertToJSON(v1_counter_t *v1_counter);

#endif /* _v1_counter_H_ */

