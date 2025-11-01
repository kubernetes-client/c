/*
 * v1_container_extended_resource_request.h
 *
 * ContainerExtendedResourceRequest has the mapping of container name, extended resource name to the device request name.
 */

#ifndef _v1_container_extended_resource_request_H_
#define _v1_container_extended_resource_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_container_extended_resource_request_t v1_container_extended_resource_request_t;




typedef struct v1_container_extended_resource_request_t {
    char *container_name; // string
    char *request_name; // string
    char *resource_name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_container_extended_resource_request_t;

__attribute__((deprecated)) v1_container_extended_resource_request_t *v1_container_extended_resource_request_create(
    char *container_name,
    char *request_name,
    char *resource_name
);

void v1_container_extended_resource_request_free(v1_container_extended_resource_request_t *v1_container_extended_resource_request);

v1_container_extended_resource_request_t *v1_container_extended_resource_request_parseFromJSON(cJSON *v1_container_extended_resource_requestJSON);

cJSON *v1_container_extended_resource_request_convertToJSON(v1_container_extended_resource_request_t *v1_container_extended_resource_request);

#endif /* _v1_container_extended_resource_request_H_ */

