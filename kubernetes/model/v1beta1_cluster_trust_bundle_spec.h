/*
 * v1beta1_cluster_trust_bundle_spec.h
 *
 * ClusterTrustBundleSpec contains the signer and trust anchors.
 */

#ifndef _v1beta1_cluster_trust_bundle_spec_H_
#define _v1beta1_cluster_trust_bundle_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_cluster_trust_bundle_spec_t v1beta1_cluster_trust_bundle_spec_t;




typedef struct v1beta1_cluster_trust_bundle_spec_t {
    char *signer_name; // string
    char *trust_bundle; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_cluster_trust_bundle_spec_t;

__attribute__((deprecated)) v1beta1_cluster_trust_bundle_spec_t *v1beta1_cluster_trust_bundle_spec_create(
    char *signer_name,
    char *trust_bundle
);

void v1beta1_cluster_trust_bundle_spec_free(v1beta1_cluster_trust_bundle_spec_t *v1beta1_cluster_trust_bundle_spec);

v1beta1_cluster_trust_bundle_spec_t *v1beta1_cluster_trust_bundle_spec_parseFromJSON(cJSON *v1beta1_cluster_trust_bundle_specJSON);

cJSON *v1beta1_cluster_trust_bundle_spec_convertToJSON(v1beta1_cluster_trust_bundle_spec_t *v1beta1_cluster_trust_bundle_spec);

#endif /* _v1beta1_cluster_trust_bundle_spec_H_ */

