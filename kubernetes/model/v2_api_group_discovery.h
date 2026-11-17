/*
 * v2_api_group_discovery.h
 *
 * APIGroupDiscovery holds information about which resources are being served for all version of the API Group. It contains a list of APIVersionDiscovery that holds a list of APIResourceDiscovery types served for a version. Versions are in descending order of preference, with the first version being the preferred entry.
 */

#ifndef _v2_api_group_discovery_H_
#define _v2_api_group_discovery_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2_api_group_discovery_t v2_api_group_discovery_t;

#include "v1_object_meta.h"
#include "v2_api_version_discovery.h"



typedef struct v2_api_group_discovery_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    list_t *versions; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v2_api_group_discovery_t;

__attribute__((deprecated)) v2_api_group_discovery_t *v2_api_group_discovery_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *versions
);

void v2_api_group_discovery_free(v2_api_group_discovery_t *v2_api_group_discovery);

v2_api_group_discovery_t *v2_api_group_discovery_parseFromJSON(cJSON *v2_api_group_discoveryJSON);

cJSON *v2_api_group_discovery_convertToJSON(v2_api_group_discovery_t *v2_api_group_discovery);

#endif /* _v2_api_group_discovery_H_ */

