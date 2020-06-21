/*
 * v1_group_version_for_discovery.h
 *
 * GroupVersion contains the \&quot;group/version\&quot; and \&quot;version\&quot; string of a version. It is made a struct to keep extensibility.
 */

#ifndef _v1_group_version_for_discovery_H_
#define _v1_group_version_for_discovery_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_group_version_for_discovery_t v1_group_version_for_discovery_t;




typedef struct v1_group_version_for_discovery_t {
    char *group_version; // string
    char *version; // string

} v1_group_version_for_discovery_t;

v1_group_version_for_discovery_t *v1_group_version_for_discovery_create(
    char *group_version,
    char *version
);

void v1_group_version_for_discovery_free(v1_group_version_for_discovery_t *v1_group_version_for_discovery);

v1_group_version_for_discovery_t *v1_group_version_for_discovery_parseFromJSON(cJSON *v1_group_version_for_discoveryJSON);

cJSON *v1_group_version_for_discovery_convertToJSON(v1_group_version_for_discovery_t *v1_group_version_for_discovery);

#endif /* _v1_group_version_for_discovery_H_ */

