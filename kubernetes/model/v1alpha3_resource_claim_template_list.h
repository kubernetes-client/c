/*
 * v1alpha3_resource_claim_template_list.h
 *
 * ResourceClaimTemplateList is a collection of claim templates.
 */

#ifndef _v1alpha3_resource_claim_template_list_H_
#define _v1alpha3_resource_claim_template_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_resource_claim_template_list_t v1alpha3_resource_claim_template_list_t;

#include "v1_list_meta.h"
#include "v1alpha3_resource_claim_template.h"



typedef struct v1alpha3_resource_claim_template_list_t {
    char *api_version; // string
    list_t *items; //nonprimitive container
    char *kind; // string
    struct v1_list_meta_t *metadata; //model

} v1alpha3_resource_claim_template_list_t;

v1alpha3_resource_claim_template_list_t *v1alpha3_resource_claim_template_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
);

void v1alpha3_resource_claim_template_list_free(v1alpha3_resource_claim_template_list_t *v1alpha3_resource_claim_template_list);

v1alpha3_resource_claim_template_list_t *v1alpha3_resource_claim_template_list_parseFromJSON(cJSON *v1alpha3_resource_claim_template_listJSON);

cJSON *v1alpha3_resource_claim_template_list_convertToJSON(v1alpha3_resource_claim_template_list_t *v1alpha3_resource_claim_template_list);

#endif /* _v1alpha3_resource_claim_template_list_H_ */

