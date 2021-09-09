/*
 * v1_limit_range.h
 *
 * LimitRange sets resource usage limits for each kind of resource in a Namespace.
 */

#ifndef _v1_limit_range_H_
#define _v1_limit_range_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_limit_range_t v1_limit_range_t;

#include "v1_limit_range_spec.h"
#include "v1_object_meta.h"



typedef struct v1_limit_range_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1_limit_range_spec_t *spec; //model

} v1_limit_range_t;

v1_limit_range_t *v1_limit_range_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_limit_range_spec_t *spec
);

void v1_limit_range_free(v1_limit_range_t *v1_limit_range);

v1_limit_range_t *v1_limit_range_parseFromJSON(cJSON *v1_limit_rangeJSON);

cJSON *v1_limit_range_convertToJSON(v1_limit_range_t *v1_limit_range);

#endif /* _v1_limit_range_H_ */

