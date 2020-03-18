/*
 * v1_host_alias.h
 *
 * HostAlias holds the mapping between IP and hostnames that will be injected as an entry in the pod&#39;s hosts file.
 */

#ifndef _v1_host_alias_H_
#define _v1_host_alias_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_host_alias_t {
    list_t *hostnames; //primitive container
    char *ip; // string

} v1_host_alias_t;

v1_host_alias_t *v1_host_alias_create(
    list_t *hostnames,
    char *ip
);

void v1_host_alias_free(v1_host_alias_t *v1_host_alias);

v1_host_alias_t *v1_host_alias_parseFromJSON(cJSON *v1_host_aliasJSON);

cJSON *v1_host_alias_convertToJSON(v1_host_alias_t *v1_host_alias);

#endif /* _v1_host_alias_H_ */

