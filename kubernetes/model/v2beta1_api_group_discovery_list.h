/*
 * v2beta1_api_group_discovery_list.h
 *
 * APIGroupDiscoveryList is a resource containing a list of APIGroupDiscovery. This is one of the types able to be returned from the /api and /apis endpoint and contains an aggregated list of API resources (built-ins, Custom Resource Definitions, resources from aggregated servers) that a cluster supports.
 */

#ifndef _v2beta1_api_group_discovery_list_H_
#define _v2beta1_api_group_discovery_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2beta1_api_group_discovery_list_t v2beta1_api_group_discovery_list_t;

#include "v1_list_meta.h"
#include "v2beta1_api_group_discovery.h"



typedef struct v2beta1_api_group_discovery_list_t {
    char *api_version; // string
    char *kind; // string
    struct v1_list_meta_t *metadata; //model
    list_t *items; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v2beta1_api_group_discovery_list_t;

__attribute__((deprecated)) v2beta1_api_group_discovery_list_t *v2beta1_api_group_discovery_list_create(
    char *api_version,
    char *kind,
    v1_list_meta_t *metadata,
    list_t *items
);

void v2beta1_api_group_discovery_list_free(v2beta1_api_group_discovery_list_t *v2beta1_api_group_discovery_list);

v2beta1_api_group_discovery_list_t *v2beta1_api_group_discovery_list_parseFromJSON(cJSON *v2beta1_api_group_discovery_listJSON);

cJSON *v2beta1_api_group_discovery_list_convertToJSON(v2beta1_api_group_discovery_list_t *v2beta1_api_group_discovery_list);

#endif /* _v2beta1_api_group_discovery_list_H_ */

