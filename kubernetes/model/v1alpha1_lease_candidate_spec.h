/*
 * v1alpha1_lease_candidate_spec.h
 *
 * LeaseCandidateSpec is a specification of a Lease.
 */

#ifndef _v1alpha1_lease_candidate_spec_H_
#define _v1alpha1_lease_candidate_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_lease_candidate_spec_t v1alpha1_lease_candidate_spec_t;




typedef struct v1alpha1_lease_candidate_spec_t {
    char *binary_version; // string
    char *emulation_version; // string
    char *lease_name; // string
    char *ping_time; //date time
    list_t *preferred_strategies; //primitive container
    char *renew_time; //date time

} v1alpha1_lease_candidate_spec_t;

v1alpha1_lease_candidate_spec_t *v1alpha1_lease_candidate_spec_create(
    char *binary_version,
    char *emulation_version,
    char *lease_name,
    char *ping_time,
    list_t *preferred_strategies,
    char *renew_time
);

void v1alpha1_lease_candidate_spec_free(v1alpha1_lease_candidate_spec_t *v1alpha1_lease_candidate_spec);

v1alpha1_lease_candidate_spec_t *v1alpha1_lease_candidate_spec_parseFromJSON(cJSON *v1alpha1_lease_candidate_specJSON);

cJSON *v1alpha1_lease_candidate_spec_convertToJSON(v1alpha1_lease_candidate_spec_t *v1alpha1_lease_candidate_spec);

#endif /* _v1alpha1_lease_candidate_spec_H_ */

