/*
 * v1alpha3_pod_group_status.h
 *
 * PodGroupStatus represents information about the status of a pod group.
 */

#ifndef _v1alpha3_pod_group_status_H_
#define _v1alpha3_pod_group_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_pod_group_status_t v1alpha3_pod_group_status_t;

#include "v1_condition.h"
#include "v1alpha3_pod_group_resource_claim_status.h"



typedef struct v1alpha3_pod_group_status_t {
    list_t *conditions; //nonprimitive container
    list_t *resource_claim_statuses; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha3_pod_group_status_t;

__attribute__((deprecated)) v1alpha3_pod_group_status_t *v1alpha3_pod_group_status_create(
    list_t *conditions,
    list_t *resource_claim_statuses
);

void v1alpha3_pod_group_status_free(v1alpha3_pod_group_status_t *v1alpha3_pod_group_status);

v1alpha3_pod_group_status_t *v1alpha3_pod_group_status_parseFromJSON(cJSON *v1alpha3_pod_group_statusJSON);

cJSON *v1alpha3_pod_group_status_convertToJSON(v1alpha3_pod_group_status_t *v1alpha3_pod_group_status);

#endif /* _v1alpha3_pod_group_status_H_ */

