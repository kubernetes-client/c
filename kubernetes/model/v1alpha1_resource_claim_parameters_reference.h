/*
 * v1alpha1_resource_claim_parameters_reference.h
 *
 * ResourceClaimParametersReference contains enough information to let you locate the parameters for a ResourceClaim. The object must be in the same namespace as the ResourceClaim.
 */

#ifndef _v1alpha1_resource_claim_parameters_reference_H_
#define _v1alpha1_resource_claim_parameters_reference_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_resource_claim_parameters_reference_t v1alpha1_resource_claim_parameters_reference_t;




typedef struct v1alpha1_resource_claim_parameters_reference_t {
    char *api_group; // string
    char *kind; // string
    char *name; // string

} v1alpha1_resource_claim_parameters_reference_t;

v1alpha1_resource_claim_parameters_reference_t *v1alpha1_resource_claim_parameters_reference_create(
    char *api_group,
    char *kind,
    char *name
);

void v1alpha1_resource_claim_parameters_reference_free(v1alpha1_resource_claim_parameters_reference_t *v1alpha1_resource_claim_parameters_reference);

v1alpha1_resource_claim_parameters_reference_t *v1alpha1_resource_claim_parameters_reference_parseFromJSON(cJSON *v1alpha1_resource_claim_parameters_referenceJSON);

cJSON *v1alpha1_resource_claim_parameters_reference_convertToJSON(v1alpha1_resource_claim_parameters_reference_t *v1alpha1_resource_claim_parameters_reference);

#endif /* _v1alpha1_resource_claim_parameters_reference_H_ */

