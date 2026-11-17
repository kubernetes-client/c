/*
 * v2_api_subresource_discovery.h
 *
 * APISubresourceDiscovery provides information about an API subresource for discovery.
 */

#ifndef _v2_api_subresource_discovery_H_
#define _v2_api_subresource_discovery_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2_api_subresource_discovery_t v2_api_subresource_discovery_t;

#include "v1_group_version_kind.h"



typedef struct v2_api_subresource_discovery_t {
    char *subresource; // string
    struct v1_group_version_kind_t *response_kind; //model
    list_t *accepted_types; //nonprimitive container
    list_t *verbs; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v2_api_subresource_discovery_t;

__attribute__((deprecated)) v2_api_subresource_discovery_t *v2_api_subresource_discovery_create(
    char *subresource,
    v1_group_version_kind_t *response_kind,
    list_t *accepted_types,
    list_t *verbs
);

void v2_api_subresource_discovery_free(v2_api_subresource_discovery_t *v2_api_subresource_discovery);

v2_api_subresource_discovery_t *v2_api_subresource_discovery_parseFromJSON(cJSON *v2_api_subresource_discoveryJSON);

cJSON *v2_api_subresource_discovery_convertToJSON(v2_api_subresource_discovery_t *v2_api_subresource_discovery);

#endif /* _v2_api_subresource_discovery_H_ */

