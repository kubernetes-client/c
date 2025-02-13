/*
 * v1_scale_spec.h
 *
 * ScaleSpec describes the attributes of a scale subresource.
 */

#ifndef _v1_scale_spec_H_
#define _v1_scale_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_scale_spec_t v1_scale_spec_t;




typedef struct v1_scale_spec_t {
    int replicas; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} v1_scale_spec_t;

__attribute__((deprecated)) v1_scale_spec_t *v1_scale_spec_create(
    int replicas
);

void v1_scale_spec_free(v1_scale_spec_t *v1_scale_spec);

v1_scale_spec_t *v1_scale_spec_parseFromJSON(cJSON *v1_scale_specJSON);

cJSON *v1_scale_spec_convertToJSON(v1_scale_spec_t *v1_scale_spec);

#endif /* _v1_scale_spec_H_ */

