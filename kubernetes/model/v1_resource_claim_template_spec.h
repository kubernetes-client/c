/*
 * v1_resource_claim_template_spec.h
 *
 * ResourceClaimTemplateSpec contains the metadata and fields for a ResourceClaim.
 */

#ifndef _v1_resource_claim_template_spec_H_
#define _v1_resource_claim_template_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_resource_claim_template_spec_t v1_resource_claim_template_spec_t;

#include "v1_object_meta.h"
#include "v1_resource_claim_spec.h"



typedef struct v1_resource_claim_template_spec_t {
    struct v1_object_meta_t *metadata; //model
    struct v1_resource_claim_spec_t *spec; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1_resource_claim_template_spec_t;

__attribute__((deprecated)) v1_resource_claim_template_spec_t *v1_resource_claim_template_spec_create(
    v1_object_meta_t *metadata,
    v1_resource_claim_spec_t *spec
);

void v1_resource_claim_template_spec_free(v1_resource_claim_template_spec_t *v1_resource_claim_template_spec);

v1_resource_claim_template_spec_t *v1_resource_claim_template_spec_parseFromJSON(cJSON *v1_resource_claim_template_specJSON);

cJSON *v1_resource_claim_template_spec_convertToJSON(v1_resource_claim_template_spec_t *v1_resource_claim_template_spec);

#endif /* _v1_resource_claim_template_spec_H_ */

