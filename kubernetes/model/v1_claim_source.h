/*
 * v1_claim_source.h
 *
 * ClaimSource describes a reference to a ResourceClaim.  Exactly one of these fields should be set.  Consumers of this type must treat an empty object as if it has an unknown value.
 */

#ifndef _v1_claim_source_H_
#define _v1_claim_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_claim_source_t v1_claim_source_t;




typedef struct v1_claim_source_t {
    char *resource_claim_name; // string
    char *resource_claim_template_name; // string

} v1_claim_source_t;

v1_claim_source_t *v1_claim_source_create(
    char *resource_claim_name,
    char *resource_claim_template_name
);

void v1_claim_source_free(v1_claim_source_t *v1_claim_source);

v1_claim_source_t *v1_claim_source_parseFromJSON(cJSON *v1_claim_sourceJSON);

cJSON *v1_claim_source_convertToJSON(v1_claim_source_t *v1_claim_source);

#endif /* _v1_claim_source_H_ */

