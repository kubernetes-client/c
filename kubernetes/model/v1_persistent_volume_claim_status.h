/*
 * v1_persistent_volume_claim_status.h
 *
 * PersistentVolumeClaimStatus is the current status of a persistent volume claim.
 */

#ifndef _v1_persistent_volume_claim_status_H_
#define _v1_persistent_volume_claim_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_persistent_volume_claim_status_t v1_persistent_volume_claim_status_t;

#include "v1_modify_volume_status.h"
#include "v1_persistent_volume_claim_condition.h"



typedef struct v1_persistent_volume_claim_status_t {
    list_t *access_modes; //primitive container
    list_t* allocated_resource_statuses; //map
    list_t* allocated_resources; //map
    list_t* capacity; //map
    list_t *conditions; //nonprimitive container
    char *current_volume_attributes_class_name; // string
    struct v1_modify_volume_status_t *modify_volume_status; //model
    char *phase; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_persistent_volume_claim_status_t;

__attribute__((deprecated)) v1_persistent_volume_claim_status_t *v1_persistent_volume_claim_status_create(
    list_t *access_modes,
    list_t* allocated_resource_statuses,
    list_t* allocated_resources,
    list_t* capacity,
    list_t *conditions,
    char *current_volume_attributes_class_name,
    v1_modify_volume_status_t *modify_volume_status,
    char *phase
);

void v1_persistent_volume_claim_status_free(v1_persistent_volume_claim_status_t *v1_persistent_volume_claim_status);

v1_persistent_volume_claim_status_t *v1_persistent_volume_claim_status_parseFromJSON(cJSON *v1_persistent_volume_claim_statusJSON);

cJSON *v1_persistent_volume_claim_status_convertToJSON(v1_persistent_volume_claim_status_t *v1_persistent_volume_claim_status);

#endif /* _v1_persistent_volume_claim_status_H_ */

