/*
 * v1alpha1_lease_candidate.h
 *
 * LeaseCandidate defines a candidate for a Lease object. Candidates are created such that coordinated leader election will pick the best leader from the list of candidates.
 */

#ifndef _v1alpha1_lease_candidate_H_
#define _v1alpha1_lease_candidate_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_lease_candidate_t v1alpha1_lease_candidate_t;

#include "v1_object_meta.h"
#include "v1alpha1_lease_candidate_spec.h"



typedef struct v1alpha1_lease_candidate_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1alpha1_lease_candidate_spec_t *spec; //model

} v1alpha1_lease_candidate_t;

v1alpha1_lease_candidate_t *v1alpha1_lease_candidate_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha1_lease_candidate_spec_t *spec
);

void v1alpha1_lease_candidate_free(v1alpha1_lease_candidate_t *v1alpha1_lease_candidate);

v1alpha1_lease_candidate_t *v1alpha1_lease_candidate_parseFromJSON(cJSON *v1alpha1_lease_candidateJSON);

cJSON *v1alpha1_lease_candidate_convertToJSON(v1alpha1_lease_candidate_t *v1alpha1_lease_candidate);

#endif /* _v1alpha1_lease_candidate_H_ */

