/*
 * v1alpha1_cluster_cidr.h
 *
 * ClusterCIDR represents a single configuration for per-Node Pod CIDR allocations when the MultiCIDRRangeAllocator is enabled (see the config for kube-controller-manager).  A cluster may have any number of ClusterCIDR resources, all of which will be considered when allocating a CIDR for a Node.  A ClusterCIDR is eligible to be used for a given Node when the node selector matches the node in question and has free CIDRs to allocate.  In case of multiple matching ClusterCIDR resources, the allocator will attempt to break ties using internal heuristics, but any ClusterCIDR whose node selector matches the Node may be used.
 */

#ifndef _v1alpha1_cluster_cidr_H_
#define _v1alpha1_cluster_cidr_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_cluster_cidr_t v1alpha1_cluster_cidr_t;

#include "v1_object_meta.h"
#include "v1alpha1_cluster_cidr_spec.h"



typedef struct v1alpha1_cluster_cidr_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1alpha1_cluster_cidr_spec_t *spec; //model

} v1alpha1_cluster_cidr_t;

v1alpha1_cluster_cidr_t *v1alpha1_cluster_cidr_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha1_cluster_cidr_spec_t *spec
);

void v1alpha1_cluster_cidr_free(v1alpha1_cluster_cidr_t *v1alpha1_cluster_cidr);

v1alpha1_cluster_cidr_t *v1alpha1_cluster_cidr_parseFromJSON(cJSON *v1alpha1_cluster_cidrJSON);

cJSON *v1alpha1_cluster_cidr_convertToJSON(v1alpha1_cluster_cidr_t *v1alpha1_cluster_cidr);

#endif /* _v1alpha1_cluster_cidr_H_ */

