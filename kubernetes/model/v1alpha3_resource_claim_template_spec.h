/*
 * v1alpha3_resource_claim_template_spec.h
 *
 * ResourceClaimTemplateSpec contains the metadata and fields for a ResourceClaim.
 */

#ifndef _v1alpha3_resource_claim_template_spec_H_
#define _v1alpha3_resource_claim_template_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_resource_claim_template_spec_t v1alpha3_resource_claim_template_spec_t;

#include "v1_object_meta.h"
#include "v1alpha3_resource_claim_spec.h"



typedef struct v1alpha3_resource_claim_template_spec_t {
    struct v1_object_meta_t *metadata; //model
    struct v1alpha3_resource_claim_spec_t *spec; //model

} v1alpha3_resource_claim_template_spec_t;

v1alpha3_resource_claim_template_spec_t *v1alpha3_resource_claim_template_spec_create(
    v1_object_meta_t *metadata,
    v1alpha3_resource_claim_spec_t *spec
);

void v1alpha3_resource_claim_template_spec_free(v1alpha3_resource_claim_template_spec_t *v1alpha3_resource_claim_template_spec);

v1alpha3_resource_claim_template_spec_t *v1alpha3_resource_claim_template_spec_parseFromJSON(cJSON *v1alpha3_resource_claim_template_specJSON);

cJSON *v1alpha3_resource_claim_template_spec_convertToJSON(v1alpha3_resource_claim_template_spec_t *v1alpha3_resource_claim_template_spec);

#endif /* _v1alpha3_resource_claim_template_spec_H_ */

