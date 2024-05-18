/*
 * v1alpha2_named_resources_filter.h
 *
 * NamedResourcesFilter is used in ResourceFilterModel.
 */

#ifndef _v1alpha2_named_resources_filter_H_
#define _v1alpha2_named_resources_filter_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha2_named_resources_filter_t v1alpha2_named_resources_filter_t;




typedef struct v1alpha2_named_resources_filter_t {
    char *selector; // string

} v1alpha2_named_resources_filter_t;

v1alpha2_named_resources_filter_t *v1alpha2_named_resources_filter_create(
    char *selector
);

void v1alpha2_named_resources_filter_free(v1alpha2_named_resources_filter_t *v1alpha2_named_resources_filter);

v1alpha2_named_resources_filter_t *v1alpha2_named_resources_filter_parseFromJSON(cJSON *v1alpha2_named_resources_filterJSON);

cJSON *v1alpha2_named_resources_filter_convertToJSON(v1alpha2_named_resources_filter_t *v1alpha2_named_resources_filter);

#endif /* _v1alpha2_named_resources_filter_H_ */

