/*
 * v1_resource_quota.h
 *
 * ResourceQuota sets aggregate quota restrictions enforced per namespace
 */

#ifndef _v1_resource_quota_H_
#define _v1_resource_quota_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_resource_quota_t v1_resource_quota_t;

#include "v1_object_meta.h"
#include "v1_resource_quota_spec.h"
#include "v1_resource_quota_status.h"



typedef struct v1_resource_quota_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1_resource_quota_spec_t *spec; //model
    struct v1_resource_quota_status_t *status; //model

} v1_resource_quota_t;

v1_resource_quota_t *v1_resource_quota_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_resource_quota_spec_t *spec,
    v1_resource_quota_status_t *status
);

void v1_resource_quota_free(v1_resource_quota_t *v1_resource_quota);

v1_resource_quota_t *v1_resource_quota_parseFromJSON(cJSON *v1_resource_quotaJSON);

cJSON *v1_resource_quota_convertToJSON(v1_resource_quota_t *v1_resource_quota);

#endif /* _v1_resource_quota_H_ */

