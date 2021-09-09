/*
 * v1_persistent_volume_claim_spec.h
 *
 * PersistentVolumeClaimSpec describes the common attributes of storage devices and allows a Source for provider-specific attributes
 */

#ifndef _v1_persistent_volume_claim_spec_H_
#define _v1_persistent_volume_claim_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_persistent_volume_claim_spec_t v1_persistent_volume_claim_spec_t;

#include "v1_label_selector.h"
#include "v1_resource_requirements.h"
#include "v1_typed_local_object_reference.h"



typedef struct v1_persistent_volume_claim_spec_t {
    list_t *access_modes; //primitive container
    struct v1_typed_local_object_reference_t *data_source; //model
    struct v1_resource_requirements_t *resources; //model
    struct v1_label_selector_t *selector; //model
    char *storage_class_name; // string
    char *volume_mode; // string
    char *volume_name; // string

} v1_persistent_volume_claim_spec_t;

v1_persistent_volume_claim_spec_t *v1_persistent_volume_claim_spec_create(
    list_t *access_modes,
    v1_typed_local_object_reference_t *data_source,
    v1_resource_requirements_t *resources,
    v1_label_selector_t *selector,
    char *storage_class_name,
    char *volume_mode,
    char *volume_name
);

void v1_persistent_volume_claim_spec_free(v1_persistent_volume_claim_spec_t *v1_persistent_volume_claim_spec);

v1_persistent_volume_claim_spec_t *v1_persistent_volume_claim_spec_parseFromJSON(cJSON *v1_persistent_volume_claim_specJSON);

cJSON *v1_persistent_volume_claim_spec_convertToJSON(v1_persistent_volume_claim_spec_t *v1_persistent_volume_claim_spec);

#endif /* _v1_persistent_volume_claim_spec_H_ */

