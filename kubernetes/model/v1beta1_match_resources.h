/*
 * v1beta1_match_resources.h
 *
 * MatchResources decides whether to run the admission control policy on an object based on whether it meets the match criteria. The exclude rules take precedence over include rules (if a resource matches both, it is excluded)
 */

#ifndef _v1beta1_match_resources_H_
#define _v1beta1_match_resources_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_match_resources_t v1beta1_match_resources_t;

#include "v1_label_selector.h"
#include "v1beta1_named_rule_with_operations.h"



typedef struct v1beta1_match_resources_t {
    list_t *exclude_resource_rules; //nonprimitive container
    char *match_policy; // string
    struct v1_label_selector_t *namespace_selector; //model
    struct v1_label_selector_t *object_selector; //model
    list_t *resource_rules; //nonprimitive container

} v1beta1_match_resources_t;

v1beta1_match_resources_t *v1beta1_match_resources_create(
    list_t *exclude_resource_rules,
    char *match_policy,
    v1_label_selector_t *namespace_selector,
    v1_label_selector_t *object_selector,
    list_t *resource_rules
);

void v1beta1_match_resources_free(v1beta1_match_resources_t *v1beta1_match_resources);

v1beta1_match_resources_t *v1beta1_match_resources_parseFromJSON(cJSON *v1beta1_match_resourcesJSON);

cJSON *v1beta1_match_resources_convertToJSON(v1beta1_match_resources_t *v1beta1_match_resources);

#endif /* _v1beta1_match_resources_H_ */

