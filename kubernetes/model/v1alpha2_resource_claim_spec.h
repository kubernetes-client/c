/*
 * v1alpha2_resource_claim_spec.h
 *
 * ResourceClaimSpec defines how a resource is to be allocated.
 */

#ifndef _v1alpha2_resource_claim_spec_H_
#define _v1alpha2_resource_claim_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha2_resource_claim_spec_t v1alpha2_resource_claim_spec_t;

#include "v1alpha2_resource_claim_parameters_reference.h"



typedef struct v1alpha2_resource_claim_spec_t {
    char *allocation_mode; // string
    struct v1alpha2_resource_claim_parameters_reference_t *parameters_ref; //model
    char *resource_class_name; // string

} v1alpha2_resource_claim_spec_t;

v1alpha2_resource_claim_spec_t *v1alpha2_resource_claim_spec_create(
    char *allocation_mode,
    v1alpha2_resource_claim_parameters_reference_t *parameters_ref,
    char *resource_class_name
);

void v1alpha2_resource_claim_spec_free(v1alpha2_resource_claim_spec_t *v1alpha2_resource_claim_spec);

v1alpha2_resource_claim_spec_t *v1alpha2_resource_claim_spec_parseFromJSON(cJSON *v1alpha2_resource_claim_specJSON);

cJSON *v1alpha2_resource_claim_spec_convertToJSON(v1alpha2_resource_claim_spec_t *v1alpha2_resource_claim_spec);

#endif /* _v1alpha2_resource_claim_spec_H_ */

