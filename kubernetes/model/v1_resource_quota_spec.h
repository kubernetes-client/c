/*
 * v1_resource_quota_spec.h
 *
 * ResourceQuotaSpec defines the desired hard limits to enforce for Quota.
 */

#ifndef _v1_resource_quota_spec_H_
#define _v1_resource_quota_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_resource_quota_spec_t v1_resource_quota_spec_t;

#include "v1_scope_selector.h"



typedef struct v1_resource_quota_spec_t {
    list_t* hard; //map
    struct v1_scope_selector_t *scope_selector; //model
    list_t *scopes; //primitive container

} v1_resource_quota_spec_t;

v1_resource_quota_spec_t *v1_resource_quota_spec_create(
    list_t* hard,
    v1_scope_selector_t *scope_selector,
    list_t *scopes
);

void v1_resource_quota_spec_free(v1_resource_quota_spec_t *v1_resource_quota_spec);

v1_resource_quota_spec_t *v1_resource_quota_spec_parseFromJSON(cJSON *v1_resource_quota_specJSON);

cJSON *v1_resource_quota_spec_convertToJSON(v1_resource_quota_spec_t *v1_resource_quota_spec);

#endif /* _v1_resource_quota_spec_H_ */

