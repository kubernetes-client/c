/*
 * v1beta1_network_policy_peer.h
 *
 * DEPRECATED 1.9 - This group version of NetworkPolicyPeer is deprecated by networking/v1/NetworkPolicyPeer.
 */

#ifndef _v1beta1_network_policy_peer_H_
#define _v1beta1_network_policy_peer_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_network_policy_peer_t v1beta1_network_policy_peer_t;

#include "v1_label_selector.h"
#include "v1beta1_ip_block.h"



typedef struct v1beta1_network_policy_peer_t {
    struct v1beta1_ip_block_t *ip_block; //model
    struct v1_label_selector_t *namespace_selector; //model
    struct v1_label_selector_t *pod_selector; //model

} v1beta1_network_policy_peer_t;

v1beta1_network_policy_peer_t *v1beta1_network_policy_peer_create(
    v1beta1_ip_block_t *ip_block,
    v1_label_selector_t *namespace_selector,
    v1_label_selector_t *pod_selector
);

void v1beta1_network_policy_peer_free(v1beta1_network_policy_peer_t *v1beta1_network_policy_peer);

v1beta1_network_policy_peer_t *v1beta1_network_policy_peer_parseFromJSON(cJSON *v1beta1_network_policy_peerJSON);

cJSON *v1beta1_network_policy_peer_convertToJSON(v1beta1_network_policy_peer_t *v1beta1_network_policy_peer);

#endif /* _v1beta1_network_policy_peer_H_ */

