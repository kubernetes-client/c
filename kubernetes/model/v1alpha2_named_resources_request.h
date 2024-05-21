/*
 * v1alpha2_named_resources_request.h
 *
 * NamedResourcesRequest is used in ResourceRequestModel.
 */

#ifndef _v1alpha2_named_resources_request_H_
#define _v1alpha2_named_resources_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha2_named_resources_request_t v1alpha2_named_resources_request_t;




typedef struct v1alpha2_named_resources_request_t {
    char *selector; // string

} v1alpha2_named_resources_request_t;

v1alpha2_named_resources_request_t *v1alpha2_named_resources_request_create(
    char *selector
);

void v1alpha2_named_resources_request_free(v1alpha2_named_resources_request_t *v1alpha2_named_resources_request);

v1alpha2_named_resources_request_t *v1alpha2_named_resources_request_parseFromJSON(cJSON *v1alpha2_named_resources_requestJSON);

cJSON *v1alpha2_named_resources_request_convertToJSON(v1alpha2_named_resources_request_t *v1alpha2_named_resources_request);

#endif /* _v1alpha2_named_resources_request_H_ */

