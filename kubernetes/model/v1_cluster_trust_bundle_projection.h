/*
 * v1_cluster_trust_bundle_projection.h
 *
 * ClusterTrustBundleProjection describes how to select a set of ClusterTrustBundle objects and project their contents into the pod filesystem.
 */

#ifndef _v1_cluster_trust_bundle_projection_H_
#define _v1_cluster_trust_bundle_projection_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_cluster_trust_bundle_projection_t v1_cluster_trust_bundle_projection_t;

#include "v1_label_selector.h"



typedef struct v1_cluster_trust_bundle_projection_t {
    struct v1_label_selector_t *label_selector; //model
    char *name; // string
    int optional; //boolean
    char *path; // string
    char *signer_name; // string

} v1_cluster_trust_bundle_projection_t;

v1_cluster_trust_bundle_projection_t *v1_cluster_trust_bundle_projection_create(
    v1_label_selector_t *label_selector,
    char *name,
    int optional,
    char *path,
    char *signer_name
);

void v1_cluster_trust_bundle_projection_free(v1_cluster_trust_bundle_projection_t *v1_cluster_trust_bundle_projection);

v1_cluster_trust_bundle_projection_t *v1_cluster_trust_bundle_projection_parseFromJSON(cJSON *v1_cluster_trust_bundle_projectionJSON);

cJSON *v1_cluster_trust_bundle_projection_convertToJSON(v1_cluster_trust_bundle_projection_t *v1_cluster_trust_bundle_projection);

#endif /* _v1_cluster_trust_bundle_projection_H_ */

