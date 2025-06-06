/*
 * v1beta2_resource_claim_template.h
 *
 * ResourceClaimTemplate is used to produce ResourceClaim objects.  This is an alpha type and requires enabling the DynamicResourceAllocation feature gate.
 */

#ifndef _v1beta2_resource_claim_template_H_
#define _v1beta2_resource_claim_template_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta2_resource_claim_template_t v1beta2_resource_claim_template_t;

#include "v1_object_meta.h"
#include "v1beta2_resource_claim_template_spec.h"



typedef struct v1beta2_resource_claim_template_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1beta2_resource_claim_template_spec_t *spec; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta2_resource_claim_template_t;

__attribute__((deprecated)) v1beta2_resource_claim_template_t *v1beta2_resource_claim_template_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta2_resource_claim_template_spec_t *spec
);

void v1beta2_resource_claim_template_free(v1beta2_resource_claim_template_t *v1beta2_resource_claim_template);

v1beta2_resource_claim_template_t *v1beta2_resource_claim_template_parseFromJSON(cJSON *v1beta2_resource_claim_templateJSON);

cJSON *v1beta2_resource_claim_template_convertToJSON(v1beta2_resource_claim_template_t *v1beta2_resource_claim_template);

#endif /* _v1beta2_resource_claim_template_H_ */

