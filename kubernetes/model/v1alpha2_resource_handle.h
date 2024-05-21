/*
 * v1alpha2_resource_handle.h
 *
 * ResourceHandle holds opaque resource data for processing by a specific kubelet plugin.
 */

#ifndef _v1alpha2_resource_handle_H_
#define _v1alpha2_resource_handle_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha2_resource_handle_t v1alpha2_resource_handle_t;

#include "v1alpha2_structured_resource_handle.h"



typedef struct v1alpha2_resource_handle_t {
    char *data; // string
    char *driver_name; // string
    struct v1alpha2_structured_resource_handle_t *structured_data; //model

} v1alpha2_resource_handle_t;

v1alpha2_resource_handle_t *v1alpha2_resource_handle_create(
    char *data,
    char *driver_name,
    v1alpha2_structured_resource_handle_t *structured_data
);

void v1alpha2_resource_handle_free(v1alpha2_resource_handle_t *v1alpha2_resource_handle);

v1alpha2_resource_handle_t *v1alpha2_resource_handle_parseFromJSON(cJSON *v1alpha2_resource_handleJSON);

cJSON *v1alpha2_resource_handle_convertToJSON(v1alpha2_resource_handle_t *v1alpha2_resource_handle);

#endif /* _v1alpha2_resource_handle_H_ */

