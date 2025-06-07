/*
 * v1beta1_counter.h
 *
 * Counter describes a quantity associated with a device.
 */

#ifndef _v1beta1_counter_H_
#define _v1beta1_counter_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_counter_t v1beta1_counter_t;




typedef struct v1beta1_counter_t {
    char *value; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_counter_t;

__attribute__((deprecated)) v1beta1_counter_t *v1beta1_counter_create(
    char *value
);

void v1beta1_counter_free(v1beta1_counter_t *v1beta1_counter);

v1beta1_counter_t *v1beta1_counter_parseFromJSON(cJSON *v1beta1_counterJSON);

cJSON *v1beta1_counter_convertToJSON(v1beta1_counter_t *v1beta1_counter);

#endif /* _v1beta1_counter_H_ */

