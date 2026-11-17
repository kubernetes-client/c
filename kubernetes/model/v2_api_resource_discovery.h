/*
 * v2_api_resource_discovery.h
 *
 * APIResourceDiscovery provides information about an API resource for discovery.
 */

#ifndef _v2_api_resource_discovery_H_
#define _v2_api_resource_discovery_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2_api_resource_discovery_t v2_api_resource_discovery_t;

#include "v1_group_version_kind.h"
#include "v2_api_subresource_discovery.h"



typedef struct v2_api_resource_discovery_t {
    char *resource; // string
    struct v1_group_version_kind_t *response_kind; //model
    char *scope; // string
    char *singular_resource; // string
    list_t *verbs; //primitive container
    list_t *short_names; //primitive container
    list_t *categories; //primitive container
    list_t *subresources; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v2_api_resource_discovery_t;

__attribute__((deprecated)) v2_api_resource_discovery_t *v2_api_resource_discovery_create(
    char *resource,
    v1_group_version_kind_t *response_kind,
    char *scope,
    char *singular_resource,
    list_t *verbs,
    list_t *short_names,
    list_t *categories,
    list_t *subresources
);

void v2_api_resource_discovery_free(v2_api_resource_discovery_t *v2_api_resource_discovery);

v2_api_resource_discovery_t *v2_api_resource_discovery_parseFromJSON(cJSON *v2_api_resource_discoveryJSON);

cJSON *v2_api_resource_discovery_convertToJSON(v2_api_resource_discovery_t *v2_api_resource_discovery);

#endif /* _v2_api_resource_discovery_H_ */

