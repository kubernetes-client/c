/*
 * v1alpha1_cluster_cidr_spec.h
 *
 * ClusterCIDRSpec defines the desired state of ClusterCIDR.
 */

#ifndef _v1alpha1_cluster_cidr_spec_H_
#define _v1alpha1_cluster_cidr_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_cluster_cidr_spec_t v1alpha1_cluster_cidr_spec_t;

#include "v1_node_selector.h"



typedef struct v1alpha1_cluster_cidr_spec_t {
    char *ipv4; // string
    char *ipv6; // string
    struct v1_node_selector_t *node_selector; //model
    int per_node_host_bits; //numeric

} v1alpha1_cluster_cidr_spec_t;

v1alpha1_cluster_cidr_spec_t *v1alpha1_cluster_cidr_spec_create(
    char *ipv4,
    char *ipv6,
    v1_node_selector_t *node_selector,
    int per_node_host_bits
);

void v1alpha1_cluster_cidr_spec_free(v1alpha1_cluster_cidr_spec_t *v1alpha1_cluster_cidr_spec);

v1alpha1_cluster_cidr_spec_t *v1alpha1_cluster_cidr_spec_parseFromJSON(cJSON *v1alpha1_cluster_cidr_specJSON);

cJSON *v1alpha1_cluster_cidr_spec_convertToJSON(v1alpha1_cluster_cidr_spec_t *v1alpha1_cluster_cidr_spec);

#endif /* _v1alpha1_cluster_cidr_spec_H_ */

