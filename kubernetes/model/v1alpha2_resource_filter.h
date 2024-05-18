/*
 * v1alpha2_resource_filter.h
 *
 * ResourceFilter is a filter for resources from one particular driver.
 */

#ifndef _v1alpha2_resource_filter_H_
#define _v1alpha2_resource_filter_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha2_resource_filter_t v1alpha2_resource_filter_t;

#include "v1alpha2_named_resources_filter.h"



typedef struct v1alpha2_resource_filter_t {
    char *driver_name; // string
    struct v1alpha2_named_resources_filter_t *named_resources; //model

} v1alpha2_resource_filter_t;

v1alpha2_resource_filter_t *v1alpha2_resource_filter_create(
    char *driver_name,
    v1alpha2_named_resources_filter_t *named_resources
);

void v1alpha2_resource_filter_free(v1alpha2_resource_filter_t *v1alpha2_resource_filter);

v1alpha2_resource_filter_t *v1alpha2_resource_filter_parseFromJSON(cJSON *v1alpha2_resource_filterJSON);

cJSON *v1alpha2_resource_filter_convertToJSON(v1alpha2_resource_filter_t *v1alpha2_resource_filter);

#endif /* _v1alpha2_resource_filter_H_ */

