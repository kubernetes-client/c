/*
 * v1_node_features.h
 *
 * NodeFeatures describes the set of features implemented by the CRI implementation. The features contained in the NodeFeatures should depend only on the cri implementation independent of runtime handlers.
 */

#ifndef _v1_node_features_H_
#define _v1_node_features_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_node_features_t v1_node_features_t;




typedef struct v1_node_features_t {
    int supplemental_groups_policy; //boolean

} v1_node_features_t;

v1_node_features_t *v1_node_features_create(
    int supplemental_groups_policy
);

void v1_node_features_free(v1_node_features_t *v1_node_features);

v1_node_features_t *v1_node_features_parseFromJSON(cJSON *v1_node_featuresJSON);

cJSON *v1_node_features_convertToJSON(v1_node_features_t *v1_node_features);

#endif /* _v1_node_features_H_ */

