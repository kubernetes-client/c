/*
 * v2beta1_api_version_discovery.h
 *
 * APIVersionDiscovery holds a list of APIResourceDiscovery types that are served for a particular version within an API Group.
 */

#ifndef _v2beta1_api_version_discovery_H_
#define _v2beta1_api_version_discovery_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2beta1_api_version_discovery_t v2beta1_api_version_discovery_t;

#include "v2beta1_api_resource_discovery.h"



typedef struct v2beta1_api_version_discovery_t {
    char *version; // string
    list_t *resources; //nonprimitive container
    char *freshness; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v2beta1_api_version_discovery_t;

__attribute__((deprecated)) v2beta1_api_version_discovery_t *v2beta1_api_version_discovery_create(
    char *version,
    list_t *resources,
    char *freshness
);

void v2beta1_api_version_discovery_free(v2beta1_api_version_discovery_t *v2beta1_api_version_discovery);

v2beta1_api_version_discovery_t *v2beta1_api_version_discovery_parseFromJSON(cJSON *v2beta1_api_version_discoveryJSON);

cJSON *v2beta1_api_version_discovery_convertToJSON(v2beta1_api_version_discovery_t *v2beta1_api_version_discovery);

#endif /* _v2beta1_api_version_discovery_H_ */

