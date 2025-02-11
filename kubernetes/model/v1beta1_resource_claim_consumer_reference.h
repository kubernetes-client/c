/*
 * v1beta1_resource_claim_consumer_reference.h
 *
 * ResourceClaimConsumerReference contains enough information to let you locate the consumer of a ResourceClaim. The user must be a resource in the same namespace as the ResourceClaim.
 */

#ifndef _v1beta1_resource_claim_consumer_reference_H_
#define _v1beta1_resource_claim_consumer_reference_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_resource_claim_consumer_reference_t v1beta1_resource_claim_consumer_reference_t;




typedef struct v1beta1_resource_claim_consumer_reference_t {
    char *api_group; // string
    char *name; // string
    char *resource; // string
    char *uid; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_resource_claim_consumer_reference_t;

__attribute__((deprecated)) v1beta1_resource_claim_consumer_reference_t *v1beta1_resource_claim_consumer_reference_create(
    char *api_group,
    char *name,
    char *resource,
    char *uid
);

void v1beta1_resource_claim_consumer_reference_free(v1beta1_resource_claim_consumer_reference_t *v1beta1_resource_claim_consumer_reference);

v1beta1_resource_claim_consumer_reference_t *v1beta1_resource_claim_consumer_reference_parseFromJSON(cJSON *v1beta1_resource_claim_consumer_referenceJSON);

cJSON *v1beta1_resource_claim_consumer_reference_convertToJSON(v1beta1_resource_claim_consumer_reference_t *v1beta1_resource_claim_consumer_reference);

#endif /* _v1beta1_resource_claim_consumer_reference_H_ */

