/*
 * v1_resource_quota_status.h
 *
 * ResourceQuotaStatus defines the enforced hard limits and observed use.
 */

#ifndef _v1_resource_quota_status_H_
#define _v1_resource_quota_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_resource_quota_status_t v1_resource_quota_status_t;




typedef struct v1_resource_quota_status_t {
    list_t* hard; //map
    list_t* used; //map

    int _library_owned; // Is the library responsible for freeing this object?
} v1_resource_quota_status_t;

__attribute__((deprecated)) v1_resource_quota_status_t *v1_resource_quota_status_create(
    list_t* hard,
    list_t* used
);

void v1_resource_quota_status_free(v1_resource_quota_status_t *v1_resource_quota_status);

v1_resource_quota_status_t *v1_resource_quota_status_parseFromJSON(cJSON *v1_resource_quota_statusJSON);

cJSON *v1_resource_quota_status_convertToJSON(v1_resource_quota_status_t *v1_resource_quota_status);

#endif /* _v1_resource_quota_status_H_ */

