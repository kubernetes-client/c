/*
 * extensions_v1beta1_scale_spec.h
 *
 * describes the attributes of a scale subresource
 */

#ifndef _extensions_v1beta1_scale_spec_H_
#define _extensions_v1beta1_scale_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct extensions_v1beta1_scale_spec_t {
    int replicas; //numeric

} extensions_v1beta1_scale_spec_t;

extensions_v1beta1_scale_spec_t *extensions_v1beta1_scale_spec_create(
    int replicas
);

void extensions_v1beta1_scale_spec_free(extensions_v1beta1_scale_spec_t *extensions_v1beta1_scale_spec);

extensions_v1beta1_scale_spec_t *extensions_v1beta1_scale_spec_parseFromJSON(cJSON *extensions_v1beta1_scale_specJSON);

cJSON *extensions_v1beta1_scale_spec_convertToJSON(extensions_v1beta1_scale_spec_t *extensions_v1beta1_scale_spec);

#endif /* _extensions_v1beta1_scale_spec_H_ */

