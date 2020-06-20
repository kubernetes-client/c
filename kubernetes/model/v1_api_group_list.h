/*
 * v1_api_group_list.h
 *
 * APIGroupList is a list of APIGroup, to allow clients to discover the API at /apis.
 */

#ifndef _v1_api_group_list_H_
#define _v1_api_group_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_api_group_list_t v1_api_group_list_t;

#include "v1_api_group.h"



typedef struct v1_api_group_list_t {
    char *api_version; // string
    list_t *groups; //nonprimitive container
    char *kind; // string

} v1_api_group_list_t;

v1_api_group_list_t *v1_api_group_list_create(
    char *api_version,
    list_t *groups,
    char *kind
);

void v1_api_group_list_free(v1_api_group_list_t *v1_api_group_list);

v1_api_group_list_t *v1_api_group_list_parseFromJSON(cJSON *v1_api_group_listJSON);

cJSON *v1_api_group_list_convertToJSON(v1_api_group_list_t *v1_api_group_list);

#endif /* _v1_api_group_list_H_ */

