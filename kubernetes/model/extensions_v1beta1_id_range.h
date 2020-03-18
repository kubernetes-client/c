/*
 * extensions_v1beta1_id_range.h
 *
 * IDRange provides a min/max of an allowed range of IDs. Deprecated: use IDRange from policy API Group instead.
 */

#ifndef _extensions_v1beta1_id_range_H_
#define _extensions_v1beta1_id_range_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct extensions_v1beta1_id_range_t {
    long max; //numeric
    long min; //numeric

} extensions_v1beta1_id_range_t;

extensions_v1beta1_id_range_t *extensions_v1beta1_id_range_create(
    long max,
    long min
);

void extensions_v1beta1_id_range_free(extensions_v1beta1_id_range_t *extensions_v1beta1_id_range);

extensions_v1beta1_id_range_t *extensions_v1beta1_id_range_parseFromJSON(cJSON *extensions_v1beta1_id_rangeJSON);

cJSON *extensions_v1beta1_id_range_convertToJSON(extensions_v1beta1_id_range_t *extensions_v1beta1_id_range);

#endif /* _extensions_v1beta1_id_range_H_ */

