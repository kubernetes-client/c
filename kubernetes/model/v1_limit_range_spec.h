/*
 * v1_limit_range_spec.h
 *
 * LimitRangeSpec defines a min/max usage limit for resources that match on kind.
 */

#ifndef _v1_limit_range_spec_H_
#define _v1_limit_range_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_limit_range_item.h"



typedef struct v1_limit_range_spec_t {
    list_t *limits; //nonprimitive container

} v1_limit_range_spec_t;

v1_limit_range_spec_t *v1_limit_range_spec_create(
    list_t *limits
);

void v1_limit_range_spec_free(v1_limit_range_spec_t *v1_limit_range_spec);

v1_limit_range_spec_t *v1_limit_range_spec_parseFromJSON(cJSON *v1_limit_range_specJSON);

cJSON *v1_limit_range_spec_convertToJSON(v1_limit_range_spec_t *v1_limit_range_spec);

#endif /* _v1_limit_range_spec_H_ */

