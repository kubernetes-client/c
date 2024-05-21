/*
 * v1alpha2_resource_claim_parameters.h
 *
 * ResourceClaimParameters defines resource requests for a ResourceClaim in an in-tree format understood by Kubernetes.
 */

#ifndef _v1alpha2_resource_claim_parameters_H_
#define _v1alpha2_resource_claim_parameters_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha2_resource_claim_parameters_t v1alpha2_resource_claim_parameters_t;

#include "v1_object_meta.h"
#include "v1alpha2_driver_requests.h"
#include "v1alpha2_resource_claim_parameters_reference.h"



typedef struct v1alpha2_resource_claim_parameters_t {
    char *api_version; // string
    list_t *driver_requests; //nonprimitive container
    struct v1alpha2_resource_claim_parameters_reference_t *generated_from; //model
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    int shareable; //boolean

} v1alpha2_resource_claim_parameters_t;

v1alpha2_resource_claim_parameters_t *v1alpha2_resource_claim_parameters_create(
    char *api_version,
    list_t *driver_requests,
    v1alpha2_resource_claim_parameters_reference_t *generated_from,
    char *kind,
    v1_object_meta_t *metadata,
    int shareable
);

void v1alpha2_resource_claim_parameters_free(v1alpha2_resource_claim_parameters_t *v1alpha2_resource_claim_parameters);

v1alpha2_resource_claim_parameters_t *v1alpha2_resource_claim_parameters_parseFromJSON(cJSON *v1alpha2_resource_claim_parametersJSON);

cJSON *v1alpha2_resource_claim_parameters_convertToJSON(v1alpha2_resource_claim_parameters_t *v1alpha2_resource_claim_parameters);

#endif /* _v1alpha2_resource_claim_parameters_H_ */

