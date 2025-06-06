/*
 * v1beta1_cluster_trust_bundle.h
 *
 * ClusterTrustBundle is a cluster-scoped container for X.509 trust anchors (root certificates).  ClusterTrustBundle objects are considered to be readable by any authenticated user in the cluster, because they can be mounted by pods using the &#x60;clusterTrustBundle&#x60; projection.  All service accounts have read access to ClusterTrustBundles by default.  Users who only have namespace-level access to a cluster can read ClusterTrustBundles by impersonating a serviceaccount that they have access to.  It can be optionally associated with a particular assigner, in which case it contains one valid set of trust anchors for that signer. Signers may have multiple associated ClusterTrustBundles; each is an independent set of trust anchors for that signer. Admission control is used to enforce that only users with permissions on the signer can create or modify the corresponding bundle.
 */

#ifndef _v1beta1_cluster_trust_bundle_H_
#define _v1beta1_cluster_trust_bundle_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_cluster_trust_bundle_t v1beta1_cluster_trust_bundle_t;

#include "v1_object_meta.h"
#include "v1beta1_cluster_trust_bundle_spec.h"



typedef struct v1beta1_cluster_trust_bundle_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1beta1_cluster_trust_bundle_spec_t *spec; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_cluster_trust_bundle_t;

__attribute__((deprecated)) v1beta1_cluster_trust_bundle_t *v1beta1_cluster_trust_bundle_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta1_cluster_trust_bundle_spec_t *spec
);

void v1beta1_cluster_trust_bundle_free(v1beta1_cluster_trust_bundle_t *v1beta1_cluster_trust_bundle);

v1beta1_cluster_trust_bundle_t *v1beta1_cluster_trust_bundle_parseFromJSON(cJSON *v1beta1_cluster_trust_bundleJSON);

cJSON *v1beta1_cluster_trust_bundle_convertToJSON(v1beta1_cluster_trust_bundle_t *v1beta1_cluster_trust_bundle);

#endif /* _v1beta1_cluster_trust_bundle_H_ */

