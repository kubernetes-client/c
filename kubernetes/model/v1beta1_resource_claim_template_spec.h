/*
 * v1beta1_resource_claim_template_spec.h
 *
 * ResourceClaimTemplateSpec contains the metadata and fields for a ResourceClaim.
 */

#ifndef _v1beta1_resource_claim_template_spec_H_
#define _v1beta1_resource_claim_template_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_resource_claim_template_spec_t v1beta1_resource_claim_template_spec_t;

#include "v1_object_meta.h"
#include "v1beta1_resource_claim_spec.h"



typedef struct v1beta1_resource_claim_template_spec_t {
    struct v1_object_meta_t *metadata; //model
    struct v1beta1_resource_claim_spec_t *spec; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_resource_claim_template_spec_t;

__attribute__((deprecated)) v1beta1_resource_claim_template_spec_t *v1beta1_resource_claim_template_spec_create(
    v1_object_meta_t *metadata,
    v1beta1_resource_claim_spec_t *spec
);

void v1beta1_resource_claim_template_spec_free(v1beta1_resource_claim_template_spec_t *v1beta1_resource_claim_template_spec);

v1beta1_resource_claim_template_spec_t *v1beta1_resource_claim_template_spec_parseFromJSON(cJSON *v1beta1_resource_claim_template_specJSON);

cJSON *v1beta1_resource_claim_template_spec_convertToJSON(v1beta1_resource_claim_template_spec_t *v1beta1_resource_claim_template_spec);

#endif /* _v1beta1_resource_claim_template_spec_H_ */

