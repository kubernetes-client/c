/*
 * v1beta1_lease_candidate_list.h
 *
 * LeaseCandidateList is a list of Lease objects.
 */

#ifndef _v1beta1_lease_candidate_list_H_
#define _v1beta1_lease_candidate_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_lease_candidate_list_t v1beta1_lease_candidate_list_t;

#include "v1_list_meta.h"
#include "v1beta1_lease_candidate.h"



typedef struct v1beta1_lease_candidate_list_t {
    char *api_version; // string
    list_t *items; //nonprimitive container
    char *kind; // string
    struct v1_list_meta_t *metadata; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_lease_candidate_list_t;

__attribute__((deprecated)) v1beta1_lease_candidate_list_t *v1beta1_lease_candidate_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
);

void v1beta1_lease_candidate_list_free(v1beta1_lease_candidate_list_t *v1beta1_lease_candidate_list);

v1beta1_lease_candidate_list_t *v1beta1_lease_candidate_list_parseFromJSON(cJSON *v1beta1_lease_candidate_listJSON);

cJSON *v1beta1_lease_candidate_list_convertToJSON(v1beta1_lease_candidate_list_t *v1beta1_lease_candidate_list);

#endif /* _v1beta1_lease_candidate_list_H_ */

