/*
 * v1_lease_spec.h
 *
 * LeaseSpec is a specification of a Lease.
 */

#ifndef _v1_lease_spec_H_
#define _v1_lease_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_lease_spec_t v1_lease_spec_t;




typedef struct v1_lease_spec_t {
    char *acquire_time; //date time
    char *holder_identity; // string
    int lease_duration_seconds; //numeric
    int lease_transitions; //numeric
    char *renew_time; //date time

} v1_lease_spec_t;

v1_lease_spec_t *v1_lease_spec_create(
    char *acquire_time,
    char *holder_identity,
    int lease_duration_seconds,
    int lease_transitions,
    char *renew_time
);

void v1_lease_spec_free(v1_lease_spec_t *v1_lease_spec);

v1_lease_spec_t *v1_lease_spec_parseFromJSON(cJSON *v1_lease_specJSON);

cJSON *v1_lease_spec_convertToJSON(v1_lease_spec_t *v1_lease_spec);

#endif /* _v1_lease_spec_H_ */

