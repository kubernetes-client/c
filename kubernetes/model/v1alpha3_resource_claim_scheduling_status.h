/*
 * v1alpha3_resource_claim_scheduling_status.h
 *
 * ResourceClaimSchedulingStatus contains information about one particular ResourceClaim with \&quot;WaitForFirstConsumer\&quot; allocation mode.
 */

#ifndef _v1alpha3_resource_claim_scheduling_status_H_
#define _v1alpha3_resource_claim_scheduling_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_resource_claim_scheduling_status_t v1alpha3_resource_claim_scheduling_status_t;




typedef struct v1alpha3_resource_claim_scheduling_status_t {
    char *name; // string
    list_t *unsuitable_nodes; //primitive container

} v1alpha3_resource_claim_scheduling_status_t;

v1alpha3_resource_claim_scheduling_status_t *v1alpha3_resource_claim_scheduling_status_create(
    char *name,
    list_t *unsuitable_nodes
);

void v1alpha3_resource_claim_scheduling_status_free(v1alpha3_resource_claim_scheduling_status_t *v1alpha3_resource_claim_scheduling_status);

v1alpha3_resource_claim_scheduling_status_t *v1alpha3_resource_claim_scheduling_status_parseFromJSON(cJSON *v1alpha3_resource_claim_scheduling_statusJSON);

cJSON *v1alpha3_resource_claim_scheduling_status_convertToJSON(v1alpha3_resource_claim_scheduling_status_t *v1alpha3_resource_claim_scheduling_status);

#endif /* _v1alpha3_resource_claim_scheduling_status_H_ */

