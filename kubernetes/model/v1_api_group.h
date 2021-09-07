/*
 * v1_api_group.h
 *
 * APIGroup contains the name, the supported versions, and the preferred version of a group.
 */

#ifndef _v1_api_group_H_
#define _v1_api_group_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_api_group_t v1_api_group_t;

#include "v1_group_version_for_discovery.h"
#include "v1_server_address_by_client_cidr.h"



typedef struct v1_api_group_t {
    char *api_version; // string
    char *kind; // string
    char *name; // string
    struct v1_group_version_for_discovery_t *preferred_version; //model
    list_t *server_address_by_client_cidrs; //nonprimitive container
    list_t *versions; //nonprimitive container

} v1_api_group_t;

v1_api_group_t *v1_api_group_create(
    char *api_version,
    char *kind,
    char *name,
    v1_group_version_for_discovery_t *preferred_version,
    list_t *server_address_by_client_cidrs,
    list_t *versions
);

void v1_api_group_free(v1_api_group_t *v1_api_group);

v1_api_group_t *v1_api_group_parseFromJSON(cJSON *v1_api_groupJSON);

cJSON *v1_api_group_convertToJSON(v1_api_group_t *v1_api_group);

#endif /* _v1_api_group_H_ */

