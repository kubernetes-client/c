/*
 * v1beta1_id_range.h
 *
 * IDRange provides a min/max of an allowed range of IDs.
 */

#ifndef _v1beta1_id_range_H_
#define _v1beta1_id_range_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_id_range_t v1beta1_id_range_t;




typedef struct v1beta1_id_range_t {
    long max; //numeric
    long min; //numeric

} v1beta1_id_range_t;

v1beta1_id_range_t *v1beta1_id_range_create(
    long max,
    long min
);

void v1beta1_id_range_free(v1beta1_id_range_t *v1beta1_id_range);

v1beta1_id_range_t *v1beta1_id_range_parseFromJSON(cJSON *v1beta1_id_rangeJSON);

cJSON *v1beta1_id_range_convertToJSON(v1beta1_id_range_t *v1beta1_id_range);

#endif /* _v1beta1_id_range_H_ */

