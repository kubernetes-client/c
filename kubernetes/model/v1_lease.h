/*
 * v1_lease.h
 *
 * Lease defines a lease concept.
 */

#ifndef _v1_lease_H_
#define _v1_lease_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_lease_t v1_lease_t;

#include "v1_lease_spec.h"
#include "v1_object_meta.h"



typedef struct v1_lease_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1_lease_spec_t *spec; //model

} v1_lease_t;

v1_lease_t *v1_lease_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_lease_spec_t *spec
);

void v1_lease_free(v1_lease_t *v1_lease);

v1_lease_t *v1_lease_parseFromJSON(cJSON *v1_leaseJSON);

cJSON *v1_lease_convertToJSON(v1_lease_t *v1_lease);

#endif /* _v1_lease_H_ */

