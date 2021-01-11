/*
 * v1_api_versions.h
 *
 * APIVersions lists the versions that are available, to allow clients to discover the API at /api, which is the root path of the legacy v1 API.
 */

#ifndef _v1_api_versions_H_
#define _v1_api_versions_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_api_versions_t v1_api_versions_t;

#include "v1_server_address_by_client_cidr.h"



typedef struct v1_api_versions_t {
    char *api_version; // string
    char *kind; // string
    list_t *server_address_by_client_cidrs; //nonprimitive container
    list_t *versions; //primitive container

} v1_api_versions_t;

v1_api_versions_t *v1_api_versions_create(
    char *api_version,
    char *kind,
    list_t *server_address_by_client_cidrs,
    list_t *versions
);

void v1_api_versions_free(v1_api_versions_t *v1_api_versions);

v1_api_versions_t *v1_api_versions_parseFromJSON(cJSON *v1_api_versionsJSON);

cJSON *v1_api_versions_convertToJSON(v1_api_versions_t *v1_api_versions);

#endif /* _v1_api_versions_H_ */

