/*
 * v1_ip_block.h
 *
 * IPBlock describes a particular CIDR (Ex. \&quot;192.168.1.1/24\&quot;) that is allowed to the pods matched by a NetworkPolicySpec&#39;s podSelector. The except entry describes CIDRs that should not be included within this rule.
 */

#ifndef _v1_ip_block_H_
#define _v1_ip_block_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_ip_block_t {
    char *cidr; // string
    list_t *except; //primitive container

} v1_ip_block_t;

v1_ip_block_t *v1_ip_block_create(
    char *cidr,
    list_t *except
);

void v1_ip_block_free(v1_ip_block_t *v1_ip_block);

v1_ip_block_t *v1_ip_block_parseFromJSON(cJSON *v1_ip_blockJSON);

cJSON *v1_ip_block_convertToJSON(v1_ip_block_t *v1_ip_block);

#endif /* _v1_ip_block_H_ */

